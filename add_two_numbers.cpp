#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};
struct node* createList(int n){
    struct node *last, *head;
    head = (struct node*)malloc(sizeof(struct node));
    cin>>head->data;
    head->next = nullptr;
    last = head;
    for(int i=0 ; i<n-1 ; i++){
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        cin>>temp->data;
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
    return head;
}
struct node* Sum(struct node *l1, struct node *l2){
    struct node *p, *q, *sum, *last, *r;
    p = l1;
    q = l2;
    sum = (struct node*)malloc(sizeof(struct node));
    sum->data = p->data + q->data;
    sum->next = nullptr;
    p = p->next;
    q = q->next;
    last = sum;
    while(p && q){
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp->data = p->data + q->data;
        p = p->next;
        q = q->next;
        temp->next = nullptr;
        last->next = temp;
        last = temp;
    }
    if(p)last->next = p;
    else if(q)last->next = q;
    r = sum;
    while(r->next){
                if(r->data > 9){
                r->next->data += (r->data)/10;
                r->data = r->data % 10;
            }
            r = r->next;
        }
        if(r->data > 9){
            struct node *temp = (struct node*)malloc(sizeof(struct node));
            temp->data = r->data / 10;
            r->data = r->data % 10;
            temp->next = nullptr;
            r->next = temp;
        }
    return sum;
}
struct node* addNum(struct node *l1, struct node *l2){
    struct node *p, *q;
    int n1, n2;
    p = l1;
    while(p){
        n1++;
        p = p->next;
    }
    p = l2;
    while(p){
        n2++;
        p = p->next;
    }
    if(n1>n2){
        p = l2;
        q = l1;
        while(p){
            q->data += p->data;
            q = q->next;
            p = p->next;
        }
        p = l1;
        while(p->next){
                if(p->data > 9){
                p->next->data += (p->data)/10;
                p->data = p->data % 10;
            }
            p = p->next;
        }
        if(p->data > 9){
            struct node *temp = (struct node*)malloc(sizeof(struct node));
            temp->data = p->data / 10;
            p->data = p->data % 10;
            temp->next = nullptr;
            p->next = temp;
        }
        return l1;
    }
    else{
        p = l1;
        q = l2;
        while(p){
            q->data += p->data;
            q = q->next;
            p = p->next;
        }
        p = l2;
        while(p->next){
                if(p->data > 9){
                p->next->data += (p->data)/10;
                p->data = p->data % 10;
            }
            p = p->next;
        }
        if(p->data > 9){
            struct node *temp = (struct node*)malloc(sizeof(struct node));
            temp->data = p->data / 10;
            p->data = p->data % 10;
            temp->next = nullptr;
            p->next = temp;
        }
        return l2;
    }
}

int main(){
    struct node *l1, *l2, *sum;
    int n, m;
    cout<<"Enter number of elements List :\n";
    cin>>n>>m;
    cout<<"Enter First List :\n";
    l1 = createList(n);
    cout<<"Enter Second List :\n";
    l2 = createList(m);
    cout<<"The Sum is :\n";
    sum = Sum(l1,l2);
    while(sum){
        cout<<sum->data<<" ";
        sum = sum->next;
    }
    cout<<endl;
    return 0;
}