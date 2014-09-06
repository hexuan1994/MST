#ifndef SHOWVIEW_H
#define SHOWVIEW_H

#include <QGraphicsView>
#include "ShowScene.h"

class ShowView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit ShowView(QWidget *parent = 0);

signals:

public slots:
protected:
    void mouseDoubleClickEvent(QMouseEvent *event);

};

#endif // SHOWVIEW_H
