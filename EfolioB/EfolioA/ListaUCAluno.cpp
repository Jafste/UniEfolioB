#define dbUCAluno "DbUCAluno.txt" 
#include "ListaUCAluno.h"
#include <fstream>
#include <string>
#include "UC.h"
#include "ListaUC.h"
#include "ListaAlunos.h"

namespace std {

    ofstream fpUCAlunoOutPut;
    ifstream fpUCAlunoInput;
    ListaUCAluno::ListaUCAluno() {
        // TODO Auto-generated constructor stub

    }

    ListaUCAluno::ListaUCAluno(int n) {
        this->n = n;
        for (int i = 0; i < n; ++i) lUCAluno.push_back(UCAluno());
    }

    void ListaUCAluno::RegistaUcAluno() {
        string nAluno;
        string nUC;
        if (VerificaSeExisteAluno(nAluno, nUC))
            lUCAluno.push_back(UCAluno(nAluno, nUC));
    }

    bool ListaUCAluno::VerificaSeExisteAluno(string& nAluno, string& nUC) {
        cout << "entre o numero de Aluno" << endl;
        cin >> nAluno;
        cout << "entre o cod da UC" << endl;
        cin >> nUC;

        if (lAlunos.ExisteAluno(nAluno) == 0)
        {
            cout << "Este aluno nao existe" << endl;
            return false;
        }

        if (lUC.ExisteUC(nUC) == 0)
        {
            cout << "Este UC nao existe" << endl;
            return false;
        }

        for (itUCAluno = lUCAluno.begin(); itUCAluno != lUCAluno.end(); itUCAluno++)
        {
            if ((!nAluno.compare((*itUCAluno).getIdAluno()) && !nUC.compare((*itUCAluno).getIdIdUC())))
            {
                cout << "Este aluno ja tem nota a essa disciplina" << endl;
                return false;
            }
        }


        return true;
    }


    void ListaUCAluno::AvaliaAlunoEfolios() {
        string nAluno;
        string nUC;
        double nota;
        if (!VerificaSeExisteAluno(nAluno, nUC))
            return;

        for (itUCAluno = lUCAluno.begin(); itUCAluno != lUCAluno.end(); itUCAluno++)
        {
            if ((!nAluno.compare((*itUCAluno).getIdAluno()) && !nUC.compare((*itUCAluno).getIdIdUC())))
            {
                if ((*itUCAluno).getModalidade() == true) {
                    double notAtual = stod((*itUCAluno).getEfolios());
                    int qtdAvaliados = stoi((*itUCAluno).getQtdEfoliosAvaliados());
                    if (qtdAvaliados < 4) {


                        if (notAtual >= -1 || notAtual <= 8) {
                            if (notAtual == -1)
                                notAtual = 0;
                            cout << "Introduza a nota do Aluno" << endl;
                            cin >> nota;
                            double total = nota + notAtual;
                            while ((total <= 8 && total >= 0) || nota < 0)
                            {
                                total -= nota;
                                cout << "Nota inválida, introduza novamente | soma total: " + to_string(total) << endl;
                                cin >> nota;
                                total += nota;
                            }
                            qtdAvaliados++;
                            (*itUCAluno).setQtdEfoliosAvaliados(qtdAvaliados);
                            (*itUCAluno).setEfolios(nota);
                        }
                        else {
                            cout << "Aluno já avaliado!" << endl;
                            return;
                        }
                    }
                    else
                        cout << "Aluno já foi avaliado a 3 efolios!"<<endl;
                }
                else {
                    cout << "Aluno não se encontra na modalidade de avaliação continua" << endl;
                    return;
                }

            }
        }
    }

