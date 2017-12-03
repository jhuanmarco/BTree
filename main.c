#include <stdio.h>
#include <stdlib.h>

#define ORDEM 2

typedef struct pagina{
	int num_keys;
	int keys[ORDEM*2];
	struct pagina* filhos[(ORDEM*2)+1];
} PAGINA;



void main(){
	int opt;
	PAGINA *root = NULL;
	
	do{
		printf("B-TREE\n1- Criar Arvore\n2- Adicionar Chave\n3- Buscar Chave\n4- Remover Chave\n0-Sair\n");
		scanf(" %d", &opt);
		switch(opt){
			case 1: // Cria btree
				if(root) {
					printf("B-Tree Ja Criada");
					break;
				}
				
				printf("B-Tree Criada Com Sucesso");
				break;
			case 2: // Adiciona chave
				if(!root){
					printf("B-Tree Ainda Nao Criada");
					break;
				}
				break;
			case 3: // Busca chave
 				if(!root){
					printf("B-Tree Ainda Nao Criada");
					break;
				}
				break;
			case 4: // Remove chave
				if(!root){
					printf("B-Tree Ainda Nao Criada");
					break;
				}
				break;
		}

	}while(opt != 0);
}
