#include <iostream>
#include <string>
using namespace std;

void recur(int n,int a)
{
    
    string dash ="";
    dash.append(a*4,'_');
    cout <<dash<< "\"����Լ��� ������?\"\n";
    if(n==0)
    {
        cout <<dash<<"\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
    }
    else
    {
        cout << dash<<"\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
        cout << dash<<"���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
        cout << dash<<"���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
		recur(n-1,a+1);
    }
    cout << dash<< "��� �亯�Ͽ���.\n";
    return;
}

int main()
{
    int n; 
    cin >> n;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
    recur(n,0);
}