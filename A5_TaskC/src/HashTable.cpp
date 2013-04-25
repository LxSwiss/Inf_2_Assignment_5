/*
 *  University of Zurich
 *  Department of Informatics
 *  Visualization and Multimedia Laboratory
 *
 *  Algorithms and Data structures
 *  Author: Genc Mazlami
 */

#include <iostream>
#include <cmath>
#include "math.h"
#include "HashTable.h"



HashTable::HashTable(){
    table = new Item*[TABLE_SIZE];
    

    //by Alex
    for(int i=0; i<TABLE_SIZE; i++){
    	table[i]=NULL;
    }


    //Using MAD compression map, therefore we need factors a and b
    factor_a = 7;
    factor_b = 13;
}

int HashTable::hashfunction(int key_){
    int index = (factor_a * key_  + factor_b) % TABLE_SIZE;  //compute the hash of the key using MAD compression (see slides)
    return index;
}

void HashTable::put(Item* item){
	int counter=0;
		int key = item->getKey();
		int cell = hashfunction(key+counter);

		while(table[cell] != NULL){
			counter++;
			cell = hashfunction(key+counter);
		}

		table[cell] = item;
}

Item* HashTable::get(int key_){
		int cell = hashfunction(key_);

		if(table[cell]->getKey()== key_){
			return table[cell];
		}else{
			int counter=1;
			while(table[cell]->getKey()!= key_){
				counter++;
			}
			return table[cell+counter];
		}
}

void HashTable::putQuadratic(Item* item){
	int counter=0;
	int key = item->getKey();
	int cell = hashfunction(key+counter*counter);

	while(table[cell] != NULL){
		counter++;
		cell = hashfunction(key+counter*counter);
	}

	table[cell] = item;
}

Item* HashTable::getQuadratic(int key_){
	int cell = hashfunction(key_);

			if(table[cell]->getKey()== key_){
				return table[cell];
			}else{
				int counter=1;
				while(table[cell]->getKey()!= key_){
					cell = hashfunction(key_+counter*counter);
					counter++;
				}
				return table[cell];
			}
}

void HashTable::printContent(){
    std::cout << "-----------------------------" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == NULL) {
            std::cout << i << "\t | \t" << "NULL" << std::endl;
            std::cout << "-----------------------------" << std::endl;
        }else{
            std::cout << i << "\t | \t" <<  table[i]->getName() << std::endl;
            std::cout << "-----------------------------" << std::endl;
        }
    }
    std::cout << "-----------------------------" << std::endl;
}

