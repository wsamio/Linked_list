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

void Rprint(node* current){
    if(current==NULL){
        return;
    }
    printf("%d ", current->data);
    Rprint(current->next);
}

void RRprint(node* current){
    if(current==NULL){
        return;
    }
    RRprint(current->next);
    printf("%d ", current->data);
}

void Erase(int x){
    node* temp = head;
    node* temp1 = head;
    bool flg=0;
    if(head==NULL){
        puts("there's nothing in the array");
    }
    while(temp!=NULL){
        if(temp->data==x) break;
        temp1 = temp;
        temp = temp->next;
    }
    if(temp==NULL){ //if the temp crosses the boundary, the node is surely not found
        printf("number %d is not even in the array,what the hell?\n", x);
    }
    else if(temp==head){
            // if the head is the node that we want to erase we would just shift the head to the next node
            // if there's just one node the head will be empty or NULL
        if(temp->next==NULL){
            head = NULL;
        }
        else{
            head = temp->next;
        }
        free(temp);
    }
    else{
        // if the node is at the very end of the list, we are required to set the second last's next to NULL
        // means we are setting the last element to be the second last one of the list
        if(temp->next==NULL){
            temp1->next = NULL;
        }
        //if the node we are searching is at the middle of two nodes we will just link the two and the node will not be in the link list
        else{
            temp = temp->next;
            temp1->next = temp;
        }
    }
}

void Reverse(){
    node *current = head,*prev=NULL,*next;
    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void Rreverse(node *current, node *prev){
    if(current==NULL){
        head = prev;
        return;
    }
    node* next = current->next;
    current->next = prev;
    Rreverse(next,current);
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
    Rreverse(head,NULL);
    puts("enter the number of nodes you need to be removed :");
    cin >> n;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        Erase(x);
        Print();
    } 
    puts("do you want to reverse the numbers? press one or zero");
    bool flg=0; cin >> flg;
    if(flg){
        Reverse();
        //Rreverse();
        Print();
    }
   // Print();
    //RRprint(head);
    return 0;
}