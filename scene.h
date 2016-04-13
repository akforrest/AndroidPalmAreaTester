#ifndef __SCENE_H
#define __SCENE_H

#include <QGraphicsScene>

class Scene : public QGraphicsScene
{
		Q_OBJECT

	public:

		Scene(QObject * parent);

	protected:

		void drawBackground(QPainter *painter, const QRectF & rect) override;
};

#endif // __SCENE_H
