/* linked list of integers */

#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* next;
};

node* head; // that stores the first node or we can call it root

//this Insert function will insert a value in the beginning of the linked list
void Insert(int x){
    node* temp = new(node);
    temp->data = x;
    temp->next = head; //this will save the address of head because, now head will actually be the element after the head
    head = temp; // and we are declaring a new head right after we insert a new value to list
}

void Print(){
    // we will be using a temp pointer since we don't want to overwrite or change the head
    node* temp = head;
    // since the last element points to no one and has the address NULL, we will traverse till we reach the NULL
    puts("current list :");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    puts("");
}

int main(){
    node* head = NULL; //right now the list is empty, so the head points to null
    puts("enter the number of nodes :");
    int n; scanf("%d", &n);
    for(int i=0;i<n;i++){
        int x; scanf("%d", &x);
        Insert(x);
        Print();
    }
    return 0;
}
