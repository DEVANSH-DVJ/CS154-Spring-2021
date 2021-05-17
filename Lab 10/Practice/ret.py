
f = lambda x: x + x  # function abstraction-- creates a function, we are
# assignig that to variable f


print(f(10))


# anonymous function
# takes any no of arguments, but only one expression


g = lambda x: x * x if (x > 10) else x + x

print(g(20))


# nested if else

h = lambda x: x * x if (x > 10) else (10 if x == 9 else 0)

print(h(9))
