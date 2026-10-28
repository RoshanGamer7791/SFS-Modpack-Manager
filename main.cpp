#include <QApplication>
#include <QMainWindow>

class App: public QMainWindow {
    Q_OBJECT
    public:
    App() {
        this->setWindowTitle("SFS Modpack Manager");
        this->resize(960, 480);
    }
};

#include "main.moc" // Qt made me have to do this :sob:

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    App win;
    win.show();
    return QCoreApplication::exec();
}