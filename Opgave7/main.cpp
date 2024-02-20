#include "Dictionary.h"

using namespace std;

int main()
{

	pair<int, string> pair1, pair2, pair3;

	pair1.first = 10;
	pair1.second = "Hund";

	pair2.first = 444;
	pair2.second = "Trold";

	pair3.first = 2;
	pair3.second = "Tunge";

	Dictionary d1;
	cout << d1.insert(pair1) << endl;
	cout << d1.insert(pair2) << endl;

	cout << d1.insert(pair2) << endl;

	cout << d1.contains(pair3) << endl;

	cout << d1.contains(pair1) << endl;

	d1.remove(pair1);
	cout << d1.contains(pair1) << endl;

	return 0;
}