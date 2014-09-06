#include "QGraphicsItempoint.h"
#include "ShowScene.h"
#include <QBrush>
#include <QGraphicsScene>
void QGraphicsItemPoint::mousePressEvent(QGraphicsSceneMouseEvent *event){
    qDebug()<<event->pos();
    isPressed = true;
    scene()->update(sceneBoundingRect());

}

void QGraphicsItemPoint::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    setPos(event->scenePos());
}
void QGraphicsItemPoint::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    isPressed = false;
    scene()->update(sceneBoundingRect());

    ((ShowScene*)scene())->baseCalculate->addvertex(vertex((float)event->pos().x(),(float)event->pos().y()));

    ((ShowScene*)scene())->clear();qDebug() << "2";
    ((ShowScene*)scene())->baseCalculate->DelCalculate();qDebug() << "3";
    ((ShowScene*)scene())->paintitem();
    ((ShowScene*)scene())->paintline();
}

QBrush QGraphicsItemPoint::defaultBrush = QBrush(QColor(200,15,15,200));
QBrush QGraphicsItemPoint::specialBrush = QBrush(QColor(0,15,200,200));


void QGraphicsItemPoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    if(isPressed)
        painter->setBrush(specialBrush);
    else
        painter->setBrush(defaultBrush);
    painter->drawRoundedRect(-10,-10,20,20,99,99);
}
