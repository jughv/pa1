#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct node{
    int num;
    struct node* next;
}node;

node* new(int num){ //creates new node
    struct node* next = (node*)malloc(sizeof(node));
    next->num=num;
    next->next=NULL;

    return next;
}

int counter(node* ptr){
    int count=0;
    while (ptr!=NULL){
        count++;
        ptr=ptr->next;
    }
    return count;
}

node* insert(struct node* ptr, int num){ // insert to program

    if (ptr->num == num){return ptr;}//if equal to the first item in the list

    //struct node* in = (node*)malloc(sizeof(node)); //node to be inserted
    
    if (ptr->num >num){ //inserted to first item
        struct node* in = (node*)malloc(sizeof(node)); //node to be inserted
        in->num = num;
        in->next= ptr;
        return in;
    }

    struct node* before = ptr; //prev value
    struct node* root = ptr;//beginning of list
    
    ptr = ptr->next;

    while (ptr!=NULL){ // runs through list
    if(ptr->num == num){//if already in list
        return root;
    }

    if (ptr->num > num){//if it should go in this spot in the list
        struct node* in = (node*)malloc(sizeof(node)); //node to be inserted
        in->num = num;
        in->next= ptr;
        before->next = in;
        return root;
    }

    before = ptr;
    ptr=ptr->next;

    }//end while

    struct node* in = (node*)malloc(sizeof(node)); //node to be inserted at end of list
    in->num= num;
    before->next = in; //issue occurs here
    return root;
}


node* delete(struct node* ptr, int num){

    struct node* before = ptr; //prev value
    struct node* root = ptr;//beginning of list

    if(ptr->num == num){ //if first item matches
        root = ptr->next;
        free(ptr);
        return root;
    }

    ptr = ptr->next;

    while(ptr!=NULL){//through list

    if (ptr->num == num){ // if values match
        before->next = ptr->next;
        free(ptr);
        return root;
    }

    before = ptr;
    ptr=ptr->next;

    }

    return root; //nothing matched


}

int main(int argc, char**argv){

    struct node* root=NULL;
    struct node* ptr=NULL;
    int num, count;
    char instruct;

  //  while (instruct != 'q'){

        //scanf(" %c %d",&instruct,&num);
        //fgets("%c %d",&instruct,&num);

    while(scanf("%c %d\n",&instruct,&num) !='\0'){
    

        printf("char = %c  num = %d\n",instruct, num);

            if (instruct == 'i'){

                if (root == NULL){//if first item in list
                root = new(num);
            }

                root = insert(root, num);
            }

            if (instruct == 'd'){

                if (root == NULL){//if first item in list
                    root = new(num);
                    }

                root = delete(root, num);
            }


        count = counter(root);
        printf("%d : ",count);
        ptr = root;
        int bs = 0;
        while (ptr!= NULL){
            printf("%d",ptr->num);
            ptr= ptr->next;
            //bs++;
            //if(bs != count){
                printf(" ");
            //}
            //if(bs == count){
            //    printf("\n");
            //}
            bs++;
        }
        printf("\n");





        }

      ptr = root; 
      while (ptr!=NULL){ // free allocated data
          ptr=ptr->next;
          free(root);
          root = ptr;
      }


    return 0;
}
