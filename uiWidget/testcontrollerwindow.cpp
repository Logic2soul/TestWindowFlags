#include "testcontrollerwindow.h"

TestControllerWindow::TestControllerWindow(QWidget *parent) : QWidget(parent)
{
    initUi();
}

void TestControllerWindow::initUi()
{
    controllerWindow = new TestControllerWindow(tr("controller window"));
    createTypeGroupBox();
    createFlagGroupBox();

    previewWindow = new TestPreviewWindow(tr("preview window"));
}
