#include "ShowScene.h"


void ShowScene::mousePressEvent(QMouseEvent *e){
    qDebug()<<e->pos();
}

void ShowScene::mouseDoubleClickEvent(QMouseEvent *e) {
    QGraphicsObject *item = (QGraphicsObject *)itemAt(e->pos(),QTransform());

    if(item== 0){
        QGraphicsItemPoint *item = new QGraphicsItemPoint();
        addItem(item);
        qDebug() << "vertex" <<item->pos().x() << " " << item->pos().y();
        qDebug()<<"addItem";
        item->setPos(e->pos());
        baseCalculate->addvertex(vertex((float)item->pos().x(),(float)item->pos().y()));
        clear();
        paintline();
        paintitem();

        update();
    }else{

        qDebug()<<"remove";
        baseCalculate->removevertex(vertex((float)item->pos().x(),(float)item->pos().y()));
        clear();
        paintline();
        paintitem();
        update();
    }
}


void ShowScene::paintline()
    {
        baseCalculate->DelCalculate();
        edgeSet edges = baseCalculate->GetEdges();
        edgeIterator tempedge = edges.begin();

        while(tempedge != edges.end())
        {
            QPoint  const pV0((int)(tempedge)->m_pV0->GetX(),(int)(tempedge)->m_pV0->GetY());
            QPoint  const pV1((int)(tempedge)->m_pV1->GetX(),(int)(tempedge)->m_pV1->GetY());
            QLine   tLine(pV0,pV1);
            addLine(tLine);
//            qDebug() << "Finally:a new line from (" <<(int)(tempedge)->m_pV0->GetX()<< ","<<(int)(tempedge)->m_pV0->GetY()
//                        <<") to ("<<(int)(tempedge)->m_pV1->GetX()<<","<< (int)(tempedge)->m_pV1->GetY()<<")";
            tempedge++;

        }
}

void ShowScene::paintitem()
{
    vertexSet vertexs = baseCalculate->GetVertexs();
    vIterator tempvertex = vertexs.begin();
    while(tempvertex != vertexs.end())
    {

        QPoint  const pV0((int)(tempvertex)->GetX(),(int)(tempvertex)->GetY());
        QGraphicsItemPoint   *ItemPoint = new QGraphicsItemPoint;
        ItemPoint->setPos(pV0);
        ItemPoint->acceptDrops();
        ItemPoint->acceptedMouseButtons();
        addItem(ItemPoint);
        tempvertex++;
        }
}


