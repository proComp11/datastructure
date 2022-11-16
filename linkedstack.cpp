/** stack using linked list -- written by pralay mondal**/
#include<iostream>
using namespace std;
class Node {
    public:
        int info;
        Node *next;

    public:    
    Node(int info){
        this->info = info;
        this->next = NULL;
    }
    
};

class Stack {
    Node *top;
    public:
    Stack(){
        top = NULL;
    }

    void push(int data){
        // create an object of node class
        Node *temp = new Node(data);
        if(temp == NULL){
            cout<<"\n Stack Overflow";
            return;
        }
        temp->info = data;
        temp->next = top;
        top = temp;
    }

    bool is_empty(){
        return top == NULL;
    }

    void pop(){
        if(is_empty()){
            cout<<"\n Stack Underflow";
            return;
        }
        // LIFO -- LAST IN FIRST OUT
        Node *tmp;
        tmp = top;
        top = tmp->next;
        cout<<"\n Popped Element is = " << tmp->info;
        free(tmp);
    }

    int peek_top(){
        if(top == NULL){
            return 0;
        }else{
            return top->info;
        }
    }

    void show_all(){
        Node *tmp;
        if(top == NULL){
            cout<<"\n\n Stack is empty \n\n";
        }else{
            tmp = top;
            while(tmp->next != NULL){
                cout<< tmp->info<< " => ";
                tmp = tmp->next;
            }
            if(tmp->next == NULL){
                cout<<tmp->info;
            }
        }
    }
};
int main(){
    int x,choice;
    Stack stk;
    do{
        cout<<"\n 1: PUSH AN ELEMENT INTO STACK";
        cout<<"\n 2: POP AN ELEMENT";
        cout<<"\n 3: PICK TOP ELEMENT";
        cout<<"\n 4: SHOW ALL ELEMENTS IN STACK";
        cout<<"\n 0: TO EXIT";
        cout<<"\n Enter your choice:";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"\n Enter an element:";
                cin>>x;
                stk.push(x);
                break;
            case 2: stk.pop();
                break;
            case 3: stk.peek_top() ? cout<<"\n Top Element is = "<< stk.peek_top(): cout<<"\n Stack is empty";
                break;
            case 4:stk.show_all();
                break;
            case 0: cout<<"\n The End";
                break;    
            default:cout<<"\n Invalid Input";        
        }
    }while(choice != 0);
    return 0;
}