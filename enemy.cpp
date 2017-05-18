#include "enemy.h"
#include <QTimer>
#include <QDebug>
#include <stdlib.h>
#include <QGraphicsScene>
#include "game.h"
#include "bullet.h"

extern Game * game;
Enemy::Enemy()
{


    //set position
    int random_number = rand()%700;
    setPos(random_number,0);
    setRect(0,0,100,100);


    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50); //miils

    blood = 10;
}

void Enemy::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
       if(typeid(*(colliding_items[i])) == typeid(Bullet)){
            game->score->increse();
            blood-=5;
            setPos(x(),y()-1);//keep same location
            qDebug() << blood;
            if(blood <= 0){
            //scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete colliding_items[i];
            delete this;
            return;
            }
       }
    }
    // down!
    setPos(x(),y()+1);

    if(pos().y() > 500){
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
        qDebug() << "enemy bye";
    }
}
