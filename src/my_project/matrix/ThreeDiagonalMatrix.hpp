//
// Created by egor on 05.02.2022.
//

#ifndef MY_PROJECT_THREEDIAGONALMATRIX_HPP
#define MY_PROJECT_THREEDIAGONALMATRIX_HPP

#include "my_project/SlaeBaseException.hpp"

#include <vector>
#include <sstream>

namespace Slae::Matrix {
    class ThreeDiagonalMatrix {
    public:
        std::vector<double> data_;
        explicit ThreeDiagonalMatrix(unsigned size);
        static ThreeDiagonalMatrix Zero (unsigned size);

        double &operator()(unsigned i, unsigned j);

        [[nodiscard]] const double &operator()(unsigned i, unsigned j) const;
    };
} // namespace Slae::Matrix


#endif //MY_PROJECT_THREEDIAGONALMATRIX_HPP
