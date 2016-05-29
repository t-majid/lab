#include <iostream>
#include <map>
#include <vector>
#include <stdint.h>
#include <utility>      // std::pair
#include <time.h>

#include <omp.h>
#include <set>


#include <unistd.h>

using namespace std;


class ietat
{
public:
	friend void helloo(ietat& o);
	ietat(){}
	ietat(int d, int c):a(d),b(c), bitm(0x00){}
	ietat(const ietat& o){}
	~ietat(){}
	bool cmp_state(ietat& od){
		if(od.a != a)
			bitm |= 0x80;
		if(od.b != b)
			bitm |= 0x40;
		return 1;
	}
	void display(){cout << a << " "<< b <<" bitm " << (int)bitm <<endl;}
protected:
	uint64_t a;
	uint64_t b;
	uint8_t bitm;

};
class labs
{
public:
	labs(){
		etati.reserve(5);
		for (int i(0); i< 5; i++)
			etati[i]= NULL;
		etati[2]= new ietat(50, 100);
		etati[1] = new ietat(10,30);
	}
	ietat* newd(int r, int f){
		ietat* newOn = new ietat(r, f);
		newOn->cmp_state(*etati[2]);
		delete etati[2];
		etati[2] =  newOn;
		return etati[2];
	} 
	void display(){
		for (int i(0); i< 5; i++){
			if(etati[i]!=NULL)
				etati[i]->display();
		}
			
	}
	~labs(){ 
		delete etati[2];
		delete etati[1];
	}
private:
	vector<ietat*> etati;
	/* data */
};
