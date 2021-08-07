#include "Math_Solutions.h"

using namespace std;

MathFunctions::MathFunctions(){

}

MathFunctions::~MathFunctions(){

}

returnType MathFunctions::ceilThreeDP(returnType inputNumber) const
{
    long retNumber = 0;
    retNumber = inputNumber * 1000;
    retNumber += 1;
    inputNumber = retNumber / static_cast<returnType>(1000);
    return inputNumber;
}

void MathFunctions::mulConstantInEquation(vector <returnType> &vect,unsigned short vectSize, returnType constant) const
{
    for(int vect_ctr = 0; vect_ctr < vectSize; vect_ctr++){
        vect[vect_ctr] *= constant;
    }

}
void MathFunctions::subTwoSameSizeEquations(vector <returnType> &vect1,unsigned short vectSize,vector <returnType> vect2) const
{
    for(int vect_ctr = 0; vect_ctr < vectSize; vect_ctr++){
        vect1[vect_ctr] -= vect2[vect_ctr];
    }

}

void operator ^(vector <returnType> &vect1,vector <returnType> vect2)
{
    for(int ctr = 0; ctr < vect2.size();ctr++){
        vect1.push_back(vect2[ctr]);
    }
}

void MathFunctions::swapTwoEquations(vector <returnType> &vect1,vector <returnType> &vect2) const
{
    vect1.swap(vect2);
}

void MathFunctions::getEquationOfLineSolution(vector <returnType> v1,vector <returnType> v2,
                                              vector <returnType> &basePoint,vector <returnType> &directonVector) const
{
    vector<returnType> localFirstVector, localSecondVector;
    if(v1[0] != 0){
        this->mulConstantInEquation(v1,4,v2[0]);
        this->mulConstantInEquation(v2,4,v1[0]);
        this->subTwoSameSizeEquations(v1,4,v2);
    }
    if(v1[1] != 0){
        this->mulConstantInEquation(v1,4,v2[0]);
        this->mulConstantInEquation(v2,4,v1[0]);
        this->subTwoSameSizeEquations(v1,4,v2);
    }
    /* ToDo:: get the equation */
}

vector<returnType> MathFunctions::solveThreeEquationsHaveThreeVariables(vector<returnType> v1,vector <returnType> v2,vector <returnType> v3) const
{
    /* Solve using Gaussian elimination theory */
    static vector<returnType>  intersectionPoint, localFirstVector, localSecondVector,localThirdVector,
                               lineSolutionBasePoint,lineSolutionVectorDirection;
    returnType x,y,z,mul_num;
    operator ^(localFirstVector,v1);
    operator ^(localSecondVector,v2);
    operator ^(localThirdVector,v3);
    /* eliminate x from the first equation */
    if(v1[0] != 0){
        mul_num = localFirstVector[0];
        this->mulConstantInEquation(localFirstVector,4,localSecondVector[0]);
        this->mulConstantInEquation(localSecondVector,4,mul_num);
        this->subTwoSameSizeEquations(localFirstVector,4,localSecondVector);
    }
    /* eliminate x from the second equation */
    if(v2[0] != 0){
        mul_num = localSecondVector[0];
        this->mulConstantInEquation(localSecondVector,4,localThirdVector[0]);
        this->mulConstantInEquation(localThirdVector,4,mul_num);
        this->subTwoSameSizeEquations(localSecondVector,4,localThirdVector);
    }
    /* Eliminate y from the first equation */
    if(v1[1] != 0){
        mul_num = localFirstVector[1];
        this->mulConstantInEquation(localFirstVector,4,localSecondVector[1]);
        this->mulConstantInEquation(localSecondVector,4,mul_num);
        this->subTwoSameSizeEquations(localFirstVector,4,localSecondVector);
    }
    /* calculate z from the first equation */
    try{
        z = localFirstVector[3]/localFirstVector[2];
        if(localFirstVector[2] == 0 && localFirstVector[3] != 0){
            throw 0;
        }else if(localFirstVector[2] == 0 && localFirstVector[3] == 0){
            throw 1;
        }
    }catch(int num){
        if(num == 0)
            cout << "This equation has no solution" << endl;
        else if(num == 1){
            this->getEquationOfLineSolution(localFirstVector,localSecondVector,lineSolutionBasePoint,lineSolutionVectorDirection);
            cout << "This equation has line solution" << endl;
        }
        return intersectionPoint;
    }
    /* refill equations */
    localFirstVector.clear();
    localSecondVector.clear();
    localThirdVector.clear();
    operator ^(localFirstVector,v1);
    operator ^(localSecondVector,v2);
    operator ^(localThirdVector,v3);
    /* eliminate x from the first equation */
    if(v1[0] != 0){
        mul_num = localFirstVector[0];
        this->mulConstantInEquation(localFirstVector,4,localSecondVector[0]);
        this->mulConstantInEquation(localSecondVector,4,mul_num);
        this->subTwoSameSizeEquations(localFirstVector,4,localSecondVector);
    }
    /* calculate y */
    try{
    y = (localFirstVector[3] - (localFirstVector[2]*z) ) / localFirstVector[1];
        if(localFirstVector[1] == 0 && (localFirstVector[3] - (localFirstVector[2]*z) ) != 0){
                throw 0;
        }else if(localFirstVector[1] == 0 && (localFirstVector[3] - (localFirstVector[2]*z) ) == 0){
                throw 1;
        }
    }catch(int num){
        if(num == 0)
            cout << "This equation has no solution" << endl;
        else if(num == 1)
            cout << "This equation has line solution" << endl;
        return intersectionPoint;
    }
    /* refill equations */
    localFirstVector.clear();
    localSecondVector.clear();
    localThirdVector.clear();
    operator ^(localFirstVector,v1);
    operator ^(localSecondVector,v2);
    operator ^(localThirdVector,v3);
    /* calculate x */
    try{
    if(v1[0] != 0){
        x = (localFirstVector[3] - (localFirstVector[2]*z) - (localFirstVector[1]*y)) / localFirstVector[0];
    }else if(v2[0] != 0){
        this->swapTwoEquations(localFirstVector,localSecondVector);
        x = (localFirstVector[3] - (localFirstVector[2]*z) - (localFirstVector[1]*y)) / localFirstVector[0];
    }else if(v3[0] != 0){
        this->swapTwoEquations(localFirstVector,localThirdVector);
        x = (localFirstVector[3] - (localFirstVector[2]*z) - (localFirstVector[1]*y)) / localFirstVector[0];
    }
        if(localFirstVector[0] == 0 && (localFirstVector[3] - (localFirstVector[2]*z) - (localFirstVector[1]*y)) != 0){
            throw 0;
        }else if(localFirstVector[0] == 0 && (localFirstVector[3] - (localFirstVector[2]*z) - (localFirstVector[2]*y)) == 0){
            throw 1;
        }
    }catch(int num){
        if(num == 0)
            cout << "This equation has no solution" << endl;
        else if(num == 1)
            cout << "This equation has line solution" << endl;
        return intersectionPoint;
    }
    intersectionPoint.push_back(x);
    intersectionPoint.push_back(y);
    intersectionPoint.push_back(z);
    return intersectionPoint;
}

