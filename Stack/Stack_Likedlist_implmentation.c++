#include <iostream>
using namespace std;


class stack {
    int top;

    public:
     int a[1000];//max size of the stack

     stack()
     {
        top = -1;
     }
     bool push (int x);
     int pop();
     int peek();
     bool isEmpty();
     int size();
};

//implmentation of push
bool stack::push(int x)
{
    if (top >= (1000 - 1))
    {
        cout<<"stack Overflow";
        return false;
    }
    {
        a[++top] = x;
        cout<<x<<" pushed into stack\n";
        return true;
    }
}

//implmentation of pop
int stack::pop()
{
    if (top < 0)
    {
        cout<<"stack underflow\n";
        return 0;
    }
    else
    {
        int x = a[top--];
        return (x);
    }
}
//peek implmentation
int stack::peek()
{
    if(top < 0)
    {
        cout<<"stack emptu\n";
        return 0;
    }
    else
    {
        int x = a[top];
        return x;
    }
}
//isEmpty()
bool stack::isEmpty()
{
    return (top < 0);
}

int stack::size()
{
   
    return (top + 1);
}

int main()
{
    class stack numbers;
    for (int i = 0; i < 40; i = (i * 4) % 3)
    {
        numbers.push(i);
    }

    int size = numbers.size();
    cout <<"the size is : "<<size<<" \n";

    while (!numbers.isEmpty())
    {
        cout<<numbers.peek()<<"\n";
        numbers.pop();
    }

    return 0;
}