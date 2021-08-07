
#ifndef LINEAR_ALGEV_LIB_H_
#define LINEAR_ALGEV_LIB_H_

#include <iostream>
#include <vector>
#include <math.h>
#include <exception>

#define PI 3.14159

typedef double vect_input_tst;

class Vector_Operations{
private:

protected:

public:
Vector_Operations();
~Vector_Operations();
friend class Lines_Operations;
friend class plane;
std::vector<vect_input_tst> Add_2_Vectors(std::vector <vect_input_tst> Vect1,std::vector <vect_input_tst> Vect2) const;
std::vector<vect_input_tst> Sub_2_Vectors(std::vector <vect_input_tst> Vect1,std::vector <vect_input_tst> Vect2) const;
std::vector<vect_input_tst> Vector_Scaler_Mul(std::vector <vect_input_tst> Vect1,vect_input_tst scaler_val) const;
vect_input_tst Get_Vector_Magnitde(std::vector<vect_input_tst> Vect) const;
std::vector<vect_input_tst> Get_Vector_Direction(std::vector<vect_input_tst> Vect) const;
vect_input_tst Calc_VectorsDotProduct(std::vector <vect_input_tst> Vect1,std::vector <vect_input_tst> Vect2,int shortest_angle) const;
vect_input_tst Calc_VectorsDotProduct(std::vector <vect_input_tst> Vect1,std::vector <vect_input_tst> Vect2) const;
vect_input_tst* Calc_VectorsAngle_RadDeg(std::vector <vect_input_tst> Vect1,std::vector <vect_input_tst> Vect2) const;
bool IsVectorsParallel(std::vector <vect_input_tst> Vect1,std::vector <vect_input_tst> Vect2) const;
bool IsVectorsOrthognal(std::vector <vect_input_tst> Vect1,std::vector <vect_input_tst> Vect2) const;
std::vector<vect_input_tst> NormalizeVector(std::vector <vect_input_tst> Vect1) const;
std::vector<vect_input_tst> GetProjectionVector(std::vector <vect_input_tst> Vect1,std::vector <vect_input_tst> Vect2) const;
std::vector<vect_input_tst> GetOrthognalVector(std::vector <vect_input_tst> Vect1,std::vector <vect_input_tst> Vect2) const;
std::vector<vect_input_tst> CalcCrossProduct(std::vector <vect_input_tst> Vect1,std::vector <vect_input_tst> Vect2) const;
vect_input_tst RectAreaBetweenTwoVectors(std::vector <vect_input_tst> Vect1,std::vector <vect_input_tst> Vect2) const;
vect_input_tst TriangleAreaOfTwoVectors(std::vector <vect_input_tst> Vect1,std::vector <vect_input_tst> Vect2) const;
};

#endif
