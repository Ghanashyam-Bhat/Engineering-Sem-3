//Circular Linked List

/*In singly linked list, the last node will point to h->head. Thus it becomes circular singly linked list

In Doubly linked list, if llink of h->head is pointing to last node, and rrlink of last node will be pointing to h->head */

//In circular linked list, going to last element is easier  [h->head->llink]



/* To go to last element, traverse till  (pres->link != h->head) is True for singly circular linked list

 To go to last element, h->head->llink for doubly circular linked list 
*/

 
 /*
 INSERT REAR FOR CIRCULAR DOUBLY LINKED LIST (if head !=NULL)
 cur = head->llink
 cur->rlink = newnode
 newnode->llink = cur
 newnode->rlink = head 
 head->llink = newnode
 */
 
 