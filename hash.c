#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "hash.h"

// Create Hash table creation
_table* newHashScope(int size,int scope){

	_table * tab = malloc(sizeof(_table));
	tab->array = calloc(size,sizeof(_cell*));
	tab->size = size;
	tab->scope = scope;

	if(!(size % 2))
		printf(" > Warning: Use a Prime Number!");

	return tab;

}

// Create a New Hash Table
_table* newHash(int size){
	return newHashScope(size,-1);
}

// Hash function
unsigned int hashcode(char * key, _table* tab){

	unsigned int h = 0;

	while(*key != '\0')
		h = (127 * h + *key++) % tab->size;

	return h;

}

// Get Hash Cell
_cell* hashGetCell(char* key,_table* tab){

	_cell* ptr = tab->array[hashcode(key,tab)];

	while(ptr)

		if(!strcmp(ptr->key,key))
			return ptr;
		else
			ptr = ptr->next;
	
	return NULL;

}

// Put Hash Cell
void hashPut(char* key,_table* tab){

	int hash = hashcode(key,tab);

	_cell* found = hashGetCell(key,tab);

	if(found)
		return;

	// if not found
	
	_cell * new = malloc(sizeof(_cell));
	new->key = key;
	new->next = tab->array[hash];
	tab->array[hash] = new;

}

// Update Hash Cell
void hashUpdate(char* key,void* value,_table* tab){	

	_cell * cell = hashGetCell(key,tab);

	if(cell)
		cell->value = value;
	else
		printf(" >> Cannot updated. [Key not found]");

}

// Get Hash Element
// Get a value by key
void* hashGet(char* key,_table* tab){
	_cell* ptr = hashGetCell(key,tab);
	return ptr ? ptr->value : NULL;
}