#include "cabecalho.h"

void analise_lex(char *arquivo){
	linha *tabela;
	token *t;
	tabela = ler_tabela("automoto.auto");
	int aux;
	Lista *L=NULL;
	buffer[0]='\0';
	FILE *arq = fopen(arquivo,"r");
	if(!arq){
		exit(1);
	}
	int i=0;
	next_character = 0;	
	while (next_character != EOF){
		automato(tabela,arq);
		if(valido){
			t= (token*) malloc(sizeof(token));
			aux = strlen(buffer);
			aux += 1;
//			t->linha = ;
//			t->coluna = ;
			t->conteudo = (char*) malloc(sizeof(char)*aux);
			strcpy(t->conteudo,buffer);
			t->type = tokem_type;
			t->idtype = tokem_type_id;			
			L = push(L,t);
//			printf("%s,%s\n",buffer,tokem_type);
//			exit(1);
		}
		i++;
	}
	classificaToken(L);
}