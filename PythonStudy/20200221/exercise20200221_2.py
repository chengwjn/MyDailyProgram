from abc import ABCMeta, abstractmethod


class Pet(object, metaclass=ABCMeta):
    def __init__(self, nickname):
        self._nickname = nickname

    @abstractmethod
    def make_voice(self):
        pass


class Dog(Pet):
    def make_voice(self):
        print('%s: 汪汪汪' % self._nickname)


class Cat(Pet):
    def make_voice(self):
        print('%s: 喵喵喵' % self._nickname)


def main():
    pets = [Dog('旺财'), Cat('大橘'), Dog('二黄')]
    for pet in pets:
        pet.make_voice()


if __name__ == '__main__':
    main()
