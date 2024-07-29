#include <iostream>
#include <set>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL); 
    string s;
    cin >> s;
 
    set<string> set;
 
    string str = "";
    for (int i = 0; i < s.size(); i++) {
        for (int j = i; j < s.size(); j++) {
            str += s[j];
            set.insert(str);
        }
        str = "";
    }
 
    cout << set.size();
}