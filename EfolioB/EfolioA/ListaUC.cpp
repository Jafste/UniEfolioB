
#define dbUC "DbUC.txt" 
#include "ListaUC.h"
#include <string>
#include <fstream>

namespace std {
    ofstream fpUcOutPut;
    ifstream fpUcInput;

	ListaUC::ListaUC() {
		// TODO Auto-generated constructor stub

	}

	ListaUC::ListaUC(int n) {
		this->n = n;
		for (int i = 0; i < n; ++i) lUC.push_back(UC());
	}

	ListaUC::~ListaUC() {
		// TODO Auto-generated destructor stub
	}

	// Ordena os alunos segundo o número de matrícula
	void ListaUC::ordenaUC() {
		sort(lUC.begin(), lUC.end());
	}

	// Imprime a lista de alunos segundo a escolha de curso
	void ListaUC::imprimeUC(string c) {
		for (itUC = lUC.begin(); itUC != lUC.end(); itUC++) (*itUC).imprimeUC(c);
	}
    void ListaUC::imprimeUCPorId(string c) {
        for (itUC = lUC.begin(); itUC != lUC.end(); itUC++) (*itUC).imprimeUCPorId(c);
    }

    void ListaUC::imprimeUCId(string c) {
        for (itUC = lUC.begin(); itUC != lUC.end(); itUC++) (*itUC).imprimeUCId(c);
    }

	// Imprime a lista de alunos
	void ListaUC::imprimeUC() {
		for (itUC = lUC.begin(); itUC != lUC.end(); itUC++) (*itUC).imprimeUC();
	}

    void ListaUC::RegistaUC() {
        string idUC;
        cout << "Entre o Codigo da UC:" << endl;
        cin >> idUC;
        for (itUC = lUC.begin(); itUC != lUC.end(); itUC++)
        {
            if (!(*itUC).getidUC().compare(idUC)) {
                cout << "Este UC ja esta registado" << endl;
                return;
            }
        }

        lUC.push_back(UC(idUC));
    }

    int ListaUC::ExisteUC(string idUC) {

        for (itUC = lUC.begin(); itUC != lUC.end(); itUC++)
        {
            if (!(*itUC).getidUC().compare(idUC)) {
                return 1;
            }
        }
        return 0;
    }

    void ListaUC::Get_UC()
    {

        fpUcInput.open("DbUC.txt", ios::in);
        if (fpUcInput.fail())
            cerr << "Error Opening File" << endl;

        else
              while (!fpUcInput.eof())
            {
                string line;
                getline(fpUcInput, line);
                if (line != "")
                    FindDelimiter(line);
            }
        fpUcInput.close();
    }


    void ListaUC::FindDelimiter(string str)
    {

        vector<string> Uc;
        string delimiter = ">=";
        size_t pos = 0;
        string token;
        int i = 0;
        while ((pos = str.find(delimiter)) != std::string::npos)
        {
            Uc.push_back(str.substr(0, pos));
            str.erase(0, pos + delimiter.length());
            i++;
        }
        InsertUC(Uc);
    }

    void ListaUC::InsertUC(vector<string> Uc)
    {
        UC uc;

        uc.setidUC(Uc[0]);
        uc.setECTS(stoi(Uc[1]));
        uc.setNome((Uc[2]));
        uc.setCurso((Uc[3]));
        uc.setAno(stof(Uc[4]));
        uc.setSemestre(stof(Uc[5]));
        lUC.push_back(uc);
    }

    void ListaUC::WriteToFile()
    {
        string limiter = ">=";
        fpUcOutPut.open(dbUC, std::ios::out | std::ios::trunc);

        for (itUC = lUC.begin(); itUC != lUC.end(); itUC++)
        {
            fpUcOutPut << (*itUC).getidUC() + limiter + to_string((*itUC).getECTS()) + limiter + (*itUC).getNome() + limiter + (*itUC).getCurso() + limiter + to_string((*itUC).getAno()) + limiter + to_string((*itUC).getSemestre()) + limiter << endl;
        }
        fpUcOutPut.close();
    }
} /* namespace std */
