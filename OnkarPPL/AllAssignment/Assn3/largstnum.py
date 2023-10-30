list=[]
size=int(input("Enter the size of list: "))
print("Enter Numbers: ")
for i in range(size):
    list.append(int(input("")))
max=list[0]
for i in range(size):
    if(list[i]>max):
        max=list[i]
print(f'Largest element: {max}')