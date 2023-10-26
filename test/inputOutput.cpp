
#include "gtest/gtest.h"
#include "../src/SqrMatrix.h"
#include <iostream>

/** Test Naming Requirements:
*  - Unique Name
*  - Name describes what it is testing
*/

namespace {
    TEST(Matrix, Test_To_Input_And_Output_1) {
        // Setup
        testing::internal::CaptureStdout(); // Overrides output (to test it)
        std::streambuf *orig = std::cin.rdbuf();
        int N = 3; // size of matrix

        std::string inputString = "1 2 3 4 5 6 7 8 9"; // Overrides input (so each test does not need to be typed out each time)
        std::istringstream input(inputString);
        std::cin.rdbuf(input.rdbuf());

        // Defining matrix 1
        SqrMatrix *m1;
        m1 = new SqrMatrix(N);
        std::cin >> m1; // Puts in input
        std::cout << m1;  // Gets output


        //Test
        std::string output = testing::internal::GetCapturedStdout(); // Gets output
        std::string expected = "[1, 2, 3,\n 4, 5, 6,\n 7, 8, 9]\n";
        std::cin.rdbuf(orig);
        EXPECT_EQ(expected, output);
    }

    TEST(Matrix, Test_to_Double_Input_And_Output) {
        // Setup
        testing::internal::CaptureStdout(); // Overrides output (to test it)
        std::streambuf *orig = std::cin.rdbuf();
        int N = 2; // size of matrix

        std::string inputString = "1 2 3 4 5 6 7 8"; // Overrides input (so each test does not need to be typed out each time)
        std::istringstream input(inputString);
        std::cin.rdbuf(input.rdbuf());

        // Defining matrix 1
        SqrMatrix *m1;
        m1 = new SqrMatrix(N);
        std::cin >> m1; // Puts in input
        std::cout << m1; //Gets output

        // Defining matrix 2
        SqrMatrix *m2;
        m2 = new SqrMatrix(N);
        std::cin >> m2; // Puts in input
        std::cout << m2;  // Gets output


        //Test
        std::string output = testing::internal::GetCapturedStdout(); // Gets output
        std::string expected1 = "[1, 2,\n 3, 4]\n";
        std::string expected2 = "[5, 6,\n 7, 8]\n";
        std::string expected = expected1 + expected2; //test output

        std::cin.rdbuf(orig);
        EXPECT_EQ(expected, output);
    }

    TEST(Matrix, Test_Too_Much_Input) {
        // Setup
        testing::internal::CaptureStdout(); // Overrides output (to test it)
        std::streambuf *orig = std::cin.rdbuf();
        int N = 2; // size of matrix

        std::string inputString = "1 2 3 4 5 6 7 8"; // Overrides input (so each test does not need to be typed out each time)
        std::istringstream input(inputString);
        std::cin.rdbuf(input.rdbuf());

        // Defining matrix 1
        SqrMatrix *m1;
        m1 = new SqrMatrix(N);
        std::cin >> m1; // Puts in input
        std::cout << m1; //Gets output

        //Test
        std::string output = testing::internal::GetCapturedStdout(); // Gets output
        std::string expected = "[1, 2,\n 3, 4]\n";
        std::cin.rdbuf(orig);
        EXPECT_EQ(expected, output);

    }
}
