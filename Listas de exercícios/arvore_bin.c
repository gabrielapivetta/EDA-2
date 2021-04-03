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
		raiz->esq = adiciona(raiz->esq, no);
	else
		raiz->dir = adiciona(raiz->dir, no);
	//ignora chaves iguais
	return(raiz);
}

PONT busca(TIPOCHAVE ch, PONT raiz){
	if(raiz == NULL) return(NULL);
	if(raiz->chave == ch) return(raiz);
	if(raiz->chave > ch) 
		return(busca(ch, raiz->esq));
	return(contem(ch, raiz->dir));
}

int numeroNos(PONT raiz){
	if(!raiz) return 0;
	return (numeroNos(raiz->esq) + 1 + numeroNos(raiz->dir));
}

void exibirArvore(PONT raiz){
	if(raiz != NULL){
		printf("%i", raiz->chave);
		printf("(");
		exibirArvore(raiz->esq);
		exibirArvore(raiz->dir);
		printf(")");
	}
}

int main(){
	PONT r = init_arvore();
	PONT no = criaNovoNo();
	r = adiciona_no(r, no);
	printf("%d\n", numeroNos(r));
return 0;
}
