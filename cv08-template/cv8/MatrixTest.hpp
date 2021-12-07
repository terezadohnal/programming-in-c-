//
//  MatrixTest.hpp
//  dynamicka_matice_vzor
//
//  Created by David Procházka on 15/11/2018.
//

#ifndef MatrixTest_hpp
#define MatrixTest_hpp

#include "TestSuite/Test.h"
#include "Matrix.h"

class MatrixTest: public TestSuite::Test {
public:
    void run();
private:
    void testConstructor();
    void testInsert();
    void testAddRow();
    void testAddColumn();
    void testDeleteRow();
    void testDeleteColumn();
};

#endif /* MatrixTest_hpp */
