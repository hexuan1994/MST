#ifndef QGRAPHICSITEMPOINT_H
#define QGRAPHICSITEMPOINT_H

#include <QGraphicsObject>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

class QGraphicsItemPoint : public QGraphicsObject
{
public:
    QRectF boundingRect() const
    {
        return QRect(-10,-10,20,20);
    }
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    static QBrush defaultBrush;
    static QBrush specialBrush;
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    bool isPressed = false;

};

#endif // QGRAPHICSITEMPOINT_H
