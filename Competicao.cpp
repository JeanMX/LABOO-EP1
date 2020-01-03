#include "Equipe.h"
#include "Modalidade.h"
#include "Tabela.h"
#include "Competicao.h"
#include <iostream>
#include <string>

using namespace std;

Competicao::Competicao(string nome, Equipe** equipes, int quantidade, int maximoDeModalidades) :
    nome(nome), equipes(equipes), quantidade(quantidade), maximoDeModalidades(maximoDeModalidades) {
    this->modalidades = new Modalidade*[maximoDeModalidades];
    quantidadeModalidades = 0;
}

Competicao::~Competicao() {
    for (int i = 0; i < quantidadeModalidades; i++) {
        delete modalidades[i];
    }

    delete[] modalidades;
}

string Competicao::getNome() {
    return nome;
}

Equipe** Competicao::getEquipes() {
    return equipes;
}

Modalidade** Competicao::getModalidades() {
    return modalidades;
}

Tabela* Competicao::getTabela() {
    Tabela* tabela = new Tabela(equipes, quantidade);

    for (int i = 0; i < quantidadeModalidades; i++) {
        Modalidade* m;
        m = modalidades[i];

        for (int j = 0; j < quantidade; j++) {
            Equipe* e = (m->getEquipes())[j];
            int posicao;

            posicao = m->getPosicao(e);

            if (posicao < 0) {
                continue;
            }

            switch (posicao) {
                case 0:
                    tabela->pontuar(e, 13);
                    break;

                case 1:
                    tabela->pontuar(e, 10);
                    break;

                case 2:
                    tabela->pontuar(e, 8);
                    break;

                case 3:
                    tabela->pontuar(e, 7);
                    break;

                case 4:
                    tabela->pontuar(e, 5);
                    break;

                case 5:
                    tabela->pontuar(e, 4);
                    break;

                case 6:
                    tabela->pontuar(e, 3);
                    break;

                case 7:
                    tabela->pontuar(e, 2);
                    break;

                case 8:
                    tabela->pontuar(e, 1);
                    break;

                default:
                    tabela->pontuar(e, 0);
                    break;
            }
        }
    }

    return tabela;
}

int Competicao::getQuantidadeDeEquipes() {
    return quantidade;
}

int Competicao::getQuantidadeDeModalidades() {
    return quantidadeModalidades;
}

bool Competicao::adicionar(Modalidade* m) {
    if (quantidadeModalidades >= maximoDeModalidades) {
        return false;
    }

    modalidades[quantidadeModalidades] = m;
    quantidadeModalidades++;
    return true;
}

void Competicao::imprimir() {
    Tabela* novaTabela = getTabela();
    cout << endl << nome << endl;
    novaTabela->imprimir();
    delete novaTabela;
}
