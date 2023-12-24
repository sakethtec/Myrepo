import sys,subprocess
l=[[0,0,0],[0,0,0],[0,0,0]]
k=1
for i in range(1,6):
    for j in range(1,6):
        if i%2==1:
            if j%2==1:
                print(k,end="")
                k+=1
            else:
                 print(end="|")
        else:
             if j%2==1:
                 print(end="- ")
    print()  
input("game starts with player enter index number at evey turn \npress enter to to start")
p1="0"
while p1!="O" and p1!="X":
      subprocess.run("cle.  ar",shell=True)
      p1=input("player-1 enter O or X :").strip().title()
if p1=="O":
    p2="X" 
else :
            p2="O"
print("player-2 choice is ",p2)
i=1
while i<10:
    if i%2==1:
        k=int(input("enter player-1 choice:"))
    else:
        k=int(input("enter player-2 choice:"))
    m=k//3
    if(k%3==0):
        m=m-1
    n=k%3-1
    if(k%3==0):
        n=2
    if i%2==1:
        if l[m][n]==0:
            l[m][n]=p1
        else:
            print("wrong choice")
            continue
    else:
        if l[m][n]==0:
            l[m][n]=p2
        else:
            print("wrong choice")
            continue
    a=0;b=0
    subprocess.run("clear",shell=True)
    for a in range(3):
        for b in range(3):
            if l[a][b]!=0:
                print(l[a][b],end="")
            else:
                print(end=" ")
            if b!=2:
                    print("|",end="")
        print()
        if a<2:
            print("- "*3)
    i+=1
    flag1=flag2=0
    if l[0][0]==l[0][1]==l[0][2]==p1 or l[1][0]==l[1][1]==l[1][2]==p1 or l[2][0]==l[2][1]==l[2][2]==p1 or \
                              l[0][0]==l[1][1]==l[2][2]==p1 or l[2][0]==l[1][1]==l[0][2]==p1 or \
                              l[0][0]==l[1][0]==l[2][0]==p1 or l[0][1]==l[1][1]==l[2][1]==p1 or l[0][2]==l[1][2]==l[2][2]==p1:
        flag1=1
        break;
    if l[0][0]==l[0][1]==l[0][2]==p2 or l[1][0]==l[1][1]==l[1][2]==p2 or l[2][0]==l[2][1]==l[2][2]==p2 or \
                              l[0][0]==l[1][1]==l[2][2]==p2 or l[2][0]==l[1][1]==l[0][2]==p2 or \
                              l[0][0]==l[1][0]==l[2][0]==p2 or l[0][1]==l[1][1]==l[2][1]==p2 or l[0][2]==l[1][2]==l[2][2]==p2:
        flag2=1
        break 
if flag1==1:
    print("\n \n player-1 won")
elif flag2==1:
    print("\n \n player-2 won")
else:
    print("\n \n match is draw")