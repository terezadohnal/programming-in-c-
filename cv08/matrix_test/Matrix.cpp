#include "Matrix.h"

Matrix::Matrix(int width, int height){
    if (width < 1) {
        width = 1;
    }

    if (height < 1) {
        height = 1;
    }
    
    assert(height >= 1);
    assert(height >= 1);
    
    // assert musi byt vzdy splneny, jinak nam program spadne, coz chceme
    //takto se daji osetrt vstupni parametry metod
    //napr chceme, aby parametry, ktere predavame, aby byly prirozene, tudiz udelame toto:
    //assert(width >= 1 and height >= 1);
    
    //vyjimky jsou nestandardni situace, kdy se neco pokazi, ale nemely by se pouzivat prilis, protoze to spomaluje kod, asserty jsou ujisteni

//	vector<int> column(height); // (height, 0);
//	for (int i=0; i<height; i++)
//		column[i] = 0;
    //oprava:
    vector<int> column(width);
    for (int i=0; i<width; i++)
        column[i] = 0;
//	for (int i=0; i<width; i++)
//		m_matrix.push_back(column);
    for (int i=0; i<height; i++)
        m_matrix.push_back(column);
		
	m_width = width;
	m_height = height;
}

void Matrix::addRow(){
	for (int i=0; i<m_width; i++)	
		m_matrix[i].push_back(0);
	m_height++;
}

void Matrix::addColumn(){
	//m_matrix.push_back(vector<int>(m_height,0));
	vector<int> column(m_height,0);
	m_matrix.push_back(column);
	m_width++;
}

void Matrix::deleteRow() throw (std::length_error){
	if (m_height>0){
		for (int i=0; i<m_width; i++)	
			m_matrix[i].pop_back();	
		m_height--;
	} else {
		throw std::length_error("Pocet radku je 0");
	}
}

void Matrix::deleteColumn() throw (std::length_error){
	if (m_width>0){
		m_matrix.pop_back();	
		m_width--;
	} else {
		throw std::length_error("Pocet sloupcu je 0");
	}
}

void Matrix::printMatrix(){
	for (int i=0; i<m_height; i++){	
		for (int j=0; j<m_width; j++)	
			std::cout << m_matrix.at(j).at(i) << " ";
		std::cout << std::endl;
	}
}

void Matrix::insert(int x, int y, int value) throw (std::out_of_range){
	if ((x>=0) and (x<=m_width) and (y>=0) and (y<=m_height)){
//        m_matrix[x][y] = value; oprava
		m_matrix[y][x] = value;
	} else {
		throw std::out_of_range("Zapis mimo rozsah matice");
	}
}

int Matrix::getWidth() const {
	return m_width;
}

int Matrix::getHeight() const {
	return m_height;
}

int Matrix::getValue(int x, int y) const noexcept(false) {
    return m_matrix.at(y).at(x); // x - column, y - row
}
