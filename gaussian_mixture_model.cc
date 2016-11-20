#include <iostream>
#include <math.h>
#include <cmath>
#include "gaussian.h"
#include "Eigen/Dense"

class GaussianMixtureModel
{
  public:

    int trainModel(const MatrixXd &data);
    int getNumberComponents();


};
