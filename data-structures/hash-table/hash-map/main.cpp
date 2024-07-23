#include <iostream>
using namespace std;

// linked list implementation
class Node
{
public:
    Node(int key, int value, Node *next = nullptr)
    {
        this->key = key;
        this->value = value;
        this->next = next;
    }
    int value;
    int key;
    Node *next;
};

class HashMapLinkedList
{
public:
    Node *head = nullptr;
    void add(Node *node)
    {
        if (head == nullptr)
        {
            head = node;
            return;
        }

        Node *currentNode = head;
        while (currentNode->next != nullptr)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = node;
    }

    void deleteNode(Node *node)
    {
        if (node == head)
        {
            head = head->next;
            return;
        }

        Node *currentNode = head;
        while (currentNode->next != node)
        {
            if (currentNode == nullptr)
                return;
            currentNode = currentNode->next;
        }
        currentNode->next = currentNode->next->next;
    }

    bool contains(int key)
    {
        Node *iterator = head;
        while (iterator != nullptr)
        {
            if (iterator->key == key)
                return true;
            iterator = iterator->next;
        }

        return false;
    }

    int get(int key)
    {
        Node *iterator = head;
        while (iterator != nullptr)
        {
            if (iterator->key == key)
                return iterator->value;
            iterator = iterator->next;
        }

        return -1;
    }
};

class HashMap
{
private:
    static const int BUCKET_COUNT = 5;
    static const int BUCKET_SIZE = 10;

    int hash(int key)
    {
        return key % BUCKET_COUNT;
    }

    HashMapLinkedList table[BUCKET_COUNT][BUCKET_SIZE];

public:
    void insert(int key, int value)
    {
        int index = hash(key);
        Node *newNode = new Node(key, value);
        table[index]->add(newNode);
    }

    int get(int key)
    {
        int index = hash(key);
        return table[index]->get(key);
    }
};

int main()
{
    HashMap hm;
    hm.insert(5, 10);  // table[0]->head == [5,10]
    hm.insert(10, 32); // table[0]->head->next == [10, 32]
    hm.get(10);        // 32

    return 0;
}