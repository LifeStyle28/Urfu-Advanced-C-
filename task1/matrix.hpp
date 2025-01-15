#pragma once
#include <vector>
using namespace std;
class Matrix
{
private:
    int x, y;
    vector<vector<int>> Z;
public:
    Matrix() = default;
    Matrix(int numRows, int numCols);

    void Reset(int numRows, int numCols);
    int& At(int row, int col);
    const int& At(int row, int col) const;
    int GetRows() const;
    int GetCols() const;

    bool operator==(const Matrix& m2);
    bool operator!=(const Matrix& m2);
    Matrix operator+(const Matrix& m2);

    friend istream& operator>>(istream& in, Matrix& M)
    friend ostream& operator<<(ostream& out, const Matrix& M)
};
