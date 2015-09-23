//
// Created by danilo on 23/09/15.
//

#ifndef CG_TRAB1_TWODIMMATRIX_C
#define CG_TRAB1_TWODIMMATRIX_C

#include <cstdlib>
#include "TwoDimMatrix.h"



#endif
template<class T>
TwoDimMatrix<T>::TwoDimMatrix(unsigned int height, unsigned int width, T **data) {
    this->width = width;
    this->height = height;
    this->data = (T*) calloc(height*width, sizeof(T));
    for(int y; y < height; y++) {
        for(int x; x < height; x++) {
            this->data[y * height + width] = data[y][x];
        }
    }
}

template<class T>
TwoDimMatrix<T>::TwoDimMatrix(unsigned int height, unsigned int width) {
    this->width = width;
    this->height = height;
    this->data = (T*) calloc(height*width, sizeof(T));
}

template<class T>
TwoDimMatrix<T>::~TwoDimMatrix() {
    free(this->data);
}

template<class T>
T TwoDimMatrix<T>::Get(unsigned int row, unsigned int column) {
    return this->data[row*this->height + column];

}

template<class T>
void TwoDimMatrix<T>::Set(unsigned int row, unsigned int column, T value) {
    this->data[row*this->height + column] = value;
}
