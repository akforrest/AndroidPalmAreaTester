#include "mainwindow.h"
#include <QApplication>

#include <iostream>

#ifdef Q_OS_ANDROID
#include <android/log.h>
#endif

static MainWindow * staticWindowP = 0;

void myMessageOutput(QtMsgType type, const QMessageLogContext&, const QString& msg)
{

#ifdef Q_OS_ANDROID
	android_LogPriority priority = ANDROID_LOG_DEBUG;
	switch (type) {
	case QtDebugMsg: priority = ANDROID_LOG_DEBUG; break;
	case QtWarningMsg: priority = ANDROID_LOG_WARN; break;
	case QtCriticalMsg: priority = ANDROID_LOG_ERROR; break;
	case QtFatalMsg: priority = ANDROID_LOG_FATAL; break;
	case QtInfoMsg: priority = ANDROID_LOG_INFO; break;
	};

	__android_log_print(priority, "", "%s\n", qPrintable(msg.toStdString().c_str()));
#else
	fprintf(stdout, "%s\n", msg.toLatin1().data());
	fflush(stdout);
#endif

	if (staticWindowP != 0)
	{
		staticWindowP->log(msg);
	}
}

int main(int argc, char *argv[])
{
	qInstallMessageHandler(myMessageOutput);

	QApplication a(argc, argv);
	MainWindow w;
	staticWindowP = &w;
	w.show();

	return a.exec();
}
