//
// Created by egor on 05.02.2022.
//

#include "ThreeDiagonalSolver.hpp"

namespace Slae::Solver {
    double *ThreeDiagonalSolver::solveThreeDiagonal(const Slae::Matrix::ThreeDiagonalMatrix &matrix,
                                                    const double* col) {
        long n = matrix.size_;
        auto result = new double[n];
        auto gammas = new double[n];
        auto betas = new double[n];
        gammas[0] = -matrix(0, 2) / matrix(0, 1);
        betas[0] = col[0] / matrix(0, 1);

        for (unsigned i = 1; i < n; ++i){
            gammas[i] = -matrix(i, 2) /
                    (matrix(i, 0) * gammas[i - 1] + matrix(i, 1));
            betas[i]  = (col[i] - matrix(i, 0) * betas[i - 1]) /
                    (matrix(i, 0) * gammas[i - 1] + matrix(i, 1));
        }

        result[n - 1] = (col[n - 1] - matrix(n - 1, 0) * betas[n - 2])/
                (matrix(n - 1, 0) * gammas[n - 2] + matrix(n - 1, 1));

        for (unsigned i = 1; i < n; ++i){
            result[n - 1 - i] = gammas[n - 1 - i] * result[n - i] + betas[n - 1 - i];
        }

        return result;
    }
}