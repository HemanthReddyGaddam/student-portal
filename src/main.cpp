#include <iostream>
#include <string>

struct Student {
    int id;
    std::string name;
    std::string program;
};

int main() {
    std::string portalName = "Student Portal";

    std::cout << portalName << std::endl;
    std::cout << "Portal initialized successfully." << std::endl;

    return 0;
}