#include <iostream>
#include <string>

struct Student {
    int id;
    std::string name;
    std::string program;
};

bool isValidStudent(const Student &student) {
    return student.id > 0 &&
           !student.name.empty() &&
           !student.program.empty();
}

void displayStudentProfile(const Student &student) {
    std::cout << "\n--- Student Profile ---" << std::endl;
    std::cout << "Student ID: " << student.id << std::endl;
    std::cout << "Student Name: " << student.name << std::endl;
    std::cout << "Program: " << student.program << std::endl;
}

void registerStudent(const Student &student) {
    if (!isValidStudent(student)) {
        std::cout << "Invalid student information." << std::endl;
        return;
    }

    std::cout << "Student Registration" << std::endl;
    std::cout << "ID: " << student.id << std::endl;
    std::cout << "Name: " << student.name << std::endl;
    std::cout << "Program: " << student.program << std::endl;
    std::cout << "Registration completed successfully." << std::endl;
}
bool findStudentById(const Student &student, int searchId) {
    return student.id == searchId;
}
void displayPortalMenu() {
    std::cout << "\n--- Student Portal Menu ---" << std::endl;
    std::cout << "1. Register Student" << std::endl;
    std::cout << "2. View Student Profile" << std::endl;
    std::cout << "3. Search Student" << std::endl;
}
int main() {
    std::string portalName = "Student Portal";

    std::cout << portalName << std::endl;
    std::cout << "Portal initialized successfully." << std::endl;
    displayPortalMenu();

    Student student{2026201018, "Hemanth", "MTech"};

    registerStudent(student);
    displayStudentProfile(student);
    int searchId = 2026201018;

    if (findStudentById(student, searchId)) {
        std::cout << "\nStudent with ID " << searchId
                << " was found." << std::endl;
    } else {
        std::cout << "\nStudent with ID " << searchId
                << " was not found." << std::endl;
    }

    return 0;
}