def main():
    set1 = {1, 2, 3, 3, 3, 2}
    print(set1)
    print("length = %d" % len(set1))
    set2 = set(range(1, 10))
    print(set2)
    set1.add(4)
    set1.add(5)
    set2.update([11, 12])
    print(set1)
    print(set2)
    set2.discard(5)
    # remove的元素如果不存在会引发KeyError
    if 4 in set2:
        set2.remove(4)
    print(set2)
    # 遍历集合容器
    for elem in set2:
        print(elem ** 2, end='')
    print()
    # 将元组转换成集合
    set3 = set((1, 2, 3, 3, 2, 1))
    print(set3.pop())
    print(set3)
    # 集合的交集、并集、差集、对称差运算
    print(set1 & set2)
    print(set1 | set2)
    print(set1 - set2)
    print(set1 ^ set2)
    print(set1 <= set2)
    print(set1 >= set2)
    print(set1 >= set3)


if __name__ == '__main__':
    main()


def main():
    scores = {'chengwj': 3, 'github': 4, 'gxxhub?': 5}
    print(scores['chengwj'])
    print(scores['github'])
    for elem in scores:
        print('%s\t--->\t%d' % (elem, scores[elem]))
    # 更新字典中的元素
    scores['lalala'] = 65
    scores['ioioip'] = 71
