class Queue:
    def __init__(self):
        self.curr_size = 0
        self.queue = []

    def add(self, element):
        self.curr_size += 1
        self.queue += [element]
        return self.curr_size

    def delete(self):
        if self.curr_size == 0:
            return 'Queue is empty'
        self.curr_size -= 1
        element = self.queue[0]
        del self.queue[0]
        return element

    def front(self):
        if self.curr_size == 0:
            return 'Queue is empty'
        return self.queue[0]

    def isEmpty(self):
        return self.curr_size == 0

if __name__ == "__main__":
    q = Queue()
    print(q.add(1))
    print(q.add(2))
    print(q.add(3))
    print(q.add(4))
    print(q.delete())
    print(q.delete())
    print(q.front())
    print(q.front())
    