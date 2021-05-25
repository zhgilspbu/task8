#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <iostream>



typedef struct list {

int id;
int key;
list* next;

} list;


void push (list *&head, int num,int key ){

if (!head){
    head =new list;
    head->id=num;
    head->key=key;
    head->next=NULL;
}else{
list* ptr=head;
list* tmp=new list;
tmp->id=num;
tmp->next=NULL;
tmp->key=key;
while(ptr->next){
    ptr=ptr->next;
}
ptr->next=tmp;

}
}


void rem(list *&head,int num){
        list *ptr=head;
if (head->id == num){

    head=head->next;
    delete(ptr);
}else{
while (ptr->next->id!=num){
    ptr=ptr->next;
}

list* tmp=ptr->next;
ptr->next=ptr->next->next;
delete(tmp);
}

}


int maximum(list *head){
    int ans_v, ans_k;
    if (head){
         ans_k=head->key;
         ans_v=head->id;
        head=head->next;
        while (head){
            if (head->key>ans_k){
                ans_k=head->key;
                ans_v=head->id;
            }
            head=head->next;
        }
        return ans_v;
    }
return 0;
}

void printl(list *head){

while (head){
    std::cout<<head->id<<" ";
    head=head->next;
}
}
#endif // LIST_H_INCLUDED
