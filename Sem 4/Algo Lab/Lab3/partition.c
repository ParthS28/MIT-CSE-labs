#include <stdio.h>
#include <math.h>

int partition(int *num, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += num[i];
    }
    sum=sum/2;
	
	for(int i = 1;i<pow(2,n);i++)
	{
		int current_sum = 0;
		
		for(int j = 0;j<n;j++)
		{
			if(i&(1<<j))
			{
				current_sum+=num[j];
			}
		}
		
		if(current_sum == sum)
		{
            printf("True\nSum =%d\n", current_sum);
            printf("Set 1: ");
			for(int j =0;j<n;j++)
			{
				if(i&(1<<j))
				{
					printf("%d ",num[j]);
				}
			}
            printf("\nSet 2: ");
            for(int j =0;j<n;j++)
			{
				if(!(i&(1<<j)))
				{
					printf("%d ",num[j]);
				}
			}
            printf("\n");
            break;
		}
		
		
	}
}

int main(){
	int n;
	
	printf("Enter number of terms : ");
	scanf("%d",&n);
	
	printf("Enter numbers : ");
	int num[n];
	
	for(int i = 0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	partition(num, n);
	
}
