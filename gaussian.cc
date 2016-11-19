#include <iostream>
#include <math.h>
#include <cmath>
#include "Eigen/Dense"

using Eigen::MatrixXd;
using Eigen::DiagonalMatrix;

double pi = 3.14159;
double e = 2.71828;

class Gaussian
{
  public:
    void fitData(const MatrixXd &data){
      setMean(computeMean(data));
      setCovar(computeCovar(data));
    }

    void setMean(const MatrixXd &mean_in){
      mean = mean_in;
    }

    void setCovar(const MatrixXd &covar_in){
      covar = covar_in;

    }

    MatrixXd getMean(){
      return mean;
    }

    MatrixXd getCovar(){
      return covar;
    }

    double log_likelihood(const MatrixXd &vector){
      double twopi = pow( 2 * pi, double(vector.cols()) / 2);
      double covar_determinant = pow( double(covar.determinant()), 1/2);
      double multiplier = 1/(twopi * covar_determinant);
      double l_multiplier = log(multiplier);
      printf("The log multiplier is %f \n", l_multiplier);
      MatrixXd covar_inverse = covar.inverse();
      double exponent = -0.5 * ((vector - mean) * covar_inverse * (vector - mean).transpose())(0);
      printf("The exponent is %f \n", exponent);
      printf("The log likelihood is %f \n", l_multiplier  + exponent);
      printf("The likelihood is %f \n", exp(l_multiplier  + exponent));

      return (l_multiplier + exponent);

      //take +and - 0.0000001, and perform the integral / use the cdf (??)

    }

  private:

    MatrixXd mean;
    MatrixXd covar;
    MatrixXd computeMean(const MatrixXd &data)
    {
      MatrixXd mean = data.colwise().mean();
      return mean;
    }

    MatrixXd computeCovar(const MatrixXd &data)
    {
      MatrixXd centered = data.rowwise() - data.colwise().mean();
      MatrixXd devscoresums = centered.transpose() * centered;
      MatrixXd covar = devscoresums / double(data.rows() - 1);

      return covar;
    }

};

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
    new_gaussian.log_likelihood(new_gaussian.getMean());
    return 0;
}
