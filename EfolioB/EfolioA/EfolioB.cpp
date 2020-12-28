
#include <iostream>
#include "ListaAlunos.h"
#include "ListaUCAluno.h"
#include "ListaUC.h"
#include "EfolioB.h"

using namespace std;


string n;
string input;
int choice;
ListaAlunos lAlunos;
ListaUC lUC;
ListaUCAluno lUCAluno;

void getEverything() {
	lAlunos.Get_Alunos();
	lUC.Get_UC();
	lUCAluno.Get_UCAlunos();
}
int main();
int MenuInicial();

int MenuInserir() {

	string n;
	string input;
	int choice;

	do
	{
		cout << endl << endl << endl
			<< " 1 - Registar Aluno\n"
			<< " 2 - Registar UC.\n"
			<< " 3 - Registar Nota Aluno.\n"
			<< "0. Voltar\n"
			<< " 99 - Exit.\n"
			<< " Faça a sua escolha e prima Enter ";
		cin >> choice;
		cout << endl << endl << endl;
		switch (choice)
		{
		case 0:
			MenuInicial();
			break;
		case 1:
			lAlunos.registaAluno();
			break;
		case 2:
			lUC.RegistaUC();
			break;
			/*case 3:
				lUCAluno.VerificaSeExiste(lAlunos, lUC);
				break;*/
		case 3:
			lUCAluno.RegistaUcAluno();
			break;
		case 99:
			break;
		default:
			cout << "Opcao Invalida. \n"
				<< "Tente Novamente.\n";
			break;
		}

	} while (choice != 99);
	return 0;
}

int MenuAvaliarAluno() {
	string n;
	string input;
	int choice;

	do
	{
		cout << endl << endl << endl
			<< "1. Avaliar Efolios\n"
			<< "2. Avaliar ProvaEscrita"
			<< "3. Avaliar Exame\n"
			<< "0. Voltar\n"
			<< "Faça a sua escolha e prima Enter ";
		cin >> choice;
		cout << endl << endl << endl;
		switch (choice)
		{
		case 0:
			MenuInicial();
			break;
		case 1:
			lUCAluno.AvaliaAlunoEfolios();
			break;
		case 2:
			lUCAluno.AvaliaAlunoProvaEscrita();
			break;
		case 3:
			lUCAluno.AvaliaAlunoExame();
			break;
		case 99:
			return 0;
			break;
		default:
			cout << "Opcao Invalida. \n"
				<< "Tente Novamente.\n";
			break;
		}

	} while (choice != 99);
	return 0;
}


int MenuAlterar() {
	string n;
	string input;
	int choice;

	do
	{
		cout << endl << endl << endl
			<< "1. Alterar Registos Aluno\n"
			<< "2. Alterar Registos UCS\n"
			<< "3. Alterar Registos UC Aluno"
			<< "4. Avaliar Aluno\n"
			<< "0. Voltar\n"
			<< "Faça a sua escolha e prima Enter ";
		cin >> choice;
		cout << endl << endl << endl;
		switch (choice)
		{
		case 0:
			MenuInicial();
			break;
		case 1:
			lAlunos.registaAluno();
			break;
		case 2:
			lUC.RegistaUC();
			break;
			/*case 3:
				lUCAluno.VerificaSeExiste(lAlunos, lUC);
				break;*/
		case 3:
			//lUCAluno.VerificaSeExiste(lAlunos, lUC);
			break;
		case 4:
			MenuAvaliarAluno();
			break;
		case 99:
			return 0;
			break;
		default:
			cout << "Opcao Invalida. \n"
				<< "Tente Novamente.\n";
			break;
		}

	} while (choice != 99);
	return 0;
}



int MenuListarRegistos() {
	string n;
	string input;
	int choice;

	do
	{
		cout << endl << endl << endl
			<< "1. Imprime Alunos\n"
			<< "2. ImprimeUCs"
			<< "3. Imprime Aprovacao UC por Aluno\n"
			<< "4. Imprime lunos aprovados por UC\n"
			<< "5. Imprime Total Media Aluno\n"
			<< "99. Voltar\n"
			<< "Faça a sua escolha e prima Enter ";
		cin >> choice;
		cout << endl << endl << endl;
		switch (choice)
		{
		case 0:
			MenuInicial();
			break;
		case 1:
			lAlunos.imprimeAlunos();
			break;
		case 2:
			lUC.imprimeUC();
			break;
		case 3:
			cout << "Insira o numero do aluno " << endl;
			cin >> input;
			lUCAluno.imprimeUCAlunos(input);
			break;
		case 4:
			cout << "Insira o codigo da UC " << endl;
			cin >> input;
			lUCAluno.imprimeUCAprovados(input);
			break;
		case 99:
			return 0;
			break;
		default:
			cout << "Opcao Invalida. \n"
				<< "Tente Novamente.\n";
			break;
		}

	} while (choice != 99);
	return 0;
}

int MenuInicial() {
	do
	{
		cout << endl << endl << endl
			<< "1. Inserir Registos Aluno - UC - UC Aluno\n"
			<< "2. Avaliar Aluno\n"
			<< "3. Apagar registos\n"
			<< "4. Listar registos\n"
			<< "6. Pesquisar Registos\n"
			<< " 7 - Gravar Listas nos Ficheiros.\n"
			<< " 99 - Exit.\n"
			<< " Enter your choice and press return: " << endl;
		cin >> choice;
		cout << endl << endl << endl;
		switch (choice)
		{
		case 0:
			break;
		case 1:
			MenuInserir();
			break;
		case 2:
			MenuAvaliarAluno();
			break;
		case 3:
			//lUCAluno.VerificaSeExiste(lAlunos, lUC);
			break;
		case 4:
			MenuListarRegistos();
			break;
		case 5:
			lUC.imprimeUC();
			break;
		case 6:
			cout << "Insira o cod aluno que quer verificar" << endl;
			cin >> input;
			lUCAluno.imprimeUCAlunos(input);
			break;
		case 7:
			cout << "Insira o cod UC que quer verificar" << endl;
			cin >> input;
			lUCAluno.imprimeUCAprovados(input);
		case 8:
			lAlunos.WriteToFileAlunos();
			lUC.WriteToFile();
			lUCAluno.WriteToFile();
			break;
		case 99:
			cout << "Fim do Programa.\n";
			return 0;
			break;
		default:
			cout << "Opcao Invalida. \n"
				<< "Tente Novamente.\n";
			break;
		}

	} while (choice != 99);
}

int main() {
	getEverything();
	lUCAluno.lAlunos = lAlunos;
	lUCAluno.lUC = lUC;

	MenuInicial();
	return 0;
	
}








