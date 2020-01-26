#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* next;
};

node* head; // that stores the first node or what we call root

//this Insert function will insert a value at the end of the linked list
void Insert(int x){
    node* temp = new node();
    temp->data = x;
    temp->next = NULL; // each node we will push will insert at the end, so it will points to actually nothing
    if(head!=NULL){
        node *temp1 = head; // we are creating another pointer so we can traverse all the nodes of the list
        while(temp1->next!=NULL){
            temp1 = temp1->next; // we will move forward by pointing to next node and then to the next and so on and so forth
        }
        temp1->next = temp; //when we will reach at the NUll pointer we are actually reaching second last node of the list
        // so we basically going to link that to the last one
    }
    else{
        head = temp;
    }
}

void Print(){
    // we will be using a temp pointer since we don't want to overwrite or change the head, while we are traversing the list
    node* temp = head;
    puts("Current list :");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    puts("");
}

int main(){
    head = NULL; //right now the list is empty, so the head points to null
    puts("enter the number of nodes :");
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        Insert(x);
        Print();
    }
    return 0;
}
