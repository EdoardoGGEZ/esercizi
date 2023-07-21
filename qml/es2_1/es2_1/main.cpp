#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "recipesmodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("es2_1", "Main");
    RecipesModel recipesModel;
    engine.rootContext()->setContextProperty("recipesModel", &recipesModel);

    return app.exec();
}
