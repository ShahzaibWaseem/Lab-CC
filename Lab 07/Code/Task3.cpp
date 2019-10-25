#include <iostream>
#include <cctype>
#include <stdlib.h>

using namespace std;

struct node {
    char type;
    char data;
    node* next;
    node* prev;
};

int input_type(char ch){
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '/' || ch == '*')
        return 2;
    else
        return 3;
}

int main(int argc, char const *argv[]){
    node* n,* h,* t;
    n = new node;
    n->type = 'E';
    t = n;
    h = n;
    string expression;

    if (argc != 2){
        cout << "The Expression should be entered as a command line argument\nThere should be exactly two command line arguments\nThe Expression must be without any spaces\n\nUsage: a.exe <expression>" << endl;
        exit(1);
    }

    expression = argv[1];
    for (int i = 0; i < expression.length(); i++) {
        if (t->type == 'E') {
            switch (input_type(expression[i])) {
            case 1: // +,-
                cout << "E --> " << expression[i] << "\n\n";
                n = new node; n->data = expression[i]; n->next = NULL; n->prev = t;
                break;

            case 2: // *,/
                n = new node; n->type = 'T'; t->next = n; n->prev = t; t = n;

                cout << "T --> " << expression[i] << "\n\n";

                n = new node; n->data = expression[i]; n->next = NULL; n->prev = t;
                break;

            case 3: //id, num, or op
                n = new node; n->type = 'T'; t->next = n; n->prev = t; t = n;

                n = new node; n->type = 'F'; t->next = n; n->prev = t; t = n;

                cout << "E --> T --> F --> " << expression[i] << "\n\n";
                n = new node; n->data = expression[i]; n->next = NULL; n->prev = t;
                break;
            }

        }
        else if (t->type == 'T') {
            switch (input_type(expression[i])) {
            case 1:
                cout << "E --> " << expression[i] << "\n\n";
                //t now points to E. t is at root node
                t = t->prev;
                n = new node; n->data = expression[i]; n->next = NULL; n->prev = t;
                break;

            case 2:
                cout << "T --> " << expression[i] << "\n\n";
                n = new node; n->data = expression[i]; n->next = NULL; n->prev = t;
                break;

            case 3:
                n = new node; n->type = 'F'; t->next = n; n->prev = t; t = n;

                cout << "E --> T --> F --> " << expression[i] << "\n\n";
                n = new node; n->data = expression[i]; n->next = NULL; n->prev = t;
                break;
            }
        }
        else if (t->type == 'F') {
            switch (input_type(expression[i])) {
            case 1:
                t = t->prev; //goes from F to T
                t = t->prev; //goes form T to E

                cout << "E --> " << expression[i] << "\n\n";
                n = new node; n->data = expression[i]; n->next = NULL; n->prev = t;
                break;

            case 2:
                t = t->prev; //goes form F to T

                cout << "T --> " << expression[i] << "\n\n";
                n = new node; n->data = expression[i]; n->next = NULL; n->prev = t;
                break;

            case 3:
                cout << "F --> " << expression[i] << "\n\n";
                n = new node; n->data = expression[i]; n->next = NULL; n->prev = t;
                break;
            }
        }
    }
    return 0;
}