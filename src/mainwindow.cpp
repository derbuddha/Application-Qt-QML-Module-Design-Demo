#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QQmlApplicationEngine>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    const QUrl url(u"qrc:/qt/qml/first/main.qml"_qs);
    //const QUrl url(u"qrc:/first/main.qml"_qs);

    QQmlApplicationEngine engine = ui->quickWidget->engine();
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreationFailed,
        this, []()
        { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    ui->quickWidget->setSource(url);
    ui->quickWidget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

