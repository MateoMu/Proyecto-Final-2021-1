#include "objetos_movil.h"

objetos_movil::objetos_movil()
{

}

objetos_movil::objetos_movil(QString _ruta, int _x, int _y,int _xf,int _yf, int _w, int _h,int _move) : objetos_graficos(_ruta,_x,_y,_w,_h)
{
    ///DECLARACION DE OBJETOS
    movimiento = new movimientos(_x,_y,_xf,_yf);
    time_move = new QTimer;
    move = _move;

    ///CONEXION DE SIGNAL & SLOT
    switch (_move) {
    case 1:
            ///Movimiento Parabolico
        connect(time_move,&QTimer::timeout,this,&objetos_movil::updatePos);
        break;
    case 2:
            ///Movimiento Senoidal
        connect(time_move,&QTimer::timeout,this,&objetos_movil::updatePos2);
        break;
    case 3:
            ///Movimiento Rectilineo Acelerado
        this->setMUA();
        connect(time_move,&QTimer::timeout,this,&objetos_movil::updatePos3);
        break;
    default:
            ///Movimiento Parabolico
        connect(time_move,&QTimer::timeout,this,&objetos_movil::updatePos);
        break;
    }



}

objetos_movil::objetos_movil(QString _ruta, int _x, int _y, int _w, int _h): objetos_graficos(_ruta,_x,_y,_w,_h)
{
    movimiento = new movimientos;
    time_move = new QTimer;
    connect(time_move,&QTimer::timeout,this,&objetos_movil::changeSize);
    time_move->start(250);
}

objetos_movil::~objetos_movil()
{
    ///ELIMINACION DE MEMORIA
    //qDebug()<<"Destruyendo elementos de Objetos";
    delete movimiento;
    delete time_move;
    delete this->parent();
}

QRectF objetos_movil::boundingRect() const
{
    ///RETORNO DE OBJETO
    return QRectF(0,0,this->getW(),this->getH());
}

void objetos_movil::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    ///ASIGNACION DE VALORES
    painter->drawPixmap(boundingRect(),*(this->getImage()),this->getImage()->rect());
}

bool objetos_movil::closeness(objetos_movil *obj,int howFar)
{
    bool close = false;
    int d = sqrt(sqrt(pow(obj->getX()-this->getX(),2)+pow(obj->getY()-this->getY(),2))); //Distancia entre Objetos)
    if(d <= howFar) close = true;
    return close;
}

void objetos_movil::setMovParabolico(int xf, int yf,int param,bool minMax)
{
    ///DECLARACION DE VARIABLES AUXILIARES LOCALES
    vector<float> params;                                //Vector de Parametros de Lanzamiento
    int d = sqrt(pow(xf-this->getX(),2)+pow(yf-this->getY(),2)); //Distancia entre Objetos                              //Porcentaje de Impacto

    //qDebug()<<"Distancia calculada";
    ///ASIGNACION DE VALORES
    movimiento->nParabolicos(xf,yf,d,factorImpacto);    //Se calculan las velocidades de lanzamiento
    //movimiento->imprimirVector(movimiento->getLanzamientos());
    //qDebug()<<"Calculados n parabolicos";
    ///DEBUG
    //qDebug()<<"GEtting Best...";

    ///ASIGNACION DE VALORES
    params = movimiento->getBest(param,minMax);         //Parametros para lanzamiento con altura minima
    //qDebug()<<"Se eligio el mejor";
    angle = params.at(3);
    v0 = params.at(4);
    movimiento->setParamsMove(v0,angle);
    //qDebug()<<"parametros seteados";
}

void objetos_movil::setVel(float _v0, float _angle)
{
    ///ASIGNACION DE VALORES
    angle = _angle;
    v0 = _v0;
    movimiento->setParamsMove(v0,angle);
}

void objetos_movil::set_vel(int vx, int vy, int px, int py)
{
    this->movimiento->set_vel(vx,vy,px,py);
    this->set_Pos(px,py);
}

void objetos_movil::setMovSenoidal()
{
    movimiento->setMovSeno();
}

void objetos_movil::setMUA()
{
    this->movimiento->setMUA();
}

float objetos_movil::get_velX()
{
    return this->movimiento->getVx();
}

float objetos_movil::get_velY()
{
    return this->movimiento->getVy();
}

void objetos_movil::setInverseMove()
{
    this->movimiento->setReverse();
}

void objetos_movil::startMove(int msec)
{
    ///ASIGNACION DE VALORES
    time_move->start(msec);
}

void objetos_movil::stopMove()
{
    ///ASIGNACION DE VALORES
    time_move->stop();
}

void objetos_movil::updatePos()
{
    ///SI SE CUMPLE LA CONDICION
    if (movimiento->actualizar(0.1)) {outOfScene = true; /*delete this;*/}       //EMITE SEÑAL
    ///ASIGNACION DE VALORES
    this->set_Pos(movimiento->getX(),movimiento->getY());
}

void objetos_movil::updatePos2()
{
    if(movimiento->actualizarSeno()){outOfScene = true;}
    this->set_Pos(movimiento->getX(),movimiento->getY());
}

void objetos_movil::updatePos3()
{
    if(movimiento->actualizarMUA()){outOfScene = true;}
    this->set_Pos(movimiento->getX(),movimiento->getY());
}

void objetos_movil::stop()
{
    time_move->stop();
}

void objetos_movil::changeSize()
{
    switch (cont) {
    case 1:
        this->parentItem()->setScale(1.2);
        break;
    case 2:
        this->parentItem()->setScale(1.4);
        break;
    case 3:
        this->parentItem()->setScale(1.6);
        break;
    case 4:
        this->parentItem()->setScale(0.8);
        break;
    case 5:
        this->parentItem()->setScale(0.5);
        break;
    case 6:
        delete this;
        break;
    default:
        qDebug()<<"Algo anda mal";
        break;
    }
    cont++;
}

bool objetos_movil::getOutOfScene() const
{
    return outOfScene;
}

void objetos_movil::deleteObject()
{
    //time_move->stop();
    //qDebug()<<"Eliminando Objeto at .... No se";
    delete this;
}

bool objetos_movil::getLado()
{
    return movimiento->getLado();
}

int objetos_movil::getV0() const
{
    return v0;
}

int objetos_movil::getAngle() const
{
    return angle;
}

int objetos_movil::getMove() const
{
    return move;
}

void objetos_movil::setRestitucion(float value)
{
    this->setRest(value);
}
