#include <iostream>
#include <cmath>
#include <set>
#include <string>
//x^2 + y^2 = z^2
//But Z must be a whole number
using namespace std;

long double z = 0; //= square root (x² + y²); when n = 2
int power;


std::set<string> output;

int main(){
	cout << "x^n + y^n = z^n" << endl;
	cout << "n = "; cin >> power;
	string s_power = to_string(power);
	
	for(int x = 1; x < 500; x++){
		for(int y = 1; y < 500; y++){
			z = pow((pow(x, power) + pow(y, power)),  double(float(1))/power);
			
			if(z == floor(z)){//if z is int
				//this if statment below is to keep the set unique
				//Because 16² + 14² is equivilent to 14² + 16² but '16² + 14²' is not equivilent to '14² + 16²'
				if(x > y){
					output.insert(to_string(x) + "^" + s_power +  " + "
							   +  to_string(y) + "^" + s_power +  " = " 
							   +  to_string(int(z)) + "^" + s_power);
				}
				else{
					output.insert(to_string(y) + "^" + s_power +  " + "
							   +  to_string(x) + "^" + s_power +  " = " 
							   +  to_string(int(z)) + "^" + s_power);
				}
			}
		}		
	}
	
	for (set<string>::iterator i = output.begin(); i != output.end(); i++) {
		cout << *i << endl;
	}
	return 0;
}
