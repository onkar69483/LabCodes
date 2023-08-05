# Assignment 4

## Program Code: a) Phone Book

```python
PhoneBook = {}

def add_num(PhoneBook, size):
    for i in range(size):    
        name = input("Enter name of person: ")
        phoneNum = int(input("Enter phone number: "))
        PhoneBook.update({name: phoneNum})
    return "Phone Numbers Saved!"

def Search(PhoneBook, size):
    SearchNum = int(input("Enter number to Search Person: "))
    for key, value in PhoneBook.items():
        if(SearchNum == value):
            return f'Person name: {key}'
    return "Person Not found!"

size = int(input("Enter the number of phone numbers to store: "))
print(add_num(PhoneBook, size))
print(Search(PhoneBook, size))
```
## Program Code: b) Reverse Integer

```python
def reverseInt(num):
    rev = 0
    while num > 0:
        last = num % 10
        rev = rev * 10 + last
        num = num // 10
    return rev

num = int(input("Enter number: "))
rev = reverseInt(num)
print("Reversed:", rev)
```
## Program Code: c) Checking Prime Number

```python
def is_prime(num):
    if num <= 1:
        return 0
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            return 0
    return 1

num = int(input("Enter a number: "))
if is_prime(num):
    print(f"{num} is a prime number.")
else:
    print(f"{num} is not a prime number.")
```
##  Program Code: d) Display Month

```python
def displayMonth(month):
    months = ["January", "February", "March", "April", "May", "June",
              "July", "August", "September", "October", "November", "December"]
    if 1 <= month <= 12:
        print("Month:", months[month - 1])
    else:
        print("Invalid month number!")

month = int(input("Enter a number between 1 and 12: "))
displayMonth(month)
```

## Program Code: e) Read, Sort and Display Data

```python
class Data:
    def __init__(self):
        self.data = []

    def read(self, size):
        for i in range(size):
            num = int(input("Enter number: "))
            self.data.append(num)

    def sort(self):
        size = len(self.data)
        for i in range(size):
            swapped = False
            for j in range(size - i - 1):
                if self.data[j] > self.data[j + 1]:
                    temp = self.data[j]
                    self.data[j] = self.data[j + 1]
                    self.data[j + 1] = temp
                    swapped = True
            if not swapped:
                break
        print("Data Sorted!")

    def display(self):
        print("Data: ", self.data)

newData = Data()
menu = 0
while menu != 4:
    print("\nMenu")
    print("1.Read/Store Data")
    print("2.Sort Data")
    print("3.Display Data")
    print("4.Quit")
    menu = int(input("Enter Choice: "))
    if menu == 1:
        size = int(input("Enter the number of elements: "))
        newData.read(size)
    elif menu == 2:
        newData.sort()
    elif menu == 3:
        newData.display()
    elif menu == 4:
        break
    else:
        print("Invalid Input!")
```

