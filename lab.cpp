#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main () 
{
	vector<multimap<int, int>*[6]> isec;
	isec.reserve(100);
	cout<< isec.size()<<endl;
	for(int i(0);i<100;++i)
	{
		for (int j=0;j<6;++j)
			isec[i][j]=NULL;
	}
	cout<< isec.size()<<endl;
	if (isec[0][0]== NULL)
		cout << "niu";
	
	isec[0][0]=new multimap<int,int>;
	
	isec[0][5]=new multimap<int,int>;
	isec[0][0]->insert(make_pair(50,30));
	isec[0][0]->insert(make_pair(56,30));
	isec[0][0]->insert(make_pair(56,30));
	cout << isec[0][0]->size() << endl;
	cout<< isec.size()<<endl;
	//cout<< sizeof(isec)<<endl;
	multimap<int,int>::iterator it;
	it= isec[0][0]->find(50);
	isec[0][0]->erase(it);
	it= isec[0][0]->begin();
	cout << it->first;
	
	for(int i(0);i<100;++i)
	{
		for (int j=0;j<6;++j)
		{
			if(isec[i][j]!= NULL)
			{
				delete isec[i][j];
				cout << "delete" <<endl;
			}
		}
	}
	return 0;
}
