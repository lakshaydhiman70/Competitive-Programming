# Importing a module
import math

# Using functions from a module
result = math.sqrt(16)
print (result);
print('Hello World');

# Variables
x = 5
name = "John"

# Data Types
integer_num = 10
float_num = 3.14
string = "Hello, World!"
boolean = True
print (string);

for i in range (5):
    print ("Looping here");

# user_input = input("Please enter something: ")
# print("You entered:", user_input)

# if condition:
#     # Code block if condition is true
# elif another_condition:
#     # Code block if another condition is true
# else
#     # Code block if none of the conditions are true

# for i in range(5):  # Iterates from 0 to 4
#     # Code block to repeat


# for i in range(5):  # Iterates from 0 to 4
#     # Code block to repeat


# while condition:
#     # Code block to repeat while the condition is true


# my_list = [1, 2, 3, 4, 5]
# my_list.append(6)
# element = my_list[2]


# my_tuple = (1, 2, 3)
# element = my_tuple[1]


# my_dict = {"name": "John", "age": 30}
# value = my_dict["name"]
# my_dict["city"] = "New York"


# my_set = {1, 2, 3, 3, 4}
# my_set.add(5)


# def greet(name):
#     return "Hello, " + name

# result = greet("Alice")


# class Person:
#     def __init__(self, name, age):
#         self.name = name
#         self.age = age

#     def greet(self):
#         return "Hello, my name is " + self.name

# person1 = Person("John", 30)
# message = person1.greet()


# try:
#     # Code that may raise an exception
# except ExceptionType as e:
#     # Code to handle the exception
# else:
#     # Code to execute if no exception occurred
# finally:
#     # Code that always runs (optional)


orda = ord('a')

def solve():
    n = int(input())
    cnt = [0] * 26
    for c in input():
        cnt[ord(c) - orda] += 1
    mx = max(cnt)
    print(max(n % 2, 2 * mx - n))


for _ in range(int(input())):
    solve()