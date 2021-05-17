# anonymous function is defined inside f and returned

def f(x):
    return (lambda y: x + 2 * y)


g1 = f(10)
g2 = f(20)
g3 = f(30)

print(g1(100))
print(g1(200))
print(g2(100))
print(g2(200))
print(g3(100))
print(g3(200))
