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
    double getLogLikelihood(const Eigen::MatrixXd &vector);

    GaussianMixtureModel();
    GaussianMixtureModel(int components);
    GaussianMixtureModel(int components, const Eigen::MatrixXd &data);

  private:

    std::vector<MixtureComponent> components;

    void addComponent(const MixtureComponent &new_component);
    void initialize(const Eigen::MatrixXd &data);
    void train(const Eigen::MatrixXd &data);

    void kMeans(const Eigen::MatrixXd &data);
    void eStep(const Eigen::MatrixXd &data);
    void mStep(const Eigen::MatrixXd &data);
    void eM(const Eigen::MatrixXd &data);
};


#endif
