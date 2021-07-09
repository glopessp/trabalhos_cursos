#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
struct regProjeto
{
	int codigo;
	char titulo[20];
	char descricao[200];
	int ano;
	int status;
	char gerente[20];
	int urgente;
	char requisitos[200];
	char prazoFinal[11];
};
struct regProjeto projeto[200]; 
int totProjeto = 0;
void cadastrarProjeto()
{
	projeto[totProjeto].codigo = totProjeto+1;
	printf("Cadastrando projeto #%d\n", projeto[totProjeto].codigo);
	printf("Insira do t�tulo do projeto: \n");
	gets(projeto[totProjeto].titulo);
	fflush(stdin);
	printf("Insira a descri��o do projeto: \n");
	gets(projeto[totProjeto].descricao);
	fflush(stdin);
	printf("Insira o ano do projeto: \n");
	scanf("%d", &projeto[totProjeto].ano);
	fflush(stdin);
	printf("Insira o status do projeto: \n1-A FAZER 2-FAZENDO 3-CONCLU�DO\n");
	scanf("%d", &projeto[totProjeto].status);
	fflush(stdin);
	printf("Insira o gerente respons�vel: \n");
	gets(projeto[totProjeto].gerente);
	fflush(stdin);
	printf("Projeto � urgente? 1-SIM 0-N�O\n");
	scanf("%d", &projeto[totProjeto].urgente);
	fflush(stdin);
	printf("Insira os requisitos do projeto: \n");
	gets(projeto[totProjeto].requisitos);
	fflush(stdin);
	printf("Insira o prazo final do projeto no formato DD/MM/AAAA \n");
	scanf("%s", &projeto[totProjeto].prazoFinal);
	fflush(stdin);
	printf("Projeto cadastrado com sucesso! \n");
}
void listarProjeto(int x)
{
	printf("=======================================\n");
	printf("C�digo: %d\n", projeto[x].codigo);
	printf("T�tulo: %s\n", projeto[x].titulo);
	printf("Descri��o: %s\n", projeto[x].descricao);
	printf("Ano: %d\n", projeto[x].ano);
	if (projeto[x].status == 1)
	{
		printf("Status: A fazer\n");
	}
	if (projeto[x].status == 2)
	{
		printf("Status: Fazendo\n");
	}
	if (projeto[x].status == 3)
	{ 
		printf("Status: Conclu�do\n");
	}
	printf("Gerente: %s\n", projeto[x].gerente);
	if (projeto[x].urgente == 1)
	{
		printf("Urgente: SIM\n");
	}
	if (projeto[x].urgente == 0)
	{
		printf("Urgente: N�O\n");
	}
	printf("Requisitos: %s\n", projeto[x].requisitos);
	printf("Prazo Final: %s\n", projeto[x].prazoFinal);
	printf("=======================================\n");
}
void menu()
{
	printf("=======================================\n");
	printf("|  BEM-VINDO AO CADASTRO DE PROJETOS  |\n");
	printf("=======================================\n");
	printf("|    Digite a op��o desejada:         |\n");
	printf("|    1-CADASTRAR PROJETOS             |\n");
	printf("|    2-LISTAR TODOS OS PROJETOS       |\n");
	printf("|    3-LISTAR PROJETOS \"A FAZER\"      |\n");
	printf("|    4-LISTAR PROJETOS \"FAZENDO\"      |\n");
	printf("|    5-LISTAR PROJETOS \"CONCLU�DO\"    |\n");
	printf("|    6-BUSCAR POR C�DIGO              |\n"); 
	printf("|    7-SAIR                           |\n"); 
	printf("=======================================\n");
}
int main()
{
	setlocale(LC_ALL, "Portuguese");
	int escolhaMenu, i, cod, achou = 0;
	char resp = 's';
	menu();
	scanf("%d",&escolhaMenu);
	fflush(stdin);
	switch (escolhaMenu)
	{
		case 1:
			while (resp == 's' && totProjeto < 200)
			{
				system("cls");
				cadastrarProjeto();
				totProjeto = totProjeto+1;
				printf("Deseja cadastrar mais projetos? s/n ");
				scanf("%c", &resp);
				fflush(stdin);
			}
			system("cls");
			main();
			break;	
		case 2:
			system("cls");
			for(i=0;i<totProjeto;i++)
			{
				listarProjeto(i);
			}
			system("pause");
			system("cls");
			main();
			break ;                      
		case 3:
			system("cls");
			for(i=0;i<totProjeto;i++)
			{
				if (projeto[i].status == 1)
				{
					listarProjeto(i);
				}
			}
			system("pause");
			system("cls");
			main();
			break;
		case 4: 
		    system("cls");
			for(i=0;i<totProjeto;i++)
			{
				if (projeto[i].status == 2)
				{
					listarProjeto(i);
				}
			}
			system("pause");
			system("cls");
			main();
			break;
		case 5: 
			system("cls");
			for(i=0;i<totProjeto;i++)
			{
				if (projeto[i].status == 3)
				{
					listarProjeto(i);
				}
			}
			system("pause");
			system("cls");
			main();
			break;
		case 6:
			system("cls");
			printf("Digite o c�digo do projeto: ");
			scanf("%d", &cod);
			fflush(stdin);
			for(i=0;i<totProjeto;i++)
			{
				if (projeto[i].codigo == cod)
				{
					listarProjeto(i);
					achou = 1;
				}
			}
			if (achou == 0)
			{ 
			printf("C�digo n�o encontrado.\n");
			}
			system("pause");
			system("cls");
			main();
			break;
		case 7:
			exit(0);
		default:
			printf("Op��o inv�lida.\n");
			break;
	}
	return(0);
}

