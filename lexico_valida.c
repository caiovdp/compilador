#include "cabecalho.h"

int lexico_valida(char c,int op){
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