#include "ShowView.h"

ShowView::ShowView(QWidget *parent) :
    QGraphicsView(parent)
{
    setMouseTracking(true);
    setDragMode(QGraphicsView::ScrollHandDrag);
}

void ShowView::mouseDoubleClickEvent(QMouseEvent *event){
    qDebug()<<"into view";
    if(scene()!=0)
       ((ShowScene*)scene())->mouseDoubleClickEvent(event);
}
