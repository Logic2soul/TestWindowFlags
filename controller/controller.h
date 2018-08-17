#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "signalmanager.h"
#include "worker.h"
#include <QObject>
#include <QDateTime>
#include <QThread>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller();
    ~Controller();

    void initConnect();

private:
    QThread* m_workerThread;
    Worker* m_worker;
};

#endif // CONTROLLER_H
