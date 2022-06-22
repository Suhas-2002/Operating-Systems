// Banker's Algorithm
#include <stdio.h>
int main(){
	int n, m;
	printf("Enter the number of processes and resources : ");
	scanf("%d %d", &n, &m);
	int alloc[n][m], max[n][m], avail[m];// Allocation, Max, Available resources

	printf("Enter the values into the Allocation Matrix : \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d", &alloc[i][j]);
		}
	} 

	printf("Enter the values into the Max Matrix : \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d", &max[i][j]);
		}
	} 

	printf("Enter the values into available matrix : ");
	for(int i=0; i<m; i++){
		scanf("%d",&avail[i]);
	}
	int f[n], ans[n], ind = 0;
	for (int k = 0; k < n; k++) {
		f[k] = 0;//Assigning flag zero
	}
	int need[n][m];//need matrix
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}
	
	printf("Need Matrix : \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("%d ", need[i][j]);
		}
		printf("\n");
	} 

	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < n; i++) {
			if (f[i] == 0) {
				int flag = 0;
				for (int j = 0; j < m; j++) {
					if (need[i][j] > avail[j]){
						flag = 1;
						break;
					}
				}
				if (flag == 0) {
					ans[ind++] = i;
					for (int y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}
		}
	}

	int flag = 1;
	
	for(int i=0;i<n;i++){
		if(f[i]==0){
			flag=0;
			break;
		}
	}
	
	if(flag==1){
		printf("Safe Sequence : ");
		for (int i = 0; i < n - 1; i++)
			printf(" P%d ->", ans[i]);
		printf(" P%d", ans[n - 1]);
	}
	
	printf("\n");
	return (0);
}

