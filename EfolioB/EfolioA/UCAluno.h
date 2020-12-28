
#ifndef UCAluno_H_
#define UCAluno_H_

#include <iostream>
#include <string>

namespace std {

	class UCAluno {
		//podia ficar ECTS e nome em UC mas facilita assim
	private:
		string idUCAluno;
		string idAluno;
		string idUC;
		int ECTS;
		int Nota;
		double efolios;
		double provaEscrita;
		double exame;
		bool modalidade;
		int qtdEfoliosAvaliados;
	public:
		UCAluno();
		UCAluno(string aluno, string uc);
		virtual ~UCAluno();
		string getIdUcAluno() const { return idUCAluno; };
		string getIdIdUC() const { return idUC; };
		string getIdAluno() const { return idAluno; };

		string getEfolios() { if(modalidade) return to_string(efolios); else return "Aluno encontra-se em Modalidade normal"; };
		string getProvaEscrita() { if (modalidade) return to_string(provaEscrita); else return "Aluno encontra-se em Modalidade normal"; };
		string getExame() { if (!modalidade) return to_string(exame); else return "Aluno encontra-se em Modalidade normal"; };
		string getQtdEfoliosAvaliados() { if (!modalidade) return to_string(qtdEfoliosAvaliados); else return "Aluno encontra-se em Modalidade normal"; };
		
		bool getModalidade() { return modalidade; }
		int getNota() { return Nota; };
		int getECTS() const { return ECTS; };


		void setIdUCAluno(string m) { idUCAluno = m; };
		void setIdAluno(string m) { idAluno = m; };
		void setIdUC(string m) { idUC = m; };
		void setNota(int n) { Nota = n; };
		void setECTS(int m) { ECTS = m; };

		void setEfolios(double m) { efolios = m; }
		void setQtdEfoliosAvaliados(int m) { qtdEfoliosAvaliados = m; }
		void setProvaEscrita(double m) { provaEscrita = m; }
		void setExame(double m) { exame = m; }
		void setModalidade(bool m) { modalidade = m; }
		
		// Operador para ser utilizado pelo método sort no vector
		bool operator < (const UCAluno& a) const { return (idUCAluno < a.idUCAluno); };
	};

} /* namespace std */
#endif /* UCUCAluno_H_ */
