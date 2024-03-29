#ifndef CONTROL_USUARIO_H
#define CONTROL_USUARIO_H
#include <QDialog>
#include <QDesktopWidget>
#include <QTableWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QMessageBox>
#include <QPalette>
#include "mainwindow.h"
#include "basedatos.h"

namespace Ui {
class control_usuario;
}

class control_usuario : public QDialog
{
    Q_OBJECT

public:
    explicit control_usuario(QWidget *parent = nullptr);
    ~control_usuario();

    ///FUNCIONES
    void crearObjetos();
    void hideItems();
    void disconnectAll();
    void showSavedGames();
    void showRecords();
    void exit();

    ///DISEÑO DE VENTANA
    void welcomeWindow();
    void setCredentialsWindow();
    void setMenuWindow();
    void loadGameWindow();
    void recordsWindow();
    void setMatchNameWindow();
    void matchNameWindow();
    void loadGame();
    void showRecordsWindow();


    ///Eventos de Teclado
    void keyPressEvent(QKeyEvent *event);

    ///SLOTS BOTONES
    void showMainWindow();
    void setArcade();
    void setMultiplayer();
    void logIn();
    void signIn();
    void validateUser();
    void createUser();
    void startGame();
    void loadDataGame();
    void setBackground1();
    void setBackground2();

    void printVector(vector<QString> vec);
    void printVectorInTable(vector<QString> vec, QStringList l, int columns);
    void infoBox(QString title, QString text, QString infoText);



private:
    Ui::control_usuario *ui;
    MainWindow *gameWindow;
    QDesktopWidget *deskWidget;
    basedatos *database;
    QMessageBox *msgBox;

    QPushButton *boton1;
    QPushButton *boton2;
    QPushButton *boton3;
    QPushButton *boton4;
    QPushButton *boton5;
    QPushButton *boton6;
    QPushButton *boton7;

    QLabel *label1;
    QLabel *label2;
    QLabel *label3;

    QLineEdit *line_Edit1;
    QLineEdit *line_Edit2;
    QLineEdit *line_Edit3;
    QSpinBox *spin_box1;

    QTableWidget *table_widget;

    int desk_width,desk_height;
    QString user_name ;


    bool arcade = true;
    bool newUser = true;
};

#endif // CONTROL_USUARIO_H
