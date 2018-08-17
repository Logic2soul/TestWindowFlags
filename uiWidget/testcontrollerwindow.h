#ifndef TESTCONTROLLERWINDOW_H
#define TESTCONTROLLERWINDOW_H

#include "testpreviewwindow.h"
#include "signalmanager.h"

#include <QWidget>

class TestControllerWindow : public QWidget
{
    Q_OBJECT
public:
    explicit TestControllerWindow(QWidget *parent = 0);

public slots:
signals:
    void updatePreviewWindow();

private:
    void initUi();
    void createTypeGroupBox();
    void createFlagGroupBox();

    TestPreviewWindow *previewWindow;
    TestControllerWindow *controllerWindow;

};

#endif // TESTCONTROLLERWINDOW_H
