#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;

};
struct node *head;

//function that insert a number in a linked list at any postion
void insert (int data, int position){
    node* temp1 = new node();
    temp1->data = data;
    temp1->next = NULL;

    if (position == 1){
        temp1->next = head;
        head = temp1;
        return ;
    }

    node* temp2 = head;
    for (int i = 1; i < position - 1; i++){
        temp2 = temp2->next;
    }
        temp1->next = temp2->next;
        temp2->next = temp1;
       
}


//function to delete elemnts of linked list at any position
void Delete(int a){
    node *temp = new node();
    temp = head;

    if(temp == NULL){
        cout<<"no element\n";
    }
    if(a == 1){
        head = temp->next;
        delete temp;
        return;
    }

    for(int i = 1; i < a - 1; i++){
        temp = temp->next;
    }
    node *temp2 = temp->next;
    temp->next =temp2->next;
    delete temp2;
    
}

//function to print elemnts of linked list
void print(){
    node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
        cout<<endl;
}

int main(){
    head = NULL;
    insert(1,1);
    insert(3,2);
    insert(5,1);
    insert(6,2);
    insert(53,3);
    
    Delete(4);
    
    print();
}