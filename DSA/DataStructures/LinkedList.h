#pragma once

#include <cassert>
#include <iostream>

template<typename T>
class LinkedList
{
public:
	~LinkedList()
	{
		Node* Current = Start;
		while (Current)
		{
			Node* Next = Current->Next;
			delete Current;
			Current = Next;
		}
	}

	void Add(const T& Value)
	{
		Node* NextNode = Start;

		NextNode = new Node();
		NextNode->Data = Value;

		if (!Size)
		{
			Start = NextNode;
		}
		else
		{
			Node* LastNode = GetIndex(Count() - 1);
			assert(LastNode);
			LastNode->Next = NextNode;
		}

		Size++;
	}

	void Insert(const T& Value, int Index)
	{
		if (Index > Count() || Index < 0)
		{
			return;
		}

		if (Index == Count())
		{
			Add(Value);
			return;
		}

		switch (Index)
		{
		case 0:
			if (!Start)
			{
				Start = new Node();
				Start->Data = Value;
			}
			else
			{
				Node* InsertedNode = new Node();
				InsertedNode->Next = Start;
				InsertedNode->Data = Value;
				Start = InsertedNode;
			}

			break;
		default:
			Node* IndexNode = GetIndex(Index - 1);
			assert(IndexNode);

			Node* InsertedNode = new Node();
			InsertedNode->Data = Value;

			InsertedNode->Next = IndexNode->Next;
			IndexNode->Next = InsertedNode;

			break;
		}

		Size++;
	}

	void Remove(int Index)
	{
		if (Index >= Count() || Index < 0)
		{
			return;
		}

		if (Index == Count() - 1)
		{
			Node* SecondLastNode = GetIndex(Index - 1);
			assert(SecondLastNode);

			SecondLastNode->Next->Next = nullptr;
			delete SecondLastNode->Next;
			SecondLastNode->Next = nullptr;
			return;
		}

		Node* NewStart = Start->Next;
		assert(NewStart);
		switch (Index)
		{
		case 0:
			delete Start;
			Start = nullptr;

			Start = NewStart;
			break;
		default:

			Node* OneBeforeIndex = GetIndex(Index - 1);
			assert(OneBeforeIndex);

			Node* RemovedNode = OneBeforeIndex->Next;
			assert(RemovedNode);

			OneBeforeIndex->Next = RemovedNode->Next;
			assert(RemovedNode->Next);

			RemovedNode->Next = nullptr;
			delete RemovedNode;

			break;
		}

		Size--;
	}

	void ReverseIteratively()
	{
		Node* Current = Start;
		Node* Prev = nullptr;
		Node* Next = nullptr;

		while (Current)
		{
			Next = Current->Next;
			Current->Next = Prev;
			Prev = Current;
			Current = Next;
		}

		Start = Prev;
	}

	void ReverseRecursively()
	{
		ReverseRecursively(Start, nullptr);
	}

	int Count() { return Size; }

	void Print()
	{
		Node* CurrentNode = Start;
		while (CurrentNode)
		{
			CurrentNode->Print();
			std::cout << " -> ";
			CurrentNode = CurrentNode->Next;
		}
	}

private:
	int Size = 0;

	class Node
	{
	public:
		Node* Next = nullptr;
		T Data;

		void Print()
		{
			std::cout << "[" << Data << "]";
		}
	};

	Node* GetIndex(const int Index)
	{
		if (!IsValidIndex(Index))
		{
			return nullptr;
		}

		Node* IndexNode = Start;
		for (int i = 0; i < Index; i++)
		{
			IndexNode = IndexNode->Next;
		}

		return IndexNode;
	}

	void ReverseRecursively(Node* Current, Node* Previous)
	{
		if (!Current)
		{
			Start = Previous;
			return;
		}

		ReverseRecursively(Current->Next, Current);
		Current->Next = Previous;
	}

	Node* Start = nullptr;

	bool IsValidIndex(const int Index) { return Index < Count()  && Index >= 0; }
};
