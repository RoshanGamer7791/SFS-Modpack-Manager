#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QUrl uiFile = QUrl::fromLocalFile("ui/main.qml");
    engine.load(uiFile);

    return QGuiApplication::exec();
}