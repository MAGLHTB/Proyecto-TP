#ifndef PERSONAJE_H_INCLUDED
#define PERSONAJE_H_INCLUDED
#include "Pantalla.h"

/**
    \file Personaje.h
    \brief La biblioteca Personaje.h es una biblioteca con la que definimos el personaje del videojueego
*/

/**
    \brief TDA Personaje
 */

typedef struct PersonajeRep * Personaje;

/**
    \brief Crea y configura el personaje
    \param i Imagen del personaje
    \param w Ancho del personaje
    \param h Alto del personaje
    \param x Coordenada x del personaje
    \param y Coordenada y del personaje
    \return Devuelve un personaje
*/

Personaje PersonajeCrea (Imagen i, int w, int h, int x, int y);

/**
    \brief Elimina a un personaje
    \param p Personaje a eliminar

*/

void PersonajeLibera(Personaje p);

/**
    \brief Hace que el personaje se mueva
    \param p Personaje que queremos que se mueva
    \param vx Velocidad en la coordenada x
    \param vy Velocidad en la coordenada y
*/
void PersonajeMueve (Personaje p, int vx, int vy);
/**
    \brief Dibuja en pantalla un personaje
    \param p Personaje que queremos dibujar
*/

void PersonajeDibuja(Personaje p);
/**
    \brief Devuelve la coordenada x de un personaje
    \param p Personaje del cual queremos su coordenada x
    \return Coordenada x del personaje
*/

int PersonajeGetX  (Personaje p);
/**
    \brief Devuelve la coordenada y de un personaje
    \param p Personaje del cual queremos su coordenada y
    \return Coordenada y del personaje
*/
int PersonajeGetY  (Personaje p);
/**
    \brief Devuelve la anchura de un personaje
    \param p Personaje del cual queremos su anchura
    \return Anchura del personaje
*/
int PersonajeGetW  (Personaje p);
/**
    \brief Devuelve la altura de un personaje
    \param p Personaje del cual queremos su altura
    \return Altura del personaje
*/
int PersonajeGetH  (Personaje p);


#endif // PERSONAJE_H_INCLUDED
