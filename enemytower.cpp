#include "bullet.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include "mytower.h"
#include "game.h"
#include "QGraphicsRectItem"
#include "enemy.h"
#include "enemytower.h"
extern Game * game;
EnemyTower::EnemyTower()
{
     setRect(0,0,100,100);
     blood = 100;


}



void EnemyTower::spawn()
{
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50); //miils

    //tower attack
    Enemy * enemeybullet = new Enemy();
    int random_number = rand()%700;
    enemeybullet->setPos(random_number,100);
    qDebug() << "created tower enemy~";
    scene()->addItem(enemeybullet);




}

void EnemyTower::move()
{
    // destory both when collides
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
       if(typeid(*(colliding_items[i])) == typeid(Bullet)){
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

void EnemyTower::attatck()
{

}