    void ListaUCAluno::AvaliaAlunoEfolios(string nAluno, string nUC) {
        
        double nota;
        if (!VerificaSeExisteAluno(nAluno, nUC))
            return;

        for (itUCAluno = lUCAluno.begin(); itUCAluno != lUCAluno.end(); itUCAluno++)
        {
            if ((!nAluno.compare((*itUCAluno).getIdAluno()) && !nUC.compare((*itUCAluno).getIdIdUC())))
            {
                if ((*itUCAluno).getModalidade() == true) {
                    double notAtual = stod((*itUCAluno).getEfolios());
                    int qtdAvaliados = stoi((*itUCAluno).getQtdEfoliosAvaliados());
                    if (qtdAvaliados < 4) {


                        if (notAtual >= -1 || notAtual <= 8) {
                            if (notAtual == -1)
                                notAtual = 0;
                            cout << "Introduza a nota do Aluno" << endl;
                            cin >> nota;
                            double total = nota + notAtual;
                            while ((total <= 8 && total >= 0) || nota < 0)
                            {
                                total -= nota;
                                cout << "Nota inválida, introduza novamente | soma total: " + to_string(total) << endl;
                                cin >> nota;
                                total += nota;
                            }
                            qtdAvaliados++;
                            (*itUCAluno).setQtdEfoliosAvaliados(qtdAvaliados);
                            (*itUCAluno).setEfolios(nota);
                        }
                        else {
                            cout << "Aluno já avaliado!" << endl;
                            return;
                        }
                    }
                    else
                        cout << "Aluno já foi avaliado a 3 efolios!" << endl;
                }
                else {
                    cout << "Aluno não se encontra na modalidade de avaliação continua" << endl;
                    return;
                }

            }
        }
    }

    void ListaUCAluno::AvaliaAlunoProvaEscrita() {
        string nAluno;
        string nUC;
        double nota;
        int choice;
        if (!VerificaSeExisteAluno(nAluno, nUC))
            return;

        for (itUCAluno = lUCAluno.begin(); itUCAluno != lUCAluno.end(); itUCAluno++)
        {
            if ((!nAluno.compare((*itUCAluno).getIdAluno()) && !nUC.compare((*itUCAluno).getIdIdUC())))
            {
                if ((*itUCAluno).getModalidade() == true) {
                    double notaEfolios = stoi((*itUCAluno).getEfolios());
                    if (notaEfolios >= 3.5) {
                        if (stoi((*itUCAluno).getProvaEscrita()) > 0) {
                            do
                            {
                                cout << endl << endl << endl;
                                cout << "Aluno já avaliado, é melhoria de nota!" << endl;
                                cout << "[1] - Melhoria de nota!" << endl;
                                cout << "[99] - Voltar ao menu;" << endl;
                                cout << "Faça a sua escolha e prima Enter ";
                                cin >> choice;
                                cout << endl << endl << endl;
                                switch (choice)
                                {
                                case 1:
                                    MelhoriaNota(nAluno,nUC,nota);
                                    break;
                                
                                case 99:
                                    return;
                                    break;
                                default:
                                    cout << "Opcao Invalida. \n"
                                        << "Tente Novamente.\n";
                                    break;
                                }

                            } while (choice != 99);
                        }
                        
                        else {
                            cout << "Introduza a nota do Aluno" << endl;
                            cin >> nota;
                            (*itUCAluno).setProvaEscrita(nota);
                            while (nota <0 || nota >12)
                            {
                                cout << "Nota inválida, introduza novamente."<< endl;
                                cin >> nota;
                            }
                            nota = round(notaEfolios + nota);
                            (*itUCAluno).setNota(nota);
                        }
                    }
                    else {
                        cout << "Aluno não têm o somatório suficiente dos Efolios para realizar a prova escrita!" << endl;
                        return;
                    }
                }

                else {
                    cout << "Aluno não se encontra na modalidade de avaliação continua" << endl;
                    return;
                }

            }
        }

    }

    void ListaUCAluno::AvaliaAluno() {
        string nAluno;
        string nUC;
        double nota;
        int choice;
        if (!VerificaSeExisteAluno(nAluno, nUC))
            return;

        for (itUCAluno = lUCAluno.begin(); itUCAluno != lUCAluno.end(); itUCAluno++)
        {
            if ((!nAluno.compare((*itUCAluno).getIdAluno()) && !nUC.compare((*itUCAluno).getIdIdUC())))
            {
                
                double notaEfolios = stoi((*itUCAluno).getEfolios());
                if (notaEfolios >= 3.5) {
                    if ((*itUCAluno).getNota()>=10) {
                        do
                        {
                            cout << endl << endl << endl;
                            cout << "Aluno já avaliado:" << endl;
                            cout << "[1] - Melhoria de nota!" << endl;
                            cout << "[99] - Voltar ao menu!" << endl;
                            cout << "Faça a sua escolha e prima Enter ";
                            cin >> choice;
                            cout << endl << endl << endl;
                            switch (choice)
                            {
                            case 1:
                                MelhoriaNota(nAluno,nUC,10);
                                break;

                            case 99:
                                return;
                                break;
                            default:
                                cout << "Opcao Invalida. \n"
                                    << "Tente Novamente.\n";
                                break;
                            }

                        } while (choice != 99);
                    }

                }
                
            }
        }

    }

