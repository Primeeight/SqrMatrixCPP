
#include "gtest/gtest.h"
#include "../src/SqrMatrix.h"
#include <iostream>

/** Test Naming Requirements:
  *  - Unique Name
  *  - Name describes what it is testing
  */

namespace {

    TEST(Matrix, Test_To_Multiply_1) {
        // Setup
        testing::internal::CaptureStdout(); // Overrides output (to test it)
        std::streambuf *orig = std::cin.rdbuf();
        int N = 2; // size of matrix

        std::string inputString = "1 2 3 4 10 11 12 13"; // Overrides input (so each test does not need to be typed out each time)
        std::istringstream input(inputString);
        std::cin.rdbuf(input.rdbuf());

        // Defining matrix 1
        SqrMatrix *m1;
        m1 = new SqrMatrix(N);
        std::cin >> m1;
        std::cout << m1;

        // Defining matrix 2
        SqrMatrix *m2;
        m2 = new SqrMatrix(N);
        std::cin >> m2;
        std::cout << m2;

        //Process
        // Multiplying the 2 matrices and getting their result
        SqrMatrix *m3 = *m1 * m2;
        std::cout << m3;


        //Test
        std::string output = testing::internal::GetCapturedStdout(); // Gets output
        std::string expected1 = "[1, 2,\n 3, 4]\n";
        std::string expected2 = "[10, 11,\n 12, 13]\n";
        std::string expected3 = "[34, 37,\n 78, 85]\n";
        std::string expected = expected1 + expected2 + expected3; // Strings are combined to test output
        std::cin.rdbuf(orig);
        EXPECT_EQ(expected, output);
    }

    TEST(Matrix, Test_For_Inverse) {
        // Setup
        testing::internal::CaptureStdout(); // Overrides output (to test it)
        std::streambuf *orig = std::cin.rdbuf();
        int N = 2; // size of matrix

        std::string inputString = "1 1 2 3 3 -1 -2 1"; // Overrides input (so each test does not need to be typed out each time)
        std::istringstream input(inputString);
        std::cin.rdbuf(input.rdbuf());

        // Defining matrix 1
        SqrMatrix *m1;
        m1 = new SqrMatrix(N);
        std::cin >> m1;
        std::cout << m1;

        // Defining matrix 2
        SqrMatrix *m2;
        m2 = new SqrMatrix(N);
        std::cin >> m2;
        std::cout << m2;

        //Multiply the matrices
        SqrMatrix *m3 = *m1 * m2;
        std::cout << m3;

        //Test for identity
        //Test
        std::string output = testing::internal::GetCapturedStdout(); // Gets output
        std::string expected1 = "[1, 1,\n 2, 3]\n";
        std::string expected2 = "[3, -1,\n -2, 1]\n";
        std::string expected3 = "[1, 0,\n 0, 1]\n";
        std::string expected = expected1 + expected2 + expected3; // Strings are combined to test output
        std::cin.rdbuf(orig);
        EXPECT_EQ(expected, output);
    }

    TEST(Matrix, Test_For_Large_Matrix) {
        // Setup
        testing::internal::CaptureStdout(); // Overrides output (to test it)
        std::streambuf *orig = std::cin.rdbuf();
        int N = 3; // size of matrix

        std::string inputString = "3 6 9 12 15 18 21 24 27 2 5 7 11 13 17 19 23 29"; // Overrides input (so each test does not need to be typed out each time)
        std::istringstream input(inputString);
        std::cin.rdbuf(input.rdbuf());
        //Create the first large matrix
        SqrMatrix *m1;
        m1 = new SqrMatrix(N);
        std::cin >> m1;
        std::cout << m1;
        //Create the second large matrix
        SqrMatrix *m2;
        m2 = new SqrMatrix(N);
        std::cin >> m2;
        std::cout << m2;//Multiply the matrices
        SqrMatrix *m3 = *m1 * m2;
        std::cout << m3;

        //Test
        std::string output = testing::internal::GetCapturedStdout(); // Gets output
        std::string expected1 = "[3, 6, 9,\n 12, 15, 18,\n 21, 24, 27]\n";
        std::string expected2 = "[2, 5, 7,\n 11, 13, 17,\n 19, 23, 29]\n";
        std::string expected3 = "[243, 300, 384,\n 531, 669, 861,\n 819, 1038, 1338]\n";
        std::string expected = expected1 + expected2 + expected3; // Strings are combined to test output
        std::cin.rdbuf(orig);
        EXPECT_EQ(expected, output);

    }
}