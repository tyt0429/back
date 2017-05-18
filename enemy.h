#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>
class Enemy: public QObject,public QGraphicsRectItem{
    Q_OBJECT //inherit QObject to use signal
public:
    Enemy();

public slots:
    void move();
private:
    int blood;
};

#endif // ENEMY_H
