#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double height, weight;
	cout<<"Enter your Weight(in lbs): ";
	cin>>weight;
	cout<<"Enter your Height(in inches): ";
	cin>>height;
    double bmi = weight * 703.0 / (height * height);
    if (height and weight != 0){
        if (bmi < 18.5){
            cout<<fixed<<setprecision(2)<<bmi<< "\t\tunderweight";
        }
        if (bmi>=18.5 and bmi <=25.00 ){
            cout<<fixed<<setprecision(2)<<bmi<< "\t\toptimal weight";
        }
        if (bmi > 25.00 ){
            cout<<fixed<<setprecision(2)<<bmi<< "\t\toverweight";
        }
        
    }
    else{
        cout<<"Error";
    }
    return 0;
}
