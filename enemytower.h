#ifndef ENEMYTOWER_H
#define ENEMYTOWER_H
#include <QGraphicsRectItem>
#include <QObject>

class EnemyTower:  public QObject,public QGraphicsRectItem{
    Q_OBJECT //inherit QObject to use signal
public:
    EnemyTower();

public slots:
    void spawn();
    void move();
    void attatck();
private:
    int blood;




};
#endif // ENEMYTOWER_H
