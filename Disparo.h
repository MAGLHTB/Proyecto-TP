#ifndef DISPARO_H_INCLUDED
#define DISPARO_H_INCLUDED
#include "Bala.h"
#include "FLOT.h"
/**
    \file Disparo.h
    \brief La biblioteca Disparo.h nos permite crear una estructura en la que almacenamos nuestras balas.
*/
/**
    \brief TDA Disparo
 */

typedef struct DisparoRep * Disparo;

/**
    \brief Creamos un Disparo vac�o.
    \return Devuelve una Disparo.
*/

Disparo DisparoCrea();

/**
    \brief Eliminamos Disparo.
    \param d Disparo la cual queremos eliminar.
*/


void DisparoLibera(Disparo d);
/**
    \brief Hacemos que el Disparo se mueva.
    \param d Disparo el cual queremos que se mueva.
*/
void DisparoMueve(Disparo d);

/**
    \brief Dibujamos la Flota por Pantalla.
    \param d Disparo el cual queremos dibujar.
*/

void DisparoDibuja(Disparo d);
/**
    \brief Comprueba si ha habido colisi�n con los disparo y otro elemento
    \param d Disparo la cual queremos sabar si ha tenido colisi�n
    \param x Coordenada x del elemento
    \param y Coordenada y del elemento
    \param w Anchura del elemento
    \param h Altura del elemento
    \return 0 si no ha habido colisi�n, un entero si ha habido colisi�n

*/

int DisparoColision(Disparo d, int x, int y, int w, int h);

/**

    \brief Inserta balas en el disparo
    \param d Disparo en el cual queremos insertar las balas
    \param b Bala la cual queremos insertar
*/

void DisparoInsertaNuevaBala(Disparo d, Bala b);

/**
    \brief Comprueba si ha habido colisi�n con los disparos y una flota
    \param d Disparo el cual queremos saber si ha tenido colisi�n
    \param f Flota la cual queremos saber si ha tenido colisi�n
    \return 0 si no ha habido colisi�n, 1 si ha habido colisi�n
*/

int DisparoColisionFlota(Disparo d, Flota f);

#endif // DISPARO_H_INCLUDED

