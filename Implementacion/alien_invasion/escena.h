#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsScene>
#include <QPushButton>

class escena : public QGraphicsScene
{

public:
        /// CONSTRUCTOR Y DESTRUCTOR
    escena();
    ~escena();



        /// CARACTERISTICAS DE ESCRITORIO
    void setWindowProperty(int desk_w, int desk_h);


private:
        /// CARACTERISTICAS DE ESCRITORIO
    int limit_x,limit_y;
};

#endif // SCENE_H
