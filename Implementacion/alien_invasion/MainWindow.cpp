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

///     FUNCION SET PROPIEDADES ESCRITORIO      ///
void MainWindow::setDeskProperty(int w, int h)
{
    ///ASIGNACION DE VALORES
   desk_widht = w;
   desk_height = h;
   view->setGeometry(0,0,w,h);
   scene->setWindowProperty(w,h);
}

///         FUNCION QUE CREA OBJETOS EN MEMORIA DINAMICA         ///
void MainWindow::instanceItems()
{
        /// ESCENARIO
    view = new QGraphicsView(this);
    scene = new escena();
}

void MainWindow::addItems2Scene(int opc)
{
    QColor bg_color(255, 0, 0, 0);
    QPalette p(label1->palette());
    p.setColor(QPalette::Background, bg_color);
    QPalette p1 = palette();
    p1.setColor(QPalette::Highlight, Qt::red);
            addObjetoGrafico(":/personajes/imagenes/senor1.png",desk_widht/8,2*desk_height/4,200,300,true);
            //setPosSir(desk_widht/8,2*desk_height/4);

}

///         AÑADE OBJETOS SIN MOVIMIENTO         ///
void MainWindow::addObjetoGrafico(QString ruta, int x, int y, int w, int h,bool main)
{
    ///DECLARACION DE OBJETOS
    scene->addObjetoGrafico(ruta,x,y,w,h,main);
}


                /////// FUNCIONES DE PRUEBA ////////////////
void MainWindow::cambiofondo()
{
    if (cont == 1) {view->setBackgroundBrush(QImage(":/personajes/imagenes/Fondo_Original1.png"));cont=2;}
        else if (cont == 2) {view->setBackgroundBrush(QImage(":/personajes/imagenes/Fondo_Original22.png"));cont=3;}
        else if (cont == 3) {view->setBackgroundBrush(QImage(":/personajes/imagenes/Fondo_Original33.png"));cont=1;}
}

void MainWindow::imagen1()
{
    view->setBackgroundBrush(QImage(":/personajes/imagenes/fondo.png"));
}

void MainWindow::imagen2()
{
    if (img) {view->setBackgroundBrush(QImage(":/personajes/imagenes/fondo.png")); img = false;}
    else {view->setBackgroundBrush(QImage(":/personajes/imagenes/GIFT.png")); img = true;}
}

void MainWindow::setPosSir(int x, int y)
{
    x_sir = x; y_sir = y;
}