#ifndef COCKOOHASH_H
#define COCKOOHASH_H
#include "Hash.h"

class CuckooHash : public Hash{
public:
	int key;
	int oldValue;
	int count; 	// need to rehash
	bool rehash;	
	CuckooHash(){	};

	void insert(int x);
	void delCuckoo(int x);
	bool lookup(int x);
	void reHash();
	void printMenu();
};
#endif


