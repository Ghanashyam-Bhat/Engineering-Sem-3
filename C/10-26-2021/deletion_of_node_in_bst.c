/*

1.Leaf Node  : We will take a "cur" pointer and make it point to the required node, then delete it 
--------------------------------------------------------------------------------------------------------

2. One child :  We will take a "cur" pointer and make it point to the required node, then make previous
				node point to one child of cur, then delete cur

--------------------------------------------------------------------------------------------------------
3.Two child : 
Inorder Traversal in BST is Ascending order Traversal

We can use one of the methods
a)Inorder Predecessor : The the node visited before going to required node in Inorder Traversal
b)Inorder Successor : The the node visited after going to required node in Inorder Traversal

We use Inorder Successor here :-
We will replace the node to be deleted with value of inorder successor, the point "cur" to the inorder successor and then delete the inorder successor
--------------------------------------------------------------------------------------------------------
*/