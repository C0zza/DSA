#pragma once

#include <iostream>

template<typename T>
class DoublyLinkedList
{
public:
	~DoublyLinkedList()
	{
		Node* Current = Start;

		while (Current)
		{
			Node* Next = Current->Next;
			delete Current;
			Current = Next;
		}
	}

	void InsertAtStart(const T& Value)
	{
		Node* NewNode = new Node;
		NewNode->Data = Value;

		if (Start)
		{
			NewNode->Next = Start;
			Start->Previous = NewNode;
			Start = NewNode;
		}
		else
		{
			Start = NewNode;
			End = NewNode;
		}
	}

	void InsertAtEnd(const T& Value)
	{
		Node* NewNode = new Node;
		NewNode->Data = Value;

		if (End)
		{
			End->Next = NewNode;
			NewNode->Previous = End;
			End = NewNode;
		}
		else
		{
			Start = NewNode;
			End = NewNode;
		}
	}

	void Print()
	{
		const Node* Current = Start;

		while (Current)
		{
			Current->Print();
			std::cout << " -> ";
			Current = Current->Next;
		}

		std::cout << "\n";
	}

	void ReversePrint()
	{
		const Node* Current = End;
		while (Current)
		{
			Current->Print();
			std::cout << " -> ";
			Current = Current->Previous;
		}

		std::cout << "\n";
	}

private:
	class Node
	{
	public:
		Node* Next = nullptr;
		Node* Previous = nullptr;
		T Data;

		void Print() const
		{
			std::cout << "[" << Data << "]";
		}
	};

	Node* Start = nullptr;
	Node* End = nullptr;
};

