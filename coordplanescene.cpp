#include "coordplanescene.h"

CoordPlaneScene::CoordPlaneScene(const QRectF& size_, const QPointF& gridsize_, QObject *parent)
    :QGraphicsScene(size_, parent)
    ,gridsize(gridsize_)
{
    // Set background color
    setBackgroundBrush (QBrush(Qt::white));
    // Add X and Y axis lines
    addLine(QLineF(-width(), 0, width(), 0),QPen(QBrush(Qt::black),1));
    addLine(QLineF(0, -height(), 0, height()),QPen(QBrush(Qt::black),1));
    // Set grid
    drawGrid();
}

// Function to set new grid size
void CoordPlaneScene::setGrid(const QPointF& gridsize_)
{
    // Delete previous grid from scene
    for(int i =0; i < griditems.size(); i++)
    {
        removeItem(griditems[i]);
        removeItem(coordinates[i]);
        delete griditems[i];
        delete coordinates[i];
    }
    griditems.clear();
    coordinates.clear();
    // Sets new grid
    gridsize = gridsize_;
    drawGrid();
}

void CoordPlaneScene::drawGrid()
{
    // Add vertical grid lines
    for(qreal i = -int(width()/gridsize.x())*gridsize.x(); i <= width(); i += gridsize.x())
    {
        griditems.append(addLine(QLineF(i, -height(), i, height()),QPen(QBrush(Qt::black),1,Qt::DashLine)));
        ReversedText* temp = new ReversedText(QString::number(i));
        addItem(temp);
        temp->moveBy(i, 0);
        coordinates.append(temp);
    }
    // Add horizontal grid lines
    for(qreal i = -int(height()/gridsize.y())*gridsize.y(); i <= height(); i += gridsize.y())
    {
        griditems.append(addLine(QLineF(-width(), i, width(), i),QPen(QBrush(Qt::black),1,Qt::DashLine)));
        ReversedText* temp = new ReversedText(QString::number(i));
        addItem(temp);
        temp->moveBy(0, i);
        coordinates.append(temp);
    }
}

void CoordPlaneScene::changeGridSize(qreal dx, qreal dy)
{
    if (gridsize.x() + dx > 0 && gridsize.y() + dy > 0)
        setGrid(QPointF(gridsize.x() + dx, gridsize.y() + dy));
}

