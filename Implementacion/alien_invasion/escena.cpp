#include "escena.h"

///         CONSTRUCTOR         ///
escena::escena()
{
    image = new QPixmap(":/../Imagenes/fondo1.jpeg");
    image2 = new QPixmap(":/../Imagenes/fondo2.jpeg");
}

///         DESTRUCTOR         ///
escena::~escena()
{
        ///ELIMINACION DE MEMORIA
    delete personaje;
}

void escena::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseMoveEvent(event);
    //qDebug()<<"x "<<event->scenePos().x()<<" y "<<event->scenePos().y();
}

///         PROPIEDADES DE VENTANA         ///
void escena::setWindowProperty(int desk_w, int desk_h)
{
    limit_x = desk_w;
    limit_y = desk_h;
    setSceneRect(0,0,desk_w,desk_h);
}

void escena::drawBackground(QPainter *painter, const QRectF &exposed)
{
    if(backGround) painter->drawPixmap(QRectF(0,0,limit_x,limit_y),*image,image->rect());
    else painter->drawPixmap(QRectF(0,0,limit_x,limit_y),*image2,image2->rect());
}

///         AÑADIR OBJETOS GRAFICOS         ///
void escena::addObjetoGrafico(QString ruta, int x, int y, int w, int h,bool main)
{
    if(main){
        ///DECLARACION DE OBJETO
        personaje = new objetos_graficos(ruta,x,y,w,h);
        ///ASIGNACION DE VALORES
        this->addItem(personaje);
    }
}

///         FUNCION MOVIMIENTO DE PRUEBA         ///
void escena::doSome()
{
    ///ASIGNACION DE VALORES
    personaje->set_Pos(personaje->getX()+50,personaje->getY());
}

///         AÑADIR OBJETOS GRAFICOS MOVILES         ///
void escena::addObjetoMovil(QString ruta, int x, int y,int xf,int yf, int w, int h, int move)
{
    ///DECLARACION DE VARIABLES AUXILIARES LOCALES
    int param = 5;              //Parametro Altura Maxima
    bool minMax = true;         //Minimo Valor del Parametro

    ///CREACION DE OBJETO MOVIL
    muni = new objetos_movil(ruta,x,y,xf,yf,w,h,move);
    objetosMoviles.push_back(muni);     //Añadir objeto a la lista de objetos moviles

    /// ASIGNACION DE MOVIMIENTO PARABOLICO
    if(move == 1) {
        muni->setMovParabolico(xf,yf,param,minMax);
        muni->setInverseMove();
    }   //Calcula velocidad y angulo inicial

    //qDebug()<<"No hay problemas con la inicializacion del movimiento";

    //ASIGNACION DE MOVIMIENTO SENOIDAL
    //muni->setMovSenoidal();

    /// INICIALIZACION DE OBJETO EN ESCENA
    this->addItem(muni);                //Se añade el objeto a la escena
    muni->startMove(time_move);                //Asigna valor de timeout para el movimiento
}

void escena::addObjetoMovil(QString ruta, int x, int y, int v0, int angle, int move)
{
    ///CREACION DE OBJETO MOVIL
    muni = new objetos_movil(ruta,x,y,0,500,100,100,move);
    objetosMoviles.push_back(muni);     //Añadir objeto a la lista de objetos moviles
    muni->setVel(v0,angle);

    /// INICIALIZACION DE OBJETO EN ESCENA
    this->addItem(muni);                //Se añade el objeto a la escena
}

vector<objetos_movil *> escena::getObjetosMoviles() const
{
    return objetosMoviles;
}

void escena::setBackGround(bool value)
{
    backGround = value;
}
