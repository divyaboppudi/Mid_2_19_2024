#include <iostream> // Include the input/output stream library for console I/O
#include <string> // Include the string library for string manipulation

using namespace std; // Using the standard namespace for cout, cin, string, etc.

// Linked List Node for Employee Management System
class Employee {
public:
    int id; // Employee ID
    string name; // Employee name
    string department; // Employee department
    int salary; // Employee salary
    Employee* next; // Pointer to the next employee node

    // Constructor to initialize employee details
    Employee(int id, const string& name, const string& department, int salary)
        : id(id), name(name), department(department), salary(salary), next(nullptr) {}
};

// Linked List to manage employees
class EmployeeLinkedList {
private:
    Employee* head; // Pointer to the first employee node
    int size; // Total number of employees in the list

public:
    // Constructor to initialize an empty linked list
    EmployeeLinkedList() : head(nullptr), size(0) {}

    // Function to add an employee to the linked list
    void addEmployee(int id, const string& name, const string& department, int salary) {
        // Create a new employee node
        Employee* newEmployee = new Employee(id, name, department, salary);
        if (head == nullptr) {
            // If the list is empty, set the new employee as the head
            head = newEmployee;
        }
        else {
            // Traverse the list to find the last node
            Employee* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            // Append the new employee to the end of the list
            temp->next = newEmployee;
        }
        // Increment the size of the list
        size++;
    }

    // Function to display details of all employees in the list
    void displayEmployees() {
        cout << "\nEmployee List:" << endl;
        Employee* temp = head;
        while (temp != nullptr) {
            // Print details of each employee
            cout << "ID: " << temp->id << ", Name: " << temp->name << ", Department: " << temp->department
                << ", Salary: " << temp->salary << endl;
            // Move to the next employee in the list
            temp = temp->next;
        }
        // Print the total number of employees in the list
        cout << "Total number of employees: " << size << endl;
    }

    // Destructor to free memory allocated for employee nodes
    ~EmployeeLinkedList() {
        Employee* temp = head;
        while (temp != nullptr) {
            // Store the next employee node before deleting the current node
            Employee* nextEmployee = temp->next;
            delete temp; // Delete the current employee node
            temp = nextEmployee; // Move to the next employee node
        }
    }
};

int main() {
    // Create an instance of EmployeeLinkedList to manage employees
    EmployeeLinkedList employeeList;

    int numEmployees;
    cout << "Enter the number of employees: ";
    cin >> numEmployees;

    // Input employee details from the user and add them to the list
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

        // Add the employee to the linked list
        employeeList.addEmployee(id, name, department, salary);
    }

    // Display the details of all employees in the list
    employeeList.displayEmployees();

    return 0;
}
//changes