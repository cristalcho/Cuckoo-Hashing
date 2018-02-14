#ifndef HASH_H
#define HASH_H
#include <iostream>

class Hash{
protected:
	bool table_; //false = table1, true=table2
	int hashTableSize;
	int** hashTable;
public:
	Hash(){	
		table_ = false;
	}
	~Hash(){ };
	void setHashTableSize(int size);
	int getHash(int x);
	void print();
};
#endif



