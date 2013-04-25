//
//  Created by Rafael Ballester on 10.04.13.
//  Copyright (c) 2013 Universität Zürich. All rights reserved.
//

#include <iostream>
#include "bucket_sort.h"

void
bucket_sort (std::vector < int >&numbers)
{
	int bucket[1000];
	for(unsigned i = 0; i < 1000; i++) {
		bucket[i] = 0;
	}

	for(unsigned i = 0; i<numbers.size(); i++) {  // remos failure   forgot  i<
		bucket[numbers[i]]++;
	}
	numbers.clear();

	/*for(unsigned i = 0; i < 1000; i++) {    // Remos approach
		int cnt = 0;
		while(cnt < bucket[i]) {
			numbers.push_back(i);
			cnt++;
		}
	} */

	for(unsigned i= 0;i<1000;i++){  //Alex's  approach
		int bucketsize = bucket[i];
		while(bucketsize != 0){
			numbers.push_back(i);
			bucketsize--;
		}
	}

}
