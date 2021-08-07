#include "Vectors.h"

using namespace std;

Vector_Operations::Vector_Operations(){

}

Vector_Operations::~Vector_Operations(){

}

std::vector<vect_input_tst> Vector_Operations::Add_2_Vectors(std::vector <vect_input_tst> Vect1,std::vector <vect_input_tst> Vect2) const
{
    /* Add each element into the vector with the corresponding element from the second vector */
    vector<vect_input_tst> result_vect;
    int counter;
    for(counter = 0; counter < Vect1.size(); counter++){
        result_vect.push_back(Vect1[counter] + Vect2[counter]);
    }
    return result_vect;
}

std::vector<vect_input_tst> Vector_Operations::Sub_2_Vectors(std::vector <vect_input_tst> Vect1,std::vector <vect_input_tst> Vect2) const
{
    /* Subtract each element into the vector with the corresponding element from the second vector */
    vector<vect_input_tst> result_vect;
    int counter;
    for(counter = 0; counter < Vect1.size(); counter++){
        result_vect.push_back(Vect1[counter] - Vect2[counter]);
    }
    return result_vect;
}

std::vector<vect_input_tst> Vector_Operations::Vector_Scaler_Mul(std::vector <vect_input_tst> Vect1,vect_input_tst scaler_val) const
{
    /* Multiply each element into the vector by the scaler value */
    vector<vect_input_tst> result_vect;
    int counter;
    for(counter = 0; counter < Vect1.size(); counter++){
        result_vect.push_back(Vect1[counter] * scaler_val);
    }
    return result_vect;
}

vect_input_tst Vector_Operations::Get_Vector_Magnitde(std::vector<vect_input_tst> Vect) const
{
    /* by applying rule of Pythagoras the vector magnitude is the root of the square of sides  */
    vect_input_tst sum = 0;
    for(int counter =0;counter < Vect.size();counter++){
        sum += (static_cast<vect_input_tst> (Vect[counter]) * static_cast<vect_input_tst> (Vect[counter]));
    }
    return sqrt(sum);
}

std::vector<vect_input_tst> Vector_Operations::Get_Vector_Direction(std::vector<vect_input_tst> Vect) const
{
    /* The vector direction equals (1/ the vector magnitude) multiplied by the vector */
    vector<vect_input_tst> Vector_direction ;
    vect_input_tst normalize_scaler ;
    try{
        normalize_scaler = (1/this->Get_Vector_Magnitde(Vect));
    }catch(exception& e){
        cout << "Can't calculate the direction of the zero vector" << endl;
    }
    for(int counter = 0;counter < Vect.size(); counter++){
        Vector_direction.push_back( normalize_scaler * Vect[counter]) ;
    }
    return Vector_direction;
}

vect_input_tst Vector_Operations::Calc_VectorsDotProduct(std::vector <vect_input_tst> Vect1,std::vector <vect_input_tst> Vect2,int shortest_angle) const
{
    /* To calculate the dot product calculate the magnitude of the two product multiplied by the cosine of
       the shortest angle between them */
    return(this->Get_Vector_Magnitde(Vect1) * this->Get_Vector_Magnitde(Vect2) * cos(shortest_angle));
}

vect_input_tst Vector_Operations::Calc_VectorsDotProduct(std::vector <vect_input_tst> Vect1,std::vector <vect_input_tst> Vect2) const
{
    /* To calculate the dot product multiply every element of the first vector with the corresponding one from the second
       and sum the result */
    vect_input_tst resultofDotProduct = 0;
    for(int counter = 0;counter <Vect1.size();counter++){
        resultofDotProduct += Vect1[counter] * Vect2[counter];
    }
    return resultofDotProduct;
}

vect_input_tst* Vector_Operations::Calc_VectorsAngle_RadDeg(std::vector <vect_input_tst> Vect1,std::vector <vect_input_tst> Vect2) const
{
    /* To get the shortest angle between two vectors is equal arch cosine the dot product between them / the multiplication of their magnitude */
    static vect_input_tst ShortestAngleRadDeg[2];
    ShortestAngleRadDeg[0] = acos((this->Calc_VectorsDotProduct(Vect1,Vect2) / ((this->Get_Vector_Magnitde(Vect1)*this->Get_Vector_Magnitde(Vect2)))));
    ShortestAngleRadDeg[1] = ShortestAngleRadDeg[0] * (static_cast<vect_input_tst>(180)/PI);
    return ShortestAngleRadDeg;
}

