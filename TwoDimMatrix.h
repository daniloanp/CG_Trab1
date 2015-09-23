//
// Created by danilo on 23/09/15.
//

#ifndef CG_TRAB1_TWODIMMATRIX_H
#define CG_TRAB1_TWODIMMATRIX_H

template <class T>
class TwoDimMatrix
{
private:
    unsigned int height;
    unsigned int width;
    T *data = nullptr;

public:
    TwoDimMatrix(unsigned int height, unsigned int width, T **data);
    TwoDimMatrix(unsigned int height, unsigned int width);
    ~TwoDimMatrix();

    T Get(unsigned int row, unsigned int column);
    void Set(unsigned int row, unsigned int column, T value );
    
};


#endif //CG_TRAB1_TWODIMMATRIX_H
