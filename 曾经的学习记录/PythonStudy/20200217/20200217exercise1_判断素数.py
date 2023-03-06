"""输入一个数判断是不是素数"""
'''from math import sqrt'''
num = int(input("insert a number:"))
'''end = int(sqrt(num))'''
is_prime = True
for x in range(2, num-1):
    if num % x == 0:
        is_prime = False
        break
if is_prime and num != 0:
    print('%d 是素数' % num)
else:
    print('%d 不是素数' % num)
