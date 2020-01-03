#ifndef MODALIDADE_H
#define MODALIDADE_H

#include "Equipe.h"
#include <iostream>
#include <string>

using namespace std;

class Modalidade {
    public:
        Modalidade(string nome, Equipe** participantes, int quantidade);
        ~Modalidade();
        string getNome();

        Equipe** getEquipes();

        int getQuantidadeDeEquipes();

        void setResultado(Equipe** ordem);

        int getPosicao(Equipe* participante);

        void imprimir();

    private:
        bool resultado = false;
        string nome;
        Equipe** participantes;
        int quantidade;
        Equipe** ordem;
};

#endif // MODALIDADE_H
