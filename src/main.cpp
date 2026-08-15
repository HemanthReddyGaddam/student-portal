#include <iostream>
#include <string>

struct Student {
    int id;
    std::string name;
    std::string program;
};

void registerStudent(const Student &student) {
    std::cout << "Student Registration" << std::endl;
    std::cout << "ID: " << student.id << std::endl;
    std::cout << "Name: " << student.name << std::endl;
    std::cout << "Program: " << student.program << std::endl;
}

int main() {
    std::string portalName = "Student Portal";

    std::cout << portalName << std::endl;
    std::cout << "Portal initialized successfully." << std::endl;

    Student student{2026201018, "Hemanth", "MTech"};

    registerStudent(student);

    return 0;
}