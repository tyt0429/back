#ifndef GAME_H
#define GAME_H


#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>
#include <QTimer>
#include "score.h"
#include "health.h"
#include "mytower.h"
#include <QGraphicsRectItem>
#include "mytower.h"
#include "enemytower.h"
class Game:public QGraphicsView{
public:
   Game(QWidget * parent=0);

   QGraphicsScene * scene;
   MyRect * player;
   Score * score;
   Health * health;

};


#endif // GAME_H
