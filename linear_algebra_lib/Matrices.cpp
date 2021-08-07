#include "Matrices.h"

Matrices::Matrices()
{

}

Matrices::~Matrices()
{

}

extern void operator ^(vector <returnType> &vect1,vector <returnType> vect2);

bool Matrices::printMatrices(unsigned char rows,unsigned char cols,vector <returnType> v) const
{
    unsigned char ctr = 0 ;
    if(v.size() >= (rows*cols)){
        for(unsigned char row = 0;row < rows;row++){
            for(unsigned char col = 0;col < cols;col++){
                std::cout << v[ctr] << " ";
                ctr++;
            }
            std::cout << std::endl;

        }
        return MatricesFound;
    }else
        return MatricesNotFound;
}

void Matrices::matricesScalarMul(vector <returnType> &v1,returnType Scalar) const
{
    /* Multiply the scalar by all matrices numbers */
    for(unsigned long ctr = 0;ctr < v1.size();ctr++){
        v1[ctr] = v1[ctr]*Scalar;
    }
}

char Matrices::addTwoMatrices(vector <returnType> v1,vector <returnType> v2,vector <returnType> &addedVectrs) const
{
    /* To add to matrices they should be in the same size and you should add each element from the first one
       with it's corresponding element from the second one */
    if(v1.size() != v2.size())
        return WRONG_RESULT;

    for(unsigned char ctr = 0;ctr < v1.size();ctr++)
        addedVectrs[ctr] = v1[ctr] + v2[ctr];
    return SUCCESS_OPERATION;
}

char Matrices::mulTwoMatrices(unsigned char colsinFirstAndRowsInsSecond,vector <returnType> v1,vector <returnType> v2,
                              vector <returnType> &resultVector) const
{
    /* 	To multiply two matrices you should calculate the sum of multiplication each row of the first one
        with the column of the second one */
    returnType sumVar ;
    if((v1.size()/colsinFirstAndRowsInsSecond > 0 && v1.size()%colsinFirstAndRowsInsSecond == 0) &&
       (v2.size()/colsinFirstAndRowsInsSecond > 0 && v2.size()%colsinFirstAndRowsInsSecond == 0)){
           for(unsigned char upperRows=0;upperRows < v1.size()/colsinFirstAndRowsInsSecond;upperRows++){
            for(unsigned char rows =0;rows <v2.size()/colsinFirstAndRowsInsSecond;rows++){
                for(unsigned char cols = 0;cols < (colsinFirstAndRowsInsSecond);cols++){
                    sumVar += v1[(cols) + (upperRows*colsinFirstAndRowsInsSecond)] * v2[((cols) * ((v2.size()/colsinFirstAndRowsInsSecond)))+rows ];
                }
                resultVector.push_back(sumVar);
                sumVar = 0 ;
                }
              }
       }else{
        return WRONG_RESULT;
       }

}

void Matrices::transposeMatrices(unsigned char rows,unsigned char cols,vector <returnType> &m) const
{
    vector <returnType> localMatrices ;
    for(unsigned char col = 0;col < cols;col++){
        for(unsigned char row = 0;row<rows;row++){
            localMatrices.push_back(m[(row*cols)+col]);
        }
    }

    m.clear();
    operator ^(m,localMatrices); // copy the local matrix to the passed matrix
}

void Matrices::calculateIdentityMatrix(unsigned char matriecsCols,vector <returnType> matriecs,vector <returnType> &identityMatriecs) const
{
    identityMatriecs.clear();
    for(unsigned char col = 0;col < matriecsCols; col++){
        for(unsigned char row = 0;row<matriecsCols;row++){
            if(row == col)
                identityMatriecs.push_back(1);
            else
                identityMatriecs.push_back(0);
        }
    }
}

void Matrices::calculateInverseMatrix(vector <returnType> matriecs,vector <returnType> &inverseMatriecs,
                                      returnType &inverseMatrixScalar) const
{
    vector <returnType> localMatrix;
    switch(matriecs.size()){
        /* calculate matrix inverse for 2x2 matrices */
        case (2*2):
            inverseMatrixScalar = (1/((matriecs[0]*matriecs[3])-(matriecs[1]*matriecs[2])));
            localMatrix.push_back(matriecs[3]);
            localMatrix.push_back((-1 * matriecs[1]));
            localMatrix.push_back((-1 * matriecs[2]));
            localMatrix.push_back(matriecs[0]);
            inverseMatriecs.clear();
            operator ^(inverseMatriecs,localMatrix); // copy the local matrix to the passed matrix
        break;
        default:
        break;
    }
}
