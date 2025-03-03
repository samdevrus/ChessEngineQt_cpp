#include "tile.h"
#include "validation.h"
#include "QDebug"
validation *valid = new validation();

//extern QWidget *myWidget;
extern int count,turn;
Tile *ttemp;
extern Tile *click1;
bool validate(Tile *temp,int c);
void disOrange();

void Tile::mousePressEvent(QMouseEvent *event)
{
    if (validate(this,++count) ) {
        FieldCoordinate fc1 = FieldCoordinate(click1->col+1,8-click1->row);
        FieldCoordinate fc2 = FieldCoordinate(ttemp->col+1,8-ttemp->row);
        emit move(fc1,fc2);
    }

}

void Tile::display(char elem)
{
    this->pieceName=elem;

    if(this->pieceColor && this->piece)
    {
        switch(elem)
        {
            case 'P': this->setPixmap(QPixmap(":/Images/pawn_white.svg"));
                      break;
            case 'R': this->setPixmap(QPixmap(":/Images/rook_white.svg"));
                      break;
            case 'K': this->setPixmap(QPixmap(":/Images/knight_white.svg"));
                      break;
            case 'G': this->setPixmap(QPixmap(":/Images/king_white.svg"));
                      break;
            case 'Q': this->setPixmap(QPixmap(":/Images/queen_white.svg"));
                      break;
            case 'B': this->setPixmap(QPixmap(":/Images/bishop_white.svg"));
                      break;
        }
    }

    else if(this->piece)
    {
        switch(elem)
        {
        case 'P': this->setPixmap(QPixmap(":/Images/pawn_black.svg"));
                  break;
        case 'R': this->setPixmap(QPixmap(":/Images/rook_black.svg"));
                  break;
        case 'K': this->setPixmap(QPixmap(":/Images/knight_black.svg"));
                  break;
        case 'G': this->setPixmap(QPixmap(":/Images/king_black.svg"));
                  break;
        case 'Q': this->setPixmap(QPixmap(":/Images/queen_black.svg"));
                  break;
        case 'B': this->setPixmap(QPixmap(":/Images/bishop_black.svg"));
                  break;
        }
    }
    else
        this->clear();
}

bool validate(Tile *temp, int c)
{
    int retValue,i;
    if(c==1)
    {
        if(temp->piece && (temp->pieceColor==turn))
        {
            //exp[max++]=temp->tileNum;
            retValue=valid->chooser(temp);

            if(retValue)
            {
                click1= new Tile();
                temp->setStyleSheet("QLabel {background-color: green;}");
                click1=temp;
            }
            else
            {
                //temp->setStyleSheet("QLabel {background-color: red;}");
                count=0;
            }
        }
        else
        {
            //qDebug()<<"Rascel, clicking anywhere";
            count=0;
        }
    }

    else
    {

        if(temp->tileNum==click1->tileNum)
        {
            click1->tileDisplay();
            disOrange();
            max=0;
            count=0;
        }

        for(i=0;i<max;i++)
        {
            if(temp->tileNum==exp[i])
            {
                click1->piece=0;
                temp->piece=1;

                temp->pieceColor=click1->pieceColor;
                temp->pieceName=click1->pieceName;

                click1->display(click1->pieceName);
                temp->display(click1->pieceName);

                click1->tileDisplay();
                temp->tileDisplay();

                retValue=valid->check(click1);

                disOrange();

                max=0;

                turn=(turn+1)%2;
                FieldCoordinate fc1 = FieldCoordinate(temp->row,temp->col);
                FieldCoordinate fc2 = FieldCoordinate(click1->row,click1->col);
                ttemp = temp;

                count=0;
                return true;
                qDebug()<<"your Move:";

            }

            else
                count=1;
        }
    }
    return false;
}

void Tile::tileDisplay()
{

    if(this->tileColor)
        this->setStyleSheet("QLabel {background-color: rgb(120, 120, 90);}:hover{background-color: rgb(170,85,127);}");
    else
        this->setStyleSheet("QLabel {background-color: rgb(211, 211, 158);}:hover{background-color: rgb(170,95,127);}");
}

void disOrange()
{
    int i;

    for(i=0;i<max;i++)
        tile[exp[i]/8][exp[i]%8]->tileDisplay();

}
