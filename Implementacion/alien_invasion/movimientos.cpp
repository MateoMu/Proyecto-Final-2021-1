#include "movimientos.h"

movimientos::movimientos()
{

}

movimientos::movimientos(float _x,float _y,int xf,int yf): x(_x),y(_y),px(_x),py(_y),pfx(xf),pfy(yf)
{
    ///ASIGNACION DE LADO

    if (_x <= xf) lado = true;       //Movimiento de izquierda a derecha
    else lado = false;              //Movimiento de derecha a izquierda
}

void movimientos::setMUA()
{
    vx=(pfx-px-float(0.5)*ax*float(DT*DT));
    vy=(pfy-py-float(0.5)*ay*float(DT*DT));
    qDebug()<<"vx: "<<vx;
    qDebug()<<"vy: "<<vy;

}

bool movimientos::actualizarMUA()
{
    bool outScene = false;
    float v = 10;
    float A = 30;
    float freq = 1/2;
    if(!lado) v = -30;
    if(!lado){
        x = x + v*t;
        y = y + A*sin(2*3.1416*freq*t);
    }
    else{
        x = x + vx*t;
        y = y + vy*t;
    }
    //qDebug()<<x<<" , "<<t;
    t = t +0.01;
    ///SI SE CUMPLE LA CONDICION
    if(lado) {if(x >= pfx) outScene = true;}    //Comprobando que el objeto siga en escena
    if(!lado) {if(x <= pfx) outScene = true;}

    ///RETORNO DE VALOR
    return outScene;
}

void movimientos::setMovSeno()
{
    x = px; y = py;
}

bool movimientos::actualizarSeno()
{
    bool outScene = false;
    float v = 10;
    float A = 30;
    float freq = 1/2;
    if(lado) x = x + v;
    else x = x - v;

    y = y + (-1*A*cos(/*2*3.1416*freq**/t));
    //qDebug()<<x<<" , "<<sin(2*3.1416*freq*x);
    t = t +0.4;
    ///SI SE CUMPLE LA CONDICION
    if(lado) {if(x >= pfx) outScene = true;}    //Comprobando que el objeto siga en escena
    if(!lado) {if(x <= pfx) outScene = true;}

    ///RETORNO DE VALOR
    return outScene;
}

bool movimientos::actualizar(float dt)
{
    ///DECLARACION DE VARIABLES AUXILIARES LOCALES
    bool outScene = false;
    //ax = 0;                         //Aceleracion en Componente x
    //ay = G;                         //Aceleracion en Componente y

    ///ASIGNACION DE VALORES
    //vx = vx;                      //Velocidad en Componente x
    vy = vy - ay*dt;                //Velocidad en Componente y
    x = x + vx*dt;                  //Nueva Posicion x
    y = y + vy*dt-(0.5*ay*dt*dt);   //Nueva Posicion y

    //qDebug()<<"Posicion: "<<x<<", "<<y;

    ///SI SE CUMPLE LA CONDICION
    if(lado) {if(x >= pfx) outScene = true;}    //Comprobando que el objeto siga en escena
    if(!lado) {if(x <= pfx) outScene = true;}

    ///RETORNO DE VALOR
    return outScene;
}

