#include <iostream>
using namespace std;

class HashMap
{
private:
    static const int BUCKET_COUNT = 5;
    static const int bucketSizes[BUCKET_COUNT];

    int hash(int key)
    {
        return key % BUCKET_COUNT;
    }

    struct HashMapNode
    {
        int key;
        int value;
        HashMapNode *next;
    };

    HashMapNode table[BUCKET_COUNT];

public:
    void insert(int key, int value)
    {
        int index = hash(key);

        if (bucketSizes[index] != 0)
        {
            HashMapNode newNode = {key, value, nullptr};
            table[index].next = &newNode;
            return;
        }
    };
};

int main()
{
    HashMap hm;
    hm.insert(1, 10);
    hm.insert(1, 10);
    hm.insert(5, 11);
    return 0;
}