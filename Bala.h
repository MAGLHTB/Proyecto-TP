#ifndef BALA_H_INCLUDED
#define BALA_H_INCLUDED
#include "Pantalla.h"
/**
    \file Bala.h
    \brief La biblioteca Bala.h nos crea los disparos del personaje.
*/

/**
    \brief TDA Bala.
*/


typedef struct BalaRep * Bala;
/**
    \brief Creamos una bala.
    \param bala Imagen de la bala.
    \param x Coordenada x de la bala.
    \param y Coordenada y de la bala.
    \param w Ancho de la bala.
    \param h Alto de la bala.
    \param vy Velocidad en el eje y.
    \return Devuelve una bala.
*/

Bala BalaCrea (Imagen bala,int x, int y, int w, int h, int vy);
/**
    \brief Elimina una bala.
    \param b Bala a eliminar.
*/

void BalaLibera (Bala b);
/**
    \brief Dibuja una bala en Pantalla.
    \param b Bala a dibujar.
*/
void BalaDibuja(Bala b);
/**
    \brief Devuelve la coordenada x de una Bala.
    \param b Bala la cual queremos su coordenada x.
    \return Coordenada x de la Bala.
*/
int BalaGetX  (Bala b);
/**
    \brief Devuelve la coordenada y de una Bala.
    \param b Bala la cual queremos su coordenada y.
    \return Coordenada y de la Bala.
*/
int BalaGetY  (Bala b);
/**
    \brief Devuelve la anchura de una Bala.
    \param b Bala la cual queremos su anchura.
    \return Anchura de la Bala.
*/
int BalaGetW  (Bala b);
/**
    \brief Devuelve la altura de una Bala.
    \param b Bala la cual queremos su altura.
    \return Altura de la Bala.
*/
int BalaGetH  (Bala b);
/**
    \brief Mueve la bala.
    \param b Bala la cual queremos que se mueva.
    \return 1 si la bala se mueve, 0 si no se mueve.
*/
int BalaMueve (Bala b);


#endif // BALA_H_INCLUDED

