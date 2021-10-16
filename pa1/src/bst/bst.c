#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct node{
    int num;
    struct node* left;
    struct node* right;
}node;

node* new(int num){ //creates new node
    struct node* next = (node*)malloc(sizeof(node));
    next->num=num;
    next->left=NULL;
    next->right=NULL;

    return next;
}

void freedom(node*root){   //frees the BST
    if(root->left != NULL){
        freedom(root->left);
    }
    if(root->right!=NULL){
        freedom(root->right);
    }
    free(root);
    return;
}

void print(node* root){//prints list out

    if(root == NULL){return;}//end

    printf("(");//left bracket
    print(root->left);//recurse left
    printf("%d",root->num);//print values
    print(root->right);//recurse right
    printf(")");//right bracket


}

int search(node* root, int n){//searches for int
    node* ptr = root; //pointer to use

    while (ptr!=NULL){

    if (ptr->num == n){ //if numbers match
      //  printf("present");
        return 0;
    }


    if (ptr->num > n){ //go to the left of tree
        ptr = ptr->left;
        if (ptr == NULL){
        //    printf("absent");
            return 1;
        }
      

    }//end left

    if (ptr->num < n){ //go to the left of tree
        ptr = ptr->right;
            if (ptr == NULL){
          //      printf("absent");
                return 1;
            }
      

    }//end right


    }//end whille

    return 1;
}

node* insert(node* root, int num){
    node* ptr = root; //pointer to use
    node* prev = root;//previous ptr needed in loop

    while (ptr !=NULL ){
        if (ptr->num == num){
            printf("not inserted");
            return root;
        }
        else if (ptr->num < num){ // to the right
            prev = ptr;
            ptr = ptr->right;
        }else{
            prev = ptr;
            ptr=ptr->left;
        }
    }

    ptr = new(num);
    if (prev->num > num){//go left
            prev->left = ptr;
            
        }else{//go right       (prev->num < num);
            prev->right = ptr;
        }
    printf("inserted");


/*
   
    if(ptr == NULL){//insertion
        ptr = new(num);
        printf("inserted");
        return ptr;
    } //recursive

    

    if(root->num == num){// if equal
        printf("not inserted");
        return root;
    }

    else if (root->num > num){//go left
        ptr->left = insert(ptr->left, num);
    }

    else{//go right(root->num < num)
        ptr->right = insert(ptr->left, num);
    }
     
    
    
    


    while(ptr!=NULL){ //loop t printf("absent");

        if (prev->num > num){//go left
            prev->left = ptr;
            
        }else{//go right       (prev->num < num);
            prev->right = ptr;
            
        }

        printf("inserted");
        return root;
    }
    */

    

    return root;

}

node* delete(node* root, int num){

    
    if(root==NULL){return root;}

    if (root->num > num){ //go left
        root->left = delete(root->left, num);
    }else if (root->num < num){ //go right
        root->right = delete(root->right, num);
    }else{  //actually deleting lmao
        if(root->left == NULL){//if nothing is attached on the left
            struct node* ptr = root->right;
            free(root);
            return ptr;
        }else if(root->right==NULL){ //if nothing was attached on the right instead
            struct node* ptr = root->left;
            free(root);
            return ptr;
        }else{
            node* head = root;
            node* fix = root->right;
            while(fix->left!=NULL){
                head = fix;
                fix = fix->left;
            }

            if(head !=root){
                head->left =fix->right;
            }else{
                head->right = fix->right;
            }
            root->num = fix->num;
            free(fix);
            return root;

        }
    }

    

    return root;
}









int main(int argc, char**argv){

    struct node* root=NULL;
    //struct node* ptr=NULL;
    int num;
    char instruct;
    int j;


    while(scanf(" %c %d",&instruct,&num)==2){// takes arguments
        // ||  scanf(" %c",&instruct) == 1  //tryna figure out how to take just p
    



            if (instruct == 'i'){//insert

                if (root == NULL){//if first item in list just create it
                root = new(num);
                printf("inserted\n");
                continue;
            }

                root = insert(root, num);//insert
            }

            if (instruct == 'd'){//delete

                if (root == NULL){//if first item in list
                    printf("absent");
                    continue;
                    }
                    
                 /*   root = delete(root, num);
                    printf("deleted"); */
                
                j = search(root, num);//search list
                
                if (j == 1){
                    printf("absent");
                }else{                  //if not absent delete it
                root = delete(root, num);
                printf("deleted");
                }
                
               

            }

            if (instruct == 's'){//search

                if (root == NULL){//if list is empty
                    printf("absent");
                    continue;
                }
            
                j = search(root, num); //search

                if (j == 0) {           
                    printf("present");      //if present
                }else{
                    printf("absent");       //if absent
            }

            }

            if (instruct == 'p'){//print

                if (root == NULL){//if first item in list
                continue;
            }

            print(root); //print out list
            }


       

       // ptr = root;
        //int bs = 0;

//            if(root == NULL ){ //if no list
 //               printf("\n");
 //               continue;
 //           }

 //       while (ptr!= NULL){

  //          printf(" %d",ptr->num); //print list
   //         ptr= ptr->next;
   //         bs++;
    //    }



        printf("\n");      
        }// end scan while

    if (root!= NULL){
    freedom(root);//free all allocated data
    }
    return 0;
}