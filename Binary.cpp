#include <iostream>
using namespace std;

class BST
{

    struct node
    {
        int data;
        node *left;
        node *right;
    };

    node *root;

    node *makeEmpty(node *t)
    {
        if (t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    node *insert(int x, node *t)
    {
        if (t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if (x < t->data)
            t->left = insert(x, t->left);
        else if (x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    node *findMin(node *t)
    {
        if (t == NULL)
            return NULL;
        else if (t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node *findMax(node *t)
    {
        if (t == NULL)
            return NULL;
        else if (t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node *remove(int x, node *t)
    {
        node *temp;
        if (t == NULL)
            return NULL;
        else if (x < t->data)
            t->left = remove(x, t->left);
        else if (x > t->data)
            t->right = remove(x, t->right);
        else if (t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if (t->left == NULL)
                t = t->right;
            else if (t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    void inorder(node *t)
    {
        if (t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    void preorder(node *t)
    {
        if (t == NULL)
            return;

        cout << t->data << " ";
        preorder(t->left);
        preorder(t->right);
    }

    void postOrder(node *t)
    {
        if (t != NULL)
        {
            postOrder(t->left);
            postOrder(t->right);
            cout << t->data << " ";
        }
        else
        {
            return;
        }
    }

    int heightOfTree(node *t)
    {
        if (t == NULL)
            return -1;
        else
        {
            int left = heightOfTree(t->left);
            int right = heightOfTree(t->right);
            if (left > right)
                return left + 1;
            else
                return right + 1;
        }
    }

    void find(node *t, int x, int cont)
    {
        if (t == NULL)
        {
            cout << "-1\n";
            return;
        }
        else if (x < t->data)
        {
            cont = cont + 1;
            return find(t->left, x, cont);
        }
        else if (x > t->data)
        {
            cont = cont + 1;
            return find(t->right, x, cont);
        }
        else
            cout << cont << endl;
        return;
    }

    bool ancestors(node *root, int target)
    {
        if (root == NULL)
            return false;
        if (root->data == target)
            return true;
        if (ancestors(root->left, target) || ancestors(root->right, target))
        {
            cout << root->data << " ";
            return true;
        }
        return false;
    }

public:
    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        root = makeEmpty(root);
    }

    void insert(int x)
    {

        root = insert(x, root);
    }

    void remove(int x)
    {
        root = remove(x, root);
    }

    void displayInorder()
    {
        inorder(root);
        cout << endl;
    }

    void displayPreorder()
    {
        preorder(root);
        cout << endl;
    }

    void displayPostorder()
    {
        postOrder(root);
        cout << endl;
    }

    void whatlevelamI(int x)
    {
        find(root, x, 0);
    }

    int height()
    {
        int h = heightOfTree(root);
        return h;
    }

    void ancestorsNodes(int x)
    {
        ancestors(root, x);
    }
};

int main()
{
    BST t;

    t.insert(11);
    t.insert(47);
    t.insert(26);
    t.insert(62);
    t.insert(99);
    t.insert(20);
    t.insert(69);
    t.insert(11);
    t.insert(90);
    t.insert(21);

    cout << "Preorder Tansvesal\n";
    t.displayPreorder();
    cout << "Inorder Tansvesal\n";
    t.displayInorder();
    cout << "Postorder Tansvesal\n";
    t.displayPostorder();
    cout << "Heigth: " << t.height() << endl;
    cout << "El numero 26 se encuetra en la Height ";
    t.whatlevelamI(26);
    cout << "El numero 999 no se encuentra ";
    t.whatlevelamI(999);
    cout << "Los ancestros del numero 99 son: ";
    t.ancestorsNodes(99);

    return 0;
}
