#include <stdlib.h>
#include "points.c" //we can make a header file later...

typedef struct _point_list_t_ {
  point* p;
 struct _point_list_t_* next;
} point_list_t;

typedef struct _hash_table_t_ {
  int size; //table size
  point_list_t** table;
} hash_table_t;


hash_table_t* create_hash_table(int size) {
  hash_table_t* new_table;

  if(size < 1)
    return NULL; //size needs to be positive.

  if((new_table = malloc(sizeof(hash_table_t))) == NULL)
    return NULL;

  /* Attempt to allocate memory for the table itself */
  if ((new_table->table = malloc(sizeof(point_list_t *) * size)) == NULL) {
    return NULL;
  }


  int i;
  //initialize table
  for(i = 0; i < size; i++) {
    new_table->table[i] = NULL;
    
    new_table->size = size;
    
    return new_table;
  }
}

//bijective algorithm that returns unique value from 2 numbers.
int hashCode(point* p, hash_table_t* ht){
  int tmp = ( p->y +  ((p->x + 1)/2));
  return (p->x +  ( tmp * tmp)) % ht->size;
}

point_list_t *lookup_point(hash_table_t *ht, point* p)
{
  point_list_t *list;
  unsigned int hashval = hashCode(p, ht);

  /* Go to the correct list based on the hash value and see if p is
   * in the list.  If it is, return return a pointer to the list element.
   * If it isn't, the item isn't in the table, so return NULL.
   */
  for(list = ht->table[hashval]; list != NULL; list = list->next) {
    if (equal(p, list->p)) return list;
  }
  return NULL;
}


  int add_point(hash_table_t* ht, point* p) {
  point_list_t* new_list;
  point_list_t* curr_list;

  unsigned int hashval = hashCode(p, ht);
  printf("hashval: %d\n", hashval);  
  /* Attempt to allocate memory for list */
  if ((new_list = malloc(sizeof(point_list_t))) == NULL) return 0;

  /* Does item already exist? */
  curr_list = lookup_point(ht, p);
  /* item already exists; we won't insert it again. */
  
  if (curr_list != NULL){
    printf("Point already in list\n");
    return 2;
  }
  printf("made it to insertion time\n");
  /* Insert into list */
  //make a copy
  point* p_copy = malloc(sizeof(point*));
  p_copy->x = p->x;
  p_copy->y = p->y;
  
  new_list->p = p_copy;
  new_list->next = ht->table[hashval];
  ht->table[hashval] = new_list;
  
  
  return 1;
  }


ht_n_entries(hash_table_t* ht) {
  int count = 0;
  int i;
  for(i = 0; i < ht->size; i++) {
    if(ht->table[i] != NULL) {
      count++;
      point_list_t*curr = ht->table[i];
      curr=curr->next;
      while(curr != NULL) {
	count++;
	curr=curr->next;
      }
    }
  }
  return count;
}
