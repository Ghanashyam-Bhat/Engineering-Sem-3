#Language - Python 3.8
def qo(string):
    if len(string)==0:
        return 0
    elif(string[0]=='a'):
        return q1(string[1:])
    else:
        return D(string[1:])
def q1(string):
    if len(string)==0:
        return 0
    elif(string[0]=='a'):
        return q2(string[1:])
    else:
        return D(string[1:])
def q2(string):
    if len(string)==0:
        return 0
    elif(string[0]=='a'):
        return q2(string[1:])
    elif (string[0]=='b'):
        return q3(string[1:])
    else:
        return D(string[1:])
def q3(string):
    if len(string)==0:
        return 0
    elif(string[0]=='a'):
        return q2(string[1:])
    elif (string[0]=='b'):
        return q4(string[1:])
    else:
        return D(string[1:])
def q4(string):
    if len(string)==0:
        return 1
    elif(string[0]=='a'):
        return q2(string[1:])
    elif (string[0]=='b'):
        return q4(string[1:])
    else:
        return D(string[1:])
def D(string):
    return 0
 
print("The Regular Expression of the DFA is aa(a+b)*bb")
print("Enter the string: ") 
string = input()
if(qo(string)==1):
    print("String Accepted")
else:
    print("String Rejected")