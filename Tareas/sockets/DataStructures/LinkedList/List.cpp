#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;
int length = 0;

void add(int value){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (length = 0) {
        newNode->data = value;
        newNode->next = NULL;
        head = newNode;

    }else{
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        length = length + 1;

    }
}
void deleteNode(){

    if(length == 0){
        return;
    }
    else{
        head = head->next;
        length = length - 1;
    }
}
//The position in the list is assumed stars by 0
void edit(int position, int value){
    Node* ptr = head;
    for (int i = 0; i < position; i++){
            ptr = ptr->next;
    }
    ptr->data = value;

}
int getV_position(int position){
    Node* ptr = head;
    for(int i = 0; i<position; i++){
        ptr = ptr->next;
    }
    std::cout<<"El valor del nodo en posición "<<position<<" es:"<<ptr->data<<"\n";
    return ptr->data;

}
void print(){
    struct Node *node = head;
    while(node != NULL){
        std::cout<< node->data <<", ";
        node = node->next;
    }
    std::cout<<"\n";

}

int main(){
    add(3);
    add(4);
    print();
    edit(0,2);
    print();
    getV_position(1);
    deleteNode();
    print();


}

