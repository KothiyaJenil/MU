#include<stdio.h>
int main(){
    int i,j,rows, cols, a[10][10], b[10][10], multi[10][10];
    printf("enter number of row and cols\n");
    scanf("%d%d", &rows, &cols);

    printf("enter elements of first matrix: \n");
    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
        printf("a[%d][%d] = ", i,j);
        scanf("%d", &a[i][j]);
        }
    }
    printf("enter elements of second matrix: \n");
    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
        printf("a[%d][%d] = ", i,j);
        scanf("%d", &b[i][j]);
        }
    }
    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
        multi[i][j]=a[i][j]*b[i][j];
        }
    }
    printf("multi of the matrix is : \n");
    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
        printf("%d \t", multi[i][j]);
        }
        printf("\n");
    }
}

