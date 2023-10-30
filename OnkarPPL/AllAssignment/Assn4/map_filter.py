# Sample list of numbers
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

doubled_numbers = list(map(lambda x:x*2,numbers))
even_numbers = list(filter(lambda x:x%2==0,numbers))

# Displaying the original list
print("Original numbers:", numbers)

# Displaying the doubled numbers using map()
print("Doubled numbers:", doubled_numbers)

# Displaying the even numbers using filter()
print("Even numbers:", even_numbers)
