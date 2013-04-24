#include <iostream>
#include "merge_sort.h"

// Split a vector into two parts and recursively call merge() on each of them
void merge_sort (std::vector < int >&numbers)
{

	if(numbers.size() <= 1){
		return;
	}

	std::vector<int>::iterator middle = numbers.begin() + (numbers.size()/2); //find middle element

	std::vector<int> left(numbers.begin(), middle);
	std::vector<int> right(middle, numbers.end());

	 merge_sort(left);
	 merge_sort(right);

	 merge(left, right, numbers);

}

// Merge two sorted lists (numbers1 and numbers2) into one sorted list (numbers)
void merge (std::vector < int >&numbers1, std::vector < int >&numbers2,
       std::vector < int >&numbers)
{
	    unsigned countLeft = 0, countRight = 0;

	    while(countLeft < numbers1.size() && countRight < numbers2.size())
	    {

	        if(numbers1[countLeft] < numbers2[countRight])
	        {
	            numbers.push_back(numbers2[countLeft]);
	            countLeft++;
	        }
	        else
	        {
	            numbers.push_back(numbers2[countRight]);
	            countRight++;
	        }
	    }

	    while(countLeft < numbers1.size())
	    {
	        numbers.push_back(numbers1[countLeft]);
	        countLeft++;
	    }

	    while(countRight < numbers2.size())
	    {
	        numbers.push_back(numbers2[countRight]);
	        countRight++;
	    }

}
