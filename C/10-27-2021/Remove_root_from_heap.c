#include <stdio.h>
#include <stdlib.h>

//To remove root element, replace the root with last element(To maintain complete Binary tree property and then heapify the entire tree again

//To insert new element, insert element at end and then Heapify the entire tree

//Top down approach of building a Heap : Adding single element and Heapifying n times
//Time complexity is (nlogn)

//Heap Sort Algorithm:
//Create a min heap and remove root element n times to get Ascending order