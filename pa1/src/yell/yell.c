#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char **argv){


    for (int i =1;i < argc;i++){ //each word
       
    //int len = strlen(argv[i]);
    //len +=1;       
    char str[strlen(argv[i])+1];
    strcpy(str, argv[i]); //copy word

        for(int j=0; str[j]!='\0';j++){ // each character
            str[j] = toupper(str[j]);
        }

            printf("%s ", str);

           

    }

    if(isspace(argv[1][0]) ==  1){
     printf("\b!!\n");}

   if(argv[1] != NULL){
     printf("\b!!\n");}

    // if(argv[1][0]==' '){  tryna figure out how to recognize spaces
    // printf("\b!!\n");}

    return 0;
}