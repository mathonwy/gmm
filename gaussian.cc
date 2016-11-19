#include <iostream>
#include "Eigen/Dense"

using Eigen::MatrixXd;
using Eigen::DiagonalMatrix;

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

class Gaussian
{
  public:
    void fitData(const MatrixXd &data){


    }

    void setMean(const MatrixXd &mean){


    }

    void setCovar(const MatrixXd &covar){


    }

    void getMean(){

    }

    void getCovar(){

    }

    void likelihood(const MatrixXd data){

    }

  private:

    MatrixXd mean;
    MatrixXd covar;

};

int main()
{

    // MatrixXd test(3, 4);
    // test << 1, 2, 3, 4,
	  //   5, 6, 7, 8,
	  //   9, 10, 11, 12;

    //
    // MatrixXd test(2, 2);
    // test << 5, -1,
    //         2, 0;
    MatrixXd test(5, 3);
    test << 4.0, 2.0, 0.60,
            4.2, 2.1, 0.59,
            3.9, 2.0, 0.58,
            4.3, 2.1, 0.62,
            4.1, 2.2, 0.63;


    std::cout << "There are " << test.rows() << " test vectors." << std::endl;
    // std::cout << mean(test) << std::endl;
    std::cout << computeCovar(test) << std::endl;
    return 0;
}
