#ifndef GAUSSIAN_MIXTURE_MODEL_H
#define GAUSSIAN_MIXTURE_MODEL_H

class MixtureComponent{

  public:
    double getWeight();
    Eigen::MatrixXd getMean();
    Eigen::MatrixXd getCovar();
    double getLogLikelihood(const Eigen::MatrixXd &vector);
    void setMean(const Eigen::MatrixXd &mean_in);
    void setCovar(const Eigen::MatrixXd &covar_in);

  private:
    Gaussian gaussian;
};

class GaussianMixtureModel
{
  public:

    int trainModel(const Eigen::MatrixXd &data);

    int getNumberComponents();

  private:

    std::vector<MixtureComponent> components;

    void addComponent(const MixtureComponent &new_component);
    void e_m(const Eigen::MatrixXd &data);
};


#endif
