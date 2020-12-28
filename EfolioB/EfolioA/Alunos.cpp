
#include "Alunos.h"

namespace std {

	// Construtor personalizado

	// Construtor vazio
	Alunos::Alunos() {
		
	}

	Alunos::Alunos(string naluno) {
		idAluno = naluno;
		cout << "Entre o nome do aluno:" << endl;
		cin >> nome;
		cout << "Entre o nome do curso:" << endl;
		cin >> curso;
		cout << "Entre o ano de matr�cula:" << endl;
		cin >> nMatr;
		
		notaM = 0;
	}

	Alunos::~Alunos() {
		// TODO Auto-generated destructor stub
	}

	// Imprime toda a lista de alunos que faça o curso escolhido
	void Alunos::imprimeAluno(string c) {
		if (!c.compare(curso)) {
			cout << "NOME: " << nome << endl;
			cout << "CURSO: " << curso << endl;
			cout << "MATRICULA: " << nMatr << endl;
		}
	}

	void Alunos::imprimeAlunoPorId(string c) {
		if (!c.compare(idAluno)) {
			cout << "ALUNO: " << nome << endl;
		}
	}

	// Imprime toda a lista de alunos
	void Alunos::imprimeAluno() {
		cout << "NOME: " << nome << endl;
		cout << "CURSO: " << curso << endl;
		cout << "MATRICULA: " << nMatr << endl;
		cout << "NOTA MÉDIA: " << notaM << endl;
	}

} /* namespace std */
