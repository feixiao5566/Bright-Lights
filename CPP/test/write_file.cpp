#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//ofstream fout2("/home/robot2/Desktop/wheel_right.txt");

string home_value = getenv("HOME");
string file_path = home_value+"/Desktop/wheel_right.txt";
ofstream fout(file_path.c_str());//或ofstream fout2;  fout2.open(file_path.c_str(),ios::app);

fout<<twist.linear.x<<" "<< twist.angular.z<<std::endl;
