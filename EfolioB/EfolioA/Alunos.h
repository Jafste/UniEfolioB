#ifndef ALUNOS_H_
#define ALUNOS_H_

#include <iostream>

namespace std {

	class Alunos {
	private:
		string idAluno;
		string nome;
		int nMatr;
		string curso;
		int notaM;
	public:
		Alunos();
		Alunos(string naluno);
		virtual ~Alunos();
		void imprimeAluno(string);
		void imprimeAlunoPorId(string c);
		void imprimeAluno();
		int getMatricula() const { return nMatr; };
		string getId() const { return idAluno; };
		int getNotaM() { return notaM; };
		string getNome() { return nome; };
		string getCurso() { return curso; };
		void setId(string m) { idAluno = m; };
		void setMatricula(int m) { nMatr = m; };
		void setNotaM(int n) { notaM = n; };
		void setNome(string n) { nome = n; };
		void setCurso(string c) { curso = c; };
		// Operador para ser utilizado pelo método sort no vector
		bool operator < (const Alunos& a) const { return (nMatr < a.nMatr); };
	};

} /* namespace std */
#endif /* ALUNOS_H_ */
