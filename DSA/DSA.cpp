// DSA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "DataStructures/DoublyLinkedList.h"
#include "DataStructures/LinkedList.h"

void TestLinkedList();
void TestDoublyLinkedList();

int main()
{
    TestDoublyLinkedList();

    return 0;
}

void TestLinkedList()
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
}

void TestDoublyLinkedList()
{
    DoublyLinkedList<int> List;

    List.InsertAtEnd(1);
    List.InsertAtEnd(2);
    List.InsertAtEnd(3);
    List.InsertAtEnd(4);
    List.InsertAtEnd(5);

    List.Print();
    std::cin.get();

    List.ReversePrint();
    std::cin.get();
}
