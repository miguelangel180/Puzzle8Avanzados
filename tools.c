
#include <stdio.h>
#include <stdlib.h>
#ifndef STRUCT_H
#define STRUCT_H
#include "structs.h"
#endif
#include "Puzzle.h"
#include "visit.h"
#include "result.h"

/* se define el puzzle ideal o resultado como el siguiente

         [1,2,3,4,5,6,7,8,X]  =   1  2  3
                                  4  5  6
                                  7  8  X

*/
char ideal[9] = {'1','2','3','4','5','6','7','8','X'};

//Imprime un puzzle --- Se activa solo con modo DEBUG
void imprimir(puzzle* pzl){
  int y = 0;
  for (int i = 0; i < SIZE_PUZZLE; i++) {
    if (y == 3) {
      printf("\n" );
      y=0;
    }
    printf("%c ",pzl->pzl[i]);
    y++;
  }
  printf("\n");

}

//utiliza una lista como cola y almacena siempre al final una nueva estructura puzzle
void encolar(list* currentC, puzzle* new){

  if (currentC->first == NULL) {
    currentC->first = new;
    currentC->count = 1;

    #ifdef DEBUG

     printf("***La cola no tiene elementos = Cola vacia***\n");

    #endif

  }
  else{

    #ifdef DEBUG

     printf("***La cola tiene elementos = Cola NO vacia***\n");

    #endif
    puzzle* aux = currentC->first;

    while (aux->next != NULL) {
      aux = aux->next;
    }
    aux->next = new;
    currentC->count++;

  }

}

/* funcion principal del Programa

Esta funcion desencola un puzzle de una cola y genera todos los posibles
movimientos que pueda tener ese puzzle

Los movimientos estan dados por la X, es decir, si X se puede mover entre:
            [arriba,abajo,izquierda,derecha]

si se puede mover en alguno de estos, se genera un nuevo puzzle el cual se
consulta si ya ha sido visitado, en el caso de que el puzzle ya haya sido visitado
se libera la memoria pedida para almacenar ese puzzle.

En el caso de que no haya sido visitado, se encola a la cola actual para luego
repetir el proceso.

Si un puzzle no se puede encolar ya que han sido visitados todos sus movimientos
se libera la memoria de ese puzzle y se continua con el siguiente de la cola.


*/
void iterativo(list* cola,visit* visit,result* result){


  double x =0;

  while(cola->first != NULL /*x <= 500*/) //como el programa tarda, se prueba con un numero x < 500
  {
    puzzle* aux = cola->first;

    #ifdef DEBUG
    printf("iteracion = %f\n",x );
    printf("cantidad de visitados : %i\n",getCountVisit(visit));
    printf("puzzle actual = \n" );
    imprimir(aux);
    printf("cantidad de movimientos actual : %i\n",aux->moves );
    #endif

    //se hace una copia del puzzle actual para no modificarlo
      char* aux_plz = aux->pzl;
      char* copy = (char*)malloc(sizeof(char)*SIZE_PUZZLE);
      for (int i = 0; i < SIZE_PUZZLE; i++) {
        copy[i] = aux_plz[i];
      }
      //se agrega el puzzle actual a la lista de visitados
      addPzlvisit(visit,copy);

      //se pregunta si X se puede mover hacia arriba
    if(canXUp(aux) == TRUE){

      //se genera un nuevo puzzle (copia a nivel de estructura)
      puzzle* b = (puzzle*)malloc(sizeof(puzzle));
      char* h = (char*)malloc(sizeof(char)*SIZE_PUZZLE);
      for (int i = 0; i < SIZE_PUZZLE; i++) {
        h[i] = aux_plz[i];
      }
      b->pzl = h;
      b->moves=aux->moves;
      b->next = NULL;
      moveXUp(b); //se mueve X en la copia del puzzle
      // se pregunta si es el puzzle ideal o resultado
      if (equalsPuzzle(b->pzl,ideal)== TRUE) {
        #ifdef DEBUG
        printf("encontre el puzzle ideal = \n" );
        imprimir(b);
        printf("cantidad de movimientos actual : %i\n",b->moves );
        #endif
        //se agrega los movimientos del puzzle actual a la lista de resultados
        addPzlresult(result,b->moves);

      }
      //se pregunta si el puzzle copia con X movido ha sido visitado
      if (wasVisited(visit,h)== FALSE) {
        //sino: se encola
        encolar(cola,b);
      }
      else{
        /*en caso de que ya haya sido visitado, se libera la memoria
        que antes se habia pedido*/

        free(h);
        free(b);
      }


    }
    if(canXDown(aux) == TRUE){
      puzzle* b = (puzzle*)malloc(sizeof(puzzle));
      char* h = (char*)malloc(sizeof(char)*SIZE_PUZZLE);
      for (int i = 0; i < SIZE_PUZZLE; i++) {
        h[i] = aux_plz[i];
      }
      b->pzl = h;
      b->moves=aux->moves;
      b->next = NULL;
      moveXdown(b);
      if (equalsPuzzle(b->pzl,ideal)== TRUE) {
        #ifdef DEBUG
        printf("encontre el puzzle ideal = \n" );
        imprimir(b);
        printf("cantidad de movimientos actual : %i\n",b->moves );
        #endif
        addPzlresult(result,b->moves);

      }
      if (wasVisited(visit,h)== FALSE) {
        encolar(cola,b);
      }
      else{


        free(h);
        free(b);
      }

    }
    if(canXrigth(aux) == TRUE){

      puzzle* b = (puzzle*)malloc(sizeof(puzzle));
      char* h = (char*)malloc(sizeof(char)*SIZE_PUZZLE);
      for (int i = 0; i < SIZE_PUZZLE; i++) {
        h[i] = aux_plz[i];
      }
      b->pzl = h;
      b->moves=aux->moves;
      b->next = NULL;
      moveXrigth(b);
      if (equalsPuzzle(b->pzl,ideal)== TRUE) {
        #ifdef DEBUG
        printf("encontre el puzzle ideal = \n" );
        imprimir(b);
        printf("cantidad de movimientos actual : %i\n",b->moves );
        #endif
        addPzlresult(result,b->moves);

      }
      if (wasVisited(visit,h)== FALSE) {
        encolar(cola,b);
      }
      else{


        free(h);
        free(b);
      }

    }
    if(canXleft(aux) == TRUE){

      puzzle* b = (puzzle*)malloc(sizeof(puzzle));
      char* h = (char*)malloc(sizeof(char)*SIZE_PUZZLE);
      for (int i = 0; i < SIZE_PUZZLE; i++) {
        h[i] = aux_plz[i];
      }
      b->pzl = h;
      b->moves=aux->moves;
      b->next = NULL;
      moveXleft(b);
      if (equalsPuzzle(b->pzl,ideal)== TRUE) {
        #ifdef DEBUG
        printf("encontre el puzzle ideal = \n" );
        imprimir(b);
        printf("cantidad de movimientos actual : %i\n",b->moves );
        #endif
        addPzlresult(result,b->moves);

      }
      if (wasVisited(visit,h)== FALSE) {
        encolar(cola,b);
      }
      else{


        free(h);
        free(b);
      }
    }

    //se sigue con el siguiente en la cola
    cola->first=aux->next;
    //se libera la memoria del puzzle actual
    free(aux->pzl);
    free(aux);
    x++; //aumenta X
  }
}
