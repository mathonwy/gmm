#include <iostream>
#include <math.h>
#include <cmath>
#include "Eigen/Dense"
#include "gaussian.h"
#include "/usr/local/Cellar/cppunit/1.13.2/include/cppunit/Test.h"

using Eigen::MatrixXd;
using Eigen::DiagonalMatrix;
using namespace CppUnit;

void Gaussian::fitData(const MatrixXd &data){
  Gaussian::setMean(Gaussian::computeMean(data));
  Gaussian::setCovar(Gaussian::computeCovar(data));
}

void Gaussian::setMean(const MatrixXd &mean_in){
  Gaussian::mean = mean_in;
}

void Gaussian::setCovar(const MatrixXd &covar_in){
  Gaussian::covar = covar_in;
}

MatrixXd Gaussian::getMean(){
  return Gaussian::mean;
}

MatrixXd Gaussian::getCovar(){
  return Gaussian::covar;
}

double Gaussian::getLogLikelihood(const MatrixXd &vector){
  return Gaussian::computeLogLikelihood(vector);
}

MatrixXd Gaussian::computeMean(const MatrixXd &data)
{
  MatrixXd mean = data.colwise().mean();
  return mean;
}

MatrixXd Gaussian::computeCovar(const MatrixXd &data)
{
  MatrixXd centered = data.rowwise() - data.colwise().mean();
  MatrixXd devscoresums = centered.transpose() * centered;
  MatrixXd covar = devscoresums / double(data.rows() - 1);

  return covar;
}

double Gaussian::computeLogLikelihood(const MatrixXd &vector){

  return -0.5 * (
                    vector.cols() * log(2 * pi) -
                    log(Gaussian::covar.determinant()) +
                    ((vector - Gaussian::mean) * Gaussian::covar.inverse() * (vector - Gaussian::mean).adjoint())(0)
                );
}


int main()
{
    MatrixXd test(5, 3);
    test << 4.0, 2.0, 0.60,
            4.2, 2.1, 0.59,
            3.9, 2.0, 0.58,
            4.3, 2.1, 0.62,
            4.1, 2.2, 0.63;

    MatrixXd item(1, 3);
    item << 4.1, 2.0, 0.60;


    std::cout << "There are " << test.rows() << " test vectors." << std::endl;

    Gaussian new_gaussian;
    // new_gaussian.fitData(test);
    // std::cout << new_gaussian.getCovar() << std::endl;
    // // std::cout << "The likelihood of the vector " << item << " under the Gaussian is " << new_gaussian.likelihood(item) << std::endl;
    // new_gaussian.log_likelihood(new_gaussian.getMean());

    MatrixXd unit_variance(3,3);
    unit_variance.setIdentity();
    MatrixXd zero_vector = MatrixXd(1, 3);
    zero_vector << 0.0, 0.0, 0.0;
    new_gaussian.setMean(zero_vector);
    new_gaussian.setCovar(unit_variance);
    double log_lik = new_gaussian.getLogLikelihood(new_gaussian.getMean());
    std::cout << new_gaussian.getMean() << std::endl;
    return 0;
}
