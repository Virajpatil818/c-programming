#include <stdio.h>

void main(){
    int r=3,c=3 ;
    int i,j,k,choice;
    int mat1[r][c],mat2[r][c];
    int add[r][c],mul[r][c];
    int *m1,*m2,*a1,*mu;

    m1=&mat1[0][0];
    m2=&mat2[0][0];
    a1=&add[0][0];
    mu=&mul[0][0];
    
    printf("Enter Matrix 1\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf(" %d",&mat1[i][j]);
        }
    }

    printf("Enter Matrix 2\n");
     for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf(" %d",&mat2[i][j]);
        }
    }
    
    do
    {
       printf("\n1.Matrix Addition\n2.Matrix Multiplication\n3.Matrix Transpose\n");
       scanf(" %d",&choice);

       switch (choice)
       {
       case 1:
         printf("Addition of Matrix 1 and Matrix 2 :");
         printf("\n");
          for(int i=0;i<r;i++){
              for(int j=0;j<c;j++){
                *(a1+((i*3)+j))=*(m1+((i*r)+j))+*(m2+((i*r)+j));
                 printf("%d\t",*(a1+((i*3)+j)));
              }
              printf("\n");
            }
        break;
       
       case 2:
        printf("Multiplication of Matrix 1 and Matrix 2 :\n");
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                mul[i][j]=0;
                for(int k=0;k<3;k++){
                mul[i][j] += *(m1+((i*3)+k)) * *(m1+((k*3)+j)); 
                }
            }
        }

      for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
            printf(" %d",mul[i][j]);
            }
          printf("\n");
            }
            break;
       case 3:
          printf("\n");
          printf("Transpose Of Matrix 1 is :\n");
          for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                printf(" %d",*(m1+((j*3)+i)));
            }
            printf("\n");
          }
         break;
       default:
        break;
       }
    } while (choice!=0);
    
}