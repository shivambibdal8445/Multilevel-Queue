#include<stdio.h>
int a_t1[30],a_t2[30],pt2[30],ps2[30],a_t3[30]; int b_t1[30],b_t2[30],b_t3[30];
int Total=0,t1=0,t2=0,t3=0;
int n,i,at[30],bt[30],pr[30],j=0,k=0,l=0; int total,x,temp[30],co=0;
float a_w_t1=0.0,a_t_t1=0.0; int p,w_t3[30],t_t3[30];
float a_w_t3=0.0,a_t_t3=0.0;
int po,q,temp1,sum=0,w_t2[30],t_t2[30]; float a_w_t2,a_t_t2;
void Round_Robin1(); void Round_Robin(); void FCFS();
void Priority(); int main()
{
printf("Enter the no. of process you want to enter\n"); scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter details of process[%d]\n",i+1); printf("Arrival Time:");
scanf("%d",&at[i]); printf("Burst Time:"); scanf("%d",&bt[i]); printf("Priority(1 to 15):"); scanf("%d",&pr[i]); Total=Total+bt[i];
}
for(i=0;i<n;i++)
{
if(pr[i]>=1&&pr[i]<=5)
{
printf("\n\nProcess[%d] belongs to Queue 1\n",i+1); a_t1[j]=at[i];
b_t1[j]=bt[i]; j++;
t1=t1+bt[i];
}
else if(pr[i]>=6&&pr[i]<=10)
{
printf("Process[%d] belongstoQueue2\n",i+1); a_t2[k]=at[i];
b_t2[k]=bt[i];
pt2[k]=pr[i]; ps2[k]=k+1; k++;
t2=t2+bt[i];
}

else if(pr[i]>=11&&pr[i]<=15)
{
printf("Process[%d] belongs to Queue 3\n\n\n\n",i+1); a_t3[l]=at[i];
b_t3[l]=bt[i]; l++;
t3=t3+bt[i];
}
}

Round_Robin1(); Round_Robin(); FCFS();
Priority();

