#ifndef OBJETOS_GRAFICOS_H
#define OBJETOS_GRAFICOS_H

#include <QGraphicsItem>
#include <QPainter>
#include <vector>

class objetos_graficos: public QGraphicsItem
{
public:
    objetos_graficos();
    objetos_graficos(QString _ruta,int _x,int _y,int _w,int _h);

    //PROPIEDADES DE VISUALIZACION
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);

    int getX();
    int getY();
    void set_Pos(int _x,int _y);

    QPixmap *getImage() const;
    void setImage(QPixmap *value);

private:
    int x,y;
    int w,h;
    float escala = 1;
    float rest = 1;
    QString ruta;
    QPixmap *image;
};

#endif // OBJETOS_GRAFICOS_H
