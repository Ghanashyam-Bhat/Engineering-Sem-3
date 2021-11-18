/*
Self Balancing Binary search trees(Search complexity is in the order of log n)
->Types of self balalncing tree :
		1. Red black tree 
		2. AVL tree
		
		
AVL tree :
	It is balanced by the process of rotation (Left rotation / Right rotation / Combination of both)
	For every node we compute something called Balance factor. which is Height of left subtree and  height of right subtree
	AVL tree is said to balanced is the Balance factor is 0,1 or -1
	
	
Types of Imbalances: 
	while inserting , 10 20 30, the tree is right tilted. So we rotate it to balance it (Here it is left rotation
	So, now 20 becomes root, 10 becomes lchild and 30 becomes rchild
*/

/*

Example
10 30 20 


	10				right rotation		10						Left Rotation 				20
			30     ---> 						20             --->					10				30
		20																					20



We have to rotate inorder to balance it when we add/delete node