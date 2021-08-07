#include <iostream>
#include "Vectors.h"
#include "Lines.h"
#include "Math_Solutions.h"
#include "plane.h"
#include "Matrices.h"

using namespace std;

int main()
{

    Vector_Operations vect_op_1;
    std::vector <vect_input_tst> first_vect;
    std::vector <vect_input_tst> second_vect;
    std::vector <vect_input_tst> result_vect;
    first_vect.push_back(1.5);
    first_vect.push_back(9.547);
    first_vect.push_back(3.691);
    second_vect.push_back(-6.007);
    second_vect.push_back(0.124);
    second_vect.push_back(5.772);
    result_vect = vect_op_1.Add_2_Vectors(first_vect,second_vect);
    for(int counter = 0; counter < result_vect.size();counter++){
       cout << result_vect[counter] << endl;
    }
    result_vect = vect_op_1.Sub_2_Vectors(first_vect,second_vect);
    for(int counter = 0; counter < result_vect.size();counter++){
       cout << result_vect[counter] << endl;
    }
    result_vect = vect_op_1.Vector_Scaler_Mul(first_vect,5);
    for(int counter = 0; counter < result_vect.size();counter++){
       cout << result_vect[counter] << endl;
    }

    vect_input_tst vector_magnitude = vect_op_1.Get_Vector_Magnitde(first_vect);
    cout << vector_magnitude << endl;

    cout << "vector direction = " << endl;
    result_vect = vect_op_1.Get_Vector_Direction(first_vect);
    for(int counter = 0; counter < result_vect.size();counter++){
       cout << result_vect[counter] << endl;
    }
    cout << "==================== Dot Product ======================" << endl;
    cout << vect_op_1.Calc_VectorsDotProduct(first_vect,second_vect,180) << endl;
    cout << vect_op_1.Calc_VectorsDotProduct(first_vect,second_vect) << endl;
    vect_input_tst *angle = vect_op_1.Calc_VectorsAngle_RadDeg(first_vect,second_vect);
    cout << *(angle + 0) << endl;
    cout << *(angle + 1) << endl;
    if(vect_op_1.IsVectorsOrthognal(first_vect,second_vect))
        cout << "The two vectors are orthogonal" << endl;
    else
        cout << "No orthogonal vectors" << endl;

    if(vect_op_1.IsVectorsParallel(first_vect,second_vect))
        cout << "The two vectors are parallel" << endl;
    else
        cout << "No parallel vectors" << endl;

    cout << "==================== Projection ======================" << endl;
    result_vect = vect_op_1.GetProjectionVector(first_vect,second_vect);
    for(int counter = 0; counter < result_vect.size();counter++){
       cout << result_vect[counter] << endl;
    }

    cout << "==================== Orthogonal vector ======================" << endl;
    result_vect = vect_op_1.GetOrthognalVector(first_vect,second_vect);
    for(int counter = 0; counter < result_vect.size();counter++){
       cout << result_vect[counter] << endl;
    }

    cout << "==================== Cross vector ======================" << endl;
    result_vect = vect_op_1.CalcCrossProduct(first_vect,second_vect);
    for(int counter = 0; counter < result_vect.size();counter++){
       cout << result_vect[counter] << endl;
    }

    cout << "Rect Area = " << vect_op_1.RectAreaBetweenTwoVectors(first_vect,second_vect) << endl;
    cout << "Rect Area = " << vect_op_1.TriangleAreaOfTwoVectors(first_vect,second_vect) << endl;
    cout << "==================== Lines ======================" << endl;
    Lines_Operations lineObject(result_vect,0);
    if(lineObject.isTwoLinesEqual(4.046,2.836,1.21,10.115,7.09,3.025))
        cout << "Two lines Are equal" << endl;
    else
        cout << "Not equal lines" << endl;
    if(lineObject.is2LinesIntersected(1.182,5.562,6.744,1.773,8.343,9.525))
        cout << "Two intersected lines" << endl;
    else
        cout << "No intersected lines" << endl;
//    shared_ptr<pointsType[]> (ptr) = make_shared<pointsType[]>(lineObject.GetIntersectedPoints(7.204,3.182,8.68,8.172,4.114,9.883));

    /********************************************************* Planes ***************************************************************/
    std::vector<returnType> planeVect1, planeVect2,planeVect3,returnVect;
    planeVect1.push_back(0);
    planeVect1.push_back(1);
    planeVect1.push_back(-1);
    planeVect1.push_back(2);
    planeVect2.push_back(1);
    planeVect2.push_back(-1);
    planeVect2.push_back(1);
    planeVect2.push_back(2);
    planeVect3.push_back(3);
    planeVect3.push_back(-4);
    planeVect3.push_back(1);
    planeVect3.push_back(1);
    plane planeObj ;
    if(planeObj.isTwoPlanesParallel(planeVect1,planeVect2))
      cout << "Two parallel planes" << endl;
    else
      cout <<  "Not parallel planes" << endl;

    if(planeObj.isTwoPlanesEqual(planeVect1,planeVect2))
      cout << "Two equal planes" << endl;
    else
      cout <<  "Not equal planes" << endl;

      MathFunctions Mf1;
      returnVect = Mf1.solveThreeEquationsHaveThreeVariables(planeVect1,planeVect2,planeVect3);
      for(int i = 0;i<returnVect.size();i++)
        cout << "Vect[" << i << "] = " << returnVect[i] << endl;

    /**************************************** Matrices ****************************************/
    Matrices mx1;
    std::vector<returnType> matriecsVect1,matriecsVect2,matriecsVect3,resultMatriecs;
    matriecsVect1.push_back(17);
    matriecsVect1.push_back(25);
    matriecsVect1.push_back(6);
    matriecsVect1.push_back(2);
    matriecsVect1.push_back(6);
    matriecsVect1.push_back(1);
    matriecsVect1.push_back(97);
    matriecsVect1.push_back(4);
    matriecsVect1.push_back(80);
    matriecsVect1.push_back(8);
    matriecsVect1.push_back(54);
    matriecsVect1.push_back(15);
   // mx1.matricesScalarMul(matriecsVect1,2);
    mx1.printMatrices(3,2,matriecsVect1);

    matriecsVect2.push_back(3);
    matriecsVect2.push_back(25);
    matriecsVect2.push_back(9);
    matriecsVect2.push_back(2);
    matriecsVect2.push_back(4);
    matriecsVect2.push_back(7);
    matriecsVect2.push_back(15);
    matriecsVect2.push_back(6);
    matriecsVect2.push_back(92);
    matriecsVect2.push_back(17);
    matriecsVect2.push_back(31);
    matriecsVect2.push_back(18);
    matriecsVect2.push_back(0);
    matriecsVect2.push_back(11);
    matriecsVect2.push_back(8);
    mx1.printMatrices(3,5,matriecsVect2);
    std::cout << "=================" << std::endl;
    mx1.transposeMatrices(3,5,matriecsVect2);
    mx1.printMatrices(5,3,matriecsVect2);
    //mx1.addTwoMatrices(matriecsVect2,matriecsVect3,matriecsVect1);
    //mx1.printMatrices(2,5,matriecsVect1);
   // mx1.mulTwoMatrices(4,matriecsVect1,matriecsVect2,resultMatriecs);
   // std::cout << "Result of metrics mul = " << std::endl;
   // mx1.printMatrices(3,6,resultMatriecs);
   std::cout << "=================================================" << std::endl;
   std::vector<returnType> identityMatriecs;
   mx1.calculateIdentityMatrix(5,matriecsVect2,identityMatriecs);
   mx1.printMatrices(5,5,identityMatriecs);
   std::cout << "=================================================" << std::endl;
    matriecsVect3.push_back(4);
    matriecsVect3.push_back(7);
    matriecsVect3.push_back(2);
    matriecsVect3.push_back(6);
    vector <returnType> resultMax;
    returnType scale;
    mx1.calculateInverseMatrix(matriecsVect3,resultMax,scale);
    mx1.printMatrices(2,2,resultMax);
    std::cout << scale << std::endl;



    return 0;

}
