#include <stdio.h>
#include <stdlib.h>

#define nDiasAno 366
#define nMeses 12
#define maxAgendamento 5

void printMenu();
void printInformacaoInicial();
void estruturaCalendario();
void mostraCalendario(int diaSemana, int diaMeses[], int diasAno[]);
int inserirAgendamento(int agendamentos[], int diaMeses[]);

int main() {
/*
        Função principal, na qual será interpretada pelo compilador. Lê do
        usuário o dia da semana que cai o primeiro dia do ano em questão e
        armazena na variável diaSemana e pergunta se o ano é bisexto ou não,
        e armazena na váriável anoBisexto. Esses dados são para a criação do
        calendário, que poderá ser usado pelas funções mostraCalendario ou
        estruturaCalendario. Ainda, aqui é alocado uma parte da memória,
        estaticamente, para armazenar os vetores que contém os dias do ano e
        os agendamentos de cada dia. Nesta função contém um looping de menu
        para o usuário escolher a opção que deseja acessar.
*/

	int opcMenu, diaSemana, agendamentos[nDiasAno], diasAno[nDiasAno];
	int diaMeses[nMeses] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char anoBisexto;

	for(int i=0; i<nDiasAno; i++) agendamentos[i] = 0;

	system("clear");

	printf("Bem vindo ao sistema de agendamento ASM\n\n");//Agendamento Super Moderno

	printInformacaoInicial();

	printf("Em que dia da semana cai 1º de janeiro? ");
	scanf("%d", &diaSemana);

	printf("O ano em questão é bisexto?(s/n) ");
	__fpurge(stdin);
	scanf("%c", &anoBisexto);

	if (anoBisexto == 's' || anoBisexto == 'S') diaMeses[1]= 29;

	system("clear");

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
				system("clear");
				break;

			case 5:
				printf("\nAté logo!\n");
				break;

			default:
				printf("Opção inválida. Por favor, selecione a opção corretamente\n");
		}

	} while(opcMenu != 5);

	return 0;
}

void printMenu() {
/*
        Função responsável apenas por printar o menu na tela, assim que chamado.
        Por definição, a função mostrará as opções: mostrar o calendário, ou seja,
        calendário do ano atual, com os dias e semanas dos meses; inserir
        agendamento, ou seja, opção para o usuário inserir o agendamento do cliente;
        calendário com agendamentos, ou seja, a estrutura do calendário porém com as
        informações da quantidade de agendamentos que determinado dia possui; e
        por fim, a opção para sair e encerrar a operação.
*/

	printf("-----------------------------------------\n");
	printf("|		Menu ASM		|\n");
	printf("-----------------------------------------\n");
	printf("|	(1) Mostrar calendário		|\n");
	printf("|	(2) Inserir agendamento		|\n");
	printf("|	(3) Calendário com agendamentos	|\n");
	printf("|	(4) Limpar a tela		|\n");
	printf("|	(5) Sair			|\n");
	printf("-----------------------------------------\n");
}

void printInformacaoInicial() {
/*
	Função responsável por mostrar na tela do usuário uma tabela para auxilia-lo
	a responder sobre o dia da semana. Nota-se que nessa etapa, uma solução mais
	natural seria ler do usuário a palavra (string) que corresponde ao dia
	solicitado, porém, preferiu-se utilizar uma representação numérica para
	facilitar o código.
*/
	printf("Antes de iniciarmos, por favor informe as solicitações abaixo.\n\n");

	printf("Para continuar, considere:\n");
	printf("---------------------------------\n");
	printf("|	(1) Domingo 		|\n");
	printf("|	(2) Segunda-feira	|\n");
	printf("|	(3) Terça-feira		|\n");
	printf("|	(4) Quarta-feira	|\n");
	printf("|	(5) Quinta-feira	|\n");
	printf("|	(6) Sexta-feira		|\n");
	printf("|	(7) Sábado		|\n");
	printf("---------------------------------\n\n");
}

