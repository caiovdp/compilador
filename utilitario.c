#include "cabecalho.h"

int contalinhas(char *arquivo){//ok
	FILE *arq;
	char c;
	int linha=0;	
	TS = NULL;
	arq = fopen(arquivo,"r");
	
	if(arq){
		while ( (c = fgetc(arq)) != EOF )
			if(c=='\n')
				linha++;

		return linha;
	}else{
		return 0;
	}
	fclose(arq);
}

linha* ler_tabela(char *arquivo){
	int ea,prox,ac,i=0,trans;
	int linhas = contalinhas(arquivo);
	num_linha = linhas;
	linha *tabela = (linha *) malloc(sizeof(linha)*linhas);

	
	FILE *arq = fopen(arquivo,"r");
	
	if(!arq){
		exit(1);
	}
	
	for(i=0; i < linhas;i++){
		fscanf(arq,"%d;%d;%d;%d",&ea,&prox,&ac,&trans);
		tabela[i].EA=ea;
		tabela[i].PROX=prox;
		tabela[i].ACTION=ac;
		tabela[i].trans=trans;
	}

	return tabela;
}