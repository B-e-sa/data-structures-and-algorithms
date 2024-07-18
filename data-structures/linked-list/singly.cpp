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

    void add(SinglyListNode *node, SinglyListNode *prev) {
        node->next = prev->next;
        prev->next = node;
    }
};

int main()
{
    SinglyLinkedList list;
    SinglyListNode firstNode(5, nullptr);
    SinglyListNode secondNode(13, nullptr);
    SinglyListNode thirdNode(98, nullptr);
    SinglyListNode fourthNode(71, nullptr);

    list.add(&firstNode);
    list.add(&secondNode);
    list.add(&thirdNode);
    list.add(&fourthNode, &firstNode);

    SinglyListNode *iterator = list.head;
    while (iterator != nullptr) {
        cout << iterator->value << "\n";
        iterator = iterator->next;
    }

    return 0;
}
