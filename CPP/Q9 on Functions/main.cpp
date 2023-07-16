#include <iostream>
using namespace std;
#define Max 50

void ReadMatrix(int Matrix1[][Max], int row, int column)
{
    for(int i = 0; i < row; i++)
        for(int j = 0; j < column; j++)
            cin>>Matrix1[i][j];


}

void MultiplyMatrices(int Matrix1[][Max], int Matrix2[][Max], int multResult[][Max], int row, int column)
{
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<column; j++)
        {
            multResult[i][j] = 0;
            for (int k=0; k<row; k++)
                multResult[i][j] += Matrix1[i][k] * Matrix2[k][j];
        }
    }
}

void display(int mult[][Max], int row, int column)
{
    cout << "Result Matrix:" << endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            cout<<mult[i][j]<<" ";
            if(j == column-1)
                cout<<endl;
        }
    }
}

int main()
{
    int Matrix1[Max][Max], Matrix2[Max][Max], mult[Max][Max], row, column;

    cout<<"Enter rows and column for first matrix : ";
    cin>>row>>column;

    cout<<"\nEnter 1st Matrix Elements : ";
    ReadMatrix(Matrix1,  row, column);

    cout<<"\nEnter 2nd Matrix Elements : ";
    ReadMatrix(Matrix2,  row, column);

    MultiplyMatrices(Matrix1, Matrix2, mult, row, column);

    display(mult, row, column);

    return 0;
}
