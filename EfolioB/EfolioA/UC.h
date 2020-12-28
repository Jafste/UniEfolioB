
#ifndef UC_H_
#define UC_H_

#include <iostream>

namespace std {

	class UC {
	private:
		string idUC;
		string nome;
		int ECTS;
		string curso;
		int Ano;
		int semestre;
	public:
		UC();
		UC(int);
		UC(string iUC);
		virtual ~UC();
		void imprimeAlunoPorId(string c, int nota);
		void imprimeUC(string);
		void imprimeUCPorId(string c);
		void imprimeUCId(string c);
		void imprimeUC();
		int getECTS() const { return ECTS; };
		string getidUC() const { return idUC; };
		int getAno() { return Ano; };
		int getSemestre() { return semestre; };
		string getNome() { return nome; };
		string getCurso() { return curso; };
		void setidUC(string m) { idUC = m; };
		void setECTS(int m) { ECTS = m; };
		void setAno(int n) { Ano = n; };
		void setSemestre(int n) { semestre = n; };
		void setNome(string n) { nome = n; };
		void setCurso(string c) { curso = c; };
		// Operador para ser utilizado pelo método sort no vector
		bool operator < (const UC& a) const { return (ECTS < a.ECTS); };
	};

} /* namespace std */
#endif /* UC_H_ */
