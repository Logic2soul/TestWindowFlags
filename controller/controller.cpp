#include "controller.h"

Controller::Controller()
{
    m_worker = new Worker;
    m_workerThread = new QThread;
    m_worker->moveToThread(m_workerThread);
    initConnect();
    m_workerThread->start();
}

Controller::~Controller()
{

}

void Controller::initConnect()
{
    connect(SignalManager::instance(), &SignalManager::actionRunCmd,
            m_worker, &Worker::onRunCmd);
    connect(SignalManager::instance(), &SignalManager::actionRestartAll,
            m_worker, &Worker::onRestartAll);
    connect(SignalManager::instance(), &SignalManager::actionRestartDB,
            m_worker, &Worker::onRestartDB);
    connect(SignalManager::instance(), &SignalManager::actionLogDB,
            m_worker, &Worker::onLogDB);
    connect(SignalManager::instance(), &SignalManager::actionRestartPlatformService,
            m_worker, &Worker::onRestartPlatformService);
    connect(SignalManager::instance(), &SignalManager::actionLogPlatformService,
            m_worker, &Worker::onLogPlatformService);
    connect(SignalManager::instance(), &SignalManager::actionRestartPlatformUI,
            m_worker, &Worker::onRestartPlatformUI);
    connect(SignalManager::instance(), &SignalManager::actionLogPlatformUI,
            m_worker, &Worker::onLogPlatformUI);
    connect(SignalManager::instance(), &SignalManager::actionRestartBD,
            m_worker, &Worker::onRestartBD);
    connect(SignalManager::instance(), &SignalManager::actionLogBD,
            m_worker, &Worker::onLogBD);

    connect(m_worker, &Worker::logChanged,
            SignalManager::instance(), &SignalManager::logChanged);

}
