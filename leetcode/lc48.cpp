// 47. rotate a 2d array

// lessons learned

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) 
	{
		if(matrix.size()<2)
			return;
		
		int br=0;
		int er=matrix.size()-1;
		int bc=0;
		int ec=matrix.size()-1;

		while(bc<ec)
		{
			int cnt=ec-bc;
			for(int i=0; i<cnt; i++)
			{
				int t=matrix[br][bc+i];
				matrix[br][bc+i]=matrix[er-i][bc];
				matrix[er-i][bc]=matrix[er][ec-i];
				matrix[er][ec-i]=matrix[br+i][ec];
				matrix[br+i][ec]=t;
			}
			br++; er--;
			bc++; ec--;
		}
    }
};


int main()
{
	int matrix_size=5;
	Solution sol;
	vector<vector<int> > matrix(matrix_size, vector<int>(matrix_size));

	for(int i=0; i<matrix_size; i++)
		for(int j=0; j<matrix_size; j++)
			matrix[i][j]=i*matrix_size+j;

	cout << "Before rotation:" << endl;
	for( int i=0; i<matrix_size; i++ )
	{
		for(int j=0; j<matrix_size; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	sol.rotate(matrix);
	cout << "After rotation:" << endl;
	for( int i=0; i<matrix_size; i++ )
	{
		for(int j=0; j<matrix_size; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	
	
	return 0;
}

