//
// Created by danilo on 23/09/15.
//

#ifndef CG_TRAB1_TWODIMMATRIX_H
#define CG_TRAB1_TWODIMMATRIX_H

#include <stdlib.h>
#include <string.h>
#include <assert.h>

namespace image
{
    template<class T>
    class TwoDimMatrix
    {
    private:
        unsigned int height;
        unsigned int width;
        T            * data = nullptr;

    public:
        TwoDimMatrix(unsigned int height, unsigned int width, T** data);

        TwoDimMatrix(unsigned int height, unsigned int width);

        ~TwoDimMatrix();

        T    Get(unsigned int row, unsigned int column);

        void Set(unsigned int row, unsigned int column, T value);

        TwoDimMatrix<T>* Copy();

        void GetDataAsByteArray(unsigned char** data,
                                unsigned int* numElements); //unsafe: for task that required performance
    };

    template<class T>
    TwoDimMatrix<T>::TwoDimMatrix(unsigned int height, unsigned int width, T** data)
    {
        this->width  = width;
        this->height = height;
        this->data   = (T*) calloc(height * width, sizeof(T));
        for (int y; y < height; y++) {
            for (int x; x < height; x++) {
                this->data[y * height + width] = data[y][x];
            }
        }
    }

    template<class T>
    TwoDimMatrix<T>::TwoDimMatrix(unsigned int height, unsigned int width)
    {
        this->width  = width;
        this->height = height;
        this->data   = (T*) calloc(height * width, sizeof(T));
    }

    template<class T>
    TwoDimMatrix<T>::~TwoDimMatrix()
    {
        free(this->data);
    }

    template<class T>
    T TwoDimMatrix<T>::Get(unsigned int row, unsigned int column)
    {
        assert(row >= 0);
        assert(column >= 0);
        assert(row < height);
        assert(column < width);
        return this->data[row * this->width + column];

    }

    template<class T>
    void TwoDimMatrix<T>::Set(unsigned int row, unsigned int column, T value)
    {
        assert(row >= 0);
        assert(column >= 0);
        assert(row < height);
        assert(column < width);
        this->data[row * this->width + column] = value;
    }

    template<class T>
    TwoDimMatrix<T>* TwoDimMatrix<T>::Copy()
    {
        TwoDimMatrix<T>* newObj = new TwoDimMatrix<T>(this->height, this->width);
        memcpy(newObj->data, this->data, this->height * this->width * sizeof(T));
        return newObj;
    }


    template<class T>
    void TwoDimMatrix<T>::GetDataAsByteArray(unsigned char** data, unsigned int* numElements)
    {
        *data        = (unsigned char*) this->data;
        *numElements = this->height * this->width * (sizeof(T));
    }


}

#endif //CG_TRAB1_TWODIMMATRIX_H
