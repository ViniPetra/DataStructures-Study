#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int valor;
	struct Node* prox;
}node;

typedef node* No;

typedef struct Cabe�a {
	struct No* inicio;
}cabe�a;

typedef cabe�a* Head;

No llCriaNo(int valor) {
	No novono = malloc(sizeof(No));
	novono->prox = NULL;
	novono->valor = valor;
	return novono;
}

void llPrintar(Head head) {
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

void llInserirFinal(Head head, int valor) {
	if (head->inicio == NULL) {
		No novono = llCriaNo(valor);
		head->inicio = novono;
	}
	else {
		No aux = llCriaNo(NULL);

		aux = head->inicio;

		while (aux->prox != NULL) {
			aux = aux->prox;
		}

		No novono = llCriaNo(valor);
		aux->prox = novono;
	}
}

void llInserirInicio(Head head, int valor) {
	if (head->inicio == NULL) {
		No novono = llCriaNo(valor);
		head->inicio = novono;
	}
	else {
		No aux = llCriaNo(NULL);
		No novono = llCriaNo(valor);
		aux->prox = head->inicio;
		head->inicio = novono;
		novono->prox = aux->prox;
	}
}

void llRemoveFim(Head head) {
	
	No aux = llCriaNo(NULL);
	No prev = llCriaNo(NULL);
	if (head->inicio == NULL) {
		printf("Lista vazia\n");
	}else aux = head->inicio;
	
	while (aux->prox != NULL) {
		prev = aux;
		aux = aux->prox;
	}
	prev->prox = NULL;
}

void llRemoveInicio(Head head) {
	if (head->inicio == NULL) {
		printf("Lista vazia\n");
		return;
	}
	No primeiro = head->inicio;
	head->inicio = primeiro->prox;
}

void llInserirApos(Head head, int index, int valor) {
	No aux = llCriaNo(NULL);
	aux = head->inicio;
	while (aux->valor != index) {
		aux = aux->prox;
		if (aux->prox == NULL) {
			printf("Valor n�o encontrado\n");
			return;
		} 
	}
	No novono = llCriaNo(valor);
	novono->prox = aux->prox;
	aux->prox = novono;
}

void llInserirAntes(Head head, int index, int valor) {
	No aux = llCriaNo(NULL);
	No prev = llCriaNo(NULL);
	aux = head->inicio;
	while (aux->valor != index) {
		prev = aux;
		aux = aux->prox;
		if (aux == NULL) {
			printf("Valor n�o encontrado\n");
			return;
		}
	}
	No novono = llCriaNo(valor);
	novono->prox = aux;
	prev->prox = novono;
}

int main() {

	int opc = 0;
	int valor;
	int index;

	Head head = malloc(sizeof(head));
	head->inicio = NULL;

	do {

		printf("1 - Inserir in�cio\n");
		printf("2 - Inserir fim\n");
		printf("3 - Visualizar\n");
		printf("4 - Remover fim\n");
		printf("5 - Remover Inicio\n");
		printf("6 - Inserir ap�s\n");
		printf("7 - Inserir antes\n");

		scanf_s("%d", &opc);

		switch (opc) {
		case 1:
			printf("Qual valor deseja inserir? ");
			scanf_s("%d", &valor);
			llInserirInicio(head, valor);
			break;
		case 2:
			printf("Qual valor deseja inserir? ");
			scanf_s("%d", &valor);
			llInserirFinal(head, valor);
			break;
		case 3:
			llPrintar(head);
			break;
		case 4:
			llRemoveFim(head);
			break;
		case 5:
			llRemoveInicio(head);
			break;
		case 6:
			printf("Qual valor deseja inserir? ");
			scanf_s("%d", &valor);
			printf("Ap�s qual valor? ");
			scanf_s("%d", &index);
			llInserirApos(head, index, valor);
			break;
		case 7:
			printf("Qual valor deseja inserir? ");
			scanf_s("%d", &valor);
			printf("Antes de qual valor? ");
			scanf_s("%d", &index);
			llInserirAntes(head, index, valor);
			break;
		}

	} while (opc);

	return 0;
}
