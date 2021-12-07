#include "MatrixTest.hpp"
#include "TestSuite/Suite.h"

int main (int argc, char * const argv[]) {
    
    auto* suite = new TestSuite::Suite("Testy Matic");
    
    suite->addTest(new MatrixTest());
    
    suite->run();
    suite->report();
    
    delete suite;
    
    return 0;

}
