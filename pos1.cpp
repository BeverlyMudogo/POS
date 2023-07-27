#include <iostream>
#include <vector>
#include <cstdlib> // for std::rand
#include <ctime>   // for std::time

// Class to represent a customer
class Customer {
public:
    std::string product;
    int appointmentCode;
    // Additional customer data can be added here
};

// Function to generate a random appointment code
int generateAppointmentCode() {
    // Generate a random number (in this example, between 1000 and 9999)
    return 1000 + (std::rand() % (9999 - 1000 + 1));
}

int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned>(time(0)));

    std::vector<Customer> customers;
    char choice;

    do {
        Customer customer;
        std::cout << "Enter the medicine you would like to buy: ";
        std::getline(std::cin, customer.product);

        customer.appointmentCode = generateAppointmentCode();
        customers.push_back(customer);

        std::cout << "Your appointment code is: " << customer.appointmentCode << std::endl;

        std::cout << "Do you want to get another servive from us? (y/n): ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore the remaining newline character from the previous input
    } while (choice == 'y' || choice == 'Y');

    // Display all the customer information
    std::cout << "\nCustomer Information:\n";
    for (size_t i = 0; i < customers.size(); ++i) {
        const Customer& customer = customers[i];
        std::cout << "Product: " << customer.product << ", Appointment Code: " << customer.appointmentCode << std::endl;
    }

    return 0;
}
