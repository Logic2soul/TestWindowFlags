#ifndef TESTCONTROLLERWINDOW_H
#define TESTCONTROLLERWINDOW_H

#include <QWidget>

class TestControllerWindow : public QWidget
{
    Q_OBJECT
public:
    explicit TestControllerWindow(QWidget *parent = 0);

public slots:
    void updatePreviewWindow();

private:
    void initUi();
    void createTypeGroupBox();
    void createFlagGroupBox();

};

#endif // TESTCONTROLLERWINDOW_H
