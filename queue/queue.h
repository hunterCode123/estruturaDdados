#define MAX 100

typedef struct aluno {
    int matricula;
    char nome[100];
    float n1,n2;
}aluno;
typedef struct fila Fila;

Fila* criarFila();
void liberarFila(Fila* fi);
int consularFila(Fila* fi, aluno* al);
int insereFila(Fila* fi, aluno al);
int removeFila(Fila* fi);
int tamanhoFila(Fila* fi);
int filaVazia(Fila* fi);
int filaCheia(Fila* fi);

