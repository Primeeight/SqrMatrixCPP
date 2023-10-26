#ifndef C455_ASSIGNMENT7_SQRMATRIX_H
#define C455_ASSIGNMENT7_SQRMATRIX_H

#include <iostream>

class SqrMatrix {

private:

    /**
     * Holds the size of the NxN matrix where size is analogous to N
     */
    int size;

    /**
     * A pointer to a two dimensional array. This is equivalent to int * sq[]
     */
    int **sq;

public:

    SqrMatrix();

    /**
     * Constructor that takes in the N for the N by N matrix with 0's.
     * @param N Number or rows and columns with the minimum integer value of 1.
     */
    explicit SqrMatrix(int N);

    ~SqrMatrix() = default;

    /**
     *  Outputs all values through standard out.
     */
    friend std::ostream& operator << (std::ostream& out, SqrMatrix* matrix);

    /**
     *  Allows ints to be passed in to the matrix through standard in.
     */
    friend std::istream& operator >> (std::istream& in, SqrMatrix* matrix);

    /**
     * Multiplies this SqrMatrix by the incoming SqrMatrix.
     * @param smPtrB a pointer to SqrMatrix of the same size that will be multiplied by this SqrMatrix.
     * @return Returns a pointer to a new SqrMatrix.
     */
    SqrMatrix* operator * ( SqrMatrix *smPtrB);

    /**
     * Will return the item at a given i and j index from the matrix
     * @param i Index for the row
     * @param j Index for the column
     * @return int returns the integer value at the given index
     */
    int getElement(int i, int j);

    /**
     * Puts an integer value at a given i and j index into the matrix
     * @param val Integer value being placed inside the matrix
     * @param i Index for the row
     * @param j Index for the column
     */
    void putElement(int val, int i, int j);

    /**
    * Gets the size of the matrix, that not being the number of elements in the array, but the
    *              number of indexes in a column/rox
    * @return the N value of a N*N matrix
    */
    int getSize();

};


#endif //C455_ASSIGNMENT7_SQRMATRIX_H
