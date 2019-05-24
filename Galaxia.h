#ifndef GALAXIA_H_INCLUDED
#define GALAXIA_H_INCLUDED
#include "Astro.h"

/**
    \file Galaxia.h
    \brief La biblioteca Galaxia.h nos permite crear una estructura donde podemos almacenar elementos del tipo Astro
*/
/**
    \brief TDA Galaxia
 */
typedef struct GalaxiaRep * Galaxia;
/**
    \brief Crea una Galaxia
    \param max Máximo de elementos permitidos en la Galaxia
    \return Devuelve una Galaxia
*/
Galaxia GalaxiaCrea (int max);
/**
    \brief Elimina una Galaxia
    \param g Galaxia a eliminar
*/
void GalaxiaLibera(Galaxia g);
/**
    \brief Inserta un nuevo Astro en la Galaxia
    \param g Galaxia en la que queremos insertar un nuevo astro
    \param a Astro que queremos insertar
*/
void GalaxiaInsertaNuevoAstro(Galaxia g, Astro a);
/**
    \brief Dibuja la Galaxia en pantalla
    \param g Galaxia a dibujar
*/

void GalaxiaDibuja (Galaxia g);
/**
    \brief Comprueba si ha habido colisión con la Galaxia con los elementos designados
    \param g Galaxia la cual queremos saber si ha tenido colisión
    \param x Coordenada x
    \param y Coordenada y
    \param w Anchura del elemento
    \param h Altura del elemento
    \return Devuelve 0 si no ha habido colisión o Devuelve un entero si ha habido colisión
*/
int GalaxiaColision(Galaxia g, int x, int y, int w, int h);


#endif // GALAXIA_H_INCLUDED
