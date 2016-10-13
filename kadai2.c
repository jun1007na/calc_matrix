#include <stdio.h>
#include <stdlib.h>

void MatrixMultiplication(double **, double *, double *, int, int, int);
void MatrixAddition(double **, double *, double *, int, int);
void PrintMatrix(double *, int, int);

int main(int argc, char **argv){
  double *a, *b, *ans;
  int i, j;

  //入力用配列(ビジュアル的に見やすい)
  double matrix1[] = {1, 2,
                      3, 4,
                      5, 6};

  double matrix2[] = {1, 2,
                      3, 4};

  //解答用配列
  ans = (double *)malloc(sizeof(double)*(sizeof(matrix1)/sizeof(matrix1[0])));

  //計算(積)
  //a(l,m) b(m,n)でなければならない
  MatrixMultiplication(&ans, matrix1, matrix2, 3, 2, 2);
  //計算(和)
  // MatrixAddition(&ans, matrix1, matrix2, 3, 3);

  PrintMatrix(matrix1, 3, 2); printf("\n");
  PrintMatrix(matrix2, 2, 2); printf("\n");
  PrintMatrix(ans, 3, 2);

  return 0;
}

/*******************************************************************************\
行列の和の計算
void MatrixAddition(double **ans, double *a, double *b, int l, int m)
\*******************************************************************************/
void MatrixAddition(double **ans, double *a, double *b, int l, int m){
  int i, j;
  for(i=0; i<l; i++) {
    for(j=0; j<m; j++) {
      (*ans)[i*l+j] = a[i*l+j] + b[i*l+j];
      // printf("%f + %f = %f\n", a[i*l+j], b[i*l+j], a[i*l+j]+b[i*l+j]);
    }
  }
}

/*******************************************************************************\
行列の積の計算
void MatrixMultiplication(double **ans, double *a, double *b, int l, int m, int n)
\*******************************************************************************/
void MatrixMultiplication(double **ans, double *a, double *b, int l, int m, int n){
  int i, j, k;

  for(i=0; i<l; i++) {
    for(k=0; k<n; k++) {
      (*ans)[i*n+k] = 0.0;
      for(j=0; j<m; j++) {
        (*ans)[i*n+k] += a[i*m+j] * b[j*n+k];
        // printf("(%d*%d)+%d=%d , %d : %f\n", i, m, j, i*m+j, j*n+k, (*ans)[i*m+k]);
        // printf("%d*%d+%d=%d\n", i, n, k, i*n+k);
      }
      // printf("\n");
    }
  }
}

/*******************************************************************************\
行列の表示
void PrintMatrix(double *a, int l, int m)
\*******************************************************************************/
void PrintMatrix(double *a, int l, int m){
  int i, j;

  for(i=0;i<l;i++) {
    for(j=0;j<m;j++) {
      printf("%+f ", a[i*m+j]);
    }
    printf("\n");
  }
}
