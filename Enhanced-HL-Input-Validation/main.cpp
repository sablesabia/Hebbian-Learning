//
//  main.cpp
//  Enhanced-HL-Input-Validation
//
//  Created by Daynesha Parker on 1/24/25.
//

#include <iostream>
#include <vector>
#include <limits> // For input validation

using namespace std;

// Function to get a valid floating-point input (e.g., learning rate)
double getValidDoubleInput(string prompt, double minVal, double maxVal) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        
        if (cin.fail() || value < minVal || value > maxVal) {
            cout << "Invalid input! Please enter a number between " << minVal << " and " << maxVal << ".\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return value;
}

// Function to get a valid integer input (e.g., number of iterations)
int getValidIntInput(string prompt, int minVal) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        
        if (cin.fail() || value < minVal) {
            cout << "Invalid input! Please enter an integer greater than or equal to " << minVal << ".\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            break;
        }
    }
    return value;
}

// Function to get valid vector inputs (if applicable)
vector<double> getValidVectorInput(int size) {
    vector<double> vec(size);
    for (int i = 0; i < size; i++) {
        cout << "Enter value for element " << i + 1 << ": ";
        while (!(cin >> vec[i])) {
            cout << "Invalid input! Please enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Enter value for element " << i + 1 << ": ";
        }
    }
    return vec;
}

// Hebbian Learning function (simplified)
void hebbianLearning() {
    cout << "=== Hebbian Learning Algorithm ===\n";
    
    // Get validated inputs
    double learningRate = getValidDoubleInput("Enter learning rate (0.0 - 1.0): ", 0.0, 1.0);
    int iterations = getValidIntInput("Enter number of iterations: ", 1);
    
    cout << "\nLearning rate: " << learningRate << "\n";
    cout << "Iterations: " << iterations << "\n";
    
    // Example: Getting vector inputs (adjust size as needed)
    int vectorSize = getValidIntInput("Enter size of input vector: ", 1);
    vector<double> inputVector = getValidVectorInput(vectorSize);
    
    cout << "\nInput vector: ";
    for (double val : inputVector) {
        cout << val << " ";
    }
    cout << "\n";
    
    // Add Hebbian learning logic here
}

int main() {
    hebbianLearning();
    return 0;
}
