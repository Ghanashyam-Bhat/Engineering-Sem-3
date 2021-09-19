l = ["m" , "i" , "s" , (2,1) , (1,1) , (2,3) , "p" , (8,1) , (1,1)]
n = 0
#Finding total number of tuples in the given list
for i in l:
	if type(i) != type("c"):
		n+=1
#Here, if we directly use for loop, we cannot cahnge the list we are iterarating through
#The updated list must be iterated each time, so using only for loop is not possible
while True:	
	#for loop is used here to find the tuple element in the given list
	for i in l:
		#This if statement is to select only tuple element
		if type(i) != type("c"):
			x = l.index(i)
			#Here we remove the tuple element and insert the respective string as directed by the tuple
			l.pop(x)
			y = i[0]
			#if length is indicated more than 1, then this inside for loop will gets executed
			for i in range(i[1]):
				l.insert(x,l[y])
				x+=1
				y+=1
			n = n- 1
			break
			#Here for loop breaks each time it encounters a tuple and modifies it
			#This is because, when the iterating list under for loop is modified, further iteration leads to RuntimeError	
	if n == 0:
	#When all the tuples gets replaced, i.e when n=0 , the while loop breaks
		print(l)
		break