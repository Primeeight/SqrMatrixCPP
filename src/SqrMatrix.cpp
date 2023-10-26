#include "SqrMatrix.h"
#include <iostream>
#include <iomanip>

using namespace std;

SqrMatrix::SqrMatrix() {
    size = 1;
    // TODO Make sq into an initialized 1 by 1 matrix (the one index is 0)
    sq = new int *[size];
    for (int i = 0; i < size; i++) {
        sq[i] = new int[size];
    }
}

SqrMatrix::SqrMatrix(int N) {
    size = N;
    // TODO Make sq into an initialized N by N matrix (all indices are 0)
    sq = new int *[size];
    for (int i = 0; i < size; i++) {
        sq[i] = new int[size];
    }
}

std::ostream &operator<<(std::ostream &out, SqrMatrix *matrix) {
    /* TODO Print out the N by N matrix in the same fashion as is displayed in the given test files, like this:
                            [1, 2, 3,
                             4, 5, 6,
                             7, 8, 9]
     */

/* Create two counts for end of line and end of file formatting
 * Create a string for buffering and a string for printing.
 * Create a loop to print numbers of an array
 * Use string stream and cEof to convert int string
 * Print out the string
 * The print statement should be formatted like the test files.
 */

    //Create a string stream object.
    stringstream sSq;
    sSq << "[";
    //Crete a string to print out the 2d array.
    string strSq = "";
    string bfrSq = "";
    //Create a count for formatting.
    int cEof = 0;
    int cEol = 0;
    //Begin converting the array into a string using string stream.
    for (int i = 0; i < matrix->size; i++) {
        for (int j = 0; j < matrix->size; j++) {
            sSq << matrix->sq[i][j];
            cEof++;
            cEol++;
            if (cEof == matrix->size * matrix->size) {
                sSq << "]";
            } else if (cEol == matrix->size) {
                bfrSq = ",";
                cEol = 0;
            } else {
                bfrSq = ", ";
            }
            sSq >> strSq;
            strSq = strSq + bfrSq;
            bfrSq.clear();
            sSq.clear();
            cout << strSq;
        }
        if (cEof == matrix->size * matrix->size) {
            cout << endl;
            cEof = 0;
        } else
            cout << endl << " ";
    }
    return out;
}

std::istream &operator>>(std::istream &in, SqrMatrix *matrix) {
    // TODO take in inputs to populate the matrix
    /*
     *Prompt for the inputs to this matrix.
     * Start from the beginning of the matrix, and loop through N size.
     * Take the input as val
     * Use the putElement method to populate the matrix.
     */

    int val = 0;
    //Use a nested for loop to increment through the matrix.
    for (int i = 0; i < matrix->size; i++) {
        for (int j = 0; j < matrix->size; j++) {
            //Take the input as val.
            cin >> val;
            //Call the put element method
            matrix->putElement(val, i, j);
        }
    }
    return in;
}

SqrMatrix *SqrMatrix::operator*(SqrMatrix *smPtrB) {
    //TODO perform matrix multiplication on the sq and smPrtB->sq matrices. Create and return a new matrix with the result of the matrix multiplication
    //Multiply the matrix.
    //Create a new matrix to hold the result.
    SqrMatrix *newSq = new SqrMatrix(size);

    //multiply the matrices.
    for (int i = 0; i < smPtrB->size; i++) {
        for (int j = 0; j < smPtrB->size; j++) {
            newSq->putElement(0, i, j);
            for (int k = 0; k < smPtrB->size; k++) {
                newSq->sq[i][j] += sq[i][k] * smPtrB->sq[k][j];
            }
        }

    }
    //return a new matrix of size N.
    return newSq;
}

int SqrMatrix::getElement(int i, int j) {
    // TODO gets the element found at the index [i][j] in the matrix
    return sq[i][j];
}

void SqrMatrix::putElement(int val, int i, int j) {
    // TODO puts the element 'val' at the index [i][j] in the matrix
    sq[i][j] = val;
}

int SqrMatrix::getSize() {
    return size;
}

