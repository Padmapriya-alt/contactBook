#include <iostream>
#include <vector>
#include <string>

struct Contact {
    std::string name;
    std::string phone;
    std::string email;
};

void display_menu() {
    std::cout << "\n=== Contact Book Menu ===\n"
              << "1. Add Contact\n"
              << "2. View All Contacts\n"
              << "3. Exit\n"
              << "Choose an option: ";
}

void add_new_contact(std::vector<Contact>& contacts) {
    Contact c;
    std::cin.ignore();
    std::cout << "Enter name: ";   std::getline(std::cin, c.name);
    std::cout << "Enter phone: ";  std::getline(std::cin, c.phone);
    std::cout << "Enter email: ";  std::getline(std::cin, c.email);
    contacts.push_back(c);
    std::cout << "Contact added!\n";
}

void view_all_contacts(const std::vector<Contact>& contacts) {
    if (contacts.empty()) {
        std::cout << "No contacts to display.\n";
    } else {
        for (size_t i = 0; i < contacts.size(); ++i) {
            std::cout << "\nContact #" << (i + 1) << ":\n";
            std::cout << "Name: "  << contacts[i].name  << "\n";
            std::cout << "Phone: " << contacts[i].phone << "\n";
            std::cout << "Email: " << contacts[i].email << "\n";
        }
    }
}

int main() {
    std::vector<Contact> contacts;
    int choice;
    do {
        display_menu();
        std::cin >> choice;
        switch (choice) {
            case 1: add_new_contact(contacts); break;
            case 2: view_all_contacts(contacts); break;
            case 3: std::cout << "Goodbye!\n"; break;
            default: std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);
    return 0;
}
