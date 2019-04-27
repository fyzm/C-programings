#include <iostream>
#include <string>
#include <cmath>
using namespace std;
template<typename E> class BinNode {
public:
	virtual ~BinNode() {
	}
	virtual E& element() = 0;
	virtual void setElement(const E&, const E&) = 0;
	virtual BinNode* left() const = 0;
	virtual void setLeft(BinNode*) = 0;
	virtual BinNode* right() const = 0;
	virtual void setRight(BinNode*) = 0;
	virtual bool isLeaf() = 0;
};
template<typename Key, typename E>
class Dictionary {
private:
	void operator =(const Dictionary&) {
	}
	Dictionary(const Dictionary&) {
	}

public:
	Dictionary() {
	}          // Default constructor
	virtual ~Dictionary() {
	} // Base destructor
	virtual void clear() = 0;
	virtual void insert(const Key& k, const E& e1, const E& e2)= 0;
	virtual E remove(const Key& k) = 0;
	virtual E removeAny() = 0;
	virtual E find(const Key& k) const = 0;
	virtual int size() = 0;
};
template<typename Key, typename E>
class BSTNode: public BinNode<E> {
private:
	Key k;
	E x;
	E y;
	BSTNode* lc;
	BSTNode* rc;
public:
	BSTNode() {
		lc = rc = NULL;
	}
	BSTNode(Key K, E e, E c, BSTNode* l = NULL, BSTNode* r = NULL) {
		k = K;
		x = e;
		y = c;
		lc = l;
		rc = r;
	}
	~BSTNode() {
	}

	float distance(int m, int n) {
		return sqrt(pow(x - m, 2) + pow(y - n, 2));
	}
	E getx() {
		return x;
	}
	E gety() {
		return y;
	}

	E& element() {
		return x;
	}

	void setElement(const E& e1, const E& e2) {
		x = e1;
		y = e2;
	}
	Key& key() {
		return k;
	}
	void setKey(const Key& K) {
		k = K;
	}
	inline BSTNode* left() const {
		return lc;
	}
	void setLeft(BinNode<E>* b) {
		lc = (BSTNode*) b;
	}
	inline BSTNode* right() const {
		return rc;
	}
	void setRight(BinNode<E>* b) {
		rc = (BSTNode*) b;
	}
	bool isLeaf() {
		return (lc == NULL) && (rc == NULL);
	}
};

template<typename Key, typename E>
class BST: public Dictionary<Key, E> {
private:
	BSTNode<Key, E>* root;   // Root of the BST
	int nodecount;         // Number of nodes in the BST
	void clearhelp(BSTNode<Key, E>*);
	BSTNode<Key, E>* inserthelp(BSTNode<Key, E>*, const Key&, const E&,
			const E&);
	BSTNode<Key, E>* deletemin(BSTNode<Key, E>*);
	BSTNode<Key, E>* getmin(BSTNode<Key, E>*);
	BSTNode<Key, E>* removehelp(BSTNode<Key, E>*, const Key&);
	E findhelp(BSTNode<Key, E>*, const Key&) const;
	void printhelp(BSTNode<Key, E>*, int) const;
	void find_distance_help(BSTNode<Key, E>* root, int x, int y, int d) const;
	void find_cityhelp(BSTNode<Key, E>* root, char c);
public:
	BST() {
		root = NULL;
		nodecount = 0;
	}  // Constructor
	~BST() {
		clearhelp(root);
	}            // Destructor

	void clear()   // Reinitialize tree
	{
		clearhelp(root);
		root = NULL;
		nodecount = 0;
	}

	void insert(const Key& k, const E& e1, const E& e2) {
		root = inserthelp(root, k, e1, e2);
		nodecount++;
	}

	E remove(const Key& k) {
		E temp = findhelp(root, k);   // First find it
		if (temp != NULL) {
			root = removehelp(root, k);
			nodecount--;
		}
		return temp;
	}
	E removeAny() {  // Delete min value
		if (root != NULL) {
			E temp = root->element();
			root = removehelp(root, root->key());
			nodecount--;
			return temp;
		} else
			return NULL;
	}
	E find(const Key& k) const {
		return findhelp(root, k);
	}

	int size() {
		return nodecount;
	}
	void print() const { // Print the contents of the BST
		if (root == NULL)
			cout << "The BST is empty.\n";
		else
			printhelp(root, 0);
	}
	void finddistance(int x, int y, int d) const {   //输出指定距离的城市
		find_distance_help(root, x, y, d);
	}
	void find_city(char c) {
		find_cityhelp(root, c);
	}
};

