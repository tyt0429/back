#ifndef MYTOWER_H
#define MYTOWER_H
#include <QGraphicsRectItem>
#include <QObject>

class MyTower:  public QObject,public QGraphicsRectItem{
    Q_OBJECT //inherit QObject to use signal
public:
    MyTower();

public slots:
    void spawn();
    void move();
    void attatck();
private:
    int blood;




};
#endif // MYTOWER_H
