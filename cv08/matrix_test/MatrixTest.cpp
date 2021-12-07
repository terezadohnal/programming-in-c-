//
// Created by Ivo Pisařovic on 12/11/2020.
//

#include "MatrixTest.h"

void MatrixTest::testConstructor() { // muzeme to rozdelit i do samostatnych metod u slozitejsich testu
    Matrix m1(1,1); // zakladni situace
    test_(m1.getWidth() == 1); //otestujem, zda sirka/vyska se rovna 1
    test_(m1.getHeight() == 1); // zapocita se do se passed / failed testu
    test_(m1.getValue(0, 0) == 0);
    testMatrixValues(m1);
    
    Matrix m2(5, 10); //externni situace
    test_(m1.getWidth() == 5); //kdzbzchom spatne naimplementovali sirku a vysku, tento test to odhali
    test_(m1.getHeight() == 10);
    testMatrixValues(m2);
    
    Matrix m3(7, 0);
    test_(m1.getWidth() == 7);
    test_(m1.getHeight() == 1); // pokud spavne funguje vyjimka, tak se vyska nastavi na 1
    testMatrixValues(m3);
    
    Matrix m4(0, 7);
    test_(m1.getWidth() == 1);
    test_(m1.getHeight() == 7);
    testMatrixValues(m4);
    
    Matrix m5(-4, -7);
    test_(m1.getWidth() == 1);
    test_(m1.getHeight() == 1);
    testMatrixValues(m5);
    
    //vyzkouseny vsechny mozne kombinace, ktere by nam to melo hlidat
}

void MatrixTest::testGetSet() {
    Matrix m1(10, 5); //sirka - poc. sloupcu, vyska - poc radku
        
    m1.insert(0, 0, 7);
    test_(m1.getValue(0, 0) == 7);
    
    m1.insert(3, 0, 9);
    test_(m1.getValue(7, 0) == 9);

    m1.insert(4, 9, 5);
    test_(m1.getValue(4, 9) == 5);
    
    try{
        m1.insert(4, 10, 101);
        fail_("We must raise exception when row is too high");
    }catch(std::out_of_range) {
        succeed_();
    }
    
    try {
        m1.insert(-10, 4, 101);
        fail_("We must raise exception when row is too low");
    }catch(std::out_of_range){
        succeed_();
    }
 
}

void MatrixTest::testMatrixValues(const Matrix& matrix) {
    for (int radek = 0; radek < matrix.getHeight(); radek++) {
        for (int sloupec = 0; sloupec < matrix.getWidth(); sloupec++) {
//            test_(matrix.getValue(radek, sloupec) == 0);
        }
    }
    
    //otestuje to, zda se vsechny pozice naplni temi vychozimi hodnotami
}

void MatrixTest::testAddColumn(){
    //normalni vektor
    Matrix matrix(3, 3);
    test_(matrix.getWidth() == 3);
    matrix.addColumn();
    test_(matrix.getWidth() == 4);
    test_(matrix.getValue(0, 3) == 0);
    
    Matrix matrix2(1,1);
    test_(matrix2.getWidth() == 1);
    matrix2.addColumn();
    test_(matrix2.getWidth() == 2);
    test_(matrix2.getValue(0, 1) == 0);
}

void MatrixTest::testDeleteColumn(){
    //normal
    Matrix matrix(3,3);
    test_(matrix.getWidth() == 3);
    matrix.deleteColumn();
    test_(matrix.getWidth() == 2);
    try {
        test_(matrix.getValue(0, 2) == 0);
        fail_("Must throw.");
    } catch (std::out_of_range) {
        succeed_();
    }
    
    //1x1
    Matrix matrix2(1,1);
    test_(matrix2.getWidth() == 1);
    try {
        matrix2.deleteColumn();
        fail_("Must throw an exception when deleting the last col.");
    } catch (std::length_error) {
        succeed_();
    }
}

void MatrixTest::run() {
    testConstructor();
    testGetSet();
    testAddColumn();
}

