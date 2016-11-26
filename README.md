# shash
Simple C Hash Table Implementation

## Usage
```C

_table * table = newHash(101);

// put key
hashPut("username",table);

// update value
hashUpdate("username","fcannizzaro",table)

// get
char* username = (char*) hashGet("username",table);

printf(" >> Username is %s", username);

```

## Constructor

### _table* newHash(int size)
create Hash Struct

### _table* newHashScope(int size,int scope)
create Hash Struct with scope id

## Get

### \_cell* hashGetCell(_table* table, char\* key)
get cell by key

### void* hashGet(_table* table, char\* key)
get value by key

## Put

### void hashPut(char* key,_table** table)
put key

### void hashUpdate(char* key,void* value,_table* table)
update key with value

### void hashSet(char* key,void* value,_table** table)
create if not exist and update

## Size

### table->size
size of hash table