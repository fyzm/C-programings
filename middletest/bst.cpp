#include <iostream>
#include <string>
using namespace std;

template <typename Key, typename E>
class BSTNode
{
private:
    Key k;
    E x;
    E y;
    BSTNode* lc;
    BSTNode* rc;
public:
    BSTNode()
    {
        lc = rc = NULL;
    }

    BSTNode(Key K, E e, E c, BSTNode* l = NULL, BSTNode* r = NULL)
    {
        k = K;
        x = e;
        y = c;
        lc = l;
        rc = r;
    }

    ~BSTNode() {}

    E distance()
    {
        return (x * x + y * y);
    }
    E getx()
    {
        return x;
    }
    E gety()
    {
        return y;
    }
    void setElement(const E& e, const E& c)
    {
        x = e;
        y = c;
    }
    Key& key()
    {
        return k;
    }
    void setKey(const Key& K)
    {
        k = K;
    }
    inline BSTNode* left() const
    {
        return lc;
    }
    void setLeft(BSTNode<Key, E>* b)
    {
        lc = (BSTNode*)b;
    }
    inline BSTNode* right() const
    {
        return rc;
    }
    void setRight(BSTNode<Key, E>* b)
    {
        rc = (BSTNode*)b;
    }
    bool isLeaf()
    {
        return (lc == NULL) && (rc == NULL);
    }
};

template <typename Key, typename E>
class BST
{
private:
    BSTNode<Key, E>* root;
    int nodecount;

    void clearhelp(BSTNode<Key, E>* root) //delete all
    {
        if (root == NULL)
            return;
        clearhelp (root->left());
        clearhelp (root->right());
        delete root;
    }

    BSTNode<Key, E>* inserthelp(BSTNode<Key, E>* root, const Key& k, const E& it, const E& e)
    {
        if (root == NULL)
            return new BSTNode<Key, E>(k, it, e, NULL, NULL);
        if (k < root->key())
            root->setLeft(inserthelp(root->left(), k, it, e));
        else
            root->setRight(inserthelp(root->right(), k, it, e));
        return root;
    }

    BSTNode<Key, E>* getmin(BSTNode<Key, E>* rt)
    {
        if (rt->left() == NULL)
            return rt;
        else
            return getmin(rt->left());
    }

    BSTNode<Key, E>* deletemin(BSTNode<Key, E>* rt)
    {
        if (rt->left() == NULL)
            return rt->right();
        else
        {
            rt->setLeft(deletemin(rt->left()));
            return rt;
        }
    }

    BSTNode<Key, E>* removehelp(BSTNode<Key, E>* rt, const Key& k) //delete one
    {
        if (rt == NULL)
            return NULL;
        else if (k < rt->key())
            rt->setLeft(removehelp(rt->left(), k));
        else if (k > rt->key())
            rt->setRight(removehelp(rt->right(), k));
        else
        {
            BSTNode<Key, E>* temp = rt;

            if (rt->left() == NULL)
            {
                rt = rt->right();
                delete temp;
            }
            else if (rt->right() == NULL)
            {
                rt = rt->left();
                delete temp;
            }
            else
            {
                BSTNode<Key, E>* temp = getmin(rt->right());
                rt->setElement(temp->getx(), temp->gety());
                rt->setKey(temp->key());
                rt->setRight(deletemin(rt->right()));
                delete temp;
            }
        }
        return rt;
    }

    E findhelp(BSTNode<Key, E>* root, const Key& k) const
    {
        if (root == NULL)
            return 0;
        if (k < root->key())
            return findhelp(root->left(), k);
        else if (k > root->key())
            return findhelp(root->right(), k);
        else
            return root->distance();
    }

    void printhelp(BSTNode<Key, E>* root, int level) const
    {
        if (root == NULL) return;
        printhelp(root->left(), level + 1);
        cout << root->key() << endl;
        printhelp(root->right(), level + 1);
    }

    void find_distance_help(BSTNode<Key, E>* root, int d) const   //输出距离在給定值以内的城市
    {
        if (root == NULL)
            return;
        find_distance_help(root->left(), d);
        if (root->distance() <= d && root->distance() != 0)
            cout << root->key() << " " << root->distance() << endl;
        find_distance_help(root->right(), d);
    }

    void find_cityhelp(BSTNode<Key, E>* root, char c)
    {
        if (root == NULL)
            return;
        find_cityhelp(root->left(), c);
        Key* city;
        city = &root->key();
        if ((*city)[0] == c)
            cout << root->key() << endl;
        find_cityhelp(root->right(), c);
    }

public:
    BST()
    {
        root = NULL;
        nodecount = 0;
    }
    ~BST()
    {
        clearhelp(root);
    }

    void clear()
    {
        clearhelp(root);
        root = NULL;
        nodecount = 0;
    }

    void insert(const Key& k, const E& it, const E& e)
    {
        root = inserthelp(root, k, it, e);
        nodecount++;
    }

    E remove(const Key& k)
    {
        E temp = findhelp(root, k);
        if (temp != 0)
        {
            root = removehelp(root, k);
            nodecount--;
        }
        return temp;
    }

    E find(const Key& k) const
    {
        return findhelp(root, k);
    }

    void print() const
    {
        if (root == NULL)
            cout << "The BST is empty.\n";
        else
            printhelp(root, 0);
    }

    void finddistance(int d) const//输出指定距离的城市
    {

        find_distance_help(root, d);
    }

    void find_city(char c)
    {
        find_cityhelp(root, c);
    }
};


int main()
{
    BST<string, int> city;
    string s;
    int x, y;
    for (int i = 0; i < 5; i++)
    {
        cin >> s >> x >> y;
        city.insert(s, x, y);
    }
    city.print();
    string s1;
    //删除城市
    cin >> s1;
    city.remove(s1);
    city.print();

    //查找指定字母打头的城市
    char ci;
    cin >> ci;
    city.find_city(ci);

    //查找指定距离以内的城市
    int dis;
    cin >> dis;
    int dis1 = dis * dis;
    city.finddistance(dis1);
    return 0;
}