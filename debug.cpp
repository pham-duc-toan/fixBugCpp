#include <bits/stdc++.h>
#define el inp << '\n'
#define NAME "findTestCase"
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

long long Rand(long long l, long long h) {
    assert(l <= h);
    return abs(l + rd() * 1LL * rd() % (h - l + 1));
}

void MakeTest() {
    string filename = string(NAME) + ".inp";
    ofstream inp(filename);
    int n = Rand(1, 15), m = Rand(1, 15);
    
    inp << n << ' ' << m<<'\n';
    
    for(int i=0;i<n;i++){
    	for (int j=0;j<m;j++){
    		int a;
			a=abs(Rand(0,1));
    		inp<< a <<' ';
		}
		inp <<'\n';
	}
    inp.close(); // Ðóng file sau khi ghi xong
}

const int NTEST = 15*15;

int main() {
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++) {
        MakeTest();
        system((string(NAME) + "_trau.exe").c_str());
        system((string(NAME) + ".exe").c_str());

        #ifdef _WIN32
            // H? di?u hành Windows
            if (system(("fc " + string(NAME) + ".out " + string(NAME) + ".ans").c_str()) != 0)
        #else
            // H? di?u hành Linux ho?c các h? di?u hành khác
            if (system(("diff " + string(NAME) + ".out " + string(NAME) + ".ans").c_str()) != 0)
        #endif
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}

