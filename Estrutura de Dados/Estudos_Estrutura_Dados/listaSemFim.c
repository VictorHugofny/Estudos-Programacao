void inserirFim(Lista *lista, int item) {
  Elemento *no = criarNo();
  no->item = item;
  no->proximo = NULL;
  if (ehVazio(lista->inicio))
    lista->inicio = no;
  else {
    Elemento *aux = lista->inicio;
    while (!ehVazio(aux->proximo)) aux = aux->proximo;
    aux->proximo = no;
  }
}

//da pra usar esse de base para inserir no meio, depois de um determinado valor, tipo maior que 10