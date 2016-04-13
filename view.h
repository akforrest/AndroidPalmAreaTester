#ifndef __VIEW_H
#define __VIEW_H

#include <QGraphicsView>

class Scene;
class MainWindow;

class View : public QGraphicsView
{
		Q_OBJECT

	public:

		View(Scene * scene, MainWindow * parent);

		bool event(QEvent *event) override;

	protected:

		void mousePressEvent(QMouseEvent * event);
		void mouseReleaseEvent(QMouseEvent * event);
		void mouseMoveEvent(QMouseEvent * event);
		void mouseDoubleClickEvent(QMouseEvent * event);

		Scene * m_scene;
		MainWindow * m_mainWindow;
};

#endif // __VIEW_H
