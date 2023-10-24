#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10


typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Estructura principal para la tabla hash.
typedef struct HashTable {
  int (*hashFunc)(int, int);
  int n;
  Node *bucket[BUCKET_SIZE];
} HashTable;

int miMod(int x, int n) { return x % n; }

void initHashTable(HashTable *ht, int (*hashFunc)(int, int), int n) {
  ht->hashFunc = hashFunc;
  ht->n = n;
  for (int i = 0; i < BUCKET_SIZE; i++) {
    ht->bucket[i] = NULL;
  }
}

void insert(HashTable *ht, int x) {
  int index = ht->hashFunc(x, ht->n);
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = x;
  newNode->next = ht->bucket[index];
  ht->bucket[index] = newNode;
}

bool find(HashTable *ht, int x) {
  int index = ht->hashFunc(x, ht->n);
  Node *temp = ht->bucket[index];
  while (temp) {
    if (temp->data == x) {
      return true;
    }
    temp = temp->next;
  }
  return false;
}

void delete (HashTable *ht, int x) {
  int index = ht->hashFunc(x, ht->n);
  Node *current = ht->bucket[index];
  Node *prev = NULL;

  while (current) {
    if (current->data == x) {
      if (prev) {
        prev->next = current->next;
      } else {
        ht->bucket[index] = current->next;
      }
      free(current);
      return;
    }
    prev = current;
    current = current->next;
  }
}

int main() {
  HashTable ht;
  initHashTable(&ht, miMod, 10);

  int x = 1234567;
  int y = 76554334234;
  insert(&ht, x);
  insert(&ht, y);

  int result = find(&ht, x);
  if (result != -1) {
    printf("El elemento %d se encontró en la tabla hash.\n", result);
  } else {
    printf("El elemento no se encontró en la tabla hash.\n");
  }

  delete (&ht, x);
  result = find(&ht, x);
  if (result != -1) {
    printf("El elemento %d se encontró en la tabla hash.\n", result);
  } else {
    printf("El elemento no se encontró en la tabla hash.\n");
  }

  return 0;
}
