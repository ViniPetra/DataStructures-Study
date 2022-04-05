#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int valor;
	struct No* prox;
	struct No* prev;
}node;

typedef node* No;

typedef struct Cabeça {
	struct Node* inicio;
	struct Node* fim;
}cabeça;

typedef cabeça* Head;

No ldlCriaNo(int valor) {
	No novono = malloc(sizeof(No));
	novono->prox = NULL;
	novono->prev = NULL;
	novono->valor = valor;
	return novono;
}

void ldlPrintar(Head head) {
	if (head->inicio == NULL) {
		printf("Lista vazia\n");
		return;
	}

	for (No aux = head->inicio; aux != NULL; aux = aux->prox)
	{
		printf("%d ", aux->valor);
	}
	printf("\n");
}

void ldlInserirFinal(Head head, int valor) {
	No novono = ldlCriaNo(valor);
	if (head->inicio == NULL) {
		head->inicio = novono;
		head->fim = novono;
	}
	else {
		head->fim->prox = novono;
		novono->prev = head->fim;
		head->fim = novono;
	}
}

void ldlInserirInicio(Head head, int valor) {
	if (head->inicio == NULL) {
		No novono = ldlCriaNo(valor);
		head->inicio = novono;
		head->fim = novono;
	}
	else {
		No aux = ldlCriaNo(NULL);
		No novono = ldlCriaNo(valor);

		novono->prox = head->inicio;
		head->inicio = novono;
	}
}

void ldlRemoveFim(Head head) {
	if (head->inicio != NULL) {
		if (head->inicio == head->fim) {
			head->fim = NULL;
			return;
		}
		head->fim = head->fim->prev;
		head->fim->prox = NULL;
	}
	else {
		printf("Lista vazia\n");
	}
}

void ldlRemoveInicio(Head head) {
	if (head->inicio == NULL) {
		printf("Lista vazia\n");
		return;
	}
	head->inicio = head->inicio->prox;
	head->inicio->prev = NULL;
}

void ldlInserirApos(Head head, int index, int valor) {
	No aux = ldlCriaNo(NULL);
	No novono = ldlCriaNo(valor);
	aux = head->inicio;
	while (aux->valor != index) {
		aux = aux->prox;
		if (aux->prox == NULL) {
			printf("Valor não encontrado\n");
			return;
		}
	}
	novono->prox = aux->prox;
	novono->prev = aux;
	aux = aux->prox;
	aux->prev = novono;
	aux = novono->prev;
	aux->prox = novono;
}

void ldlInserirAntes(Head head, int index, int valor) {
	No aux = ldlCriaNo(NULL);
	No novono = ldlCriaNo(valor);
	aux = head->inicio;
	while (aux->valor != index) {
		aux = aux->prox;
		if (aux == NULL) {
			printf("Valor não encontrado\n");
			return;
		}
	}
	novono->prev = aux->prev;
	novono->prox = aux;
	aux->prev = novono;
	aux = novono->prev;
	aux->prox = novono;
}

int main() {

	int opc = 0;
	int valor;
	int index;

	Head head = malloc(sizeof(head));
	head->inicio = NULL;
	head->fim = NULL;

	do {

		printf("1 - Inserir início\n");
		printf("2 - Inserir fim\n");
		printf("3 - Visualizar\n");
		printf("4 - Remover fim\n");
		printf("5 - Remover Inicio\n");
		printf("6 - Inserir após\n");
		printf("7 - Inserir antes\n");

		scanf_s("%d", &opc);

		switch (opc) {
		case 1:
			printf("Qual valor deseja inserir? ");
			scanf_s("%d", &valor);
			ldlInserirInicio(head, valor);
			break;
		case 2:
			printf("Qual valor deseja inserir? ");
			scanf_s("%d", &valor);
			ldlInserirFinal(head, valor);
			break;
		case 3:
			ldlPrintar(head);
			break;
		case 4:
			ldlRemoveFim(head);
			break;
		case 5:
			ldlRemoveInicio(head);
			break;
		case 6:
			printf("Qual valor deseja inserir? ");
			scanf_s("%d", &valor);
			printf("Após qual valor? ");
			scanf_s("%d", &index);
			ldlInserirApos(head, index, valor);
			break;
		case 7:
			printf("Qual valor deseja inserir? ");
			scanf_s("%d", &valor);
			printf("Antes de qual valor? ");
			scanf_s("%d", &index);
			ldlInserirAntes(head, index, valor);
			break;
		}

	} while (opc);

	return 0;
}
