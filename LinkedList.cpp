#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node *next;
};

void linkedlisttraverse(struct Node *ptr){
    while(ptr != NULL){
        cout<<"Element :"<<ptr->data;
    }
}
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    
    head = (struct Node*) malloc (sizeof(struct Node));
    second = (struct Node*) malloc (sizeof(struct Node));
    third = (struct Node*) malloc (sizeof(struct Node));
    
    head -> data = 7;
    head -> next = second;
    
    second -> data = 11;
    second -> next = third;
    
    third -> data = 66;
    third -> next = NULL;
    
    linkedlisttraverse(head); 
    return 0;
    
}