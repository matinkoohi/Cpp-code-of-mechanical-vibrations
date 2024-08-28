//program to determine type of damper and determine function points 
// CODE BY MATIN
// tel id: @matinkoohi
// 
// example :
// 
// M = 450 ,K=26519.2 ,C=1000 ,x0=0.539567 ,xd0=1 ,N=10 ,DELTAT=0.25
//
//################################### 
// time                   x(i)     //  
// 0.25                 0.019265   // 
// 0.50                -0.318985   // 
// 0.75                 0.144699   // 
// 1.00                 0.112366   //
// 1.25                -0.137887   // 
// 1.50                 0.002856   //
// 1.75                 0.077718   // 
// 2.00                -0.039587   //
// 2.25                -0.025262   // 
// 2.50                 0.035048   //
//################################### 
#include <iostream> 
#include <cmath> 
 
using namespace std; 
 
int main() { 
    // variables 
    float c, x0, k, m, deltat, xd0, n; 
    float zeta, omegan, omegad, f; 
     
    // input date 
    cin >> c; 
    cin >> x0; 
    cin >> k; 
    cin >> m; 
    cin >> deltat; 
    cin >> xd0; 
    cin >> n; 
     
    // determine variables 
    zeta = c / (2.0 * sqrt(m * k)); 
    omegan = sqrt(k / m); 
    omegad = omegan * sqrt(1 - pow(zeta, 2)); 
    cout << "Zeta = " << zeta << endl; 
     
    // analysis of motion 
    if (zeta = 0) { 
        float t = deltat; 
        cout<<"Undamped"<<endl; 
        for (int i = 1; i <= n; i++) { 
            f = exp(-(zeta * omegan * t)) * (x0 * cos(omegad * t) + ((xd0 + zeta * omegan * x0) / omegad) * sin(omegad * t)); 
            cout << "i = " << i <<" t = " << t << " , X(t) = " << f << endl; 
            t += deltat; 
        } 
    if (zeta < 1 && zeta > 0) { 
        float t = deltat; 
        cout<<"Underdamped"<<endl; 
        for (int i = 1; i <= n; i++) { 
            f = exp(-(zeta * omegan * t)) * (x0 * cos(omegad * t) + ((xd0 + zeta * omegan * x0) / omegad) * sin(omegad * t)); 
            cout << "i = " << i <<" t = " << t << " , X(t) = " << f << endl; 
            t += deltat; 
        } 
    } 
    if (zeta = 1) { 
        float t = deltat; 
        cout<<"Critically Damped"<<endl; 
        for (int i = 1; i <= n; i++) { 
            f = exp(-omegan*deltat)*(x0+(x0*omegan+xd0)*deltat); 
            cout << "i = " << i << " t = " << t <<" , X(t) = " << f << endl; 
            t += deltat; 
        } 
    } 
    if (zeta > 1) { 
        float t = deltat; 
        cout<<"Overdamped"<<endl; 
        for (int i = 1; i <= n; i++) { 
            f = exp(-zeta*omegan*deltat)*(x0*cosh(omegan*sqrt(pow(zeta,2)-1)*deltat)+(((xd0*x0*zeta*omegan)/omegan/sqrt(zeta-1))*sinh(omegan*sqrt(pow(zeta,2)-1)*deltat))) ; 
            cout << "i = " << i <<" t = " << t <<" , X(t) = " << f << endl; 
            t += deltat; 
        } 
    } 
    else{ 
      cout<<"Damping Coefficient can not be negative"; 
    } 
    return 0; 
}
}