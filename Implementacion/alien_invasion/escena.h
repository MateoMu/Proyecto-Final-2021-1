#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include <QPushButton>
#include <QGraphicsSceneMouseEvent>
#include "objetos_graficos.h"
#include "objetos_movil.h"

class escena : public QGraphicsScene
{

public:
        /// CONSTRUCTOR Y DESTRUCTOR
    escena();
    ~escena();

        /// MOVIMIENTO DE MOUSE
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) ;


        /// CARACTERISTICAS DE ESCRITORIO
    void setWindowProperty(int desk_w, int desk_h);
    virtual void drawBackground(QPainter *painter, const QRectF &exposed);

        /// FUNCIONES AÑADIR OBJETOS GRAFICOS
    void addObjetoGrafico(QString ruta, int x, int y, int w, int h, bool main);
    void addObjetoMovil(QString ruta,int x,int y,int xf,int yf,int w,int h,int move);
    void addObjetoMovil(QString ruta,int x,int y,int v0,int angle,int move);
    void explodeObject(int _x,int _y,int _w,int _h);

        /// FUNCIONES DE PRUEBA
    void doSome();
    void explode(objetos_movil *enem);
    void explodePlusPlus();

    vector<objetos_movil *> getObjetosMoviles() const;
    void setBackGround(bool value);

private:
        /// APUNTADOR A OBJETOS GRAFICOS
    objetos_graficos *personaje;
    objetos_movil *muni;

        /// CONTENEDORES DE OBJETOS
    vector<objetos_graficos *> objetosGraficos;
    vector<objetos_graficos *>::iterator itObjGra;
    vector<objetos_movil *> objetosMoviles;
    vector<objetos_movil *>::iterator itObjMov;
    vector<objetos_movil *>::iterator itObjMov2;

        /// CARACTERISTICAS DE ESCRITORIO
    int limit_x,limit_y;
    QPixmap *image;
    QPixmap *image2;

        /// ATRIBUTOS DE JUEGO
    int blood = 100;
    int score = 0;
    int cont_1 = 0;
    int time_move = 60;
    float e = 0.5; //Coeficiente de Restitucion
    bool backGround = true;
};

#endif // SCENE_H
