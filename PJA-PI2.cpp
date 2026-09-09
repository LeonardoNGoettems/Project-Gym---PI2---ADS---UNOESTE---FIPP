//Projeto C - Atualizado com Função - PI2

//Bicliotecas
#include<stdio.h>
#include<string.h>

#define mInst 10
#define mAlu 30

//Vetores
int vCodInst[mInst];
char vInstrutor[mInst][50];
int TLI = 0;

//Funções
int buscaInstrutor(int codigo){
	int i, pos;
	pos = -1;
	
	for(i = 0; i < TLI; i++){
		if(vCodInst[i] == codigo){
			pos = i;
		}
	}
	return pos;
}
void cadastrarInstrutor(){
	int codigo, pos;
	
	printf("Digite o codigo do instrutor: ");
	scanf("%d", &codigo);
	
	pos = buscaInstrutor(codigo);
	
	if(pos != -1){
		printf("Insturtor ja cadastrado!\n");
	}
	else{
		if(TLI < mInst){
			vCodInst[TLI] = codigo;
			
			getchar();
			printf("Digite o nome do instrutor: ");
			gets(vInstrutor[TLI]);
			
			TLI++;
			printf("Instrutor cadastrado com sucesso!\n");
		}
		else{
			printf("Limite de instrutores atingidos!\n");
		}
	}
}

//Funções para o Menu
int menuPrincipal(){
	int opcao;
	
	printf("\n===================================\n");
    printf("        MENU PRINCIPAL\n");
    printf("===================================\n");
    printf("1 - Cadastro\n");
    printf("2 - Finalizar\n");
    scanf("%d", &opcao);
    
    return opcao;
}
int menuCadastro(){
	int opcao;
	
	printf("\n ----- Cadastro -----\n");
	printf("1 - Cadastrar Instrutor\n");
	printf("2 - Retornar\n");
	printf("Escolhar uma Opcao: ");
	scanf("%d", &opcao);
	
	return opcao;
}
//int menuRelatorio(){
//	
//}



//Código Principal
int main(){
	int opcaoPrincipal, opcaoCadastro;
	
	opcaoPrincipal = menuPrincipal();
	
	while(opcaoPrincipal != 2){
		if(opcaoPrincipal == 1){
			opcaoCadastro = menuCadastro();
			while(opcaoCadastro != 2){
				if(opcaoCadastro == 1){
					cadastrarInstrutor();
				}
				opcaoCadastro = menuCadastro();
			}
		}
		opcaoPrincipal = menuPrincipal();
	}
	printf("\nPrograma Encerrado.\n");
}

