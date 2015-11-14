#include <QCommandLineParser>
#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QGuiApplication>
#include "pushquickview.h"

int main(int argc, char *argv[])
{
    {
        QCoreApplication app(argc, argv);

        QDir::setCurrent(app.applicationDirPath());
    }

    qputenv("QML2_IMPORT_PATH", "Push2/qml;Qt/qml");
    qputenv("QT_PLUGIN_PATH", "Qt/plugins");

    QGuiApplication app(argc, argv);
    QCommandLineParser parser;

    parser.setApplicationDescription("Push 2 QML Runner");
    parser.addHelpOption();
    parser.addPositionalArgument("filename", QCoreApplication::translate("main", "The file to open."));

    parser.process(app);

    QString filename;

    if (!parser.positionalArguments().empty())
        filename = QDir::fromNativeSeparators(parser.positionalArguments().first());
    if (!QFileInfo(filename).exists())
        parser.showHelp(0);

    PushQuickView w(QUrl::fromLocalFile(filename));

    Q_UNUSED(w);

    return app.exec();
}
