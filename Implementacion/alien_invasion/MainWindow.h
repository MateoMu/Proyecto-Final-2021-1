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
    void addItems2Scene(int opc);
    void connectItems();



private:
    Ui::MainWindow *ui;

    /// ESCENARIO
escena *scene;
QGraphicsView *view;

/// MEDIDAS DE ESCRITORIO
int desk_widht,desk_height;

/// VALORES DE TIMERS
int game_time = 0;

};

#endif // MAINWINDOW_H
