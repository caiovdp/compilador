#include "cabecalho.h"

Lista *criaLista(token *conteudo){
	Lista *L = (Lista*) malloc(sizeof(Lista));
	L->conteudo = conteudo;
	L->prox = NULL;
	return L;
}

Lista *push(Lista *L, token *conteudo)
{
	Lista *cabeca, *aux;
	cabeca = L;			
	if(!L){
		return criaLista(conteudo);
	}else{
		aux = (Lista*) malloc(sizeof(Lista));
		aux->conteudo = conteudo;
		aux->prox = NULL;
		while(L->prox)
		{
			L= L->prox;
		}
		L->prox = aux;
		return cabeca;
	}
}


TablelaSimbolos *criaTablelaSimbolos(char *conteudo){
	TablelaSimbolos *L = (TablelaSimbolos*) malloc(sizeof(TablelaSimbolos));
	L->variavel = conteudo;
	L->prox = NULL;
	return L;
}

TablelaSimbolos *pushTablelaSimbolos(TablelaSimbolos *L, char *conteudo)
{
	TablelaSimbolos *cabeca, *aux;
	cabeca = L;			
	if(!L){
		return criaTablelaSimbolos(conteudo);
	}else{
		aux = (TablelaSimbolos*) malloc(sizeof(TablelaSimbolos));
		aux->variavel = conteudo;
		aux->prox = NULL;
		while(L->prox)
		{
			L= L->prox;
		}
		L->prox = aux;
		return cabeca;
	}
}


