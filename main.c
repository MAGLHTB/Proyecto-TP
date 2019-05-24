#include "Pantalla.h"
#include "Galaxia.h"
#include "Colision.h"
#include "Astro.h"
#include "Enemigo.h"
#include "Personaje.h"
#include "FLOT.h"
#include "Disparo.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define WPANTALLA 640
#define HPANTALLA  480
#define WPERSONAJE 60
#define HPERSONAJE 60
#define VXPERSONAJE 8
#define VYPERSONAJE 8
#define VXENEMIGO   3
#define VYENEMIGO   3
#define NVIDAS  3
#define WENEMIGO    40
#define HENEMIGO    40
#define MAXASTROS   4
#define FRECASTROS  20
#define FRECENEMIGOS 40
#define maxpuntosextra 15
#define WBALA 20
#define HBALA 20
#define VBALA 10
#define maxrecarga 10

/**
    \mainpage main.c
    \brief Save the World in C es un proyecto de la asignatura de Tecnología de la Programación del grado de ingeniería informática
    <br/> Controles:
    <br/> &nbsp;&nbsp;&nbsp; Flecha arriba para moverte hacia arriba.
    <br/> &nbsp;&nbsp;&nbsp; Flecha abajo para moverte hacia abajo.
    <br/> &nbsp;&nbsp;&nbsp; Flecha derecha para moverte hacia derecha.
    <br/> &nbsp;&nbsp;&nbsp; Flecha izquierda para moverte hacia izquierda.
    <br/> &nbsp;&nbsp;&nbsp; Espacio para disparar (Necesitas balas para poder disparar ráfagas).
    <br/> Recoge Soles para recargar la ráfaga.
    <br/>Mata enemigos para recuperar vidas.
    <br/>Si tus vidas llegan a 0, has perdido.
    <br/>Recoge escudos, si tienes un escudo activo, no recibirás daños.
**/

FILE* f;

