#include <stdio.h>
#include <stdlib.h>
struct lista {
    int info;
    struct lista *prox;
};
typedef struct lista Lista;
Lista* criaLista() {
    return NULL;
}
Lista* inserirLista(Lista *lista, int i) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = lista;
    return novo;
}
void imprimeLista(Lista *l) {
    Lista *p;
    for (p = l; p != NULL; p = p->prox) {
        printf("%d\n", p->info);
    }
}
int listaVazia(Lista *l) {
    return l == NULL ? 1 : 0;
}
Lista* buscaLista(Lista *l, int v) {
    Lista *p;
    for (p = l; p != NULL; p = p->prox) {
        if (p->info == v) {
            return p;
        }
    }
    return NULL;
}
Lista* retiraLista(Lista *l, int v) {
    Lista *ant = NULL;
    Lista *p = l;
    while (p != NULL && p->info != v) {
        ant = p;
        p = p->prox;
    }

    if (p == NULL) { 
        return l;
    }

    if (ant == NULL) { 
        l = p->prox;
    } else { 
        ant->prox = p->prox;
    }
    free(p);
    return l;
}
void liberaLista(Lista *l) {
    Lista *p = l;
    while (p != NULL) {
        Lista *t = p->prox;
        free(p);
        p = t;
    }
}
Lista* inserirOrdenado(Lista *l, int valor) {
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = NULL;
    if (l == NULL || valor < l->info) {
        novo->prox = l;
        return novo;
    }
    Lista *p = l;
    while (p->prox != NULL && p->prox->info < valor) {
        p = p->prox;
    }
    novo->prox = p->prox;
    p->prox = novo;
    return l;
}
int main() {
    Lista *lista = criaLista();
    int opcao, valor;
    
do {
    printf("1 -> Inserir elemento na lista (em ordem crescente)\n");
    printf("2 -> Exibir lista\n");
    printf("3 -> Buscar lista\n");
    printf("4 -> Remover elemento da lista\n");
    printf("5 -> Liberar lista e sair\n");
    printf("Escolha uma opção:");
    scanf("%d", &opcao);
switch (opcao) {
case 1:
    printf("Digite um valor para inserir: ");
    scanf("%d", &valor);
    lista = inserirOrdenado(lista, valor);
    printf("Elemento %d inserido.\n", valor);
    break;
case 2:
    printf("Lista atual: ");
    imprimeLista(lista);
    break;
case 3:
    printf("Digite um valor para buscar: ");
    scanf("%d", &valor);
    Lista *resultado = buscaLista(lista, valor);
    if (resultado != NULL) {
        printf("Elemento %d encontrado.\n", valor);
    } else{
        printf("Elemento %d não encontrado.\n", valor);
    }
    break;
case 4:
    printf("Digite um valor para remover: ");
    scanf("%d", &valor);
    lista = retiraLista(lista, valor);
    break;
case 5:
    liberaLista(lista);
    printf("Lista liberada.\n");
    break;
default:
    printf("Opção inválida. Tente novamente.\n");
}
} while (opcao != 5);

return 0;
}
   