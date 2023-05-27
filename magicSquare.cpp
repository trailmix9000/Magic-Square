


#include <iostream>
#include <cstdlib> 
#include <ctime> 
#include<array> 

using namespace std;




const int NUMBER_OF_COLUMNS = 3;
const int NUMBER_OF_ROWS = 3;

void createSquare(int matrix[][NUMBER_OF_COLUMNS], int noOfRows);
bool isDuplicate(int matrix[][NUMBER_OF_COLUMNS], int num);
int findMagicNumber(int matrix[][NUMBER_OF_COLUMNS]);
bool isMagicSquare(int matrix[][NUMBER_OF_COLUMNS]);

void createSquare(int matrix[][NUMBER_OF_COLUMNS], int noOfRows)
{
    int num;
    for (int row = 0; row < NUMBER_OF_ROWS; row++)
    {
        cout << endl;
        for (int col = 0; col < NUMBER_OF_COLUMNS; col++)
        {
            do {
                num = rand() % 9 + 1;

            } while (isDuplicate(matrix, num));
                matrix[row][col] = num;
        }
    }
}
bool isDuplicate(int matrix[][NUMBER_OF_COLUMNS], int num)
{
    for (int row = 0; row < NUMBER_OF_ROWS; row++) {
        for (int col = 0; col < NUMBER_OF_COLUMNS; col++) {
            if (num == matrix[row][col]) {   
                return true;
            }
         
        }
    }
    
    return false;
}
bool isMagicSquare(int matrix[][NUMBER_OF_COLUMNS]) // this function does not work with squares larger than 3x3 :(
{
    int magicNum = findMagicNumber(matrix);
    for (int i = 0; i < NUMBER_OF_ROWS; i++) 
    {
        if (matrix[i][0] + matrix[i][1] + matrix[i][2] != magicNum)
            return false;
    }
    for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
    {
        if (matrix[0][j] + matrix[1][j] + matrix[2][j] != magicNum)
            return false;
    }
    if (matrix[0][0] + matrix[1][1] + matrix[2][2] != magicNum || matrix[0][2] + matrix[1][1] + matrix[2][0] != magicNum)
        return false;

    return true;
}
int findMagicNumber(int matrix[][NUMBER_OF_COLUMNS]) // this is always 15 and I probably didnt need this function 
{
    int sum = 0;
    
    for (int row = 0; row < NUMBER_OF_ROWS; row++)

    {
        for (int col = 0; col < NUMBER_OF_COLUMNS; col++)
            sum = sum + matrix[row][col];;
    }
    int avg = sum / 3;
    return avg;
}

int main()
{
    srand(time(0));
    int matrix[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
    cout << "Generating a 3x3 square! . . .";
    createSquare(matrix, NUMBER_OF_ROWS);
    cout << "Your square is show below." << endl;
    for (int i = 0; i < NUMBER_OF_ROWS; i++)
    {
        cout << endl;
        for (int x = 0; x < NUMBER_OF_COLUMNS; x++)
        {
            cout << matrix[i][x];
        }

    }
    cout << endl;
    if (isMagicSquare(matrix) == true)
    {
        cout << endl << "Wow! This is magic square! All the rows, columns, and \ndiagonals add to the magic number!" << endl;
        cout << "This is a very rare occurrence." << endl;
        cout << endl << "The Magic Number: " << findMagicNumber(matrix) << endl;
    }
    else {
        cout << endl << "This is not a magic square as all the rows, columns, and \ndiagonals added together do not all equal the magic number." << endl;
        cout << endl << "The Magic Number: " << findMagicNumber(matrix) << endl;
    }
    

   
}
