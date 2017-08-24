#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int main()
{
	int nF,nR,zone;
	
	cout<<"Please Insert the number of Functional Nodes you want to insert"<<endl;
	cin>>nF;
	
	cout<<"Please Insert the number of Redundent Nodes you want to insert"<<endl;
	cin>>nR;
	
	//declaration of 2d array of functional node as well as redundent node
	int i=0,j=0;
	int F[nF][3],R[nR][3];
	
	
	//the structure is like this [x][y][indentity No]
	
	
	//insertion of the co-ordinates
	cout<<"Kindly Insert the co-ordinates of the Redundent Nodes One By One (as x[space]y) "<<endl;
	for(i=0;i<nR;i++)
	{	R[i][2]=i+1;
		cin>>R[i][0]>>R[i][1];
	}
	
	float dist,d,z1,z2;
	float distance[nF][2];
	
	cout<<"Kindly Insert the co-ordinates of the Functional Nodes One By One (as x[space]y) "<<endl;
	for(i=0;i<nF;i++)
	{
		cin>>F[i][0]>>F[i][1];
		F[i][2]=i+1;//assigning the identity number of the Node 
		
		
		
		//((x2-x1)^2
		z1=pow((F[i][0]-R[0][0]),2);
		//(y2-y1)^2)
		z2=pow((F[i][1]-R[0][1]),2);
		
		//initialize d and zone with the first values of the array
		d=pow(z1+z2,0.5);// ((x2-x1)^2 +(y2-y1)^2)^0.5
		zone=1;	
		
		
		for(j=1;j<nR;j++)
		{
			z1=pow((F[i][0]-R[j][0]),2);
			z2=pow((F[i][1]-R[j][1]),2);
			dist=pow(z1+z2,0.5);// ((x2-x1)^2 +(y2-y1)^2)^0.5
			//compare if d is the smallest or not 
			if(d>dist)
			{
			//if not then swap the least value and make d the smallest
				d=dist;
				zone=j+1;
			}
		}
		//Store the distance between the target nodes and the identity no of its nearest Redudent Node
		distance[i][0]=d;
		distance[i][1]=zone;
		
	}
//Now Just Print	
	for(i=0;i<nF;i++)
	{
		cout<<"("<<F[i][0]<<" , "<<F[i][1]<<") Functional Node No. "<<F[i][2]<<" is belongs to the region of ("<<R[((int)distance[i][1] -1)][0]<<" , "<<R[((int)distance[i][1]-1)][1]<<") Redundent Node No. "<<distance[i][1]<<" with distance of "<<distance[i][0]<<" units"<<endl; 
	}
	


return 0;
}
