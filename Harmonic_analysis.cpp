//برنامه ای  برای حل مسائل تحلیل هارمونیک
//حل مسائل 1.81 1.82 1.83 1.84 کتاب ارتعاشات مکانیکی رائو ویرایش 4
//
// example :
// Determine the first M harmonics of the Fourier series based on the given table
// 
// M = 5
//#######################################################################
//moment , i                   time,t                         pressure //
//    0                          0                                0    //
//    1                          0.01                             20   //
//    2                          0.02                             34   // 
//    3                          0.03                             42   //
//    4                          0.04                             49   //
//    5                          0.05                             53   //
//    6                          0.06                             70   //
//    7                          0.07                             60   //
//    8                          0.08                             36   //
//    9                          0.09                             22   // 
//    10                         0.10                             16   //
//    11                         0.11                             7    //
//    12                         0.12                             0    //
//#######################################################################
#include <iostream>
#include <cmath>
#include <vector>

#define M_PI 3.14159265358979323846

using namespace std;

int main() {
    // Variables
    int N;  // number of data points
    int M;  // number of harmonics
    float T;  // period
    float omega;
    float A_0 = 0;
    vector<float> A(M, 0.0);
    vector<float> B(M, 0.0);
    vector<float> t;
    vector<float> x;
    double constant;

    cout << "Please input the number of data points (N):\n";
    cin >> N;
    cout << "Please input the number of harmonics you want (M):\n";
    cin >> M;
    cout << "Please input the period (T):\n";
    cin >> T;

    // Determine constant
    constant = 2.0 / N;

    // Determine omega
    omega = (2 * M_PI) / T;

    // Input x[i], t[i]
    t.resize(N);
    x.resize(N);
    cout << "Please input the values of x[i] for i = 0, ..., N-1:\n";
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }
    cout << "Please input the values of t[i] for i = 0, ..., N-1:\n";
    for (int j = 0; j < N; j++) {
        cin >> t[j];
    }

    // Determine A_0
    for (int k = 0; k < N; k++) {
        A_0 += x[k];
    }
    A_0 = (A_0 * constant) / 2;

    // Determine A_n and B_n
    for (int n = 1; n <= M; n++) {
        for (int j = 0; j < N; j++) {
            A[n - 1] += x[j] * cos(n * omega * t[j]);
            B[n - 1] += x[j] * sin(n * omega * t[j]);
        }
        A[n - 1] *= constant;
        B[n - 1] *= constant;
    }

    // Output the results
    cout << "The Fourier coefficients are:\n";
    cout << "A_0 = " << A_0 << endl;
    for (int n = 1; n <= M; n++) {
        cout << "A_" << n << " = " << A[n - 1] << ", B_" << n << " = " << B[n - 1] << endl;
    }

    // Calculate the Fourier series at each time point
    vector<float> P(N, A_0);
    for (int i = 0; i < N; i++) {
        for (int n = 1; n <= M; n++) {
            P[i] += A[n - 1] * cos(n * omega * t[i]) + B[n - 1] * sin(n * omega * t[i]);
        }
        cout << "P[" << i << "] = " << P[i] << " at t = " << t[i] << endl;
    }

    return 0;
}
//code by Matin
//telegram id : @matinkoohi