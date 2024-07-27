#include <iostream>

using namespace std;

class Node
{
public:
    Node(int val, Node *next = nullptr)
    {
        this->next = next;
        this->val = val;
    }
    int val;
    Node *next;
};

class SinglyLinkedList
{
public:
    Node *head = nullptr;
    void add(int val)
    {
        Node *n = new Node(val);
        if (head == nullptr)
        {
            head = n;
            return;
        }

        Node *currentNode = head;
        while (currentNode->next != nullptr)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = n;
    }

    void addBefore(int val, int prev)
    {
        Node *currentNode = head;
        while (currentNode->next != nullptr)
        {
            if (currentNode->val == prev)
            {
                Node *n = new Node(val);
                n->next = currentNode->next;
                currentNode->next = n;
                break;
            }

            currentNode = currentNode->next;
        }
    }

    void addBeforeHead(int val)
    {
        Node *n = new Node(val);
        n->next = head;
        head = n;
    }

    void deleteNode(int val)
    {
        if (val == head->val)
        {
            head = head->next;
            return;
        }

        Node *currentNode = head;
        while (currentNode->next->val != val)
        {
            if (currentNode == nullptr)
                return;
            currentNode = currentNode->next;
        }
        currentNode->next = currentNode->next->next;
    }

    void show()
    {
        Node *iterator = head;
        while (iterator != nullptr)
        {
            cout << iterator->val << "\n";
            iterator = iterator->next;
        }
    }

    int contains(int val)
    {
        Node *iterator = head;
        while (iterator != nullptr)
        {
            if (iterator->val == val)
                return true;
            iterator = iterator->next;
        }

        return false;
    }
};

int main()
{
    SinglyLinkedList list;
    Node fourthNode(4);
    Node fifthNode(5);

    list.add(1);
    list.add(2);
    list.addBefore(4, 1);  // > 1, 4, 2
    list.addBeforeHead(5); // > 5, 1, 4, 2
    list.deleteNode(2);    // > 5, 1, 4
    list.contains(4);      // true
    list.contains(10);     // false

    return 0;
}
