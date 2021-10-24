#ifndef OBJETOS_MOVIL_H
#define OBJETOS_MOVIL_H

#include <QObject>
#include <QTimer>
#include <objetos_graficos.h>
#include "movimientos.h"

class objetos_movil:public QObject, public objetos_graficos
{
    Q_OBJECT

    public:
        objetos_movil();
        objetos_movil(QString _ruta, int _x, int _y, int _xf, int _yf, int _w, int _h, int _move);
        objetos_movil(QString _ruta, int _x, int _y, int _w, int _h);
        ~objetos_movil();

        //PROPIEDADES DE VISUALIZACION
        virtual QRectF boundingRect() const;
        virtual void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
        bool closeness(objetos_movil *obj,int howFar);

        void setMovParabolico(int xf,int yf,int param,bool minMax);
        void setVel(float _v0,float _angle);
        void set_vel(int vx,int vy,int px,int py);
        void setMovSenoidal();
        void setMUA();

        float get_velX();
        float get_velY();
        void setInverseMove();


        void startMove(int msec);
        void stopMove();
        void updatePos();
        void updatePos2();
        void updatePos3();
        void stop();
        void changeSize();


        bool getOutOfScene() const;
        void deleteObject();

        bool getLado();

        int getV0() const;

        int getAngle() const;

        int getMove() const;

        void setRestitucion(float value);

    private:
        movimientos *movimiento;

        QTimer *time_move;


        int v0 = 0, angle = 0; //Variables de Movimiento
        float factorImpacto = 0.05; //Porcentaje de Error en el impacto
        bool outOfScene = false;
        int move = 0;
        int cont = 1;

    signals:
        void outScene();
    };

#endif // OBJETOS_MOVIL_H
