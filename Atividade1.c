#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Portuguese");
	float salario, salarioFinal, reajuste, abono;
	int verificaAbono;

	printf("=========== SILPH.CO ===========\n|        Gustavo Lopes         |\n|        RA: 20140509-5        |\n================================\n");
	printf("  Digite o sal�rio l�quido: \n     R$");
	scanf("%f", &salario);
	#define abono 150.00
	reajuste = (salario/100)*7.5;
	salarioFinal = salario + reajuste;
	
	if (salarioFinal <= 1750) {
		salarioFinal = salarioFinal + abono;
		verificaAbono = 1;
	}
	else {
		verificaAbono = 0;
	}
	
	printf("================================\n");
	printf(" Sal�rio informado: R$%.2f\n Sal�rio reajustado: R$%.2f\n", salario, salarioFinal);
	if (verificaAbono == 1) {
		printf(" Recebe abono: SIM\n");
	}
	else {
		printf(" Recebe abono: N�O\n");
	}
	printf("================================\n");
		
}
