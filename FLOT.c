#include <stdlib.h>
#include "FLOT.h"
#include "Colision.h"
#include "Enemigo.h"
#include <stdio.h>


struct FlotaRep
{
    Enemigo e;
    Flota sig;
};

Flota FlotaCrea()
{
    Flota f = malloc(sizeof(struct FlotaRep));
    f->sig=NULL;
    return f;
}

void FlotaLibera(Flota f)
{
    while(f->sig!=NULL)
    {

        Flota aux=f->sig;
        f->sig=f->sig->sig;
        EnemigoLibera(aux->e);
        free(aux);
    }
    free(f);
}

void FlotaMueve(Flota f)
{
    while(f->sig!=NULL)
    {
        if(EnemigoMueve(f->sig->e))
        {
            Flota aux=f->sig;
            f->sig = f->sig->sig;
            EnemigoLibera(aux->e);
            free(aux);
        }
        else f=f->sig;
    }
}

void FlotaDibuja(Flota f)
{
    for (; f->sig!=NULL; f=f->sig)
    {
        EnemigoDibuja(f->sig->e);
    }

}
void FlotaInsertaNuevoEnemigo(Flota f,Enemigo enemigo)
{
    Flota aux=malloc(sizeof(struct FlotaRep));
    aux->e=enemigo;
    aux->sig = f->sig;
    f->sig=aux;
}

int FlotaColision(Flota f,int x,int y,int w,int h)
{
    while((f->sig!=NULL)&&(!Colision(EnemigoGetX(f->sig->e)
                                     ,EnemigoGetY(f->sig->e)
                                     ,EnemigoGetH(f->sig->e)
                                     ,EnemigoGetW(f->sig->e)
                                     ,x,y,h,w)))
    {
        f=f->sig;
    }
    int colision=(f->sig!=NULL);
    if (colision)
    {
        Flota aux=f->sig;
        f->sig=f->sig->sig;
        EnemigoLibera(aux->e);
        free(aux);
    }

    return colision;
}
