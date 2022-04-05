#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int valor;
	struct Node* prox;
}node;

typedef node* No;

typedef struct Cabeça {
	struct No* inicio;
	struct No* fim;
}cabeça;

typedef cabeça* Head;

No llCriaNo(int valor) {
	No novono = malloc(sizeof(No));
	novono->prox = NULL;
	novono->valor = valor;
	return novono;
}

void llPrintar(Head head) {
	
	for (No aux = head->inicio; aux != NULL; aux = aux->prox)
	{
		printf("%d ", aux->valor);
	}
	printf("\n");
}//Vai dar segmentation fault pq n tem verificador de lista vazia

void llInserirFinal(Head head, int valor) {
	if (head->inicio == NULL) {
		No novono = llCriaNo(valor);
		head->inicio = novono;
		novono->valor = valor;
	}
	else {
		No aux = llCriaNo(NULL);

		aux = head->inicio;

		while (aux->prox != NULL) {
			aux = aux->prox;
		}

		No novono =llCriaNo(valor);
		aux->prox = novono;
		novono->valor = valor;
	}
}

void llInserirInicio(Head head, int valor) {
	if (head->inicio == NULL) {
		No novono = llCriaNo(valor);
		head->inicio = novono;
		novono->valor = valor;
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

int main() {

	int opc = 0;
	int valor;

	Head head = malloc(sizeof(head));
	head->inicio = NULL;
	head->fim = NULL;

	do {

		printf("1 - Inserir início\n");
		printf("2 - Inserir fim\n");
		printf("3 - Visualizar\n");
		printf("4 - Remover fim\n");

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
		}

	} while (opc);

	return 0;
}
