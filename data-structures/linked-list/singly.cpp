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
};

int main()
{
    SinglyLinkedList list;
    SinglyListNode firstNode(1, nullptr);
    SinglyListNode secondNode(2, nullptr);
    SinglyListNode thirdNode(3, nullptr);
    SinglyListNode fourthNode(4, nullptr);
    SinglyListNode fifthNode(5, nullptr);

    list.add(&firstNode);
    list.add(&secondNode);
    list.add(&thirdNode); // > 1, 2, 3
    list.add(&fourthNode, &firstNode); // > 1, 4, 2, 3 
    list.add(&fifthNode, true); // > 5, 1, 4, 2, 3
    list.deleteNode(&secondNode); // > 5, 1, 4, 3
    list.show();

    return 0;
}
