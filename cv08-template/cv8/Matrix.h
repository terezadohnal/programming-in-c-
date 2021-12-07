#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
#include <stdexcept>
using std::vector;

class Matrix{
private:
	vector<vector<int>> m_matrix;
	int m_width;
	int m_height;
public:
	Matrix(const int width, const int height);
    
    void print();
    
    int getValue(const int row, const int column) const noexcept(false);
    int getWidth() const;
    int getHeight() const;
    
    void insert(const int row, const int column, const int value) noexcept(false);
    
	void addRow();
	void addColumn();
    void deleteRow() noexcept(false);
    void deleteColumn() noexcept(false);
};
#endif

