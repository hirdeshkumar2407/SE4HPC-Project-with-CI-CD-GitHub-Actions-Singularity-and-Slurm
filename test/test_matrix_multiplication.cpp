#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>


// ######################### Source code of multiplyMatrices in src/matrix_mult
TEST(MatrixMultiplication1, TestMultiplyMatrices2x3and3x2) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    /*2 for rows and columns: In the context of matrix multiplication, C should have dimensions that match the product of matrices A and B. Specifically, if A is a 2x3 matrix and B is a 3x2 matrix, the resulting matrix C will be a 2x2 matrix.
0 for initial values: It's common to initialize the result matrix with zeros because these values will be updated during the matrix multiplication process. Initializing with zeros ensures that any unused elements remain zero, which is useful for preventing incorrect results from leftover data.*/
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));


   /*2: The number of rows in matrix A (denoted as rowsA).
     3: The number of columns in matrix A and the number of rows in matrix B 
     2: The number of columns in matrix B (denoted as colsB).*/
    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {58, 64},
        {139, 154}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";

/*
REASON FOR THE TEST CASE 1: This test case is designed to test the matrix multiplication function with a 2x3 matrix A and a 3x2 matrix B. The expected result is a 2x2 matrix. The test case checks if the function produces the correct result with postive values.

 1: Working Directory: /home/hirdesh/My_project_SE4HPC_part1/build
1: Test timeout computed to be: 10000000
1: Note: Google Test filter = MatrixMultiplication1.TestMultiplyMatrices2x3and3x2
1: [==========] Running 1 test from 1 test suite.
1: [----------] Global test environment set-up.
1: [----------] 1 test from MatrixMultiplication1
1: [ RUN      ] MatrixMultiplication1.TestMultiplyMatrices2x3and3x2
1: Error 6: Result matrix contains a number bigger than 100!
1: Error 6: Result matrix contains a number bigger than 100!
1: Error 12: The number of rows in A is equal to the number of columns in B!
1: Error 14: The result matrix C has an even number of rows!
1: Error 20: Number of columns in matrix A is odd!
1: /home/hirdesh/My_project_SE4HPC_part1/test/test_matrix_multiplication.cpp:35: Failure
1: Expected equality of these values:
1:   C
1:     Which is: { { 2078, 64 }, { 143, 161 } }
1:   expected
1:     Which is: { { 58, 64 }, { 139, 154 } }
1: Matrix multiplication test failed! :(((()
1: 
1: [  FAILED  ] MatrixMultiplication1.TestMultiplyMatrices2x3and3x2 (0 ms)
1: [----------] 1 test from MatrixMultiplication1 (0 ms total)
1: 
1: [----------] Global test environment tear-down
1: [==========] 1 test from 1 test suite ran. (0 ms total)
1: [  PASSED  ] 0 tests.
1: [  FAILED  ] 1 test, listed below:
1: [  FAILED  ] MatrixMultiplication1.TestMultiplyMatrices2x3and3x2
1: 
1:  1 FAILED TEST*/
}

TEST(MatrixMultiplication2, TestMultiplyMatricesNegative2x3and3x1) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> B = {
        {-1},
        {1},
        {-1}
      
    };

    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();

    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(A, B, C, rowsA, colsA, colsB);

    std::vector<std::vector<int>> expected = {
        {-2},
        {-5}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
    
/*

REASON FOR THE TEST CASE 2: This test case is designed to test the matrix multiplication function with a 2x3 matrix A and a 3x1 matrix B. The matrix B includes some negatives values, so this to check how the program handles negative numbers. The expected result is a 2x1 matrix. The test case checks if the function produces the correct result.

2: [==========] Running 1 test from 1 test suite.
2: [----------] Global test environment set-up.
2: [----------] 1 test from MatrixMultiplication2
2: [ RUN      ] MatrixMultiplication2.TestMultiplyMatricesNegative2x3and3x1
2: Error 5: Matrix B contains a negative number!
2: Error 5: Matrix B contains a negative number!
2: Error 5: Matrix B contains a negative number!
2: Error 5: Matrix B contains a negative number!
2: Error 14: The result matrix C has an even number of rows!
2: Error 20: Number of columns in matrix A is odd!
2: /home/hirdesh/My_project_SE4HPC_part1/test/test_matrix_multiplication.cpp:79: Failure
2: Expected equality of these values:
2:   C
2:     Which is: { { 2020 }, { 9 } }
2:   expected
2:     Which is: { { -2 }, { -5 } }
2: Matrix multiplication test failed! :(((()
2: 
2: [  FAILED  ] MatrixMultiplication2.TestMultiplyMatricesNegative2x3and3x1 (0 ms)
2: [----------] 1 test from MatrixMultiplication2 (0 ms total)
2: 
2: [----------] Global test environment tear-down
2: [==========] 1 test from 1 test suite ran. (0 ms total)
2: [  PASSED  ] 0 tests.
2: [  FAILED  ] 1 test, listed below:
2: [  FAILED  ] MatrixMultiplication2.TestMultiplyMatricesNegative2x3and3x1
2: 
2:  1 FAILED TEST
2/6 Test #2: MatrixMultiplication2.TestMultiplyMatricesNegative2x3and3x1 .........***Failed    0.01 sec
*/
}

