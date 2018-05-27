#include <iostream>
#include <cstring>
using namespace std;

/* Part 2 - template classes */
template<class T>
class NodeBST
{
	T data;
	NodeBST* left;
	NodeBST* right;
public:
	NodeBST(T _data) : data(_data), left(NULL), right(NULL) {}
	bool contains(T val) const;
	bool insert(T val);
	void print() const;
};

template<class T>
class TreeBST
{
	NodeBST<T> * root;
public:
	TreeBST() : root(NULL) {}
	bool contains(T val) const { return (root != NULL) ? root->contains(val) : false; }
	bool insert(T val);
	void print() const;

  /* The extrovert */
  template <class U>
  friend ostream& operator<<(ostream&, const TreeBST<U>&);
};
