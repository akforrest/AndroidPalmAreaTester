#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPlainTextEdit>

#include <QVBoxLayout>
#include <QGridLayout>
#include <QTimer>
#include <QTouchDevice>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	m_scene = new Scene(this);
	m_view = new View(m_scene, this);

	m_log = new QPlainTextEdit("Touch Test Log Window", this);
	m_log->setMaximumBlockCount(20);
	m_log->appendPlainText("Touch information for the above view will be displayed here");

	m_log->appendPlainText("");

	QTimer::singleShot(200, [this](){
		m_log->appendPlainText("Available touch devices:");

		// This is how we inspect devices - this has not been shown to be all that reliable
		// but potentially can return some interesting information
		QList<const QTouchDevice *> devices = QTouchDevice::devices();
		for (QList<const QTouchDevice *>::const_iterator i = devices.begin();
			 i != devices.end();
			 i++)
		{
			qDebug() << (*i)->name() << ": " << (*i)->capabilities();
		}

		m_log->appendPlainText("");
	});

	QVBoxLayout * layout = new QVBoxLayout();
	layout->addWidget(m_view);
	layout->addWidget(m_log);

	QWidget * cw = new QWidget();
	cw->setLayout(layout);

	this->setCentralWidget(cw);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::log(QString str)
{
	m_log->appendPlainText(str);
	m_log->moveCursor(QTextCursor::End, QTextCursor::MoveAnchor);
}

