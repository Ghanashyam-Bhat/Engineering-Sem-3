/*
Heap conditions:
1. Complete Binary tree
2. Parental Dominance

Types of Heap Parental Dominance
->Min Heap  : Parent value is lower than whatever there in the children
->Max Heap : Parent value is greater than whatever there in the children

Complete Binary Tree:
All nodes must be present till n-1 level and then, in nth level no right node should be there without left node

//Heap is used to get repeatedly Max value or Min value 

We can delete element only from root
and insert only in next possible location to satisfy the conditions of Heap
*/

/*To construct there are 2 approaches
1.Top down approach
2.Bottom up approach:
	It is just like creating Binary search tree using array reprasentaion
	then we can comapre the parent and children (lchild first, then rchild), then swap them accordingly to get required max heap or min heap
	
	*/