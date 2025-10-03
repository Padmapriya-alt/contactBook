#include <iostream>
#include <string>


int main() {
    std :: string name, phone, email;

    std :: cout << "Enter Name: ";
    getline(std :: cin, name);

    std :: cout << "Enter Phone Number: ";
    getline(std :: cin, phone);

    std :: cout << "Enter Email: ";
    getline(std :: cin, email);

    std :: cout << "\n--- Contact Details ---\n";
    std :: cout << "Name  : " << name << std :: endl;
    std :: cout << "Phone : " << phone << std :: endl;
    std :: cout << "Email : " << email << std :: endl;

    return 0;
}
