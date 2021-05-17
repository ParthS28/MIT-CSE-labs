#include <stdio.h>
#include <string.h>

void search(char* pat, char* txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int opcount = 0;
    for (int i = 0; i <= N - M; i++) {
        int j;
 
        for (j = 0; j < M; j++){
            opcount++;
            if (txt[i + j] != pat[j])
                break;
        }
        
        if (j == M) 
            printf("Pattern found at index %d \n", i);
    }
    printf("Opcount = %d\n", opcount);
}
 
int main()
{
    char s[30], sub[10];
	
	printf("Enter main string ");
	scanf("%s",s);
	
	printf("Enter substring ");
	scanf("%s",sub);
    search(sub, s);
    return 0;
}