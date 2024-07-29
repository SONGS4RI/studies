#include<iostream>
using namespace std;
int main()
{
    string str,res;
    int num1, num2;
    getline(cin,str);
    for(int i=0;i<7;i++)
    {
        res[i] = str[6-i];
    }
    num1 = ((int)res[0]-48)*100+((int)res[1]-48)*10+((int)res[2]-48);
    num2 = ((int)res[4]-48)*100+((int)res[5]-48)*10+((int)res[6]-48);
    if(num1>num2) cout << num1;
    else cout << num2;
    return 0;
}