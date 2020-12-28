#ifndef LISTA_H_
#define LISTA_H_

#include "Alunos.h"

#include <list>
#include <vector>
#include <algorithm>

namespace std {

	class ListaAlunos {
	private:
		vector<Alunos> lAlunos;
		vector<Alunos>::iterator itAluno;
		int n;
	public:
		ListaAlunos();
		ListaAlunos(int);
		void registaAluno();
		void insertAluno(Alunos);
		virtual ~ListaAlunos();
		void ReadFile();
		float calculaMediaGlobal();
		void ordenaAlunos();
		void imprimeAlunos(string);
		void imprimeAlunoPorId(string c);
		int ExisteAluno(string c);
		void imprimeAlunos();
		void WriteToFileAlunos();
		void Get_Alunos();
		void FindDelimiter(string);
		void InsertAlunos(vector<string>);
	};

} /* namespace std */
#endif /* LISTA_H_ */
