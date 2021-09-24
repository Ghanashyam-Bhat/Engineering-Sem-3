//Queue Data Structure : First in FIrst out
//Stack : Last in first out

/*
		Q U E U E 
		
		Applications
		~ Sheduling Event 
		~ BFS
*/

/*
	~ Queue has : front, rear

	Operations to be supported by queue
	~Enqueue : TO add elements to queue
	~Dequeue : To remove elements from Queue
	
	If front = -1 and rear = -1 , then Queue is Empty in array reprasentation (Here we have to check if Queue is full in this reprasentation)
	If front = NULL and rear = NULL , then Queue is Empty in Linked List reprasentation
	
*/

/*

Types of Queue : 
~ Linear Queue
~ Circular Queue
~ DOuble ended Queue
~ Priority Queue

*/


/*
LINEAR QUEUE

						--------------------------------------
					Rear										Front 
					end		--->						--->	end
					
						--------------------------------------




Say we have a empty queue of size 5*sizeof(int)
front = -1
rear = -1
						 4	 3	 2	 1	 0
						---------------------
						|	|	|	|	|	|
						---------------------
						
Now in performing enqueue operation

-> Enqueue(Q,10)
	front++
	rear ++
	
						4	 3	 2	 1	 0
						---------------------
						|	|	|	|	|10 |
						---------------------
						
						both front and reae points to location 0
						
						
-> Enqueue(Q,20)

	rear ++
	
	(When there is already an element in Queue, we just need to increment rear , and keep front as it is)
	
	
						4	 3	 2	 1	 0
						---------------------
						|	|	|	|20	|10 |
						---------------------
						
						front  = 0
						rear = 1
						
-> Enqueue(Q,30)

	rear ++	
	
						4	 3	 2	 1	 0
						---------------------
						|	|	|30	|20	|10 |
						---------------------
						
						front  = 0
						rear = 2
						
Now Dequeuing the Queue

Possibility 1:
	remove front element, and shift everything left by 1
	This is bad because shifting evrything is time and memory consuming

						4	 3	 2	 1	 0
						---------------------
						|	|	|	|30	|20 |
						---------------------
						
						front  = 0
						rear = 1
						
Possibility 2:
	Just make front point to next element, thus it is similar to deleting first element from left
	But, here the size of the Queue is decreased !!!
	
	But Still we use this
	This is the primary disadvantage of Linear Queue (Array reprasentation)
	
						4	 3	 2	 1	 0
						---------------------
						|	|	|30	|20	|	|
						---------------------
						
						front  = 1
						rear = 2
						
~ Enqueue(Q,40)
	
						4	 3	 2	 1	 0
						---------------------
						|   |40 |30	|20	|	|
						---------------------
						
						front  = 1
						rear = 3
						
~ Enqueue(Q,50)
	
						4	 3	 2	 1	 0
						---------------------
						|50 |40 |30	|20	|	|
						---------------------
						
						front  = 1
						rear = 4

~ Enqueue(Q,60)
	
	HERE IT SHOWS STACK IS FULL !!! Even though we have a space free in front end
	
	Here because we are moving "front" , we are not able to utilize complete memory allocated 
	
	To solve this we prfere Circular QUEUE
	
	
*/