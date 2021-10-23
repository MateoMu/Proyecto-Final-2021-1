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

void escena::circulo(int r, int px, int py)
{
    //QGraphicsItem *circu = new QGraphicsItem();

}
