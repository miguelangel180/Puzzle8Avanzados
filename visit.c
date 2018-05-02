#include <stdio.h>
#include <stdlib.h>
#ifndef STRUCT_H
#define STRUCT_H
#include "structs.h"
#endif
#include "Puzzle.h"

//se agrega un nuevo puzzle a la lista de visitados
void addPzlvisit(visit* current, char* pzl){


  if (current->count == 0) {
    current->puzle=pzl;
    current->count=1;
    current->next=NULL;

    #ifdef DEBUG

     printf("***La lista no tiene elementos = Cola vacia***\n");

    #endif

  }
  else{

    #ifdef DEBUG

    printf("***La lista de visitas tiene elementos***\n");


    #endif
    visit* aux = current;

    while (aux->next != NULL) {
      aux = aux->next;
    }
    visit* new = (visit*)malloc(sizeof(visit));
    new->puzle = pzl;
    new->count = aux->count+1;
    new->next = NULL;

    aux->next = new;

  }
}
// se obtiene la cantidad de puzzles visitados que tiene la lista

int getCountVisit(visit* vis){

  visit* aux = vis;
  while (aux->next != NULL) {
      aux = aux->next;
    }
    return aux->count;
}




//funcion que dice si un puzzle esta dentro de la lista de visitados
int wasVisited(visit* currentLP, char* pzl){

  visit* aux = currentLP;

  while(aux != NULL){

    if (equalsPuzzle(aux->puzle, pzl) == TRUE) {
       return TRUE;
    }
    aux = aux->next;
  }
  return FALSE;
}


//se libera la lista de puzzles visitados
void freeVisit(visit* current){

  while(current->next != NULL){
    visit* aux=current->next;
    free(aux->puzle);
    current->next = aux->next;
    free(aux);
  }
}
