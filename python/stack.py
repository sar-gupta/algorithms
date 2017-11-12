class Stack:
    def __init__(self):
        self.curr_size = 0
        self.stack = []

    def push(self, element):
        self.curr_size += 1
        self.stack += [element]
        return self.curr_size

    def pop(self):
        if self.curr_size == 0:
            return 'Stack is empty'
        self.curr_size -= 1
        element = self.stack[self.curr_size]
        del self.stack[-1]
        return element

    def top(self):
        if self.curr_size == 0:
            return 'Stack is empty'
        return self.stack[self.curr_size-1]

    def isEmpty(self):
        return self.curr_size == 0

if __name__ == "__main__":
    s = Stack()
    print(s.push(1))
    print(s.push(2))
    print(s.push(3))
    print(s.push(4))
    print(s.pop())
    print(s.pop())
    print(s.top())