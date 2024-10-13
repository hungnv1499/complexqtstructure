#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "myapp.h"  // Your custom class

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    // Create and set up the QML engine
    QQmlApplicationEngine engine;

    // Register the MyApp C++ class to be accessible in QML
    qmlRegisterType<MyApp>("MyComplexQtQuickApp", 1, 0, "MyApp");

    // Load the main QML file
    const QUrl url(QStringLiteral("qrc:/qml/Main.qml"));
    engine.load(url);

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

