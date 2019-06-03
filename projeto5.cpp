#include<bits/stdc++.h>
#include "redBlack.h"

using namespace std;

int main(){

	ArvRB* arvore = new ArvRB;

	// for(int i=0; i<10; i++){
	// 	arvore->inserir(i);
	// }

	arvore->inserir(10);
	arvore->inserir(20);


	int tiago = 20;
	
	No* busca = arvore->busca(tiago);

	cout << busca->chave << endl;

	return 0;
}
