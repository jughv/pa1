#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct node{
    char delim;
    struct node* point;
}node;


node* new(char delim){
    struct node* next = (node*)malloc(sizeof(node));
    next->delim=delim;
    next->point=NULL;

    return next;
}

/*
static void reverse(struct node** front){
    struct node* prev = NULL;
    struct node* current = *front;
    struct node* next = NULL;

        while(current != NULL){
            next = current->point;
            current->point=prev;
            prev = current;
            current = next;
        }
        
        *front = prev;


}
*/

static void freedom(node* ptr, node* root){
    while (ptr!=NULL){
        root = ptr;
        ptr=ptr->point;
        free(root);
        root = ptr;
    }
    free(root);
}



int main(int argc, char **argv){

    node* root = new('\0');
    node* ptr = root;

    for (int i = 0; i<strlen(argv[1]); i++){
        if (argv[1][i]  == '('){
            node* temp = new(')');
            temp->point = ptr;
            ptr = temp;
        //    printf("current node = %c\n", ptr->delim);
        }
        if (argv[1][i]  == '['){
            node* temp = new(']');
            temp->point = ptr;
            ptr = temp;
        //    printf("current node = %c\n", ptr->delim);
        }
        if (argv[1][i]  == '{'){
            node* temp = new('}');
            temp->point = ptr;
            ptr = temp;
          //  printf("current node = %c\n", ptr->delim);


        }    //end opening brackets



        if (argv[1][i]  == ')' ||
            argv[1][i]  == ']' ||
            argv[1][i]  == '}'){

                if (ptr->delim != argv[1][i]){ //early closing delim
                    printf("%d: %c\n",i, argv[1][i]);    
                    freedom(ptr,root);
                        
                    return EXIT_FAILURE;
                }
                
                root = ptr;
                ptr=ptr->point;
                free(root);
                root = ptr;
                        

        }

    
    }



    if (ptr->delim != '\0'){
       // reverse(&ptr);
        printf("open: ");
        root = ptr;
        while (ptr->delim!='\0'){
        printf("%c",ptr->delim);
        ptr=ptr->point;
        }
        ptr = root;
        freedom(ptr, root);
        return EXIT_FAILURE;
    }
    printf("\n");
    ptr = root;
    freedom(ptr, root);


    
    return 0;
}