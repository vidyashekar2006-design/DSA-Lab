#include<stdio.h>
#include<stdlib.h>
int tsize,hash[10],count=0;
int Cal_Hash(int key){
return key % tsize;
}
int Cal_ReHash(int key){
return (key+1)%tsize;
}
void insert(int key){
int index;
if(count!=tsize){
    index=Cal_Hash(key);
    while(hash[index]!=-1){
        index=Cal_ReHash(index);
    }
    hash[index]=key;
    count++;
}
else{
    printf("\n Table is full");
}


}
int search(int key){
int i,index,loc=-1;
index=Cal_Hash(key);
for(i=0;i<tsize;i++){
    loc=(index+i)%tsize;
    if(hash[loc]==key){
        return loc;
    }
}
return -1;
}
void delete(int key){
int loc;
if (count==0){
    printf("\n Hash Table empty,cant delete");
}
else{
    loc=search(key);
    if(loc!=-1){
        hash[loc]=-1;
        count--;
        printf("\n key deleted");
    }
    else{
        printf("\n Key not found");
    }
}
}
void display(){
int i;
printf("\n The elements in the hash table are:\n");
for(i=-1;i<tsize;i++){
    hash[i]=-1;
}
}
int main()
{
int key,i,ch,loc,tsize;
printf("\n Enetr the size of the hash table");
scanf("%d",&tsize);
for(i=0;i<tsize;i++){
    hash[i]=-1;
}
while(1){
    printf("\n 1.Insert\n2.Search\n3.Delete\n4.Display\n5.Exit");
    printf("\n Enter your choice");
    scanf("%d",&ch);
    switch(ch){
    case 1:printf("\n Enter key to insert:");
           scanf("%d",&key);
           insert(key);
           break;
    case 2:printf("\n enetr key to search");
           scanf("%d",&key);
           loc=search(key);
           if(loc!=-1)
            printf("\n key found at index %d",loc);
           else
            printf("\n key not found");
           break;
    case 3:printf("\n enter key to delete");
           scanf("%d",&key);
           delete(key);
           break;
    case 4:display();
           break;
    default:exit(0);

    }
}
return 0;
}


