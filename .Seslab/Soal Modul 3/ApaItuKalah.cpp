// C++ program to demonstrate the creation of descending
// order set container
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{

	set<string, greater<string> > s1;
	s1.insert("anjay");
	s1.insert("badut");
	s1.insert("rey");
	s1.insert("cacing");

	for (auto i : s1) {
		cout << i << ' ';
	}
	return 0;
}
