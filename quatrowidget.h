#ifndef QUATROWIDGET_H
#define QUATROWIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QKeyEvent>
#include <QLabel>
#include <QPixmap>
#include <QPainter>
#include <QDialog>
#include <string>

class quatrowidget : public QWidget
{
    Q_OBJECT

public:
    quatrowidget(QWidget *parent = nullptr);
    ~quatrowidget();
    std::vector<QLabel*> getHistorique(){
        return _historiques;
    }

public slots:
    void Chose_Piece();
    void Put_Piece(int row,int col);
    void changePlayer();


private:
    QIcon selectedIcon;
    QHBoxLayout *piecesLayout;
    int Njoueur=1;
    std::string _status = "Joueur Actif: " + std::to_string(Njoueur) + "\nJoueur " + std::to_string((Njoueur==1)?2:1) + " doit selectionner une piece que le joueur " + std::to_string(Njoueur) + " place.";
    std::string _footer="";
    QLabel *statusLabel;
    QLabel *footerLabel;
    std::vector<QLabel*> _historiques;
    int _col;
    int _row;
    int _index;

};

#endif // QUATROWIDGET_H


