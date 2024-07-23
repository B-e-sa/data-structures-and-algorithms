#include <iostream>

using namespace std;

class SinglyListNode
{
public:
    SinglyListNode(int value, SinglyListNode *next = nullptr)
    {
        this->next = next;
        this->value = value;
    }
    int value;
    SinglyListNode *next;
};

class SinglyLinkedList
{
public:
    SinglyListNode *head = nullptr;
    void add(SinglyListNode *node)
    {
        if (head == nullptr)
        {
            head = node;
            return;
        }

        SinglyListNode *currentNode = head;
        while (currentNode->next != nullptr)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = node;
    }

    void add(SinglyListNode *node, SinglyListNode *prev)
    {
        node->next = prev->next;
        prev->next = node;
    }

    void add(SinglyListNode *node, bool beforeHead)
    {
        node->next = head;
        head = node;
    }

    void deleteNode(SinglyListNode *node)
    {
        if (node == head)
        {
            head = head->next;
            return;
        }

        SinglyListNode *currentNode = head;
        while (currentNode->next != node)
        {
            if (currentNode == nullptr)
                return;
            currentNode = currentNode->next;
        }
        currentNode->next = currentNode->next->next;
    }

    void show()
    {
        SinglyListNode *iterator = head;
        while (iterator != nullptr)
        {
            cout << iterator->value << "\n";
            iterator = iterator->next;
        }
    }

    int contains(int value)
    {
        SinglyListNode *iterator = head;
        while (iterator != nullptr)
        {
            if (iterator->value == value)
                return true;
            iterator = iterator->next;
        }

        return false;
    }
};

int main()
{
    SinglyLinkedList list;
    SinglyListNode firstNode(1);
    SinglyListNode secondNode(2);
    SinglyListNode thirdNode(3);
    SinglyListNode fourthNode(4);
    SinglyListNode fifthNode(5);

    list.add(&firstNode);
    list.add(&secondNode);
    list.add(&thirdNode);              // > 1, 2, 3
    list.add(&fourthNode, &firstNode); // > 1, 4, 2, 3
    list.add(&fifthNode, true);        // > 5, 1, 4, 2, 3
    list.deleteNode(&secondNode);      // > 5, 1, 4, 3
    list.contains(4);                  // true
    list.contains(10);                 // false
    list.show();

    return 0;
}
