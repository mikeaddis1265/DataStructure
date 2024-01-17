#include <iostream>
using namespace std;

// Node structure for SLL
struct SLLNode {
    int data;
    SLLNode* next;
};

// Node structure for DLL
struct DLLNode {
    int data;
    DLLNode* next;
    DLLNode* prev;
};

// Function prototypes for SLL
SLLNode* insertAtBeginningSLL(SLLNode* head, int value);
SLLNode* insertAtEndSLL(SLLNode* head, int value);
SLLNode* insertAtMiddleSLL(SLLNode* head, int value, int position);
SLLNode* deleteFirstNodeSLL(SLLNode* head);
SLLNode* deleteLastNodeSLL(SLLNode* head);
SLLNode* deleteMiddleNodeSLL(SLLNode* head, int position);
void displayForwardSLL(SLLNode* head);
bool searchElementSLL(SLLNode* head, int value);

// Function prototypes for DLL
DLLNode* insertAtBeginningDLL(DLLNode* head, int value);
DLLNode* insertAtEndDLL(DLLNode* head, int value);
DLLNode* insertAtMiddleDLL(DLLNode* head, int value, int position);
DLLNode* deleteFirstNodeDLL(DLLNode* head);
DLLNode* deleteLastNodeDLL(DLLNode* head);
DLLNode* deleteMiddleNodeDLL(DLLNode* head, int position);
void displayForwardDLL(DLLNode* head);
void displayBackwardDLL(DLLNode* head);
bool searchElementDLL(DLLNode* head, int value);

