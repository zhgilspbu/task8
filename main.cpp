#include <iostream>
#include<cstdlib>
#include "tree.h"
#include "list.h"
const int NUMBER_OF_FIRST_NODES=7;


using namespace std;

int main()
{

    unsigned seed=50;
srand(seed);
tree* root=NULL;

list* head=NULL;

for (int i=0;i<NUMBER_OF_FIRST_NODES;i++){
    int num=rand()%100;
    int key=rand()%3-1;
    add(root,num,key,0,head);
}
while(1){
cout<<"vvedite 1 dlya dobavleniya 2 dlya udaleniya 3 dlya vivoda 4dlya individual'nogo zadaniya \n";
int req,num,key;
cin>>req;
if (req==1){
    cout<<"vvedite element i ego klyuch dlya dobavleniya\n";
    cin>>num>>key;
    add(root,num,key,0,head);
}
else if(req==2){
    cout<<"vvedite element dlya udaleniya\n";
    cin>>num;
    pop(root,num);

}
else if (req==3){
    show(root,0);
    cout<<"\n";
}
else if (req==4){
        int t=maximum(head);
    print_path(root,t);
cout<<"\n";
}
else if (req==5){
    printl(head);
    cout<<"\n";
}
else if(req ==6 ){
    cout<<maximum(head);
    cout<<"\n";
}
else if(req==0){
    return 0;
}

}
    return 0;
}
