#ifndef SIGNALMANAGER_H
#define SIGNALMANAGER_H

#include <QObject>

class SignalManager : public QObject
{
    Q_OBJECT
public:
    inline static SignalManager* instance(){
        static SignalManager instance;
        return &instance;
    }

signals:
    //V-C signal:
    void actionRunCmd(const QString &cmd);

    void actionRestartAll();
    void actionRestartDB();
    void actionLogDB();
    void actionRestartPlatformService();
    void actionLogPlatformService();
    void actionRestartPlatformUI();
    void actionLogPlatformUI();
    void actionRestartBD();
    void actionLogBD();

    void logChanged(const QString &log);

public slots:

private:
    explicit SignalManager(QObject *parent = 0);
    ~SignalManager();
    SignalManager(const SignalManager &s);
    SignalManager & operator=(const SignalManager &s);
};

#endif // SIGNALMANAGER_H
