#pragma once

#include <vector>

template<typename KeyType, typename DataType>
class HashMap
{
public:
	HashMap(const int NumBuckets)
	{
		HashTable.reserve(NumBuckets);
	}

	void Put(const KeyType& Key, const DataType& Value)
	{
		int HashKey = HashFunction(Key);

		if (HashKey >= 0 && HashTable.size() > HashKey)
		{
			HashTable[HashKey] = new DataType(Value);
		}
	}

	bool Get(const KeyType& Key, DataType& Value)
	{
		int HashKey = HashFunction(Key);

		if (HashKey >= 0 && HashTable.size() > HashKey)
		{
			if (HashTable[HashKey])
			{
				Value = *HashTable[HashKey];
				return true;
			}
		}
		return false;
	}

	void Remove(const KeyType& Key)
	{
		int HashKey = HashFunction(Key);

		if(HashKey >= 0 && HashTable.size() > HashKey)
		{
			HashTable[HashKey] = nullptr;
		}
	}

protected:
	int HashFunction(const KeyType& Key) = 0;

private:
	std::vector<DataType*> HashTable;
};
