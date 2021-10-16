#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char **argv){

    if (argc == 2 && isspace(argv[1][0]) ==  1)
    {
        return 0;
    }
    
    if (argc < 2){//if empty
        printf("empty");
        return 0;
    }


    for (int i =1;i < argc;i++){ //each word
       
    //int len = strlen(argv[i]);
    //len +=1;       
   // char str[100];
   // strcpy(str, argv[i]); //copy word

        for(int j=0; argv[i][j] !='\0';j++){ // each character
            argv[i][j] = toupper(argv[i][j]);
            printf("%c", argv[i][j]);
        }

            if(i<argc-1){printf(" ");}

           

    }

    if(isspace(argv[1][0]) ==  1){printf("!!\n");}

    if(argv[1] != NULL){
     printf("!!\n");}

    //printf("%s\n",argv[0]);

    

    // if(argv[1][0]==' '){  tryna figure out how to recognize spaces
    // printf("\b!!\n");}

    return 0;
}