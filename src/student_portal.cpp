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
struct LoginCredentials {
    std::string username;
    std::string password;
};
bool validateLogin(const LoginCredentials& credentials) {
    const std::string validUsername = "student";
    const std::string validPassword = "portal123";

    return credentials.username == validUsername &&
           credentials.password == validPassword;
}
bool loginUser() {
    LoginCredentials credentials;

    std::cout << "\n=== Student Login ===\n";
    std::cout << "Username: ";
    std::cin >> credentials.username;

    std::cout << "Password: ";
    std::cin >> credentials.password;

    if (validateLogin(credentials)) {
        std::cout << "Login successful.\n";
        return true;
    }

    std::cout << "Invalid username or password.\n";
    return false;
}
int main() {
    std::string portalName = "Student Portal";

    std::cout << portalName << std::endl;
    std::cout << "Portal initialized successfully." << std::endl;
    if (!loginUser()) {
    std::cout << "Access denied. Exiting portal." << std::endl;
    return 0;
}
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