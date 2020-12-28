#include "UCAluno.h"
#include <string>

namespace std {

	// Construtor personalizado
	UCAluno::UCAluno() {

	}

	UCAluno::~UCAluno() {

	}

	// Construtor vazio
	UCAluno::UCAluno(string aluno, string uc) {
		string modl="";
		idUC = uc;
		idAluno = aluno;
		idUCAluno = idUC + idAluno;
		Nota = -1;
		efolios = -1;
		qtdEfoliosAvaliados = 0;
		provaEscrita = -1;
		exame = -1;
		
		
		//notas são iniciadas a 0 podem ser double mas a nota final é sempre int
		
			while (modl != "0" || modl != "1") {
				cout << "Escolha da Modalidade do Aluno:"
					<< "[0] - Avaliacao Continua.\n"
					<< "[1] - Avalicao Por Exame." << endl;
				cin >> modl;
				if (Nota < 0 || Nota>20)
					cout << "Modalidade inválida, insira novamente" << endl;
			}
			modalidade = stoi(modl);
	}


} /* namespace std */