    /*void ListaUCAluno::MelhoriaNota() {
        string nAluno;
        string nUC;
        int nota;
        if (!VerificaSeExisteAluno(nAluno, nUC))
            return;
        cout << "nota a ser introduzida" << endl;
        cin >> nota;
        for (itUCAluno = lUCAluno.begin(); itUCAluno != lUCAluno.end(); itUCAluno++)
        {
            if ((!nAluno.compare((*itUCAluno).getIdAluno()) && !nUC.compare((*itUCAluno).getIdIdUC())))
            {
                double notaEfolios = stoi((*itUCAluno).getEfolios());
                double notaAnt = ((*itUCAluno).getNota());
                if ((*itUCAluno).getModalidade() == false && stod((*itUCAluno).getProvaEscrita()) >= 0) {
                    cout << "Introduza a nota do Aluno" << endl;
                    cin >> nota;
                    (*itUCAluno).setProvaEscrita(nota);
                    while (nota < 0 || nota >12)
                    {
                        cout << "Nota inválida, introduza novamente." << endl;
                        cin >> nota;
                    }
                    nota = round(notaEfolios + nota);
                    if (notaAnt < nota)
                        (*itUCAluno).setNota(nota);
                }

                else {
                    cout << "Aluno não se encontra na modalidade de Exame" << endl;
                    return;
                }
            }
        }
    }*/

    void ListaUCAluno::MelhoriaNota(string nAluno, string nUC, int nota) {

        for (itUCAluno = lUCAluno.begin(); itUCAluno != lUCAluno.end(); itUCAluno++)
        {
            if ((!nAluno.compare((*itUCAluno).getIdAluno()) && !nUC.compare((*itUCAluno).getIdIdUC())))
            {
                double notaEfolios = stoi((*itUCAluno).getEfolios());
                double notaAnt = ((*itUCAluno).getNota());

                if ((*itUCAluno).getModalidade() == true && stod((*itUCAluno).getProvaEscrita()) >= 0 && stod((*itUCAluno).getEfolios())>=0) {
                    int choice;
                    do
                    {
                        cout << endl << endl << endl;
                        cout << "[1] - Manter Efolios e Avaliar Prova Escrita!" << endl;
                        cout << "[2] - Avaliar Efolios e Prova Escrita!" << endl;
                        cout << "Faça a sua escolha e prima Enter ";
                        cin >> choice;
                        cout << endl << endl << endl;
                        switch (choice)
                        {
                        case 1:
                            notaAnt = stod((*itUCAluno).getProvaEscrita());
                            cout << "Introduza a nota do Aluno" << endl;
                            cin >> nota;
                            while (nota < 0 || nota >12)
                            {
                                cout << "Nota inválida, introduza novamente." << endl;
                                cin >> nota;
                            }
                            if(nota>notaAnt)
                                (*itUCAluno).setProvaEscrita(nota);
                            AtribuiNotaAluno(nAluno, nUC);
                        break;

                        case 2:
                            cout << "Introduza a nota do Aluno" << endl;
                            cin >> nota;
                            AvaliaAlunoEfolios(nAluno, nUC);
                            AtribuiNotaAluno(nAluno, nUC);
                        break;


                        case 99:
                            return;
                            break;
                        default:
                            cout << "Opcao Invalida. \n"
                                << "Tente Novamente.\n";
                            break;
                        }

                    } while (choice != 99);
                    
                    
                    cout << "Introduza a nota do Aluno" << endl;
                    cin >> nota;
                    (*itUCAluno).setProvaEscrita(nota);
                    while (nota < 0 || nota >12)
                    {
                        cout << "Nota inválida, introduza novamente." << endl;
                        cin >> nota;
                    }
                    nota = round(notaEfolios + nota);
                    if (notaAnt < nota)
                        (*itUCAluno).setNota(nota);
                }

                else {
                    cout << "Aluno não se encontra na modalidade de Exame" << endl;
                    return;
                }
            }
        }
    }

