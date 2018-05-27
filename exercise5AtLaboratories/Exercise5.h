#include <iostream>
#include <cstring>
using namespace std;

/* Part 2 - template classes */
template<class T>
class Node
{
	T data;
	Node<T>& operator=(const Node<T>&);
public:
	Node* next;
	Node * getNextValue();
	Node(T _data) : data(_data), next(NULL) {}
	bool contains(T val) const;
	bool insert(T val);
	void print() const;
};

template<class T>
class LinkedList
{
	Node<T> * root;
	LinkedList(const LinkedList& LL);
	LinkedList<T>& operator=(const LinkedList<T>&);
public:
	LinkedList() : root(NULL) {}
	~LinkedList();
	bool contains(T val) const { return (root != NULL) ? root->contains(val) : false; }
	bool insert(T val);
	bool removeHead();
	void print() const;

  /* The extrovert */
  template <class U>
  friend ostream& operator<<(ostream&, const LinkedList<U>&);
};
