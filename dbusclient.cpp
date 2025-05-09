#include "dbusClient.h"
#include <QVBoxLayout>
#include <QDBusConnection>
#include <QDBusError>
#include <QDebug>

dbusClient::dbusClient(QWidget *parent) : QWidget(parent), m_label(new QLabel(this)),m_amount(new QLabel(this)) {
    // Set up the GUI layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_label);
    layout->addWidget(m_amount);
    setLayout(layout);

    // Connect to the input signal
    bool inputsConnected = QDBusConnection::sessionBus().connect(
        "com.example.InputService",
        "/InputObject",
        "com.example.InputService",
        "dataReceived",
        this, SLOT(onInputsReceived(QString,QString))
        );

    if (!inputsConnected) {
        qCritical() << "Failed to connect to inputReceived signal:" << QDBusConnection::sessionBus().lastError().message();
    } else {
        qDebug() << "Successfully connected to inputReceived signal.";
    }
}

void dbusClient::onInputsReceived(const QString &input, const QString &amount)
{
    m_label->setText("Received Name: " + input);
    m_amount->setText("Received Amount: " + amount);

}
