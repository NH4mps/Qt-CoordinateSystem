#include "coordplaneview.h"

CoordPlaneView::CoordPlaneView(CoordPlaneScene *scene, QWidget *parent)
    :QGraphicsView(scene, parent)
{
    x=1;
    y=1;
    scale(1,-1);
}

void CoordPlaneView::standartScale()
{
    scale(1/x,1/y);
    x=1;
    y=1;
}

void CoordPlaneView::zoom(qreal x_coef, qreal y_coef)
{
    if(x * x_coef > 0 && y * y_coef > 0)
    {
        x*=x_coef;
        y*=y_coef;
        scale(x_coef,y_coef);
    }
    else
    {
        QMessageBox* pmbx = new QMessageBox
                (QMessageBox::Warning,
                "MessageBox",
                "Coefficients should be positive",
                QMessageBox::Ok
                ) ;
        pmbx->exec();
        delete pmbx;
    }
}

void CoordPlaneView::keyPressEvent(QKeyEvent* pe)
{
    QGraphicsView::keyPressEvent(pe);
    switch  (pe->key())
    {
        case Qt::Key_Equal:
            if((pe->modifiers() & Qt::ControlModifier))
               zoom(1.1,1.1);
            break;
        case Qt::Key_Minus:
            if(pe->modifiers() & Qt::ControlModifier)
                zoom(0.9,0.9);
            break;
        case Qt::Key_0:
            if(pe->modifiers() & Qt::ControlModifier)
                standartScale();
            break;
        default:
           qDebug() << "You pressed wrong buttons\n";
    }
}
