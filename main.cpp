#include <iostream>
#include "HashTable.h"

//15. �������� ���������, ������� ��������� ����� ��������� ����������� � ������������ �������������������
//���� � ���-��������, ���������� �� ������ ���������. ������, ���������� � ����� ������� � ���-�������.
//���� ������ ��������� �� ����� 15 ����� �����. ������� ����������� ���-������� �� �����
//(������ � ����������� ����������� ����). ������������ ����� ������ � ���-�������.
//���������� ������ ������ ������� �� �����. ����� ������� ���������� ����, ������� ���� ��������� ��� ������.

using namespace Lab5;

int main() {
    int* temp;
    temp = new int[15];
    unsigned size = 50;
    temp[0] = 1;
    for(int i=1; i<15; i++) {
        temp[i] = 250*rand();
    }
    HashTable A(50);
    for(int i=0; i<15; i++) {
        A.addElement(temp[i]);
    }
    A.findElement(1);

    return 0;
}