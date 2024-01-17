#include <iostream>
using namespace std;

// A linked list node
struct Node
{
   int data;
   struct Node *next;
};

//function to  insert at the beginning
void Add_beginning(Node** head_pointer, int new_data)
{
    //allocate a new node
    Node* new_node = new Node();

    //put the data
    new_node->data = new_data;

    //make the next of new node as a head
    new_node->next = (*head_pointer);

    //Make the head point to the new node
    (*head_pointer) = new_node;

}

//fucntion to insert at the end
void Add_end(Node** head_pointer, int new_data)
{
    //allocate a new node
    Node* new_node = new Node();

    //put the data
    new_node->data = new_data;
    new_node->next = NULL; 

    //create a new pointer to traverse
    Node* temp = (*head_pointer);
    temp = (*head_pointer);

    // 4. If the Linked List is empty,
    // then make the new node as head
    if(head_pointer == NULL)
    {
        *(head_pointer) = new_node;
        return;
    }
    //Else traverse till the last node
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
        temp->next = new_node;
        return;
          
}

    //function to insert at the middle
    void Add_middle(Node** head_pointer, int data, int position)
    {
        Node* temp = (*head_pointer);

        //create our new node and intialize it
        Node* new_node = new Node();
        new_node->data = data;
        new_node->next = NULL;

        //if postion 1 make the headpointr point to new node
        if(position == 1)
        {
            new_node->next = temp;
            (*head_pointer) = new_node;
            return;
        }

        //else traverse to the node at postion - 1
        for(int i = 1; i < position -1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        //check if the postion is valid
        if(temp == NULL)
        {
            cout<<"Invalid position. Inserting at the end"<<endl;
            temp = (*head_pointer);
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
        }

        //Insert the new node at the specified postion
        new_node->next = temp->next;
        temp->next = new_node;
    }

    //fuction that delete first node
    void Delete_beginning(Node** head_pointer)
    {
        //check if the list is empty
        if(*head_pointer == NULL)
        {
            return;
        }
        //create a new pointer
        Node* temp = *head_pointer;
        *head_pointer = (*head_pointer)->next;
        delete temp;
    }

    //Delete the last node
    void Delete_last(Node** head_pointer)
    {
        Node* temp = *head_pointer; // pointer to traversing
        Node* prev = NULL;

        while(temp->next != NULL)
        {   
            prev = temp; // track previous node before pointing to another node
            temp = temp->next;
        }
        delete temp;
        prev->next = NULL;
        return;
    }

    //6) Delete the at any position node
    void Delete_anypostion(Node** head_pointer, int position) 
{  
    if (*head_pointer == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    if (position == 1) 
    {
        Node* temp = *head_pointer;
        *head_pointer = (*head_pointer)->next;
        delete temp;
        return;
    }

    Node* temp = *head_pointer;
    for (int i = 0; i < position - 2 && temp != NULL; i++) 
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) 
    {
        cout << "Invalid position\n";
        return;
    }

    Node* temp2 = temp->next;
    temp->next = temp2->next;
    delete temp2;
}

//7function to display from first to last
 void print_fist_last(Node** head_pointer)
 {
     
    Node* current = *head_pointer;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
 }

 //displaybackward
 void print_last(Node** head_pointer)
 {
    if(*head_pointer == NULL)
    {
        cout<<"no elemt";
        return;
    }
    Node* temp =(*head_pointer);
    Node* temp2;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    do{
        temp2 = *head_pointer;
        while(temp2->next != temp)
        {
            temp2 = temp2->next;
        }
            cout<<temp->data;
            temp = temp2;
    }while(temp != *head_pointer);
    
 }

 //function to display last to fist
 void print_last_first(Node** head_pointer)
{
    Node* temp = *head_pointer;

    // Base case: check if the current node is NULL
    if (temp == NULL) {
        return;
    }

    // Recursive call for the next node
    if (temp->next != NULL) {
        print_last_first(&temp->next);
    }

    // Print the data of the current node
    cout << temp->data << " ";
}

    //function to search an element
    void search_value(Node** head_pointer, int value)
    {
        if(*head_pointer == NULL)
        {
            cout<<"no element\n";
            return;
        }

        Node* temp = *head_pointer;
        int count = 0;
        while(temp != NULL)
        {
            count++;
            if(temp->data == value)
            {
                cout<<"the number is found in the "<<count<<" position\n";
                return;
            }
            temp = temp->next;
        }
            cout<<"not found\n";
    }   
         
         int main()
{
    Node* head_ptr = NULL;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at the end\n";
        cout << "3. Insert at the middle\n";
        cout << "4. Delete the 1st node\n";
        cout << "5. Delete the last node\n";
        cout << "6. Delete the middle node\n";
        cout << "7. Display from 1st to last\n";
        cout << "8. Display from last to 1\n";
        cout << "9. Search an element\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter the value to insert at the beginning: ";
                cin >> value;
                Add_beginning(&head_ptr, value);
                break;
            }

            case 2: {
                int value;
                cout << "Enter the value to insert at the end: ";
                cin >> value;
                Add_end(&head_ptr, value);
                break;
            }

            case 3: {
                int position, value;
                cout << "Enter the position to insert at the middle: ";
                cin >> position;
                cout << "Enter the value to insert: ";
                cin >> value;
                Add_middle(&head_ptr, value, position);
                break;
            }

            case 4:
                Delete_beginning(&head_ptr);
                break;

            case 5:
                Delete_last(&head_ptr);
                break;

            case 6: {
                int position;
                cout << "Enter the position to delete at the middle: ";
                cin >> position;
                Delete_anypostion(&head_ptr, position);
                break;
            }

            case 7:
                print_fist_last(&head_ptr);
                break;

            case 8:
                print_last(&head_ptr);
               // print_last_first(&head_ptr);
                break;

            case 9: {
                int value;
                cout << "Enter the value to search: ";
                cin >> value;
                search_value(&head_ptr, value);
                break;
            }

            case 10:
                cout << "Exiting the program\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 10);

    return 0;
}


    