bool movimientos::nParabolicos(float xf, float yf, float d, float factorImpacto)
{
    ///DECLARACION DE VARIABLES AUXILIARES LOCALES
    bool impacto = false;           //Bandera que indica si hubo impacto o no
    bool aux=false;                 //Variable auxiliar
    int v0_,angle,cont=0;           //Variables Temporales para cada iterador


    ///MIENTRAS SE CUMPLA LA CONDICION
    for(v0_=0;;){
                        //Iteracion para diferentes valores de Velocidad
        for( angle= 30; (angle< 90); angle++){
                            //Iteracion para diferentes valores de Angulo
            x = px; y = py; angulo = angle, v0 = v0_;           //Inicializacion de Variables para cada valor de angulo y velocidad
            aux = parabolico(xf,yf,v0_,angle,d,factorImpacto);  //Retorna true si la parabola es efectiva
            //qDebug()<<"Calculando parabolico";
            if(aux){
                                // Se ejecuta si y solo si hubo impacto
                //qDebug()<<"Impacto numero: "<<cont+1;
                setParametros(cont);
                /*imprimirValoresImpacto();*/ impacto = true; cont++; break;
            }
            if(cont == 1) break;
        }
        if(cont == 1) break;
        if(lado){                                       //De izquierda a derecha
                            //Condicion Relativa De Fin de la Funcion
            v0_+=5;
            if(x >= 2*(xf+(factorImpacto*d))) break;            // Si la Posicion Excede la Posicion Enemiga en X
        }
        else{                                           //De derecha a izquierda
            v0_-=5;
            if(x < 2*(xf-(factorImpacto*d))) break;             // Si la Posicion Excede la Posicion Enemiga en X
        }
    }
    return impacto;
}

bool movimientos::parabolico(float xf, float yf, int _v0,int _angle,float d, float factorImpacto)
{
    ///DECLARACION DE VARIABLES AUXILIARES LOCALES
    bool impacto = false;
    float dt = 0.1;                 //Delta de tiempo
    ymax = 0;                       //Posicion Maxima en y
    time = 0;                       //Se inicializa el tiempo de lanzamiento en cero

    ///ASIGNACION DE VALORES
    vx = _v0*cos(_angle*pi/180);    //Velocidad inicial de x
    vy = abs(_v0)*sin(_angle*pi/180) - ay*dt; //Velocidad inicial de y

    ///MIENTRAS SE CUMPLA LA CONDICION
    while((y >= 0) ){
                        //Mientras el proyectil este sobre la superficie
        actualizar(dt);                     //Actualizar parametros de movimiento
        if(sqrt(pow((xf - x),2)+pow((yf - y),2)) <= factorImpacto*d){
            impacto=true; break; //Impacto si las posiciones estan en el area de explosion
        }
        time = time + dt;

        if(y > ymax) ymax = y;
    }

    ///RETORNO DE VALOR
    return impacto;
}

vector<float> movimientos::parabolico(float timeStop,float _x, float _y, int _v0, int _angle)
{
    ///DECLARACION DE VARIABLES AUXILIARES LOCALES
    vector<float> pos;
    float dt = 0.1; //Delta de tiempo

    ///ASIGNACION DE VALORES
    time = 0;       //Se inicializa el tiempo de lanzamiento en cero
    x = _x; y = _y;
    vx = _v0*cos(_angle*pi/180);    //Velocidad inicial de x
    vy = abs(_v0)*sin(_angle*pi/180) - ay*dt; //Velocidad inicial de y

    ///MIENTRAS SE CUMPLA LA CONDICION
    while((y >= 0) || time >= timeStop ){   //Mientras el proyectil este sobre la superficie
        actualizar(dt); //Actualizar parametros de movimiento
        time = time + dt;
    }
    pos.push_back(x);
    pos.push_back(y);

    ///RETORNO DE VALOR
    return pos;
}



void movimientos::setParametros(int cont)
{
    ///ASIGNACION DE VALORES
    parametrosLanzamiento.clear();
    parametrosLanzamiento.push_back(x);             //0
    parametrosLanzamiento.push_back(y);             //1
    parametrosLanzamiento.push_back(time);          //2
    parametrosLanzamiento.push_back(angulo);        //3
    parametrosLanzamiento.push_back(v0);            //4
    parametrosLanzamiento.push_back(ymax);          //5
    lanzamientos.insert(pair<int,vector<float>>(cont,parametrosLanzamiento));
}

map<int, vector<float> > movimientos::getParametros()
{
    ///RETORNO DE VALOR
    return lanzamientos;
}

