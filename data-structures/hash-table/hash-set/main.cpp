#include <iostream>
using namespace std;

class HashSet
{
private:
    static const int BUCKET_COUNT = 5;
    static const int BUCKET_SIZE = 10;
    int bucketSizes[BUCKET_SIZE];

    int hash(int key)
    {
        return key % BUCKET_COUNT;
    }

    int table[BUCKET_COUNT][BUCKET_SIZE];

public:
    HashSet()
    {
        for (int i = 0; i < BUCKET_COUNT; i++)
        {
            bucketSizes[i] = 0;
            for (int j = 0; j < BUCKET_SIZE; j++)
            {
                table[i][j] = -1;
            }
        }
    }

    void insert(int key)
    {
        int index = hash(key);
        int bucketSize = bucketSizes[index];
        int *currentTable = table[index];

        if (bucketSize == BUCKET_SIZE)
            return;

        if (bucketSize == 0)
        {
            currentTable[0] = key;
            bucketSizes[index]++;
            return;
        }

        for (int i = 0; i < bucketSize; i++)
        {
            if (currentTable[i] == key)
                return;
        }

        currentTable[bucketSize] = key;
    }

    void show()
    {
        for (int i = 0; i < this->BUCKET_COUNT; i++)
        {
            cout << i << ":\n";
            for (int j = 0; j < this->BUCKET_SIZE; j++)
            {
                if (this->table[i][j] == -1)
                    continue;
                cout << "  " << this->table[i][j] << "\n";
            }
        }
    }
};

int main()
{
    HashSet hs;
    hs.insert(5);
    hs.insert(10);
    hs.insert(4);
    hs.show(); // 5, 10, 4

    return 0;
}