#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include<QFile>
#include<QWindow>
#include<QString>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QtSql>
#include<QSqlQuery>
#include<QSqlDatabase>
#include<QTableWidget>
#include<QTableWidgetItem>
#include<QMessageBox>
#include<QProcess>
#include <QUrl>
#include <QNetworkReply>
#include <QCheckBox>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include<QString>
#include<QStringList>
#include<QStyledItemDelegate>
#include<QPushButton>
#include<QApplication>
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void backButton_clicked();
    void confirmButton_clicked();
private:
    QStringList download_file(QString fn);
    Ui::Widget *ui;
    QSqlDatabase db;
    void settable();
    void downloadall();
    void setRow(int i);
    void setflame();
    void setButton();

    QTableWidget *tableWidget;
    QStringList name,number,price;
};
#endif // WIDGET_H
