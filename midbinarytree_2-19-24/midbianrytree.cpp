#include <iostream> // Include the input/output stream library for console I/O
#include <string> // Include the string library for string manipulation

using namespace std; // Using the standard namespace for cout, cin, string, etc.

// TreeNode represents a node in the organization hierarchy
class EmployeeNode {
public:
    string name; // Name of the employee
    EmployeeNode* left;   // Pointer to the left child node (subordinate)
    EmployeeNode* right;  // Pointer to the right child node (subordinate)

    // Constructor to initialize an EmployeeNode with a given name
    EmployeeNode(string name) : name(name), left(nullptr), right(nullptr) {}
};

// OrganizationHierarchy represents the organization hierarchy as a binary tree
class OrganizationHierarchy {
private:
    EmployeeNode* root; // Pointer to the root node of the organization hierarchy

public:
    // Constructor to initialize an empty organization hierarchy
    OrganizationHierarchy() : root(nullptr) {}

    // Function to add an employee to the organization hierarchy
    void addEmployee(string name) {
        if (root == nullptr) { // If the organization is empty
            root = new EmployeeNode(name); // Create a new node and make it the root
            cout << "Added " << name << " as the CEO." << endl;
        }
        else { // If the organization is not empty
            string superior; // Variable to store the name of the superior
            cout << "Enter the superior of " << name << ": ";
            cin >> superior; // Input the name of the superior
            EmployeeNode* superiorNode = findEmployee(root, superior); // Find the superior in the hierarchy
            if (superiorNode != nullptr) { // If the superior is found
                char position; // Variable to store the position of the new employee
                cout << "Is " << name << " a (L)eft or (R)ight child of " << superior << "? ";
                cin >> position; // Input the position of the new employee relative to the superior
                if (position == 'L' || position == 'l') { // If the new employee is a left child
                    superiorNode->left = new EmployeeNode(name); // Create a new node and make it the left child
                }
                else { // If the new employee is a right child
                    superiorNode->right = new EmployeeNode(name); // Create a new node and make it the right child
                }
                cout << "Added " << name << " under " << superior << "." << endl;
            }
            else { // If the superior is not found
                cout << "Superior not found. Adding " << name << " as an independent employee." << endl;
            }
        }
    }

    // Function to find an employee in the organization hierarchy recursively
    EmployeeNode* findEmployee(EmployeeNode* node, string name) {
        if (node == nullptr) { // If the node is null (employee not found)
            return nullptr;
        }
        if (node->name == name) { // If the current node matches the name
            return node; // Return the node
        }
        EmployeeNode* leftResult = findEmployee(node->left, name); // Recursively search the left subtree
        if (leftResult != nullptr) { // If the employee is found in the left subtree
            return leftResult; // Return the node
        }
        return findEmployee(node->right, name); // Recursively search the right subtree
    }

    // Function to display the organization hierarchy (in-order traversal)
    void displayHierarchy(EmployeeNode* node) {
        if (node == nullptr) { // If the node is null (end of subtree)
            return;
        }
        displayHierarchy(node->left); // Recursively display the left subtree
        cout << node->name << endl; // Print the name of the current node
        displayHierarchy(node->right); // Recursively display the right subtree
    }

    // Function to display the organization hierarchy
    void displayOrganization() {
        cout << "Organization Hierarchy:" << endl;
        displayHierarchy(root); // Display the hierarchy starting from the root
    }
};

int main() {
    OrganizationHierarchy orgHierarchy; // Create an instance of OrganizationHierarchy

    int numEmployees; // Variable to store the number of employees
    cout << "Enter the number of employees in the organization: ";
    cin >> numEmployees; // Input the number of employees

    for (int i = 0; i < numEmployees; ++i) { // Loop to input employee names and add them to the hierarchy
        string name; // Variable to store the name of each employee
        cout << "Enter the name of employee " << i + 1 << ": ";
        cin >> name; // Input the name of the employee
        orgHierarchy.addEmployee(name); // Add the employee to the organization hierarchy
    }

    orgHierarchy.displayOrganization(); // Display the organization hierarchy

    return 0;
}
//changes