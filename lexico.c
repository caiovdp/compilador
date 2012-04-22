#include "cabecalho.h"

int Lexico_EA=0;
int Lexico_num_linha;


Lista* analise_lexica(char *arquivo){
	//vars
	linha *tabela;
	token *t;
	int aux;
	Lista *L=NULL;
	int i;

	//Init
	i=0;
	next_character = 0;	
	buffer[0]='\0';
	tabela = ler_tabela("automoto.auto");
	Lexico_num_linha = num_linha;

	FILE *arq = fopen(arquivo,"r");
	if(!arq){
		exit(1);
	}
	
	while (next_character != EOF){
		automato_lexico(tabela,arq);
		if(Lexico_valido){
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
	lexico_classificaToken(L);

	return L;
}

void automato_lexico(linha *tabela,FILE *arq){
	//vars
	char c;
	int aux;
	int i=0;

	//init 
	Lexico_volta=1;
	Lexico_valido=0;
	buffer[0]='\0';
	Lexico_EA=0;
	
	while(!feof(arq) && Lexico_EA!=-1){
		c = fgetc(arq);

		if (!( aux = lexico_verifica_troca(c,tabela) )){
			printf("\nError input\n");
			exit(1);
		}
		
	}

	next_character = fgetc(arq);
	fseek(arq,-sizeof(char),SEEK_CUR);
	if(Lexico_volta){	
		fseek(arq,-sizeof(char),SEEK_CUR);
	}

}

int lexico_verifica_troca(char c, linha* tabela){

	int tam_tabela = Lexico_num_linha;//tamanho_tabela(tabela);
	int i=0;
	int valido;
	while(i < tam_tabela){

		if(Lexico_EA == tabela[i].EA){
			valido = lexico_valida(c,tabela[i].trans);			

			if( valido ){
				lexico_acao(c,tabela[i].ACTION);
				Lexico_EA = tabela[i].PROX;
				return 1;
			}
		}
		i++;
	}
	return 0;
}
