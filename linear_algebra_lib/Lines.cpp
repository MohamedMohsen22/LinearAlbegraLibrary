#include "Lines.h"

using namespace std;


Lines_Operations::Lines_Operations(std::vector<vectorType> normalVector,pointsType constantTermInLineEq):lineNormalVector(normalVector),lineConstantTermInLineEq(constantTermInLineEq)
{
}

Lines_Operations::~Lines_Operations()
{

}

std::vector<vectorType> Lines_Operations::formVectorFromLineEq(pointsType A1,pointsType B1,pointsType C1) const
{
    /* The line should obey the line equation y = mx+b, so rVector = roVector + t * vParallelVector
       and zero vector is parallel to each vector so the vector is rpointVector */
    std::vector<vectorType> formedVector ;
    formedVector.push_back(A1);
    formedVector.push_back(B1);
    formedVector.push_back(C1);
    return formedVector;
}

bool Lines_Operations::isTwoLinesEqual(pointsType A1,pointsType B1,pointsType C1,pointsType A2,pointsType B2,pointsType C2)const
{
    /* To check if the lines are similar so they should verify the same equation of the line
       Ax + By = C */
      MathFunctions MathObj;
    try{
        return(static_cast<pointsType>(MathObj.ceilThreeDP(A1/A2)) == static_cast<pointsType>(MathObj.ceilThreeDP(B1/B2))
               && static_cast<pointsType>(MathObj.ceilThreeDP(A1/A2)) == static_cast<pointsType>(MathObj.ceilThreeDP(C1/C2)));
    }catch(exception& e){
        cout << "Can't divide by zero" << endl;
        return 0;
    }


}

bool Lines_Operations::is2LinesIntersected(pointsType A1,pointsType B1,pointsType C1,pointsType A2,pointsType B2,pointsType C2)const
{
    /* Two intersected lines means no parallel lines means they can't be divided by a constant or scaler*/
    return (!this->isTwoLinesEqual(A1,B1,C1,A2,B2,C2));
}

/*
std::vector<vectorType> Lines_Operations::GetlineBasePoint(std::vector<vectorType> normalVector,pointsType constantTermInLineEq) const
{
    std::vector<vectorType> lineBasePoint;
}
*/
#if 0
shared_ptr<pointsType[]> Lines_Operations::GetIntersectedPoints(pointsType A1,pointsType B1,pointsType C1,pointsType A2,pointsType B2,pointsType C2) const
{
    static pointsType sharedArr[2];
    pointsType xIntersectedPoints = (((B2*C1) - (B1*C2)) / ((A1*B2)-(B1*A2)));
    pointsType yIntersectedPoints = (((-1*A2*C1)+A1*C2)/((A1*B2)-(B1*A2)));
    sharedArr[0] = xIntersectedPoints;
    sharedArr[1] = yIntersectedPoints;
    shared_ptr<pointsType[]> returnPtr = make_shared<pointsType[]>(sharedArr);
    cout << "shared ptr = " << *(returnPtr) << endl;
    return returnPtr;
}
#endif
