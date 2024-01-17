#include<iostream>
#include<stack>
using namespace std;

int top = -1;
const int MAX_STACK = 5;

int stackList[MAX_STACK];

bool isEmpty() {
    return (top < 0);
}

void push(int val) {
    if (top >= MAX_STACK - 1) {
        cout << "Stack Overflow!" << endl;
    } else {
        ++top;
        stackList[top] = val;
        cout << "Item inserted at the top" << endl;
    }
}



int pop() {
    int stackTop;
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
    } else {
        stackTop = stackList[top];
        --top;
    }
    return stackTop;
}

void display_stack() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        for (int i = top; i >= 0; i--) {
            cout << stackList[i] << " ";
        }
        cout << endl;
    }
}

void create_stack() {
    cout << "Enter the data to be inserted: " << endl;
    for (int i = 0; i < MAX_STACK; i++) {
        int data;
        cin >> data;
        push(data);
    }
}

void reverse_stack() {
    int tempStack[MAX_STACK];
    int tempTop = -1;

    // Copy elements from the original stack to the temporary stack
    while (!isEmpty()) {
        tempStack[++tempTop] = pop();
    }

    // Copy elements from the temporary stack back to the original stack
    for (int i = 0; i <= tempTop; i++) {
        push(tempStack[i]);
    }

    display_stack();
}
    

void reverseString() {
    string input;
    cout << "Enter the string to be reversed: ";
    cin.ignore();
    getline(cin, input);

    for (char c : input) {
        push(c);
    }

    cout << "Reversed String: ";
    while (!isEmpty()) {
        cout << (char)pop();
    }
    cout << endl;
}

bool isPalindrome() {
    string word;
    cout << "Enter the string you want to check: ";
    cin >> word;

    for (char w : word) {
        push(w);
    }

    for (char w : word) {
        if (w != (char)pop()) {
            return false;
        }
    }
    return true;
}

void decimalToBinary(int decimal) {
    stack<int> binaryNum;

    while (decimal > 0) {
        int reminder = decimal % 2;
        binaryNum.push(reminder);
        decimal = decimal / 2;
    }

    cout << "Binary Number: ";
    while (!binaryNum.empty()) {
        cout << binaryNum.top();
        binaryNum.pop();
    }
    cout << endl;
}

bool isOp(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int opOrder(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

string infixToPostFix(const string& infix) {
    string postfix = "";
    stack<char> opStack;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            opStack.push(c);
        } else if (c == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.pop(); // Discard the '(' from the stack
        } else if (isOp(c)) {
            while (!opStack.empty() && opOrder(opStack.top()) >= opOrder(c)) {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(c);
        }
    }

    while (!opStack.empty()) {
        postfix += opStack.top();
        opStack.pop();

    }

    return postfix;
}

int evaluatePostFix(const string& postFix) {
    stack<int> operandStack;

    for (char c : postFix) {
        if (isdigit(c)) {
            operandStack.push(c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            switch (c) {
                case '+':
                    operandStack.push(operand1 + operand2);
                    break;
                case '-':
                    operandStack.push(operand1 - operand2);
                    break;
                case '*':
                    operandStack.push(operand1 * operand2);
                    break;
                case '/':
                    operandStack.push(operand1 / operand2);
                    break;
            }
        }
    }

    return operandStack.top();
}

int main() {
    int choice;
    do {
        cout << "\t\tMenu" << endl;
        cout << "1. Push data to the stack" << endl;
        cout << "2. Pop data from the stack" << endl;
        cout << "3. Display data from stack" << endl;
        cout << "4. Reverse Stack" << endl;
        cout << "5. Reverse a String" << endl;
        cout << "6. Check for Palindrome" << endl;
        cout << "7. Decimal to Binary" << endl;
        cout << "8. Infix to Postfix" << endl;
        cout << "9. Postfix Evaluation" << endl;
        cout << "10. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                create_stack();
                display_stack();
                break;
            case 2:
                pop();
                display_stack();
                break;
            case 3:
                display_stack();
                break;
            case 4:
                reverse_stack();
                break;
            case 5:
                reverseString();
                break;
            case 6:
                if (isPalindrome()) {
                    cout << "It's a palindrome!" << endl;
                } else {
                    cout << "It's not a palindrome!" << endl;
                }
                break;
            case 7: {
                int decimal;
                cout << "Enter a decimal number to convert to binary: ";
                cin >> decimal;
                decimalToBinary(decimal);
                break;
            }
            case 8: {
                string infixExp;
                cout << "Enter an infix expression to convert to postfix: ";
                cin.ignore();
                getline(cin, infixExp);
                cout << "Postfix expression: " << infixToPostFix(infixExp) << endl;
                break;
            }
            case 9: {
                string postfixExp;
                cout << "Enter a postfix expression to evaluate: ";
                cin.ignore();
                getline(cin, postfixExp);
                cout << "Evaluation result: " << evaluatePostFix(postfixExp) << endl;
                break;
            }
            case 10:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Error input" << endl;
                break;
        }
    } while (choice != 10);

    return 0;
}
