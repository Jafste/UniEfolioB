#define dbAluno "DbAlunos.txt" 
#include "ListaAlunos.h"
#include <fstream>
#include <string>

namespace std {

    ofstream fpAlunoOutPut;
    ifstream fpAlunoInput;

	ListaAlunos::ListaAlunos() {
		// TODO Auto-generated constructor stub

	}

	ListaAlunos::ListaAlunos(int n) {
		this->n = n;
		for (int i = 0; i < n; ++i) lAlunos.push_back(Alunos());
	}

	ListaAlunos::~ListaAlunos() {
		// TODO Auto-generated destructor stub
	}

	void ListaAlunos::ReadFile() {		
	}

    void ListaAlunos::registaAluno() {
        string idAluno;
        cout << "Entre o numero do aluno:" << endl;
        cin >> idAluno;
        for (itAluno = lAlunos.begin(); itAluno != lAlunos.end(); itAluno++)
        {
            if (!(*itAluno).getId().compare(idAluno)) {
                cout << "Este aluno ja esta registado" << endl;
                return;
            }
        }
        lAlunos.push_back(Alunos(idAluno));
    }
	void ListaAlunos::insertAluno(Alunos aluno) {
		lAlunos.push_back(aluno);
	}

	// Calcula a média global da lista de alunos
	float ListaAlunos::calculaMediaGlobal() {
		float media = 0;
		for (itAluno = lAlunos.begin(); itAluno != lAlunos.end(); itAluno++)
		{
			media = media + (*itAluno).getNotaM();
		}

		return (media / n);
	}

	// Ordena os alunos segundo o número de matrícula
	void ListaAlunos::ordenaAlunos() {
		sort(lAlunos.begin(), lAlunos.end());
	}

	// Imprime a lista de alunos segundo a escolha de curso
	void ListaAlunos::imprimeAlunos(string c) {
		for (itAluno = lAlunos.begin(); itAluno != lAlunos.end(); itAluno++) (*itAluno).imprimeAluno(c);
	}
    void ListaAlunos::imprimeAlunoPorId(string c) {
        for (itAluno = lAlunos.begin(); itAluno != lAlunos.end(); itAluno++) (*itAluno).imprimeAlunoPorId(c);
    }

    int ListaAlunos::ExisteAluno(string c) {
        for (itAluno = lAlunos.begin(); itAluno != lAlunos.end(); itAluno++)
        {
            if (!(*itAluno).getId().compare(c)) {
                return 1;
            }
        }
        return 0;
    }

	// Imprime a lista de alunos
	void ListaAlunos::imprimeAlunos() {
		for (itAluno = lAlunos.begin(); itAluno != lAlunos.end(); itAluno++) (*itAluno).imprimeAluno();
	}

    void ListaAlunos::Get_Alunos()
    {

        fpAlunoInput.open(dbAluno, ios::in);
        if (fpAlunoInput.fail())
            cerr << "Error Opening File" << endl;

        else

            while (!fpAlunoInput.eof())
            {
                string line;
                getline(fpAlunoInput, line);
                if(line!="")
                    FindDelimiter(line);
            }
        fpAlunoInput.close();
    }


    void ListaAlunos::FindDelimiter(string str)
    {

        vector<string> Alunos;
        string delimiter = ">=";
        size_t pos = 0;
        string token;
        int i = 0;
        while ((pos = str.find(delimiter)) != std::string::npos)
        {
            Alunos.push_back(str.substr(0, pos));
            str.erase(0, pos + delimiter.length());
            i++;
        }
        InsertAlunos(Alunos);
    }

    void ListaAlunos::InsertAlunos(vector<string> Aluno)
    {
        Alunos aluno;

        aluno.setId(Aluno[0]);
        aluno.setNome(Aluno[1]);
        aluno.setNotaM(stoi(Aluno[2]));
        aluno.setCurso((Aluno[3]));
        aluno.setMatricula(stoi(Aluno[4]));
        lAlunos.push_back(aluno);
    }

    void ListaAlunos::WriteToFileAlunos()
    {
        fpAlunoOutPut.open(dbAluno);
        string limiter = ">=";
        for (itAluno = lAlunos.begin(); itAluno != lAlunos.end(); itAluno++)
        {
            fpAlunoOutPut << (*itAluno).getId() + limiter + (*itAluno).getNome() + limiter + to_string((*itAluno).getNotaM()) + limiter + (*itAluno).getCurso() + limiter + to_string((*itAluno).getMatricula()) + limiter << endl;
        }
         fpAlunoOutPut.close();
    }
} /* namespace std */
