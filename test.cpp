#include<iostream>
using namespace std;

int main()
{
    int x;
    while(!(cin>>x))
    {
        cout << "fail" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        
    }
    cout << x;
    return 0;
}