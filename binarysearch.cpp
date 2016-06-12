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
	explicit sti(int x): _x(x), _y(5){}
	sti(const sti& o){_x = o._x; cout << "copy c" << endl;}
	sti& operator=(const sti& o){_x = o._x; cout << "assign" << endl; return *this;}
	void update_with_arc();
	void update_with_c();
bool operator==(const int key) const {
	return (key == _x) ? true : false;
}
bool operator<(const int key) const {
	return (key > _x) ? true : false;
}
public:
	int _x, _y;
};


class grp {
public:
	grp(){
		v.reserve(50);
		cout << "sizeof " << sizeof(v) << endl;
		for (unsigned i(0); i < 20 ; ++i){
			v.push_back(sti(i));
		}
		v.resize(v.size());
//		cout << "sizeof " << sizeof(v) << endl;
}
private:
sti& Binary_Search( int key) {

int iteration = 0, left = 0, right = v.size()-1, mid;

while (left <= right) {
	iteration++;
	mid = (int) ((left + right) / 2);
	if (  v[mid] == key) {
		// cout << "Binary search found " << my_numbers[mid] << " after " << iteration << " iterations.\n";
		iteration++;
		cout << iteration;
		return v[mid];
	}
if (v[mid] < key)
	left = mid + 1;
else
	right = mid - 1;
}
// cout << "Binary search did not found " << my_numbers[mid] << " after " << iteration << " iterations.\n";

return v[mid]; // error

}
public:
void update_one_i()
{
	sti& s = Binary_Search( 2);
	// test s else log error
	s.update_with_arc();
}

void update_all_i()
{
	update_c();
	for (unsigned i(0); i < v.size(); ++i)
	{
		v[i].update_with_c();
	}
}	
void update_c();
	void disp(){
		for (unsigned i(0); i < v.size() ; ++i){
			cout << v[i]._x << " " ;
		}
		cout << endl;
	}
grp(int d){v.reserve(50);}
public:
	vector<sti> v ;
};

class sc
{
public:
	sc();
	~sc();
	void update_s();
	void update_g();
	void load_rec();//file
private:
	std::vector<grp> vg;
};

sc::sc()
{

}
void sc::update_s()
{
	

}
int main(){
sti s1(10);
sti s2;
grp g1;
g1.disp();

// cout << Binary_Search( g1.v, 5);

	return 0;
}


// grp g2(1);
// g2.disp();

// 	string filename = "./classfile.dat";
// 	   ofstream outfile;
// 	   outfile.open (filename.c_str(), ios::out|ios::binary);
// 	   outfile.write ( (char *)(&g1), sizeof(grp) );
// 	   outfile.close();

// 	   ifstream infile;
// 	     infile.open (filename.c_str(), ios::in|ios::binary);

// 	     infile.read ( (char *)&g2, sizeof(grp));
// 	     infile.close();
