#include <iostream>
#include <cstring>
#include <stdexcept>
#include "Exercise5.h"
using namespace std;

/* Part 1 - template functions */
/* #Always increasing */
template<class T>
bool equal(T a, T b, T c) {
  bool result;
  a >= b ? result = false :
    b >= c ? result = false :
      result = true;
  return result;
}

bool equal(const char * a, const char * b, const char * c) {
  bool result;
  strcmp(a, b) >= 0 ? result = false :
    strcmp(b, c) >= 0 ? result = false :
      result = true;
  return result;
}

/* Part 2 - template classes */
/* Class Node */
template<class T>
Node<T> * Node<T>::getNextValue() {
  return next;
  // Node * last = next;
  // while(last != NULL)
  //   last = last -> next;
  // return last;
}

template<class T>
bool Node<T>::contains(T val) const {
	if (val == data) return true;
	Node* _next = next;
	return (_next != NULL) ? _next->contains(val) : false;
}

template<class T>
bool Node<T>::insert(T val) {
	if (val == data)
    throw std::invalid_argument("Value You want to add is currently in tree");

	Node* & _next = next;
	if (_next == NULL) {
		_next = new Node(val);
		return true;
	}
	else return _next->insert(val);
}

template<class T>
void Node<T>::print() const {
	if (next != NULL) next->print();
	cout << data << " ";
}

/* Class LinkedList */
template<class T>
LinkedList<T>::~LinkedList() {
  if(root == NULL)
    return;
  Node<T>* old;
  while(root != NULL) {
    old = root;
    root = root -> next;
    delete(old);
  }
}

template<class T>
bool LinkedList<T>::insert(T val) {
	if (root == NULL) {
		root = new Node<T>(val);
		return true;
	}
	else return root->insert(val);
}

template<class T>
bool LinkedList<T>::removeHead() {
  if(root == NULL) return true;
  Node<T>* old = root;
  root = root -> next;
  delete(old);
}


template<class T>
void LinkedList<T>::print() const {
	cout << "tree: [";
	if (root == NULL) cout << "empty" << endl;
	else root->print();
	cout << "]" << endl;
}

/* The extrovert */
template<class T>
ostream& operator<<(ostream& o, const LinkedList<T>& t) {
  o << "tree: [";
  (t.root == NULL) ? o << "empty" : o << "not-empty";
  o << "]" << endl;
}

int main(int argc, char ** argv) {
  const char a[4] = "ala";
  const char b[4] = "alb";
  const char c[4] = "alc";
  cout << (a == b) << endl;
  cout << equal(a, b, c) << endl;
  cout << equal(1, 1, 1) << endl;
  cout << equal(1, 2, 3) << endl;

  LinkedList<int> tree;
  tree.insert(13);
  tree.insert(1);
  tree.insert(33);
  tree.insert(5);
  tree.insert(28);
  tree.insert(7);
  tree.removeHead();
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
