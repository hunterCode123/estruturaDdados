#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct fila {
    int inicio, final, qtd;
    aluno dados[MAX];
};

Fila* criarFila(){
    Fila *fi;
    fi = (Fila*) malloc(sizeof(struct fila));
    if(fi != NULL){
       fi->inicio=0;
       fi->final=0;
       fi->qtd=0;
    }
    return fi;
}

void liberarFila(Fila* fi){
    if(fi !=NULL){
        free(fi);
    }
    fi = NULL;
}

int tamanhoFila(Fila* fi){
    if(fi != NULL){
        return fi->qtd;
    }
    else{
        return -1;
    }
}

int filaCheia(Fila* fi){
    if(fi == NULL){
        return -1;
    }
    if(fi->qtd==MAX){
        return 1;
    }
    else{
        return 0;
    }
}

int filaVazia(Fila* fi){
    if(fi == NULL){
        return -1;
    }
    if(fi->qtd==0){
        return 1;
    }
    else{
        return 0;
    }
}

int insereFila(Fila* fi, aluno al){
    if(fi == NULL){
        return 0;
    }
    if(fi->qtd==MAX){
        return 0;
    }
    fi->dados[fi->final] = al;
    fi->final = (fi->final+1) % MAX;
    fi->qtd++;
    return 1;
}

int removeFila(Fila* fi){
    if(fi == NULL || fi->qtd == 0)
        return 0;
    fi->inicio = (fi->inicio+1)%MAX;
    fi->qtd--;
    return 1;
}

int consultarFila(Fila* fi, aluno* al){
    if(fi==NULL || fi->qtd == 0)
        return 0;
    *al = fi->dados[fi->inicio];
    return 1;
}
void exibirMenu() {
    printf("\n=== MENU ===\n");
    printf("1. Criar fila\n");
    printf("2. Liberar fila\n");
    printf("3. Inserir elemento\n");
    printf("4. Remover elemento\n");
    printf("5. Consultar elemento\n");
    printf("6. Verificar se a fila esta vazia\n");
    printf("7. Verificar se a fila esta cheia\n");
    printf("8. Exibir tamanho da fila\n");
    printf("9. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Fila *fi = NULL;
    int opcao;
    aluno al;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                fi = criarFila();
                printf("Fila criada com sucesso!\n");
                break;
            case 2:
                liberarFila(fi);
                printf("Fila liberada!\n");
                fi = NULL;
                break;
            case 3:
                printf("Digite os dados do aluno: ");
                scanf("%s", al.nome);  // Supondo que aluno tenha um campo nome
                if (insereFila(fi, al))
                    printf("Elemento inserido com sucesso!\n");
                else
                    printf("Erro ao inserir elemento.\n");
                break;
            case 4:
                if (removeFila(fi))
                    printf("Elemento removido com sucesso!\n");
                else
                    printf("Erro ao remover elemento.\n");
                break;
            case 5:
                if (consultarFila(fi, &al))
                    printf("Primeiro elemento da fila: %s\n", al.nome);
                else
                    printf("Erro ao consultar a fila.\n");
                break;
            case 6:
                printf("Fila esta %s\n", filaVazia(fi) ? "vazia" : "nao esta vazia");
                break;
            case 7:
                printf("Fila esta %s\n", filaCheia(fi) ? "cheia" : "nao esta cheia");
                break;
            case 8:
                printf("Tamanho da fila: %d\n", tamanhoFila(fi));
                break;
            case 9:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 9);

    return 0;
}