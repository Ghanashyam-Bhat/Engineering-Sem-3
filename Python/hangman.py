def hangman(word):
    wrong = 0
    word = word.lower()
    temp = list("-"*len(word))
    to_be = list(word)
    g = ' '
    while g  in to_be:
        i = to_be.index(g)
        temp[i] = g
        to_be[i] = '*'
    while to_be.count('*')!=len(word) and wrong!=12:
        print("".join(temp))
        g = input("Guess a letter: ")
        if g=='quit':
            break
        elif len(g)>1:
            print("You can guess only 1 word at a time")
        elif g in temp:
            print("Word already guessed")
        elif g in to_be:
            print("Right Guess")
            while g  in to_be:
                i = to_be.index(g)
                temp[i] = g
                to_be[i] = '*'
        else:
            print("Wrong Guess")
            wrong+=1
    if to_be.count('*')==len(word):
        print("You won")
        return 1
    elif wrong==12:
        print("You Lost")
        return 0
    if g=='quit':
        print("You have quit the game")
        return 0
        
def fill():


def feed():

