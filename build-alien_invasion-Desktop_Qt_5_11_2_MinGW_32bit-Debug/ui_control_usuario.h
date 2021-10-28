/********************************************************************************
** Form generated from reading UI file 'control_usuario.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROL_USUARIO_H
#define UI_CONTROL_USUARIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_control_usuario
{
public:

    void setupUi(QDialog *control_usuario)
    {
        if (control_usuario->objectName().isEmpty())
            control_usuario->setObjectName(QStringLiteral("control_usuario"));
        control_usuario->resize(759, 341);
        control_usuario->setStyleSheet(QStringLiteral("border-image: url(:/new/prefix1/Imagenes/fondo.jpg);"));

        retranslateUi(control_usuario);

        QMetaObject::connectSlotsByName(control_usuario);
    } // setupUi

    void retranslateUi(QDialog *control_usuario)
    {
        control_usuario->setWindowTitle(QApplication::translate("control_usuario", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class control_usuario: public Ui_control_usuario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROL_USUARIO_H
