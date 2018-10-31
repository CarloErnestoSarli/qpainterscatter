#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QFile>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void paintEvent(QPaintEvent *event);

    int convertLetterToInt(QChar l);
    std::vector<QChar> readCsv();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
