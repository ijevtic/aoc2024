#include <iostream>

using namespace std;

int first[10000];
int second[10000];

int main()
{
    for(int i = 0; i < 10000000; i++) {
        int x,y;
        cin >> x >> y;
        cout << i + 1;
    }
    return 0;
}