int main() {
    SLLNode* sllHead = nullptr;
    DLLNode* dllHead = nullptr;

    char choice;
    do {
        cout << "\nMain Menu:\n";
        cout << "A) SLL\n";
        cout << "B) DLL\n";
        cout << "C) EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'A':
            case 'a': {
                char sllOption;
                do {
                    cout << "\nSLL Menu:\n";
                    cout << "1) Insert at the beginning\n";
                    cout << "2) Insert at the end\n";
                    cout << "3) Insert at the middle\n";
                    cout << "4) Delete the 1st node\n";
                    cout << "5) Delete the last node\n";
                    cout << "6) Delete the middle node\n";
                    cout << "7) Display from 1st to last\n";
                    cout << "8) Search an element\n";
                    cout << "9) Return to the main menu\n";
                    cout << "Enter your choice: ";
                    cin >> sllOption;

                    switch (sllOption) {
                        case '1':
                            cout << "Enter value to insert: ";
                            int sllValue;
                            cin >> sllValue;
                            sllHead = insertAtBeginningSLL(sllHead, sllValue);
                            break;
                        case '2':
                            cout << "Enter value to insert: ";
                            int sllEndValue;
                            cin >> sllEndValue;
                            sllHead = insertAtEndSLL(sllHead, sllEndValue);
                            break;
                        case '3':
                            cout << "Enter value to insert: ";
                            int sllMiddleValue;
                            cin >> sllMiddleValue;
                            cout << "Enter position: ";
                            int sllPosition;
                            cin >> sllPosition;
                            sllHead = insertAtMiddleSLL(sllHead, sllMiddleValue, sllPosition);
                            break;
                        case '4':
                            sllHead = deleteFirstNodeSLL(sllHead);
                            break;
                        case '5':
                            sllHead = deleteLastNodeSLL(sllHead);
                            break;
                        case '6':
                            cout << "Enter position to delete: ";
                            int sllDeletePosition;
                            cin >> sllDeletePosition;
                            sllHead = deleteMiddleNodeSLL(sllHead, sllDeletePosition);
                            break;
                        case '7':
                            displayForwardSLL(sllHead);
                            break;
                        case '8':
                            cout << "Enter element to search: ";
                            int sllSearchValue;
                            cin >> sllSearchValue;
                            if (searchElementSLL(sllHead, sllSearchValue)) {
                                cout << "Element found in the SLL.\n";
                            } else {
                                cout << "Element not found in the SLL.\n";
                            }
                            break;
                        case '9':
                            break;
                        default:
                            cout << "Invalid choice.\n";
                    }
                } while (sllOption != '9');
                break;
            }

            case 'B':
            case 'b': {
                char dllOption;
                do {
                    cout << "\nDLL Menu:\n";
                    cout << "1) Insert at the beginning\n";
                    cout << "2) Insert at the end\n";
                    cout << "3) Insert at the middle\n";
                    cout << "4) Delete the 1st node\n";
                    cout << "5) Delete the last node\n";
                    cout << "6) Delete the middle node\n";
                    cout << "7) Display from 1st to last\n";
                    cout << "8) Display from last to 1st\n";
                    cout << "9) Search an element\n";
                    cout << "10) Return to the main menu\n";
                    cout << "Enter your choice: ";
                    cin >> dllOption;

                    switch (dllOption) {
                        case '1':
                            cout << "Enter value to insert: ";
                            int dllValue;
                            cin >> dllValue;
                            dllHead = insertAtBeginningDLL(dllHead, dllValue);
                            break;
                        case '2':
                            cout << "Enter value to insert: ";
                            int dllEndValue;
                            cin >> dllEndValue;
                            dllHead = insertAtEndDLL(dllHead, dllEndValue);
                            break;
                        case '3':
                            cout << "Enter value to insert: ";
                            int dllMiddleValue;
                            cin >> dllMiddleValue;
                            cout << "Enter position: ";
                            int dllPosition;
                            cin >> dllPosition;
                            dllHead = insertAtMiddleDLL(dllHead, dllMiddleValue, dllPosition);
                            break;
                        case '4':
                            dllHead = deleteFirstNodeDLL(dllHead);
                            break;
                        case '5':
                            dllHead = deleteLastNodeDLL(dllHead);
                            break;
                        case '6':
                            cout << "Enter position to delete: ";
                            int dllDeletePosition;
                            cin >> dllDeletePosition;
                            dllHead = deleteMiddleNodeDLL(dllHead, dllDeletePosition);
                            break;
                        case '7':
                            displayForwardDLL(dllHead);
                            break;
                        case '8':
                            displayBackwardDLL(dllHead);
                            break;
                        case '9':
                            cout << "Enter element to search: ";
                            int dllSearchValue;
                            cin >> dllSearchValue;
                            if (searchElementDLL(dllHead, dllSearchValue)) {
                                cout << "Element found in the DLL.\n";
                            } else {
                                cout << "Element not found in the DLL.\n";
                            }
                            break;
                        case '10':
                            break;
                        default:
                            cout << "Invalid choice.\n";
                    }
                } while (dllOption != '10');
                break;
            }

            case 'C':
            case 'c':
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 'C' && choice != 'c');

    return 0;
}

// Function definitions for SLL
SLLNode* insertAtBeginningSLL(SLLNode* head, int value) {
    SLLNode* newNode = new SLLNode;
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

SLLNode* insertAtEndSLL(SLLNode* head, int value) {
    SLLNode* newNode = new SLLNode;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        return newNode;
    }

    SLLNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

SLLNode* insertAtMiddleSLL(SLLNode* head, int value, int position) {
    SLLNode* newNode = new SLLNode;
    newNode->data = value;
    newNode->next = nullptr;

    if (position == 1 || head == nullptr) {
        newNode->next = head;
        return newNode;
    }

    SLLNode* temp = head;
    for (int i = 1; i < position - 1 && temp->next != nullptr; ++i) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

SLLNode* deleteFirstNodeSLL(SLLNode* head) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete.\n";
        return nullptr;
    }

    SLLNode* newHead = head->next;
    delete head;
    cout << "Deleted the 1st node.\n";
    return newHead;
}

