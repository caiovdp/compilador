#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char buffer[100];
char tokem_type[50];
char next_character;
int valido;
int tokem_type_id;
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

int verifica_troca(char c, linha* tabela);
int valida(char c,int op);
void acao(char c,int op);
int contalinhas(char *arquivo);
char lerCaracter(FILE *arq);
linha* ler_tabela(char *arquivo);
int tamanho_tabela(linha* lin);
void automato(linha *tabela,FILE *arq);
Lista* criaLista(token *conteudo);
Lista* push(Lista *L, token *conteudo);
TablelaSimbolos *criaTablelaSimbolos(char *conteudo);
TablelaSimbolos *pushTablelaSimbolos(TablelaSimbolos *L, char *conteudo);

