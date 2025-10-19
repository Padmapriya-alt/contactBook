#include <iostream>
#include <vector>
#include <string>
#include <regex>

struct Contact {
    std::string name;
    std::string phone;
    std::string email;
};

bool isValidPhone(const std::string& phone) {
    // Check if phone is 10 digits long and contains only numbers
    std::regex pattern("^[0-9]{10}$");
    return std::regex_match(phone, pattern);
}

void display_menu() {
    std::cout << "\n=== Contact Book Menu ===\n";
    std::cout << "1. Add Contact\n";
    std::cout << "2. View All Contacts\n";
    std::cout << "3. Exit\n";
    std::cout << "Choose an option: ";
}

void add_contact(std::vector<Contact>& contacts) {
    Contact c;
    std::cin.ignore(); // clear previous input

    std::cout << "Enter name: ";
    std::getline(std::cin, c.name);

    // Phone validation loop
    do {
        std::cout << "Enter phone (10 digits): ";
        std::getline(std::cin, c.phone);
        if (!isValidPhone(c.phone)) {
            std::cout << "Invalid phone number! Try again.\n";
        }
    } while (!isValidPhone(c.phone));

    std::cout << "Enter email: ";
    std::getline(std::cin, c.email);

    contacts.push_back(c);
    std::cout << "Contact saved successfully!\n";
}

void view_contacts(const std::vector<Contact>& contacts) {
    if (contacts.empty()) {
        std::cout << "No contacts found.\n";
        return;
    }

    std::cout << "\n--- Contact List ---\n";
    for (size_t i = 0; i < contacts.size(); ++i) {
        std::cout << "Contact #" << (i + 1) << "\n";
        std::cout << "Name  : " << contacts[i].name << "\n";
        std::cout << "Phone : " << contacts[i].phone << "\n";
        std::cout << "Email : " << contacts[i].email << "\n";
        std::cout << "---------------------\n";
    }
}

int main() {
    std::vector<Contact> contacts;
    int choice;

    do {
        display_menu();
        std::cin >> choice;

        switch (choice) {
            case 1: add_contact(contacts); break;
            case 2: view_contacts(contacts); break;
            case 3: std::cout << "Goodbye!\n"; break;
            default: std::cout << "Invalid choice!\n"; break;
        }
    } while (choice != 3);

    return 0;
}

