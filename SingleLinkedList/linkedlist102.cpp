#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;

};
struct node *head;

//at the beginning
void insert(int x){
    node *temp = new node();
    temp->data = x; // Set the data of the new node
    temp->next = head;
    head = temp;
     
}

void print(){
    node* temp = head;

    while(temp!= NULL){
          cout<<temp->data<<" ";
          temp= temp->next;
    }
    cout<<endl;
}
//linked list : inserting a node at the beginning

int main(){

     head = NULL; //list is empty

     cout<<"how many numbers ?\n";
     int n, x;
     cin>>n;

     for (int i = 0; i < n; i++){
        cout<<"enter number? \n";
        cin>>x;
        insert(x);

     }
     print();
}
