#include <iostream>
#include <cstdlib>
#include <climits>
#include "Hash.h"
using namespace std;

void Hash::setHashTableSize(int size){
	hashTableSize = size;
 	hashTable = new int*[2];
	for(int i=0; i<2; ++i){
		hashTable[i] = new int[size];
		for(int j=0; j<size; j++){
			hashTable[i][j] = INT_MIN;
		}
	}
	
}

int Hash::getHash(int x){
	if(!table_) return x % hashTableSize;
	return (x/hashTableSize) % hashTableSize;
}

void Hash::print(){
	for(int i=0; i<2; i++){
		for(int j=0; j<hashTableSize; j++){
			if(hashTable[i][j]==INT_MIN){
				cout << "_ ";
			}else{
				cout << hashTable[i][j] << " ";
			}
		}
		cout << endl;
	}
}


