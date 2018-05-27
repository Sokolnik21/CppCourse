class NodeBST
{
	int data;
	NodeBST* left;
	NodeBST* right;
public:
	NodeBST(int _data) : data(_data), left(NULL), right(NULL) {}
	bool contains(int val) const;
	bool insert(int val);
	void print() const;
};

bool NodeBST::contains(int val) const {
	if (val == data) return true;
	NodeBST* next = (val < data) ? left : right;
	return (next != NULL) ? next->contains(val) : false;
}

bool NodeBST::insert(int val) {
	if (val == data) return false;
	NodeBST* & next = (val < data) ? left : right;
	if (next == NULL) {
		next = new NodeBST(val);
		return true;
	}
	else return next->insert(val);
}

void NodeBST::print() const {
	if (left != NULL) left->print();
	cout << data << " ";
	if (right != NULL) right->print();
}

class TreeBST
{
	NodeBST* root;
public:
	TreeBST() : root(NULL) {}
	bool contains(int val) const { return (root != NULL) ? root->contains(val) : false; }
	bool insert(int val);
	void print() const;
};

bool TreeBST::insert(int val) {
	if (root == NULL) {
		root = new NodeBST(val);
		return true;
	}
	else return root->insert(val);
}

void TreeBST::print() const {
	cout << "tree: [";
	if (root == NULL) cout << "empty" << endl;
	else root->print();
	cout << "]" << endl;
}
