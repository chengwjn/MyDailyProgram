class Test:
    def __init__(self, foo):
        self.__foo = foo

    def __bar(self):
        print(self.__foo)
        print('__bar')


def main():
    test = Test('hello')
    '''test.__bar()  # 会报错
    print(test.__foo)  # 会报错'''
    test._Test__bar()


if __name__ == "__main__":
    main()
