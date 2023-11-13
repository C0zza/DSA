// DSA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DataStructures/LinkedList.h"

int main()
{
    LinkedList<int> IntLinkedList;

    IntLinkedList.Add(1);
    IntLinkedList.Add(2);
    IntLinkedList.Add(3);

    IntLinkedList.Print();
    std::cin.get();

    IntLinkedList.Insert(0, 0);
    IntLinkedList.Insert(1, 1);
    IntLinkedList.Insert(4, 5);

    IntLinkedList.Print();
    std::cin.get();

    IntLinkedList.ReverseRecursively();
    IntLinkedList.Print();
    std::cin.get();

    IntLinkedList.ReverseRecursively();
    IntLinkedList.Print();
    std::cin.get();

    /*IntLinkedList.Remove(0);
    IntLinkedList.Print();
    std::cin.get();
    
    IntLinkedList.Remove(3);
    IntLinkedList.Print();
    std::cin.get();

    IntLinkedList.Remove(IntLinkedList.Count() - 1);
    IntLinkedList.Print();
    std::cin.get();*/

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
