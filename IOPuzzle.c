#include <stdio.h>
#include <stdlib.h>
#ifndef STRUCT_H
#define STRUCT_H
#include "structs.h"
#endif
/*

#include "IOPuzzle.h"
*/
puzzle* readFile(char* rute){
  char* puzzleList = (char*)malloc(sizeof(char)*SIZE_PUZZLE);
  FILE* fichero = fopen(rute,"r");



  if (fichero) {
    #ifdef DEBUG
    printf("Fichero abierto correctamente\n");
    #endif

    int i = 0;
    while (!feof(fichero)){
      fscanf(fichero,"%c",&puzzleList[i]);
      if (puzzleList[i]!= ' ' && puzzleList[i]!= '\n') {
         i++;
      }

    }
    #ifdef DEBUG //Sentencia de DEBUG
    for (i = 0; i < SIZE_PUZZLE; i++) {
      printf(" posicion %i , caracter: %c\n",i,puzzleList[i]);
    }
    #endif
    fclose(fichero);
    puzzle* tablero = (puzzle*)malloc(sizeof(puzzle));
    tablero->pzl = puzzleList;
    tablero->moves = 0;
    tablero->next =NULL;
    return tablero;
  }
  else
   {

    printf("No se pudo abrir el archivo\n");
    printf("revise que la ruta o nombre del archivo sea correcto...\n");
    return NULL;
  }


}




void writeFile(int movimientos){

  FILE* fichero = fopen("salida.txt","w");

  if (fichero) {
    #ifdef DEBUG
    printf("Fichero abierto correctamente\n");
    #endif
    fprintf(fichero, "La cantidad de movimientos minimos para resolver el puzzle es : %i\n",movimientos);
    fclose(fichero);
  }
  else
   {

    printf("No se pudo abrir el archivo\n");
    printf("revise que no exista un archivo con el mismo nombre -> 'Salida.txt'\n");
  }


}
