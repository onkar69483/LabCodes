def is_prime(number):
    if number <= 1:
        return 0  # Numbers less than or equal to 1 are not prime

    for i in range(2, int(number ** 0.5) + 1):
        if number % i == 0:
            return 0  # Number is divisible by a number other than 1 and itself

    return 1  # Number is prime

# Input from the user
num = int(input("Enter an integer to check if it's prime: "))

# Check if the number is prime using the is_prime function
result = is_prime(num)

if result == 1:
    print(num, "is a prime number.")
else:
    print(num, "is not a prime number.")
