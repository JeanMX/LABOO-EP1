#include <iostream>
#include <string>
#include "Equipe.h"

using namespace std;

Equipe::Equipe(string nome) : nome(nome) {
}

Equipe::~Equipe() {
}

string Equipe::getNome() {
    return nome;
}

void Equipe::imprimir() {
    cout << "Equipe " << this->getNome() << endl;
}
