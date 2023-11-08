#pragma once

#include <cassert>
#include <iostream>

template<typename T>
class LinkedList
{
public:
	void Add(const T& Value)
	{
		LinkedListNode* NextNode = Start;

		NextNode = new LinkedListNode();
		NextNode->Data = Value;

		if (!Size)
		{
			Start = NextNode;
		}
		else
		{
			LinkedListNode* LastNode = GetIndex(Count() - 1);
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
				Start = new LinkedListNode();
				Start->Data = Value;
			}
			else
			{
				LinkedListNode* InsertedNode = new LinkedListNode();
				InsertedNode->Next = Start;
				InsertedNode->Data = Value;
				Start = InsertedNode;
			}

			break;
		default:
			LinkedListNode* IndexNode = GetIndex(Index - 1);
			assert(IndexNode);

			LinkedListNode* InsertedNode = new LinkedListNode();
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
			LinkedListNode* SecondLastNode = GetIndex(Index - 1);
			assert(SecondLastNode);

			SecondLastNode->Next->Next = nullptr;
			delete SecondLastNode->Next;
			SecondLastNode->Next = nullptr;
			return;
		}

		LinkedListNode* NewStart = Start->Next;
		assert(NewStart);
		switch (Index)
		{
		case 0:
			delete Start;
			Start = nullptr;

			Start = NewStart;
			break;
		default:

			LinkedListNode* OneBeforeIndex = GetIndex(Index - 1);
			assert(OneBeforeIndex);

			LinkedListNode* RemovedNode = OneBeforeIndex->Next;
			assert(RemovedNode);

			OneBeforeIndex->Next = RemovedNode->Next;
			assert(RemovedNode->Next);

			RemovedNode->Next = nullptr;
			delete RemovedNode;

			break;
		}

		Size--;
	}

	int Count() { return Size; }

	void Print()
	{
		LinkedListNode* CurrentNode = Start;
		while (CurrentNode)
		{
			CurrentNode->Print();
			std::cout << " -> ";
			CurrentNode = CurrentNode->Next;
		}
	}

private:
	int Size = 0;

	class LinkedListNode
	{
	public:
		LinkedListNode* Next = nullptr;
		T Data;

		void Print()
		{
			std::cout << "[" << Data << "]";
		}
	};

	LinkedListNode* Start = nullptr;

	LinkedListNode* GetIndex(const int Index)
	{
		if (!IsValidIndex(Index))
		{
			return nullptr;
		}

		LinkedListNode* IndexNode = Start;
		for (int i = 0; i < Index; i++)
		{
			IndexNode = IndexNode->Next;
		}

		return IndexNode;
	}

	bool IsValidIndex(const int Index) { return Index < Count()  && Index >= 0; }
};
