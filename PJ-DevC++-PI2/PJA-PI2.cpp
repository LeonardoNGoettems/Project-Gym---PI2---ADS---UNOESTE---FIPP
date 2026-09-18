//Projeto C - Atualizado com Funcao - PI2

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

float selecionaAtividade(){
	float totalAt;
	int codAtDigitado, pos, i;
	
	if(TLAT == 0){
		printf("\nNenhuma atividade cadastrada no sistema!\n");
		return 0;
	}
	printf("\nAtividades disponiveis: \n");
	for(i = 0; i < TLAT; i++){
		printf("Codigo: %d | Nome: %s | Valor: %.2f\n", vCodAt[i], vAtividade[i], vValorAt[i]);
	}
	totalAt = 0;
	
	printf("\nDigite o codigo da Atividade (0 para encerrar): ");
	scanf("%d", &codAtDigitado);
	
	while(codAtDigitado != 0){
		pos = buscaAt(codAtDigitado);
		
		if(pos != -1){
			totalAt = totalAt + vValorAt[pos];
			printf("Atividade adicionada! Valor parcial do plano");
		}
		else{
			printf("Atividade nao encontrada!\n");
		}
		printf("Proximo codigo de atividade ( 0 para encerrar )");
	}
	return totalAt;
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
void cadastrarAluno(){
	char cpf[15];
	int pos, valido, dia;
	float valorPlano;
	
	getchar();
	printf("Digite o CPF do alunno: ");
	gets(cpf);
	
	valido = validaCPF(cpf);
	
	while( valido == 0){
		printf("[ERRO] CPF ja invalido!\n");
		printf("Digite novamente o CPF do aluno: ");
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
void consultarInstrutor(){
	int i;
	
	if(TLI == 0){
		printf("Nenhum instrutor cadastrado!\n");
		
	}
	else{
		printf("\n----- Lista de instrutores -----\n");
		for(i = 0; i < TLI; i++){
			printf("Codigo: %d | Nome: %s\n", vCodInst[i],vInstrutor[i]);
		}
	}
}
void consultarAlunos(){
	int i;
	
	if(TLA == 0){
		printf("Nenhum aluno cadastrado!\n");
	}
	else{
		printf("\n----- Lista de alunos -----\n");
		for(i = 0; i < TLA; i++){
			printf("CPF: %s | Nome: %s | Dia de vencimento: %d | Valor do plano: %.2f", vCPFAluno[i], vNAluno[i], vDiaVenc[i], vValorPlano[i]);
		}
	}
}
void consultarAt(){
	int i;
	
	if(TLAT == 0){
		printf("Nenhum aluno cadastrado!\n");
	}
	else{
		printf("\n----- Lista de atividades -----\n");
		for(i = 0; i < TLAT; i++){
			printf("Codigo: %s | Atividade: %s | Valor: %.2f", vCodAt[i], vAtividade[i], vValorAt[i]);
		}
	}
}
void excluirInstrutor(){
	int i, codigo, pos;
	printf("\n ----- Excluir Instrutor -----\n");
	printf("Digite o codigo do instrutor: ");
	scanf("%d", &codigo);
	
	pos = buscaInstrutor(codigo);
	
	if(pos == 1){
		printf("\nInstrutor nao encontrado!\n");
	}
	else{
		for(i = 0; i < TLI - 1; i++){
			vCodInst[i] = vCodInst[i+1];
			strcpy(vInstrutor[i], vInstrutor[i+1]);
		}
		TLI--;
		printf("\nInstrutor excluido com sucesso!\n");
	}
}
void excluirAluno(){
	int i, pos;
	char cpf[15];
	
	printf("\n ----- Excluir Aluno -----\n");
	getchar();
	printf("Digite o CPF do aluno: ");
	gets(cpf);
	
	pos = buscaAluno(cpf);
	
	if(pos == 1){
		printf("\nAluno nao encontrado\n");
	}
	else{
		for(i = 0; i < TLA - 1; i++){
			strcpy(vCPFAluno[i], vCPFAluno[i+1]);
			strcpy(vNAluno[i], vNAluno[i+1]);
			vDiaVenc[i] = vDiaVenc[i+1];
			vValorPlano[i] = vValorPlano[i+1];
			
		}
		TLA--;
		printf("Aluno excluido com sucesso!\n");
	}
}
void excluirAt(){
	int i, codigo, pos;
	printf("\n ----- Excluir Atividade -----\n");
	printf("Digite o codigo da atividade: ");
	scanf("%d", &codigo);
	
	pos = buscaAt(codigo);
	
	if(pos == 1){
		printf("Atividade nao encontrada!\n");
	}
	else{
		for(i = 0; i < TLAT - 1; i++){
			vCodAt[i] = vCodAt[i+1];
			strcpy(vAtividade[i], vAtividade[i+1]);
			vValorAt[i] = vValorAt[i+1];
		}
		TLA--;
		printf("Atividade excluida com sucesso!\n");
	}
	
}
//Funcoes para o Menu
int menuPrincipal(){
	int opcao;
	
	printf("\n===================================\n");
    printf("        MENU PRINCIPAL\n");
    printf("===================================\n");
    printf("1 - Cadastro\n");
    printf("2 - Consulta\n");
    printf("3 - Excluir\n");
//  printf("4 - Avaliacao Fisica\n");
    printf("5 - Finalizar\n");
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
int menuConsulta(){
	int opcao;
	
	printf("\n ----- Consulta -----\n");
	printf("1 - Consultar instrutor\n");
	printf("2 - Consultar Aluno\n");
	printf("3 - Consultar Atividade\n");
	printf("4 - Retornar\n");
	printf("Escolha uma opcao: ");
	scanf("%d", opcao);
	
	return opcao;
}
int menuExclusao(){
	int opcao;
	
	printf("\n ----- Excluir -----\n");
	printf("1 - Excluir instrutor\n");
	printf("2 - Excluir Aluno\n");
	printf("3 - Excluir Atividade\n");
	printf("4 - Retornar\n");
	printf("Escolha uma opcao: ");
	scanf("%d", opcao);
	
	return opcao;
}
//int menuRelatorio(){
//	
//}

//C?digo Principal
int main(){
	int opcaoPrincipal, opcaoCadastro, opcaoConsulta, opcaoExclusao;
	
	opcaoPrincipal = menuPrincipal();
	
	while(opcaoPrincipal != 4){
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
		else if(opcaoPrincipal == 2){
			opcaoConsulta = menuConsulta();
			while(opcaoConsulta != 4){
				if(opcaoConsulta == 1){
					consultarInstrutor();
				}
				else if(opcaoConsulta == 2){
					consultarAlunos();
				}
				else if(opcaoConsulta == 3){
					consultarAt();
				}
				opcaoConsulta = menuConsulta();
			}
		}
		else if(opcaoPrincipal == 3){
			while(opcaoExclusao != 4){
				if(opcaoExclusao == 1){
					excluirInstrutor();
				}
				else if(opcaoExclusao == 2){
					excluirAluno();
				}
				else if(opcaoExclusao == 3){
					excluirAt();
				}
				opcaoExclusao = menuExclusao();
			}
		}
		opcaoPrincipal = menuPrincipal();
	}
	printf("\nPrograma Encerrado.\n");
}
