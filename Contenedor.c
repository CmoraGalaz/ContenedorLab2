#include <stdio.h>
#include <stdlib.h>
#include "TDAcola.h"
#include "TDAembarque.h"
#include <time.h>

int embarcarProb(double probabilidad_embarque ){



    // Generar un número aleatorio entre 0 y RAND_MAX
    int aleatorio = rand();

    // Convertir el número aleatorio en un valor entre 0 y 1
    double resultado = (double)aleatorio / RAND_MAX;
    if(resultado <= probabilidad_embarque){
       
        return 1;
    }else{
     
    return 0;
    }
}

int main (){

srand(time(NULL));
printf("Laboratorio 2 : Inicio \n");
int duracion,inicio =0,tiempo_de_carga,count=0,cantidad_de_carga=1;
double probabilidad_embarque;

    printf(" Tiempo de duracion de la simulacion: ");
    scanf("%d", &duracion);
    printf("\n Probabilidad De Embarque: ");
    scanf("%lf", &probabilidad_embarque);
      printf("\n Tiempo De llegada De Carga: ");
    scanf("%d", &tiempo_de_carga);

    Cola cola;
    inicializarCola(&cola);
    ColaEmbarque colaEmbarque;
    inicializarColaEmbarque(&colaEmbarque);
    

while(inicio <= duracion){

     printf("\n Tiempo Transcurrido : %d",inicio);

     


 if(count==tiempo_de_carga){
    Carga nuevaCarga;
    nuevaCarga.tiempo_llegada = inicio;
    nuevaCarga.tiempo_atencion = cantidad_de_carga;
    agregarCarga(&cola,nuevaCarga);
    cantidad_de_carga++;
    count=0;}
    imprimirCola(&cola);
 

  
    if(embarcarProb(probabilidad_embarque)==1){
             
             if(esColaVacia(&cola)==0){  
                CargaEmbarque cargaEmbarcar;
                Nodo* nodo = frente(&cola);
                cargaEmbarcar.tiempoCarga= inicio;
                cargaEmbarcar.numeroCarga=nodo->carga.tiempo_atencion;

              agregarAlEmbarque(&colaEmbarque,cargaEmbarcar);
               descolar(&cola);
             }
                
               printf("/////////////////////////////EMBARQUE/////////////////////////////");
              }
    
       inicio++;
    count++;
   
}
imprimirCola(&cola);
//descolar(&cola);
  //Nodo* nodo = frente(&cola);
   //printf("Tiempo de llegada en el frente de la cola: %d\n", nodo->carga.tiempo_llegada);

  imprimirColaEmbarque(&colaEmbarque);
return 0;
}
