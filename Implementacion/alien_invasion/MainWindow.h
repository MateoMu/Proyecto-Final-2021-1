#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//Librerias necesarias
#include <QApplication>
#include <QMainWindow>
#include <QKeyEvent>
#include <QPushButton>
#include <QGraphicsView>
#include <QDebug>
#include <QLCDNumber>
#include <QLabel>
#include <QProgressBar>
#include <QMessageBox>
#include <stdlib.h>
#include <time.h>
#include "escena.h"

QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

        /// CARACTERISTICAS DE PANTALLA
    void setDeskProperty(int w,int h);

        /// FUNCIONES DE CARGA DE OBJETOS Y PRESENTACION
    void instanceItems();
    void hideItems();
    void addItems2Scene();
    void connectItems();

        /// SLOTS
    void moveObject();
    void addObjetoGrafico(QString ruta, int x, int y, int w, int h, bool main);
    void addObjetoMovil(QString ruta,int xo,int yo,int xf,int yf,int w,int h,int _move);
    void addObjetoMovil(QString ruta,int xo,int yo,int v0,int angle,int _move);
    void addObjetoMovil1();
    void addObjetoMovil2();
    void addObjetoMovil3();
    void addEnemy();

        ///Eventos del Mouse
    void mousePressEvent(QMouseEvent *event);

        /// FUNCIONES DE PRUEBA
    void add();
    void cambiofondo();

    void imagen1();
    void imagen2();
    void setPosSir(int x, int y);
    void setBackground1();
    void setBackground2();

private:
    Ui::MainWindow *ui;

        /// LABELS
    QLabel *label1;
    QLabel *label2;

        /// TIMERS
    QTimer *enemy_timer;
    QTimer *seconds;
    QTimer *timer;

        /// ESCENARIO
    escena *scene;
    QGraphicsView *view;

        /// MEDIDAS DE ESCRITORIO
    int desk_widht,desk_height;

        /// VALORES DE TIMERS
    int game_time = 0;

        /// VARIABLES AUXILIARES
    QString time_format;
    bool img = true;
    int cont_aux = 0;
    int cont=1;

        /// VARIABLES DE CONTROL
    QString match_name,username;
    QString main_caracter_path = ":/new/prefix1/Imagenes/fondo1.jpeg";
    QString enemy_path = ":/new/prefix1/Imagenes/Bala1.png";
    QString bala1_path = ":/new/prefix1/Imagenes/Bala1.png";
    QString bala2_path = ":/new/prefix1/Imagenes/Bala1.png";
    QString bala3_path = ":/new/prefix1/Imagenes/Bala1.png";
        ///POSICION DE PERSONAJE PRINCIPAL
    int x_sir = desk_widht/8, y_sir = desk_height-310;
    int w_sir = 200, h_sir = 300;

        /// NUMERO DE MUNICIONES
    int ammu1 = 10, ammu2 = 10, ammu3 =  10;
        /// INDICADOR DE TIPO MOVIMIENTO
    int move1 = 1 , move2 = 1;
        /// VALORES DE TIMERS
    int fs_time = 50;
    int time_enemys = 1500,time_seconds = 1000;
    int level = 1;



    signals:
    void end();
};

#endif // MAINWINDOW_H
