#include <stdio.h>
#include <stdlib.h>
#ifndef STRUCT_H
#define STRUCT_H
#include "structs.h"
#endif
#include "Puzzle.h"
/*#include "structs.h"
#include "visit.h"
*/
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

int getCountVisit(visit* vis){

  visit* aux = vis;
  while (aux->next != NULL) {
      aux = aux->next;
    }
    return aux->count;
}



/* funcion booleana que detecta si dentro de toda la cola existe un puzzle
igual a otro */

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



void freeVisit(visit* current){

  while(current->next != NULL){
    visit* aux=current->next;
    free(aux->puzle);
    current->next = aux->next;
    free(aux);
  }
}
