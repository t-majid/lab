#include <iostream>
#include <map>
#include <vector>
#include <stdint.h>
#include <utility>      // std::pair
#include <time.h>

#include <omp.h>


#include <unistd.h>
using namespace std;

double seconds;
std::pair <int64_t,uint64_t> bo[6];

typedef map<int64_t,uint64_t>* maplist;
vector<maplist[6]> isec;
// must add open MP for for
void hh()
{

}

//---------------------------
	void init()
	{

		isec.reserve(100);
		cout<< isec.size()<<endl;
		#pragma omp parallel for
		for(int i=0;i<100;++i)
		{
			// #pragma omp parallel for
			for (int j=0;j<6;++j)
				isec[i][j]=NULL;
		}
	}
void add(maplist& list, const int64_t& p, const uint64_t& q)
{
	if(list == NULL)
	{
		list = new map<int64_t,uint64_t>; // on peut qu'ajouter
		cout<< "new map "<<endl;

	}

	if(list->find(p)!= list->end())
	{
		list->at(p)+=q;
		cout<< list->at(p)<<endl;
	}
	else
	{
		list->insert(make_pair(p, q));
		cout<< list->at(p)<<endl;
	}
}
void deleteq(maplist& list, const int64_t& p, const uint64_t& q)
{
	if(list == NULL)
	{
		cout << "error : not exist list empty" << endl;
	}
	else
	{

		map<int64_t,uint64_t>::iterator it = list->find(p);
		if (it != list->end())
		{
			list->at(p)-=q;
			cout<< "del" << list->at(p)<<endl;
			if(list->at(p) == 0)
			{
				list->erase(it);
				cout<< "erase"<<endl;
			}
		}
		else
		{
			cout << "error : p not exist " << endl;
		}

	}
}
void destruct()
{
#pragma omp parallel for
	for(int i=0;i<100;++i)
	{
	// #pragma omp parallel for
		for (int j=0;j<6;++j)
		{
			if(isec[i][j]!= NULL)
			{
				cout << "delete" <<endl;
				delete isec[i][j];
				
			}
		}
	}	
}


void display()
{
#pragma omp parallel for
	for(int i=0;i<100;++i)
	{
		// #pragma omp parallel for
		for (int j=0;j<6;++j)
		{

			if(isec[i][j]!= NULL)
			{
				cout << "-----" << i << "------" << endl;
				map<int64_t,uint64_t>::iterator it= isec[i][j]->begin();
				// #pragma omp parallel for
				for (it; it!=isec[i][j]->end(); ++it)
					cout << it->first << " : " << it->second << endl;
				
			}
		}
	}	
}

int main () 
{
std::cout.setf( std::ios::fixed, std:: ios::floatfield );
struct timespec start_time;
    struct timespec end_time;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);
    uint64_t startNs = start_time.tv_sec * 1000 * 1000 * 1000 + start_time.tv_nsec;
cout << startNs << endl;	
	init();


	uint64_t q = 500;
	int64_t p = 100;
	
	add(isec[0][0], p, q);
	add(isec[0][0], p, q);
	// deleteq(isec[0][0], p, q);
	add(isec[0][0], 20, 50);
	// deleteq(isec[0][2], 10, q);
	// deleteq(isec[0][0], p, q);
	

	// isec[0][0]=new map<int64_t,uint64_t>;
	
	// isec[0][5]=new map<int64_t,uint64_t>;
	// isec[0][0]->insert(make_pair(50,30));
	// isec[0][0]->insert(make_pair(56,30));
	// isec[0][0]->insert(make_pair(56,30));
	// cout << isec[0][0]->size() << endl;
	// cout<< isec.size()<<endl;
	// //cout<< sizeof(isec)<<endl;
	// map<int64_t,uint64_t>::iterator it;
	// // it= isec[0][0]->find(50);
	// // isec[0][0]->erase(it);
	// it= isec[0][0]->begin();
	if(isec[0][0]!=NULL)
		cout << isec[0][0]->size()<<endl;
	display();

	// destruct();
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_time);


uint64_t endNs = end_time.tv_sec * 1000 * 1000 * 1000 + end_time.tv_nsec;
uint64_t diffNs = endNs - startNs;
uint64_t diffMicro = diffNs / 1000;
uint64_t diffSec = start_time.tv_sec - end_time.tv_sec;
// std::cout.precision(12);
std::cout.setf( std::ios::fixed, std:: ios::floatfield );
cout << diffSec << " " << endNs << endl;
	return 0;
}
