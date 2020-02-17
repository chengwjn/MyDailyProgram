"""输入两个正整数，计算最大公约数和最小公倍数"""

x = int(input('x= '))
y = int(input('y= '))

if(x > y):
    x, y = y, x
for factor in range(x, 0, -1):
    if x % factor == 0 and y % factor == 0:
        print('%d和%d的最大公约数是%d' % (x, y, factor))
        print('%d和%d的最小公倍数是%d' % (x, y, x*y//factor))
        break
"""打印各种三角形图案"""

row = int(input('请输入行数: '))
for i in range(row):
    for _ in range(i+1):
        print('*', end='')
    print()
for i in range(row):
    for j in range(row):
        if j < row-i-1:
            print(' ', end='')
        else:
            print('*', end='')
    print()
for i in range(row):
    for _ in range(row-i-1):
        print(' ', end='')
    for _ in range(2*i+1):
        print('*', end='')
    print()
