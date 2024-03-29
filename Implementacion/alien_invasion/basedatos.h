#ifndef BASEDATOS_H
#define BASEDATOS_H

#include <QDialog>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include "objetos_movil.h"


class basedatos
{
public:
        //CONSTRUCTOR
    basedatos();

//CREAR TABLAS
    void crearTabladeUsuarios();
    void crearTabladeDatos();
    void crearTabladeEnemigos();
    void crearTabladeRecords();

    //INSERTAR VALORES A LAS TABLAS
    void insertarUsuario();
    void insertarUsuario(QString user, QString pass);
    bool insertarDatos(QString match_name, QString username, bool arcade, int nivel, int player,
                       int blood, int gameTime, int score_1, int score_2, int ammo1,
                       int ammo2, int ammo3);
    bool insertarEnemigos(QString match_name, QString username, int x, int y, int v0, int angle, int move);

    void insertarRecord();
    void insertarRecord(QString name, QString high_score, QString player);

    //MUESTRA CON QDEBUG LOS DATOS EN LAS TABLAS

    void mostrarUsuarios();
    vector<QString> mostrarDatos(QString match_name, QString username);
    vector<QString> mostrarEnemigos(QString match_name, QString username);
    vector<QString> mostrarRecord();
    vector<QString> mostrarPartidas(QString username);

    //VERIFICA QUE LOS DATOS ESTEN O NO

    bool validarUsuario(QString _name, QString _psswd);
    bool validarMatchName(QString name);


    //METODOS GET Y SET DE VARIABLES
    bool getUser() const;
    bool getPassword() const;

    void setUser(bool value);
    void setPassword(bool value);


    int level;

    bool turno;
    int vida_1,score_1;
    int vida_2,score_2;

    ~basedatos();



    QString getName_partida() const;
    void setName_partida(const QString &value);

    QString getName() const;
    void setName(const QString &value);

private:
    QSqlDatabase database;
    QString name;
    QString pass;
    QString name_partida;

    int high_score;
    bool user, password;

};

#endif // BASEDATOS_H
