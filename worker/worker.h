#ifndef WORKER_H
#define WORKER_H

#include "Logger.h"
#include <QObject>
#include <QProcess>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = 0);
    void initConnect();

signals:
    void logChanged(const QString& log);

public slots:
    void onRestartAll();
    void onRestartDB();
    void onLogDB();
    void onRestartPlatformService();
    void onLogPlatformService();
    void onRestartPlatformUI();
    void onLogPlatformUI();
    void onRestartBD();
    void onLogBD();

    void onRunCmd(const QString & cmdstring);
    void onRunCmdArgs(const QString &cmd, const QStringList& args);
    void readProcessStandardOutput();
    void readProcessStandardError();

    void onProcessFininsed(int exitCode, QProcess::ExitStatus exitStatus);

private:
    QProcess* m_cmdProcess;
    QString m_log;
};

#endif // WORKER_H
