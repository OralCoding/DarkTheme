#include <QMainWindow>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void toggleTheme();
    void showMessageBox();

private:
    void setDarkTheme();
    void setLightTheme();

private:
    Ui::MainWindow ui;
    bool isDarkTheme = false;
};