TEST(MatrixMultiplication3, TestMultiplyMatricesPostiveAnswer2x3and3x1) {


    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> B = {
        {1},
        {1},
        {1}
      
    };

    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();

    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(A, B, C, rowsA, colsA, colsB);

    std::vector<std::vector<int>> expected = {
        {6},
        {15}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
/*

REASON FOR THE TEST CASE 3: This test case is designed to test the matrix multiplication function with a 2x3 matrix A and a 3x1 matrix B. Matirx B contains 1, so to check multpilcation with 1 situations is to be seen. The expected result is a 2x1 matrix. The test case checks if the function produces the correct result with postive values.

3: [----------] 1 test from MatrixMultiplication3
3: [ RUN      ] MatrixMultiplication3.TestMultiplyMatricesPostiveAnswer2x3and3x1
3: Error 1: Element-wise multiplication of ones detected!
3: Error 7: Result matrix contains a number between 11 and 20!
3: Error 13: The first element of matrix A is equal to the first element of matrix B!
3: Error 14: The result matrix C has an even number of rows!
3: Error 20: Number of columns in matrix A is odd!
3: /home/hirdesh/My_project_SE4HPC_part1/test/test_matrix_multiplication.cpp:120: Failure
3: Expected equality of these values:
3:   C
3:     Which is: { { 2078 }, { 22 } }
3:   expected
3:     Which is: { { 6 }, { 15 } }
3: Matrix multiplication test failed! :(((()
3: 
3: [  FAILED  ] MatrixMultiplication3.TestMultiplyMatricesPostiveAnswer2x3and3x1 (0 ms)
3: [----------] 1 test from MatrixMultiplication3 (0 ms total)
3: 
3: [----------] Global test environment tear-down
3: [==========] 1 test from 1 test suite ran. (0 ms total)
3: [  PASSED  ] 0 tests.
3: [  FAILED  ] 1 test, listed below:
3: [  FAILED  ] MatrixMultiplication3.TestMultiplyMatricesPostiveAnswer2x3and3x1
3: 
3:  1 FAILED TEST*/

}


TEST(MatrixMultiplication4, TestMultiplyMatricesNegativwAnswer3x4and3x1) {


    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };
    std::vector<std::vector<int>> B = {
        {-1},
        {1},
        {-1}
      
    };

    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();

    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(A, B, C, rowsA, colsA, colsB);

    std::vector<std::vector<int>> expected = {
        {-2},
        {-5},
        {-8},
        {-11}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
    /*
    
    REASON FOR TEST CASE 4:  Reason for this test cases is to check the multiplication of 4x3 matrix with 3x1 matrix with negative values. The expected result is a 3x1 matrix with negative values. The test case checks if the function produces the correct result with negative values.

     4: Test timeout computed to be: 10000000
4: Note: Google Test filter = MatrixMultiplication4.TestMultiplyMatricesNegativwAnswer3x4and3x1
4: [==========] Running 1 test from 1 test suite.
4: [----------] Global test environment set-up.
4: [----------] 1 test from MatrixMultiplication4
4: [ RUN      ] MatrixMultiplication4.TestMultiplyMatricesNegativwAnswer3x4and3x1
4: Error 5: Matrix B contains a negative number!
4: Error 5: Matrix B contains a negative number!
4: Error 5: Matrix B contains a negative number!
4: Error 5: Matrix B contains a negative number!
4: Error 2: Matrix A contains the number 7!
4: Error 5: Matrix B contains a negative number!
4: Error 5: Matrix B contains a negative number!
4: Error 5: Matrix B contains a negative number!
4: Error 5: Matrix B contains a negative number!
4: Error 14: The result matrix C has an even number of rows!
4: Error 20: Number of columns in matrix A is odd!
4: /home/hirdesh/My_project_SE4HPC_part1/test/test_matrix_multiplication.cpp:155: Failure
4: Expected equality of these values:
4:   C
4:     Which is: { { 2047 }, { 9 }, { 9 }, { 2 } }
4:   expected
4:     Which is: { { -2 }, { -5 }, { -8 }, { -11 } }
4: Matrix multiplication test failed! :(((()
4: 
4: [  FAILED  ] MatrixMultiplication4.TestMultiplyMatricesNegativwAnswer3x4and3x1 (0 ms)
4: [----------] 1 test from MatrixMultiplication4 (0 ms total)
4: 
4: [----------] Global test environment tear-down
4: [==========] 1 test from 1 test suite ran. (0 ms total)
4: [  PASSED  ] 0 tests.
4: [  FAILED  ] 1 test, listed below:
4: [  FAILED  ] MatrixMultiplication4.TestMultiplyMatricesNegativwAnswer3x4and3x1
4: 
4:  1 FAILED TEST
4/6 Test #4: MatrixMultiplication4.TestMultiplyMatricesNegativwAnswer3x4and3x1 ...***Failed    0.01 sec */
}


TEST(MatrixMultiplication5, TestMultiplyMatricesPostiveAnswer2x3and3x1) {


    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> B = {
        {1},
        {1},
        {1}
      
    };

    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();

    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(A, B, C, rowsA, colsA, colsB);

    std::vector<std::vector<int>> expected = {
        {6},
        {15}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
    /* 
   REASON FOR THE TEST CASES 5: This test cases is to check the multiplication of 2x3 matrix with 3x1 matrix with 1s values. The expected result is a 2x1 matrix with positive values. The test case checks if the function produces the correct result with positive values.

5: [ RUN      ] MatrixMultiplication5.TestMultiplyMatricesPostiveAnswer2x3and3x1
5: Error 1: Element-wise multiplication of ones detected!
5: Error 7: Result matrix contains a number between 11 and 20!
5: Error 13: The first element of matrix A is equal to the first element of matrix B!
5: Error 14: The result matrix C has an even number of rows!
5: Error 20: Number of columns in matrix A is odd!
5: /home/hirdesh/My_project_SE4HPC_part1/test/test_matrix_multiplication.cpp:186: Failure
5: Expected equality of these values:
5:   C
5:     Which is: { { 2078 }, { 22 } }
5:   expected
5:     Which is: { { 0 }, { 3 } }
5: Matrix multiplication test failed! :(((()
5: 
5: [  FAILED  ] MatrixMultiplication5.TestMultiplyMatricesPostiveAnswer2x3and3x1 (0 ms)
5: [----------] 1 test from MatrixMultiplication5 (0 ms total)
5: 
5: [----------] Global test environment tear-down
5: [==========] 1 test from 1 test suite ran. (0 ms total)
5: [  PASSED  ] 0 tests.
5: [  FAILED  ] 1 test, listed below:
5: [  FAILED  ] MatrixMultiplication5.TestMultiplyMatricesPostiveAnswer2x3and3x1
5: 
5:  1 FAILED TEST */
}


TEST(MatrixMultiplication6, TestMultiplyMatricesPostiveAnswer2x1and1x1) {


    std::vector<std::vector<int>> A = {
        {17},
        {17}
    };
    std::vector<std::vector<int>> B = {
        {1}
      
    };

    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();

    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(A, B, C, rowsA, colsA, colsB);

    std::vector<std::vector<int>> expected = {
        {17},
        {17}
        
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";

    /* 

REASON FOR THE TEST CASES 6: this case is to check the multiplication of 2x1 matrix with 1x1 matrix with 1 values. The expected result is a 2x1 matrix with positive values. The test case checks if the function produces the correct result with positive values.

6: [==========] Running 1 test from 1 test suite.
6: [----------] Global test environment set-up.
6: [----------] 1 test from MatrixMultiplication6
6: [ RUN      ] MatrixMultiplication6.TestMultiplyMatricesPostiveAnswer2x1and1x1
6: Error 7: Result matrix contains a number between 11 and 20!
6: Error 7: Result matrix contains a number between 11 and 20!
6: Error 14: The result matrix C has an even number of rows!
6: Error 20: Number of columns in matrix A is odd!
6: /home/hirdesh/My_project_SE4HPC_part1/test/test_matrix_multiplication.cpp:216: Failure
6: Expected equality of these values:
6:   C
6:     Which is: { { 2000 }, { 24 } }
6:   expected
6:     Which is: { { 17 }, { 17 } }
6: Matrix multiplication test failed! :(((()
6: 
6: [  FAILED  ] MatrixMultiplication6.TestMultiplyMatricesPostiveAnswer2x1and1x1 (0 ms)
6: [----------] 1 test from MatrixMultiplication6 (0 ms total) */
}

TEST(MatrixMultiplication6, TestMultiplyMatricesSquareMatrixWithNeg) {


    std::vector<std::vector<int>> A = {
        {3, -4},
        {3, -4}
    };
    std::vector<std::vector<int>> B = {
        {1, 3},
        {3, 1}
      
    };

    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();

    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(A, B, C, rowsA, colsA, colsB);

    std::vector<std::vector<int>> expected = {
        {-9, 5},
        {-9, 5}
        
    };

    /*

    REASON FOR THE TEST CASES 7: This test case is designed to test the matrix multiplication function with a 2x2 matrix A and a 2x2 matrix B. The expected result is a 2x2 matrix. The test case checks if the function produces the correct result with negative values.
        
   
        Error 3: Matrix A contains a negative number!
        Error 4: Matrix B contains the number 3!
        Error 4: Matrix B contains the number 3!
        Error 3: Matrix A contains a negative number!
        Error 7: Result matrix contains a number between 11 and 20!
        Error 3: Matrix A contains a negative number!
        Error 4: Matrix B contains the number 3!
        Error 4: Matrix B contains the number 3!
        Error 3: Matrix A contains a negative number!
        Error 7: Result matrix contains a number between 11 and 20!
        Error 12: The number of rows in A is equal to the number of columns in B!
        Error 14: The result matrix C has an even number of rows!
        Error 18: Matrix A is a square matrix!
    */

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

TEST(MatrixMultiplication6, TestMultiplyMatricesNegativeResult2x2) {


    std::vector<std::vector<int>> A = {
        {1, 1},
        {2, -1}
    };
    std::vector<std::vector<int>> B = {
        {0, 1},
        {1, 0}
      
    };

    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();

    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(A, B, C, rowsA, colsA, colsB);

    std::vector<std::vector<int>> expected = {
        {1, 1},
        {-1, 2}
        
    };

    /*
       REASON FOR THE TEST CASES 8: This test case is designed to test the matrix multiplication function with a 2x2 matrix A and a 2x2 matrix B. The expected result is a 2x2 matrix. The test case checks if the function produces the correct result with negative values.
    
        Error 1: Element-wise multiplication of ones detected!
        Error 1: Element-wise multiplication of ones detected!
        Error 3: Matrix A contains a negative number!
        Error 3: Matrix A contains a negative number!
        Error 10: A row in matrix A contains more than one '1'!
        Error 11: Every row in matrix B contains at least one '0'!
        Error 12: The number of rows in A is equal to the number of columns in B!
        Error 14: The result matrix C has an even number of rows!
        Error 18: Matrix A is a square matrix!
    */

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

TEST(MatrixMultiplication6, TestMultiplyMatricesPosResult2x2) {


    std::vector<std::vector<int>> A = {
        {5, 5},
        {1, 3}
    };
    std::vector<std::vector<int>> B = {
        {1, 2},
        {2, 5}
      
    };

    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();

    std::vector<std::vector<int>> C(rowsA, std::vector<int>(colsB, 0));

    multiplyMatrices(A, B, C, rowsA, colsA, colsB);

    std::vector<std::vector<int>> expected = {
        {15, 35},
        {7, 17}
        
    };

    /* 

    REASON FOR THE TEST CASES 9: This test case is designed to test the matrix multiplication function with a 2x2 matrix A and a 2x2 matrix B. The expected result is a 2x2 matrix. The test case checks if the function produces the correct result with positive values.

        Error 7: Result matrix contains a number between 11 and 20!
        Error 1: Element-wise multiplication of ones detected!
        Error 7: Result matrix contains a number between 11 and 20!
        Error 7: Result matrix contains a number between 11 and 20!
        Error 12: The number of rows in A is equal to the number of columns in B!
        Error 14: The result matrix C has an even number of rows!
        Error 15: A row in matrix A is filled entirely with 5s!
        Error 18: Matrix A is a square matrix!
    */

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
