
#include "game.h"
#include <QUrl>
Game::Game(QWidget * parent): QGraphicsView(parent)
{


    // create a scene
    scene = new QGraphicsScene();

    // create an item to put into the scene
    MyRect * player = new MyRect();
    player->setRect(0,0,100,100);

    // add the item to the scene
    scene->addItem(player);

    // make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    player->setPos(300,height()-player->rect().height());

    // create the score
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    MyTower * tower1 = new MyTower ();
    tower1->setPos(30,height()-player->rect().height());

     MyTower * tower2 = new MyTower ();
    tower2->setPos(300,height()-player->rect().height());

     MyTower * tower3 = new MyTower ();
    tower3->setPos(570,height()-player->rect().height());

    scene->addItem(tower1);
    scene->addItem(tower2);
    scene->addItem(tower3);

    EnemyTower * etower1 = new EnemyTower ();
    etower1->setPos(30,0);

     EnemyTower * etower2 = new EnemyTower ();
    etower2->setPos(300,0);

     EnemyTower * etower3 = new EnemyTower ();
    etower3->setPos(570,0);

    scene->addItem(etower1);
    scene->addItem(etower2);
    scene->addItem(etower3);

    //spawn enemies
    QTimer * timer = new QTimer();
    QTimer * timer2 = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    QObject::connect(timer2,SIGNAL(timeout()),tower1,SLOT(spawn()));
    QObject::connect(timer2,SIGNAL(timeout()),tower2,SLOT(spawn()));
    QObject::connect(timer2,SIGNAL(timeout()),tower3,SLOT(spawn()));
    QObject::connect(timer2,SIGNAL(timeout()),etower1,SLOT(spawn()));
    QObject::connect(timer2,SIGNAL(timeout()),etower2,SLOT(spawn()));
    QObject::connect(timer2,SIGNAL(timeout()),etower3,SLOT(spawn()));
    timer->start(500);
    timer2->start(5000);



    show();
}

