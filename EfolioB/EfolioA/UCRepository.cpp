//#include "AlunosRepository.h"
//#include "Alunos.h"
//#define dbAluno "DbAlunos.txt" 
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//
//
//namespace std {
//
//    ofstream fpAlunoOutPut;
//    ifstream fpAlunoInput;
//    void InicAluno()
//    {
//        //fpAlunoInput.open(dbAluno, ios::in); //tentar abrir
//       /* if (fpAlunoInput.fail() == true)
//        {
//            cout << "Erro fatal: impossível criar arquivo de dados\n";
//            return;
//        }*/
//    }
//
//    AlunosRepository::AlunosRepository() {
//        // TODO Auto-generated constructor stub
//        //Add_Aluno();
//    }
//
//    void AlunosRepository::Get_Alunos()
//    {
//
//        fpAlunoInput.open("DbAlunos.txt", ios::in);
//        if (fpAlunoInput.fail())
//            cerr << "Error Opening File" << endl;
//
//        else
//            /* fpAluno << ;
//             if (fwrite(&p, sizeof(LAluno), 1, fpAluno) != 1)
//                 Mensagem("Adicionar Aluno: Falhou a escrita do registo");*/
//
//            while (!fpAlunoInput.eof())
//            {
//                string line;
//                getline(fpAlunoInput, line);
//                FindDelimiter(line);
//            }
//    }
//
//
//    void AlunosRepository::FindDelimiter(string str)
//    {
//
//        string Alunos[5];
//        string delimiter = ">=";
//        size_t pos = 0;
//        string token;
//        int i = 0;
//        while ((pos = str.find(delimiter)) != std::string::npos)
//        {
//            Alunos[i] = str.substr(0, pos);
//            std::cout << Alunos[i] << std::endl;
//            str.erase(0, pos + delimiter.length());
//            i++;
//        }
//    }
//
//    void InsertAlunos(string Aluno[])
//    {
//        Alunos lAluno;
//        lAluno.setId(stof(Aluno[0]));
//        lAluno.setNome(Aluno[1]);
//        lAluno.setNotaM(stof(Aluno[3]));
//        lAluno.setCurso((Aluno[2]));
//        lAluno.setMatricula(stof(Aluno[4]));
//
//    }
//
//    void AlunosRepository::RegistsStudent()
//    {
//
//    }
//
//    void AlunosRepository::WriteToFileAlunos()
//    {
//        string limiter = ">=";
//        Alunos d;
//        d.setId(2);
//        d.setCurso("EI");
//        d.setNome("Marcos");
//        d.setNotaM(15);
//        d.setMatricula(2020);
//
//        fpAlunoOutPut.open(dbAluno);
//
//        fpAlunoOutPut << to_string(d.getId()) + "" + limiter + "" + d.getNome() + "" + limiter + "" + d.getCurso() + "" + limiter + "" + to_string(d.getNotaM()) << endl;
//        fpAlunoOutPut.close();
//    }
//}