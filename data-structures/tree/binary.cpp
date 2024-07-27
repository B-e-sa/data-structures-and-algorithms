// root
// nodes <- um parente <- multiplos
//                     <- filhos
//
// em arvores binarias, nodes só podem ter no maximo dois filhos
//
// nodes sem filhos -> leaf nodes
//
// breath first traversal -> olha nodes por niveis
//
// depth first traversal -> olhar parentes primeiro
#include <iostream>
using namespace std;

class Node
{
public:
    Node *leftNode = nullptr;
    Node *rightNode = nullptr;
    int value;

    Node(int value, Node *leftNode = nullptr, Node *rightNode = nullptr)
    {
        this->value = value;
        this->leftNode = leftNode;
        this->rightNode = rightNode;
    }
};

class Tree
{
public:
    Node *root = nullptr;

    void add(int value)
    {
        Node *newNode = new Node(value);
        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        Node *currentNode = root;
        while (true)
        {
            if (newNode->value < currentNode->value)
            {
                if (currentNode->leftNode == nullptr)
                {
                    currentNode->leftNode = newNode;
                    break;
                }
                currentNode = currentNode->leftNode;
            }
            else
            {
                if (currentNode->rightNode == nullptr)
                {
                    currentNode->rightNode = newNode;
                    break;
                }
                currentNode = currentNode->rightNode;
            }
        }
    }
};

int main()
{
    Tree *tree = new Tree();

    tree->add(5);
    tree->add(2);
    tree->add(10);
    tree->add(3);

    // tree representation
    //    (5)
    //    / \
    // (2) (10)
    //   \
    //  (3)
}