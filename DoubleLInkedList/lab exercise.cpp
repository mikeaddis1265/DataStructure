#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node* prev;  // for double linked list

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;  // for double linked list

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAtMiddle(int data, int position) {
        Node* newNode = new Node(data);
        Node* current = head;
        int count = 1;
        while (current && count < position) {
            current = current->next;
            count++;
        }
        if (current) {
            newNode->next = current->next;
            current->next = newNode;
            newNode->prev = current;
            if (newNode->next) {
                newNode->next->prev = newNode;
            }
        }
    }

    void deleteFirstNode() {
        if (head) {
            Node* temp = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            }
            delete temp;
        }
    }

    void deleteLastNode() {
        if (head) {
            if (head == tail) {
                delete head;
                head = tail = nullptr;
            } else {
                Node* temp = tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete temp;
            }
        }
    }

    void deleteMiddleNode(int position) {
        if (head) {
            Node* current = head;
            int count = 1;
            while (current && count < position - 1) {
                current = current->next;
                count++;
            }
            if (current && current->next) {
                Node* temp = current->next;
                current->next = current->next->next;
                if (current->next) {
                    current->next->prev = current;
                }
                delete temp;
            }
        }
    }

    void displayFromFirstToLast() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void displayFromLastToFirst() {
        Node* current = tail;
        while (current) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }

    bool searchElement(int value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

int main() {
    LinkedList sll;
    LinkedList dll;

    char choice;
    do {
        std::cout << "Main Menu:\n";
        std::cout << "A) SLL\nB) DLL\nC) EXIT\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 'A':
            case 'a': {
                char sllChoice;
                do {
                    std::cout << "SLL Menu:\n";
                    std::cout << "1) Insert at the beginning\n"
                              << "2) Insert at the end\n"
                              << "3) Insert at the middle\n"
                              << "4) Delete the first node\n"
                              << "5) Delete the last node\n"
                              << "6) Delete the middle node\n"
                              << "7) Display from 1st to last\n"
                              << "8) Display from last to 1st\n"
                              << "9) Search an element\n"
                              << "0) Return to the main menu\n";
                    std::cout << "Enter your choice: ";
                    std::cin >> sllChoice;

                    switch (sllChoice) {
                        case '1':
                            // Insert at the beginning
                            int value;
                            std::cout << "Enter value to insert: ";
                            std::cin >> value;
                            sll.insertAtBeginning(value);
                            break;

                        case '2':
                            // Insert at the end
                            std::cout << "Enter value to insert: ";
                            std::cin >> value;
                            sll.insertAtEnd(value);
                            break;

                        case '3':
                            // Insert at the middle
                            int position;
                            std::cout << "Enter position to insert at: ";
                            std::cin >> position;
                            std::cout << "Enter value to insert: ";
                            std::cin >> value;
                            sll.insertAtMiddle(value, position);
                            break;

                        case '4':
                            // Delete the first node
                            sll.deleteFirstNode();
                            break;

                        case '5':
                            // Delete the last node
                            sll.deleteLastNode();
                            break;

                        case '6':
                            // Delete the middle node
                            std::cout << "Enter position to delete: ";
                            std::cin >> position;
                            sll.deleteMiddleNode(position);
                            break;

                        case '7':
                            // Display from 1st to last
                            sll.displayFromFirstToLast();
                            break;

                        case '8':
                            // Display from last to 1st
                            sll.displayFromLastToFirst();
                            break;

                        case '9':
                            // Search an element
                            std::cout << "Enter element to search: ";
                            std::cin >> value;
                            if (sll.searchElement(value)) {
                                std::cout << "Element found in the list.\n";
                            } else {
                                std::cout << "Element not found in the list.\n";
                            }
                            break;

                        case '0':
                            // Return to the main menu
                            break;

                        default:
                            std::cout << "Invalid choice. Please enter a number between 1 and 9 (or 0 to return).\n";
                    }

                } while (sllChoice != '0');
                break;
            }

            case 'B':
            case 'b': {
                // Similar menu for DLL operations
                char dllChoice;
                do {
                    std::cout << "DLL Menu:\n";
                    std::cout << "1) Insert at the beginning\n"
                              << "2) Insert at the end\n"
                              << "3) Insert at the middle\n"
                              << "4) Delete the first node\n"
                              << "5) Delete the last node\n"
                              << "6) Delete the middle node\n"
                             
                              << "7) Display from 1st to last\n"
                              << "8) Display from last to 1st\n"
                              << "9) Search an element\n"
                              << "0) Return to the main menu\n";
                    std::cout << "Enter your choice: ";
                    std::cin >> dllChoice;

                    switch (dllChoice) {
                        case '1':
                            // Insert at the beginning
                            int value;
                            std::cout << "Enter value to insert: ";
                            std::cin >> value;
                            dll.insertAtBeginning(value);
                            break;

                        case '2':
                            // Insert at the end
                            std::cout << "Enter value to insert: ";
                            std::cin >> value;
                            dll.insertAtEnd(value);
                            break;

                        case '3':
                            // Insert at the middle
                            int position;
                            std::cout << "Enter position to insert at: ";
                            std::cin >> position;
                            std::cout << "Enter value to insert: ";
                            std::cin >> value;
                            dll.insertAtMiddle(value, position);
                            break;

                        case '4':
                            // Delete the first node
                            dll.deleteFirstNode();
                            break;

                        case '5':
                            // Delete the last node
                            dll.deleteLastNode();
                            break;

                        case '6':
                            // Delete the middle node
                            std::cout << "Enter position to delete: ";
                            std::cin >> position;
                            dll.deleteMiddleNode(position);
                            break;

                        case '7':
                            // Display from 1st to last
                            dll.displayFromFirstToLast();
                            break;

                        case '8':
                            // Display from last to 1st
                            dll.displayFromLastToFirst();
                            break;

                        case '9':
                            // Search an element
                            std::cout << "Enter element to search: ";
                            std::cin >> value;
                            if (dll.searchElement(value)) {
                                std::cout << "Element found in the list.\n";
                            } else {
                                std::cout << "Element not found in the list.\n";
                            }
                            break;

                        case '0':
                            // Return to the main menu
                            break;

                        default:
                            std::cout << "Invalid choice. Please enter a number between 1 and 9 (or 0 to return).\n";
                    }

                } while (dllChoice != '0');
                break;
            }

            case 'C':
            case 'c':
                std::cout << "Exiting program.\n";
                break;

            default:
                std::cout << "Invalid choice. Please enter A, B, or C.\n";
        }

    } while (choice != 'C' && choice != 'c');

    return 0;
}