int main(int argc, char * argv[])
{

    int recarga = 0;
    int shield  = 0;
    Imagen img_escudo = Pantalla_ImagenLee("img_escudo.bmp",1);
    Imagen cabecera = Pantalla_ImagenLee("img_cabecera.bmp",0);
    Imagen Fondo = Pantalla_ImagenLee("fondo.bmp",0);
    Pantalla_ColorTrazo(255,255,255,255);
    Galaxia escudo = GalaxiaCrea(4);
    Galaxia g=GalaxiaCrea(MAXASTROS);
    int puntosextra=0;
    char texto_recarga[100] = "Disparo Activado";
    char texto1[100];
    char texto2[100];
    char texto[100];
    int t=time(NULL);
    int t1;
    int fin=0;
    Imagen aImagen = Pantalla_ImagenLee("aImagen.bmp",1);
    Pantalla_Crea("Inicio del juego", WPANTALLA,HPANTALLA);

    Pantalla_ColorTrazo(255,255,255,255);
    while (Pantalla_Activa()&&(!fin))
    {
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_RETURN))
            fin=1;
        Pantalla_DibujaImagen(cabecera,0,0,WPANTALLA,HPANTALLA);
        Pantalla_DibujaTexto("Save the World in C",20,80);
        Pantalla_DibujaTexto("Pulsa (RETURN)",20,50);
        Pantalla_Actualiza();
        Pantalla_Espera(10);
        srand(time(NULL));
    }
    fin = 0;
    while (Pantalla_Activa()&&(!fin))
    {
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_SPACE))
            fin = 1;
        Pantalla_DibujaImagen(cabecera,0,0,WPANTALLA,HPANTALLA);
        Pantalla_DibujaTexto("Pulsa las teclas de direccion para moverte", 20, 50);
        Pantalla_DibujaTexto("Pulsa la tecla espacio para disparar a los enemigos",20, 60);
        Pantalla_DibujaTexto("Destruye las naves enemigas para recuperar vidas",20, 70);
        Pantalla_DibujaTexto("Recoge soles para recargar tu disparo. Tienes una rafaga por cada sol que recoges",20, 80);
        Pantalla_DibujaTexto("Pulsa la tecla espacio para comenzar ",20, 90);
        Pantalla_Actualiza();
        Pantalla_Espera(10);

    }
    fin = 0;
    Imagen img_Disparo = Pantalla_ImagenLee("img_Disparo.bmp",1);
    Imagen eImagen=Pantalla_ImagenLee("eImagen.bmp",1);
    Imagen nave=Pantalla_ImagenLee("img_nave_pj.bmp",1);
    Personaje p=PersonajeCrea(nave,WPERSONAJE,HPERSONAJE,rand()%(WPANTALLA-WPERSONAJE),HPANTALLA-HPERSONAJE);
    Flota fl=FlotaCrea();
    Disparo d = DisparoCrea();
    int nvidas=3;
    if (fin == 0) printf("fin = 0");
    while (Pantalla_Activa()&& (!fin))
    {
        if (!(rand()%FRECENEMIGOS))
        {
            if (rand()%2)
                FlotaInsertaNuevoEnemigo(fl,EnemigoCrea(eImagen, WENEMIGO, HENEMIGO, rand()%(WPANTALLA-WENEMIGO), 0, VXENEMIGO, VYENEMIGO));
            else
                FlotaInsertaNuevoEnemigo(fl, EnemigoCrea(eImagen, WENEMIGO, HENEMIGO, rand()%(WPANTALLA-WENEMIGO), 0, -VXENEMIGO, VYENEMIGO));

        }
        if (rand()%FRECASTROS)
            GalaxiaInsertaNuevoAstro(g,AstroCrea(aImagen,40, 40, rand()%(WPANTALLA-40), rand()%(HPANTALLA-40)));

        if (!(rand()%FRECASTROS))
            GalaxiaInsertaNuevoAstro(escudo,AstroCrea(img_escudo,40,40, rand()%(WPANTALLA-40),rand()%(HPANTALLA-40)));

        if (Pantalla_TeclaPulsada(SDL_SCANCODE_ESCAPE) || (nvidas==0)) fin=1;
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_LEFT)) PersonajeMueve(p,-VXPERSONAJE,0);
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_RIGHT))PersonajeMueve(p,+VXPERSONAJE,0);
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_UP))PersonajeMueve(p,0,-VYPERSONAJE);
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_DOWN))PersonajeMueve(p,0,+VYPERSONAJE);
        Pantalla_DibujaImagen(Fondo,0,0,WPANTALLA,HPANTALLA);
        PersonajeDibuja(p);
        DisparoDibuja(d);
        GalaxiaDibuja(escudo);

        if (GalaxiaColision(escudo,PersonajeGetX(p),PersonajeGetY(p),PersonajeGetH(p),PersonajeGetW(p)))
            shield = 1;

        if (GalaxiaColision(g,PersonajeGetX(p),PersonajeGetY(p),PersonajeGetH(p),PersonajeGetW(p)))
            recarga = maxrecarga;
        //Disparos

        if (Pantalla_TeclaPulsada(SDL_SCANCODE_SPACE) && (recarga!=0))
        {
            DisparoInsertaNuevaBala(d,BalaCrea(img_Disparo,PersonajeGetX(p)+20,PersonajeGetY(p)+1,WBALA,HBALA,VBALA));
            recarga--;
        }

        DisparoMueve(d);
        if (DisparoColisionFlota(d,fl))
            if (nvidas != 3)
                nvidas++;

        FlotaMueve(fl);
        if (FlotaColision(fl,PersonajeGetX(p),PersonajeGetY(p),PersonajeGetW(p),PersonajeGetH(p)))
        {
            if ((shield == 0))
                nvidas--;
            shield  = 0;
        }
        FlotaDibuja(fl);
        GalaxiaDibuja(g);


        if (recarga == maxrecarga)
            Pantalla_DibujaTexto(texto_recarga,460, 80);
        else;
        if (shield == 1)
        {
            Pantalla_DibujaTexto("Escudo Activado", 460, 90);
        }
        t1=time(NULL);
        int puntos=t1-t+puntosextra;
        sprintf(texto,"%d",puntos);
        for (int i=1; i<=nvidas; i++)
            Pantalla_DibujaImagen(nave,WPANTALLA-WPERSONAJE/3*i,20,WPERSONAJE/3,HPERSONAJE/3);
        Pantalla_DibujaTexto(texto,20,60);
        Pantalla_DibujaTexto("TIME:",20,40);
        Pantalla_DibujaTexto("Pulsa ESC para salir",20,20);
        Pantalla_Actualiza();
        Pantalla_Espera(10);


        sprintf(texto1,"Puntos = %d",puntos);
        int puntosMax=0;
        int dato;
        FILE * f=fopen("record.txt","r");
        if (f!=NULL)
        {
            while (!feof(f))
            {

                fscanf(f,"%d",&dato);
                if(dato>puntosMax)
                    puntosMax=dato;
            }
            fclose(f);
        }
        if (puntos>puntosMax)
        {
            sprintf(texto2,"Nuevo record!!!");
        }
        else
            sprintf(texto2,"Record: %d",puntosMax);
        f=fopen("record.txt","a");
        fprintf(f,"%d\n",puntos);
        fclose(f);
    }
    fin = 0;
    GalaxiaLibera(escudo);
    GalaxiaLibera(g);
    DisparoLibera(d);
    FlotaLibera(fl);
    PersonajeLibera(p);

    while (Pantalla_Activa()&&(!fin))
    {
        Pantalla_DibujaImagen(Fondo,0,0,WPANTALLA,HPANTALLA);
        if (Pantalla_TeclaPulsada(SDL_SCANCODE_SPACE)) fin=1;
        Pantalla_DibujaTexto("Intentalo otra vez",20,20);
        Pantalla_DibujaTexto(texto1,20,40);
        Pantalla_DibujaTexto(texto2,20,60);
        Pantalla_DibujaTexto("Pulsa Espacio para salir del juego",20, 80);
        Pantalla_Actualiza();
        Pantalla_Espera(10);
    }

    Pantalla_Libera();
    return 0;
}
