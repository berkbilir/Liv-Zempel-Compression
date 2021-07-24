#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <sstream>
#include <fstream>
#include <ostream>
using namespace std;

template <class T>
struct Node {
	T key;
	int code;
	Node *left;
	Node *right;


	Node(T key, int code) : key(key), left(NULL), right(NULL), code(code) {}


	Node(T key, Node<T> left, Node<T> right, int code) {
		this->key = key;
		this->left = left;
		this->right = right;
		this->code = code;
	}
};

template <class T>
class BST {

private:
	Node<T> *root = nullptr;

	void insertHelper(Node<T> *root, T key, int code) {
		if (root->key > key) {
			if (!root->left) {
				root->left = new Node<T>(key, code);
			}
			else {
				insertHelper(root->left, key, code);
			}
		}
		else {
			if (!root->right) {
				root->right = new Node<T>(key, code);
			}
			else {
				insertHelper(root->right, key, code);
			}
		}
	}

	bool doesExistHelper(Node<T> *root, T key) {


		while (root != NULL) {
			if (root->key == key) {
				return true;
			}
			else {
				if (key > root->key) {
					root = root->right;
				}
				else {
					root = root->left;
				}
			}
		}
		return false;


	}

	void printHelper(Node<T> *root) {
		if (!root) return;
		printHelper(root->left);
		cout << root->key << ' ';
		printHelper(root->right);
	}

	int getCodeHelper(Node<T> *root, T key) {

		while (root != NULL) {
			if (root->key == key) {
				return root->code;
			}
			else {
				if (key > root->key) {
					root = root->right;
				}
				else {
					root = root->left;
				}
			}
		}
		return 0;;
	}



public:
	void insert(T key, int code) {
		if (root) {
			this->insertHelper(root, key, code);
		}
		else {
			root = new Node<T>(key, code);
		}
	}

	bool doesExist(T key) {
		bool a = doesExistHelper(this->root, key);
		return a;
	}

	void print() {
		printHelper(this->root);
	}

	int getCode(T key) {
		int a = getCodeHelper(this->root, key);
		return a;
	}
};

vector<int> lzwAlgorithm(string sequence, BST<string> *bst) {
	vector<int> codeSequence;

	string p = "";
	string c;
	string sum = p + c;
	int codeCounter = 256;

	for (int i = 0; i < sequence.length() + 1; i++)
	{
		c = sequence[i];
		sum = p + c;
		if (sum.length() == 1) //if c is a single char it already exists in ASCII
		{
			p = sum;
		}
		else
		{
			if (!(bst->doesExist(sum)))
			{
				bst->insert(sum, codeCounter);
				if (p.length() == 1)
				{
					int a = (int)p[0];
					codeSequence.push_back(a); //eger tek charsa direk ascii deðeri pushbacklensin(STRINGIN ASCII DEGERI NASIL BULUNACAk)
				}
				else  //deðilse treeden kodunu bul
				{
					int b = bst->getCode(p);
					codeSequence.push_back(b);
				}

				p = c;
				codeCounter++;
			}
			else
			{
				p = sum;
			}

		}
	}


	return codeSequence;
}



int main() {
	BST<string> *bst = new BST<string>();
	string sequence;
	vector<int> codeSequence;

	ifstream compin;
	compin.open("compin.txt");

	while (getline(compin, sequence)){ //This loop fills the set with the search words and doc numbers{
		istringstream iss(sequence);
	}


	ofstream compout("compout.txt");
	

	codeSequence = lzwAlgorithm(sequence, bst);

	for (int i = 0; i < codeSequence.size(); i++){
		compout << codeSequence[i] << " ";

	}
	
	compout.close();

	return 0;
}