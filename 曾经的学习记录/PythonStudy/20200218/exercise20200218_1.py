def main():
    str1 = 'hello,world!'
    # 通过len函数计算字符串的长度
    print(len(str1))
    # 获得字符串首字母大写的拷贝
    print(str1.capitalize())
    # 获得字符串变成大写之后的拷贝
    print(str1.upper())
    # 从字符串中查找子串所在的位置
    print(str1.find('or'))
    print(str1.find('shit'))
    # 检查字符串是否以制定的字符串开头
    print(str1.startswith('He'))
    print(str1.startswith('hel'))
    # 检查字符串以指定的字符串结尾
    print(str1.endswith('!'))
    # 将字符串以指定的宽度居中并在两侧填充指定的字符
    print(str1.center(50, '*'))
    # 将字符串以指定的宽度靠右放置并在左侧填充指定的字符
    print(str1.rjust(50, ' '))
    str2 = 'abc123456'
    # 从字符串中取出指定位置的字符(下标运算)
    print(str2[2])
    # 字符串切片（从指定的开始索引到指定的结束索引
    print(str2[2:5])
    print(str2[2:])
    print(str2[2::2])
    print(str2[::2])
    print(str2[::-1])
    print(str2[-3:-1])
    # 检查字符串是否由数字构成
    print(str2.isdigit())
    # 检查字符串是否以字母构成
    print(str2.isalpha())
    # 检查字符串是否以数字和字母构成
    print(str2.isalnum())
    str3 = '   chengwjn@126.com   '
    print(str3)
    # 获得字符串修建左右两侧空格的拷贝
    print(str3.strip())


if __name__ == '__main__':
    main()
