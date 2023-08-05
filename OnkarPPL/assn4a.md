# Experiment 4

## Code Snippet A

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
