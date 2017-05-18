#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
class Bullet: public QObject,public QGraphicsRectItem{
    Q_OBJECT //inherit QObject to use signal
public:
    Bullet();

public slots:
    void move();
private:
    int blood;
};

#endif // BULLET_H