// Clean up BST by releasing space back free store
template<typename Key, typename E>
void BST<Key, E>::clearhelp(BSTNode<Key, E>* root) {
	if (root == NULL)
		return;
	clearhelp(root->left());
	clearhelp(root->right());
	delete root;
}

// Insert a node into the BST, returning the updated tree
template<typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::inserthelp(BSTNode<Key, E>* root, const Key& k,
		const E& e1, const E& e2) {
	if (root == NULL)  // Empty tree: create node
		return new BSTNode<Key, E>(k, e1, e2, NULL, NULL);
	if (k < root->key())
		root->setLeft(inserthelp(root->left(), k, e1, e2));
	else
		root->setRight(inserthelp(root->right(), k, e1, e2));
	return root;       // Return tree with node inserted
}

// Delete the minimum value from the BST, returning the revised BST
template<typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::getmin(BSTNode<Key, E>* rt) {
	if (rt->left() == NULL)
		return rt;
	else
		return getmin(rt->left());
}
template<typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::deletemin(BSTNode<Key, E>* rt) {
	if (rt->left() == NULL) // Found min
		return rt->right();
	else {                      // Continue left
		rt->setLeft(deletemin(rt->left()));
		return rt;
	}
}

// Remove a node with key value k
// Return: The tree with the node removed
template<typename Key, typename E>
BSTNode<Key, E>* BST<Key, E>::removehelp(BSTNode<Key, E>* rt, const Key& k) {
	if (rt == NULL)
		return NULL;    // k is not in tree
	else if (k < rt->key())
		rt->setLeft(removehelp(rt->left(), k));
	else if (k > rt->key())
		rt->setRight(removehelp(rt->right(), k));
	else {                            // Found: remove it
		BSTNode<Key, E>* temp = rt;
		if (rt->left() == NULL) {     // Only a right child
			rt = rt->right();         //  so point to right
			delete temp;
		} else if (rt->right() == NULL) { // Only a left child
			rt = rt->left();          //  so point to left
			delete temp;
		} else {                    // Both children are non-empty
			BSTNode<Key, E>* temp = getmin(rt->right());
			rt->setElement(temp->getx(), temp->gety());
			rt->setKey(temp->key());
			rt->setRight(deletemin(rt->right()));
			delete temp;
		}
	}
	return rt;
}

// Find a node with the given key value
template<typename Key, typename E>
E BST<Key, E>::findhelp(BSTNode<Key, E>* root, const Key& k) const {
	if (root == NULL)
		return NULL;          // Empty tree
	if (k < root->key())
		return findhelp(root->left(), k);   // Check left
	else if (k > root->key())
		return findhelp(root->right(), k);  // Check right
	else
		return root->element();  // Found it
}

// Print out a BST
template<typename Key, typename E>
void BST<Key, E>::printhelp(BSTNode<Key, E>* root, int level) const {
	if (root == NULL)
		return;           // Empty tree
	printhelp(root->left(), level + 1);   // Do left subtree
	cout << root->key() << "\n";        // Print node value
	printhelp(root->right(), level + 1);  // Do right subtree
}

template<typename Key, typename E>
void BST<Key, E>::find_distance_help(BSTNode<Key, E>* root, int x, int y,
		int d) const { //5
	if (root == NULL)
		return;
	find_distance_help(root->left(), x, y, d);
	if (root->distance(x, y) <= (float)d && root->distance(x, y) != 0)
		cout << root->key() << " " << root->getx() << " " << root->gety()
				<< endl;
	find_distance_help(root->right(), x, y, d);
}

template<typename Key, typename E>
void BST<Key, E>::find_cityhelp(BSTNode<Key, E>* root, char c) {//5
	if (root == NULL)
		return;
	find_cityhelp(root->left(), c);
	if (root->key()[0] == c)
		cout << root->key() << " " << root->getx() << " " << root->gety()
				<< endl;
	find_cityhelp(root->right(), c);
}

int main() {

	BST<string, int> city;
	string cityName;
	int num, x, y;
	int flag;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> cityName >> x >> y;
		city.insert(cityName, x, y);
	}
	while (true) { //3
		cin >> flag;
		if (flag == 0) {
			cin >> cityName;
			city.remove(cityName);
		} else if (flag == 1) {
			cin >> cityName >> x >> y;
			city.insert(cityName, x, y);
		} else {
			break;
		}
	}

	city.print();

	//查找指定字母打头的城市
	char ci;
	cin >> ci;
	city.find_city(ci);

	//查找指定距离以内的城市
	int m, n, dis;
	cin >> m >> n >> dis;
	city.finddistance(m, n, dis);
	return 0;
}
