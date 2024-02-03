#include <iostream>
#include <string>
#include <vector>

class Student {
private:
    std::string name;
    int id;
    std::vector<std::string> classes;
    std::vector<char> grades;
    std::vector<std::string> semesters;
    double gpa;

public:
    // Constructors
    Student() : id(0), gpa(0.0) {}

    Student(std::string n, int i) : name(n), id(i), gpa(0.0) {}

    // Get and set methods
    void setName(std::string n) {
        name = n;
    }

    std::string getName() const {
        return name;
    }

    void setId(int i) {
        id = i;
    }

    int getId() const {
        return id;
    }

    void addClass(std::string className, char grade, std::string semester) {
        if (classes.size() < 100) {
            classes.push_back(className);
            grades.push_back(grade);
            semesters.push_back(semester);
        }
        else {
            std::cout << "Cannot add more classes. Maximum limit reached." << std::endl;
        }
    }

    // Calculate GPA
    void calculateGPA() {
        if (classes.empty()) {
            gpa = 0.0;
            return;
        }

        double totalPoints = 0.0;
        for (char grade : grades) {
            switch (grade) {
            case 'A':
                totalPoints += 4.0;
                break;
            case 'B':
                totalPoints += 3.0;
                break;
            case 'C':
                totalPoints += 2.0;
                break;
                // Add more cases for other grades if needed
            default:
                // Ignore unknown grades
                break;
            }
        }

        gpa = totalPoints / classes.size();
    }

    double getGPA() const {
        return gpa;
    }

    // Find all classes that match a user requested grade
    void findClassesByGrade(char requestedGrade) const {
        std::cout << "Classes with grade " << requestedGrade << ":" << std::endl;
        for (size_t i = 0; i < classes.size(); ++i) {
            if (grades[i] == requestedGrade) {
                std::cout << "Class: " << classes[i] << ", Semester: " << semesters[i] << std::endl;
            }
        }
    }
};

int main() {
    // Test the Student class
    Student student("Lionel Messi", 37455);

    student.addClass("Math", 'A', "Spring 2023");
    student.addClass("Physics", 'B', "Fall 2022");
    student.addClass("History", 'A', "Summer 2022");

    // Display all attributes
    std::cout << "Student Name: " << student.getName() << std::endl;
    std::cout << "Student ID: " << student.getId() << std::endl;

    student.calculateGPA();
    std::cout << "GPA: " << student.getGPA() << std::endl;

    // Find classes with a specific grade
    student.findClassesByGrade('A');

    return 0;
}
