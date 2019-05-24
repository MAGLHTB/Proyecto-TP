#ifndef COLISION_H_INCLUDED
#define COLISION_H_INCLUDED
/**
    \file Colision.h
    \brief La biblioteca Colision.h nos permite tener un sistema de colisiones
*/
/**
    \brief La función Colision nos permite saber si ha habido colisión entre dos elementos
    \param x1 Coordenada x del primer elemento
    \param y1 Coordenada y del primer elemento
    \param h1 Altura del primer elemento
    \param w1 Anchura del primer elemento
    \param x2 Coordenada x del segundo elemento
    \param y2 Coordenada y del segundo elemento
    \param h2 Altura del segundo elemento
    \param w2 Anchura del segundo elemento
    \return Devuelve 0  si no ha habido colisión o devuelve un entero si ha habido colisión
*/
int Colision(int x1, int y1, int h1, int w1, int x2, int y2, int h2, int w2);


#endif // COLISION_H_INCLUDED
