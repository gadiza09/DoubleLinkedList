#include <iostream>
#include <string>

using namespace std;

struct node{
    int value;
    node *next, *prev;
}*head = NULL, *tail = NULL;

void insertHead(int value){
    node *curr = new(node);
    curr->value = value;
    
    if(head==NULL){
        head = curr;
        tail = curr;
        //head = tail = curr;
        curr->next = NULL;
        curr->prev = NULL;
    }
    else{
        curr->next = head;
        head->prev = curr;
        head = curr;
        curr->prev = NULL;
    }
}

void insertTail(int value){
    node *curr = new(node);
    curr->value = value;
    
    if(head == NULL){
        head = tail = curr;
        curr->next = NULL;
        curr->prev = NULL;
    }
    else{
        tail->next = curr;
        curr->prev = tail;
        curr->next = NULL;
        tail = curr;
    }
}

void insert(int value){
    node *curr = new(node);
    curr->value = value;
    
    if(head == NULL){
        head = tail = curr;
        curr->next = curr->prev = NULL;
    }
    else{
        if(curr->value <= head->value){
            insertHead(value);
        }
        else if(curr->value >= tail->value){
            insertTail(value);
        }
        else{
            node *temp = new(node);
            temp = head;
            while(temp != NULL){
                if(temp->value > curr->value){
                    curr->next = temp;
                    curr->prev = temp->prev;
                    temp->prev->next = curr;
                    temp->prev = curr;
                    break;
                }
                temp = temp->next;
            }
        }
    }
}

void deleteHead(){
    node *curr = head;

    if(head!=NULL){
        if(head ==tail){
            head = tail = NULL;
            delete(curr);
        }
        else{
            head = head->next;
            head->prev = NULL;
            delete(curr);
        }
    }
}

void deleteTail(){
    node *curr = tail;

    if(head!=NULL){
        if(head ==tail){
            head = tail = NULL;
            delete(curr);
        }
        else{
            tail = tail->prev;
            tail->next = NULL;
            delete(curr);
        }
    }
}

void deleteKey(int key){
    node *curr = head;
    if(head != NULL){
        if(head->value == key){
            deleteHead();
        }
        else if(tail->value == key){
            deleteTail();
        }
        else{
            node *temp = head;
            curr = head->next;
            while(temp!=NULL){
                if(curr->value == key){
                    temp = curr->prev;
                    temp->next = curr->next;
                    curr->next->prev = curr->prev;
                    delete(curr);
                    break;
                }
                temp = temp->next;
                curr = curr->next;
            }
        }
    }
}


void view(){
    node *curr = head;
    while(curr != NULL){
        cout << curr->value << " ";
        curr = curr->next;
    }
}

int main() {
    
    insert(10);
    insert(11);
    insert(5);
    insert(12);
    insert(8);
    insert(67);
    insert(1);
    insert(20);
    view();
    cout << "\n";
    deleteKey(8);
    view();

    
    return 0;
}
