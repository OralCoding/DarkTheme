#include <QApplication>
#include <QStyleFactory>
#include <QStyle>
#include <QPalette>
#include <QAction>

#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QAction* toggleThemeAction = ui.toolBar->addAction("Toggle Theme");
    connect(toggleThemeAction, &QAction::triggered, this, &MainWindow::toggleTheme);

    setLightTheme();
}

void MainWindow::toggleTheme() {
    if (isDarkTheme) {
        setLightTheme();
    } else {
        setDarkTheme();
    }
    isDarkTheme = !isDarkTheme;
}

void MainWindow::setDarkTheme() {
    QPalette darkPalette;
    QColor darkColor(45, 45, 45);
    QColor disabledColor(127, 127, 127);
    darkPalette.setColor(QPalette::Window, darkColor);
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Disabled, QPalette::WindowText, disabledColor);
    darkPalette.setColor(QPalette::Base, QColor(18, 18, 18));
    darkPalette.setColor(QPalette::AlternateBase, darkColor);
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Disabled, QPalette::Text, disabledColor);
    darkPalette.setColor(QPalette::Button, darkColor);
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::Disabled, QPalette::ButtonText, disabledColor);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));

    qApp->setPalette(darkPalette);
    qApp->setStyle(QStyleFactory::create("Fusion"));
}

void MainWindow::setLightTheme() {
    qApp->setPalette(qApp->style()->standardPalette());
    qApp->setStyle(QStyleFactory::create("Fusion"));
}
