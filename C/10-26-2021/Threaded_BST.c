//Threaded Binary Search Tree

//Using system stack for recurrsion of Inorder Traversal, we can define our own stack and push pointer for recurrsion (or) We have to go for iterative approach

//In a BST , leaf nodes points to NULL, so we can make use of those pointers to point to some different places to help in doing iterative inorder Traversal

/*
LeftMost Node(Lowest Number) and Rightmost Node(Highest Number) should be left ponting to NULL

For other NULL pointers, "lchlid" pointer is made to point to its inorder predecessor
and "rchlid" pointer is made to point to its inorder successor

So, Now we should store an additional info in child defining whether the Node is pointing to its actual
child or its Inorder successor/predecessor

thread will tell whether the node is leaf node or not
Node:
	data
	lchild
	rchild
	lthread  --Bool Value(0/1)
	rthread  --Bool Value(0/1)
	
0 -> Actual Child
1-> Inorder Predecessor/Successor
*/

/*
Headed Threaded Binary Tree :
Here the LeftMost Node(Lowest Number) and Rightmost Node(Highest Number) will be made to point to Head/root
*/