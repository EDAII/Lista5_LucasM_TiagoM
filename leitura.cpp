#include<bits/stdc++.h>

using namespace std;

int main() {

    int insercao;
    int busca;

    cin >> insercao >> busca;

    cout << "Inserção de " << insercao << "itens" << endl;
    cout << "Busca de " << busca << "itens" << endl;
    cout << endl;

    vector <int> insercoes;
    vector <int> buscas;

    int limite_random = insercao * 2;

    for(int i=0; i<insercao; i++){
        int number = rand() % limite_random;
        insercoes.push_back(number);
    }
    for(int i=0; i<busca; i++){
        int number = rand() % limite_random;
        buscas.push_back(number);
    }

    int tempo_insercoes;
    int tempo_buscas;

    clock_t ticks[2];
    int tempo[2];

    cout << "Árvore Red-Black" << endl;

    ticks[0] = clock();
    for (int i=0; i<insercoes.size(); i++){

    }
    ticks[1] = clock();
    tempo[0] = ((ticks[1] - ticks[0]) * 1000 / CLOCKS_PER_SEC); 
    cout << "Tempo para inserção: " << tempo << "ms;" << endl;

    ticks[0] = clock();
    for (int i=0; i<buscas.size(); i++){

    }
    ticks[1] = clock();
    tempo[1] = ((ticks[1] - ticks[0]) * 1000 / CLOCKS_PER_SEC); 
    cout << "Tempo para busca: " << tempo << "ms;" << endl;
    cout << "Tempo total para operações: " << tempo[1] - tempo[0] << "ms." << endl;

    cout << endl;

    cout << "Busca em lista duplamente encadeada com ordenação utilizando o padrão nativo do c++" << endl;

    ticks[0] = clock();
    for (int i=0; i<insercoes.size(); i++){

    }
    ticks[1] = clock();
    tempo[0] = ((ticks[1] - ticks[0]) * 1000 / CLOCKS_PER_SEC); 
    cout << "Tempo para inserção: " << tempo << "ms;" << endl;

    ticks[0] = clock();
    for (int i=0; i<buscas.size(); i++){

    }
    ticks[1] = clock();
    tempo[1] = ((ticks[1] - ticks[0]) * 1000 / CLOCKS_PER_SEC); 
    cout << "Tempo para busca: " << tempo << "ms;" << endl;
    cout << "Tempo total para operações: " << tempo[1] - tempo[0] << "ms." << endl;

    return 0;
}