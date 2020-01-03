#include "Modalidade.h"

Modalidade::Modalidade(string nome, Equipe** participantes, int quantidade) :
    nome(nome), participantes(participantes), quantidade(quantidade) {
    this->ordem = new Equipe*[quantidade];
}

Modalidade::~Modalidade() {
    delete[] ordem;
}

string Modalidade::getNome() {
    return nome;
}

Equipe** Modalidade::getEquipes() {
    return participantes;
}

int Modalidade::getQuantidadeDeEquipes() {
    return quantidade;
}

void Modalidade::setResultado(Equipe** ordem) {
    for (int i = 0; i < quantidade; i++) {
        this->ordem[i] = ordem[i];
    }

    resultado = true;
}

int Modalidade::getPosicao(Equipe* participante) {
    if (resultado == true) {
        for (int i = 0; i < quantidade; i++) {
            if (this->ordem[i] == participante) {
                return i;
            }
        }
    }

    return -1;
}

void Modalidade::imprimir() {
    cout << "Modalidade: " << this->nome << endl;
    cout << "Participantes: " << endl;

    if (resultado) {
        for (int i = 0; i < quantidade; i++) {
            cout << "\t" << this->ordem[i]->getNome() << endl;
        }
    } 
    else {
        for (int i = 0; i < quantidade; i++) {
            cout << this->participantes[i]->getNome() << endl;
        }
    }
}
