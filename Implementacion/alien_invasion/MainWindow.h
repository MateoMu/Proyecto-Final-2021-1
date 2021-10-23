#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//Librerias necesarias
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
    void addItems2Scene(void);
    void connectItems();

        /// SLOTS
    void comeBack();
    void moveObject();
    void addObjetoGrafico(QString ruta, int x, int y, int w, int h, bool main);

        /// FUNCIONES DE PRUEBA
    void add();
    void cambiofondo();

    void imagen1();
    void imagen2();
    void setPosSir(int x, int y);

private:
    Ui::MainWindow *ui;

        /// LABELS
    QLabel *label1;

        /// ESCENARIO
    escena *scene;
    QGraphicsView *view;

        /// MEDIDAS DE ESCRITORIO
    int desk_widht=1200,desk_height=600;

        /// VALORES DE TIMERS
    int game_time = 0;

        /// VARIABLES AUXILIARES
    bool img = true;
    int cont_aux = 0;
    int cont=1;

        /// VARIABLES DE CONTROL
    QString match_name,username;
    QString main_caracter_path = ":/../Imagenes/fondo2.jpeg";

        ///POSICION DE PERSONAJE PRINCIPAL
    int x_sir = desk_widht/8, y_sir = desk_height-310;
    int w_sir = 200, h_sir = 300;



};

#endif // MAINWINDOW_H
