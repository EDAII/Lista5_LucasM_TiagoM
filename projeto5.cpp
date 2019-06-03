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

	for(int i=0; i<10; i++){
		arvore->inserir(i);
		values.push_back(i);
	}

	cout << bin(20, 0, values.size()-1) << endl;

	return 0;
}
