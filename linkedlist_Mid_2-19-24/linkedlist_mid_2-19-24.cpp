#include <iostream>
#include <string>

using namespace std;

// Linked List Node for Employee Management System
class Employee {
public:
    int id;
    string name;
    string department;
    int salary;
    Employee* next;

    Employee(int id, const string& name, const string& department, int salary)
        : id(id), name(name), department(department), salary(salary), next(nullptr) {}
};

class EmployeeLinkedList {
private:
    Employee* head;
    int size;

public:
    EmployeeLinkedList() : head(nullptr), size(0) {}

    void addEmployee(int id, const string& name, const string& department, int salary) {
        Employee* newEmployee = new Employee(id, name, department, salary);
        if (head == nullptr) {
            head = newEmployee;
        }
        else {
            Employee* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newEmployee;
        }
        size++;
    }

    void displayEmployees() {
        cout << "\nEmployee List:" << endl;
        Employee* temp = head;
        while (temp != nullptr) {
            cout << "ID: " << temp->id << ", Name: " << temp->name << ", Department: " << temp->department
                << ", Salary: " << temp->salary << endl;
            temp = temp->next;
        }
        cout << "Total number of employees: " << size << endl;
    }

    ~EmployeeLinkedList() {
        Employee* temp = head;
        while (temp != nullptr) {
            Employee* nextEmployee = temp->next;
            delete temp;
            temp = nextEmployee;
        }
    }
};

int main() {
    EmployeeLinkedList employeeList;

    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    for (int i = 0; i < numEmployees; ++i) {
        int id, salary;
        string name, department;

        cout << "\nEnter details for employee " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> id;
        cout << "Name: ";
        cin >> name;
        cout << "Department: ";
        cin >> department;
        cout << "Salary: ";
        cin >> salary;

        employeeList.addEmployee(id, name, department, salary);
    }

    employeeList.displayEmployees();

    return 0;
}
//changes