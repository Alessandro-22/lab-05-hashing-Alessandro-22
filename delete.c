void delete(HashTable *ht, int x) {
  // Calcula el índice en el que debería estar el valor x utilizando la función hash.
  int index = ht->hashFunc(x, ht->n);

  // Inicializa dos punteros: current y prev para recorrer la lista enlazada en el índice.
  Node *current = ht->bucket[index];
  Node *prev = NULL;

  // Recorre la lista enlazada buscando el valor x.
  while (current) {
    // Comprueba si el valor del nodo actual coincide con x.
    if (current->data == x) {
      // Si prev no es nulo, significa que no estamos al principio de la lista,
      // entonces actualizamos el puntero "next" del nodo anterior para omitir el nodo actual.
      if (prev) {
        prev->next = current->next;
      } else {
        // Si prev es nulo, estamos eliminando el primer nodo en la lista,
        // entonces actualizamos el puntero en el bucket directamente.
        ht->bucket[index] = current->next;
      }
      
      // Liberamos la memoria del nodo que contiene el valor x.
      free(current);
      return; // Salimos de la función después de eliminar el valor.
    }
    
    // Actualizamos los punteros prev y current para avanzar en la lista.
    prev = current;
    current = current->next;
  }
}

