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

_cell* hashPut(char*,_table*);

_cell* hashUpdate(char*,void*,_table*);

_cell* hashSet(char*,void*,_table*);

_cell* hashGetCell(char*,_table*);

void* hashGet(char*,_table*);

#endif