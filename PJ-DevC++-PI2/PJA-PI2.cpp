//Projeto C - Atualizado com Fun??o - PI2

//Bicliotecas
#include<stdio.h>
#include<string.h>

#define mInst 10
#define mAlu 30
#define mAt 10

//Vetores
int vCodInst[mInst];
char vInstrutor[mInst][50];
int TLI = 0;
char vCPFAluno[mAlu][15];
char vNAluno[mAlu][50];
int TLA = 0;
int vCodAt[mAt];
char vAtividade[mAt][30];
float vValorAt[mAt];
int TLAT = 0;


//Funcoes
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
int buscaAluno(char cpf[]){
	int i, pos;
	pos = -1;
	
	for(i = 0; i < TLA; i++)
	{
		if(strcmp(vCPFAluno[i], cpf) == 0){
			pos = i;
		}
	}
	return pos;
}

void cadastrarAluno(){
	char cpf[15];
	int pos;
	
	getchar();
	printf("Digite o CPF do alunno: ");
	gets(cpf);
	
	pos = buscaAluno(cpf);
	
	if (pos != -1){
		printf("Aluno ja cadastrado!\n");
	}
	else{
		if (TLA < mAlu){
			strcpy(vCPFAluno[TLA], cpf);
			
			printf("Digite o nome do aluno: ");
			gets(vNAluno[TLA]);
			
			TLA++;
			printf("Aluno cadastrado com sucesso!\n");
		}
		else{
			printf("Limite de alunos atingido!\n");
		}
	}
}

int buscaAt(int codigo){
	int i, pos;
	pos = -1;
	
	for(i = 0; i < TLAT; i++){
		if(vCodAt[i] == codigo){
			pos = i;
		}
	}
	return pos;
}

void cadastrarAt(){
	int codigo, pos;
	
	printf("Digite o codigo da atividade: ");
	scanf("%d", &codigo);
	
	pos = buscaAt(codigo);
	
	if(pos != -1){
		printf("Atividade ja cadastrada!\n");
	}
	else{
		if(TLAT < mAt){
			vCodAt[TLAT] = codigo;
			
			getchar();
			printf("Digite o nome da atividade: ");
			gets(vAtividade[TLAT]);
			printf("Digite o valor da atividade: ");
			scanf("%f", &vValorAt[TLAT]);
			
			TLAT++;
			printf("Atividade cadastrada com sucesso!\n");
		}
		else{
			printf("Limite de atividade atingido!\n");
		}
		
	}
}
//Funcoes para o Menu
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
	printf("2 - Cadastrar Aluno\n");
	printf("3 - Cadastrar Atividade\n");
	printf("4 - Retornar\n");
	printf("Escolhar uma Opcao: ");
	scanf("%d", &opcao);
	
	return opcao;
}
//int menuRelatorio(){
//	
//}



//C?digo Principal
int main(){
	int opcaoPrincipal, opcaoCadastro;
	
	opcaoPrincipal = menuPrincipal();
	
	while(opcaoPrincipal != 2){
		if(opcaoPrincipal == 1){
			opcaoCadastro = menuCadastro();
			while(opcaoCadastro != 4){
				if(opcaoCadastro == 1){
					cadastrarInstrutor();
				}
				else if(opcaoCadastro == 2){
					cadastrarAluno();
				}
				else if(opcaoCadastro == 3){
					cadastrarAt();
				}
				opcaoCadastro = menuCadastro();
			}
		}
		opcaoPrincipal = menuPrincipal();
	}
	printf("\nPrograma Encerrado.\n");
}
