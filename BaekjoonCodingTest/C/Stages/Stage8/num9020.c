#include <stdio.h>

int main()
{
  int T;
  int N;
  int arr[10001] = {0,1};
  
  //테스트 케이스 갯수 입력받기
  scanf("%d", &T);
  
  for(int l=0; l<T; l++){
    scanf("%d", &N);

    //N내의 소수들 구하기
    for(int i=2; i<=N; i++){
      for(int j=2; i*j<=N; j++){
        arr[i*j]=1;
      }
    }
    //index를 N/2부터 시작
    for(int m=N/2; m>0; m--){
      if(arr[m]!=1 && arr[N-m]!=1){
        printf("%d %d\n",m,N-m);
        break; 
      }
    }
  }
  
  return 0;
}