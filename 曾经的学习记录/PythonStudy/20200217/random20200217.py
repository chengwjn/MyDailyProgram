"""猜数字游戏"""
import random

answer = random.randint(1, 100)
counter = 0
while True:
    counter += 1
    number = int(input("input a number:"))
    if number < answer:
        print("more bigger")
    elif number > answer:
        print("more smaller")
    else:
        print("you are right")
        break
print("counter = %d" % counter)
if counter > 7:
    print("you are not smart")
