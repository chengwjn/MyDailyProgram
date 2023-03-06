import exercise20200217_2 as m1
from exercise20200217_2 import foo
from random import randint


def roll_dice(n=2):
    """摇色子
    :paramn:色子的个数
    :return:n颗色子点数之和5
    """
    total = 0
    for _ in range(n):
        total += randint(1, 6)
    return total


def add(a=0, b=0, c=0):
    return a+b+c


# 如果没有指定参数那么使用默认值摇两颗色子
print(roll_dice())
# 摇三颗色子
print(roll_dice(3))
print(add())
print(add(1))
print(add(1, 2))
print(add(1, 2, 3))
# 传递参数时可以不按照设定的顺序进行传递
print(add(c=50, a=100, b=200))


"""def foo():
    print('hello,world!')


def foo():
    print('goodbye,world!')


foo()"""

foo()
m1.foo()


def is_prime(num):
    for factor in range(2, num):
        if num % factor == 0:
            return False
    return True if num != 1 else False
