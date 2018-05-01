#include <stdio.h>
#include <stdlib.h>
#ifndef STRUCT_H
#define STRUCT_H
#include "structs.h"
#endif
#include "Puzzle.h"
#include "tools.h"
#include "result.h"
#include "visit.h"
#include "IOPuzzle.h"




int main(int argc, char const *argv[]) {

  #ifdef DEBUG
  printf("¡¡¡¡ MODO DEBUG ACTIVADO !!!! \n");
  printf("*******************************\n");
  #endif
  puzzle* actual = readFile("puzzle.txt");
  list* cola_actual = (list*)malloc(sizeof(list));
  cola_actual->first = NULL;
  cola_actual->count = 0;
  visit* visitados =  (visit*)malloc(sizeof(visit));
  visitados->count=0;
  result* resultados = (result*)malloc(sizeof(result));
  resultados->count=0;
  encolar(cola_actual,actual);
  iterativo(cola_actual,visitados,resultados);
  int moves = getMinMoves(resultados);
  #ifdef DEBUG
  printf("la cantidad minima para resolver el puzzle es : %i\n",moves);
  printf("la cantidad de puzzles visitados es : %i\n",getCountVisit(visitados));
  #endif
  printf("********************************\n");
  printf("* Programa terminado con exito *\n");
  printf("********************************\n");
  printf("\n\n\n");
  printf("* Revisar archivo de salida -> 'salida.txt' *\n");

  freeVisit(visitados);
  freeResult(resultados);
  writeFile(moves);

  return 0;
}
