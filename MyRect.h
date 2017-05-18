#ifndef MYRECT_H
#define MYRECT_H


#include <QGraphicsRectItem>
#include <QObject>
#include <QMediaPlayer>

class MyRect:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    MyRect(QGraphicsItem * parent=0);
public slots:
    void spawn();
    void keyPressEvent(QKeyEvent * event);
private:


};

#endif // MYRECT_H
