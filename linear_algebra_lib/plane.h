#ifndef PLANE_H_
#define PLANE_H_

#include <vector>
#include <string>

#include "Math_Solutions.h"
#include "vectors.h"

using namespace std;

class plane{
private:
protected:
public:
    plane();
    ~plane();
    bool isTwoPlanesParallel(vector<returnType> v1,vector<returnType> v2) const;
    bool isTwoPlanesEqual(vector<returnType> v1,vector<returnType> v2) const;
};

#endif // PLANE_H_
