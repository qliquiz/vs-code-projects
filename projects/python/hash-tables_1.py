class HashTable:
    def __init__(self, cellcount):
        self.m = cellcount
        self.x = 263
        self.p = 1000000007
        self.items = dict()

    def getHash(self, string):
        s = 0
        for i in range(len(string)):
            s += ord(string[i])*self.x**i
        return (s % self.p + self.p) % self.p % self.m
    
    def add(self, item):
        hash = self.getHash(item)
        get = self.items.get(hash)
        if get and item in get:
            return
        if not get:
            self.items[hash] = list()
        self.items[hash].insert(0, item)

    def delete(self, item):
        hash = self.getHash(item)
        get = self.items.get(hash)
        if get and item in get:
            self.items[hash].remove(item)

    def find(self, item):
        hash = self.getHash(item)
        get = self.items.get(hash)
        return get and item in get
    
    def check(self, hash):
        get = self.items.get(hash)
        return get if get else []


m = int(input())
n = int(input())
table = HashTable(m)
for _ in range(n):
    cmd, val = input().split()
    cmd = cmd.lower()
    if cmd == "add":
        table.add(val)
    elif cmd == "del":
        table.delete(val)
    elif cmd == "find":
        print("yes" if table.find(val) else "no")
    elif cmd == "check":
        print(*table.check(int(val)), sep=" ")