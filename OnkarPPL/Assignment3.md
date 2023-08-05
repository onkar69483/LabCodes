# Assignment 3

## a) Largest Number
```python
list = []
size = int(input("Enter the size of list: "))
print("Enter numbers: ")
for i in range(size):
    list.append(int(input("")))
max=list[0]
for i in range(size):
    if(list[i]>max):
        max=list[i]
print(f'Largest Element: {max}')
```
## b) Factorial
```python
def factorial(num):
    if(num<=1):
        return 1
    else:
        return num*factorial(num-1)

num = int(input("Enter number to find factorial: "))
fact = factorial(num)
print(f'Factorial of {num}: {fact}')
```
