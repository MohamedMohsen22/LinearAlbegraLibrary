#ifndef LINES_H_
#define LINES_H_

#include <iostream>
#include <exception>
#include <vector>
#include <math.h>
#include <memory>
#include "Math_Solutions.h"
#include "Vectors.h"

typedef double vectorType;
typedef double pointsType;

class Lines_Operations{
private:

protected:
std::vector<vectorType> lineNormalVector;
pointsType lineConstantTermInLineEq;
public:
Lines_Operations(std::vector<vectorType> normalVector,pointsType constantTermInLineEq=0);
~Lines_Operations();
std::vector<vectorType> formVectorFromLineEq(pointsType A1,pointsType B1,pointsType C1) const;
bool isTwoLinesEqual(pointsType A1,pointsType B1,pointsType C1,pointsType A2,pointsType B2,pointsType C2)const;
bool is2LinesIntersected(pointsType A1,pointsType B1,pointsType C1,pointsType A2,pointsType B2,pointsType C2)const;
//std::vector<vectorType> GetlineBasePoint(std::vector<vectorType> normalVector,pointsType constantTermInLineEq) const;
//std::shared_ptr<pointsType[]> GetIntersectedPoints(pointsType A1,pointsType B1,pointsType C1,pointsType A2,pointsType B2,pointsType C2) const;
};
#endif // LINES_H_
