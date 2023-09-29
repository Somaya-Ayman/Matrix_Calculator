#include <iostream>
#include <math.h>
using namespace std;
long long determinant;
long long determinant_calculator (int n_matrix, long long matrix[10][10]){
determinant = 0;
long long sub_matrix[10][10];
if (n_matrix==1){
determinant = matrix[0][0];
return determinant;
}
else if (n_matrix==2){
determinant = (matrix[0][0]*matrix[1][1])-(matrix[1][0]*matrix[0][1]);
return determinant;
}
// base cases of recursive function
else {
        //int sign=1;
    for (int k = 0; k < n_matrix; k++) {
            int index_rows_sub = 0;
            for (int i = 1; i < n_matrix; i++) {
                 int index_colm_sub = 0;
                 for (int j = 0; j < n_matrix; j++) {
                    if (j == k)
                     continue;
                      sub_matrix[index_rows_sub][index_colm_sub] = matrix[i][j];
                      index_colm_sub++;
                      }
                index_rows_sub++;
               }
            determinant = determinant + (pow(-1, k) * matrix[0][k] * determinant_calculator(  n_matrix - 1,sub_matrix ));
           }
   }
return determinant;
}

int main()

{
    int n_rows_A , n_colm_A , n_rows_B , n_colm_B,operation ;
    long long x ,y, matrix_A [10][10] , matrix_B [10][10];
    cout << "Please enter dimensions of Matrix A:" << endl;
    cin>> n_rows_A>>n_colm_A;
    cout << "Please enter dimensions of Matrix B:" << endl;
    cin>> n_rows_B>>n_colm_B;
    cout << "Please enter values of Matrix A:" << endl;
    for (int r=0; r<n_rows_A; r++){
        for (int c=0; c<n_colm_A; c++){
            cin>>x;
            matrix_A[r][c]=x;
        }
    }
      /* for (int r=0; r<3; r++){
        for (int c=0; c<3; c++){
            cout << matrix_A[r][c];
        }
    } */
    cout << "Please enter values of Matrix B:" << endl;
      for (int r=0; r<n_rows_B; r++){
        for (int c=0; c<n_colm_B; c++){
            cin>>y;
            matrix_B[r][c]=y;
        }
    }
    do{
    cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):" << endl;
    cin>>operation;
    switch (operation){
case 1:{
    long long sum[10][10];
     if ((n_rows_A==n_rows_B)&&(n_colm_A==n_colm_B)){
    for (int r=0; r<n_rows_A; r++){
    for (int c=0; c<n_colm_A; c++){
            sum[r][c]=matrix_A[r][c]+matrix_B[r][c];
                if (sum[r][c]>=0){
                 cout<<int(sum[r][c]+0.5)<<" ";}
        else if(sum[r][c]<0){ cout<<int(sum[r][c]-0.5)<<" ";}
        }
          cout<<endl;
    }

}
    else {cout<<"The operation you chose is invalid for the given matrices."<<endl;}
}    break;
case 2:{
     float diff[10][10];
      if ((n_rows_A==n_rows_B)&&(n_colm_A==n_colm_B)){
    for (int r=0; r<n_rows_A; r++){
        for (int c=0; c<n_rows_B; c++){
            diff[r][c]=matrix_A[r][c]-matrix_B[r][c];
              if (diff[r][c]>=0){
                 cout<<int(diff[r][c]+0.5)<<" ";}
    else if (diff[r][c]<0){ cout<<int(diff[r][c]-0.5)<<" ";}
            }
      cout<<endl;
}
      }
else {cout<<"The operation you chose is invalid for the given matrices."<<endl;}
}    break;
case 3:
      {float multiply[10][10];
        for (int r=0; r<10; r++){
        for (int c=0; c<10; c++){
           multiply[r][c]=0;
           }
        }
 if (n_colm_A==n_rows_B){
    for (int r=0; r<n_rows_A; r++){//number of rows in a should be equal no of columns in b??
        for (int c=0; c<n_colm_B; c++){
                for (int m=0;m<n_colm_A;m++){
                multiply[r][c]+=matrix_A[r][m]*matrix_B[m][c];
                }
                 if (multiply[r][c]>=0){
                  cout<<int(multiply[r][c]+0.5)<<" ";}
              else if (multiply[r][c]<0){ cout<<int(multiply[r][c]-0.5)<<" ";}
    }
      cout<<endl;
    }

}
else {cout<<"The operation you chose is invalid for the given matrices."<<endl;}
}    break;
case 4:
      {
  long long dete = determinant_calculator(n_colm_B, matrix_B);
    float inverse_B[3][3];
    if (dete!=0 && (n_rows_A==3) && (n_rows_B == 3) && (n_colm_A == 3) && (n_colm_B == 3)){
      inverse_B[0][0]= (matrix_B[1][1]*matrix_B[2][2]-matrix_B[1][2]*matrix_B[2][1])/double(dete);
      inverse_B[0][1]= - (matrix_B[0][1]*matrix_B[2][2]-matrix_B[0][2]*matrix_B[2][1])/double(dete);
      inverse_B[0][2]= (matrix_B[0][1]*matrix_B[1][2]-matrix_B[0][2]*matrix_B[1][1])/double(dete);
      inverse_B[1][0]= - (matrix_B[1][0]*matrix_B[2][2]-matrix_B[1][2]*matrix_B[2][0])/double(dete);
      inverse_B[1][1]= (matrix_B[0][0]*matrix_B[2][2]-matrix_B[0][2]*matrix_B[2][0])/double(dete);
      inverse_B[1][2]= - (matrix_B[0][0]*matrix_B[1][2]-matrix_B[0][2]*matrix_B[1][0])/double(dete);
      inverse_B[2][0]= (matrix_B[1][0]*matrix_B[2][1]-matrix_B[1][1]*matrix_B[2][0])/double(dete);
      inverse_B[2][1]= - (matrix_B[0][0]*matrix_B[2][1]-matrix_B[0][1]*matrix_B[2][0])/double(dete);
      inverse_B[2][2]= (matrix_B[1][1]*matrix_B[0][0]-matrix_B[1][0]*matrix_B[0][1])/double(dete);


       float multiply_inverse[10][10];
        for (int r=0; r<10; r++){
        for (int c=0; c<10; c++){
           multiply_inverse[r][c]=0;
           }
        }
 if (n_colm_A==n_rows_B){
    for (int r=0; r<n_rows_A; r++){//number of rows in a should be equal no of columns in b??
        for (int c=0; c<n_colm_B; c++){
                for (int m=0;m<n_colm_A;m++){
                multiply_inverse[r][c]+=matrix_A[r][m]*inverse_B[m][c];
                }
              if (multiply_inverse[r][c]>=0){
                  cout<<int(multiply_inverse[r][c]+0.5)<<" ";}
              else if (multiply_inverse[r][c]<0){ cout<<int(multiply_inverse[r][c]-0.5)<<" ";}
    }
      cout<<endl;
}
}
    }
    else {cout<<"The operation you chose is invalid for the given matrices."<<endl;}
}    break;
case 5:
 {if (n_colm_A == n_rows_A)
         { long long det_A = determinant_calculator(n_colm_A, matrix_A);
           cout << det_A <<endl;
           }
    else {cout<<"The operation you chose is invalid for the given matrices."<<endl;}
}break;
case 6:
  {if (n_colm_B == n_rows_B)
           {long long det_B = determinant_calculator(n_colm_B, matrix_B);
           cout <<det_B<<endl;
           }
   else {cout<<"The operation you chose is invalid for the given matrices."<<endl;}
}break;
case 7:
break;
default:
  {cout << "The operation you chose is invalid for the given matrices." << endl;
  }
    }
}while (operation<7);
cout << "Thank you!" << endl;

return 0;
}
