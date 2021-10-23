#include "MainWindow.h"
#include "ui_MainWindow.h"

///         CONSTRUCTOR         ///
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
        ///SE ASIGNA UN PADRE A LA INTERFAZ GRAFICA
    ui->setupUi(this);



        ///VISUALIZACION Y ESCENA
    view->setScene(scene);
    //view->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));

        ///MAXIMIZAR VENTANA
    this->showMaximized();
    game_time = 0;
    srand(time(NULL));

}

///         DESTRUCTOR         ///
MainWindow::~MainWindow()
{
        ///ESCENARIO
    delete view;
    delete scene;
    delete ui;
}
