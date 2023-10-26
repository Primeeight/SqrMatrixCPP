
#include "gtest/gtest.h"
#include "../src/SqrMatrix.cpp"
#include <iostream>

/** Test Naming Requirements:
*  - Unique Name
*  - Name describes what it is testing
*/

namespace {
    TEST(Matrix, Test_To_Get_1) {
        // Setup
        int N = 2; // size of matrix

        // Defining matrix 1
        SqrMatrix *m1;
        m1 = new SqrMatrix(N);
        m1->putElement(1, 0, 0);
        m1->putElement(2, 0, 1);
        m1->putElement(3, 1, 0);
        m1->putElement(4, 1, 1);


        //Test
        EXPECT_EQ(m1->getElement(0, 1), 2);
        EXPECT_EQ(m1->getElement(1, 1), 4);
        EXPECT_EQ(m1->getElement(0, 0), 1);
        EXPECT_EQ(m1->getElement(1, 1), 4);
    }

    TEST(Matrix, Test_To_Get_Identity) {
        //Setup
        int N = 2;

        SqrMatrix *m2;
        m2 = new SqrMatrix(N);

        m2->putElement(1, 0, 0);
        m2->putElement(0, 0, 1);
        m2->putElement(0, 1, 0);
        m2->putElement(1, 1, 1);

        //Test
        EXPECT_EQ(m2->getElement(0, 1), 0);
        EXPECT_EQ(m2->getElement(1, 0), 0);
        EXPECT_EQ(m2->getElement(0, 0), 1);
        EXPECT_EQ(m2->getElement(1, 1), 1);

    }

    TEST(Matrix, Test_To_Get_Prime) {
        //Setup
        int N = 2;
        SqrMatrix *m3;
        m3 = new SqrMatrix(N);
        m3->putElement(3, 0, 0);
        m3->putElement(6, 1, 1);
        m3->putElement(2, 0, 1);
        m3->putElement(5, 1, 0);

        SqrMatrix *m4;
        m4 = new SqrMatrix(N);
        m4->putElement(9, 0, 1);
        m4->putElement(12, 0, 1);
        m4->putElement(7, 0, 0);
        m4->putElement(11, 1, 1);

        //Test for prime numbers.
        EXPECT_EQ(m3->getElement(0, 1), 2);
        EXPECT_EQ(m3->getElement(1, 0), 5);
        EXPECT_EQ(m4->getElement(0, 0), 7);
        EXPECT_EQ(m4->getElement(1, 1), 11);
    }


}

