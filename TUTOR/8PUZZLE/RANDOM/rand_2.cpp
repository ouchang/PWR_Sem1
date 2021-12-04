#include <iostream>
#include <random>
#include <algorithm>
#include <vector>
#include <chrono>

using namespace std;

int main()
{
  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()

  /* GENERATE A VECTOR OF CONSECUTIVE INTEGERS */
	vector<int> v;
	for(int n = 0; n < 9; ++n)
		v.push_back(n);


  /* PRINT IT */
	cout << "vector of ints: ";
	for(auto it : v) cout << it << " ";
	cout << endl;

  /* RANDOMLY SHUFFLE THE VECTOR OF INTEGERS USING mt19937 GENERATOR */
	shuffle(begin(v), end(v), gen);

	/* PRINT IT */
	cout << "shuffled to   : ";
	for(auto it : v) cout << it << " ";
	cout << endl;
}
