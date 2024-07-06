#include "widget.h"
#include "ui_widget.h"
#include<QStandardItem>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    ui->setupUi(this);
    settable();
    downloadall();
    for(int i=0;i<name.size();i++)
    {
        setRow(i);
        setflame();
    }

   // tableWidget.clear();

    setButton();
    //
    }

Widget::~Widget()
{
    delete ui;
}

void Widget::setflame(){
    for (int row = 0; row < tableWidget->rowCount(); ++row) {
        // 买入复选框
        QCheckBox *checkBox1 = new QCheckBox(tableWidget);
        tableWidget->setCellWidget(row, 3, checkBox1);
        //卖出复选框
        QCheckBox *checkBox2 = new QCheckBox(tableWidget);
        tableWidget->setCellWidget(row,4,checkBox2);
        // 第三列：文本输入框，初始禁用
        QLineEdit *lineEdit = new QLineEdit(tableWidget);
        lineEdit->setEnabled(false); // 初始状态为禁用
        tableWidget->setCellWidget(row, 5, lineEdit);
        // 互斥逻辑
        connect(checkBox1, &QCheckBox::stateChanged, this, [=](int state)
                {
                    if (state == Qt::Checked) {
                        QCheckBox *otherCb = qobject_cast<QCheckBox*>(tableWidget->cellWidget(row, 4));
                        if (otherCb) otherCb->setChecked(false);
                    }
                });
        connect(checkBox2, &QCheckBox::stateChanged, this, [=](int state){
            if (state == Qt::Checked) {
                QCheckBox *otherCb = qobject_cast<QCheckBox*>(tableWidget->cellWidget(row, 3));
                if (otherCb) otherCb->setChecked(false);
            }
        });
        // 连接复选框 1 和复选框2的状态变化信号到槽，以启用/禁用 文本输入框
        connect(checkBox1, &QCheckBox::stateChanged, [lineEdit](int state) {
            lineEdit->setEnabled(state == Qt::Checked);
        });
        connect(checkBox2, &QCheckBox::stateChanged, [lineEdit](int state) {
            lineEdit->setEnabled(state == Qt::Checked);
        })
            ;}
}
void Widget::settable()
{
    tableWidget = new QTableWidget(0,6); // 构造了一个QTableWidget的对象，并且设置为100行，6列
    tableWidget->setParent(this);
    tableWidget->setWindowTitle("QTableWidget & Item");
    tableWidget->resize(900, 700);  //设置表格
    QStringList header;

    header<<"股票名称"<<"股票代码"<<"股票当前价格"<<"买入"<<"卖出"<<"买入/卖出的份数"<<"确定买入/卖出";
    tableWidget->setHorizontalHeaderLabels(header);
    //tableWidget->setItem(0,0,new QTableWidgetItem("股票名称"));
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget->show();
}

void Widget::setRow(int i)
{
    tableWidget->insertRow(i%5);
    QTableWidgetItem *it1 = new QTableWidgetItem(name[i]);
    QTableWidgetItem *it2 = new QTableWidgetItem(number[i]);
    QTableWidgetItem *it3 = new QTableWidgetItem(price[i]);
    tableWidget->setItem(i%5,0,it1);
    tableWidget->setItem(i%5,1,it2);
    tableWidget->setItem(i%5,2,it3);
}

void Widget::downloadall()
{
     name=download_file("f14");
     number=download_file("f12");
     price=download_file("f15");
}

