//
// Created by egor on 11.02.2022.
//

#include "gtest/gtest.h"
#include <my_project/SlaeBaseException.hpp>
#include <my_project/matrix/ThreeDiagonalMatrix.hpp>


Slae::Matrix::ThreeDiagonalMatrix matrix_fill(unsigned size) {
    Slae::Matrix::ThreeDiagonalMatrix result(size);
    for(unsigned i = 0; i < size; i++){
        result(i, 0) = i;
        result(i, 1) = i;
        result(i, 2) = i;
    }
    return result;
}

void check(Slae::Matrix::ThreeDiagonalMatrix matrix){
    for (unsigned i = 0; i < matrix.size_; ++i){
        if (matrix.data_[i * 3] != i or matrix.data_[i * 3 + 1] != i or matrix.data_[i * 3 + 2] != i){
            throw Slae::SlaeBaseExceptionCpp("Hi");
        }
    }
}


TEST(MATRIX, MATRIX_HI) {
    bool isCaught = true;
    try {
        Slae::Matrix::ThreeDiagonalMatrix matrix = matrix_fill(11);
        check(matrix);
    }
    catch (const Slae::SlaeBaseExceptionCpp &err) {
        isCaught = false;
    }
    ASSERT_TRUE(isCaught);
}
