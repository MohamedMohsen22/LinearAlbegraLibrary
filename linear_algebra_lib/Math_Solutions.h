#ifndef MATH_SOLUTIONS_H_
#define MATH_SOLUTIONS_H_

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

typedef double returnType ;

class MathFunctions{
private:

protected:

public:
MathFunctions();
~MathFunctions();
friend class Lines_Operations;
returnType ceilThreeDP(returnType inputNumber) const;
void mulConstantInEquation(vector <returnType> &vect,unsigned short vectSize, returnType constant) const;
void subTwoSameSizeEquations(vector <returnType> &vect1,unsigned short vectSize,vector <returnType> vect2) const;
void swapTwoEquations(vector <returnType> &vect1,vector <returnType> &vect2) const;
void getEquationOfLineSolution(vector <returnType> v1,vector <returnType> v2,vector <returnType> &basePoint,vector <returnType> &directonVector) const;
vector<returnType> solveThreeEquationsHaveThreeVariables(vector<returnType> v1,vector <returnType> v2,vector <returnType> v3) const;
};

#endif // MATH_SOLUTIONS_H_
