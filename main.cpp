#include <QApplication>
#include <QMainWindow>
#include "styling/styling.hpp"
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <nlohmann/json.hpp>
#include <filesystem>

using modpackJSON = std::unordered_map<std::string, std::vector<std::string>>;
using modpacksJSON = std::unordered_map<std::string, modpackJSON>;
using json = nlohmann::json;
namespace fs = std::filesystem;

class App: public QMainWindow {
    Q_OBJECT
private:
    std::unordered_map<std::string, std::string> styles = get_global_styles();

    modpackJSON load_modpack(fs::path filePath) {
        std::ifstream modpackFile(filePath);
        json modpackJson = json::parse(modpackFile);

        return modpackJson.get<modpackJSON>();
    }

    modpacksJSON load_modpacks(fs::path filePath) {
        modpacksJSON modpacks;
        for (const auto& modpackDir: fs::directory_iterator(filePath)) {
            if (!modpackDir.is_directory()) {
                continue;
            }

            modpacks[modpackDir.path().stem().string()] = this->load_modpack(modpackDir.path() / "modpack.json"); // trust me this will totally work
        }
        return modpacks;
    }
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