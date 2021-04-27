#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define mp make_pair
#define ii pair<int, int>

int main() {
    int v[2] = {2, 3};
    int *p = v; //p aponta para o começo do vetor(v[0])
    cout << *p << endl;
    p++; //p agora aponta para v[1]
    cout << *p << endl;

    string str = "Hello World";
    for (auto &c : str) {
        cout << c << endl;
        c = toupper(c);
    }

    reverse(str.begin(), str.end());
    cout << str << endl;
    return 0;
}