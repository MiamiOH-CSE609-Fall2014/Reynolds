#include <iostream>
#include <vector>

using namespace std;

vector<int> matrix1j;
vector<int> matrix2j;

int i1,j1,i2,j2;

int main()
{
  cin >> i1;
  cin >> j1;
  cin >> i2;
  cin >> j2;

  if(j1 != i2)
    cout << "Error, Matrix Dimensions do not match" << '\n';
  
  //add to array 1
  int size1 = 0;
  do
       {
	 int entry = 0;
	 cin >> entry;
	 matrix1j.push_back(entry);
	 size1++;
       }
  while(size1 < i1*j1);

  //Add to Array 2
  int size2 = 0;
  do
    {
      int entry = 0;
      cin >> entry;
      matrix2j.push_back(entry);
      size2++;
    }
  while(size2 < i2*j2);
 
  cout << '\n';
  //Print Array1
  int count = 1;
  for(int i = 0; i < i1*j1; i++){
    cout << matrix1j.at(i) << " ";
    if(count == j1)
      { cout << '\n';
        count = 0;
      }
    count++;
  }
  
  cout << '\n';
  //Print Array 2;
  int count2 = 1;
  for(int i = 0; i < i2*j2; i++){
    cout << matrix2j.at(i) << " ";
    if(count2 == j2)
      { cout << '\n';
        count2 = 0;
      }
    count2++;
  }

  vector<int> matrixC;

   for(int i = 0; i < i1; i++)
    {
      for(int j =0; j < j2; j++)
	{
	  int entryij = 0;
	   for(int k = 0; k < i2; k++)
	     {  
	      entryij += matrix1j.at(i*j1 + k)* matrix2j.at(j + j2*k);
	     }
	  matrixC.push_back(entryij);	 
	}
    }

  cout << '\n';

  //Print Array3
  int count3 = 1;
  for(int i = 0; i < i1*j2; i++){
    cout << matrixC.at(i) << " ";
    if(count3 == j2)
      { cout << '\n';
        count3 = 0;
      }
    count3++;
  }



  return 0;
}