return 0;
}
void Round_Robin()
{
printf("Time Quantum for Queue1 is 4\n"); for(i=0;i<j;i++)
{
temp[i]=b_t1[i];
}
printf("\nProcess ID\tBurst Time\t Turnaround Time\t Waiting Time\n"); x=j;
for(i=0,total=0;x!=0;)
{
if(temp[i]<=4&&temp[i]>0)
{
printf("\nProcess[%d] of Queue1 is running for %d units",i+1,temp[i]); total=total+temp[i];
temp[i]=0; co=1;
}
else if(temp[i]>0)
{
printf("\nProcess[%d] of Queue1 is running for 4 units",i+1);
temp[i]=temp[i]-4; total=total+4;
}
if(temp[i]==0&&co==1)
{
x--;
printf("\nProcess[%d]\t%d\t%d\t%d",i+1,b_t1[i],total-a_t1[i],total-a_t1[i]-b_t1[i]); a_w_t1=a_w_t1+total-a_t1[i]-b_t1[i];
a_t_t1=a_t_t1+total-a_t1[i];co=0;
}
if(i==j-1)
{
i=0;
}
else if(a_t1[i+1]<=total)
{
i++;
}
else
{
i=0;
}
}
a_w_t1=a_w_t1/j; a_t_t1=a_t_t1/j;
printf("\nAverage Waiting Time:%f",a_w_t1); printf("\nAverage Turnaround Time:%f\n",a_t_t1);
}
void Priority()
{
for(i=0;i<k;i++)
{
po=i;for(q=i+1;q<k;q++)
{
if(pt2[q]<pt2[po])
{
po=q;
}
}
temp1=pt2[i]; pt2[i]=pt2[po];
pt2[po]=temp1;

temp1=b_t2[i]; b_t2[i]=b_t2[po]; b_t2[po]=temp1;

temp1=ps2[i]; ps2[i]=ps2[po]; ps2[po]=temp1;
}
w_t2[0]=0; for(i=1;i<k;i++)
{
w_t2[i]=0; for(q=0;q<i;q++)
{
w_t2[i]=w_t2[i]+b_t2[j];
}
sum=sum+w_t2[i];
}
a_w_t2=sum/k; sum=0;
printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n"); for(i=0;i<k;i++)
{
t_t2[i]=b_t2[i]+w_t2[i]; sum=sum+t_t2[i];
printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n",ps2[i],b_t2[i],w_t2[i],t_t2[i]);
}
a_t_t2=sum/k;
printf("\nAverage Waiting Time:\t%f",a_w_t2); printf("\nAverage Turnaround Time:\t%f\n",a_t_t2);

for(i=0;i<k;i++)
{
while(b_t2[i]!=0)
{
if(b_t2[i]>10)
{


}


printf("\nProcess[%d] of Queue2 is running for 10 units",i+1); b_t2[i]=b_t2[i]-10;
else if(b_t2[i]<=10)
{
printf("\nProcess[%d] of Queue2 is running for %d
units",i+1,b_t2[i]);
b_t2[i]=0;
}
}
}
}
void FCFS()
{
w_t3[0] = 0; for(i=1;i<l;i++)
{
w_t3[i] = 0; for(p=0;p<l;p++)
{
w_t3[i]=w_t3[i]+b_t3[p];
}
}
printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n"); for(i=0;i<l;i++)
{
t_t3[i]=b_t3[i]+w_t3[i]; a_w_t3=a_w_t3+w_t3[i]; a_t_t3=a_t_t3+t_t3[i];
printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d\n",i+1,b_t3[i],w_t3[i],t_t3[i]);
}
a_w_t3=a_w_t3/l; a_t_t3=a_t_t3/l;
printf("\nAverage Waiting Time=%f",a_w_t3); printf("\nAverage Turnaround Time=%f",a_t_t3); for(i=0;i<l;i++)
{
while(b_t3[i]!=0)
{
if(b_t3[i]>10)
{


}


printf("\nProcess[%d] of Queue3 is running for 10 units",i+1); b_t3[i]=b_t3[i]-10;
else if(b_t3[i]<=10)
{

units",i+1,b_t3[i]);

}
}
}
}
printf("\nProcess[%d] of Queue2 is running for %d b_t3[i]=0;
void Round_Robin1()
{
printf("Time Quantum between the 3 queues is 10\n"); for(i=1;i<Total;i=i+10)
{
if(t1>10)
{
printf("Queue1 is running for 10 units\n"); t1=t1-10;
}
else if(t1<=10&&t1!=0)
{
printf("Queue1 is running for %d units\n",t1); t1=0;
}
if(t2>10)
{
printf("Queue2 is running for 10 units\n"); t2=t2-10;
}
else if(t2<=10&&t2!=0)
{
printf("Queue2 is running for %d units\n",t2); t2=0;
}
if(t3>10)
{
printf("Queue3 is running for 10 units\n"); t3=t3-10;
}
else if(t3<=10&&t3!=0)
{
printf("Queue3 is running for %d units\n",t3); t3=0;
}
}
}
#include<stdio.h>
int a_t1[30],a_t2[30],pt2[30],ps2[30],a_t3[30]; int b_t1[30],b_t2[30],b_t3[30];
int Total=0,t1=0,t2=0,t3=0;
int n,i,at[30],bt[30],pr[30],j=0,k=0,l=0; int total,x,temp[30],co=0;
float a_w_t1=0.0,a_t_t1=0.0; int p,w_t3[30],t_t3[30];
float a_w_t3=0.0,a_t_t3=0.0;
int po,q,temp1,sum=0,w_t2[30],t_t2[30]; float a_w_t2,a_t_t2;
void Round_Robin1(); void Round_Robin(); void FCFS();
void Priority(); int main()
{
printf("Enter the no. of process you want to enter\n"); scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter details of process[%d]\n",i+1); printf("Arrival Time:");
scanf("%d",&at[i]); printf("Burst Time:"); scanf("%d",&bt[i]); printf("Priority(1 to 15):"); scanf("%d",&pr[i]); Total=Total+bt[i];
}
for(i=0;i<n;i++)
{
if(pr[i]>=1&&pr[i]<=5)
{
printf("\n\nProcess[%d] belongs to Queue 1\n",i+1); a_t1[j]=at[i];
b_t1[j]=bt[i]; j++;
t1=t1+bt[i];
}

else if(pr[i]>=6&&pr[i]<=10)
{
printf("Process[%d] belongstoQueue2\n",i+1); a_t2[k]=at[i];
b_t2[k]=bt[i];
pt2[k]=pr[i]; ps2[k]=k+1; k++;
t2=t2+bt[i];
}

else if(pr[i]>=11&&pr[i]<=15)
{
printf("Process[%d] belongs to Queue 3\n\n\n\n",i+1);
a_t3[l]=at[i];
b_t3[l]=bt[i]; l++;
t3=t3+bt[i];
}
}

Round_Robin1(); Round_Robin(); FCFS();
Priority();

return 0;
}
void Round_Robin()
{
printf("Time Quantum for Queue1 is 4\n"); for(i=0;i<j;i++)
{
temp[i]=b_t1[i];
}
printf("\nProcess ID\tBurst Time\t Turnaround Time\t Waiting Time\n"); x=j;
for(i=0,total=0;x!=0;)
{
if(temp[i]<=4&&temp[i]>0)
{
printf("\nProcess[%d] of Queue1 is running for %d units",i+1,temp[i]); total=total+temp[i];
temp[i]=0; co=1;
}
else if(temp[i]>0)
{
printf("\nProcess[%d] of Queue1 is running for 4 units",i+1);
temp[i]=temp[i]-4; total=total+4;
}
if(temp[i]==0&&co==1)
{
x--;
printf("\nProcess[%d]\t%d\t%d\t%d",i+1,b_t1[i],total-a_t1[i],total-a_t1[i]-b_t1[i]); a_w_t1=a_w_t1+total-a_t1[i]-b_t1[i];
a_t_t1=a_t_t1+total-a_t1[i]; co = 0;
}
if(i==j-1)
{
i=0;
}
else if(a_t1[i+1]<=total)
{
i++;
}
else
{
i=0;
}
}
a_w_t1=a_w_t1/j; a_t_t1=a_t_t1/j;
printf("\nAverage Waiting Time:%f",a_w_t1); printf("\nAverage Turnaround Time:%f\n",a_t_t1);
}
void Priority()
{
for(i=0;i<k;i++)
{
po=i;for(q=i+1;q<k;q++)
{
if(pt2[q]<pt2[po])
{
po=q;
}
}
temp1=pt2[i]; pt2[i]=pt2[po]; pt2[po]=temp1;

temp1=b_t2[i]; b_t2[i]=b_t2[po]; b_t2[po]=temp1;

temp1=ps2[i]; ps2[i]=ps2[po]; ps2[po]=temp1;
}
w_t2[0]=0; for(i=1;i<k;i++)
{
w_t2[i]=0;
for(q=0;q<i;q++)
{
w_t2[i]=w_t2[i]+b_t2[j];
}
sum=sum+w_t2[i];
}
a_w_t2=sum/k; sum=0;
printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n"); for(i=0;i<k;i++)
{
t_t2[i]=b_t2[i]+w_t2[i]; sum=sum+t_t2[i];
printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n",ps2[i],b_t2[i],w_t2[i],t_t2[i]);
}
a_t_t2=sum/k;
printf("\nAverage Waiting Time:\t%f",a_w_t2); printf("\nAverage Turnaround Time:\t%f\n",a_t_t2);

for(i=0;i<k;i++)
{
while(b_t2[i]!=0)
{
if(b_t2[i]>10)
{


}


printf("\nProcess[%d] of Queue2 is running for 10 units",i+1); b_t2[i]=b_t2[i]-10;
else if(b_t2[i]<=10)
{

units",i+1,b_t2[i]);

}
}
}
}
void FCFS()
{
printf("\nProcess[%d] of Queue2 is running for %d b_t2[i]=0;
w_t3[0] = 0; for(i=1;i<l;i++)
{
w_t3[i] = 0; for(p=0;p<l;p++)
{
w_t3[i]=w_t3[i]+b_t3[p];
}
}
printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n"); for(i=0;i<l;i++)
{
t_t3[i]=b_t3[i]+w_t3[i]; a_w_t3=a_w_t3+w_t3[i]; a_t_t3=a_t_t3+t_t3[i];
printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d\n",i+1,b_t3[i],w_t3[i],t_t3[i]);
}
a_w_t3=a_w_t3/l; a_t_t3=a_t_t3/l;
printf("\nAverage Waiting Time=%f",a_w_t3); printf("\nAverage Turnaround Time=%f",a_t_t3); for(i=0;i<l;i++)
{
while(b_t3[i]!=0)
{
if(b_t3[i]>10)
{


}


printf("\nProcess[%d] of Queue3 is running for 10 units",i+1); b_t3[i]=b_t3[i]-10;
else if(b_t3[i]<=10)
{

units",i+1,b_t3[i]);

}
}
}
}
void Round_Robin1()
{
printf("\nProcess[%d] of Queue2 is running for %d b_t3[i]=0;
printf("Time Quantum between the 3 queues is 10\n"); for(i=1;i<Total;i=i+10)
{
if(t1>10)
{
printf("Queue1 is running for 10 units\n"); t1=t1-10;
}
else if(t1<=10&&t1!=0)
{
printf("Queue1 is running for %d units\n",t1); t1=0;
}
if(t2>10)
{
printf("Queue2 is running for 10 units\n"); t2=t2-10;
}
else if(t2<=10&&t2!=0)
{
printf("Queue2 is running for %d units\n",t2); t2=0;
}
if(t3>10)
{
printf("Queue3 is running for 10 units\n"); t3=t3-10;
}
else if(t3<=10&&t3!=0)
{
printf("Queue3 is running for %d units\n",t3); t3=0;
}
}
}
