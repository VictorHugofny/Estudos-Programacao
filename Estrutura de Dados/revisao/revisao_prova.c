void restaUm(Controle *p) {
    Elemento *noProx = (Elemento *)malloc(sizeof(Elemento));
    noProx = p->topo;
    if(noProx->proximo){
        desempilhar(&p, p->topo);
        restaUm(&p, p->topo);
    }else{
        printf("\n Parou de desempilhar o valor atual e %d", noProx->valor);
    }  
}

void retirarElemento(int val){
    int temp1, temp2;

    while(p1.topo){
        temp1 = desempilhar(p1, p1->topo);
        if(temp1 != val){
            empilhar(&p2, temp1);
        }
    }

    while(p2.topo){
        temp2 = desempilhar(p2, p2->topo);
        empilhar(&p1, temp2);
    }
}

void compararPilhas(Controle *p, Controle *p2){
    int validacao = 0;

    while (p->topo) {
      Elemento *e = desempilhar(p, p->topo);
      Elemento *e2 = desempilhar(p2, p2->topo);
      
      if(e->valor != e2->valor){
        validacao = 1;
      }
    }

    if(validacao == 1){
      printf("Pilhas diferentes");
    }else{
      printf("pilhas iguais");
    }
}

void comparaPilhas(Elemento *e1, Elemento *e2){
    if(e1 && e2){
        if(e1->valor == e2->valor){
            comparaPilhas(e1->proximo, e2->proximo);
        }else if(!e1 && !e2){
            printf("\n Pilhas iguais");
        }else{
            printf("\n Pilhas diferentes \n \n");
        }
    }
}//fim