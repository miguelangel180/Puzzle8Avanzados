#include <stdio.h>
#include <stdlib.h>
#ifndef STRUCT_H
#define STRUCT_H
#include "structs.h"
#endif/*

#include "Puzzle.h"
*/

int currentPositionX(puzzle* P){

  for(int i =0; i<SIZE_PUZZLE;i++){
    if(P->pzl[i] == 'X'){
	return i;
    }
  }
  return -1;
}

/* Funcion booleana que detecta si una estructura puzzle contiene el mismo
arreglo que otra estructura */

int equalsPuzzle(char* pzl, char* pzl2){

  for (int i = 0; i < SIZE_PUZZLE; i++) {
    if (pzl[i] != pzl2[i]) {
      return FALSE;
    }
  }
  return TRUE;
}



/* ¿X se puede mover hacia arriba? se podra mover si no esta en
 las posiciones [0,1,2] o si:

   sea i = posicion de 'X' en el arreglo
   Si i-3 >= 0
*/

int canXUp(puzzle* puzzle){

  int currentX = currentPositionX(puzzle);
  if((currentX -3) >= 0){
    return TRUE;
  }
  else{

    return FALSE;
  }

}

void moveXUp(puzzle* puzzle){
  int currentX = currentPositionX(puzzle);
  char aux = puzzle->pzl[currentX-3];
  puzzle->pzl[currentX] = aux;
  puzzle->pzl[currentX-3] = 'X';
  puzzle->moves++;


}



/* ¿X se puede mover hacia abajo? se podra mover si no esta en
 las posiciones [6,7,8] o si:

   sea i = posicion de 'X' en el arreglo
   Si i+3 <= 8
*/


int canXDown(puzzle* puzzle){

  int currentX = currentPositionX(puzzle);
  if((currentX + 3) <= 8){
    return TRUE;
  }
  else{

    return FALSE;
  }

}


void moveXdown(puzzle* puzzle){
  int currentX = currentPositionX(puzzle);
  char aux = puzzle->pzl[currentX+3];
  puzzle->pzl[currentX] = aux;
  puzzle->pzl[currentX+3] = 'X';
  puzzle->moves++;

}

/* ¿X se puede mover hacia la derecha? se podra mover si no esta en
 las posiciones [2,5,8] o si:

   sea i = posicion de 'X' en el arreglo
   Si (i+1) % 3 != 0
*/


int canXrigth(puzzle* puzzle){

  int currentX = currentPositionX(puzzle);
  if(((currentX + 1) % 3) != 0){
    return TRUE;
  }
  else{

    return FALSE;
  }

}

void moveXrigth(puzzle* puzzle){
  int currentX = currentPositionX(puzzle);
  char aux = puzzle->pzl[currentX+1];
  puzzle->pzl[currentX] = aux;
  puzzle->pzl[currentX+1] = 'X';
  puzzle->moves++;

}

/* ¿X se puede mover hacia la izquierda? se podra mover si no esta en
 las posiciones [0,3,6] o si:

   sea i = posicion de 'X' en el arreglo
   Si i % 3 != 0
*/

int canXleft(puzzle* puzzle){

  int currentX = currentPositionX(puzzle);
  if((currentX % 3) != 0){
    return TRUE;
  }
  else

    return FALSE;
  }



void moveXleft(puzzle* puzzle){
  int currentX = currentPositionX(puzzle);
  char aux = puzzle->pzl[currentX-1];
  puzzle->pzl[currentX] = aux;
  puzzle->pzl[currentX-1] = 'X';
  puzzle->moves++;

}
