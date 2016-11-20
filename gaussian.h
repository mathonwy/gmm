#ifndef GAUSSIAN_H
#define GAUSSIAN_H

static const double pi = 3.14159;
static const double e = 2.71828;

class Gaussian
{
  public:
    void fitData(const Eigen::MatrixXd &data);

    void setMean(const Eigen::MatrixXd &mean_in);

    void setCovar(const Eigen::MatrixXd &covar_in);

    Eigen::MatrixXd getMean();

    Eigen::MatrixXd getCovar();

    double getLogLikelihood(const Eigen::MatrixXd &vector);

  private:

    Eigen::MatrixXd mean;
    Eigen::MatrixXd covar;

    Eigen::MatrixXd computeMean(const Eigen::MatrixXd &data);

    Eigen::MatrixXd computeCovar(const Eigen::MatrixXd &data);

    double computeLogLikelihood(const Eigen::MatrixXd &vector);
};


#endif
