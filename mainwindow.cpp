#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QString alpha = {"abcdefghijklmnopqrstuvwxyz"};

    std::vector<QChar> letters = readCsv();

    const int LABEL_SPACING = 780/26;

    QPainter axis(this);
    QPainter label(this);
    QPainter mark(this);
    QPen linepen(Qt::red);
    linepen.setCapStyle(Qt::RoundCap);
    linepen.setWidth(2);
    mark.setRenderHint(QPainter::Antialiasing,true);
    mark.setPen(linepen);

    axis.drawLine(100, 50, 100, 830);
    axis.drawLine(100, 830, 880, 830);

    for(int i =0; i < 26; ++i)
    {

        label.drawText(QPoint(80, 830-((i+0.5)*LABEL_SPACING)),(QString)alpha[i]);
        label.drawText(QPoint(100+((i+0.5)*LABEL_SPACING), 850),(QString)alpha[i]);
    }

    for(int i =0; i<letters.size()-1; ++i)
    {
        QChar lX = letters.at(i).toLower();
        QChar lY = letters.at(++i).toLower();
        double x = ((convertLetterToInt(lX) * LABEL_SPACING) + (90 + LABEL_SPACING));
        double y = ((840 - LABEL_SPACING) -(convertLetterToInt(lY) * LABEL_SPACING));

        mark.drawPoint(QPointF(x,y));

    }

}

int MainWindow::convertLetterToInt(QChar l)
{
    return l.toLatin1() - 'a';
}

std::vector<QChar> MainWindow::readCsv()
{
    std::vector<QChar> letters;

    QFile file("D:/Users/Carlo/git/C++/Qt/qt_bars/InternetOfEnergy.csv");
        if(!file.open(QFile::ReadOnly | QFile::Text))
        {
            qDebug() << "File does not exists";
        }else
        {
            QTextStream in(&file);
            in.readLine();
            while(!in.atEnd())
            {
                QString line = in.readLine();
                for(int i=0; i < line.length(); ++i )
                {
                    if(line.at(i).isLetter())
                    {
                        letters.push_back(line.at(i));
                    }
                }

            }
            file.close();
        }
    return letters;
}
