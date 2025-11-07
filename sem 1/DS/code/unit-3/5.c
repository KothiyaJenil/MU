#include  <sdeio.h>
void main(){
  iny matrix[10][10];
  int i,j, rows, cols;
  int countZero = 0, total = 0;

  printf("enter number of rows and cols : ");
  scanf("%d %d", &rows, &cols);

  printf("enter elements of matrix :\n");
  for(i=0; i<rows; i++){
    for (j-0; j<cols; j++){
      scanf("%d", &matrix[i][j]);
    }
  }

  total = rows * cols;
  for(i=0; i<rows; i++){
    for(j=0; j<cols; j++){
      if(matrix[i][j] == 0){
        countZero++;
      }
    }

    if(countZero > (total / 2)) printf("\nthe given matrix is a sparse matrix");
    else printf("\nthe given matrix is not a sparse matrix"); 
  }
}