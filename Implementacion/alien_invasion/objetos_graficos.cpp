#include "objetos_graficos.h"

objetos_graficos::objetos_graficos()
{

}

objetos_graficos::objetos_graficos(QString _ruta, int _x, int _y, int _w, int _h)
    :x(_x),y(_y),w(_w),h(_h),ruta(_ruta)
{
    ///ASIGNACION DE VALORES
    this->setPos(_x,_y);
    ///DECLARACION DE OBJETO
    image=new QPixmap(_ruta);
}

QRectF objetos_graficos::boundingRect() const
{
    ///RETORNO DE OBJETO
    return QRectF(-w*escala/2,-h*escala/2,w*escala,h*escala);
    //return QRectF(x,y,w,h);
}

void objetos_graficos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    ///ASIGNACION DE VALORES
    painter->drawPixmap(boundingRect(),*image,image->rect());
}

int objetos_graficos::getX()
{
    ///RETORNO DE VALOR
    return x;
}

int objetos_graficos::getY()
{
    ///RETORNO DE VALOR
    return y;
}

void objetos_graficos::set_Pos(int _x,int _y)
{
    ///ASIGNACION DE VALORES
    x = _x; y = _y;
    this->setPos(_x,_y);
}

QPixmap *objetos_graficos::getImage() const
{
    ///RETORNO DE OBJETO
    return image;
}

void objetos_graficos::setImage(QPixmap *value)
{
    ///RETORNO DE VALOR
    image = value;
}

QString objetos_graficos::getRuta() const
{
    ///RETORNO DE VALOR
    return ruta;
}

int objetos_graficos::getW() const
{
    ///RETORNO DE VALOR
    return w;
}

int objetos_graficos::getH() const
{
    ///RETORNO DE VALOR
    return h;
}

void objetos_graficos::setEscala(float value)
{
    escala = value;
}

void objetos_graficos::escalaMinusMinus()
{
    escala = escala/cont;
}

void objetos_graficos::setRest(float value)
{
    rest = value;
}
