#include <iostream>
using namespace std;

// Define a structure to store product information
struct Product {
    int productNumber;
    string productName;
    double productPrice;
};

// Function to calculate the total amount required to order a number of products
double calculateTotalAmount(const Product& product, int quantity) {
    return product.productPrice * quantity;
}

int main() {
    // Create a Product object
    Product product1;
    product1.productNumber = 1;
    product1.productName = "Product A";
    product1.productPrice = 10.99;

    // Get the quantity of products to order from the user
    int quantity;
    cout << "Enter the quantity of " << product1.productName << " to order: ";
    cin >> quantity;

    // Calculate the total amount
    double totalAmount = calculateTotalAmount(product1, quantity);

    // Display the total amount
    cout << "Total amount for ordering " << quantity << " " << product1.productName << " is: $" << totalAmount << endl;

    return 0;
}
