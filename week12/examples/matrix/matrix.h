#ifndef _MATRIX_H
#define _MATRIX_H

#include <stdbool.h> //for bool

typedef struct Matrix_{ //use typedef to simplify type name
    size_t rows; // use size_t, not int
    size_t cols; // use size_t, not int
    float * data;
} Matrix;

Matrix * createMat(size_t rows, size_t cols);
bool releaseMat(Matrix * p);//使用bool来判断是否操作成功
bool add(const Matrix * input1, const Matrix * input2, Matrix *output);

#endif
//头文件内写定义，cPP内写实现