#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char buffer[100];
char tokem_type[50];
char next_character;
int num_linha;
int tokem_type_id;



//Lexico
int Lexico_valido;
int Lexico_volta;

typedef struct{
	int EA,PROX,ACTION,trans;
} linha;

typedef struct {
	int linha;
	char *conteudo;
	int coluna;
	char *type;
	int idtype;
}token;

struct ListaS{
	struct ListaS *prox;
	token *conteudo;
};

typedef struct ListaS Lista;

struct tablelaSimbolos{
	struct tablelaSimbolos *prox;
	char *variavel;
};

typedef struct tablelaSimbolos TablelaSimbolos;

TablelaSimbolos *TS;



//Lista encadeada
Lista* criaLista(token *conteudo);
Lista* push(Lista *L, token *conteudo);

//Tabela de simbolos
TablelaSimbolos *criaTablelaSimbolos(char *conteudo);
TablelaSimbolos *pushTablelaSimbolos(TablelaSimbolos *L, char *conteudo);

//utilitario automato
linha* ler_tabela(char *arquivo);


//Lexico
Lista* analise_lexica(char *arquivo);
void automato_lexico(linha *tabela,FILE *arq);
int  lexico_verifica_troca(char c, linha* tabela);
void lexico_acao(char c,int op);
int  lexico_valida(char c,int op);
void lexico_classificaSimbolo (token * conteudo);
void lexico_classificaIdent (token * conteudo);
void lexico_classificaToken (Lista * L);
