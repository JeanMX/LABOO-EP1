#include <iostream>
#include <string>
#include "Modalidade.h"
#include "Equipe.h"
#include "Tabela.h"
#include "Competicao.h"
using namespace std;

int main() {
    int n;
    int m;
    int colocacao;
    string nomeEquipe;
    string nomeModalidade;
    string nomeCompeticao;

    cout << "Informe o nome da competicao: ";
    cin >> nomeCompeticao;

    cout << endl << "Informe a quantidade de equipes: ";
    cin >> n;

    Equipe** equipes = new Equipe*[n];

    for (int i = 0; i < n; i++) {
        cout << "Informe o nome da equipe " << i + 1 << ": ";
        cin >> nomeEquipe;
        equipes[i] = new Equipe(nomeEquipe);
    }

    cout << endl << "Informe a quantidade de modalidades: ";
    cin >> m;

    Modalidade** modalidades = new Modalidade*[m];
    Competicao* competicao = new Competicao(nomeCompeticao, equipes, n, m);

    Equipe** ordem = new Equipe*[n];

    for (int i = 0; i < m; i++) {
        if (i == 0) {
            cout << "Informe o nome da modalidade " << i + 1 << " : ";
        } else {
            cout << endl << "Informe o nome da modalidade " << i + 1 << " : ";
        }

        cin >> nomeModalidade;

        modalidades[i] = new Modalidade(nomeModalidade, equipes, n);

        competicao->adicionar(modalidades[i]);

        for (int j = 0; j < n; j++) {
            cout << "Informe a equipe " << j + 1 << "a colocada: ";
            cin >> colocacao;
            ordem[j] = equipes[colocacao - 1];
        }

        modalidades[i]->setResultado(ordem);
    }

    competicao->imprimir();
    delete competicao;
    delete[] modalidades;
    delete[] ordem;

    for (int i = 0; i < n; i++) {
        delete equipes[i];
    }

    delete[] equipes;
    return 0;
}
