def create_phonebook(n):
    phonebook={}
    for i in range(n):
        name=input(f'Enter name {i+1}: ')
        number=input(f'Enter number {name}: ')
        phonebook[number]=name
    return phonebook

def search_name(phonebook,number):
    if number in phonebook:
        return phonebook[number]
    else:
        return "Name not Found"
    
n=int(input("Enter number of entries in phonebook: "))
phonebook=create_phonebook(n)

while True:
    search_number = input("Enter number to search name: ")
    if search_number == 'quit':
        break
    result=search_name(phonebook,search_number)
    print(f'name: {result}')