bool Vector_Operations::IsVectorsParallel(std::vector <vect_input_tst> Vect1,std::vector <vect_input_tst> Vect2) const
{
        /* The vector are parallel when the angle between the vectors are 0 or PI or one of them = 0 */
        vect_input_tst *VectorsAngle = this->Calc_VectorsAngle_RadDeg(Vect1,Vect2);
        if(!this->Get_Vector_Magnitde(Vect1) || !this->Get_Vector_Magnitde(Vect2) || static_cast<int>(VectorsAngle[1]) == 0 || static_cast<int>(VectorsAngle[1]) == 180)
            return 1;
        else
            return 0;
}

bool Vector_Operations::IsVectorsOrthognal(std::vector <vect_input_tst> Vect1,std::vector <vect_input_tst> Vect2) const
{
    /* The vector are orthogonal when the angle between the vectors are 90 so when they have dot product */
    return !(ceil(this->Calc_VectorsDotProduct(Vect1,Vect2)));
}

std::vector<vect_input_tst> Vector_Operations::NormalizeVector(std::vector <vect_input_tst> Vect1) const
{
    /* Vector normalization = (1/Vector Magnitude) * Vector */
    vect_input_tst VectorMagnitude = this->Get_Vector_Magnitde(Vect1);
    std::vector<vect_input_tst> normalizedVecrtor;
    try{
       normalizedVecrtor = (this->Vector_Scaler_Mul(Vect1,static_cast<vect_input_tst>(1/VectorMagnitude)));
    }catch(exception &e){
        cout << "Can't divide by 0" << endl;
    }
    return normalizedVecrtor;
}

std::vector<vect_input_tst> Vector_Operations::GetProjectionVector(std::vector <vect_input_tst> Vect1,std::vector <vect_input_tst> Vect2) const
{
    /* To get projection of vector Vect1 on vector Vect2 you should multiply the vector * vector normalization * vector normalization */
    std::vector<vect_input_tst> projectionVector = this->Vector_Scaler_Mul(this->NormalizeVector(Vect2),this->Calc_VectorsDotProduct(Vect1,this->NormalizeVector(Vect2)));
    return projectionVector;

}

std::vector<vect_input_tst> Vector_Operations::GetOrthognalVector(std::vector <vect_input_tst> Vect1,std::vector <vect_input_tst> Vect2) const
{
    /* To get the Orthogonal vector = Vector - parallel vector */
    std::vector<vect_input_tst> OrthognalVector = this->Sub_2_Vectors(Vect1,Vect2);
    return OrthognalVector;
}

std::vector<vect_input_tst> Vector_Operations::CalcCrossProduct(std::vector <vect_input_tst> Vect1,std::vector <vect_input_tst> Vect2) const
{
    std::vector<vect_input_tst> crossProductVector ;
    if(Vect1.size() == 3){
        crossProductVector.push_back((Vect1[1] * Vect2[2]) - (Vect2[1] * Vect1[2]));
        crossProductVector.push_back(-1 * ((Vect1[0] * Vect2[2]) - (Vect2[0] * Vect1[2])));
        crossProductVector.push_back((Vect1[0] * Vect2[1]) - (Vect2[0] * Vect1[1]));
    }
    return crossProductVector;

}

vect_input_tst Vector_Operations::RectAreaBetweenTwoVectors(std::vector <vect_input_tst> Vect1,std::vector <vect_input_tst> Vect2) const
{
    /* To calc the area between two vectors, calc the magnitude of the cross product of the two vectors */
    return this->Get_Vector_Magnitde(this->CalcCrossProduct(Vect1,Vect2));
}

vect_input_tst Vector_Operations::TriangleAreaOfTwoVectors(std::vector <vect_input_tst> Vect1,std::vector <vect_input_tst> Vect2) const
{
    /* To calc the area between two vectors, calc the half area of the rectangle between them */
    return (.5 * this->RectAreaBetweenTwoVectors(Vect1,Vect2));
}
