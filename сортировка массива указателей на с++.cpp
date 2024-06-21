#include <iostream>
#include <string>
#include <algorithm>
class Student {
public:
    Student(int id, std::string name) : id(id), name(name) {}

    int getId() const { return id; }
    std::string getName() const { return name; }

private:
    int id;
    std::string name;
};
bool compareStudents(const Student* student1, const Student* student2) {
    return student1->getId() < student2->getId();
}
void sortStudentPointersArray(Student** students, int size) {
    std::sort(students, students + size, compareStudents);
}
int main() {
    int numStudents;
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;
    Student** students = new Student * [numStudents];
    for (int i = 0; i < numStudents; ++i) {
        int id;
        std::string name;

        std::cout << "Enter ID for student " << i + 1 << ": ";
        std::cin >> id;

        std::cout << "Enter name for student " << i + 1 << ": ";
        std::cin >> name;

        students[i] = new Student(id, name);
    }
    sortStudentPointersArray(students, numStudents);
    std::cout << "\nSorted student list:\n";
    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Student ID: " << students[i]->getId() << ", Name: " << students[i]->getName() << std::endl;
    }
    for (int i = 0; i < numStudents; ++i) {
        delete students[i];
    }
    delete[] students;

    return 0;
}