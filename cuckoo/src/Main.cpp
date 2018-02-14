#include <iostream>
#include <cstdlib>
#include "CuckooHash.h"

using namespace std;

int main(){
	int size, n;
	int x; 	// want to use hash?
 	CuckooHash ch;

	//ready to use cuckoo hash
	cout << "Start Cuckoo Hashing Test." << endl;
	cout << "Set HashTable size: ";
	cin >> size;
	ch.setHashTableSize(size);
	ch.print();
	
	//Choose Menu
	while(true){
		cout << endl <<endl;
		ch.printMenu();
		cout << " Choose menu: ";
		cin >> n;
		cin.ignore();
		switch(n)
		{
			case 0: 
				cout << "THE END"<<endl;
				return 0;
			case 1: 
				cout << "Insert : ";
				cin >> x;
				ch.insert(x);
				if(ch.rehash){
					cout << "need to restart." <<endl;
					return 0;
				}	
				break;
			case 2:
				cout << "Delete : ";
				cin >> x;
				ch.delCuckoo(x);
				break;
			case 3: 
				cout << "Search : ";
				cin >> x;
				cin.ignore();
				(ch.lookup(x))? cout<<"FIND "<<x<<endl : cout<<"NOT IN TABLE "<<x<< endl; 
				break;
			case 4:
				ch.print();
				break;
		}
	}
}
