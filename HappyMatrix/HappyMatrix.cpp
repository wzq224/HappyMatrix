/************************************************************************/
/* ¿ìÀÖµÄ¾ØÕó    WZQ  2014-01-23                                         */
/************************************************************************/

#include <iostream>
using namespace std;

void ZMatrix(const int n);
void normalMatrix(const int n);
void vortexMatrix(const int n);
void vortexMatrix2(const int n);
void zigzagMatrix(const int n);
void zigzag(int** &matrix,int x,int y,int n);
int main()
{
	const int n = 6;
	normalMatrix(n);
	ZMatrix(n);
	vortexMatrix(n);
	//vortexMatrix2(n);
	zigzagMatrix(n);
	system("pause");

	return 0;
}

void ZMatrix(const int n)
{
	cout << "Z Matrix :" << endl;
	int num = 0;
	for (int i=0; i<n; i++)
	{
		if (0 == i%2)
		{	
			num = i*n;
			for (int j=0; j<n; j++)
			{
				cout << num++ << "\t";
			}
		}
		else
		{
			num = (i+1)*n-1;
			for (int j=0; j<n; j++)
			{
				cout << num-- << "\t";
			}
		}
		cout << endl << endl;
	}
}


void normalMatrix(const int n)
{
	cout << "Normal Matrix :" << endl;
	int num = 0;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			cout << num++ << "\t";
		}
		cout << endl << endl;
	}
}

void vortexMatrix(const int n)
{
	int **matrix = new int*[n];
	int num = 0;
	cout << "Vortex Matrix:" << endl;
	
	for (int i=0; i<n; i++)
	{
		matrix[i] = new int[n];
	}
	int x=0,y=0;
	for (int i=0; i<(n+1)/2; i++)
	{
		x=i;y=i;
		for (int j=0; j<n-2*i; j++)
		{
			matrix[x][y] = num++;
			y++;
		}
	
		x=i+1;y=n-i-1;
		for (int j=0; j<n-2*i-1; j++)
		{
			matrix[x][y] = num++;
			x++;
		}
		
		x=n-i-1;y=n-i-2;
		for (int j=0; j<n-2*i-1; j++)
		{
			matrix[x][y] = num++;
			y--;
		}
		x=n-i-2;y=i;
		for (int j=0; j<n-2*i-2; j++)
		{
			matrix[x][y] = num++;
			x--;
		}
	}

	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl << endl;
	}
}

void vortexMatrix2(const int n)
{
	int **matrix = new int*[n];
	int num = 0;
	cout << "Vortex Matrix 2:" << endl;

	for (int i=0; i<n; i++)
	{
		matrix[i] = new int[n];
	}
	int x=0,y=0;
	for (int i=0; i<(n+1)/2; i++)
	{
		for (int j=0; j<n-2*i-1; j++)
		{
			matrix[x][y++] = num++;
		}
		for (int j=0; j<n-2*i-1; j++)
		{
			matrix[x++][y] = num++;
		}
		for (int j=0; j<n-2*i-1; j++)
		{
			matrix[x][y--] = num++;
		}
		for (int j=0; j<n-2*i-1; j++)
		{
			matrix[x--][y] = num++;
		}
		x++;y++;
	}
	
	if (n%2 != 0)
	{
		matrix[n/2][n/2] = n*n-1;
	}

	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl << endl;
	}
}

void zigzagMatrix(const int n)
{
	int **matrix = new int*[n];
	cout << "ZigZag Matrix:" << endl;

	for (int i=0; i<n; i++)
	{
		matrix[i] = new int[n];
	}
	
	zigzag(matrix,n-1,n-1,n);

	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl << endl;
	}
}

void zigzag(int** &matrix,int x,int y,int n)
{
	if (0 == x && 0 == y)
	{
		matrix[x][y] = 0;
	}
	else if ((0 == y && 0 == x%2) || (x != 0 && n - 1 == y && 0 == (x+n)%2))
	{
		zigzag(matrix,x-1,y,n);		
		matrix[x][y] = matrix[x-1][y] + 1;		
	}
	else if ((0 == x && 1 == y%2) || (y != 0 && n - 1 == x && 1 == (y+n)%2))
	{
		zigzag(matrix,x,y-1,n);
		matrix[x][y] = matrix[x][y-1] + 1;	
	}
	else
	{
		if (0 == (x+y)%2)
		{
			zigzag(matrix,x+1,y-1,n);
			matrix[x][y] = matrix[x+1][y-1] + 1;
		}
		else
		{
			zigzag(matrix,x-1,y+1,n);
			matrix[x][y] = matrix[x-1][y+1] + 1;
		}
	}
}
