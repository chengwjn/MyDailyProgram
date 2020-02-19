"""import sys


def main():
    f = [x for x in range(1, 10)]
    print(f)
    f = [x+y for x in 'ABCDE' for y in '1234567']
    print(f)
    f = [x ** 2 for x in range(1, 1000)]
    print(sys.getsizeof(f))
    print(f)
    f = (x ** 2 for x in range(1, 1000))
    print(sys.getsizeof(f))
    print(f)
    for val in f:
        print(val)


if __name__ == '__main__':
    main()"""


def main():
    # 定义元组
    t = ('chengwj', 78, True, '安徽芜湖')
    print(t)
    # 获得元组中的元素
    print(t[0])
    print(t[3])
    # 遍历元组中的值
    for member in t:
        print(member)
    # 重新给元组赋值
    # t[0] = 'C# is the best' ==> TypeError
    # 变量t重新引用了新的元组原来的元组将被垃圾回收
    t = ('Xbox is the best', 66, False, '江苏苏州')
    print(t)
    # 将元组转换成列表
    person = list(t)
    print(person)
    # 列表是可以修改它的元素的
    person[0] = 'I don\'t like Ps4'
    person[1] = 89
    print(person)
    # 将列表转换成元组
    fruits_list = ['apple', 'banana', 'orange']
    fruits_turple = tuple(fruits_list)
    print(fruits_turple)


if __name__ == '__main__':
    main()
