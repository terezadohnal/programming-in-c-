#include "Matrix.h"

Matrix::Matrix(const int width, const int height) {
    int tmpHeight = height;
    if (height < 1) tmpHeight = 1;
    assert(tmpHeight >= 1);
    
    int tmpWidth = width;
    if (width < 1) tmpWidth = 1;
    assert(tmpWidth >= 1);
    
    vector<int> row(tmpWidth, 0);
    assert(row.size() == tmpWidth);
		
    for (int i = 0; i < tmpHeight; i++) {
		m_matrix.push_back(row);
    }
    
    assert(m_matrix.size() == tmpHeight);
		
	m_width = tmpWidth;
	m_height = tmpHeight;
}

void Matrix::print() {
    assert(m_height >= 0);
    assert(m_width >= 0);
    
    for (int i = 0; i < m_height; i++) {
        for (int j = 0; j < m_width; j++) {
            std::cout << m_matrix.at(j).at(i) << " ";
        }
        std::cout << std::endl;
    }
}

int Matrix::getValue(const int row, const int column) const noexcept(false) {
    return m_matrix.at(column).at(row);
}

int Matrix::getWidth() const {
    assert(m_width >= 0);
    return m_width;
}

int Matrix::getHeight() const {
    assert(m_height >= 0);
    return m_height;
}


void Matrix::insert(const int row, const int column, const int value) noexcept(false) {
    if (
        (row >= 0) and (row < m_height) and
        (column >= 0) and (column < m_width)
    ){
        m_matrix[column][row] = value;
    } else {
        throw std::out_of_range("Zapis mimo rozsah matice");
    }
}

void Matrix::addRow() {
    vector<int> column(m_height, 0);
    assert(column.size() == m_height);
    
    m_matrix.push_back(column);
    assert(m_matrix.size() == m_height + 1);
    
    m_height++;
}

void Matrix::addColumn() {
    assert(m_width >= 0);
    
    for (int i = 0; i < m_width; i++) {
		m_matrix.at(i).push_back(0);
    }
    
    assert(m_width == 0 or m_matrix.at(0).size() == m_width + 1);
    
	m_width++;
}


void Matrix::deleteRow() noexcept(false) {
	if (m_height > 1) {
        m_matrix.pop_back();
        assert(m_matrix.size() == m_height - 1);
		m_height--;
	} else {
		throw std::length_error("Pocet radku je 1, nelze smazat posledni radek");
	}
}

void Matrix::deleteColumn() noexcept(false) {
	if (m_width > 1) {
        for (int i = 0; i < m_width; i++) {
            m_matrix.at(i).pop_back();
        }
        assert(m_width == 0 or m_matrix.at(0).size() == m_width - 1);
        
		m_width--;
	} else {
		throw std::length_error("Pocet sloupcu je 0, nelze smazat posledni sloupec");
	}
}
