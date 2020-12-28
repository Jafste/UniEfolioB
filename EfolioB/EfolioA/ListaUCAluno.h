
#ifndef LISTA_H_UCAluno
#define LISTA_H_UCAluno

#include "UCAluno.h"
#include <list>
#include <vector>
#include <algorithm>
#include "ListaUC.h"
#include "ListaAlunos.h"

namespace std {

	class ListaUCAluno {
	private:
		vector<UCAluno> lUCAluno;
		vector<UCAluno>::iterator itUCAluno;
		int n;
	public:
		ListaUC lUC;
		ListaAlunos lAlunos;
		ListaUCAluno();
		ListaUCAluno(int);
		void RegistaUcAluno();
		bool VerificaSeExisteAluno(string& nAluno, string& nUC);
		void AvaliaAlunoEfolios();

		void AvaliaAlunoEfolios(string nAluno, string nUC);
		
		void AvaliaAlunoProvaEscrita();
		void AvaliaAluno();
		void MelhoriaNota(string nAluno, string nUC, int nota);
		void AvaliaAlunoExame();
		void AtribuiNotaAluno(string nAluno, string nUC);
		void MelhoriaNota();
		virtual ~ListaUCAluno();
		float calculaMediaGlobal();
		void imprimeMaxMin();
		void ordenaUCAlunos();
		void imprimeUCAprovados(string idUC);
		void imprimeUCAlunos(string c);
		void imprimeTotalUCS(string c);
		void WriteToFile();
		void imprimeTotalECTS(string c);
		void imprimeTotalMediaAluno(string c);
		void Get_UCAlunos();
		void FindDelimiter(string);
		void InsertUCAlunos(vector<string>);
	};

} /* namespace std */
#endif /* LISTA_H_ */
