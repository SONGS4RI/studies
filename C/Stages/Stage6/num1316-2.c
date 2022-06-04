#include <stdio.h>
#include <string.h>
 
int main(void){
    int N;
    scanf("%d", &N);
 
    int group_num = 0; 
    for(int i=0; i<N; i++){
        char word[101];
        scanf("%s", word);
        
        int alphabet[26] = {0,};
        int word_len = strlen(word);
        for(int k=0; k<word_len; k++){
            char letter = word[k];
            if(alphabet[letter-'a'] == 0){
                alphabet[letter-'a'] = 1;
            }
            else{ 
                if(word[k-1] != word[k]) 
                    break;
            }
            if(k==word_len-1)group_num++;
        }
    }
    printf("%d\n", group_num);
}
// 알파벳 배열을 만들어서 안쓰인 알파벳이면 1등록,
// 이미 쓰였다면 이전의 알파벳과 비교하는 루프
// 만약 무사히 단어의 길이만큼 반복한다면 그룹 단어