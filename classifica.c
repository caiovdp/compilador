#include "cabecalho.h"

void classificaSimbolo (token * conteudo){
	switch(conteudo->conteudo[0]){
		case '(':
			conteudo->idtype=40;
		break;
		case ')':
			conteudo->idtype=41;
		break;
		case ';':
			conteudo->idtype=42;
		break;
		case ',':
			conteudo->idtype=43;
		break;
		case '{':
			conteudo->idtype=44;
		break;
		case '}':
			conteudo->idtype=45;
		break;
	}
}

void classificaIdent (token * conteudo){
	char funcao_primitiva[2][6] =   { "printf", "scanf"};
	char palavra_reservada[13][10] = { "while", "if", "else", "for", "main", "return", "void", "int", "double", "float", "switch", "case", "break"};
	int aux = 0,fim = 1;
	while(aux < 2){
		if(strcmp(conteudo->conteudo,funcao_primitiva[aux]) == 0){
			fim=0;
			conteudo->idtype=11;
			break;
		}
		aux++;
	}
	aux=0;
	if(fim==1){
		while(aux < 13){
			if(strcmp(conteudo->conteudo,palavra_reservada[aux]) == 0){
				conteudo->idtype=12;
				break;
			}else
				aux++;
		}
	}
}

void classificaToken (Lista * L){
	Lista * cabeca;
	cabeca = L;
	int aux;
	while(L->prox)
	{

		aux = L->conteudo->idtype;
		if(aux == 1){//ident
			classificaIdent(L->conteudo);
		}else{
			if(aux == 4){
				classificaSimbolo(L->conteudo);
			}
		}

		if(L->conteudo->idtype == 1){
			TS = pushTablelaSimbolos(TS,L->conteudo->conteudo);
		}
		printf("%s,%d\n", L->conteudo->conteudo,L->conteudo->idtype);
		L= L->prox;
	}
}