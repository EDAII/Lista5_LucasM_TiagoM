#include<bits/stdc++.h>
//#include "AVL.h"

using namespace std;

struct Node {
	int value;
	Node* Left;
	Node* Right;
	Node* Father;
	int High;

	Node (int value, Node* Left, Node* Right, Node* Father){
		this->value = value;
		this->Left = Left;
		this->Right = Right;
		this->Father = Father;
	}

	Node (int value) {
		this->value = value;
		Left = NULL;
		Right = NULL;
		Father = NULL;
	}
	Node (){
	}
};

class AVLTree {
	private:	

		Node* search(int value, Node* node){
			if (node->value == value){
				return node;
			}
			if (value <= node->value && node->Left != NULL){
				return search(value, node->Left);
			}
			if (value > node->value && node->Right != NULL){
				return search(value, node->Right);
			}
			return NULL;
		}

		int HighNode(Node* node){
			if (node == NULL){
				return -1;
			}
			return node->High;
		}

		int Balance(Node* node){
			return (HighNode(node->Left) - HighNode(node->Right));
		}

	public:
		Node* Root;
		size_t size;

		AVLTree(){
			Root = NULL;
			size=0;
		}
		Node* find(int value){
			cout << "Valor buscado " << value << endl;

			cout << "Root " << (*Root).value << endl; 
			
			return search(value, Root);	
			cout << "Saiu da busca" << endl;
		}
		void insert(int value){
			if(size == 0){
				Node aux(value);
				Root = &aux;
				size++;
				cout << "Root " << (*Root).value << endl; 
				cout << "Endereço de Root: " << Root << endl;
			}
		}
};


int main(){

	AVLTree teste;

	cout << teste.size << endl;

	teste.insert(10);

	auto b = teste.Root;

	cout << teste.size << endl;

	cout << "Endereço de b: " << b << endl;
	cout << "Root in main " << (*b).value << endl;

	//auto a=teste.find(10);

	//cout << a << endl;

	return 0;
}
