#include<stdio.h>

void SpraseMatrixRepresentation(int mat[][],int row, int col)
{
          int i,j,k=1;
          
          for(i=0;i<row;i++)
          {
                    for(j=0;j<col;j++)
                    {
                              if(mat[i][j]!=0)
                              {
                                        sp[k][0]=i;
                                        sp[k][1]=j;
                                        sp[k][2]=mat[i][j];
                                        k++;
                              }
                    }
          }
          int sp[][];
          
          sp[0][0]=row;
          sp[0][1]=col;
          sp[0][2]=k-1;
          
}

void SparseAddition(sp1[][],sp2[][])
{
          int i = 1, j = 1,k = 1;
          int row1 = sp1[0][0];
          int col1 = sp1[0][1];
          int count1 = sp1[0][2];
          int row2 = sp2[0][0];
          int col2 = sp2[0][1]; 
          int count2 = sp2[0][2];
          
          if((row1 == row2)&&(col1 == col2))
          {
                    while(i <= count1 && j <= count2)
                    {
                              if(sp1[i][0] == sp2[j][0])
                              {
                                        if(sp1[i][1] == sp2[j][1])
                                        {
                                                  sum = sp1[i][2]+sp2[j][2];
                                                  if ( sum != 0)
                                                  {
                                                  sp3[k][0] = sp1[i][0];
                                                  sp3[k][1] = sp1[i][1];
                                                  sp3[k][2] = sum;
                                                  k++;
                                                  }
                                        }          
                                        else
                                        {
                                                  if(sp1[i][1] < sp2[j][1])
                                                  {
                                                            sp3[k][0] = sp1[i][0];
                                                            sp3[k][1] = sp1[i][1];
                                                            sp3[k][2] = sp1[i][2];
                                                            i++;
                                                            k++;
                                                  }
                                                  else
                                                  {
                                                            sp3[k][0] = sp1[j][0];
                                                            sp3[k][1] = sp1[j][1];
                                                            sp3[k][2] = sp1[j][2];
                                                            j++;
                                                            k++;      
                                                  }
                                        }                                                                    
                              }
                              else
                              {
                                        if(sp1[i][0] < sp2[j][0])
                                        {
                                                  sp3[k][0] = sp1[i][0];
                                                  sp3[k][1] = sp1[i][1];
                                                  sp3[k][2] = sp1[i][2];
                                                  i++;
                                                  k++;
                                        }            
                                        else
                                        {
                                                  while(j <= count2)
                                                  {
                                                            sp3[k][0] = sp1[j][0];
                                                            sp3[k][1] = sp1[j][1];
                                                            sp3[k][2] = sp1[j][2];
                                                            j++;
                                                            k++;
                                                  }
                                        }   
                                        sp3[0][0] = sp1[0][0];
                                        sp3[0][1] = sp1[0][1];
                                        sp3[0][2] = k-1;                        
                              }
                    }
          }
          else
                    printf("Matrices are not of same order and cannot be added.\n");
}

void SparseTranspose(int sp1[][3])
{
          int i,j,k=1,tr[10][3];
          
          for(i=0;i<sp1[0][1];i++)
          {
                    for(j=0;j<sp1[0][2];j++)
                    {
                              if(sp1[j][1] == 1)
                              {
                                        tr[k][0] = sp1[j][1];
                                        tr[k][1] = sp1[j][0];
                                        tr[k][2] = sp1[j][2];
                                        k++;
                              }    
                    }
          }
          tr[0][0] = sp1[0][1];
          tr[0][1] = sp1[0][0];
          tr[0][2] = sp1[0][2];
}

int main()
{
	int x[20][20];
	int r,c,j,i;
 	printf("\nEnter the no:of rows and columns");
 	scanf("%d",&r);
 	scanf("%d",&c);
 	printf("\nEnter the element: ");
 	for(i=0;i<r;i++)
 	{
 		for(j=0;j<c;j++)
 		{
 			
 			scanf("%d",&x[i][j]);
 		}
 	}
 	printf("the matrixs is :\n");
 	for(i=0;i<r;i++)
 	{
 		for(j=0;j<c;j++)
 		{
 			printf("%d\t",x[i][j]);
 			
 		}
 		printf("\n");
 	}
}
