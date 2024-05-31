#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*QTranslator translator;
    if(translator.load(QLocale::system(), "Annotations", "_", a.applicationDirPath(), ".qm")) {
        a.installTranslator(&translator);
    }*/

    MainWindow w;
    w.setWindowTitle("Quatro");
    QIcon icon("./Quatro.jpg");
    w.setWindowIcon(icon);
    a.setWindowIcon(icon);
    w.show();

    return a.exec();
}
