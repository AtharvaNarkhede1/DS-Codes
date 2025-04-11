#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);
    cout << "Enter values of x:\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    cout << "Enter values of y:\n";
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    double sum_x = 0, sum_y = 0;
    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
    }

    double mean_x = sum_x / n;
    double mean_y = sum_y / n;

    double std_x = 0, std_y = 0, cov_xy = 0;
    for (int i = 0; i < n; i++) {
        std_x += pow(x[i] - mean_x, 2);
        std_y += pow(y[i] - mean_y, 2);
        cov_xy += (x[i] - mean_x) * (y[i] - mean_y);
    }

    std_x = sqrt(std_x / n);
    std_y = sqrt(std_y / n);
    cov_xy = cov_xy / n;

    double r = cov_xy / (std_x * std_y);
    double b_yx = r * (std_y / std_x); // y on x
    double b_xy = r * (std_x / std_y); // x on y

    double intercept_yx = mean_y - b_yx * mean_x;
    double intercept_xy = mean_x - b_xy * mean_y;

    // Output
    cout << "\nMean of x: " << mean_x << endl;
    cout << "Mean of y: " << mean_y << endl;
    cout << "Standard deviation of x: " << std_x << endl;
    cout << "Standard deviation of y: " << std_y << endl;
    cout << "Covariance of x and y: " << cov_xy << endl;
    cout << "Correlation coefficient (r): " << r << endl;
    cout << "Regression coefficient (y on x): " << b_yx << endl;
    cout << "Regression coefficient (x on y): " << b_xy << endl;
    cout << "Regression line (y on x): y = " << b_yx << "x + " << intercept_yx << endl;
    cout << "Regression line (x on y): x = " << b_xy << "y + " << intercept_xy << endl;

    cout << "\nPress Enter to exit...";
    cin.ignore();
    cin.get();

    return 0;
}