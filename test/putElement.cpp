
#include "gtest/gtest.h"
#include "../src/SqrMatrix.h"
#include <iostream>

/** Test Naming Requirements:
*  - Unique Name
*  - Name describes what it is testing
*/

namespace {
    TEST(Matrix, Test_To_Put_1) {
        // Setup
        testing::internal::CaptureStdout(); // Overrides output (to test it)
        std::streambuf* orig = std::cin.rdbuf();
        int N = 1; // size of matrix

        // Defining matrix 1
        SqrMatrix* m1;
        m1 = new SqrMatrix(N);
        m1->putElement(4, 0, 0);
        std::cout<<m1;

        //Test
        std::string output = testing::internal::GetCapturedStdout(); // Gets output
        std::string expected = "[4]\n";
        std::cin.rdbuf(orig);
        EXPECT_EQ(expected, output);
    }

    TEST(Matrix, Test_To_Put_2) {
        // Setup
        int N = 2; // size of matrix

        // Defining matrix 1
        SqrMatrix* m1;
        m1 = new SqrMatrix(N);
        m1->putElement(1, 0, 0);
        m1->putElement(4, 1, 1);


        //Test
        EXPECT_EQ(m1->getElement(0, 0), 1);
        EXPECT_EQ(m1->getElement(1, 1), 4);
    }
    TEST(Matrix,Test_To_Put_Twice) {
        // Setup
        testing::internal::CaptureStdout(); // Overrides output (to test it)
        std::streambuf* orig = std::cin.rdbuf();
        int N = 2; // size of matrix

        // Defining matrix 1
        SqrMatrix* m1;
        m1 = new SqrMatrix(N);
        m1->putElement(2, 0, 0);
        m1->putElement(7, 0, 1);
        m1->putElement(1, 1, 0);
        m1->putElement(8, 1, 1);
        std::cout<<m1;

        // Defining matrix 2
        SqrMatrix* m2;
        m2 = new SqrMatrix(N);
        m2->putElement(1, 0, 0);
        m2->putElement(2, 0, 1);
        m2->putElement(6, 1, 0);
        m2->putElement(24, 1, 1);
        std::cout << m2;

        //Test
        std::string output = testing::internal::GetCapturedStdout(); // Gets output
        std::string expected1 = "[2, 7,\n 1, 8]\n";
        std::string expected2 = "[1, 2,\n 6, 24]\n";
        std::string expected = expected1 + expected2;
        std::cin.rdbuf(orig);
        EXPECT_EQ(expected, output);
    }


}
