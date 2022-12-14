//
//  Matrix.cpp
//  Determinant2
//
//  Created by ing.conti on 07/10/22.
//

#include <vector>
#include <iostream>

#include "Matrix.h"

// “YOUR CODE HERE” for constructor.


Matrix::Matrix( int nRows, int nCols){
    // “YOUR CODE HERE”
    vector<double> zeros(nCols,0);

    for (int i = 0; i < nRows ; ++i) {
        mat.push_back(zeros);
    }
}

double Matrix::getElem(size_t i, size_t j) const{
    // “YOUR CODE HERE”
    if(i<mat.size() && j<mat[i].size())
        return mat[i][j];
    else
        return INVALID; // default value. Only to allow build.
}

double Matrix::determinant() const{

    // “YOUR CODE HERE”
    if (mat.size()!=mat[0].size())
        return INVALID;
    if (mat.size()==1 && mat[0].size()==1)
        return mat[0][0];

    double sum=0;
    for (int j = 0; j < mat[0].size(); ++j) {
        sum += mat[0][j]*pow(-1,j)*complementary(0,j).determinant() ;
    }

    return sum;
}


Matrix::Matrix(const vector<vector<double>> & mat_init):mat(mat_init) {}

void Matrix::print() {
    for (const auto & v : mat) {
        for (const double & m:v) {
            std::cout << m << " ";
        }
        std::cout << "\n";
    }
}


void Matrix::setElem(size_t i, size_t j, double v) {
    mat[i][j]=v;
}

Matrix Matrix::complementary(int i, int j) const{\
    size_t m=0, n=0;
    Matrix comp=Matrix(mat.size()-1,mat[0].size()-1);

    for (int k = 0; k < mat.size(); ++k) {
        if(k!=i){
            for (int l = 0; l < mat[0].size(); ++l) {
                if (l!=j) {
                    //comp.setElem(m, n, mat[k][l]);

                    //QUESTION: Can an object and his methods directly access a private field of another object of the same class? It seems so
                    comp.mat[m][n]=mat[k][l];
                    n++;
                }
            }
            n=0;
            m++;
        }
    }
    return comp;
}

