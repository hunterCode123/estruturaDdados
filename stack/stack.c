#include <stdio.h>
#include <stdlib.h>

typedef struct No {

    int dado;
    struct No* prox;

}No;

No* criarNo(int valor){

        No* novoNo = (No*)malloc(sizeof(No));
        if(novoNo){
            novoNo->dado = valor;
            novoNo->prox = NULL;
            return novoNo;
        }
        else{
            printf("erro ao alocar memoria!\n");
            exit(1);
        }
}

void inserirPush(No** topo, int valor){

    No* novoNo = criarNo(valor);
    novoNo->prox = *topo;
    *topo = novoNo;
    printf("elemento %d insrido na pilha.\n", valor);

}

int removerPop(No** topo){

    if(*topo){
        No* temp = *topo;
        int valor = temp->dado;
        *topo = temp->prox;
        free(temp);
        return valor;
    }
    else {
        printf("pilha vazia, nada a ser removido!\n");
        return -1;
    }
}

int vazia(No* topo){
    return topo == NULL;
}


void imprimirPilha(No* topo){
    if(topo){
        while(topo){
            printf("\n%d",topo->dado);
            topo = topo->prox;
            printf("\n");
        }
    }
    else{
        printf("Pilha esta vazia.\n");
        return;
    }
}

void pilhaLivre(No** topo){
    while(!vazia(*topo)){
        removerPop(topo);
    }
}

int main(){
    No* pilha = NULL;
    int op;
   do {

        printf("1-inserir\n2-remover\n3-imprimir");
        scanf("%d",&op);
        getchar();

        if(op==1){
            int valor;
            printf("\nescolha um valor para ser adicionado:");
            scanf("%d",&valor);
            inserirPush(&pilha,valor);
        }
        else if(op==2){
            removerPop(&pilha);
        }
        else if(op==3){
            imprimirPilha(pilha);
        }
        else{
            printf("\noperacao invalida tente novamente!\n");
        }
   }while(op!=0);

   pilhaLivre(pilha);
   return 0;

}