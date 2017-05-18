#include <QApplication>
#include "game.h"
/*
-QGraphicScene
-QGraphicItem (QGraphicsRectItem)
-QGraphicView

-events (keyPressEvent() and QkeyEvent)
-event porpogation system
-QDebug
*/
Game * game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();

    return a.exec();
}
