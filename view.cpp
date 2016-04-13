#include "view.h"

#include "scene.h"
#include "mainwindow.h"

#include <QMouseEvent>

View::View(Scene * scene, MainWindow * parent)
	: QGraphicsView(scene, parent),
	  m_scene(scene),
	  m_mainWindow(parent)
{
	this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

	this->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
	this->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing);

	this->viewport()->setAttribute(Qt::WA_AcceptTouchEvents);
	this->setAttribute(Qt::WA_AcceptTouchEvents);

	this->setDragMode(QGraphicsView::NoDrag);

	this->setBackgroundBrush(Qt::white);

	this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

bool View::event(QEvent *event)
{
	if (event->type() == QEvent::TouchBegin)
	{
		qDebug() << "View::event - TouchBegin";
		QTouchEvent * te = dynamic_cast<QTouchEvent*>(event);

		int index = 1;
		for (QList<QTouchEvent::TouchPoint>::const_iterator i = te->touchPoints().begin(); i != te->touchPoints().end(); i++)
		{
            qDebug() << index << ": Position(" << (*i).pos() << ") : Area(" << (*i).rect() << ") -> " << (*i).rect().size();
			index++;
		}

		return true;
	}
	else if (event->type() == QEvent::TouchUpdate)
	{
		qDebug() << "View::event - TouchUpdate";
		QTouchEvent * te = dynamic_cast<QTouchEvent*>(event);

		int index = 1;
		for (QList<QTouchEvent::TouchPoint>::const_iterator i = te->touchPoints().begin(); i != te->touchPoints().end(); i++)
		{
            qDebug() << index << ": Position(" << (*i).pos() << ") : Area(" << (*i).rect() << ") -> " << (*i).rect().size();
			index++;
		}

		return true;
	}
	else if (event->type() == QEvent::TouchEnd)
	{
		qDebug() << "View::event - TouchEnd";
		return true;
	}
	else if (event->type() == QEvent::TouchCancel)
	{
		qDebug() << "View::event - TouchCancel";
		return true;
	}

	return QGraphicsView::event(event);
}

void View::mousePressEvent(QMouseEvent * event)
{
	//qDebug() << "View::mousePressEvent - " << event->pos();
}

void View::mouseReleaseEvent(QMouseEvent * event)
{
	//qDebug() << "View::mouseReleaseEvent - " << event->pos();
}

void View::mouseMoveEvent(QMouseEvent * event)
{
	//qDebug() << "View::mouseMoveEvent - " << event->pos();
}

void View::mouseDoubleClickEvent(QMouseEvent * event)
{
	//qDebug() << "View::mouseDoubleClickEvent - " << event->pos();
}
