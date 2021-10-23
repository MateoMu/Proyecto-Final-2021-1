#include "escena.h"

///         CONSTRUCTOR         ///
escena::escena()
{

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

