
#include <stdio.h>
#include <stdlib.h>
#ifndef STRUCT_H
#define STRUCT_H
#include "structs.h"
#endif
#include "Puzzle.h"
#include "visit.h"
#include "result.h"
/*
#include "tools.h"

#include "Puzzle.h"
#include "result.h"
*/

char ideal[9] = {'1','2','3','4','5','6','7','8','X'};


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


void iterativo(list* cola,visit* visit,result* result){


  double x =0;

  while(/*cola->first != NULL*/ x <= 500)
  {
    puzzle* aux = cola->first;

    #ifdef DEBUG
    printf("iteracion = %f\n",x );
    printf("cantidad de visitados : %i\n",getCountVisit(visit));
    printf("puzzle actual = \n" );
    imprimir(aux);
    printf("cantidad de movimientos actual : %i\n",aux->moves );
    #endif
      char* aux_plz = aux->pzl;
      char* copy = (char*)malloc(sizeof(char)*SIZE_PUZZLE);
      for (int i = 0; i < SIZE_PUZZLE; i++) {
        copy[i] = aux_plz[i];
      }
      addPzlvisit(visit,copy);

    if(canXUp(aux) == TRUE){

      puzzle* b = (puzzle*)malloc(sizeof(puzzle));
      char* h = (char*)malloc(sizeof(char)*SIZE_PUZZLE);
      for (int i = 0; i < SIZE_PUZZLE; i++) {
        h[i] = aux_plz[i];
      }
      b->pzl = h;
      b->moves=aux->moves;
      b->next = NULL;
      moveXUp(b);
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

    cola->first=aux->next;
    free(aux->pzl);
    free(aux);
    x++;
  }
}
