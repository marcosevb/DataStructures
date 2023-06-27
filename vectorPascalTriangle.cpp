#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<vector<int>> pascalTriangle (int row) {
    vector<vector<int>> result; //declare vector of vectors which will contain pascal triangle
    
    if (0 > row && row > 20) { //if rows not in range then return empty vector
        cout << "You did not enter a valid input" << endl;
        return result;
    }

    result.resize(row); //resize vector to number of rows

    for (int i = 0; i < row ; ++i) {
        result[i].resize(i+1); //for each row resize it to the correct size
        for (int j = 0; j < i+1; ++j) {
            if (j == 0 || j == i ) //begining and end elements will be 1
                result[i][j] = 1;
            else
                result[i][j] = result[i-1][j-1] + result[i-1][j]; //all other elements will be the sum of the two elements above it
        }
    }

    return result; //return resulting triangle
}

void printPascalTriangle(const vector<vector<int>>& triangle) {
    for (int i = 0; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++)
            cout << triangle[i][j] << " "; //go through each element in vector and print it

        cout << endl;
    }
}

int main()
{
    int rows = 0; // !!INPUT!! the number of rows desired for your pascal triangle 

    cout << "Please enter an integer from 1 - 20: ";
    cin >> rows;

    auto triangle = pascalTriangle(rows); //call functions to create and then print pascal triangle
    printPascalTriangle(triangle);

}
