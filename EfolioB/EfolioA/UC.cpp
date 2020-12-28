#include "UC.h"
#include <string>

namespace std {

	// Construtor personalizado
	UC::UC() {

	}

	// Construtor vazio
	UC::UC(string iUC) {
		idUC = iUC;
		cout << "Entre o nome da UC:" << endl;
		cin >> nome;
		cout << "Entre o nome do curso:" << endl;
		cin >> curso;
		cout << "Entre o n. de matricula:" << endl;
		cin >> ECTS;
		cout << "Entre o Ano " << endl;
		cin >> Ano;
		cout << "Entre o semestre " << endl;
		cin >> semestre;
	}

	UC::~UC() {
		// TODO Auto-generated destructor stub
	}

	// Imprime toda a lista de UC que faça o curso escolhido
	void UC::imprimeAlunoPorId(string c, int nota) {
		if (!c.compare(idUC)) {
			cout << nome+"                "+to_string(ECTS)+"                "+to_string(nota)<<endl;
			cout << "CURSO: " << curso << endl;
			cout << "ECTS: " << ECTS << endl;
			cout << "Ano: " << Ano << endl;
			cout << "Semestre: " << semestre << endl;
		}
	}

	void UC::imprimeUC(string c) {
		if (!c.compare(curso)) {
			cout << "Cod Curso" << idUC << endl;
			cout << "NOME: " << nome << endl;
			cout << "CURSO: " << curso << endl;
			cout << "ECTS: " << ECTS << endl;
			cout << "Ano: " << Ano << endl;
			cout << "Semestre: " << semestre << endl;
		}
	}


	void UC::imprimeUCPorId(string c) {
		if (!c.compare(idUC)) {
			
			cout << "UNIDADE CURRICULAR: " << nome << endl;
		}
	}

	void UC::imprimeUCId(string c) {
		if (!c.compare(idUC)) {
			cout << nome + "                 " + to_string(ECTS);
		}
	}

	// Imprime toda a lista de UC
	void UC::imprimeUC() {
		cout << "Cod Curso" << idUC << endl;
		cout << "NOME: " << nome << endl;
		cout << "CURSO: " << curso << endl;
		cout << "Ano: " << Ano << endl;
		cout << "Semestre: " << semestre << endl;
	}

} /* namespace std */
