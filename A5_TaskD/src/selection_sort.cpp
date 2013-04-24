//
//  Created by Rafael Ballester on 10.04.13.
//  Copyright (c) 2013 Universität Zürich. All rights reserved.
//

#include <iostream>
#include "selection_sort.h"

void selection_sort (std::vector < int >&numbers)
{
 int minEl;
 int temp;
 for(unsigned int i = 0; i<numbers.size(); i++){
	 minEl = i;
	 for(unsigned int j=i; j<numbers.size(); j++){
		 minEl = std::min(minEl,numbers[j]);
		 if(numbers[j]<numbers[minEl]){
			 minEl= j;
		 }
	 }
	 temp = numbers[i];
	 numbers[i] = numbers[minEl];
	 numbers[minEl]= temp;
 }
}
