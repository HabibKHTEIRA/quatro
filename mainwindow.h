#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QApplication>
#include <QLabel>
#include <QSpinBox>
#include <QFileDialog>
#include <QMessageBox>


#include "quatrowidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void newPartie();
    void aboutQT();
    void aboutQuatro();
    void historique();


private:

    void createActions();
    void createMenu();
    void createToolBar();

    QAction *_NouvellePartieAction;
    QAction *_HistoriqueAction;
    QAction *_QuitterAction;

    QAction *_AboutQT;
    QAction *_AboutQuatro;


    quatrowidget *_quatrowidget;
};

#endif // MAINWINDOW_H




