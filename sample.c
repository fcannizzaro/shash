#include <stdio.h>
#include "hash.h"

typedef struct sample{
	int count;
	char* str;	
} sample;

int main(){

	_table * table = newHash(101);

	// put key
	hashPut("username",table);

	// update value
	hashUpdate("username","fcannizzaro",table);

	// get
	char* username = (char*) hashGet("username",table);

	printf(" >> Username is %s", username);

}