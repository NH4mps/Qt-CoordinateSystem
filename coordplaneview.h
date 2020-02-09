/* Class is created to support CoordPlaneScene
 * Turns scene upside down making its coordinate system right-handed
 * Allows to scale coordinate system
 * The problem for now is to change font size of coordinates with scaling
*/

#ifndef COORDPLANEVIEW_H
#define COORDPLANEVIEW_H

#include <QGraphicsView>
#include <QDebug>
#include <QKeyEvent>
#include <QMessageBox>
#include <QPushButton>
#include "coordplanescene.h"



class CoordPlaneView : public QGraphicsView
{
    Q_OBJECT
public:
    CoordPlaneView(CoordPlaneScene *scene, QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    qreal x;
    qreal y;

protected slots:
    void zoom(qreal x_coef, qreal y_coef);
    void standartScale();
};

#endif // COORDPLANEVIEW_H
