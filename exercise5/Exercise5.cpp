#include <iostream>
#include <cstring>
#include <stdexcept>
#include "Exercise5.h"
using namespace std;

/* Part 1 - template functions */
template<class T>
bool equal(T a, T b, T c) {
  bool result;
  a != b ? result = false :
    b != c ? result = false :
      result = true;
  return result;
}

bool equal(const char * a, const char * b, const char * c) {
  bool result;
  strcmp(a, b) != 0 ? result = false :
    strcmp(b, c) != 0 ? result = false :
      result = true;
  return result;
}

/* Part 2 - template classes */
/* Class NodeBST */
template<class T>
bool NodeBST<T>::contains(T val) const {
	if (val == data) return true;
	NodeBST* next = (val < data) ? left : right;
	return (next != NULL) ? next->contains(val) : false;
}

template<class T>
bool NodeBST<T>::insert(T val) {
  // if (val == data) return false;
	if (val == data)
    throw std::invalid_argument("Value You want to add is currently in tree");

	NodeBST* & next = (val < data) ? left : right;
	if (next == NULL) {
		next = new NodeBST(val);
		return true;
	}
	else return next->insert(val);
}

template<class T>
void NodeBST<T>::print() const {
	if (left != NULL) left->print();
	cout << data << " ";
	if (right != NULL) right->print();
}

/* Class TreeBST */
template<class T>
bool TreeBST<T>::insert(T val) {
	if (root == NULL) {
		root = new NodeBST<T>(val);
		return true;
	}
	else return root->insert(val);
}

template<class T>
void TreeBST<T>::print() const {
	cout << "tree: [";
	if (root == NULL) cout << "empty" << endl;
	else root->print();
	cout << "]" << endl;
}

/* The extrovert */
template<class T>
ostream& operator<<(ostream& o, const TreeBST<T>& t) {
  o << "tree: [";
  (t.root == NULL) ? o << "empty" : o << "not-empty"; 
  o << "]" << endl;
}

int main(int argc, char ** argv) {
  const char a[4] = "ala";
  const char b[4] = "ala";
  const char c[4] = "ala";
  cout << (a == b) << endl;
  cout << equal(a, b, c) << endl;
  cout << equal(1, 1, 1) << endl;

  TreeBST<int> tree;
  tree.insert(13);
  tree.insert(1);
  tree.insert(33);
  tree.insert(5);
  tree.insert(28);
  tree.insert(7);
  try {
    tree.insert(7);
  }
  catch(const invalid_argument& e) {
    cout << endl << "Cought exception!" << endl;
  }

  tree.print();
  cout << tree;
  return 0;
}
