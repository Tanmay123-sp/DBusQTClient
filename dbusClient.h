#ifndef DBUSCLIENT_H
#define DBUSCLIENT_H

#include <QWidget>
#include <QLabel>
#include <QDBusConnection>

class dbusClient : public QWidget {
    Q_OBJECT

public:
    explicit dbusClient(QWidget *parent = nullptr);

public slots:
    // void onInputReceived(const QString &input);
    // void onAmountReceived(const QString &amount);
    void onInputsReceived(const QString &input,const QString &amount);

private:
    QLabel *m_label;
    QLabel *m_amount;
};

#endif // DBUSCLIENT_H