    void ListaUCAluno::AvaliaAlunoExame() {
        string nAluno;
        string nUC;
        int nota;
        if (!VerificaSeExisteAluno(nAluno, nUC))
            return;

        for (itUCAluno = lUCAluno.begin(); itUCAluno != lUCAluno.end(); itUCAluno++)
        {
            if ((!nAluno.compare((*itUCAluno).getIdAluno()) && !nUC.compare((*itUCAluno).getIdIdUC())))
            {
                if ((*itUCAluno).getModalidade() == false) {
                    cout << "Introduza a nota do Aluno" << endl;
                    cin >> nota;
                    (*itUCAluno).setProvaEscrita(nota);
                    while (nota < 0 || nota >20)
                    {
                        cout << "Nota inválida, introduza novamente." << endl;
                        cin >> nota;
                    }
                    nota = round(nota);
                        (*itUCAluno).setNota(nota);
                }

                else {
                    cout << "Aluno não se encontra na modalidade de Exame" << endl;
                    return;
                }
            }
        }
    }

   void ListaUCAluno::AtribuiNotaAluno(string nAluno, string nUC) {
       for (itUCAluno = lUCAluno.begin(); itUCAluno != lUCAluno.end(); itUCAluno++)
       {
           if ((!nAluno.compare((*itUCAluno).getIdAluno()) && !nUC.compare((*itUCAluno).getIdIdUC())))
           {
               if ((*itUCAluno).getModalidade()) {

                   (*itUCAluno).setNota(round(stod((*itUCAluno).getEfolios()) + stod((*itUCAluno).getProvaEscrita())));
               }
               else
                   (*itUCAluno).setNota(round(stod((*itUCAluno).getExame())));
           }
       }
    }


	ListaUCAluno::~ListaUCAluno() {
		// TODO Auto-generated destructor stub
	}

	// Imprime a maior e menor nota média da lista de alunos
	void ListaUCAluno::imprimeMaxMin() {
		int maior = 0, menor = 20;

		for (itUCAluno = lUCAluno.begin(); itUCAluno != lUCAluno.end(); itUCAluno++) 
		{
			if ((*itUCAluno).getNota() < menor) menor = (*itUCAluno).getNota();
			if ((*itUCAluno).getNota() > maior) maior = (*itUCAluno).getNota();
		}

		cout << "MAIOR: " << maior << endl;
		cout << "MENOR: " << menor << endl;
	}

	// Calcula a média global da lista de alunos
	float ListaUCAluno::calculaMediaGlobal() {
		float media = 0;
		for (itUCAluno = lUCAluno.begin(); itUCAluno != lUCAluno.end(); itUCAluno++)
		{
			media = media + (*itUCAluno).getNota();
		}

		return (media / n);
	}


	// Ordena os alunos segundo o número de matrícula
	void ListaUCAluno::ordenaUCAlunos() {
		sort(lUCAluno.begin(), lUCAluno.end());
	}

    void ListaUCAluno::imprimeUCAprovados(string idUC)
    {
        int alunosAprov = 0;
        float Media = 0;
        int count=0;
        lUC.imprimeUCPorId(idUC);
        for (itUCAluno = lUCAluno.begin(); itUCAluno != lUCAluno.end(); itUCAluno++)
        {
            if ((*itUCAluno).getModalidade() ) {
                if (!(*itUCAluno).getIdIdUC().compare(idUC)) {
                    if ((*itUCAluno).getNota() >= 10)
                        alunosAprov++;
                    Media += (*itUCAluno).getNota();
                    count++;
                }
            }
        }

        Media = Media / count;
        cout << "Total de Alunos aprovados: " + to_string(alunosAprov)<<endl;
        printf("Media : %0.2f", Media);

    }




    void ListaUCAluno::imprimeUCAlunos(string idAluno)
    {
        lAlunos.imprimeAlunoPorId(idAluno);
        cout << "Unidades curriculares onde obteve aprovacao" << endl;
        cout << "UC                 ECTS                NOTA"<<endl;
        for (itUCAluno = lUCAluno.begin(); itUCAluno != lUCAluno.end(); itUCAluno++)
        {
            if (!(*itUCAluno).getIdAluno().compare(idAluno)) {
                if ((*itUCAluno).getNota() >= 10) {
                    lUC.imprimeUCId((*itUCAluno).getIdIdUC());
                    cout << "                           " +to_string((*itUCAluno).getNota()) << endl;
                }
            } 
        }
        imprimeTotalUCS(idAluno);
        imprimeTotalECTS(idAluno);
        imprimeTotalMediaAluno(idAluno);

    }


