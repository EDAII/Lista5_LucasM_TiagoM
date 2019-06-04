#include<bits/stdc++.h>
#include "redBlack.h"

using namespace std;

vector<int> values;

int bin(int value,int begin, int end){
	
	int media = (begin+end)/2;

	if(values[media] == value){
		return media;	
	}

	if(begin == media || end == media){
		return -1;
	}else if(values[media] > value){
		return bin(value, begin, media);
	}else{
		return bin(value, media, end);
	}
}

int main(){

	ArvRB* arvore = new ArvRB;

	// for(int i=0; i<10; i++){
	// 	arvore->inserir(i);
	// }

	// int tiago = 1;
	
	// No* busca = arvore->busca(tiago);

	// cout << busca->chave << endl;

	// for(int i=0; i<10; i++){
	// 	arvore->inserir(i);
	// 	values.push_back(i);
	// }

	int insercao;
    int busca;
    setlocale(LC_NUMERIC, "");

    cin >> insercao >> busca;

    // scanf("%d", &busca);

    printf("Inserção de %'d itens\n", insercao);
    printf("Busca de %'d itens\n", busca);
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

    clock_t Ticks[2];
    int tempo[2];

    cout << "Busca em vector com ordenação utilizando o padrão nativo do c++" << endl;

    Ticks[0] = clock();
    for (int i=0; i<insercoes.size(); i++){
	  	values.push_back(insercoes[i]);
    }
    sort(values.begin(), values.end());
    Ticks[1] = clock();
    tempo[0] = ((Ticks[1] - Ticks[0]) * 1000 / CLOCKS_PER_SEC); 
    printf ("Tempo para inserçao: %'d ms;\n", tempo[0]);

    Ticks[0] = clock();
    for (int i=0; i<buscas.size(); i++){
	  	bin(buscas[i], 0, values.size()-1);
    }
    Ticks[1] = clock();
    tempo[1] = ((Ticks[1] - Ticks[0]) * 1000 / CLOCKS_PER_SEC); 
    printf ("Tempo para busca: %'d ms;\n", tempo[1]);
    printf ("Tempo total para operações: %'d ms;\n", tempo[1] + tempo[0]);

    values.clear();
    cout << endl;

    cout << "Árvore Red-Black" << endl;

    Ticks[0] = clock();
    for (int i=0; i<insercoes.size(); i++){
		  arvore->inserir(insercoes[i]);
    }
    Ticks[1] = clock();
    tempo[0] = ((Ticks[1] - Ticks[0]) * 1000 / CLOCKS_PER_SEC); 
    printf ("Tempo para inserçao: %'d ms;\n", tempo[0]);
    insercoes.clear();

    Ticks[0] = clock();
    for (int i=0; i<buscas.size(); i++){
	  	arvore->busca(buscas[i]);
    }
    Ticks[1] = clock();
    tempo[1] = ((Ticks[1] - Ticks[0]) * 1000 / CLOCKS_PER_SEC); 
    printf ("Tempo para busca: %'d ms;\n", tempo[1]);
    printf ("Tempo total para operações: %'d ms;\n", tempo[1] + tempo[0]);
    

	return 0;
}
