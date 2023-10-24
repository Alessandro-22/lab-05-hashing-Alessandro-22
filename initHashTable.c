void initHashTable(HashTable *ht, int (*hashFunc)(int, int), int n) {
  ht->hashFunc = hashFunc;
  ht->n = n;
  for (int i = 0; i < BUCKET_SIZE; i++) {
    ht->bucket[i] = NULL;
  }
}