void estruturaCalendario(int diaSemana, int diaMeses[], int vetorMostrar[]) {
/*
        Função responsável por criar e estruturar um calendário, ou seja, dar o
        formato visual adequado e mostrar na tela o resultado, assim que chamado.
        A função poderá mostrar o calendário normal, com os dias de cada mes, ou
        o calendário com agendamentos, com o número de agendamentos que o usuário
        possui em determinado dia. Nesta função é criado um vetor de strings para
        armazenar o nome de cada mês (usado para imprimir os calendários). Também
        são criados três variáveis do tipo inteiro para servir como contadores e
        auxiliar no desenvolvimento das funcionalidades. Parâmetros:
        diaSemana- inteiro que contém o dia da semana, dada em número (1-domingo,
        2-segunda, entre outros), para auxiliar na criação do calendário;
        diaMeses- vetor de inteiros que armazena em cada posição a quantidade de
        dias que um determinado mês possui;
        vetorMostrar- vetor de inteiros que será interpretado pelo função e fará
        parte do calendário a ser imprimido. O parâmetro pode ser um vetor que
        contêm os dias do ano (para quando for solicitado mostrar o calendário) ou
        um vetor que contém a quantidade de agendamentos de cada dia (para quando
        for solicitado mostrar o calendário de agendamentos).
*/

	char nomeMes[nMeses][9]= {{"Janeiro"}, {"Fevereiro"}, {"Março"}, {"Abril"}, {"Maio"}, {"Junho"}, {"Julho"}, {"Agosto"}, {"Setembro"}, {"Outubro"}, {"Novembro"}, {"Dezembro"}};
	int i, quebraLinha, varAux= 0;

	quebraLinha= diaSemana-1;

	for(int j= 0; j<nMeses; j++) {
		printf("\n\t%s\n", nomeMes[j]);

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
/*
        Função intermediária para mostrar na tela o calendário de dias do ano.
        Essa função é responsável por armazenar os dias do ano em um vetor
        dado, ou seja, na posição zero terá o número 1, na posição 1, o número
        2, na posição 31, terá o número 1, e assim sucessivamente. Após
        armazenar os dias do ano no vetor, essa função chama a outra função
        estruturaCalendario, para assim, mostrar na tela o calendário normal.
        Aqui, é criada a variável varAux, do tipo inteiro que se inicia em zero,
        para auxiliar no desenvolvimento das funcionalidades. mostraCalendario
        recebe como parâmetros:
        diaSemana- inteiro que contém o dia da semana, dada em número, para
        auxiliar na criação do calendário. Esse parâmetro não é utilizado na
        função, mas é necessário para ser usado como parâmetro de outra função;
        diaMeses- vetor de inteiros que armazena em cada posição a quantidade de
        dias que um determinado mês possui;
        diasAno- vetor de inteiros que irá armazenar os dias do ano. Esse vetor
        é passado vazio e durante a execução, será modificado e preenchido.
*/

	int varAux=0;

	for(int j=0; j<nMeses; j++) {
		for(int i=0; i< diaMeses[j]; i++) {
			diasAno[varAux]= i+1;

			varAux++;
		}
	}

	estruturaCalendario(diaSemana, diaMeses, diasAno);
}

int inserirAgendamento(int agendamentos[], int diaMeses[]) {
/*
        Função responsável por inserir os agendamentos no vetor que armazena a
        contagem de trabalhos em um dia. Essa, leva em consideração que o cliente
        só atua em no máximo 5 trabalhos por dia, portanto, caso em um certo dia já
        tenha completado o número máximo, a função mostrará na tela uma mensagem de
        erro ao tentar encaixar um horário e tentará encaixar no próximo dia que há
        um espaço. Durante a execução, a função solicita ao usuário o dia que
        pretende iniciar o tratamento, o mês (dado em número) e a duração (dada em
        número de dias). Também é criada a variável do tipo inteiro varAux para
        servir de contador e auxiliar no desenvolvimento da função. Parâmetros:
        agendamentos- vetor de inteiros que irá receber a quantidade de agendamentos
        de um dia, assumindo que cada posição do vetor corresponde a um dia do ano;
        diaMeses- vetor de inteiros que armazena em cada posição a quantidade de
        dias que um determinado mês possui.
*/

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
		if(agendamentos[varAux] == maxAgendamento) {
			printf("Não foi possível agendar a consulta para um dos dias selecionados\n");
		}

		else agendamentos[varAux]++;

		varAux++;
	}

	return 0;
}
