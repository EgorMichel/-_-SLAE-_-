//
// Created by egor on 11.02.2022.
//

#include "gtest/gtest.h"
#include <my_project/SlaeBaseException.hpp>
#include <my_project/matrix/ThreeDiagonalMatrix.hpp>
#include <my_project/solvers/ThreeDiagonalSolver.hpp>

using std::abs;

void check (){
    Slae::Matrix::ThreeDiagonalMatrix A(5);
    A(0, 1) = 1; A(0, 2) = -5;
    A(1, 0) = 2; A(1, 1) = -2; A(1, 2) = -5;
    A(2, 0) = -1; A(2, 1) = -13; A(2, 2) = -5;
    A(3, 0) = 11; A(3, 1) = 3; A(3, 2) = 5;
    A(4, 0) = -4; A(4, 1) = 13;

    double col[5] = {14, -7, 2, 1, 3};

    double* X = Slae::Solver::ThreeDiagonalSolver::solveThreeDiagonal(A, col);
    double eps = 10e-4;

//    for (int i = 0; i < 5; i++){
//        std::cout << X[i] << ' ';
//    }

    if (abs(X[0] + 1846./711) > eps or
        abs(X[1] + 2360./711) > eps or
        abs(X[2] - 1201./711) > eps or
        abs(X[3] + 2935./711) > eps or
        abs(X[4] + 739./711) > eps){
        throw Slae::SlaeBaseExceptionCpp("Hi");
    }

}

TEST(SOLUTION, SOLUTION_HI) {
    bool isCaught = true;
    try {
        check();
    } catch (const Slae::SlaeBaseExceptionCpp &err) {
        isCaught = false;
    }
    ASSERT_TRUE(isCaught);
}
