#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include <QPushButton>
#include <QGraphicsSceneMouseEvent>
#include "objetos_graficos.h"

class escena : public QGraphicsScene
{

public:
        /// CONSTRUCTOR Y DESTRUCTOR
    escena();
    ~escena();



        /// CARACTERISTICAS DE ESCRITORIO
    void setWindowProperty(int desk_w, int desk_h);
    virtual void drawBackground(QPainter *painter, const QRectF &exposed);

        /// FUNCIONES AÑADIR OBJETOS GRAFICOS
    void addObjetoGrafico(QString ruta, int x, int y, int w, int h, bool main);
    void explodeObject(int _x,int _y,int _w,int _h);

        /// FUNCIONES DE PRUEBA
    void doSome();
    //void explode(Objeto_Movil *enem);
    void explodePlusPlus();

    void circulo(int r, int px, int py);

private:
        /// APUNTADOR A OBJETOS GRAFICOS
    objetos_graficos *personaje;

        /// CONTENEDORES DE OBJETOS
    std::vector<objetos_graficos *> objetosGraficos;
    std::vector<objetos_graficos *>::iterator itObjGra;

        /// CARACTERISTICAS DE ESCRITORIO
    int limit_x,limit_y;
    QPixmap *image;
    QPixmap *image2;

        /// ATRIBUTOS DE JUEGO
    bool backGround = true;
};

#endif // SCENE_H
