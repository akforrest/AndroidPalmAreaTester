#include "scene.h"

#include <QPainter>

Scene::Scene(QObject * parent)
	: QGraphicsScene(0, 0, 1920, 1080, parent)
{
}

void Scene::drawBackground(QPainter *painter, const QRectF &)
{
	painter->fillRect(this->sceneRect(), backgroundBrush());
}
