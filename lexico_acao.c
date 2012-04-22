#include "cabecalho.h"

void lexico_acao(char c,int op){
	int i = 0;
	int valido;

	valido = Lexico_valido;

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
			Lexico_volta=0;
			valido=1;
		break;
		
		case 6:
			tokem_type_id = 5;
			strcpy(tokem_type,"string");
			valido=1;
			Lexico_volta=0;
		break;
		
	}

	Lexico_valido = valido;

}