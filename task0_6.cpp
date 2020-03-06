#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void calculation_works(double v, double a1, double a2, double s)
{
    double max_possible_v = sqrt( (s*a1*a2) / (a1 + a2) );
    if (v >= max_possible_v)
    {
        double t = sqrt( s / (a1 + a2) ) * ( sqrt(a2/a1) + sqrt(a1/a2) );

        cout << "Maximal reasonable velocity: " << max_possible_v << endl
             << "Time with this velocity: " << t << endl;
    }
    else
    {
        double t1 = v/a1;
        double t2 = v/a2;

        double Sacc = a1 * t1 * t1 / 2;
        double Sbr = a2 * t2 * t2 / 2;

        double Sonmax = s - Sacc - Sbr;

        double tonmax = Sonmax / v;

        double t = t1 + t2 + tonmax;

        cout << "Maximal velocity: " << v << endl
             << "Time with this velocity: " << t;
    }
}

int main()
{
    double v, a1, a2, s;

    cout << "Input velocity in m/s, a1 and a2 in m/s^2 and s in m: ";
    cin >> v >> a1 >> a2 >> s;

    calculation_works(v, a1, a2, s);

    return 0;
}


