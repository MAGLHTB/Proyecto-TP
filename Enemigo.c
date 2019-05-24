#include "Enemigo.h"
#include "Pantalla.h"
#include <stdio.h>
#include <stdlib.h>
#define WPANTALLA 640
#define HPANTALLA 480
#define WENEMIGO 40
#define HENEMIGO 40
#define VXENEMIGO 3
#define VYENEMIGO 3
struct EnemigoRep
{
    Imagen i;
    int w,h,x,y,vx,vy;
};

Enemigo EnemigoCrea(Imagen i, int w, int h, int x, int y,int vx, int vy){
    Enemigo e = malloc(sizeof(struct EnemigoRep));
    e->i=i;
    e->w=WENEMIGO;
    e->h=HENEMIGO;
    e->x=x;
    e->y=y;
if(rand()%2)
    e->vx=VXENEMIGO;
else
    e->vx=-VXENEMIGO;
    e->vy=VYENEMIGO;
    return e;
}
void EnemigoLibera(Enemigo e)
{
    free(e);
}


void EnemigoDibuja(Enemigo e)
{

      Pantalla_DibujaImagen(e->i,e->x,e->y,e->w,e->h);

}
int EnemigoGetX  (Enemigo e)
{

    return e->x;

}
int EnemigoGetY  (Enemigo e)
{

    return e->y;

}
int EnemigoGetW  (Enemigo e)
{

    return e->w;

}
int EnemigoGetH  (Enemigo e)
{

    return e->h;

}


int EnemigoMueve(Enemigo e)
{
    e->x += e->vx;
    e->y += e->vy;
    if  (e->x<0)
    {
        e->x=0;
        e->vx=-1;
    }
    if (e->x>Pantalla_Anchura()-e->w)
    {
        e->x = Pantalla_Anchura()-e->w;
        e->vx=-1;
    if (e->y<0)
        e->y=0;
        e->vy*=1;
    if(e->y>Pantalla_Altura()-e->h)
    {
        e->y = Pantalla_Altura()-e->y;
    }
}
    return (e->y>Pantalla_Altura()-e->h);

}
