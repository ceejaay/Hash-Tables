#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/****
  Basic hash table key/value pair
 ****/
typedef struct Pair {
  char *key;
  char *value;
} Pair;

/****
  Basic hash table
 ****/
typedef struct BasicHashTable {
  int capacity;
  Pair **storage;
} BasicHashTable;

/****
  Create a key/value pair to be stored in the hash table.
 ****/
Pair *create_pair(char *key, char *value)
{
  Pair *pair = malloc(sizeof(Pair));
  pair->key = strdup(key);
  pair->value = strdup(value);

  return pair;
}

/****
  Use this function to safely destroy a hashtable pair.
 ****/
void destroy_pair(Pair *pair)
{
  if (pair != NULL) {
    free(pair->key);
    free(pair->value);
    free(pair);
  }
}

/****
  djb2 hash function

  Do not modify this!
 ****/
unsigned int hash(char *str, int max)
{
  unsigned long hash = 5381;
  int c;
  unsigned char * u_str = (unsigned char *)str;

  while ((c = *u_str++)) {
    hash = ((hash << 5) + hash) + c;
  }

  return hash % max;
}


/****
  Fill this in.

  All values in storage should be initialized to NULL
  (hint: look up `calloc`)
 ****/
BasicHashTable *create_hash_table(int capacity)
{
  BasicHashTable *ht;
  ht->capacity = capacity;
  ht->storage = calloc(capacity, sizeof(char *));
  return ht;
}

/****
  Fill this in.

  If you are overwriting a value with a different key, print a warning.

  Don't forget to free any malloc'ed memory!
 ****/
void hash_table_insert(BasicHashTable *ht, char *key, char *value)
{

  int hashed = hash(key, ht->capacity);

  if(ht-storage[hashed] == '\0')
  {
    ht->storage[hashed] = value
  } else {
    printf("You are overwriting another value\n");
    ht->storage[hashed] = value
  }
  /* printf("value at hashed key %s\n", ht->storage[hashed]); */
  /* printf("ht capacity: %d", ht->capacity); */
  /* int hashed = hash(key, 10); */
  /* unsigned int hashed = hash(key, ht->capacity); */
  /* printf("hashed key: %i\n", hashed); */
}

/****
  Fill this in.

  Don't forget to free any malloc'ed memory!
 ****/
void hash_table_remove(BasicHashTable *ht, char *key)
{

}

/****
  Fill this in.

  Should return NULL if the key is not found.
 ****/
char *hash_table_retrieve(BasicHashTable *ht, char *key)
{
  int hashed_key = hash(key, ht->capacity);
  return ht->storage[hashed_key];

  /* return NULL; */
}

/****
  Fill this in.

  Don't forget to free any malloc'ed memory!
 ****/
void destroy_hash_table(BasicHashTable *ht)
{

}


#ifndef TESTING
int main(void)
{
  /* printf("hashed string %d\n", hash("hello world", 10)); */

  struct BasicHashTable *ht = create_hash_table(16);
  /* printf("capacity %d\n", ht->capacity); */
  /* ht->storage[1] = "hello"; */
  /* printf("storage %s\n", ht->storage[1]); */

  hash_table_insert(ht, "line", "Here today...\n");
  printf(" out of the hash table => %s", hash_table_retrieve(ht, "line"));

  hash_table_remove(ht, "line");

  if (hash_table_retrieve(ht, "line") == NULL) {
    printf("...gone tomorrow. (success)\n");
  } else {
    fprintf(stderr, "ERROR: STILL HERE\n");
  }

  destroy_hash_table(ht);

  return 0;
}
#endif
