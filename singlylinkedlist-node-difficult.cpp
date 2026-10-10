#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

// 1. Insert at beginning
void insertBeginning(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = head;
    head = newNode;

    cout << "Node inserted successfully.\n";
}

// 2. Insert at end
void insertEnd(int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Node inserted successfully.\n";
}

// 3. Insert at a position (1-based)
void insertPosition(int value, int pos)
{
    if (pos < 1)
    {
        cout << "Invalid position.\n";
        return;
    }

    if (pos == 1)
    {
        insertBeginning(value);
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Position out of range.\n";
        return;
    }

    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Node inserted at position " << pos << ".\n";
}

// 4. Delete from beginning
void deleteBeginning()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    cout << "First node deleted.\n";
}

// 5. Delete from end
void deleteEnd()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;

        cout << "Last node deleted.\n";
        return;
    }

    Node* temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;

    cout << "Last node deleted.\n";
}

// 6. Delete a node by value
void deleteValue(int value)
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    if (head->data == value)
    {
        deleteBeginning();
        return;
    }

    Node* temp = head;

    while (temp->next != NULL &&
           temp->next->data != value)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        cout << "Value not found.\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;

    cout << "Node deleted successfully.\n";
}

// 7. Delete at position
void deletePosition(int pos)
{
    if (head == NULL || pos < 1)
    {
        cout << "Invalid position or empty list.\n";
        return;
    }

    if (pos == 1)
    {
        deleteBeginning();
        return;
    }

    Node* temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        cout << "Position does not exist.\n";
        return;
    }

    Node* del = temp->next;
    temp->next = del->next;
    delete del;

    cout << "Node deleted at position " << pos << ".\n";
}

// 8. Search a value
void searchValue(int value)
{
    Node* temp = head;
    int pos = 1;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            cout << "Found at position " << pos << ".\n";
            return;
        }

        temp = temp->next;
        pos++;
    }

    cout << "Value not found.\n";
}

// 9. Display list
void display()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "HEAD -> ";

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// 10. Count nodes
int countNodes()
{
    int count = 0;
    Node* temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

// 11. Update first matching value
void updateValue(int oldValue, int newValue)
{
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->data == oldValue)
        {
            temp->data = newValue;
            cout << "Value updated successfully.\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Value not found.\n";
}

// 12. Reverse list
void reverseList()
{
    Node* previous = NULL;
    Node* current = head;
    Node* nextNode = NULL;

    while (current != NULL)
    {
        nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }

    head = previous;

    cout << "List reversed successfully.\n";
}

// 13. Find maximum value
void findMaximum()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    int maximum = head->data;
    Node* temp = head->next;

    while (temp != NULL)
    {
        if (temp->data > maximum)
        {
            maximum = temp->data;
        }

        temp = temp->next;
    }

    cout << "Maximum value: " << maximum << "\n";
}

// 14. Find minimum value
void findMinimum()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    int minimum = head->data;
    Node* temp = head->next;

    while (temp != NULL)
    {
        if (temp->data < minimum)
        {
            minimum = temp->data;
        }

        temp = temp->next;
    }

    cout << "Minimum value: " << minimum << "\n";
}

// 15. Sort list in ascending order
void sortList()
{
    if (head == NULL || head->next == NULL)
    {
        cout << "List is already sorted.\n";
        return;
    }

    Node* current;
    Node* index;

    for (current = head; current->next != NULL;
         current = current->next)
    {
        for (index = current->next; index != NULL;
             index = index->next)
        {
            if (current->data > index->data)
            {
                int temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }

    cout << "List sorted in ascending order.\n";
}

// 16. Remove duplicate values
void removeDuplicates()
{
    Node* current = head;

    while (current != NULL)
    {
        Node* previous = current;
        Node* temp = current->next;

        while (temp != NULL)
        {
            if (temp->data == current->data)
            {
                previous->next = temp->next;
                delete temp;
                temp = previous->next;
            }
            else
            {
                previous = temp;
                temp = temp->next;
            }
        }

        current = current->next;
    }

    cout << "Duplicate values removed.\n";
}

// 17. Find middle node (slow/fast pointers)
void findMiddle()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle value: " << slow->data << "\n";
}

// 18. Clear the entire list
void clearList()
{
    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    cout << "All nodes deleted.\n";
}

// Main function
int main()
{
    int choice, value, pos;
    int oldValue, newValue;

    do
    {
        cout << "\n===== ADVANCED LINKED LIST =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete by Value\n";
        cout << "7. Delete at Position\n";
        cout << "8. Search Value\n";
        cout << "9. Display List\n";
        cout << "10. Count Nodes\n";
        cout << "11. Update Value\n";
        cout << "12. Reverse List\n";
        cout << "13. Find Maximum\n";
        cout << "14. Find Minimum\n";
        cout << "15. Sort List\n";
        cout << "16. Remove Duplicates\n";
        cout << "17. Find Middle Node\n";
        cout << "18. Clear List\n";
        cout << "0. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertEnd(value);
                break;

            case 3:
                cout << "Enter value and position: ";
                cin >> value >> pos;
                insertPosition(value, pos);
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteValue(value);
                break;

            case 7:
                cout << "Enter position: ";
                cin >> pos;
                deletePosition(pos);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                searchValue(value);
                break;

            case 9:
                display();
                break;

            case 10:
                cout << "Total nodes: " << countNodes() << "\n";
                break;

            case 11:
                cout << "Enter old and new values: ";
                cin >> oldValue >> newValue;
                updateValue(oldValue, newValue);
                break;

            case 12:
                reverseList();
                break;

            case 13:
                findMaximum();
                break;

            case 14:
                findMinimum();
                break;

            case 15:
                sortList();
                break;

            case 16:
                removeDuplicates();
                break;

            case 17:
                findMiddle();
                break;

            case 18:
                clearList();
                break;

            case 0:
                clearList();
                cout << "Program terminated.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
