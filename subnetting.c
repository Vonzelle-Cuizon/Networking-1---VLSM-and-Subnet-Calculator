#include <stdio.h>
#include <math.h>
#include <string.h>
typedef struct{
	int arr[4];
}address;


int main(){
	int sm,req,range;
	int ip[4];
	printf("IP ADDRESS - SM - Req: ");  // To use: provide IP ADDRESS, SUBNET MASK, NUMBER OF SUBNETS(REQUIREMENT)
	scanf("%d.%d.%d.%d /%d %d",&ip[0],&ip[1],&ip[2],&ip[3],&sm,&req); // Sample: "192.168.10.10 /22 20
	
	int x=0,y,pos=0,q,w,num = 0,diff;
	
	while(x*8<sm){
	y=x*8;
	x++;
	pos++;
	}
	diff = sm - y;
	
	w = 128;
	for(q=1;q<=sm-y;q++){
		num += w;
		w /=2;
	}
	
	printf("Initial Subnet Mask: ");
	if(diff%8==0){
		for(q=1;q<=4;q++){
			if(q<=pos){
				printf("255");
				if(q<4)printf(".");
			}
			if(q>pos){
				printf("0");
				if(q<4)printf(".");
			}
		}
	}
	
	else if(diff%8!=0){
		for(q=1;q<=4;q++){
			if(q<pos){
				printf("255");
				if(q<4)printf(".");
			}
			if(q==pos){
				printf("%d",num);
				if(q<4)printf(".");
			}
			if(q>pos){
				printf("0");
				if(q<4)printf(".");
			}
		}
	}
	
	int bb=1;
	
	while(pow(2,bb)-2<req){
	bb++;}
	
	printf("\n\nRequirements: %d",req);
	printf("\nB.B. = %d  (%.0f)",bb,pow(2,bb));
	int newsm = sm + bb;
	
	printf("\nNew Subnet Mask: /%d = ",newsm);
	x=0;
	pos=0;
	num = 0;
	while(x*8<newsm){
	y=x*8;
	x++;
	pos++;
	}
	diff = newsm - y;

	w = 128;
	for(q=1;q<=diff;q++){
		num += w;
		w /=2;
	}
	
	if(diff%8==0){
		for(q=1;q<=4;q++){
			if(q<=pos){
				printf("255");
				if(q<4)printf(".");
			}
			if(q>pos){
				printf("0");
				if(q<4)printf(".");
			}
		}
	}
	
	else if(diff%8!=0){
		for(q=1;q<=4;q++){
			if(q<pos){
				printf("255");
				if(q<4)printf(".");
			}
			if(q==pos){
				printf("%d",num);
				if(q<4)printf(".");
			}
			if(q>pos){
				printf("0");
				if(q<4)printf(".");
			}
		}
	}
	
	range = 256-num;
	printf("\nRange: %d",range);
	
	printf("\nNetwork Address: ");
	
		for(q=0;q<4;q++){
			if(q+1==pos){
				w = 0;
				while(w<=ip[q]){
					w+=range;		
				}
				ip[q]=w-range;
					if(ip[q]>255){
					ip[q-1] += 1;
					ip[q] -= 256;
					}
			}
			if(q+1>pos){
				ip[q]=0;
			}
		}
		printf("%d.%d.%d.%d",ip[0],ip[1],ip[2],ip[3]);
		
	address subnets[req];
	
	memcpy(subnets[0].arr, ip, sizeof(ip));

	for(x=1;x<req;x++){
		for(q=0;q<4;q++){
			if(q+1==pos){
				ip[q] += range;
					if(ip[q]>255){
					ip[q-1] += 1;
					ip[q]=ip[q]-256;}
			}
			if(q+1>pos){
				ip[q]=0;
			}
		}
		memcpy(subnets[x].arr, ip, sizeof(ip));
	}
	
	for(x=0;x<req;x++){
		printf("\nSubnet %d: %d.%d.%d.%d",x,subnets[x].arr[0],subnets[x].arr[1],subnets[x].arr[2],subnets[x].arr[3]);
	}
	
}
