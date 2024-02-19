#include <iostream>
#include <string>

using namespace std;

// TreeNode represents a node in the organization hierarchy
class EmployeeNode {
public:
    string name;
    EmployeeNode* left;   // Represents the left child (subordinate)
    EmployeeNode* right;  // Represents the right child (subordinate)

    EmployeeNode(string name) : name(name), left(nullptr), right(nullptr) {}
};

// OrganizationHierarchy represents the organization hierarchy as a binary tree
class OrganizationHierarchy {
private:
    EmployeeNode* root;

public:
    OrganizationHierarchy() : root(nullptr) {}

    // Function to add an employee to the organization hierarchy
    void addEmployee(string name) {
        if (root == nullptr) {
            root = new EmployeeNode(name);
            cout << "Added " << name << " as the CEO." << endl;
        }
        else {
            string superior;
            cout << "Enter the superior of " << name << ": ";
            cin >> superior;
            EmployeeNode* superiorNode = findEmployee(root, superior);
            if (superiorNode != nullptr) {
                char position;
                cout << "Is " << name << " a (L)eft or (R)ight child of " << superior << "? ";
                cin >> position;
                if (position == 'L' || position == 'l') {
                    superiorNode->left = new EmployeeNode(name);
                }
                else {
                    superiorNode->right = new EmployeeNode(name);
                }
                cout << "Added " << name << " under " << superior << "." << endl;
            }
            else {
                cout << "Superior not found. Adding " << name << " as an independent employee." << endl;
            }
        }
    }

    // Function to find an employee in the organization hierarchy
    EmployeeNode* findEmployee(EmployeeNode* node, string name) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->name == name) {
            return node;
        }
        EmployeeNode* leftResult = findEmployee(node->left, name);
        if (leftResult != nullptr) {
            return leftResult;
        }
        return findEmployee(node->right, name);
    }

    // Function to display the organization hierarchy (in-order traversal)
    void displayHierarchy(EmployeeNode* node) {
        if (node == nullptr) {
            return;
        }
        displayHierarchy(node->left);
        cout << node->name << endl;
        displayHierarchy(node->right);
    }

    // Function to display the organization hierarchy
    void displayOrganization() {
        cout << "Organization Hierarchy:" << endl;
        displayHierarchy(root);
    }
};

int main() {
    OrganizationHierarchy orgHierarchy;

    int numEmployees;
    cout << "Enter the number of employees in the organization: ";
    cin >> numEmployees;

    for (int i = 0; i < numEmployees; ++i) {
        string name;
        cout << "Enter the name of employee " << i + 1 << ": ";
        cin >> name;
        orgHierarchy.addEmployee(name);
    }

    orgHierarchy.displayOrganization();

    return 0;
}
