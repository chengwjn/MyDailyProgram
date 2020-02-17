"""fibonacci"""
a = 0
b = 1
for _ in range(20):
    (a, b) = (b, a+b)
    print(a, end=' ')

"""水仙花数"""
for num in range(100, 1000):
    low = num % 10
    mid = num // 10 % 10
    high = num // 100
    if num == low ** 3 + mid ** 3 + high ** 3:
        print(num)

"""判断回文数"""
num = int(input("请输入一个正整数:"))
temp = num
num2 = 0
while temp > 0:
    num2 *= 10
    num2 += temp % 10
    temp //= 10
if num == num2:
    print('%d是回文数' % num)
else:
    print('%d不是回文数' % num)

"""输出2~99之间的素数"""
import math
for num in range(2, 100):
    is_prime = True
    for factor in range(2, int(math.sqrt(num))+1):
        if num % factor == 0:
            is_prime = False
            break
    if is_prime:
        print(num, end=' ')

"""输出乘法口诀表"""
for i in range(1, 10):
    for j in range(1, i+1):
        print('%d*%d=%d' % (i, j, i*j), end='\t')
    print()
