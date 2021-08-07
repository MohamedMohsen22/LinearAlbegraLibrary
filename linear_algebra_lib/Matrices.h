#ifndef MATRICES_H_
#define MATRICES_H_

#include <vector>
#include "Math_Solutions.h"

using namespace std;

#define WRONG_RESULT        -1
#define SUCCESS_OPERATION   0

typedef enum{
    MatricesFound = 0,
    MatricesNotFound = 1,
}matricesStatus_e;

class Matrices{
private:

protected:

public:
    Matrices();
    ~Matrices();
    bool printMatrices(unsigned char rows,unsigned char cols,vector <returnType> v) const;
    char addTwoMatrices(vector <returnType> v1,vector <returnType> v2,vector <returnType> &addedVectrs) const;
    void matricesScalarMul(vector <returnType> &v1,returnType Scalar) const;
    char mulTwoMatrices(unsigned char colsinFirstAndRowsInsSecond,vector <returnType> v1,vector <returnType> v2,
                        vector <returnType> &resultVector) const;
    void transposeMatrices(unsigned char rows,unsigned char cols,vector <returnType> &m) const;
    void calculateIdentityMatrix(unsigned char matriecsCols,vector <returnType> matriecs,vector <returnType> &identityMatriecs) const;
    void calculateInverseMatrix(vector <returnType> matriecs,vector <returnType> &inverseMatriecs,returnType &inverseMatrixScalar) const;
};

#endif // MATRICES_H_
