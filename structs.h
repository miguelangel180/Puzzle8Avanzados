#ifndef SIZE_PUZZLE
#define SIZE_PUZZLE 9
#endif
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif



//estructura puzzle, guarda un puzzle como char* y los movimientos de este puzzle

typedef struct nodo{
  char* pzl;
  int moves;
  struct nodo* next;
}puzzle;

//estructura que guarda siempre el primer nodo de puzzle, tambien funciona como cola
typedef struct{
  puzzle* first;
  int count;
}list;

//estructura que almacena los movimientos cuando encuentra un resultado
typedef struct enlace
{
  int movs;
  int count;
  struct enlace* next;

}result;

//estructura que almacena los puzzles visitados
typedef struct vist
{
  char* puzle;
  int count;
  struct vist* next;

}visit;
