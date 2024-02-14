#ifndef _MATRIX_H_
#define _MATRIX_H_

using namespace std;

#include <iostream>
#include <iomanip>
#include <vector>

template <typename Object>
class Matrix
{
private:
    vector<vector<Object>> array;

public:
    Matrix(){};
    Matrix(int rows, int cols) : array(rows)
    {
        for (auto &r : array)
        {
            r.resize(cols);
        }
    }

    Matrix(vector<vector<Object>> v) : array{v} {}

    int numrows() const { return array.size(); }

    int numcols() const
    {
        if (numrows() > 0)
        {
            return array[0].size();
        }
        return 0;
    }

    const vector<Object> &operator[](int row) const
    {
        if (row < 0 || row >= array.size())
            throw out_of_range("Invalid row.");
        return array[row];
    }

    vector<Object> &operator[](int row)
    {
        if (row < 0 || row >= array.size())
            throw out_of_range("Invalid row.");
        return array[row];
    }

    friend ostream &operator<<(ostream &t, Matrix<Object> &mat)
    {
        cout << fixed;
        cout.precision(2);
        for (int i = 0; i < mat.numrows(); ++i)
        {
            cout << "|";
            for (int j = 0; j < mat.numcols(); ++j)
            {
                cout << " " << setw(6) << mat[i][j] << " ";
            }
            cout << "|" << endl;
        }
        return t;
    }

    void add(Matrix &mat);
    void transpose();
    bool searchSorted(Object x) const;
};

template <typename Object>
void Matrix<Object>::add(Matrix &mat)
{
    int rows = numrows();
    int cols = numcols();

    if (rows != mat.numrows() || cols != mat.numcols())
    {
        throw invalid_argument{"Matrix has incompatible dimensions"};
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j] = matrix[i][j] + mat[i][j];
        }
    }
}

template <typename Object>
Matrix<Object> &multiply(Matrix<Object> &a, Matrix<Object> &b)
{
    if (a.numcols() != b.numrows())
    {
        throw invalid_argument{"Matrix has incompatible dimensions"};
    }

    Matrix<Object> *mult = new Matrix<Object>(a.numrows(), b.numcols());

    for (int i = 0; i < a.numrows(); ++i)
    {
        for (int j = 0; j < b.numcols(); ++j)
        {
            (*mult)[i][j] = 0;
        }
    }

    for (int i = 0; i < a.numrows(); ++i)
    {
        for (int j = 0; j < b.numcols(); ++j)
        {
            for (int k = 0; k < b.numrows(); k++)
            {
                (*mult)[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return *mult;
}
template <typename Object>
void Matrix<Object>::transpose()
{
    int rows = numrows();
    int cols = numcols();

    if (rows <= cols) // hvis der er flere kolonner end r�kker
    {
        int rowsadded = 0;
        cout << "Need more rows" << endl;
        // complexty på (cols - rows)
        while (rows < cols) // tilf�j r�kker til der er lige mange kolonner og r�kker
        {
            cout << "Adding row" << endl;
            vector<Object> row(cols);
            matrix.push_back(row);
            cout << "Row added" << endl;
            rows = numrows();
            rowsadded++;
        }
        cout << "Time to swap" << endl;
        // complextiy på (cols^2)
        for (size_t i = 0; i < cols; i++) // gennemg� alle kolonner
        {
            for (size_t j = 0; j < i; j++) // Tag den �vre trekant i matricen
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // complexty på (cols - rows)
        while (rowsadded != 0)
        {
            cout << "Removing excess colums" << endl;
            for (auto &r : matrix)
            {
                r.resize(cols - 1);
            }
            rowsadded--;
        }
    }
    else // Der er flere r�kker end kolonner
    {
        int columsadded = 0;
        cout << "Need more columns" << endl;
        while (rows > cols) // tilf�j kolonner til der er lige mange kolonner og r�kker
        {
            cout << "Adding columns" << endl;
            for (auto &row : matrix)
            {
                row.resize(rows);
            }
            cout << "Columns added" << endl;
            columsadded = numcols() - cols;
            cols = numcols();
        }

        cout << "Time to swap" << endl;
        for (size_t i = 0; i < rows; i++) // gennemg� alle kolonner
        {
            for (size_t j = 0; j < i; j++) // Tag den �vre trekant i matricen
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        while (columsadded != 0)
        {
            cout << "Removing excess rows" << endl;
            matrix.pop_back();
            columsadded--;
        }
    }
}

template <typename Object>
bool Matrix<Object>::searchSorted(Object x) const
{

    int m = 0;

    for (int i = 0; i < numcols(); i++)
    {
        if (matrix[i][0] == x)
        {
            return true;
        }

        m = i;

        if (matrix[i][0] > x)
        {
            i = numcols();

            if (m != 0) // go one row back, if m != 0
            {
                m--;
            }
        }
    }

    for (size_t j = 0; j < numcols(); j++)
    {
        if (matrix[m][j] == x) // Hvis elementet er det rigtige, returner true
        {
            return true;
        }
    }
    return false;
}

#endif
