#include<iostream>
#include<string>
using namespace std;
int main()
{
    int cnt =0,idx;
    string input,str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cin >> input;
    for(int i=0; i<input.length(); i++)
    {
        idx = str.find(input[i]);
        if(0<=idx && idx<=2) cnt+=3;
        else if(3<=idx && idx<=5) cnt+=4;
        else if(6<=idx && idx<=8) cnt+=5;
        else if(9<=idx && idx<=11) cnt+=6;
        else if(12<=idx && idx<=14) cnt+=7;
        else if(15<=idx && idx<=18) cnt+=8;
        else if(19<=idx && idx<=21) cnt+=9;
        else if(22<=idx && idx<=25) cnt+=10; 
    }
    cout << cnt;

    return 0;
}