#include "plane.h"

plane::plane()
{

}

plane::~plane()
{

}

bool plane::isTwoPlanesParallel(vector<returnType> v1,vector<returnType> v2) const
{
    /* if the angle between two planes = 0 or 180 then the two planes are parallel */
    Vector_Operations vop1;
    return vop1.IsVectorsParallel(v1,v2);
}

bool plane::isTwoPlanesEqual(vector<returnType> v1,vector<returnType> v2) const
{
    /* To check if the lines are similar so they should verify the same equation of the plane
       Ax + By + Cz = K */
      MathFunctions MathObj;
    try{
        return(static_cast<returnType>(MathObj.ceilThreeDP(v1[0]/v2[0])) == static_cast<returnType>(MathObj.ceilThreeDP(v1[1]/v2[1]))
               && (static_cast<returnType>(MathObj.ceilThreeDP(v1[0]/v2[0]))) == static_cast<returnType>(MathObj.ceilThreeDP(v1[2]/v2[2]))
               && (static_cast<returnType>(MathObj.ceilThreeDP(v1[0]/v2[0]))) == static_cast<returnType>(MathObj.ceilThreeDP(v1[3]/v2[3])));
    }catch(exception& e){
        cout << "Can't divide by zero" << endl;
        return 0;
    }
}
