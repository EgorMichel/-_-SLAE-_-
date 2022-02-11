//
// Created by egor on 05.02.2022.
//

#include "ThreeDiagonalMatrix.hpp"

namespace Slae::Matrix {

    ThreeDiagonalMatrix::ThreeDiagonalMatrix(unsigned size) : size_(size) {
        data_ = new double[3 * size]; // first and last elements are always equal to zero (cuz 3n-2 elements are applied)
    }

    ThreeDiagonalMatrix ThreeDiagonalMatrix::Zero (unsigned size){
        ThreeDiagonalMatrix result(size);
        std::fill(result.data_, result.data_ + size * 3, 0);
        return result;
    }

    double &ThreeDiagonalMatrix::operator()(unsigned i, unsigned j) {
#ifndef NDEBUG
        if (i >= size_) {
            std::stringstream buff;
            buff << "Index i overwhelm matrix size! Got: " << i << ". Matrix size: "
                 << size_ << ". File:" << __FILE__ << ". String: " << __LINE__;
            throw SlaeBaseExceptionCpp(buff.str());
        }
        if (j > 2) {
            std::stringstream buff;
            buff << "Index j should be from 0 to 2. Got: " << i << ". File:" << __FILE__ << ". String: " << __LINE__;
            throw SlaeBaseExceptionCpp(buff.str());
        }
#endif //NDEBUG
        return data_[i * 3 + j];
    }

    const double &ThreeDiagonalMatrix::operator()(unsigned i, unsigned j) const {
#ifndef NDEBUG
    if (i >= size_) {
        std::stringstream buff;
        buff << "Index i overwhelm matrix size! Got: " << i << ". Matrix size: "
             << size_ << ". File:" << __FILE__ << ". String: " << __LINE__;
        throw SlaeBaseExceptionCpp(buff.str());
    }
    if (j > 2) {
        std::stringstream buff;
        buff << "Index j should be from 0 to 2. Got: " << i << ". File:" << __FILE__ << ". String: " << __LINE__;
        throw SlaeBaseExceptionCpp(buff.str());
    }
#endif //NDEBUG
    return data_[i * 3 + j];
}
}