vector<float> movimientos::getBest(int param,bool minMax)
{
    ///DECLARACION DE VARIABLES AUXILIARES
    int pos = getPosBestMove(param,minMax);
    //qDebug()<<"Posicion del mejor "<<pos;

    ///SI SE CUMPLE LA CONDICION
    if(pos != -1){                              //Si NO hay errores
        parametrosLanzamiento.clear();
        parametrosLanzamiento.push_back(lanzamientos.at(pos).at(0));
        parametrosLanzamiento.push_back(lanzamientos.at(pos).at(1));
        parametrosLanzamiento.push_back(lanzamientos.at(pos).at(2));
        parametrosLanzamiento.push_back(lanzamientos.at(pos).at(3));
        parametrosLanzamiento.push_back(lanzamientos.at(pos).at(4));
        parametrosLanzamiento.push_back(lanzamientos.at(pos).at(5));
        //imprimirVector(parametrosLanzamiento);
    }

    ///RETORNO DE VALOR
    return parametrosLanzamiento;
}

void movimientos::imprimirValoresImpacto()
{
    ///IMPRESION DE VALORES
    qDebug()<<"--------------------------";
    qDebug()<<"Impacto: ";
    qDebug()<<"Tiempo: "<<time<<" sg\n";
    qDebug()<<"Angulo: "<<angulo<<"º\n";
    qDebug()<<"Velocidad: "<<v0<<" m/sg\n";
    qDebug()<<"Posicion Final ("<<x<<","<<y<<")\n";
    qDebug()<<"Altura Maxima "<<ymax<<" m.\n";
    qDebug()<<"--------------------------";
}

void movimientos::imprimirVector(vector<float> vec)
{
    ///DECLARACION DE VARIABLES AUXILIARES LOCALES
    vector<float>::iterator it;
    ///MIENTRAS SE CUMPLA LA CONDICION
    for(it = vec.begin();it != vec.end();it++){
        ///IMPRESION DE VALORES
        qDebug()<<"Valor -> "<<*it;
    }
}

map<int, vector<float> > movimientos::getLanzamientos() const
{
    return lanzamientos;
}

bool movimientos::getLado() const
{
    return lado;
}

float movimientos::getVx() const
{
    return vx;
}

float movimientos::getVy() const
{
    return vy;
}

void movimientos::setReverse()
{
    if(lado) vy = -1*vy*e1;
    else vy = -1*vy*e2;
    ay = -1*G;
}

int movimientos::getPosBestMove(int param, bool minMax)
{
    ///DECLARACION DE VARIABLES AUXILIARES LOCALES
    int val = 0, pos = 0, cont = 0;

    ///ASIGNACION DE VALORES
    //minMax --> Variable Auxiliar(True->Minimo Valor,False-->Maximo Valor)
    it=lanzamientos.begin();

    ///SI SE CUMPLE LA CONDICION
    if(unsigned(param) < it->second.size()){
        val = it->second.at(param);
        for(;it != lanzamientos.end();it++,cont++){
            ///SI SE CUMPLE LA CONDICION
            if(minMax){                         //Si Necesita el Valor minimo
                ///SI SE CUMPLE LA CONDICION
                if(it->second.at(param) < val ) {val = it->second.at(param);pos = cont;}
            }
            ///SI NO SE CUMPLE LA CONDICION
            else{                               //Si Necesita el Valor minimo
                if(it->second.at(param) > val )  {val = it->second.at(param);pos = cont;}
            }
        }
    }
    ///SI NO SE CUMPLE LA CONDICION
    else pos = -1; //-1 si hay errores

    ///RETORNO DE VALOR
    return pos;
}



float movimientos::getX() const
{
    ///RETORNO DE VALOR
    return x;
}

float movimientos::getY() const
{
    ///RETORNO DE VALOR
    return y;
}

void movimientos::setParamsMove(float _v0, float angle)
{
    ///ASIGNACION DE VALORES
    x = px;     y = py;
    v0 = _v0;   angulo = angle;
    vx = v0*cos(angulo*pi/180);    //Velocidad inicial de x
    vy = abs(v0)*sin(angulo*pi/180) - ay*DT; //Velocidad inicial de y
}

void movimientos::set_vel(int _vx, int _vy, int _px, int _py)
{
    vx = _vx;
    vy = _vy;
    x = _px;
    y = _py;
}
