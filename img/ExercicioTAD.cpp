#include <stdio.h>
#include <stdlib.h>
/**
Exercício sobre Tipo Abstrato de dados
O código abaixo contém as funções básicas de uma lista simplesmente encadeada:
* Inserir elemeto no início da lista;
* Inserir elemento no fim;
* Retirar elemento do início;
* Retirar elemento do fim;
* Imprimir a lista inteira;
* Uma função main que utiliza estas funções acima.

Você deverá modificar este código para:
* A) Os métodos da lista encadeada deverão ser implementados por um TAD. 
*** Crie um cabeçaçho para descrever as funções e crie um arquivo C para as implementações;
*** Somente as funções deverão ser vistas pelo mundo exterior. Você deve esconder as variáveis globais.
* B) Crie um arquivo main separado que utilize o seu TAD de lista encadeada. Retire a função main atual deste arquivo e o coloque no arquivo main. 
* C) Crie um TAD de pilha, sem reescrever nenhum código. Você deve criar um cabeçalho para isto que reutilize o código que já está pronto para a lista 

*/

//
typedef struct no{
    int valor;
    struct no *prox;
}tipoNo;
//
typedef struct lista{
    tipoNo *primeiro;
} tipoLista;
//
tipoLista *l;
//
void imprime(){
    tipoNo *aux = l->primeiro;
    while(aux!=NULL){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}
//
void insereInicio(int v){
    tipoNo *novo = (tipoNo*)malloc(sizeof(tipoNo));
    novo->valor = v;
    novo->prox = l->primeiro;
    l->primeiro = novo;

}
//
void inserefim(int v){
    tipoNo *novo = (tipoNo*)malloc(sizeof(tipoNo));
    novo->valor = v;
    novo->prox = NULL;
    tipoNo *aux = l->primeiro;
    if(aux==NULL){
        l->primeiro = novo;
    }else{
        while(aux->prox!=NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}
//
int retiraInicio(){
    tipoNo* aux = l->primeiro;
    if(aux==NULL){//lista vazia
        printf("A lista est� vazia\n");
        return 0;
    }
    int val;
    if(aux!=NULL){
        l->primeiro = aux->prox;
        val=aux->valor;
        free(aux);
    }
    return val;
}
//
int retiraFim(){
    if(l->primeiro==NULL){//lista vazia
        printf("A lista est� vazia\n");
        return 0;
    }
    //a lista so tem 1 elemento -  atualiza a cabeça
    if(l->primeiro->prox==NULL){
        return retiraInicio(l);
    }
    //se tem mais de um elemento, percorre ate o fim
    tipoNo *penultimo = l->primeiro;
    tipoNo *ultimo = l->primeiro->prox;
    
    while(ultimo->prox != NULL){
        penultimo = ultimo;
        ultimo = ultimo->prox;
    }
    //encerra a lista no penultimo
    penultimo->prox = NULL;
    //salva o valor do ultimo
    int val = ultimo->valor;
    free(ultimo);
    return val;  
}
//
void criaListaVazia(){
    l = (tipoLista*)malloc(sizeof(tipoLista));
    l->primeiro = NULL;
}
//
int main(){
    criaListaVazia();
    
    inserefim(20);
    inserefim(5);
    inserefim(25);
    imprime();
    retiraFim();//25
    imprime();
    retiraInicio();//20
    imprime();
    insereInicio( 55);//55
    imprime();
    retiraInicio();//5
    imprime();
    retiraInicio();
    imprime();
    retiraFim();
    imprime();
    retiraInicio();
}
