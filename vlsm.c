#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct{
	int arr[4];
	int sm;
	int pos;
	int range;
}address;

int* bubbleSort(int arr[], int n);

int main(){
	int num,x;
	
	printf("Number of Subnets: ");
	scanf("%d",&num);
	int req[num];
	
	printf("\nNumber of Hosts: \n");
	for(x=0;x<num;x++){
		printf("Subnet #%d: ",x+1);
		scanf("%d",&req[x]);
	}
	bubbleSort(&req,num);
	
	
	int network[4];

	printf("Network address: ");
	scanf("%d.%d.%d.%d",&network[0],&network[1],&network[2],&network[3]);
	
	address ip[num];
	int bb;
	
	for(x=0;x<num;x++){
		bb=0;
		while(pow(2,bb)-2<req[x])bb++;
		ip[x].sm=32-bb;
	}
	printf("_______________\n");
	
	int i,j,y,temp;
	for(x=0;x<num;x++){
		printf("S.M: %d",ip[x].sm);
		if(ip[x].sm>24){
			ip[x].pos=4;
		}
		else if(ip[x].sm<=24 && ip[x].sm>16){
			ip[x].pos=3;
		}
		else if(ip[x].sm<=16 && ip[x].sm>8){
			ip[x].pos=2;
		}
		else if(ip[x].sm<=8 && ip[x].sm>=0){
			ip[x].pos=1;
		}
		temp = ip[x].sm;
		while(temp>=8)temp-=8;
		i=0;
		j=128;
		
		while(temp>0){
			i = i+j;
			j /=2;
			temp--;
		}
		
		ip[x].range = 256-i;
		if(ip[x].range==256)ip[x].range=1;
		printf(" - Pos: %d - Range = %d\n",ip[x].pos,ip[x].range);
		
		
	}
	
	for(x=0;x<4;x++){
		ip[0].arr[x]=network[x];
	}

	printf("\n\nSubnet 1 = %d.%d.%d.%d/%d\n",ip[0].arr[0],ip[0].arr[1],ip[0].arr[2],ip[0].arr[3],ip[0].sm);

	for(x=1;x<num;x++){
		for(i=0;i<4;i++){
			ip[x].arr[i] = ip[x-1].arr[i];
		}
		ip[x].arr[ip[x-1].pos-1] += ip[x-1].range;
		
		if(ip[x].arr[ip[x-1].pos-1]>=256){
			ip[x].arr[ip[x-1].pos-1] = 0;
			ip[x].arr[ip[x-1].pos-2] +=1;
		}
		printf("Subnet %d = %d.%d.%d.%d/%d\n",x+1,ip[x].arr[0],ip[x].arr[1],ip[x].arr[2],ip[x].arr[3],ip[x].sm);
		
	}
	
	return 0;
}

int* bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
