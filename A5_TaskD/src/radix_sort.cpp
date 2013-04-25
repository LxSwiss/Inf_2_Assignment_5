//
//  radix_sort.cpp
//  radixsort
//
//  Created by Loc Nguyen on 19.04.12.
//  Copyright (c) 2012 Universität Zürich. All rights reserved.
//
#include <algorithm>
#include "radix_sort.h"

void radix_sort (std::vector < int >&input_list)
{
    std::vector <int>digitBucket[10];
    int m = 10;
    int n= 1;
    int iterator = 3; //because max element is 999
    int key;

    while(iterator >0){
    	while(!input_list.empty()){
    		key= (input_list.back()%m)/n;
    		digitBucket[key].push_back(input_list.back());
    		input_list.pop_back();
    	}
    	for(int i=0; i<10;i++){
    		while(!digitBucket[i].empty()){
    			input_list.push_back(digitBucket[i].back());
    			digitBucket[i].pop_back();
    		}
    	}
    	m = m*10;
    	n = n*10;
    	iterator --;
    }
}
