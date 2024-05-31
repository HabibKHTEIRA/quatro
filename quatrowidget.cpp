#include"quatrowidget.h"
#include<math.h>
#include <sstream>
#include <QMessageBox>
#include <fstream>

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream ss(s);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

quatrowidget::quatrowidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    piecesLayout = new QHBoxLayout;
    QGridLayout *boardLayout = new QGridLayout;
    statusLabel = new QLabel(QString::fromStdString(_status));


    QPixmap pix(50, 50);
    QPainter painter(&pix);
    painter.setPen(QColor(31,31,31));
    painter.setBrush(QColor(250, 250, 250));
    painter.drawRect(0, 0, 50, 50);


    QPushButton *CLAIRE_PETIT_ROND_TROU = new QPushButton;
    painter.setBrush(QColor(253, 245, 172));
    painter.drawEllipse(14, 14, 22, 22);
    painter.setBrush(QColor(51, 25, 0));
    painter.drawEllipse(23, 23, 4, 4);
    CLAIRE_PETIT_ROND_TROU->setIcon(QIcon(pix));
    CLAIRE_PETIT_ROND_TROU->setIconSize(pix.size());
    piecesLayout->addWidget(CLAIRE_PETIT_ROND_TROU);
    CLAIRE_PETIT_ROND_TROU->setObjectName("CLAIRE-PETIT-ROND-TROU");
    connect(CLAIRE_PETIT_ROND_TROU, &QPushButton::clicked, this, &quatrowidget::Chose_Piece);

    painter.setBrush(QColor(250, 250, 250));
    painter.drawRect(0, 0, 50, 50);


    QPushButton *CLAIRE_PETIT_ROND_PLEIN = new QPushButton;
    painter.setBrush(QColor(253, 245, 172));
    painter.drawEllipse(14, 14, 22, 22);
    CLAIRE_PETIT_ROND_PLEIN->setIcon(QIcon(pix));
    CLAIRE_PETIT_ROND_PLEIN->setIconSize(pix.size());
    piecesLayout->addWidget(CLAIRE_PETIT_ROND_PLEIN);
    connect(CLAIRE_PETIT_ROND_PLEIN, &QPushButton::clicked, this, &quatrowidget::Chose_Piece);
    CLAIRE_PETIT_ROND_PLEIN->setObjectName("CLAIRE-PETIT-ROND-PLEIN");

    painter.setBrush(QColor(250, 250, 250));
    painter.drawRect(0, 0, 50, 50);


    QPushButton *CLAIRE_PETIT_CARRE_TROU = new QPushButton;
    painter.setBrush(QColor(253, 245, 172));
    painter.drawRect(14, 14, 22, 22);
    painter.setBrush(QColor(51, 25, 0));
    painter.drawEllipse(23, 23, 4, 4);
    CLAIRE_PETIT_CARRE_TROU->setIcon(QIcon(pix));
    CLAIRE_PETIT_CARRE_TROU->setIconSize(pix.size());
    piecesLayout->addWidget(CLAIRE_PETIT_CARRE_TROU);
    connect(CLAIRE_PETIT_CARRE_TROU, &QPushButton::clicked, this, &quatrowidget::Chose_Piece);
    CLAIRE_PETIT_CARRE_TROU->setObjectName("CLAIRE-PETIT-CARRE-TROU");

    painter.setBrush(QColor(250, 250, 250));
    painter.drawRect(0, 0, 50, 50);


    QPushButton *CLAIRE_PETIT_CARRE_PLEIN = new QPushButton;
    painter.setBrush(QColor(253, 245, 172));
    painter.drawRect(14, 14, 22, 22);
    CLAIRE_PETIT_CARRE_PLEIN->setIcon(QIcon(pix));
    CLAIRE_PETIT_CARRE_PLEIN->setIconSize(pix.size());
    piecesLayout->addWidget(CLAIRE_PETIT_CARRE_PLEIN);
    connect(CLAIRE_PETIT_CARRE_PLEIN, &QPushButton::clicked, this, &quatrowidget::Chose_Piece);
    CLAIRE_PETIT_CARRE_PLEIN->setObjectName("CLAIRE-PETIT-CARRE-PLEIN");

    painter.setBrush(QColor(250, 250, 250));
    painter.drawRect(0, 0, 50, 50);


    QPushButton *CLAIRE_GRAND_ROND_TROU = new QPushButton;
    painter.setBrush(QColor(253, 245, 172));
    painter.drawEllipse(1, 1, 48, 48);
    painter.setBrush(QColor(51, 25, 0));
    painter.drawEllipse(23, 23, 4, 4);
    CLAIRE_GRAND_ROND_TROU->setIcon(QIcon(pix));
    CLAIRE_GRAND_ROND_TROU->setIconSize(pix.size());
    piecesLayout->addWidget(CLAIRE_GRAND_ROND_TROU);
    connect(CLAIRE_GRAND_ROND_TROU, &QPushButton::clicked, this, &quatrowidget::Chose_Piece);
    CLAIRE_GRAND_ROND_TROU->setObjectName("CLAIRE-GRAND-ROND-TROU");

    painter.setBrush(QColor(250, 250, 250));
    painter.drawRect(0, 0, 50, 50);


    QPushButton *CLAIRE_GRAND_ROND_PLEIN = new QPushButton;
    painter.setBrush(QColor(253, 245, 172));
    painter.drawEllipse(1, 1, 48, 48);
    CLAIRE_GRAND_ROND_PLEIN->setIcon(QIcon(pix));
    CLAIRE_GRAND_ROND_PLEIN->setIconSize(pix.size());
    piecesLayout->addWidget(CLAIRE_GRAND_ROND_PLEIN);
    connect(CLAIRE_GRAND_ROND_PLEIN, &QPushButton::clicked, this, &quatrowidget::Chose_Piece);
    CLAIRE_GRAND_ROND_PLEIN->setObjectName("CLAIRE-GRAND-ROND-PLEIN");

    painter.setBrush(QColor(250, 250, 250));
    painter.drawRect(0, 0, 50, 50);


    QPushButton *CLAIRE_GRAND_CARRE_TROU = new QPushButton;
    painter.setBrush(QColor(253, 245, 172));
    painter.drawRect(1, 1, 48, 48);
    painter.setBrush(QColor(51, 25, 0));
    painter.drawEllipse(23, 23, 4, 4);
    CLAIRE_GRAND_CARRE_TROU->setIcon(QIcon(pix));
    CLAIRE_GRAND_CARRE_TROU->setIconSize(pix.size());
    piecesLayout->addWidget(CLAIRE_GRAND_CARRE_TROU);
    connect(CLAIRE_GRAND_CARRE_TROU, &QPushButton::clicked, this, &quatrowidget::Chose_Piece);
    CLAIRE_GRAND_CARRE_TROU->setObjectName("CLAIRE-GRAND-CARRE-TROU");

    painter.setBrush(QColor(250, 250, 250));
    painter.drawRect(0, 0, 50, 50);


    QPushButton *CLAIRE_GRAND_CARRE_PLEIN = new QPushButton;
    painter.setBrush(QColor(253, 245, 172));
    painter.drawRect(1, 1, 48, 48);
    CLAIRE_GRAND_CARRE_PLEIN->setIcon(QIcon(pix));
    CLAIRE_GRAND_CARRE_PLEIN->setIconSize(pix.size());
    piecesLayout->addWidget(CLAIRE_GRAND_CARRE_PLEIN);
    connect(CLAIRE_GRAND_CARRE_PLEIN, &QPushButton::clicked, this, &quatrowidget::Chose_Piece);
    CLAIRE_GRAND_CARRE_PLEIN->setObjectName("CLAIRE-GRAND-CARRE-PLEIN");


    painter.setBrush(QColor(250, 250, 250));
    painter.drawRect(0, 0, 50, 50);


    QPushButton *SOMBRE_PETIT_ROND_TROU = new QPushButton;
    painter.setBrush(QColor(51, 25, 0));
    painter.drawEllipse(14, 14, 22, 22);
    painter.setBrush(QColor(253, 245, 172));
    painter.drawEllipse(23, 23, 4, 4);
    SOMBRE_PETIT_ROND_TROU->setIcon(QIcon(pix));
    SOMBRE_PETIT_ROND_TROU->setIconSize(pix.size());
    piecesLayout->addWidget(SOMBRE_PETIT_ROND_TROU);
    connect(SOMBRE_PETIT_ROND_TROU, &QPushButton::clicked, this, &quatrowidget::Chose_Piece);
    SOMBRE_PETIT_ROND_TROU->setObjectName("SOMBRE-PETIT-ROND-TROU");

    painter.setBrush(QColor(250, 250, 250));
    painter.drawRect(0, 0, 50, 50);


    QPushButton *SOMBRE_PETIT_ROND_PLEIN = new QPushButton;
    painter.setBrush(QColor(51, 25, 0));
    painter.drawEllipse(14, 14, 22, 22);
    SOMBRE_PETIT_ROND_PLEIN->setIcon(QIcon(pix));
    SOMBRE_PETIT_ROND_PLEIN->setIconSize(pix.size());
    piecesLayout->addWidget(SOMBRE_PETIT_ROND_PLEIN);
    connect(SOMBRE_PETIT_ROND_PLEIN, &QPushButton::clicked, this, &quatrowidget::Chose_Piece);
    SOMBRE_PETIT_ROND_PLEIN->setObjectName("SOMBRE-PETIT-ROND-PLEIN");

    painter.setBrush(QColor(250, 250, 250));
    painter.drawRect(0, 0, 50, 50);


    QPushButton *SOMBRE_PETIT_CARRE_TROU = new QPushButton;
    painter.setBrush(QColor(51, 25, 0));
    painter.drawRect(14, 14, 22, 22);
    painter.setBrush(QColor(253, 245, 172));
    painter.drawEllipse(23, 23, 4, 4);
    SOMBRE_PETIT_CARRE_TROU->setIcon(QIcon(pix));
    SOMBRE_PETIT_CARRE_TROU->setIconSize(pix.size());
    piecesLayout->addWidget(SOMBRE_PETIT_CARRE_TROU);
    connect(SOMBRE_PETIT_CARRE_TROU, &QPushButton::clicked, this, &quatrowidget::Chose_Piece);
    SOMBRE_PETIT_CARRE_TROU->setObjectName("SOMBRE-PETIT-CARRE-TROU");

    painter.setBrush(QColor(250, 250, 250));
    painter.drawRect(0, 0, 50, 50);


    QPushButton *SOMBRE_PETIT_CARRE_PLEIN = new QPushButton;
    painter.setBrush(QColor(51, 25, 0));
    painter.drawRect(14, 14, 22, 22);
    SOMBRE_PETIT_CARRE_PLEIN->setIcon(QIcon(pix));
    SOMBRE_PETIT_CARRE_PLEIN->setIconSize(pix.size());
    piecesLayout->addWidget(SOMBRE_PETIT_CARRE_PLEIN);
    connect(SOMBRE_PETIT_CARRE_PLEIN, &QPushButton::clicked, this, &quatrowidget::Chose_Piece);
    SOMBRE_PETIT_CARRE_PLEIN->setObjectName("SOMBRE-PETIT-CARRE-PLEIN");

    painter.setBrush(QColor(250, 250, 250));
    painter.drawRect(0, 0, 50, 50);


    QPushButton *SOMBRE_GRAND_ROND_TROU = new QPushButton;
    painter.setBrush(QColor(51, 25, 0));
    painter.drawEllipse(1, 1, 48, 48);
    painter.setBrush(QColor(253, 245, 172));
    painter.drawEllipse(23, 23, 4, 4);
    SOMBRE_GRAND_ROND_TROU->setIcon(QIcon(pix));
    SOMBRE_GRAND_ROND_TROU->setIconSize(pix.size());
    piecesLayout->addWidget(SOMBRE_GRAND_ROND_TROU);
    connect(SOMBRE_GRAND_ROND_TROU, &QPushButton::clicked, this, &quatrowidget::Chose_Piece);
    SOMBRE_GRAND_ROND_TROU->setObjectName("SOMBRE-GRAND-ROND-TROU");

    painter.setBrush(QColor(250, 250, 250));
    painter.drawRect(0, 0, 50, 50);


    QPushButton *SOMBRE_GRAND_ROND_PLEIN = new QPushButton;
    painter.setBrush(QColor(51, 25, 0));
    painter.drawEllipse(1, 1, 48, 48);
    SOMBRE_GRAND_ROND_PLEIN->setIcon(QIcon(pix));
    SOMBRE_GRAND_ROND_PLEIN->setIconSize(pix.size());
    piecesLayout->addWidget(SOMBRE_GRAND_ROND_PLEIN);
    connect(SOMBRE_GRAND_ROND_PLEIN, &QPushButton::clicked, this, &quatrowidget::Chose_Piece);
    SOMBRE_GRAND_ROND_PLEIN->setObjectName("SOMBRE-GRAND-ROND-PLEIN");

    painter.setBrush(QColor(250, 250, 250));
    painter.drawRect(0, 0, 50, 50);


    QPushButton *SOMBRE_GRAND_CARRE_TROU = new QPushButton;
    painter.setBrush(QColor(51, 25, 0));
    painter.drawRect(1, 1, 48, 48);
    painter.setBrush(QColor(253, 245, 172));
    painter.drawEllipse(23, 23, 4, 4);
    SOMBRE_GRAND_CARRE_TROU->setIcon(QIcon(pix));
    SOMBRE_GRAND_CARRE_TROU->setIconSize(pix.size());
    piecesLayout->addWidget(SOMBRE_GRAND_CARRE_TROU);
    connect(SOMBRE_GRAND_CARRE_TROU, &QPushButton::clicked, this, &quatrowidget::Chose_Piece);
    SOMBRE_GRAND_CARRE_TROU->setObjectName("SOMBRE-GRAND-CARRE-TROU");

    painter.setBrush(QColor(250, 250, 250));
    painter.drawRect(0, 0, 50, 50);


    QPushButton *SOMBRE_GRAND_CARRE_PLEIN = new QPushButton;
    painter.setBrush(QColor(51, 25, 0));
    painter.drawRect(1, 1, 48, 48);
    SOMBRE_GRAND_CARRE_PLEIN->setIcon(QIcon(pix));
    SOMBRE_GRAND_CARRE_PLEIN->setIconSize(pix.size());
    piecesLayout->addWidget(SOMBRE_GRAND_CARRE_PLEIN);
    connect(SOMBRE_GRAND_CARRE_PLEIN, &QPushButton::clicked, this, &quatrowidget::Chose_Piece);
    SOMBRE_GRAND_CARRE_PLEIN->setObjectName("SOMBRE-GRAND-CARRE-PLEIN");

    painter.setBrush(QColor(250, 250, 250));
    painter.drawRect(0, 0, 50, 50);
    for (int i = 0; i < 16; ++i) {
        QPushButton *pieceButton = new QPushButton;
        pieceButton->setIcon(QIcon(pix));
        pieceButton->setIconSize(pix.size());

        int row = floor(i / 4);
        int col = i % 4;
        boardLayout->addWidget(pieceButton, row, col);
        connect(pieceButton, &QPushButton::clicked, this, [this, row, col]() {Put_Piece(row, col);});
    }

    footerLabel = new QLabel(QString::fromStdString(_footer));

    mainLayout->addStretch();
    mainLayout->addWidget(statusLabel);
    mainLayout->addStretch();
    mainLayout->addLayout(piecesLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(boardLayout);
    mainLayout->addStretch();
    mainLayout->addWidget(footerLabel);

    statusLabel->setAlignment(Qt::AlignCenter);
    piecesLayout->setAlignment(Qt::AlignCenter);
    boardLayout->setAlignment(Qt::AlignCenter);
    footerLabel->setAlignment(Qt::AlignLeft);
   }

