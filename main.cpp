#include "dbusClient.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    dbusClient client;
    client.setWindowTitle("D-Bus Client");
    client.resize(300, 100);
    client.show();

    return app.exec();
}
