//
//  main.cpp
//  matrix_test
//
//  Created by Tereza Dohnalová on 10/11/2021.
//

#include "Matrix.h"
#include "TestSuite/Suite.h"
#include "MatrixTest.h"

#include "exception"
#include "algorithm"

int main (int argc, char * const argv[]) {
//    Matrix m(2,5);
//    m.addColumn();
//    m.printMatrix();
//
//    assert(m.getWidth() == 2);
//    std::cout << "ahoj";

    auto* suite = new TestSuite::Suite("Test matice");
    suite->addTest(new MatrixTest());

    suite->run();
    suite->report();

    delete suite;

    return 0;
}

//vyhozeni vyjimky:

// slouzi pro detekce chyb

//try {
//    throw std::exception();
//    throw std::out_of_range(); // ruzne typy
//    throw std::invalid_argument()
//} catch (std::invalid_argument &e){
//    std::cerr << "nastala chyba " << e.what() << std::endl;
//
//} catch (std::domain_error &e){
//    std::cerr << "chyba" << std::endl;
//}

/**
 Testovani:
 stabilizace vyvoje
 cisty a udrzitelny kod
 
 existuji frameworky, tady mame napr. TestSuite
 */
