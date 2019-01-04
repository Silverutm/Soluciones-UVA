#include "guessnum.h"
#include <iostream>
using namespace std;

int N, S;
int an;

int guess(int i) {
	an++;
	if (an > 100) {
		cerr << "WA - Guess limit excceded" << endl;
		cout << "0" << endl;
		exit(0);
	}
	if (i < S)
		return -1;
	if (i > S)
		return 1;
	return 0;
}

int adivinar(int i) {
	return guess(i);
}


void answer(int i) {
	if (i == S) {
		cerr << "AC" << endl;
	}
	else {
		cerr << "WA - Wrong number" << endl;
	}
	cout << ((i == S) ? "1" : "0") << endl;
	exit(0);
}

void responder(int i) {
	answer(i);
}

int main(int argc, char* argv[]) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S;

	an = 0;

	eval(N);

	cerr << "WA - Did not call answer()" << endl;
	cout << "0" << endl;
	return 0;
}
