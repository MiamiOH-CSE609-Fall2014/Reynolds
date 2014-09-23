#include <iostream>
#include <vector>

using namespace std;

vector<int> matrix1i;
vector<int> matrix1j;
vector<int> matrix2i;
vector<int> matrix2j;

int i1,j1,i2,j2;

int main()
{
  cin >> i1;
  cin >> j1;
  cin >> i2;
  cin >> j2;

   
  for(int i = 1; i <= i1; i++){
    matrix1i.push_back(i);
  }
  for(int i = 1; i <= i2; i++){
    matrix2i.push_back(i);
  }
  
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

  for( int i = 0; i < i1; i++)
    {
      for(int j =0; j < j2; j++)
	{
	  int entryij = 0;
	  for(int k = 0; k < i1; k++)
	    {
	      int one = matrix1j.at(i*j1 + k);
	      cout << "One " << one;
	      int two = matrix2j.at(j + j2*k);
	      int total = one * two;
	      cout << " Two " << two << " Total " << total << '\n';
	      entryij += matrix1j.at(i*j1 + k)* matrix2j.at(j + j2*k);
	    }
	  matrixC.push_back(entryij);
	}
    }

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
