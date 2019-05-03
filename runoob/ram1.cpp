#include<iostream>
using namespace std;

// char* pvalue =  NULL;
// pvalue = new char[20];
// delete [] pvalue;

// int *array = new int[m];
// delete [] array;

// int **array

// array = new int *[m];

// for(int i = 0; i<m;i++)
// {
//   array[i] = new int[n];
// }

// for(int i = 0; i<m;i++)
// {
//   delete [] array[i];
// }

// delete [] array;

int main()
{
  int **p;
  int i,j;
  p = new int *[4];
  for( i = 0;i<4;i++){
      p[i] = new int [8];
  }
  for(i = 0;i < 4;i++){
      for(j = 0;j < 8;j++){
        p[i][j] = j * i;
      }
  }
  for(i=0;i< 4;i++){
      for(j=0; j < 8;j++)
      {
        if(j==0)cout<<endl;
        cout << p[i][j] << "\t";
      }
  }
  for(i=0;i<4;i++){
    delete [] p[i];
  }
  delete [] p;
  return 0;
}