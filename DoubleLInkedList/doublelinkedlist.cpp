#include <iostream>
using namespace std;

//A double Linked list node
struct Node
{
    int data;
    Node* next;
    Node* prev;
};

//function to insert at the beginning
void Add_beginning(Node** head_pointer, int new_data)
{
    //allocate a new node
    Node* new_node = new Node();

    //put the data
    new_node->data = new_data;

    //point next of new node to first node
    new_node->next = (*head_pointer);

    //point previous of first pointer points to new node
    (*head_pointer)->prev = new_node;

    //move the head to point the new node
    (*head_pointer) = new_node;
    
    return;
}

//function to insert at the end
void Add_end(Node** head_pointer, int new_data)
{
    //allocate a new node
    Node* new_node = new Node();

    //put the data
    new_node->data = new_data;

    //if node is empty make is the first node
    if(*head_pointer == NULL)
    {
        *head_pointer = new_node;
        new_node->next = NULL;
        new_node->prev = *head_pointer;
        return;
    }
    //else traverse to the last
   
    else
    {
        Node* temp = *head_pointer;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        // //change the next of new node
         temp->next = new_node;
          new_node->next = NULL;
          return;
    }

   
}


// Function to insert at the middle of a doubly linked list
void Add_middle(Node** head_pointer, int data, int position)
{
    Node* temp = (*head_pointer);

    // Create our new node and initialize it
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = nullptr;
    new_node->prev = nullptr;

    // If position is 1, make the head pointer point to the new node
    if (position == 1)
    {
        new_node->next = temp;
        if (temp != nullptr) {
            temp->prev = new_node;
        }
        (*head_pointer) = new_node;
        return;
    }

    // Traverse to the node at position - 1
    for (int i = 1; i < position - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    // Check if the position is valid
    if (temp == nullptr)
    {
        cout << "Invalid position. Inserting at the end" << endl;
        temp = (*head_pointer);
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
    }

    // Insert the new node at the specified position
    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next != nullptr) {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
}

void Delete_beginning(Node** head_pointer)
{
      //check if the list is empty
        if(*head_pointer == NULL)
        {
            return;
        }

       Node* temp = *head_pointer;
       *head_pointer = (*head_pointer)->next;
       
}