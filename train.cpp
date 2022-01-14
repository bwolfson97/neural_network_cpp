/*
Trains NN and saves parameters to file.
*/

#include <iosteam>

// Data Hyperparameters
constexpr int kNumSamples = 10;
constexpr double kTrueSlope = 3;
constexpr double kTrueIntercept = -5;

// Learning Hyperparameters
constexpr int kNumEpochs = 5;
constexpr double lr = 1e-1;

// A simple feature-target pair.
struct Sample {
    double x;
    double y;
};

vector<Sample> load_data() {
    vector<Sample> data(kNumSamples);
    for (int i = 0; i < data.size(); i++) {
        sample.x = i;
        sample.y = kTrueSlope * x + kTrueIntercept;
    }
    return data;
}

class MSE {
    
};

// Stores gradients of loss wrt. params of `Model` class.
struct Gradients {
    double dL_dm;
    double dL_db;
};

class Model {
    public:
    double predict(double x) {

    }
    Gradients compute_gradients(const MSE loss_obj&, double pred, double y) {
        
    }

    private:
    double last_x_;
};

int main() {
    vector<Sample> data(load_data());
    Model model(1, 1);
    MSE loss_obj;

    // Train
    for (int i = 0; i < kNumEpochs; i++) {
        std::cout << "epoch " << i + 1 << std::endl;
        // Do pass over all samples in dataset
        for (const auto sample& : data) {
            // 1. Predict
            auto pred = model.predict(sample.x());
            // 2. Compute loss
            auto loss = loss_obj.compute_loss(pred, sample.y());
            std::cout << "\tloss: " << loss << std::endl;
            // 3. Compute gradients
            auto grads = model.compute_grads(loss_obj, pred, sample.y());
            // 4. Step parameters
            model.step_params(lr, grads);
        }
    }
}