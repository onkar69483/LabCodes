list = []
n = int(input("Enter number of elements of a list: "))
print("Enter numbers: ")
for i in range(n):
    list.append(int(input()))
print(list)
max=list[0]
min=list[0]
for i in range(len(list)):
    if list[i]>max:
        max=list[i]
    elif list[i]<min:
        min=list[i]
print(f"Max: {max}")
print(f"Min: {min}")