#ifndef AVL_TREE
#define AVL_TREE

#include<bits/stdc++.h>

using namespace std;

template<typename T>
struct Node {
	T value;
	Node* Left;
	Node* Right;
	Node* Father;
	int High;

	Node (T value, Node* Left, Node* Right, Node* Father){
		this->value = value;
		this->Left = Left;
		this->Right = Right;
		this->Father = Father;
	}

	Node (T value) {
		this->value = value;
		Left = NULL;
		Right = NULL;
		Father = NULL;
	}
	Node (){
	}
};


template<typename T>
class AVLTree {
	private:	

		Node<T>* search(T value, Node<T>* node){
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

		int HighNode(Node<T>* node){
			if (node == NULL){
				return -1;
			}
			return node->High;
		}

		int Balance(Node<T>* node){
			return (HighNode(node->Left) - HighNode(node->Right));
		}

	public:
		Node<T>* Root;
		size_t size;

		AVLTree(){
			Root = NULL;
			size=0;
		}
		Node<T>* find(T value){
			cout << "Valor buscado " << value << endl;

			cout << "Root " << (*Root).value << endl; 
			
			return search(value, Root);	
			cout << "Saiu da busca" << endl;
		}
		void insert(T value){
			if(size == 0){
				Node<T> aux(value);
				Root = &aux;
				size++;
				cout << "Root " << (*Root).value << endl; 
			}
		}
};

#endif
