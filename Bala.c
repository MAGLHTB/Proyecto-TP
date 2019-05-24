#include "Bala.h"
#include <stdlib.h>
#define WBALA 20
#define HBALA 20
#define VBALA 10
#define maxrecarga 100
struct BalaRep
{
    Imagen i;
    int x,y,w,h,vy;
};
Bala BalaCrea(Imagen i,int x, int y, int w, int h,int vy)
{
    Bala b=malloc(sizeof(struct BalaRep));
    b->i=i;
    b->x=x;
    b->y=y;
    b->w=WBALA;
    b->h=HBALA;
    b->vy = VBALA;
    return b;
}

void BalaLibera(Bala b)
{
    free(b);
}

void BalaDibuja(Bala b)
{

      Pantalla_DibujaImagen(b->i,b->x,b->y,b->w,b->h);

}

int BalaGetX  (Bala b)
{

    return b->x;

}
int BalaGetY  (Bala b)
{

    return b->y;

}
int BalaGetW  (Bala b)
{

    return b->w;

}
int BalaGetH  (Bala b)
{

    return b->h;

}
int BalaMueve (Bala b)

{

    b->y -= b->vy;

    if(b->y>Pantalla_Altura()-b->h)
    {
        b->y = Pantalla_Altura()-b->y;
    }

    return (b->y>Pantalla_Altura()-b->h);
}



