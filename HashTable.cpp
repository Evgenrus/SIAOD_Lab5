//
// Created by EVGEN on 24.02.2021.
//

#ifndef LAB5_HASHTABLE_CPP
#define LAB5_HASHTABLE_CPP

#include "HashTable.h"
#include <cmath>
#include <memory.h>

#define A (sqrt(5)-1)/2

namespace Lab5
{

    static int probes = 0;

    HashTable::HashTable(unsigned size, int *data) : m_size(size)
    {
        if(data != nullptr) {
            m_data = new int[size];
            std::copy(data, data + size, m_data);
        } else {
            m_data = new int[size];
            memset(m_data, 0, m_size);//обнуление памяти
        }
    }

    int HashTable::Hash(int element) {
        return (m_size*fmod(element * A, 1));
    }

    int HashTable::findElement(int element) {
        int i = 0;
        bool found = false;
        while(!found && i<m_size) {
            i = Collision(element, i);
            if(m_data[i] == element)
                break;
        }

        if (m_data[i] != element) {
            std::cout << "Ошибка, не получилось найти нужный элемент" << std::endl;
            return -1;
        }
        std::cout << "Probes: " << probes << std::endl;
        probes = 0;
        return i;
    }

    int HashTable::addElement(int element) {
        unsigned i = 0;
        bool inserted = false;
        while(!inserted && i < m_size) {
            i = Collision(element, i);
            if(m_data[i] != 0) {
                m_data[i] = element;
                break;
            }
        }
        std::cout << "Probes: " << probes << std::endl;
        probes = 0;
        return i;
    }

    bool HashTable::removeElement(unsigned key) {
        return false;
    }

    unsigned HashTable::Collision(int element, int i) {
        unsigned num = (Hash(element) + i*i + i) % m_size;
        if(m_data[num] != 0 && num < m_size && m_data[num] != element)
            num = Collision(element, ++i);
        if(num >= m_size)
            throw std::out_of_range("HashTable: Key is out of range;");
        return num;

    }     

}


#endif