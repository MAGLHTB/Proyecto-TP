#include "Astro.h"
#include <stdio.h>
#include <stdlib.h>

struct AstroRep
{
    Imagen i;
    int w,h,x,y;
};

Astro AstroCrea(Imagen planeta, int w, int h, int x, int y)
{
    Astro a=malloc(sizeof(struct AstroRep));
    a->i=planeta;
    a->w=w;
    a->h=h;
    a->x=x;
    a->y=y;
    return a;

}

void AstroLibera(Astro a)
{
    free(a);
}



void AstroDibuja(Astro a)
{

      Pantalla_DibujaImagen(a->i,a->x,a->y,a->w,a->h);

}
int AstroGetX  (Astro a)
{

    return a->x;

}
int AstroGetY  (Astro a)
{

    return a->y;

}
int AstroGetW  (Astro a)
{

    return a->w;

}
int AstroGetH  (Astro a)
{

    return a->h;

}