quatrowidget::~quatrowidget()
{

}

void quatrowidget::Chose_Piece() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        selectedIcon = button->icon();
        _footer = button->objectName().toStdString();
        footerLabel->setText(QString::fromStdString(_footer));
    }
}

void quatrowidget::Put_Piece(int row, int col) {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button && !selectedIcon.isNull()) {
        button->setIcon(selectedIcon);
        _col = col;
        _row = row;
        QLabel *his = new QLabel(QString::fromStdString("joueur "+std::to_string(Njoueur)+" a placé "+_footer+" en ("+std::to_string(_row)+","+std::to_string(_col)+")"));
        _historiques.push_back(his);
        changePlayer();
        _status = "Joueur Actif: " + std::to_string(Njoueur) + "\nJoueur " + std::to_string((Njoueur==1)?2:1) + " doit selectionner une piece que le joueur " + std::to_string(Njoueur) + " place.";
        statusLabel->setText(QString::fromStdString(_status));
        for (int i = 0; i < piecesLayout->count(); ++i) {
            QLayoutItem* item = piecesLayout->itemAt(i);
            if (item && item->widget() && item->widget()->objectName() == QString::fromStdString(_footer)) {
                piecesLayout->removeItem(item);
                delete item->widget();
                delete item;
                break;
            }
        }

        std::vector<std::vector<std::string>> rowVoisins;
        std::vector<std::vector<std::string>> colVoisins;
        std::vector<std::vector<std::string>> diag1Voisins;
        std::vector<std::vector<std::string>> diag2Voisins;
        if(_historiques.size()>1){
            for (unsigned long i = 0; i < _historiques.size(); ++i) {
                 QLabel* labeltest = _historiques[i];
                 std::string labelText = labeltest->text().toStdString();
                 int start = labelText.find("(")+1;
                 std::string coordinates = labelText.substr(start,3);
                 int ligne = coordinates[0] - '0';
                 int colonne = coordinates[2] - '0';
                 if (ligne == row){
                     std::string characteristiques = labelText.substr(18,start - 5 - 18);
                     std::vector<std::string> characteristiquesList = split(characteristiques, '-');
                     rowVoisins.push_back(characteristiquesList);
                 }
                 if(colonne == col){
                     std::string characteristiques = labelText.substr(18,start - 5 - 18);
                     std::vector<std::string> characteristiquesList = split(characteristiques, '-');
                     colVoisins.push_back(characteristiquesList);
                 }
                 if(colonne==ligne){
                     std::string characteristiques = labelText.substr(18,start - 5 - 18);
                     std::vector<std::string> characteristiquesList = split(characteristiques, '-');
                     diag1Voisins.push_back(characteristiquesList);
                 }
                 if(colonne+ligne == 3){
                     std::string characteristiques = labelText.substr(18,start - 5 - 18);
                     std::vector<std::string> characteristiquesList = split(characteristiques, '-');
                     diag2Voisins.push_back(characteristiquesList);
                 }
            }
        }
        bool compt = false;
        if(rowVoisins.size()==4 && !compt){
            compt = true;
            std::vector<std::string> _List = split(_footer, '-');
            for(auto i:_List){
                compt=true;
                for (auto v:rowVoisins){
                    auto it = std::find(v.begin(), v.end(), i);
                    if (it == v.end()) {
                        compt = false;
                        break;
                    }
                }
                if(compt){
                    std::string victoireLabel = "Fin de la partie. Victoire du joueur "+std::to_string((Njoueur==1)?2:1)+"!";
                    QLabel *fin = new QLabel(QString::fromStdString(victoireLabel));
                    _historiques.push_back(fin);

                    std::string msg = "Felicitation! joueur "+std::to_string((Njoueur==1)?2:1)+" a gangé!";
                    QMessageBox::information(this, tr("Gagnant!"), QString::fromStdString(msg));

                    std::ofstream outputFile("history.log");
                    if (outputFile.is_open()) {
                        for (auto label : _historiques) {
                            outputFile << label->text().toStdString() << std::endl;
                        }
                        outputFile.close();
                    }
                    break;
                }
            }
        }
        if(colVoisins.size()==4 && !compt){
            compt=true;
            std::vector<std::string> _List = split(_footer, '-');
            for(auto i:_List){
                compt=true;
                for (auto v:colVoisins){
                    auto it = std::find(v.begin(), v.end(), i);
                    if (it == v.end()) {
                        compt = false;
                        break;
                    }
                }
                if(compt){
                    std::string victoireLabel = "Fin de la partie. Victoire du joueur "+std::to_string((Njoueur==1)?2:1)+"!";
                    QLabel *fin = new QLabel(QString::fromStdString(victoireLabel));
                    _historiques.push_back(fin);

                    std::string msg = "Felicitation! joueur "+std::to_string((Njoueur==1)?2:1)+" a gangé!";
                    QMessageBox::information(this, tr("Gagnant!"), QString::fromStdString(msg));

                    std::ofstream outputFile("history.log");
                    if (outputFile.is_open()) {
                        for (auto label : _historiques) {
                            outputFile << label->text().toStdString() << std::endl;
                        }
                        outputFile.close();
                    }
                    break;
                }
            }
        }
        if(diag1Voisins.size()==4 && !compt){
            compt=true;
            std::vector<std::string> _List = split(_footer, '-');
            for(auto i:_List){
                compt=true;
                for (auto v:diag1Voisins){
                    auto it = std::find(v.begin(), v.end(), i);
                    if (it == v.end()) {
                        compt = false;
                        break;
                    }
                }
                if(compt){
                    std::string victoireLabel = "Fin de la partie. Victoire du joueur "+std::to_string((Njoueur==1)?2:1)+"!";
                    QLabel *fin = new QLabel(QString::fromStdString(victoireLabel));
                    _historiques.push_back(fin);

                    std::string msg = "Felicitation! joueur "+std::to_string((Njoueur==1)?2:1)+" a gangé!";
                    QMessageBox::information(this, tr("Gagnant!"), QString::fromStdString(msg));

                    std::ofstream outputFile("history.log");
                    if (outputFile.is_open()) {
                        for (auto label : _historiques) {
                            outputFile << label->text().toStdString() << std::endl;
                        }
                        outputFile.close();
                    }
                    break;
                }
            }
        }
        if(diag2Voisins.size()==4 && !compt){
            compt=true;
            std::vector<std::string> _List = split(_footer, '-');
            for(auto i:_List){
                compt=true;
                for (auto v:diag2Voisins){
                    auto it = std::find(v.begin(), v.end(), i);
                    if (it == v.end()) {
                        compt = false;
                        break;
                    }
                }
                if(compt){
                    std::string victoireLabel = "Fin de la partie. Victoire du joueur "+std::to_string((Njoueur==1)?2:1)+"!";
                    QLabel *fin = new QLabel(QString::fromStdString(victoireLabel));
                    _historiques.push_back(fin);

                    std::string msg = "Felicitation! joueur "+std::to_string((Njoueur==1)?2:1)+" a gangé!";
                    QMessageBox::information(this, tr("Gagnant!"), QString::fromStdString(msg));

                    std::ofstream outputFile("history.log");
                    if (outputFile.is_open()) {
                        for (auto label : _historiques) {
                            outputFile << label->text().toStdString() << std::endl;
                        }
                        outputFile.close();
                    }
                    break;
                }
            }
        }
    }
}



void quatrowidget::changePlayer(){
    Njoueur = (Njoueur==1)?2:1;
}





