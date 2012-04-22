#include "cabecalho.h"

int contalinhas(char *arquivo){	
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

int main(){
	
//	printf("---> %d \n",contalinhas("tabela1"));
	int i;

	analise_lex("arquivo");
	

	printf("\n");
	return 1;
}
