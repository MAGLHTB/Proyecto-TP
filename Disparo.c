#include "Disparo.h"
#include <stdlib.h>
#include "Colision.h"
#include "Pantalla.h"
#include "Bala.h"
struct DisparoRep
{
    Bala b;
    Disparo sig;

};

Disparo DisparoCrea()
{

    Disparo d = malloc(sizeof(struct DisparoRep));
    d->sig=NULL;
    return d;
};

void DisparoLibera(Disparo d)
{
    while(d->sig!=NULL)
    {

        Disparo aux=d->sig;
        d->sig=d->sig->sig;
        BalaLibera(aux->b);
        free(aux);
    }
    free(d);
}

void DisparoMueve(Disparo d)
{
    while(d->sig!=NULL)
    {
        if(BalaMueve(d->sig->b))
        {
            Disparo aux=d->sig;
            d->sig = d->sig->sig;
            BalaLibera(aux->b);
            free(aux);
        }
        else d=d->sig;
    }
}

void DisparoDibuja(Disparo d)
{
    for (; d->sig!=NULL; d=d->sig)
    {
        BalaDibuja(d->sig->b);
    }

}
void DisparoInsertaNuevaBala(Disparo d,Bala bala)
{
    Disparo aux=malloc(sizeof(struct DisparoRep));
    aux->b=bala;
    aux->sig = d->sig;
    d->sig=aux;
}

int DisparoColision(Disparo d,int x,int y,int w,int h)
{
    while((d->sig!=NULL)&&(!Colision(BalaGetX(d->sig->b)
                                     ,BalaGetY(d->sig->b)
                                     ,BalaGetH(d->sig->b)
                                     ,BalaGetW(d->sig->b)
                                     ,x,y,h,w)))
    {
        d=d->sig;
    }
    int colision=(d->sig!=NULL);
    if (colision)
    {
        Disparo aux=d->sig;
        d->sig=d->sig->sig;
        BalaLibera(aux->b);
        free(aux);
    }

    return colision;
}
int DisparoColisionFlota(Disparo d,Flota f)
{
    while((d->sig!=NULL)&&(!FlotaColision(f,BalaGetX(d->sig->b)
                                     ,BalaGetY(d->sig->b)
                                     ,BalaGetH(d->sig->b)
                                     ,BalaGetW(d->sig->b)
                                        )))
    {
        d=d->sig;
    }
    int colision=(d->sig!=NULL);
    if (colision)
    {
        Disparo aux=d->sig;
        d->sig=d->sig->sig;
        BalaLibera(aux->b);
        free(aux);
    }

    return colision;
}

