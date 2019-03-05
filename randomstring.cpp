#include <cstdio>
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

#define PB push_back

char base[62];
int n, m;	
//n(1000, 5000, 10000, 50000, 100000, 500000) cases
//m(100 500 1000)

vector<string> v;

void setbase(void)
{
	for(int i = 0; i < 62; i++)
	{
		if(i < 10)
			base[i] = i + '0';
		else if(i >= 10 && i <= 35)
			base[i] = (char)'A'+(i-10);
		else
			base[i] = (char)'a'+(i-36);
	}
}

void random_string(void)
{
	srand(time(NULL));

	for(int i = 0; i < n; i++)
	{
		char tmp[m];

		for(int k = 0; k < m; k++)
		{
			int index = rand() % 62;
			tmp[k] = base[index];
		}

		string hold(tmp);
		v.PB(hold);
	}
}

int main(void)
{
	freopen("in.in", "r", stdin);
	freopen("50000-500.out", "w", stdout);

	setbase();

	while(~scanf("%d %d", &n, &m))
	{
		v.clear();
		random_string();
		for(int i = 0; i < v.size(); i++)
		{
			cout << v[i] << endl;
		}
	}

	return 0;	
}