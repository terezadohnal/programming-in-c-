//
// Created by Ivo Pisařovic on 12/11/2020.
//

#ifndef CPP_CVICENI8_TESTOVANI_MATRIXTEST_H
#define CPP_CVICENI8_TESTOVANI_MATRIXTEST_H

#include "TestSuite/Test.h"
#include "Matrix.h"

class MatrixTest: public TestSuite::Test {
public:
    void run() override;
private:
    void testConstructor();
    void testGetSet(); // test insert
    void testAddColumn();
    void testDeleteColumn();
    void testMatrixValues(const Matrix &matrix);
};

//temito metodami  otestujeme vsechny metody v matrix.h


#endif //CPP_CVICENI8_TESTOVANI_MATRIXTEST_H
