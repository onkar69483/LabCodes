def fibonacci(n):
    if n <= 0:
        print("Invalid input, Enter positive number")
        return
    
    if n == 1:
        print("0")
        return

    a = 0
    b= 1
    print("Fibonacci Series:")
    print(a)
    print(b)
    
    for i in range(2, n):
        a, b = b, a + b
        print(b)

# Test the function with a user-defined value for n
num = int(input("Enter the number of terms: "))
fibonacci(num)
