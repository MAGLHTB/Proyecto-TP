#ifndef ASTRO_H_INCLUDED
#define ASTRO_H_INCLUDED
#include "Pantalla.h"

/**
    \file Astro.h
    \brief La biblioteca Astro.h nos permite generar Astros que apareceran en pantalla

*/


/**

    \brief TDA Astro

*/
typedef struct AstroRep * Astro;

/**
    \brief Crea un Astro
    \param i Imagen del Astro
    \param w Anchura del Astro
    \param h Altura del Astro
    \param x Coordenada x del Astro
    \param y Coordenada y del Astro
    \return a Devuelve un Astro

*/

Astro AstroCrea(Imagen i,int w,int h, int x, int y);
/**
    \brief Elimina un astro
    \param a Astro a eliminar
*/
void AstroLibera(Astro a);
/**
    \brief Dibuja por pantalla un astro
    \param a Astro a dibujar
*/
void AstroDibuja(Astro a);
/**
    \brief Devuelve la coordenada x de un Astro
    \param a Astro del cual queremos la coordenada x
    \return Coordenada x del Astro
*/

int AstroGetX  (Astro a);
/**
    \brief Devuelve la coordenada y de un Astro
    \param a Astro del cual queremos la coordenada y
    \return Coordeanada y del astro
*/
int AstroGetY  (Astro a);
/**
    \brief Devuelve la anchura de un Astro
    \param a Astro del cual queremos la anchura
    \return Anchura del Astro
*/
int AstroGetW  (Astro a);
/**
    \brief Devuelve la altura de un Astro
    \param a Astro del cual queremos la altura
    \return Altura del Astro
*/
int AstroGetH  (Astro a);

#endif // ASTRO_H_INCLUDED
