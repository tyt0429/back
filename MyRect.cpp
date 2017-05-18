#include "MyRect.h"
#include <QKeyEvent>
#include "bullet.h"
#include <QDebug>
#include <QGraphicsScene>
#include "enemy.h"
#include "mytower.h"
#include <QTimer>



MyRect::MyRect(QGraphicsItem *parent):QGraphicsRectItem(parent)
{
}


void MyRect::keyPressEvent(QKeyEvent *event){
    /*if(event->key() == Qt::Key_Left){
        if(pos().x() > 0 )
            setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if(pos().x() + 100 < 800)
            setPos(x()+10,y());
    }
    else */
    if (event->key() == Qt::Key_Space){

        Bullet * bullet = new Bullet();
        int random_number = rand()%700;
        bullet->setPos(random_number,430);
        qDebug() << "created bullet~";
        scene()->addItem(bullet);


    }

}



void MyRect::spawn()
{   //create enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);

}


