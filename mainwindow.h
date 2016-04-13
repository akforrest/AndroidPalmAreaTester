#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "view.h"
#include "scene.h"

#include <QDebug>

class QPlainTextEdit;

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

		void log(QString str);

	private:

		Ui::MainWindow *ui;

		View * m_view;
		Scene * m_scene;

		QPlainTextEdit * m_log;
};

#endif // MAINWINDOW_H