    void ListaUCAluno::imprimeTotalUCS(string c) {
        int ucs = 0;
        for (itUCAluno = lUCAluno.begin(); itUCAluno != lUCAluno.end(); itUCAluno++)
        {
            if (!c.compare((*itUCAluno).getIdAluno()))
            {
                if ((*itUCAluno).getNota() >= 10)
                    ucs++;
            }
        }
       
        cout << "Total de UC: " + to_string(ucs) << endl;
        //buscar toda a info sobre UC e ALuno
    }

    void ListaUCAluno::imprimeTotalECTS(string c) {
        int ects = 0;

        for (itUCAluno = lUCAluno.begin(); itUCAluno != lUCAluno.end(); itUCAluno++)
        {
            if (!c.compare((*itUCAluno).getIdAluno()))
            {
                if ((*itUCAluno).getNota() >= 10)
                    ects+= (*itUCAluno).getECTS();
            }
        }

        cout << "Total de ECTS: " + to_string(ects) << endl;
        if (ects == 180)
            cout << "PARABENS POR TER COMPLETADO O CURSO COM 180 ECTS" << endl;
        
        //buscar toda a info sobre UC e ALuno
    }

    void ListaUCAluno::imprimeTotalMediaAluno(string c) {
        float media = 0;
        int count = 0;
        for (itUCAluno = lUCAluno.begin(); itUCAluno != lUCAluno.end(); itUCAluno++)
        {
            if (!c.compare((*itUCAluno).getIdAluno()))
            {
                if ((*itUCAluno).getNota() >= 10) {
                    media += (*itUCAluno).getNota();
                    count++;
                }
                
            }
        }
        media = media / count;
        printf("Media: %.2f", media);
        //buscar toda a info sobre UC e ALuno
    }

    void ListaUCAluno::Get_UCAlunos()
    {

        fpUCAlunoInput.open(dbUCAluno, ios::in);
        if (fpUCAlunoInput.fail())
            cerr << "Error Opening File" << endl;

        else
            while (!fpUCAlunoInput.eof())
            {
                string line;
                getline(fpUCAlunoInput, line);
                if (line != "")
                    FindDelimiter(line);
            }
        fpUCAlunoInput.close();
    }


    void ListaUCAluno::FindDelimiter(string str)
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
        InsertUCAlunos(Alunos);
    }

    void ListaUCAluno::InsertUCAlunos(vector<string> Aluno)
    {
        UCAluno UcAluno;
        bool modalidade;

        UcAluno.setIdAluno(Aluno[0]);
        UcAluno.setIdUC(Aluno[1]);
        UcAluno.setIdUCAluno((Aluno[2]));
        UcAluno.setEfolios(stod((Aluno[3])));
        UcAluno.setProvaEscrita(stod((Aluno[4])));
        UcAluno.setExame(stod((Aluno[5])));
        if(Aluno[6]=="1")
            UcAluno.setModalidade(true);
        else
            UcAluno.setModalidade(false);
        UcAluno.setQtdEfoliosAvaliados(stoi(Aluno[7]));
        UcAluno.setNota(stoi(Aluno[8]));
        UcAluno.setECTS(stoi(Aluno[9]));

        lUCAluno.push_back(UcAluno);
    }

    void ListaUCAluno::WriteToFile()
    {
        string limiter = ">=";
        fpUCAlunoOutPut.open(dbUCAluno, std::ios::out | std::ios::trunc);

        for (itUCAluno = lUCAluno.begin(); itUCAluno != lUCAluno.end(); itUCAluno++)
        {
            fpUCAlunoOutPut << (*itUCAluno).getIdAluno() + limiter +
                (*itUCAluno).getIdIdUC() + limiter + 
                (*itUCAluno).getIdUcAluno() + limiter + 
                to_string((*itUCAluno).getNota()) + limiter  +
                to_string((*itUCAluno).getECTS()) + limiter << endl;

        }
        fpUCAlunoOutPut.close();
    }
} /* namespace std */
