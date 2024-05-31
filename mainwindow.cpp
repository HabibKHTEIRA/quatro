#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _quatrowidget = new quatrowidget(this);
    setCentralWidget(_quatrowidget);

    createActions();
    createMenu();
}

MainWindow::~MainWindow()
{

}

void MainWindow::createActions() {
    _NouvellePartieAction = new QAction(tr("Nouvelle partie"), this);
    _NouvellePartieAction->setShortcut(tr("CTRL+N"));
    connect(_NouvellePartieAction, &QAction::triggered, this, &MainWindow::newPartie);

    _HistoriqueAction = new QAction(tr("Voir l'historique"), this);
    _HistoriqueAction->setShortcut(tr("CTRL+H"));
    connect(_HistoriqueAction, &QAction::triggered, this, &MainWindow::historique);

    _QuitterAction = new QAction(tr("Quitter"), this);
    _QuitterAction->setShortcut(QKeySequence::Quit);
    connect(_QuitterAction, &QAction::triggered, this, &QApplication::quit);

    _AboutQT = new QAction(tr("À propos de QT"), this);
    connect(_AboutQT, &QAction::triggered, this, &MainWindow::aboutQT);


    _AboutQuatro = new QAction(tr("À propos de Quatro"), this);
    connect(_AboutQuatro, &QAction::triggered, this, &MainWindow::aboutQuatro);


}

void MainWindow::createMenu() {
    QMenu *fileMenu = menuBar()->addMenu(tr("Fichier"));
    fileMenu->addAction(_NouvellePartieAction);
    fileMenu->addAction(_HistoriqueAction);
    fileMenu->addSeparator();
    fileMenu->addAction(_QuitterAction);


    QMenu *editMenu = menuBar()->addMenu(tr("À propos"));
    editMenu->addAction(_AboutQT);
    editMenu->addAction(_AboutQuatro);
}

void MainWindow::newPartie() {
    delete _quatrowidget;
    _quatrowidget = new quatrowidget(this);
    setCentralWidget(_quatrowidget);
}


void MainWindow::aboutQuatro(){
    std::string str = "Cette application a été réaliser par Habib KHTEIRA dans le cadre de l'unité Dèveloppement d'interface graphique de L3 Informatique.";

    QMessageBox::about(this, tr("À propos de Quatro"), QString::fromStdString(str));
}

void MainWindow::aboutQT(){
    QMessageBox::aboutQt(this,"À propos de QT");
}

void MainWindow::historique() {
    std::string str="";
    for (auto label : _quatrowidget->getHistorique()) {
        str += label->text().toStdString();
        str += "\n";
    }
    QMessageBox::information(this, tr("Historique"), QString::fromStdString(str));
}
