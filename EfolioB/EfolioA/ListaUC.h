
#ifndef LISTA_H_UC
#define LISTA_H_UC

#include "UC.h"
#include <list>
#include <vector>
#include <algorithm>
#include "UCAluno.h"

namespace std {

	class ListaUC {
	private:
		vector<UC> lUC;
		vector<UC>::iterator itUC;
		int n;
	public:
		
		ListaUC();
		ListaUC(int);
		virtual ~ListaUC();
		void ordenaUC();
		void imprimeUC(string);
		void imprimeUCPorId(string c);
		void imprimeUCId(string c);
		void imprimeUC();
		void WriteToFile();
		void RegistaUC();
		int ExisteUC(string idUC);
		void Get_UC();
		void FindDelimiter(string);
		void InsertUC(vector<string>);
	};

} /* namespace std */
#endif /* LISTA_H_ */
