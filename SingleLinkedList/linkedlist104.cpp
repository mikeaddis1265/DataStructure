#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;

};

//function to reverese linkedlist
node* reverse(node* head){

    node *current, *prev, *Next;
     current = head;
     prev = NULL;

    while (current != NULL){
        Next = current->next;
        current->next = prev;
        prev = current;
        current = Next;

    }

        head = prev;
        return head;

}

//fucntion to insert node
node* insert(node *head, int data){
    node* temp = new node();

    temp->data = data;
    temp->next = NULL;

    if (head == NULL){
        head = temp;
    }
    else{
        node* temp1 = head;
        while(temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
           
            temp1->next = temp;
    }
    return head;
}

void print (node* head)
{
    node* temp = new node();
    temp = head;

    while(temp != NULL){
        cout<<temp->data;
        cout<<" ";
        temp = temp->next;
    }
}


//funnction to delete a node at any postion in a linkedlist

int main(){

    node* head = NULL;
    head = insert(head,4);
    head = insert(head, 3);
    head = insert(head, 5);
    print(head);
    cout<<endl;

    reverse(head);
    print(head);
    cout<<endl;

    

    

}