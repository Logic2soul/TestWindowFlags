#include "signalmanager.h"

SignalManager::SignalManager(QObject *parent) : QObject(parent)
{
    Q_UNUSED(parent);
}

SignalManager::~SignalManager()
{

}

SignalManager::SignalManager(const SignalManager &s)
{

}

SignalManager &SignalManager::operator=(const SignalManager &s)
{

}
