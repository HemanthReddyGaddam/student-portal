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

void registerStudent(const Student &student) {
    if (!isValidStudent(student)) {
        std::cout << "Invalid student information." << std::endl;
        return;
    }

    std::cout << "Student Registration" << std::endl;
    std::cout << "ID: " << student.id << std::endl;
    std::cout << "Name: " << student.name << std::endl;
    std::cout << "Program: " << student.program << std::endl;
}
bool findStudentById(const Student &student, int searchId) {
    return student.id == searchId;
}
int main() {
    std::string portalName = "Student Portal";

    std::cout << portalName << std::endl;
    std::cout << "Portal initialized successfully." << std::endl;

    Student student{2026201018, "Hemanth", "MTech"};

    registerStudent(student);
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