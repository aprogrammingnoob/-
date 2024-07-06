#ifndef SON_H
#define SON_H

#include <QWidget>
#include<QProcess>
namespace Ui {
class son;
}

class son : public QWidget
{
    Q_OBJECT

public:
    explicit son(QWidget *parent = nullptr);
    ~son();


private:
    Ui::son *ui;
public slots:
    void sSlot();
signals:
    void sSignal();
private slots:
    void on_signalButton_clicked();
    void on_confirmButton_clicked();
};

#endif // SON_H
