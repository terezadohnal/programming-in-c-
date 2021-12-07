#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
#include <stdexcept>
using std::vector;

class Matrix{
private:
	vector<vector<int> > m_matrix;
	int m_width;
	int m_height;
public:
	Matrix(int width, int height);
	void addRow();
	void addColumn();
	void deleteRow() throw (std::length_error);
	void deleteColumn() throw (std::length_error);
	void printMatrix();
	void insert(int x, int y, int value) throw (std::out_of_range); // pokud bychom udelali const x, tak zafixujem parametr, nemuze ho upravovat, napr: x++
	int getWidth() const; // const rikame, ze se v teto metode nemeni hodnoty, chranime se pred chybama
	int getHeight() const;
	int getValue(int x, int y) const noexcept(false);
};
#endif

/**
 matice ma rozmer 4x4:
 
 1342
 2332
 4343
 4341
 
 */

