//============================================================================
// Name        : hell.cpp
// Author      : majdi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include <map>
#include <iterator>
#include <memory>
#include <fstream>
#include <list>
#include <vector>
#include <stdint.h>
#include <algorithm>
using namespace std;

class grp;
class sti {
public:
	sti(): _x(0), _y(5){}
	sti(int x): _x(x), _y(5){}
bool operator==(const int key) const {
	return (key == _x) ? true : false;
}
bool operator<(const int key) const {
	return (key > _x) ? true : false;
}
public:
	int _x, _y;
};

int Binary_Search(const vector<sti> &my_numbers, int key) {

int iteration = 0, left = 0, right = my_numbers.size()-1, mid;

while (left <= right) {
	iteration++;
	mid = (int) ((left + right) / 2);
	if (  my_numbers[mid] == key) {
		//cout << "Binary search found " << my_numbers[mid] << " after " << iteration << " iterations.\n";
		iteration++;
		cout << iteration;
		return mid;
	}
if (my_numbers[mid] < key)
	left = mid + 1;
else
	right = mid - 1;
}
//cout << "Binary search did not found " << my_numbers[mid] << " after " << iteration << " iterations.\n";

return 0xFFFF;

}

class grp {
public:
	grp(){
		v.reserve(50);
		cout << "sizeof " << sizeof(v) << endl;
		for (unsigned i(0); i < 20 ; ++i){
			v.push_back(i);
		}
		v.resize(v.size());
//		cout << "sizeof " << sizeof(v) << endl;

	}
	void disp(){
		for (unsigned i(0); i < v.size() ; ++i){
			cout << v[i]._x << " ";
		}
	}
grp(int d){}
private:
	vector<sti> v ;
};
int main(){
sti s1(10);
sti s2;

	string filename = "./classfile.dat";
	   ofstream outfile;
	   outfile.open (filename.c_str(), ios::out|ios::binary);
	   outfile.write ( (char *)(&s1), sizeof(sti) );
	   outfile.close();

	   ifstream infile;
	     infile.open (filename.c_str(), ios::in|ios::binary);

	     infile.read ( (char *)&s2, sizeof(sti));
	     infile.close();

	return 0;
}
