#ifndef _HASH
#define _HASH

typedef struct _cell{
   char* key;
   void* value;
   struct _cell * next;
} _cell;

typedef struct{
   int size;
   int scope;
   _cell ** array;
} _table;

/* Constructor */

_table* newHashScope(int,int);

_table* newHash(int);

/* Put/Update/Get */

void hashPut(char*,_table*);

void hashUpdate(char*,void*,_table*);

void* hashGet(char*,_table*);

_cell* hashGetCell(char*,_table*);

#endif