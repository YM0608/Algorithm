//Tour
//Preorder, Postorder

#include<iostream>
#include<fstream>
using namespace std;
ifstream ifs("input.txt");
int cnt = 0;
template<class T>
struct Node {
	Node(T d, T ld, T rd, Node<T>*left = 0, Node<T>*right = 0,Node<T>*parent1=0, int left1 = 0, int right1=0)
		:data(d), leftChild(left), rightChild(right),parent(parent1) ,leftSize(left1), rightSize(right1),leftd(ld),rightd(rd) {}
	Node<T>*leftChild;
	Node<T>*rightChild;
	Node<T>*parent;
	T data;
	int leftSize;
	int rightSize;
	T leftd;
	T rightd;
};
template<class T>
class Tree {
public:
	Node<T>*root;
	Tree() { root = 0; }
	void Insert(T &value,T&value2,T&value3) { Insert(root, value,value2,value3); }
	void Preorder(T value, T value2, T value3) { Preorder(root, value, value2, value3); }
	void Postorder() { Postorder(root); }
	void Visit2(Node<T>*, T value, T d1, T d2);
	void Visit3() { Visit3(root); }
private:
	void Visit(Node<T>*);
	void Insert(Node<T>*&, T&,T&,T&);
	void Preorder(Node<T>*, T value, T value2, T value3);
	void Postorder( Node<T>* );
	void Visit3(Node<T>*);
};


template<class T>
void Tree<T>::Insert(Node<T>* &ptr, T &value,T &value2,T &value3) {
	if (ptr == 0) {
		ptr = new Node<T>(value, value2, value3);
		ptr->leftd = value2; ptr->rightd = value3;
	}
	else {
		Preorder(value, value2, value3);
	}
}
template<class T>
void Tree<T>::Preorder(Node<T>* currentNode, T value, T value2, T value3) {//프리오더
	if (currentNode) {
		Visit2(currentNode, value, value2, value3);
		Preorder(currentNode->leftChild, value, value2, value3);
		Preorder(currentNode->rightChild, value, value2, value3);
	}
}
template<class T>
void Tree<T>::Visit2(Node<T>* current, T value, T d1, T d2) {
	if (current->leftd == value) {
		current->leftChild = new Node<T>(value, d1, d2);
		return;
	}
	if (current->rightd == value) {
		current->rightChild = new Node<T>(value, d1, d2);
		return;
	}
}
template<class T>
void Tree<T>::Postorder(Node<T>*currentNode) {
	if (currentNode) {
		Postorder(currentNode->leftChild);
		Postorder(currentNode->rightChild);
		Visit(currentNode);
	}
}
template<class T>
void Tree<T>::Visit(Node<T>*ptr) {
	if (ptr->leftChild) {
		ptr->leftSize = ptr->leftChild->leftSize + ptr->leftChild->rightSize + 1;
	}
	if (ptr->rightChild) {
		ptr->rightSize = ptr->rightChild->leftSize + ptr->rightChild->rightSize + 1;
	}
}

template<class T>
void Tree<T>::Visit3(Node<T>* current) {
	if (current) {
		Visit3(current->leftChild);
		cout << current->data << " " << current->leftSize << " " << current->rightSize << endl;
		if (current->leftSize < current->rightSize)cnt++;
		Visit3(current->rightChild);
	}
}
int main() {
	int n;
	ifs >> n;
	int node;
	while (n--) {
		ifs >> node;
		Tree<double>tree;
		for (int i = 0; i < node; i++) {
			double parent, left, right;
			ifs >> parent >> left >> right;
			tree.Insert(parent, left, right);
		}
		tree.Postorder();
		tree.Visit3();
		cout << endl;
		cout << cnt << endl << endl;
		cnt = 0;
	}
	
}