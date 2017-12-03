#include <stdio.h>
#include <stdlib.h>

#define ORDEM 2

// Falta a função de remoção de nodo

typedef struct pagina{
	int numKeys;
	int keys[ORDEM*2];
	struct pagina* filhos[(ORDEM*2)+1];
} PAGINA;

int verFolha(PAGINA *pag){ // Se a pagina for folha retorna 1
	for(int i = 1; i < ORDEM*2 + 1; i++){
		if(pag->filhos[i] != NULL){
			return 0;
		}
	}
	
	return 1;
}

int getInfo(){
	int info;
	printf("Digite a info da chave: ");
	scanf(" %d", &info);
	return info;
}

PAGINA *criaPag(){
	PAGINA *nova = malloc(sizeof(PAGINA));
	nova->numKeys = 0;
	for(int i = 0; i < ORDEM*2 + 1; i++){
		nova->filhos[i] = NULL;
	}
	return nova;
}

PAGINA *criaArvore(){
	int info = getInfo();
	PAGINA *nova = criaPag();
	nova->keys[0] = info;
	nova->numKeys = 1;
	
	return nova;
}

PAGINA *buscaChave(PAGINA *atual, int info){
	PAGINA *retorno = NULL;
	PAGINA *filho;
	for(int i = 0; i < atual->numKeys; i++){
		filho = atual->filhos[i];
		
		if(atual->keys[i] == info){
			return atual;
		} else if(info < atual->keys[i]){
			if(!filho){
				return NULL;
			} else {
				retorno = buscaChave(filho, info);
				return retorno;
			}
		} else if(i = (atual->numKeys)-1){
			if(!atual->filhos[i+1]){
				return NULL;
			} else {
				retorno = buscaChave(atual->filhos[i+1], info);
				return retorno;
			}
		}
	}

}

void busca(PAGINA *root){
	int info = getInfo();
	PAGINA *pag = buscaChave(root, info);
	
	if(pag){
		printf("\nChave encontrada na arvore\n\n");
	} else {
		printf("\nChave inexistente na arvore\n\n");
	}
}

PAGINA *insereChave(PAGINA **atual, int info){
	PAGINA *pagina;
	PAGINA *filho;
	int i, aux, aux2, k=0;
	PAGINA *auxP;
	
	for(i = 0; i < (*atual)->numKeys; i++){
		
		if(info < (*atual)->keys[i]){
			if(!filho){
				pagina = (*atual);
				break;
			} else {
				pagina = insereChave(&(*atual)->filhos[i], info); 
				break;
			}
		} else if(i = ((*atual)->numKeys)-1){
			if(!(*atual)->filhos[i+1]){
				pagina = (*atual);
				break;
			} else {
				pagina = insereChave(&(*atual)->filhos[i+1], info);
				break;
			}
		}
	}	// No final dessa execução esta na pagina onde precisa ser inserido o elemento
	
	if(pagina == NULL) {
		return NULL; // Ja inserido anteriormente
	}
	
	if(pagina->numKeys < ORDEM*2){
		aux = pagina->numKeys - i;
				 
		for(int j = 0; j < aux; j++){
			aux2 = pagina->keys[i+j+1];
			pagina->keys[j+i+1] = pagina->keys[i];
			pagina->keys[i] = aux2;
		}	
		
		pagina->keys[i] = info;
		return NULL;
	}
	
}

void insere(PAGINA **root){
	int info = getInfo();
	PAGINA *pag = buscaChave(*root, info);
	
	if(pag){
		printf("\nChave encontrada na arvore, inclusão não permitida\n\n");
		return;
	}
	
	insereChave(root, info);
	printf("\n\nNodo Inserido Com Sucesso\n\n");
}


void main(){
	int opt;
	PAGINA *root = NULL;
	
	do{
		printf("B-TREE\n1- Criar Arvore\n2- Adicionar Chave\n3- Buscar Chave\n4- Remover Chave\n5- Deleta Arvore\n0-Sair\n");
		scanf(" %d", &opt);
		switch(opt){
			case 1: // Cria btree
				if(root) {
					printf("B-Tree Ja Criada");
					break;
				}
				root = criaArvore();
				printf("B-Tree Criada Com Sucesso\n\n");
				break;
			case 2: // Adiciona chave
				if(!root){
					printf("B-Tree Ainda Nao Criada\n\n");
					break;
				}
				insere(&root);				
				break;
			case 3: // Busca chave
 				if(!root){
					printf("B-Tree Ainda Nao Criada\n\n");
					break;
				}
				busca(root);
				break;
			case 4: // Remove chave
				if(!root){
					printf("B-Tree Ainda Nao Criada\n\n");
					break;
				}
				break;
			case 5 : // Deleta arvore
				if(!root){
					printf("B-Tree Ainda Nao Criada\n\n");
					break;
				}
				printf("\n\nArvore Deletada\n\n");
				root = NULL;
				break;	
		}

	}while(opt != 0);
}
