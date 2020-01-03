#include "Tabela.h"
#include "Equipe.h"

Tabela::Tabela(Equipe** participantes, int quantidade) :
    participantes(participantes), quantidade(quantidade) {
    pontos = new int [quantidade];

    for (int i = 0; i < quantidade; i++) {
        pontos[i] = 0;
    }
}

Tabela::~Tabela() {
    delete[] pontos;
}

void Tabela::pontuar(Equipe* participante, int pontos) {
    for (int i = 0; i < quantidade; i++) {
        if (this->participantes[i] == participante) {
            this->pontos[i] += pontos;
        }
    }
}

int Tabela::getPontos(Equipe* participante) {
    for (int i = 0; i < quantidade; i++) {
        if (this->participantes[i] == participante) {
            return pontos[i];
        }
    }

    return -1;
}

int Tabela::getPosicao(Equipe* participante) {
    int temp = 0; // Variável que receberá a posicao do participante
    bool passou = false; 
    posicao = 1;

    for (int i = 0; i < quantidade; i++) {
        if ((this->participantes[i] == participante) && (passou == false)) {
            temp = i;
            i = 0;
            passou = true;
        }

        if ((this->pontos[i] > this->pontos[temp]) && (passou == true)) {
            posicao++;
        }
    }

    return posicao;
}

void Tabela::imprimir() {
    for (int i = 0; i < quantidade; i++) {
        cout << this->participantes[i]->getNome() << " - " << pontos[i] << " pontos " <<
        "(" << getPosicao(participantes[i]) << "o)" << endl;
    }
}
