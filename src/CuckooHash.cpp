#include <iostream>
#include "CuckooHash.h"
#include "Hash.cpp"
using namespace std;

bool rehash=false;
int count =0;
void CuckooHash::insert(int x){
	if(lookup(x)){
		cout << "Already in table." << endl;
		return;
	}

	if(count > this->hashTableSize*2){
		cout << "need to rehash"<<endl;
		reHash();
		return;
	}
	key = this->getHash(x);
	if(hashTable[table_][key]==INT_MIN){
		hashTable[table_][key] = x;
		table_ = false;
	}else{
		oldValue = hashTable[table_][key];
		hashTable[table_][key]=x;
		table_ = !table_;
		count++;
		insert(oldValue);
	}
}

void CuckooHash::delCuckoo(int x){
	table_ = 0;
	if(lookup(x)){
		if(lookup(x)==table_){
			key = getHash(x);
			hashTable[table_][key]=INT_MIN;
		}
		else{
			table_ =!table_;
			key = getHash(x);
			hashTable[table_][key]=INT_MIN;
			table_ =!table_;
		}
		cout << "DELETE " << x <<endl;
	}else{
		cout << "NOT IN TABLE."<< endl;
	}
}


bool CuckooHash::lookup(int x){
	if(table_){
		return false;
	}

	for(int i=0; i<2; i++){
		key = this->getHash(x);
		if(hashTable[i][key]!=x){
			table_ = !table_;
		}	
		else{ 
			table_ = !table_;
			return true;	
		}	
	}
	cout<<x <<"is not in Table "<< endl;
	return false;	// there is no value.

}

void CuckooHash::reHash(){
	rehash = true;
}

void CuckooHash::printMenu(){
	cout << "-------------------------------"<<endl;
	cout << "	 <Cuckoo Hashing>	"<<endl;
	cout << "  press Number to do method.   "<<endl;
	cout << "     0) exit			"<<endl;
	cout << "     1) Insert   2) Delete	"<<endl;
	cout << "     3) Search   4) Show       "<<endl;
	cout << "-------------------------------"<<endl;
}

