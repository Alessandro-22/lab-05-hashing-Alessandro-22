// Definición de la estructura del nodo en la lista enlazada.
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Definición de la estructura principal de la tabla hash.
typedef struct HashTable {
  int (*hashFunc)(int, int);
  int n;
  Node *bucket[BUCKET_SIZE];
} HashTable;
