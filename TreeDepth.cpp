//Get Tree Depth

#include<iostream>
#include<fstream>
using namespace std;
//ifstream ifs("input.txt");
//int cnt = 0;
template<class T>
struct Node {
	Node(T d, T ld, T rd, Node<T>*left = 0, Node<T>*right = 0, Node<T>*parent1 = 0, int left1 = 0, int right1 = 0)
		:data(d), leftChild(left), rightChild(right), parent(parent1), leftSize(left1), rightSize(right1), leftd(ld), rightd(rd) {}
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
	void Insert(T &value, T&value2, T&value3) { Insert(root, value, value2, value3); }
	void Preorder(T value, T value2, T value3) { Preorder(root, value, value2, value3); }
	void Postorder() { Postorder(root); }
	void Visit2(Node<T>*, T value, T d1, T d2);
	void Visit3() { Visit3(root); }
	int Size() { Size(root); }
	int Depth() { Depth(root); }
private:
	void Visit(Node<T>*);
	void Insert(Node<T>*&, T&, T&, T&);
	void Preorder(Node<T>*, T value, T value2, T value3);
	void Postorder(Node<T>*);
	void Visit3(Node<T>*);
	int Size(Node<T>*);
	int Depth(Node<T>*);
};

template<class T>
int Tree<T>::Size(Node<T>* ptr) {
	if (ptr == NULL)return 0;
	else {
		return Size(ptr->leftChild) + Size(ptr->rightChild) + 1;
	}
}
template<class T>
int Tree<T>::Depth(Node<T>* ptr) {
	if (ptr == NULL)return 0;
	else {
		int Ldepth, Rdepth;
		Ldepth = Depth(ptr->leftChild) + 1;
		Rdepth = Depth(ptr->rightChild) + 1;
		if (Ldepth > Rdepth)return Ldepth;
		else return Rdepth;
	}
}