QStringList Widget::download_file(QString fn)
{
    //f12--代码 f14-名称 f2-最新价 f3-涨跌幅 f4-涨跌额
    /*
    cmd = {
        "沪深京A股": "f3&fs=m:0+t:6,m:0+t:80,m:1+t:2,m:1+t:23,m:0+t:81+s:2048",
        "上证A股": "f3&fs=m:1+t:2,m:1+t:23",
        "深证A股": "f3&fs=m:0+t:6,m:0+t:80",
        "北证A股": "f3&fs=m:0+t:81+s:2048",
        "新股": "f26&fs=m:0+f:8,m:1+f:8",
        "创业板": "f3&fs=m:0+t:80",
        "科创板": "f3&fs=m:1+t:23",
        "沪股通": "f26&fs=b:BK0707",
        "深股通": "f26&fs=b:BK0804",
        "B股": "f3&fs=m:0+t:7,m:1+t:3",
        "风险警示板": "f3&fs=m:0+f:4,m:1+f:4",
    }*/
    /*  map[0]="f3&fs=m:0+t:6,m:0+t:80,m:1+t:2,m:1+t:23,m:0+t:81+s:2048";
    map[1]= "f3&fs=m:1+t:2,m:1+t:23";
    map[2]= "f3&fs=m:0+t:6,m:0+t:80";
    map[3]="f3&fs=m:0+t:81+s:2048";
    map[4]="f26&fs=m:0+f:8,m:1+f:8";
    map[5]="f3&fs=m:0+t:80";
    map[6]= "f3&fs=m:1+t:23";*/

    //两种类型 1.double  2.中文(代码)
    QString url_str="https://30.push2.eastmoney.com/api/qt/clist/get?cb=jQuery112402453391037201289_1720082624724&pn=1&pz=20&po=1&np=1&ut=bd1d9ddb04089700cf9c27f6f7426281&fltt=2&invt=2&dect=1&wbp2u=|0|0|0|web&fid=f3&fs=m:1+t:2,m:1+t:23&fields=f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f12,f13,f14,f15,f16,f17,f18,f20,f21,f23,f24,f25,f22,f11,f62,f128,f136,f115,f152&_=1720082624725";
    QNetworkAccessManager manager;
    QEventLoop loop;
    QNetworkReply *reply=manager.get(QNetworkRequest(url_str));
    QObject::connect(reply,SIGNAL(finished()),&loop,SLOT(quit()));
    loop.exec();
    auto   text=reply->readAll();
    //  (f12 f14-qreg) f15-f16-f17-qregdouble
    QString qreg='\"'+fn+"\":\"(.*?)\"";//对于反斜杠要用转义字符表示
    QString qregdouble='\"'+fn+"\":(\\d+\\.\\d+)";
    if(fn!="f12"&&fn!="f14")qreg=qregdouble;
    QRegularExpression re(qreg);
    //用next函数实现跳转从而全局匹配
    QStringList strlist;
    auto pos=re.globalMatch(text);
    while(pos.hasNext())
    {
        auto match=pos.next();
        auto  tmp=match.captured(0).mid(fn.size()+3);
        if(fn=="f12"||fn=="f14")tmp=tmp.mid(1,tmp.size()-2);
        strlist.append(tmp);
    }
    return strlist;
}

void Widget::setButton()
{

    QPushButton *backButton=new QPushButton("上一页",this);
    QPushButton *frontButton=new QPushButton("下一页",this);
    QPushButton *confirmButton=new QPushButton("确定",this);
    backButton->move(100,250);
    frontButton->move(300,250);
    confirmButton->move(500,250);
    connect(backButton,&QPushButton::clicked,tableWidget,&QTableWidget::clear);
    connect(frontButton,&QPushButton::clicked,tableWidget,&QTableWidget::clear);
    //connect(frontButton,&QPushButton::clicked,tableWidget,&QTableWidget::clear);
}
void connect_sql()
{
    /*
    db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("demo");
    db.setUserName("root");
    db.setPassword("root");
    if(db.open()){
        qDebug() << "连接成功";
    }else{
        qDebug() << "连接失败";
    }
    connect(ui->commerceButton,SIGNAL(clicked()),this,SLOT(toSon()));
    connect(&S,SIGNAL(sSignal()),this,SLOT(toMain()));*/
}
void get_txt()
{
    //获取程序当前运行目录
    //获取文本数据
    /*QString fileName = QCoreApplication::applicationDirPath();
    QFile f(fileName+"data.txt");
    f.open(QIODevice::ReadOnly | QIODevice::Text);

    QByteArray t = f.readAll();
    ui->textEdit->setText(QString(t));
    QTextStream in(&f);
    while (!in.atEnd()) {
        QString line = in.readLine();
        // 处理每一行的文本
        qDebug() << line;
    }*/
}
void Widget::backButton_clicked()
{
    tableWidget->show();
}
void Widget::confirmButton_clicked()
{

}
