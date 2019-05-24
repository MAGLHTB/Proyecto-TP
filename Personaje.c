#include "Personaje.h"
#define WPANTALLA 640
#define HPANTALLA 480
#define WPERSONAJE 60
#define HPERSONAJE 60
#define VXPERSONAJE 6
#define VYPERSONAJE 8
#include <stdlib.h>

struct PersonajeRep
{
    Imagen i;
    int w,h,x,y;
};

Personaje PersonajeCrea (Imagen nave, int w, int h, int x, int y)
{

    Personaje p=malloc(sizeof(struct PersonajeRep));
    p->i=nave;
    p->w=w;
    p->h=h;
    p->x=x;
    p->y=y;
    return p;

}

void PersonajeLibera(Personaje p)
{
    free(p);
}

void PersonajeMueve (Personaje p, int vx, int vy)
{
    p->x+=vx;
    p->y+=vy;
    if (p->x<0) p->x = 0;
    if (p->y<0) p->y = 0;
    if (p->x>WPANTALLA-WPERSONAJE) p->x = WPANTALLA-WPERSONAJE;
    if (p->y>HPANTALLA-HPERSONAJE) p->y = HPANTALLA-HPERSONAJE;


}
void PersonajeDibuja(Personaje p)
{

      Pantalla_DibujaImagen(p->i,p->x,p->y,p->w,p->h);

}
int PersonajeGetX  (Personaje p)
{

    return p->x;

}
int PersonajeGetY  (Personaje p)
{

    return p->y;

}
int PersonajeGetW  (Personaje p)
{

    return p->w;

}
int PersonajeGetH  (Personaje p)
{

    return p->h;

}
