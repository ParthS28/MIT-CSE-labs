#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
 

int sum(int n){
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans+=i;
    }
    return ans;
}

int main(int argc, char * argv[]){
    int n;
    int fa, fb;
    printf("Enter n\n");
    scanf("%d", &n);

    fa = open("Output.txt", O_WRONLY);

    int pid;
    pid = fork();

    if(pid < 0){
        printf("Error in forking\n");
        exit(1);
    }
    else if(pid == 0){
        // child
        int ans = sum(n);
        char buf[2048];
        int rev = 0;
        int temp = ans;
        printf("%d\n", ans);
        while(temp > 0){
            int t = temp%10;
            rev = rev*10 + t;
            temp/=10;
        }
        // printf("%d\n", rev);
        int i = 0;
        while(rev > 0){
            int t = rev % 10;
            buf[i++] = (char)(t+48);
            rev /= 10;
        }
        buf[i] = '\0';
        write(fa, buf, strlen(buf));
        // close(fa);
    }
    else{
        //parent
        int status;
        wait(&status);
        fb = open("Output.txt", O_RDONLY);
        char buf[2048];
        int x = read(fb, buf, 2048);
        buf[x] = '\0';
        printf("%s\n", buf);
    }
}