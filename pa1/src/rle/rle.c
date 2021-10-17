#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


typedef struct node{
    char letter;
    int count;
    struct node* point;
}node;

node* new(char letter, int count){
    struct node* next = (node*)malloc(sizeof(node));
    next->letter=letter;
    next->count=count;
    next->point=NULL;

    return next;
}


int main(int argc, char **argv){

    if(argv[1][0] == '\0'){
        printf("\n");
    }

 
    int newlen = 0; //new string length   
    int oldlen = strlen(argv[1]);
    int count = 1;
  //  int where = 0;

  //  printf("old:%d, new:%d\n", oldlen, newlen);

    for (int i=0; argv[1][i] != '\0';i++){
       // count +=1;
       if (argv[1][i] == '0'){printf("error\n");return 0;}
       if (argv[1][i] == '1'){printf("error\n");return 0;}
       if (argv[1][i] == '2'){printf("error\n");return 0;}
       if (argv[1][i] == '3'){printf("error\n");return 0;}
       if (argv[1][i] == '4'){printf("error\n");return 0;}
       if (argv[1][i] == '5'){printf("error\n");return 0;}
       if (argv[1][i] == '6'){printf("error\n");return 0;}
       if (argv[1][i] == '7'){printf("error\n");return 0;}
       if (argv[1][i] == '8'){printf("error\n");return 0;}
       if (argv[1][i] == '9'){printf("error\n");return 0;}
                        
        if (argv[1][i] == argv[1][i-1]){
            
        }
        if (argv[1][i] != argv[1][i-1]){
            newlen+=2;
        }
        
    }
 //   printf("old:%d, new:%d\n", oldlen, newlen);// show lengths

   if(oldlen < newlen){ //if oldlength will be shorter
        printf("%s\n", argv[1]);
        printf("%d : %d\n", oldlen, newlen);
        return 0;
    }

    
  
    node* root = new(argv[1][0],0);
    node* ptr = root;


   // char *pressed;    
    //pressed = (char*)malloc(sizeof(char)* newlen);
    //char num[];    
    
    int last=0;


    for (int i=1; argv[1][i] != '\0';i++){
       if (argv[1][i] == argv[1][i-1]){
            count++;
        }
        if (argv[1][i] != argv[1][i-1]){
            ptr->letter = argv[1][i-1];
            ptr->count = count;
            node* next=new(argv[1][i],count);
            ptr->point=next;
            ptr=ptr->point;
            count = 1;
        }
        

        last=i;

    }
    ptr->letter = argv[1][last];
            ptr->count = count;
            

    
    ptr=root;
    while (ptr!=NULL){
        printf("%c%d",ptr->letter,ptr->count);
        ptr=ptr->point;
        free(root);
        root = ptr;
    }

    
    printf("\n");
    //free(pressed);

    return 0;

}




