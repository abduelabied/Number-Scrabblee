lst=[1,2,3,4,5,6,7,8,9]
sum1=0
sum2=0
turn=1
p1=0
p2=0
c=1
print("WELCOME TO NUMBER SCRABBLE GAME :)")
print("(THE RULES ARE SIMPLE:)")
print("1- CHOOSE NUMBER FROM THE LIST FROM (1-9)")
print("2- THE PLAYER WHOSE SUM = 15 WINS")
char=input("PLEASE PRESS SPACE TO START : ")
while(char !=' '):
    char=input("PLEASE PRESS SPACE TO START : ")
while((sum1 < 15 or sum2 < 15) and (c<=3)):
    if(turn==1):
        print("PLAYER ONE TURN")
        print(lst)
        while(p1 not in lst):
            p1=int(input("PLEASE ENTER YOUR NUMBER FROM LIST"))
        sum1=sum1+p1
        print("SUM PLAYER ONE = ",sum1)
        lst.remove(p1)
        turn=2
        print("________________________")
    else:
         print("PLAYER TWO TURN")
         print(lst)
         while(p2 not in lst):
            p2=int(input("PLEASE ENTER YOUR NUMBER FROM LIST"))
         sum2=sum2+p2
         print("SUM PLAYER TWO = ",sum2)
         lst.remove(p2)
         turn=1
         print("________________________")
         c=c+1
if(sum1==15):
    print("PLAYER ONE WINS")
elif(sum2==15):
    print("PLAYER TWO WINS")
else:
    print("Draw")

         

