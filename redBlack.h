#ifndef RED_BLACK
#define RED_BLACK

#include <bits/stdc++.h>
using namespace std;

/* VERMELHO = 0
 * PRETO = 1
 */
enum Cor {VERMELHO, PRETO};

// Estrutura de Nó
struct No{
	int chave;
	bool cor;
	No *esquerda, *direita, *super;

	No(int chave){
	this->chave = chave;
	esquerda = direita = super = NULL;
	}
};

// Classe da Árvore Rubro-Negra
class ArvRB{
private:
	No *raiz;
protected:
	void rotacaoEsquerda(No *&, No *&);
	void rotacaoDireita(No *&, No *&);
	void violacao(No *&, No *&);
public:

	ArvRB() { raiz = NULL; }
	~ArvRB(){};
	void inserir(const int &n);
	No* busca(const int n);
	void emOrdem();
	void corrigirEstrutura(No *&, No *&);
	void ordemNivel();
};

void ordenaArv(No *raiz){
	if (raiz == NULL)
		return;

	ordenaArv(raiz->esquerda);
	// cout << raiz->chave << " ";
	ordenaArv(raiz->direita);
}

No* inserirBST(No* raiz, No* pt){
	if (raiz == NULL)
	return pt;

	if (pt->chave <= raiz->chave){
		raiz->esquerda = inserirBST(raiz->esquerda, pt);
		raiz->esquerda->super = raiz;
	}
	else if (pt->chave > raiz->chave){
		raiz->direita = inserirBST(raiz->direita, pt);
		raiz->direita->super = raiz;
	}

	return raiz;
}

No* removeBST(No* raiz){
    if (raiz->direita == NULL)
        return raiz->esquerda;
    No *atual;

    for (atual = raiz; atual->esquerda == NULL && atual->direita == NULL;atual = atual->esquerda);

    atual->super->esquerda = NULL;
    atual->esquerda = raiz->direita;
    atual->direita = raiz->esquerda;
    return atual;
    
}

No* buscaChave(No* raiz, int chave){
	// cout << "Entrou" << endl;
	if (raiz == NULL)
	    return NULL;
    else if(raiz->chave == chave){
		// cout << raiz->chave << endl;
        return raiz;
	}

	if (chave <= raiz->chave) {
		// cout << "raiz equerda" << endl;
		raiz->esquerda = buscaChave(raiz->esquerda, chave);
	}
	else if (chave > raiz->chave){
		// cout << "raiz direita" << endl;
		raiz->direita = buscaChave(raiz->direita, chave);
	}
	return raiz;
}

void ordenaNivel(No *raiz){
	if (raiz == NULL){
		return;
    }
	
	int c=0, count=0;
	No *noNULL = NULL;
	std::queue<No *> q;
	q.push(raiz);
	while (!q.empty()){
		No *temp = q.front();
		if(temp == noNULL){
			q.pop();
			count++;
			continue;
		}

		if(temp->cor == 1)
			printf("\033[1m\033[30m (%d) \033[0m",temp->chave);
		else
			printf("\033[31m (%d) \033[0m",temp->chave);
		q.pop();
		count++;
		if((int)log2(count)==c){
			cout<<endl;
			count=0;
			c++;
		}
        
        if (temp->esquerda == NULL || temp->direita == NULL)
            q.push(noNULL);
		if (temp->esquerda != NULL)
			q.push(temp->esquerda);

		if (temp->direita != NULL)
			q.push(temp->direita);
	}
}

void ArvRB::rotacaoEsquerda(No *&raiz, No *&pt){
	No *pt_direita = pt->direita;
	pt->direita = pt_direita->esquerda;
	if (pt->direita != NULL)
		pt->direita->super = pt;

	pt_direita->super = pt->super;

	if (pt->super == NULL)
		raiz = pt_direita;

	else if (pt == pt->super->esquerda)
		pt->super->esquerda = pt_direita;

	else
		pt->super->direita = pt_direita;

	pt_direita->esquerda = pt;
	pt->super = pt_direita;
}

void ArvRB::rotacaoDireita(No *&raiz, No *&pt){
	No *pt_esquerda = pt->esquerda;

	pt->esquerda = pt_esquerda->direita;

	if (pt->esquerda != NULL)
		pt->esquerda->super = pt;

	pt_esquerda->super = pt->super;

	if (pt->super == NULL)
		raiz = pt_esquerda;

	else if (pt == pt->super->esquerda)
		pt->super->esquerda = pt_esquerda;

	else
		pt->super->direita = pt_esquerda;

	pt_esquerda->direita = pt;
	pt->super = pt_esquerda;
}

void ArvRB::corrigirEstrutura(No *&raiz, No *&pt){
	No *super_pt = NULL;
	No *su_super_pt = NULL;

	while ((pt != raiz) && (pt->cor != PRETO) && (pt->super->cor == VERMELHO)){

		super_pt = pt->super;
		su_super_pt = pt->super->super;

		if (super_pt == su_super_pt->esquerda){

			No *lad_pt = su_super_pt->direita;

			if (lad_pt != NULL && lad_pt->cor == VERMELHO){
				su_super_pt->cor = VERMELHO;
				super_pt->cor = PRETO;
				lad_pt->cor = PRETO;
				pt = su_super_pt;
			}

			else{
				
				if (pt == super_pt->direita){
					rotacaoEsquerda(raiz, super_pt);
					pt = super_pt;
					super_pt = pt->super;
				}

				rotacaoDireita(raiz, su_super_pt);
				swap(super_pt->cor, su_super_pt->cor);
				pt = super_pt;
			}
		}

		else{
			No *lad_pt = su_super_pt->esquerda;

			if ((lad_pt != NULL) && (lad_pt->cor == VERMELHO)){
				su_super_pt->cor = VERMELHO;
				super_pt->cor = PRETO;
				lad_pt->cor = PRETO;
				pt = su_super_pt;
			}
			else{
				if (pt == super_pt->esquerda)
				{
					rotacaoDireita(raiz, super_pt);
					pt = super_pt;
					super_pt = pt->super;
				}

				rotacaoEsquerda(raiz, su_super_pt);
				swap(super_pt->cor, su_super_pt->cor);
				pt = super_pt;
			}
		}
	}

	raiz->cor = PRETO;
}

void ArvRB::inserir(const int &chave){
	No *pt = new No(chave);

	raiz = inserirBST(raiz, pt);

	corrigirEstrutura(raiz, pt);
}

No* ArvRB::busca(const int chave){
	No* busca = buscaChave(raiz, chave);

	return busca;
}

void ArvRB::emOrdem()	 { ordenaArv(raiz);}
void ArvRB::ordemNivel() { ordenaNivel(raiz); }

#endif
