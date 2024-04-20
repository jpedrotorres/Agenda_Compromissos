#include <stdio.h>
#define nDiasAno 366
#define nMeses 12

void printMenu();
void estruturaCalendario();
void mostraCalendario(int diaSemana, int diaMeses[], int diasAno[]);
void calendarioAgendamento(int agendamentos[], int tam);
int inserirAgendamento(int agendamentos[], int diaMeses[]);

int main() {
	int opcMenu, diaSemana, agendamentos[nDiasAno], diasAno[nDiasAno];
	int diaMeses[nMeses] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char anoBisexto;

	for(int i=0; i<nDiasAno; i++) agendamentos[i] = 0;

	printf("Bem vindo ao sistema de agendamento ASM\n\n");//Agendamento Super Moderno
	printf("Antes de iniciarmos, por favor informe as solicitações abaixo.\n");
	printf("\nPara responder o item a seguir, considere:\nDomingo- 1;\nSegunda- 2;\nTerça- 3;\nQuarta- 4;\nQuinta- 5;\nSexta- 6;\nSábado- 7.\n\n");

	printf("Em que dia da semana cai 1º de janeiro? ");
	scanf("%d", &diaSemana);

	printf("O ano em questão é bisexto?(s/n) ");
	__fpurge(stdin);
	scanf("%c", &anoBisexto);

	if (anoBisexto == 's' || anoBisexto == 'S') diaMeses[1]= 29;

	do {
		printMenu();

		printf("Digite sua opção: ");
		scanf("%d", &opcMenu);

		switch(opcMenu) {
			case 1:
				mostraCalendario(diaSemana, diaMeses, diasAno);
				break;

			case 2:
				inserirAgendamento(agendamentos, diaMeses);
				break;

			case 3:
				estruturaCalendario(diaSemana, diaMeses, agendamentos);
				break;

			case 4:
				printf("\nAté logo!\n");
				break;

			default:
				printf("Opção inválida. Por favor, selecione a opção corretamente\n");
		}

	} while(opcMenu != 4);

	return 0;
}

void printMenu() {
	printf("-----------------------------------------\n");
	printf("|		Menu ASM		|\n");
	printf("-----------------------------------------\n");
	printf("|	(1) Mostrar calendário		|\n");
	printf("|	(2) Inserir agendamento		|\n");
	printf("|	(3) Calendário com agendamentos	|\n");
	printf("|	(4) Sair			|\n");
	printf("-----------------------------------------\n");
}

void estruturaCalendario(int diaSemana, int diaMeses[], int vetorMostrar[]) {
	char nomeMes[nMeses][9]= {{"Janeiro"}, {"Fevereiro"}, {"Março"}, {"Abril"}, {"Maio"}, {"Junho"}, {"Julho"}, {"Agosto"}, {"Setembro"}, {"Outubro"}, {"Novembro"}, {"Dezembro"}};
	int i, quebraLinha, varAux= 0;

	quebraLinha= diaSemana-1;

	for(int j= 0; j<nMeses; j++) {
		printf("\t%s\n", nomeMes[j]);

		printf("	dom	seg	ter	qua	qui	sex	sab\n");

		for(i=0; i<diaSemana; i++) printf("\t");

		for(i=0; i<diaMeses[j]; i++) {
			quebraLinha++;

			printf("%02d\t", vetorMostrar[varAux]);

			if(quebraLinha == 7) {
				printf("\n\t");
				quebraLinha= 0;
			}

			varAux++;
		}

		diaSemana= quebraLinha+1;

		printf("\n\n");
	}
}

void mostraCalendario(int diaSemana, int diaMeses[], int diasAno[]) {
	int varAux=0;

	for(int j=0; j<nMeses; j++) {
		for(int i=0; i< diaMeses[j]; i++) {
			diasAno[varAux]= i+1;

			varAux++;
		}
	}

	estruturaCalendario(diaSemana, diaMeses, diasAno);
}

void calendarioAgendamento(int agendamentos[], int tam) {
	for(int i=0; i<tam; i++) printf("%d ", agendamentos[i]);

	printf("\n\n");
}

int inserirAgendamento(int agendamentos[], int diaMeses[]) {
	int diaInicio, mesInicio, duracaoTratamento, varAux=0;

	printf("Digite o dia do mês que pretende iniciar o tratamento: ");
	scanf("%d", &diaInicio);

	printf("Digite o mês (em número) que iniciará o tratamento (ex: 3, para representar março): ");
	scanf("%d", &mesInicio);

	printf("Digite a duração (em dias) que o tratamento durará: ");
	scanf("%d", &duracaoTratamento);

	if(mesInicio -1 !=0) {
		for (int i=0; i< (mesInicio -1); i++) {
			varAux+= diaMeses[i];
		}

		varAux+= diaInicio -1;
	}

	else varAux= diaInicio -1;

	for(int i=0; i< duracaoTratamento; i++) {
		if(agendamentos[varAux] == 5) {
			printf("Não foi possível agendar a consulta para um dos dias selecionados\n");
		}

		else agendamentos[varAux]++;

		varAux++;
	}

	return 0;
}
