#include "bullet.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include "mytower.h"
#include "game.h"
#include "QGraphicsRectItem"
#include "enemy.h"
extern Game * game;
MyTower::MyTower()
{
     setRect(0,0,100,100);
     blood = 100;


}



void MyTower::spawn()
{
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50); //miils

    //tower attack
    Bullet * bullet = new Bullet();
    int random_number = rand()%700;
    bullet->setPos(random_number,430);
    qDebug() << "created tower bullet~";
    scene()->addItem(bullet);




}

void MyTower::move()
{
    // destory both when collides
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
       if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            game->score->increse();
            blood-=50;
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




}

void MyTower::attatck()
{

}
