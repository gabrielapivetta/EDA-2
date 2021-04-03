#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct aux{
	TIPOCHAVE chave;
	struct aux *esq, *dir;
} NO;

typedef NO* PONT;

PONT init_arvore(){
	return(NULL);
}

PONT criaNovoNo(TIPOCHAVE ch){
	PONT novoNo = (PONT)malloc(sizeof(NO));
	novoNo->esq = NULL;
	novoNo->dir = NULL;
	novoNo->chave = ch;
	return(novoNo);
}

PONT adiciona_no(PONT raiz, PONT no){
	if(raiz == NULL) return no;
	if(no->chave < raiz->chave)
		raiz->esq = adiciona_no(raiz->esq, no);
	else
		raiz->dir = adiciona_no(raiz->dir, no);
	//ignora chaves iguais
	return(raiz);
}

PONT busca(TIPOCHAVE ch, PONT raiz){
	if(raiz == NULL) return(NULL);
	if(raiz->chave == ch) return(raiz);
	if(raiz->chave > ch) 
		return(busca(ch, raiz->esq));
	return(busca(ch, raiz->dir));
}

int numeroNos(PONT raiz){
	if(!raiz) return 0;
	return (numeroNos(raiz->esq) + 1 + numeroNos(raiz->dir));
}

void exibirPreOrder(PONT raiz){
	if(raiz != NULL){
		printf("%i ", raiz->chave);
		exibirPreOrder(raiz->esq);
		exibirPreOrder(raiz->dir);
	}
}

void exibirInOrder(PONT raiz){
	if(raiz != NULL){
		exibirInOrder(raiz->esq);
		printf("%i ", raiz->chave);
		exibirInOrder(raiz->dir);
	}
}

void exibirPosOrder(PONT raiz){
	if(raiz != NULL){
		exibirPosOrder(raiz->esq);
		exibirPosOrder(raiz->dir);
		printf("%i ", raiz->chave);
	}
}

int main(){
	PONT raiz = init_arvore();
	int chave_aux;
	while(scanf("%d", &chave_aux) != EOF){
		PONT no = criaNovoNo(chave_aux);
		raiz = adiciona_no(raiz, no);
	}
	exibirPreOrder(raiz);
	printf(".\n");
	exibirInOrder(raiz);
	printf(".\n");
	exibirPosOrder(raiz);
	printf(".\n");
	
return 0;
}
