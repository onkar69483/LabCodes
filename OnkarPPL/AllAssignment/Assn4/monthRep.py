def display_month(month_number):
    months = [
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    ]

    if 1 <= month_number <= 12:
        print("The corresponding month is:", months[month_number - 1])
    else:
        print("Invalid input. Please enter a number between 1 and 12.")

# Input from the user
month_number = int(input("Enter a month number (1-12): "))

# Call the function to display the corresponding month
display_month(month_number)
