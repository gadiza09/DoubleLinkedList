#include <iostream>
#include <string>
using namespace std;

struct node{
    string name;
    int qty;
    node *next, *prev;
}*head = NULL, *tail = NULL;

void view(){
    node *curr = head;
    int x = 1;
    cout << "Items in store: \n";
    while(curr != NULL){
        cout << x << ". Name: " << curr->name << " | Quantity: " << curr->qty << endl;
        curr = curr->next;
        x++;
    }
}

void insertHead(string name, int qty){
    node *curr = new(node);
    curr->name = name;
    curr->qty = qty;
    
    if(head == NULL){
        head = curr;
        tail = curr;
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

int sizeOfList(){
    int y = 0;
    node *curr = head;
    while(curr != NULL){
        y++;
        curr = curr->next;
    }
    return y;
}

void takeOrder(int idx){
    int i;
    node *curr = head;
    if(head == NULL){
        cout << "There is no order in the list!";
    }
    else{
        if(idx == 1){
            deleteHead();
        }
        else if(idx == sizeOfList()){
            deleteTail();
        }
        else{
            node *temp = head;
            for(i = 1; i < idx; i++){
                curr = curr->next;
                temp = curr->prev;
            }
            temp->next = curr->next;
            curr->next->prev->prev = temp;
            delete (curr);
        }
        cout << "Order has been successfully taken! \n";
    }
}




int main(){
    
    cout << "Welcome to the store!";
    while(true){
        int choice;
        cout << "\nMenu: \n[1]View Order List \n[2]Add A New Order \n[3]Take Order \n[4]Exit \nInput Choice: ";
        cin >> choice;
        if(choice == 1){
            view();
        }
        
        else if(choice == 2){
            string name;
            int qty;
            cout << "Insert name: ";
            cin >> name;
            cout << "Insert quantity: ";
            cin >> qty;
            if(name.size() < 3 || name.size() > 30 || qty < 1 || qty > 20){
                cout << "Make sure the name of the item is between 3 and 30 characters and the quantity is between 1 and 20! \n";
            }
            else{
                insertHead(name, qty);
                cout << "Order has been successfully added! \n";
            }
        }
        else if(choice == 3){
            view();
            int idx;
            cout << "Enter the index of the item you want to take: ";
            cin >> idx;
            if(idx > sizeOfList()){
                cout << "Please choose from the list!";
            }
            else{
                takeOrder(idx);
            }
        }
        else if(choice == 4){
            break;
        }
        else{
            cout << "Please choose from the options! \n";
        }
    }
}
