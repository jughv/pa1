#include<stdio.h>
#include<stdlib.h>
#include<curses.h>
#include<string.h>

void matmulti(int **mat1, int **mat2, int **res, int mat1col, int mat1row, int mat2col){
    int temp = 0;

    for (int i = 0; i < mat1row; i++){
        for(int k = 0; k < mat2col; k++){
            for (int j = 0; j < mat1col; j++){
                temp += mat1[i][j] * mat2[j][k];
            }
            res[i][k] = temp;
            temp = 0;
            
        }
    }
}

void printmat(int **mat, int matrow, int matcol){
    for (int a = 0; a < matrow; a++){
        for (int b = 0; b < matcol; b++){
            printf("%d", mat[a][b]);
            if (b+1 == matcol){
                continue;
            }
            printf(" ");
        }
        if (a+1 == matrow){
            continue;
        }
        printf("\n");
    } 
}

int main(int argc, char** argv){
    
    
    if (argc < 2) {
		printf("error\n");
		return 0;
	} 


    FILE *fp = fopen(argv[1], "r");
    int length;


    fscanf(fp,"%d\n", &length);


    
    int **mat1 = (int **) malloc(length*length*1000*sizeof(int));
    int **mat2 = (int **) malloc(length*length*1000*sizeof(int));
    for (int x = 0; x < length; x++){
        mat1[x] = (int*) malloc(length*sizeof(int));
        mat2[x] = (int*) malloc(length*sizeof(int));
    }

    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){
            fscanf(fp,"%d", &mat1[i][j]);
            mat2[i][j] = mat1[i][j];
        }
        fscanf(fp,"\n");
    }






    int **res = (int **) malloc(length*length*1000*sizeof(int));
    for (int c = 0; c < length; c++){
        res[c] = (int *) malloc(length*sizeof(int));
    }
 
   int exp;
   int b = 0;

    fscanf(fp,"%d\n", &exp); //last number
    while (b < exp-1){
        matmulti(mat1, mat2, res, length, length, length);

        for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){ 
            mat1[i][j] = res[i][j];
        }
        }

    b++;
    }    


    printmat(res, length, length);
    for (int d = 0; d < length; d++){
        free(mat1[d]);

    }

    free(mat1);
    for (int e = 0; e < length; e++){
        free(mat2[e]);
    }
    free(mat2);
     for (int d = 0; d < length; d++){

        free(res[d]);
    }
    free(res);

    return 0;
}