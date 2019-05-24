#ifndef ENEMIGO_H_INCLUDED
#define ENEMIGO_H_INCLUDED
#include "Pantalla.h"
#include <stdio.h>
/**
    \file Enemigo.h
    \brief La biblioteca Enemigo.h es una biblioteca con la que definimos el enemigo del videojueego
*/

/**
    \brief TDA Enemigo
 */
typedef struct EnemigoRep * Enemigo;

/**
    \brief Crea y configura el enemigo
    \param i Imagen del enemigo
    \param w Ancho del enemigo
    \param h Altura del enemigo
    \param x Coordenada x del enemigo
    \param y Coordenada y del enemigo
    \param vx Velocidad en el eje x del enemigo
    \param vy Velocidad en el eje y del enemigo
    \return e Devuelve un enemigo
*/
Enemigo EnemigoCrea (Imagen i, int w, int h, int x, int y,int vx, int vy);
/**
    \brief Elimina a un enemigo
    \param e Enemigo a eliminar
*/
void EnemigoLibera(Enemigo e);
/**
    \brief Hace que el enemigo se mueva
    \param e Enemigo que queremos mover
    \return Devuelve la posición del enemigo
*/

int EnemigoMueve (Enemigo e);
/**
    \brief Dibuja en la pantalla a un enemigo
    \param e Enemigo que queremos dibujar
*/
void EnemigoDibuja(Enemigo e);
/**
    \brief Devuelve la coordenada x de un enemigo
    \param e Enemigo del cual queremos su coordenada x
    \return Coordenada x del enemigo
*/
int EnemigoGetX  (Enemigo e);
/**
    \brief Devuelve la coordenada y de un enemigo
    \param e Enemigo del cual queremos su coordenada x
    \return Coordenada x del enemigo
*/
int EnemigoGetY  (Enemigo e);
/**
    \brief Devuelve la anchura de un enemigo
    \param e Enemigo del cual queremos su coordenada x
    \return Anchura del enemigo
*/
int EnemigoGetW  (Enemigo e);
/**
    \brief Devuelve la altura de un enemigo
    \param e Enemigo del cual queremos su coordenada x
    \return Altura del enemigo
*/
int EnemigoGetH  (Enemigo e);



#endif // ENEMIGO_H_INCLUDED
