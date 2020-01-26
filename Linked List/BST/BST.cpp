#include<bits/stdc++.h>

using namespace std;

// similar to linked list but we are adding and extra storage of address, since a node is holding a left and a right node
struct node{
    int data;
    node* right;
    node* left;
};

node* head; // head or what we call root, this needs to be unchanged because this is the only access to the tree

void Insert(int x){
    // for every element we are creating a new node, because we are just going to link this to a particular position
    node* temp = new node();
    temp->data = x;
    temp->right = NULL;
    temp->left = NULL;
    node* temp1 = head;
    if(head!=NULL){
        while(temp1!=NULL){

            if(x<=temp1->data){
                if(temp1->left==NULL){
                    temp1->left = temp;
                    break;
                }
                // since values that are less or equal to the inserting value it will move to its left
                temp1 = temp1->left;
            }

            else{
                if(temp1->right==NULL){
                    temp1->right = temp;
                    break;
                }
                //else the value is bigger than the pointer point to so we will move to its right
                temp1 = temp1->right;
            }
        }
    }
    else{
        head = temp;
    }
}

void Search(int x){
    node* temp = new node();
    temp = head;
    bool flg = 0;
    while(temp!=NULL){
        if(temp->data==x) { flg=1; break; }
        else if(x<temp->data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    if(temp==NULL || flg==0){
        puts("there's no such an element");
    }
    else{
        puts("found");
    }
}

int main(){
    head = NULL;
    puts("enter the number of nodes :");
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        Insert(x);
    }
    puts("enter the number of element of element you want to search :");
    for(int i=0;i<n;i++){
        int x; cin >> x;
        Search(x);
    }
}
