//
//  main.cpp
//  Brain-Inspired Algorithm (Hebbian Learning)
//
//  Created by Daynesha Parker on 1/23/25.
//

#include <iostream>
#include <vector>
#include <iomanip> // For controlling output precision
#include <cstdlib> // For rand()

using namespace std;

class HebbianLearning {
private:
    int numNeurons;
    double learningRate;
    vector<vector<double>> weights;
    
public:
    // Constructor
    HebbianLearning(int neurons, double rate)
        : numNeurons(neurons), learningRate(rate), weights(neurons, vector<double>(neurons, 0.0)) {}
    
    // Initialize weights randomly
    void initializeWeights();
    
    // Display the weight matrix
    void displayWeights() const;
    
    // Train using the Hebbian learning rule
    void train(const vector<vector<int>>& inputPatterns, int epochs);
};

// Define the functions outside the class using scope resolution (::)

void HebbianLearning::initializeWeights() {
    for (size_t i = 0; i < weights.size(); ++i) {
        for (size_t j = 0; j < weights[i].size(); ++j) {
            weights[i][j] = ((double)rand() / RAND_MAX) * 0.1; // Random values between 0 and 0.1
        }
    }
}

void HebbianLearning::displayWeights() const {
    for (const auto& row : weights) {
        for (double w : row) {
            cout << fixed << setprecision(3) << w << "\t";
        }
        cout << endl;
    }
}

void HebbianLearning::train(const vector<vector<int>>& inputPatterns, int epochs) {
    for (int epoch = 1; epoch <= epochs; ++epoch) {
        cout << "\nEpoch " << epoch << ":\n";
        for (const auto& pattern : inputPatterns) {
            for (size_t i = 0; i < numNeurons; ++i) {
                for (size_t j = 0; j < numNeurons; ++j) {
                    weights[i][j] += learningRate * pattern[i] * pattern[j];
                }
            }
        }
        displayWeights();
    }
}

int main() {
    const int numNeurons = 3; // Example with 3 neurons
    const double learningRate = 0.1; // Learning rate (Ƞ)

    // Define input patterns (binary inputs)
    vector<vector<int>> inputPatterns = {
        {1, 0, 1},
        {0, 1, 1},
        {1, 1, 0}
    };

    // Create an instance of HebbianLearning
    HebbianLearning hebbian(numNeurons, learningRate);
    
    // Initialize and display initial weights
    hebbian.initializeWeights();
    cout << "Initial Weights:\n";
    hebbian.displayWeights();
    
    // Train the model
    hebbian.train(inputPatterns, 5); // Train for 5 epochs
    
    return 0;
}
