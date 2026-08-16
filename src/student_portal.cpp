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
bool isValidProfileUpdate(const std::string &name,
                          const std::string &program) {
    return name.length() >= 2 &&
           program.length() >= 2;
}
void displayStudentProfile(const Student &student) {
    std::cout << "\n--- Student Profile ---" << std::endl;
    std::cout << "Student ID: " << student.id << std::endl;
    std::cout << "Student Name: " << student.name << std::endl;
    std::cout << "Program: " << student.program << std::endl;
}
void updateStudentProfile(Student &student,
                          const std::string &newName,
                          const std::string &newProgram) {
    if (!isValidProfileUpdate(newName, newProgram)) {
        std::cout << "Profile update failed: invalid information."
                  << std::endl;
        return;
    }

    std::string oldName = student.name;
    std::string oldProgram = student.program;

    student.name = newName;
    student.program = newProgram;

    std::cout << "\nProfile update completed." << std::endl;
    std::cout << "Previous Name: " << oldName << std::endl;
    std::cout << "Updated Name: " << student.name << std::endl;
    std::cout << "Previous Program: " << oldProgram << std::endl;
    std::cout << "Updated Program: " << student.program << std::endl;
}
void editStudentProfile(Student &student) {
    std::string newName;
    std::string newProgram;

    std::cout << "\n=== Edit Student Profile ===" << std::endl;

    std::cout << "Enter new name: ";
    std::cin >> newName;

    std::cout << "Enter new program: ";
    std::cin >> newProgram;

    updateStudentProfile(student, newName, newProgram);
}
void displayDashboard(const Student &student) {
    std::cout << "\n=== Student Dashboard ===" << std::endl;
    std::cout << "Welcome, " << student.name << "!" << std::endl;
    std::cout << "Student ID: " << student.id << std::endl;
    std::cout << "Program: " << student.program << std::endl;
    std::cout << "Registration Status: Active" << std::endl;
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
void displayAcademicStatus() {
    const int completedCourses = 4;
    const int totalCourses = 6;

    std::cout << "\n--- Academic Status ---" << std::endl;
    std::cout << "Completed Courses: "
              << completedCourses << std::endl;
    std::cout << "Remaining Courses: "
              << totalCourses - completedCourses << std::endl;
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
struct PortalSettings {
    bool notificationsEnabled;
    bool darkModeEnabled;
    std::string language;
};
void displayAttendanceSummary() {
    const int attendedClasses = 18;
    const int totalClasses = 20;

    double attendancePercentage =
        (static_cast<double>(attendedClasses) / totalClasses) * 100.0;

    std::cout << "\n--- Attendance Summary ---" << std::endl;
    std::cout << "Classes Attended: "
              << attendedClasses << "/" << totalClasses << std::endl;
    std::cout << "Attendance: "
              << attendancePercentage << "%" << std::endl;
}
void displayPortalStatus() {
    std::cout << "\n--- Portal Status ---" << std::endl;
    std::cout << "Account Status: Active" << std::endl;
    std::cout << "Registration: Completed" << std::endl;
    std::cout << "Profile: Updated" << std::endl;
}
bool loginUser() {
    const int maxAttempts = 3;

    for (int attempt = 1; attempt <= maxAttempts; ++attempt) {
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

        std::cout << "Invalid username or password.";

        if (attempt < maxAttempts) {
            std::cout << " Attempts remaining: "
                      << maxAttempts - attempt << std::endl;
        } else {
            std::cout << " Maximum login attempts reached."
                      << std::endl;
        }
    }

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

    editStudentProfile(student);
    displayStudentProfile(student);
    displayDashboard(student);
    displayAcademicStatus();
    displayAttendanceSummary();
    displayPortalStatus();

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