"""用python设计第一个游戏"""
import random
"""temp=input("输入我正在猜想的数字")
guess=int(temp)"""

"""if guess==8:
    print("yes")
    print("666")
else:
    print("no")  
print("game over")"""

counts = 3
answer = random.randint(1, 10)
while counts > 0:
    temp = input("guess the number:")
    guess = int(temp)
    if guess == answer:
        print("yes")
        print("it's true")
        break
    else:
        if guess < answer:
            print("小了")
        else:
            print("大了")
        counts -= 1
print("game over")
