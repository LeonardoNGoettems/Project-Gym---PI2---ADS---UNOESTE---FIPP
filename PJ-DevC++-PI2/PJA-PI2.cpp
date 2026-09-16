//Projeto C - Atualizado com Fun??o - PI2

//Bicliotecas
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define mInst 10
#define mAlu 30
#define mAt 10

//Vetores
int vCodInst[mInst];
char vInstrutor[mInst][50];
int TLI = 0;
char vCPFAluno[mAlu][15];
char vNAluno[mAlu][50];
int vDiaVenc[mAlu];
float vValorPlano[mAlu];
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
	
	valido = validaCPF(cpf);
	
	while( valido == 0){
		printf("[ERRO] CPF ja invalido!\n");
		printf("Digite novamente o CPF do aluno: ")
		gets(cpf);
		valido = validaCPF(cpf);
	}
	
	pos = buscaAluno(cpf);
	
	if (pos != -1){
		printf("Aluno ja cadastrado!\n");
	}
	else{
		if (TLA < mAlu){
			strcpy(vCPFAluno[TLA], cpf);
			
			printf("Digite o nome do aluno: ");
			gets(vNAluno[TLA]);
			
			dia = diaVenc();
			vDiaVenc[TLA] = dia;
			
			valorPlano = selecionaAtividade();
			vValorPlano[TLA] = valorPlano;
			
			TLA++;
			printf("Aluno cadastrado com sucesso!\n");
			printf("Valor do plano; R$ %.2f\n", valorPlano);
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
int validaCPF(char cpf[]){
	int vetCPF[11], i, j, mult, n_mult, soma, resto, sub, d1, d2, n_mult2, soma2;
	char s[2];
	
	j = 0;
	for(i = 0; i < 14 && cpf[i] != '\0'; i++){
		if(cpf[i] != '.' && cpf[i] != '-'){
			s[0] = cpf[i];
			s[1] = '\0';
			vetCPF[j] = atoi(s);
			j++;
		}
	}
	if(j != 11){
		return 0;
	}
	
	soma = 0;
	n_mult = 10;
	
	for(i = 0; i < 9; i++){
		mult = vetCPF[i] * n_mult;
		soma = soma + mult;
		n_mult--;
	}
	resto = soma % 11;
	sub = 11 - resto;
	if (sub == 10 || sub == 11){
		d1 = 0;
	}
	else{
		d1 = sub;
	}
	soma2 = 0;
	n_mult2 = 11;
	for(i = 0; i < 9; i++){
		mult = vetCPF[i] * n_mult2;
		soma2 = soma2 + mult;
		n_mult2--;
	}
	soma2 = soma2 + d1*2;
	resto = soma2 % 11;
	sub = 11 - resto;
	if(sub == 10 || sub == 11){
		d2 = 0;
	}
	else{
		d2 = sub;
	}
	if(vetCPF[9] == d1 && vetCPF[10] == d2){
		return 1;
	}
	else{
		return 0;
	}
}
int diaVenc(){
	int dia;
	
	printf("Dia de Vencimento do plano (1 a 31): ");
	scanf("%d", &dia);
	
	while(dia < 1 || dia > 31){
		printf("[ERRO] Dia invalido!");
		printf("Digite novamente o dia de vencimento: ");
		scanf("%d", &dia);
	}
	return dia;
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
