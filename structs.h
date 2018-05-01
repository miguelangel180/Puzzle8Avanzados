#ifndef SIZE_PUZZLE
#define SIZE_PUZZLE 9
#endif
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif




typedef struct nodo{
  char* pzl;
  int moves;
  struct nodo* next;
}puzzle;

typedef struct{
  puzzle* first;
  int count;
}list;

typedef struct enlace
{
  int movs;
  int count;
  struct enlace* next;

}result;

typedef struct vist
{
  char* puzle;
  int count;
  struct vist* next;

}visit;
