#ifndef FLOTA_H_INCLUDED
#define FLOTA_H_INCLUDED
#include "Enemigo.h"
/**
    \file FLOT.h
    \brief La biblioteca FLOT.h nos permite crear una estructura en la que almacenamos a nuestros enemigos.
*/
/**
    \brief TDA Flota
 */
typedef struct FlotaRep * Flota;

/**
    \brief Creamos una Flota vacía.
    \return Devuelve una flota.
*/


Flota FlotaCrea();
/**
    \brief Eliminamos una Flota.
    \param f Flota la cual queremos eliminar.
*/



void FlotaLibera(Flota f);
/**
    \brief Hacemos que la Flota se mueva.
    \param f Flota la cual queremos que se mueva.
*/
void FlotaMueve(Flota f);
/**
    \brief Dibujamos la Flota por Pantalla.
    \param f Flota la cual queremos dibujar.
*/

void FlotaDibuja(Flota f);
/**
    \brief Insertamos un nuevo Enemigo en la Flota.
    \param f Flota a la cual le queremos insertar el enemigo.
    \param e Enemigo el cual queremos insertar.
*/
void FlotaInsertaNuevoEnemigo(Flota f, Enemigo e);
/**
    \brief Comprueba si ha habido colisión con la Flota y otro elemento
    \param f Flota la cual queremos sabar si ha tenido colisión
    \param x Coordenada x del elemento
    \param y Coordenada y del elemento
    \param w Anchura del elemento
    \param h Altura del elemento

*/
int FlotaColision(Flota f, int x, int y, int w, int h);


#endif // FLOTA_H_INCLUDED