SLLNode* deleteLastNodeSLL(SLLNode* head) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete.\n";
        return nullptr;
    }

    if (head->next == nullptr) {
        delete head;
        cout << "Deleted the last node.\n";
        return nullptr;
    }

    SLLNode* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    cout << "Deleted the last node.\n";
    return head;
}

SLLNode* deleteMiddleNodeSLL(SLLNode* head, int position) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete.\n";
        return nullptr;
    }

    if (position == 1) {
        SLLNode* newHead = head->next;
        delete head;
        cout << "Deleted the node at position " << position << ".\n";
        return newHead;
    }

    SLLNode* temp = head;
    for (int i = 1; i < position - 1 && temp->next != nullptr; ++i) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Invalid position to delete.\n";
        return head;
    }

    SLLNode* toDelete = temp->next;
    temp->next = temp->next->next;

    delete toDelete;
    cout << "Deleted the node at position " << position << ".\n";
    return head;
}

void displayForwardSLL(SLLNode* head) {
    cout << "List from 1st to last: ";
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

bool searchElementSLL(SLLNode* head, int value) {
    while (head != nullptr) {
        if (head->data == value) {
            return true;
        }
        head = head->next;
    }
    return false;
}

// Function definitions for DLL
DLLNode* insertAtBeginningDLL(DLLNode* head, int value) {
    DLLNode* newNode = new DLLNode;
    newNode->data = value;
    newNode->next = head;
    newNode->prev = nullptr;

    if (head != nullptr) {
        head->prev = newNode;
    }

    return newNode;
}

DLLNode* insertAtEndDLL(DLLNode* head, int value) {
    DLLNode* newNode = new DLLNode;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        newNode->prev = nullptr;
        return newNode;
    }

    DLLNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

DLLNode* insertAtMiddleDLL(DLLNode* head, int value, int position) {
    DLLNode* newNode = new DLLNode;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (position == 1 || head == nullptr) {
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        return newNode;
    }

    DLLNode* temp = head;
    for (int i = 1; i < position - 1 && temp->next != nullptr; ++i) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;

    return head;
}

DLLNode* deleteFirstNodeDLL(DLLNode* head) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete.\n";
        return nullptr;
    }

    DLLNode* newHead = head->next;
    if (newHead != nullptr) {
        newHead->prev = nullptr;
    }
    delete head;
    cout << "Deleted the 1st node.\n";
    return newHead;
}

DLLNode* deleteLastNodeDLL(DLLNode* head) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete.\n";
        return nullptr;
    }

    if (head->next == nullptr) {
        delete head;
        cout << "Deleted the last node.\n";
        return nullptr;
    }

    DLLNode* temp = head;
        while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    cout << "Deleted the last node.\n";
    return head;
}

DLLNode* deleteMiddleNodeDLL(DLLNode* head, int position) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete.\n";
        return nullptr;
    }

    if (position == 1) {
        DLLNode* newHead = head->next;
        if (newHead != nullptr) {
            newHead->prev = nullptr;
        }
        delete head;
        cout << "Deleted the node at position " << position << ".\n";
        return newHead;
    }

    DLLNode* temp = head;
    for (int i = 1; i < position - 1 && temp->next != nullptr; ++i) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Invalid position to delete.\n";
        return head;
    }

    DLLNode* toDelete = temp->next;
    temp->next = temp->next->next;

    if (temp->next != nullptr) {
        temp->next->prev = temp;
    }

    delete toDelete;
    cout << "Deleted the node at position " << position << ".\n";
    return head;
}

void displayForwardDLL(DLLNode* head) {
    cout << "List from 1st to last: ";
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void displayBackwardDLL(DLLNode* head) {
    cout << "List from last to 1st: ";
    while (head->next != nullptr) {
        head = head->next;
    }

    while (head != nullptr) {
        cout << head->data << " ";
        head = head->prev;
    }
    cout << endl;
}

bool searchElementDLL(DLLNode* head, int value) {
    while (head != nullptr) {
        if (head->data == value) {
            return true;
        }
        head = head->next;
    }
    return false;
}


