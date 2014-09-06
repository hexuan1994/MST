#ifndef SHOWSCENE_H
#define SHOWSCENE_H

#include "QGraphicsItemPoint.h"
#include "basecalculate.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QDebug>

class ShowView;
class ShowScene: public QGraphicsScene
{
public:
    ShowScene(QGraphicsView *view, QObject *parent = 0):QGraphicsScene(parent){
        view->setScene(this);
        setSceneRect(view->rect());
        baseCalculate = new BaseCalculate;
    }
    void paintline();
    void paintitem();
    friend class ShowView;
    BaseCalculate* baseCalculate;
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *e);
private:

    vertexSet vertexs;
    edgeSet edges;
};

#endif // SHOWSCENE_H
