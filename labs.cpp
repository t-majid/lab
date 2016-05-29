#include <iostream>
#include <map>
#include <vector>
#include <stdint.h>
#include <utility>      // std::pair
#include <time.h>

#include <omp.h>
#include <set>

#include <unistd.h>
#include "msg.h"
#include "stock.h"
using namespace std;


int main()
{
	labs o;
	o.display();
	ietat *som = o.newd(11,111);
	som->display();
	helloo(*som);
	return 0;
}