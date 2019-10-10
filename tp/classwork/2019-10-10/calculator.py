from functools import reduce
class Calculator:
    def add(self, *a):
        return reduce(lambda x, y: x + y, *a);

    def subtract(self, *a):
        return reduce(lambda x, y: x - y, *a);

    def multiply(self, *a):
        return reduce(lambda x, y: x * y, *a);
    
    def devide(self, *a):
        return reduce(lambda x, y: x / y, *a);
    
    def pow(self, *a):
        return reduce(lambda x, y: x ** y, *a);
    
    def root(self, *a):
        return reduce(lambda x, y: x ** (1 - y), *a);

c = Calculator()
c = c.pow([2, 2, 8])
print(c)