#ifndef WIDGET_H
#define WIDGET_H
#include<QWidget>
#include<QTimer>
#include<QStandardItemModel>
#include<QStringList>
#include<QTableView>
#include<QNetworkReply>
#include<QNetworkRequest>
#include <QNetworkAccessManager>
#include <QRegularExpression>
#include<QCompleter>
#include<QSqlDatabase>
#include<QMessageBox>
#include<QSqlQuery>
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    void settable();

    void downloadall();
    void download_file(int pn);
    void comboBox();
    void connectsql();
    double getcodeprice(QString code);
    QString getcodename(QString code);
    QString get_stock_code(QString name);
    QStringList match(QString text,QString fn);
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void qtimeSlot();
    void filltable();
    void on_forwardButton_clicked();
    void on_backButton_clicked();
    void on_confirmButton_clicked();
    void on_lineEdit_code_editingFinished();

private:
    Ui::Widget *ui;
   // QStringList name,number,price;
    QStandardItemModel *model;
    QTimer *update_timer;
    int curpage=1;
    int pagerowcount=20;
    QStringList name,code,cur_price,rise_fall_level,rise_fall_amount;
    QSqlDatabase db;
};
#endif // WIDGET_H
