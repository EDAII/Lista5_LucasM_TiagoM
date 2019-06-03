#ifndef AVL_TREE
#define AVL_TREE

#include<bits/stdc++.h>

using namespace std;

template<typename T>
class AVLTree {

	private:	

	struct Node {
		T info;
		int hight;
		Node *left, *right;
	};

	Node *root;

	void delete_by_mergeing(Node** n){
		auto node = *n;

		if(node == nullptr) return;

		if(node->right == nullptr){
			*n = node->left;
		}else if(node->left == nullptr){
			*n = node->right;
		}
		else {
			auto temp = node->left;

			while(temp->right){
				temp = temp->right;
			}

			temp->right = node->right;
			*n = node->left;
		}
		delete node;
	}

	int size(const Node *node) const {
		return node ? size(node->left) + size(node->right) + 1 : 0;
	}

	bool search(Node *node, const T& info) const {
		while(node){
			if(info == node->info) return true;

			else if (info < node->info) node = node->left;

			else node = node->right;
		}

		return false;

	}

	int hightNode(Node *node) {
		if(node == nullptr) return -1;

		return node->hight;
	}

	int balanceFactorNode(Node *node){
		return abs(hightNode(node->left) - hightNode(node->right));
	}

	void RotationLL(Node *node){
		auto n = (*node)->left;

		(*node)->left = n->right;
		n->right = *node;
		(*node)->hight = max(hightNode((*node)->left), hightNode((*node)->right)) + 1;

		n->hight = max(hightNode(n->left, (*node)->hight)) + 1;
		*node = n;
	}

	void RotationRR(Node *node){
		auto n = (*node)->right;

		(*node)->right = n->left;
		n->left = (*node);
		(*node)->hight = max(hightNode((*node)->left), hightNode((*node)->right)) + 1;

		n->hight = max(hightNode(n->right), (*node)->hight) + 1;
		(*node) = n;
	}

	void RotationLR (Node *node){
		RotationRR(&(*node)->left);
		RotationLL(node);
	}

	void RotationRL(Node *node){
		RotationLL(&(*node)->right);
		RotationRR(node);
	}

	void insert(const T& info, Node *n){

		Node *node = n;

		if(!n){
			node = new Node {info, 0, nullptr, nullptr};
			n = node;
			return;
		}else if(info <= n->info){
			insert(info, n->left);

			if(balanceFactorNode(node) >= 2){
				if(info <= (*n)->left->info){
					RotationLL(n);
				}else{
					RotationLR(n);
				}
			}

		}else{
			insert(info, n->right);

			if(balanceFactorNode(node) >= 2){
				if(info > (*n)->right->info){
					RotationRR(*n);
				}else{
					RotationRL(*n);
				}
			}
		}
		
		node->hight = max(hightNode(node->left), hightNode(node->right)) + 1;
		return;
	}

	public:

	AVLTree() : root(nullptr) {}

	int size() const { return size(root); }

	void insert(const T& info){ return insert(info, root); }

	void erase(const T& info){
		Node** node = &root;

		while(*node){
			if((*node)->info == info) break;

			if(info < (*node)->info){
				node = &(*node)->left;
			}else{
				node = &(*node)->right;
			}
		}
		delete_by_mergeing(node);
	}

	bool search(const T& info) { return search(root, info); }

};

#endif
