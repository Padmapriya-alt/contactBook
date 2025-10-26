#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

struct Contact {
    std::string name, phone, email;
};

void load_contacts(std::vector<Contact>& contacts) {
    std::ifstream infile("contacts.txt");
    Contact c;
    while (infile >> c.name >> c.phone >> c.email) {
        contacts.push_back(c);
    }
    infile.close();
}

void save_contacts(const std::vector<Contact>& contacts) {
    std::ofstream outfile("contacts.txt");
    for (const auto& c : contacts) {
        outfile << c.name << " " << c.phone << " " << c.email << std::endl;
    }
    outfile.close();
}

void add_contact(std::vector<Contact>& contacts) {
    Contact c;
    std::cin.ignore();
    std::cout << "Enter name: "; getline(std::cin, c.name);
    std::cout << "Enter phone: "; getline(std::cin, c.phone);
    std::cout << "Enter email: "; getline(std::cin, c.email);
    contacts.push_back(c);
}

void search_contact(const std::vector<Contact>& contacts) {
    std::string query;
    std::cin.ignore();
    std::cout << "Enter name to search: "; getline(std::cin, query);
    bool found = false;
    for (const auto& c : contacts) {
        if (c.name == query) {
            std::cout << "Found: " << c.name << ", " << c.phone << ", " << c.email << std::endl;
            found = true;
        }
    }
    if (!found) std::cout << "Contact not found!\n";
}

void delete_contact(std::vector<Contact>& contacts) {
    std::string query;
    std::cin.ignore();
    std::cout << "Enter name to delete: "; getline(std::cin, query);
    auto it = std::remove_if(contacts.begin(), contacts.end(),
        [&](const Contact& c) { return c.name == query; });
    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        std::cout << "Contact deleted.\n";
    } else {
        std::cout << "Contact not found.\n";
    }
}

void view_contacts(const std::vector<Contact>& contacts) {
    for (const auto& c : contacts) {
        std::cout << c.name << " " << c.phone << " " << c.email << std::endl;
    }
}

int main() {
    std::vector<Contact> contacts;
    load_contacts(contacts);

    int choice;
    do {
        std::cout << "\n1. Add\n2. View\n3. Search\n4. Delete\n5. Exit\nChoice: ";
        std::cin >> choice;
        switch (choice) {
            case 1: add_contact(contacts); break;
            case 2: view_contacts(contacts); break;
            case 3: search_contact(contacts); break;
            case 4: delete_contact(contacts); break;
            case 5: save_contacts(contacts); std::cout << "Data saved!\n"; break;
            default: std::cout << "Invalid option\n";
        }
    } while (choice != 5);
    return 0;
}
