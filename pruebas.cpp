#include <QApplication>
#include <QMainWindow>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMainWindow mainWindow;
    mainWindow.setWindowTitle("Mi Aplicación Qt");
    mainWindow.setGeometry(100, 100, 400, 300);
    mainWindow.show();

    return app.exec();
}

