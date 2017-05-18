#include "bullet.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include "game.h"

extern Game * game;
Bullet::Bullet()
{
    setRect(0,0,10,50);

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50); //miils

    blood = 10;
}

void Bullet::move()
{
    // destory both when collides
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
       if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            game->score->increse();
            blood-=3;
            setPos(x(),y()+3);
            qDebug() << blood;
            if(blood <= 0){
            //scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
           // delete colliding_items[i];
            delete this;
            return;
            }
       }
    }

    // up!
    setPos(x(),y()-3);

    if(pos().y()+rect().height() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
