#include "cabecalho.h"


int EA=0;
int num_linha;
int volta=1;


char lerCaracter(FILE *arq){
	return fgetc(arq);
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


int tamanho_tabela(linha* lin){
	return num_linha; 
}

void automato(linha *tabela,FILE *arq){
	char c;
	int aux;
	volta=1;
	valido=0;
	buffer[0]='\0';
	EA=0;
	int i=0;
	while(!feof(arq) && EA!=-1){
		c = fgetc(arq);

		if (!( aux = verifica_troca(c,tabela) )){
			printf("\nError input\n");
			exit(1);
		}
		
	}

	next_character = fgetc(arq);
	fseek(arq,-sizeof(char),SEEK_CUR);
	if(volta){	
		fseek(arq,-sizeof(char),SEEK_CUR);
	}

}

int verifica_troca(char c, linha* tabela){

	int tam_tabela = tamanho_tabela(tabela);
	int i=0;
	int valido;
	while(i < tam_tabela){

		if(EA == tabela[i].EA){
			valido = valida(c,tabela[i].trans);			

			if( valido ){
				acao(c,tabela[i].ACTION);
				EA = tabela[i].PROX;
				return 1;
			}
		}
		i++;
	}
	return 0;
}

void acao(char c,int op){
	int i = 0;
	switch(op){
		case 1:
			while(i<100 && buffer[i] !='\0')
				i++;
			buffer[i]=c;
			buffer[i+1]='\0';
		break;

		case 2:
			tokem_type_id = 1;
			strcpy(tokem_type,"ident");
			valido=1;
		break;

		case 3:
			tokem_type_id = 2;
			strcpy(tokem_type,"inteiro");
			valido=1;
		break;
		
		case 4:
			tokem_type_id = 3;
			strcpy(tokem_type,"real");
			valido=1;
		break;

		case 5:
			tokem_type_id = 4;
			strcpy(tokem_type,"simbolo");
			while(i<100 && buffer[i] !='\0')
				i++;
			buffer[i]=c;
			buffer[i+1]='\0';
			volta=0;
			valido=1;
		break;
		
		case 6:
			tokem_type_id = 5;
			strcpy(tokem_type,"string");
			valido=1;
			volta=0;
		break;
		
	}
}

int valida(char c,int op){
	switch(op){
	
	case 0://descate
		if( c == '\n' || c == '\t' || c == ' ' || c == EOF)
			return 1;
		else
			return 0;
	break;
	
	case 1://A-Z a-z
		if( ((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122))  )
			return 1;
		else
			return 0;
	break;

	case 2://0-9
		if( ((c >= 48) && (c <= 57)) )
			return 1;
		else
			return 0;	
	break;

	case 3://Simbolo
		if( c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']' || c == '=' || c == ',' || c == '&' || c == '+' || c == '-' || c == '/' || c == '*' || c == ';')
			return 1;
		else
			return 0;
	break;

	case 4://separador numerico
		if( c == '.' )
			return 1;
		else
			return 0;
	break;
	
	case 5://String
		if( c == '"' )
			return 1;
		else
			return 0;
	break;
	
	case 6://caracter String
		if( c == '@' || c == '%' )
			return 1;
		else
			return 0;
	break;
	
	case 7://Fim
		if( c == '(' || c == ')' || c == '{' || c == '}' || c == '[' || c == ']' || c == '=' || c == ',' || c == '&' || c == '+' || c == '-' || c == '/' || c == '*' || c == ';' || c == '\n' || c == '\t' || c == ' ' || c == EOF)
			return 1;
		else
			return 0;
	break;
	
	}
}
