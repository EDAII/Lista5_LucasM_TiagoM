#include<bits/stdc++.h>

using namespace std;

int main() {

    int insercao;
    int busca;
    int remocao;

    cin >> insercao >> busca >> remocao;

    cout << "Inserção de " << insercao << "itens" << endl;
    cout << "Busca de " << busca << "itens" << endl;
    cout << "Remoção de " << remocao << "itens" << endl;
    cout << endl;

    vector <int> insercoes;
    vector <int> buscas;
    vector <int> remocoes;

    int limite_random = insercao * 2;

    for(int i=0; i<insercao; i++){
        int number = rand() % limite_random;
        insercoes.push_back(number);
    }
    for(int i=0; i<busca; i++){
        int number = rand() % limite_random;
        buscas.push_back(number);
    }
    for(int i=0; i<remocao; i++){
        int number = rand() % limite_random;
        remocoes.push_back(number);
    }

    int tempo_insercoes;
    int tempo_buscas;
    int tempo_remocoes;

    clock_t ticks[2];
    int tempo;

    cout << "Árvore Red-Black" << endl;

    ticks[0] = clock();
    for (int i=0; i<remocoes.size(); i++){

    }
    ticks[1] = clock();
    tempo = ((ticks[1] - ticks[0]) * 1000 / CLOCKS_PER_SEC); 
    cout << "Tempo para inserção: " << tempo << "ms;" << endl;

    ticks[0] = clock();
    for (int i=0; i<remocoes.size(); i++){

    }
    ticks[1] = clock();
    tempo = ((ticks[1] - ticks[0]) * 1000 / CLOCKS_PER_SEC); 
    cout << "Tempo para busca: " << tempo << "ms;" << endl;

    ticks[0] = clock();
    for (int i=0; i<remocoes.size(); i++){

    }
    ticks[1] = clock();
    tempo = ((ticks[1] - ticks[0]) * 1000 / CLOCKS_PER_SEC); 
    cout << "Tempo para remoção: " << tempo << "ms." << endl;



    cout << "Árvore AVL" << endl;

    ticks[0] = clock();
    for (int i=0; i<remocoes.size(); i++){

    }
    ticks[1] = clock();
    tempo = ((ticks[1] - ticks[0]) * 1000 / CLOCKS_PER_SEC); 
    cout << "Tempo para inserção: " << tempo << "ms;" << endl;

    ticks[0] = clock();
    for (int i=0; i<remocoes.size(); i++){

    }
    ticks[1] = clock();
    tempo = ((ticks[1] - ticks[0]) * 1000 / CLOCKS_PER_SEC); 
    cout << "Tempo para busca: " << tempo << "ms;" << endl;

    ticks[0] = clock();
    for (int i=0; i<remocoes.size(); i++){

    }
    ticks[1] = clock();
    tempo = ((ticks[1] - ticks[0]) * 1000 / CLOCKS_PER_SEC); 
    cout << "Tempo para remoção: " << tempo << "ms." << endl;

    return 0;
}