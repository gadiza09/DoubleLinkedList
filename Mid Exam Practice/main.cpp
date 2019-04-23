#include <iostream>
using namespace std;

struct node{
    string rice;
    int weight;
    node *next, *prev;
}*head = NULL, *tail = NULL;

void addOrder(string rice, int weight){
    node *curr = new(node);
    curr->rice = rice;
    curr->weight = weight;
    
    if(head == NULL){
        head = curr;
        tail = curr;
        curr->prev = NULL;
        curr->next = NULL;
    }
    else{
        curr->next = head;
        head->prev = curr;
        head = curr;
        curr->prev = NULL;
    }
}

void sellRice(){
    node *curr = head;
    
    if(head!=NULL){
        if(head == tail){
            head = NULL;
            tail = NULL;
            delete(curr);
        }
        else{
            head = head->next;
            head->prev = NULL;
            delete(curr);
        }
    }
}

void view(){
    node *temp = head;
    cout << "Here is the rice stack: ";
    
    while(temp != NULL){
        cout << "\nType of rice: " << temp->rice << "\t Quantity: " << temp->weight << " kg";
        temp = temp->next;
    }
    
}

int sizeOfStack(){
    node *curr = head;
    int size = 0;
    while(curr != NULL){
        size++;
        curr = curr->next;
    }
    return size;
}

int main() {

    cout << "Welcome to the rice store!";
    
    while(true){
        int choice;
        cout << "\nMENU \n[1] View Rice Stack \n[2] Stock Rice Stack \n[3] Sell Rice \n[4] Exit \nInput choice: ";
        cin >> choice;
        
        if(choice == 1){
            view();
        }
        else if(choice == 2){
            if(sizeOfStack() == 10){
                cout << "Sorry, you can no longer restock!";
            }
            else{
                string rice;
                int weight;
                cout << "Input type of rice: ";
                cin >> ws;
                getline(cin, rice);
                cout << "Input weight of rice: ";
                cin >> weight;
                if(weight > 100 || weight < 10){
                    cout << "Please make sure the weight of the rice is between 10-100kg";
                }
                else{
                    addOrder(rice, weight);
                    cout << "The rice has been added!";
                }
            }
            
        }
        else if(choice == 3){
            sellRice();
            cout << "The rice has been sold!";
        }
        else if(choice == 4){
            break;
        }
        else{
            cout << "Please choose from the menu!";
        }
    }
    
}
