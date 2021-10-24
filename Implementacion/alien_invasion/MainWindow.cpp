#include "MainWindow.h"
#include "ui_MainWindow.h"

///         CONSTRUCTOR         ///
MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent),
    ui(new Ui::MainWindow)
{
        ///SE ASIGNA UN PADRE A LA INTERFAZ GRAFICA
    ui->setupUi(this);

        ///SE CREAN LOS OBJETOS EN MEMORIA DINAMICA
    instanceItems();

        ///VISUALIZACION Y ESCENA
    view->setScene(scene);
    //view->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));


        ///MAXIMIZAR VENTANA
    this->showMaximized();
    game_time = 0;
    srand(time(NULL));
    imagen1();
    addItems2Scene();
    setDeskProperty(desk_widht,desk_height);

}

///         DESTRUCTOR         ///
MainWindow::~MainWindow()
{
        /// LABELS
    delete label1;
    delete label2;

        /// TIMERS
    delete enemy_timer;
    delete seconds;

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

        /// LABELS
    label1 = new QLabel;
    label2 = new QLabel;

        /// TIMERS
    enemy_timer = new QTimer;
    seconds = new QTimer;
    timer = new QTimer();
}

void MainWindow::hideItems()
{
        /// LABELS
    label1->hide();
    label2->hide();

}

void MainWindow::addItems2Scene()
{
    QColor bg_color(255, 0, 0, 0);
    QPalette p(label1->palette());
    p.setColor(QPalette::Background, bg_color);
    QPalette p1 = palette();
    p1.setColor(QPalette::Highlight, Qt::red);
            //addObjetoGrafico(":/new/prefix1/Imagenes/fondo1.jpeg",100,100,200,300,true);
            addObjetoGrafico(":/../Imagenes/fondo2.jpeg",desk_widht/8,2*desk_height/4,200,300,true);
            setPosSir(desk_widht/8,2*desk_height/4);
            label1->setGeometry((desk_widht/2)-150,desk_height/10,100,50);
                        label1->setStyleSheet("border-image:url(:/../Imagenes/fondo2.jpeg);");
                        p.setColor(QPalette::Background, bg_color);
                        label1->setPalette(p);

                        ///CASO DE PRUEBA
                scene->addWidget(label1);
}

///         FUNCION QUE CONECTA SIGNALS Y SLOTS         ///
void MainWindow::connectItems()
{
    ///CONEXION DE SIGNALS & SLOTS
    connect(enemy_timer,&QTimer::timeout,this,&MainWindow::addEnemy);

}



///         AÑADE OBJETOS SIN MOVIMIENTO         ///
void MainWindow::addObjetoGrafico(QString ruta, int x, int y, int w, int h,bool main)
{
    ///DECLARACION DE OBJETOS
    scene->addObjetoGrafico(ruta,x,y,w,h,main);
}

///         AÑADE OBJETOS CON MOVIMIENTO         ///
void MainWindow::addObjetoMovil(QString ruta, int xo, int yo, int xf, int yf, int w, int h, int _move)
{
    scene->addObjetoMovil(ruta,xo,yo,xf,yf,w,h,_move);
}

void MainWindow::addObjetoMovil(QString ruta, int xo, int yo, int v0, int angle, int _move)
{
    scene->addObjetoMovil(ruta,xo,yo,v0,angle,_move);
}

///         EVENTOS DE BOTONES DE MOUSE         ///
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QMainWindow::mousePressEvent(event);
//    if(enable2Shot){
//        enable2Shot = false;
//        if (move1 == 1 && ammu1 > 0){
//            addObjetoMovil(bala1_path,
//                           x_sir+60,y_sir-60,event->x(),event->y(),50,50,move1);
//            ammu1--;
//            display_ammo1->display(ammu1);
//        }
//        else if (move1 == 2 && ammu2 > 0){
//            addObjetoMovil(bala2_path,
//                           x_sir+60,y_sir-60,event->x(),event->y(),50,50,move1);
//            ammu2--;
//            display_ammo2->display(ammu2);
//        }
//        else if (move1 == 3 && ammu3 > 0){
//            addObjetoMovil(bala3_path,
//                           x_sir+60,y_sir-60,event->x(),event->y(),50,50,move1);
//            ammu3--;
//            display_ammo3->display(ammu3);
//        }
//    }
}

void MainWindow::addEnemy()
{
    move2=1+rand()%(4-1);
    addObjetoMovil(enemy_path,
                   desk_widht,300,x_sir,y_sir,100,100,move2);
}

                /////// FUNCIONES DE PRUEBA ////////////////

///     FUNCIONES DE PRUEBA     ///
void MainWindow::addObjetoMovil1()
{
move1 = 1;
///DECLARACION DE OBJETOS
//QString ruta = ":/personajes/imagenes/GIFT.png";int w=80; int h=80;
//int xf = 900,yf = 500;
//scene->addObjetoMovil(ruta,xf,yf,x_sir,y_sir,w,h,move1);
}

void MainWindow::addObjetoMovil2()
{
move1 = 2;
///DECLARACION DE OBJETOS
//QString ruta = ":/personajes/imagenes/GIFT.png"; int w=80; int h=80;
//int xf = 900,yf = 500;
//scene->addObjetoMovil(ruta,xf,yf,x_sir,y_sir,w,h,move1);
}

void MainWindow::addObjetoMovil3()
{
move1 = 3;
///DECLARACION DE OBJETOS
//QString ruta = ":/personajes/imagenes/GIFT.png"; int w=80; int h=80;
//int xf = 900,yf = 500;
//scene->addObjetoMovil(ruta,xf,yf,x_sir,y_sir,w,h,move1);
}

void MainWindow::add()
{
    ///DECLARACION DE OBJETOS
    QString ruta = ":/personajes/imagenes/GIFT.png"; int x=0; int y=100; int w=80; int h=80;
    scene->addObjetoGrafico(ruta,x,y,w,h,false);
}

void MainWindow::cambiofondo()
{
    if (cont == 1) {view->setBackgroundBrush(QImage(":/personajes/imagenes/Fondo_Original1.png"));cont=2;}
        else if (cont == 2) {view->setBackgroundBrush(QImage(":/personajes/imagenes/Fondo_Original22.png"));cont=3;}
        else if (cont == 3) {view->setBackgroundBrush(QImage(":/personajes/imagenes/Fondo_Original33.png"));cont=1;}
}

void MainWindow::imagen1()
{
    view->setBackgroundBrush(QImage(":/new/prefix1/Imagenes/fondo2.jpeg"));
}

void MainWindow::imagen2()
{
    if (img) {view->setBackgroundBrush(QImage(":/new/prefix1/Imagenes/fondo1.jpeg")); img = false;}
    else {view->setBackgroundBrush(QImage(":/new/prefix1/Imagenes/fondo2.jpeg")); img = true;}
}

void MainWindow::setPosSir(int x, int y)
{
    x_sir = x; y_sir = y;
}

void MainWindow::setBackground1()
{
    scene->setBackGround(true);
}

void MainWindow::setBackground2()
{
    scene->setBackGround(false);
}


void MainWindow::moveObject()
{
    ///ASIGNACION DE VALORES
    scene->doSome();
}
