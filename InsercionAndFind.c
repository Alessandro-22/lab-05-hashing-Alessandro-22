// Inserción de un valor x en la tabla hash.
void insert(HashTable *ht, int x) {
  int index = ht->hashFunc(x, ht->n);
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = x;
  newNode->next = ht->bucket[index];
  ht->bucket[index] = newNode;
}

// Búsqueda de un valor x en la tabla hash.
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
