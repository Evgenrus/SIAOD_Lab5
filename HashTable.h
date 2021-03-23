#ifndef LAB5_HASHTABLE_H
#define LAB5_HASHTABLE_H

#include <iostream>

namespace Lab5 {

    class HashTable {

    private:
        unsigned m_size;
        int* m_data;

    public:
        explicit HashTable(unsigned size = 0, int* data = nullptr);

        int Hash(int element);
        int addElement(int element);
        bool removeElement(unsigned key);
        int findElement(int element);

        unsigned Collision(int element, int i);

    };
}




#endif //LAB5_HASHTABLE_H
