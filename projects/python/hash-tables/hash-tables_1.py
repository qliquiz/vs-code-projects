class HashTable:
    def __init__(self, cell_count):
        self.m = cell_count
        self.x = 263
        self.p = 10 ** 9 + 7
        self.items = dict()


    def get_hash(self, string):
        s = 0

        for i in range(len(string)):
            s += ord(string[i]) * self.x ** i

        return (s % self.p + self.p) % self.p % self.m
    

    def add(self, item):
        hash = self.get_hash(item)
        get = self.items.get(hash)

        if get and item in get:
            return
        if not get:
            self.items[hash] = list()

        self.items[hash].insert(0, item)


    def delete(self, item):
        hash = self.get_hash(item)
        get = self.items.get(hash)

        if get and item in get:
            self.items[hash].remove(item)


    def find(self, item):
        hash = self.get_hash(item)
        get = self.items.get(hash)

        return get and item in get
    

    def check(self, hash):
        get = self.items.get(hash)

        return get if get else []


m = int(input("Введите количество ячеек таблицы: "))
n = int(input("Введите количество команд: "))

table = HashTable(m)

for _ in range(n):
    string, value = input().split()
    string = string.lower()

    if string == "add":
        table.add(value)
    elif string == "del":
        table.delete(value)
    elif string == "find":
        print("yes" if table.find(value) else "no")
    elif string == "check":
        print(*table.check(int(value)), sep=" ")