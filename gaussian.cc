#include <iostream>
#include "Eigen/Dense"

using Eigen::MatrixXd;
using Eigen::DiagonalMatrix;
using Eigen::Dynamic;

// typedef DiagonalMatrix<double, Dynamic, Dynamic> DiagonalMatrixXd;

MatrixXd mean(const MatrixXd &data)
{
  MatrixXd mean = data.colwise().mean();

  return mean;
}

MatrixXd covar(const MatrixXd &data)
{
  MatrixXd centered = data.rowwise() - data.colwise().mean();
  // MatrixXd identity = MatrixXd::Identity(data.cols(), data.cols());

  // MatrixXd centered = data - (identity * data.colwise().mean());

  MatrixXd devscoresums = centered.transpose() * centered;
  MatrixXd covar = devscoresums / double(data.rows() - 1);
  // MatrixXd covar = (centered.adjoint() * centered) / double(data.rows());

  return covar;
}

// Eigen::VectorXd covar(MatrixXd data)
// {
//
//
//     return mean;
// }
// Eigen::VectorXd sdev(MatrixXd data)
// {
//     Eigen::VectorXd mean = mean(data);
//     Eigen::VectorXd sum = Eigen::VectorXd::Zero(data.cols());
//     for (int i=0; i < data.rows(); i++){
// 	sum = sum + (data.row(i).transpose() - mean) ** 2;
//     }
//
//     Eigen::VectorXd sdev = sum / data.rows();
//
//     return sdev;
// }

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
    std::cout << covar(test) << std::endl;
    return 0;
}
