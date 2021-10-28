#include "escena.h"

///         CONSTRUCTOR         ///
escena::escena()
{
    image = new QPixmap(":/new/prefix1/Imagenes/fondo1.jpeg");
    image2 = new QPixmap(":/new/prefix1/Imagenes/fondo2.jpeg");
}

///         DESTRUCTOR         ///
escena::~escena()
{
        ///ELIMINACION DE MEMORIA
    delete personaje;
    delete muni;
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
    }else{
        explosiones = new objetos_graficos(ruta,x,y,w,h);
        ///ASIGNACION DE VALORES
        this->addItem(explosiones);
        objetosGraficos.push_back(explosiones);
    }
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

void escena::explodeObject(int _x, int _y, int _w, int _h)
{
    muni = new objetos_movil(":/personajes/imagenes/explode.png",_x,_y,_w,_h);
}

///         FUNCION MOVIMIENTO DE PRUEBA         ///
void escena::doSome()
{
    ///ASIGNACION DE VALORES
    personaje->set_Pos(personaje->getX()+50,personaje->getY());
}

void escena::explode(objetos_movil *enem)
{
    int x,y;
    x=enem->getX();
//    y=enem->getY()-100;
    y=enem->getY();
    explosiones = new objetos_graficos(":/personajes/imagenes/explode.png",x,y,80,80);
    explosiones->setEscala(1.6);
    this->addItem(explosiones);
    objetosGraficos.push_back(explosiones);
}

void escena::explodePlusPlus()
{
    if(!objetosGraficos.empty()){
        for(itObjGra=objetosGraficos.begin();itObjGra!=objetosGraficos.end();itObjGra++){
            if((*itObjGra)->cont > 15){
                //this->removeItem((*itObjGra));
                delete (*itObjGra);
                objetosGraficos.erase(itObjGra);
                return;
            }
            else {(*itObjGra)->cont++;}
        }
    }
}

int escena::getHurt()
{
    return blood;
}

void escena::pause()
{
    if(!objetosMoviles.empty()){
        for(itObjMov = objetosMoviles.begin();itObjMov != objetosMoviles.end();itObjMov++){
            (*itObjMov)->stop();
        }
    }
}

void escena::start()
{
    if(!objetosMoviles.empty()){
        for(itObjMov = objetosMoviles.begin();itObjMov != objetosMoviles.end();itObjMov++){
            (*itObjMov)->startMove(time_move);
        }
    }
}

void escena::restart()
{
    if(!objetosMoviles.empty()){
        for(itObjMov = objetosMoviles.begin();itObjMov != objetosMoviles.end();itObjMov++){
            (*itObjMov)->deleteObject();
        }
        objetosMoviles.clear();
    }
    if(!objetosGraficos.empty()){
        for(itObjGra = objetosGraficos.begin();itObjGra != objetosGraficos.end();itObjGra++){
            delete (*itObjGra);
        }
        objetosGraficos.clear();
    }
    score = 0;
    blood = 100;
}

void escena::setHurt()
{
    blood -= 10;
}


///         ELIMINA LOS OBJETOS QUE ESTEN FUERA DE ESCENA´         ///
bool escena::deleteFromScene()
{
    cont_1++;
    bool collides = false;
    int cont = 0,cont2 = 0;
    explodePlusPlus();
    if(!objetosMoviles.empty()){
        for(itObjMov = objetosMoviles.begin();itObjMov != objetosMoviles.end();itObjMov++,cont++){
            if((*itObjMov)->getOutOfScene()){
                collides = true;
                explode((*itObjMov));
                if(!(*itObjMov)->getLado()){
                    ///SE REDUCE LA VIDA DEL JUGADOR
                    this->setHurt();
                }
                if((*itObjMov) == objetosMoviles.at(cont)){
                    (*itObjMov)->deleteObject();
                    objetosMoviles.erase(itObjMov);
                }
                return collides;
            }
            else if((*itObjMov)->getY() > limit_y-200){
                (*itObjMov)->set_vel((*itObjMov)->get_velX(),-1*e*(*itObjMov)->get_velY(),
                                     (*itObjMov)->getX(),(*itObjMov)->getY()-10);
            }
            else{
                for (itObjMov2 = objetosMoviles.begin(),cont2=0;itObjMov2 != objetosMoviles.end();itObjMov2++,cont2++) {
                    /// Si es bala ///              ///Si es Enemigo///
                    if((*itObjMov)->getLado() && !(*itObjMov2)->getLado()){
                        if((*itObjMov)->collidesWithItem((*itObjMov2))
                                && ((*itObjMov2)->collidesWithItem((*itObjMov)))
                                /*|| (*itObjMov)->closeness((*itObjMov2),10)*/){
                            collides = true; setScorePlus();
                            explode((*itObjMov));
                            //this->explodeObject((*itObjMov)->getX(),(*itObjMov)->getY(),100,100);
                            (*itObjMov)->deleteObject();
                            objetosMoviles.erase(itObjMov);
                            (*itObjMov2)->deleteObject();
                            objetosMoviles.erase(itObjMov2);


                            return collides;
                        }
                    }
                }
            }
        }
    }
    return collides;

}

int escena::getScore() const
{
    return score;
}

void escena::setScore(int value)
{
    score = value;
}

void escena::setScorePlus()
{
    score ++;
}

vector<objetos_movil *> escena::getObjetosMoviles() const
{
    return objetosMoviles;
}

void escena::setBackGround(bool value)
{
    backGround = value;
}

int escena::getBlood() const
{
    return blood;
}

void escena::setBlood(int value)
{
    blood = value;
}
