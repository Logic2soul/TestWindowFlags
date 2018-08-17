#include "worker.h"

Worker::Worker(QObject *parent) : QObject(parent)
{
}

void Worker::initConnect()
{
    connect(m_cmdProcess, &QProcess::readyReadStandardOutput, this, &Worker::readProcessStandardOutput);
    connect(m_cmdProcess, &QProcess::readyReadStandardError, this, &Worker::readProcessStandardError);
    connect(m_cmdProcess, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(onProcessFininsed(int,QProcess::ExitStatus)));
}

void Worker::readProcessStandardOutput()
{
    QString output = m_cmdProcess->readAllStandardOutput();
    m_log += output;
    emit logChanged(m_log);
}

void Worker::readProcessStandardError()
{
    QString output = m_cmdProcess->readAllStandardError();
    m_log += output;
    emit logChanged(m_log);
}

void Worker::onProcessFininsed(int exitCode, QProcess::ExitStatus exitStatus)
{
    qDebug() << "exitCode:" << exitCode << ", exitStatus:" << exitStatus;
}

void Worker::onRunCmd(const QString &cmdstring)
{
    qDebug() << "exec user cmd: " << cmdstring;
    QStringList cmds = cmdstring.split(" ");
    QString cmd = cmds.takeFirst();
    QStringList args = cmds;
    onRunCmdArgs(cmd, args);
}

void Worker::onRunCmdArgs(const QString &cmd, const QStringList &args)
{
    qDebug() << "exec user cmd: " << cmd << args;
    m_log.clear();
    m_cmdProcess = new QProcess;
    initConnect();
    m_cmdProcess->start(cmd, args);
    m_cmdProcess->waitForFinished();
}

void Worker::onRestartAll()
{
    onRestartDB();
    onRestartPlatformService();
    onRestartPlatformUI();
    onRestartBD();
}

void Worker::onRestartDB()
{
    onRunCmdArgs("docker", QStringList() << "restart" << "mysql_server");
}

void Worker::onLogDB()
{
    onRunCmdArgs("docker", QStringList() << "logs" << "mysql_server");
}

void Worker::onRestartPlatformService()
{
    onRunCmdArgs("docker", QStringList() << "restart" << "glider_server");
}

void Worker::onLogPlatformService()
{
    onRunCmdArgs("docker", QStringList() << "logs" << "glider_server");
}

void Worker::onRestartPlatformUI()
{
    onRunCmdArgs("docker", QStringList() << "restart" << "glider_fontend");
}

void Worker::onLogPlatformUI()
{
    onRunCmdArgs("docker", QStringList() << "logs" << "glider_fontend");
}

void Worker::onRestartBD()
{
    onRunCmdArgs("docker", QStringList() << "restart" << "glider_bdprocess");
}

void Worker::onLogBD()
{
    onRunCmdArgs("docker", QStringList() << "logs" << "glider_bdprocess");
}
