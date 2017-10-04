#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "windows.h"

using namespace std;

double a[100][100];
void gotoxy(int x, int y) 
{ 
    COORD coord;
    coord.X = x; 
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(int argc, char** argv) {
	int  r,m,n,temp,t=0,s=0,q=0,c=0,h=0;
	char ch;
	test:
	cout<<"ENTER THE NUMBER OF ROWS/COLUMNS IN MATRIX A: ";
	cin>>r,cout<<endl;
	double  a[r][r],z,v;
	cout<<"ENTER THE VALUES IN THE MATRIX A."<<endl<<"(REMEMBER THE VALUES WILL BE ENTERED ROW WISE.)\n\n\n";
	
for(int i=0;i<r;i++)
{
    for(int j=0;j<r;j++)
       {
          gotoxy(4+s,9+t);
	  cin>>a[i][j];
	  s+=6;
       }
       t+=2;
       s=0;
}

cout<<"\n\n\n\nPRESS ENTER TO CONTINUE";
getch();
system("CLS");
cout<<"ENTER THE NUMBER OF ROWS/COLUMNS IN MATRIX A: "<<r<<endl<<endl;
cout<<"\n\n\nENTER THE OPERATOR IN ORDER TO PERFORM THE DESIRED OPERATION.";
t=0;
for(int i=0;i<r;i++)
{
   for(int j=0;j<r;j++)
      {
	 gotoxy(4+s,9+t);
	 cout<<a[i][j];
	 s+=6;
      }
      t+=2;
      s=0;
}
cout<<"\n\n\n\n\n\n"<<"1)PRESS D TO FIND DETERMINANT."<<endl<<"2)PRESS R TO RESET.";
gotoxy(r*6+8,r+8);
cin>>ch;

if(ch=='d'||ch=='D')
{
system("CLS");
cout<<"ENTER THE NUMBER OF ROWS/COLUMNS IN MATRIX A: "<<r<<endl<<endl;
cout<<"\n\n\nENTER THE OPERATOR IN ORDER TO PERFORM THE DESIRED OPERATION.";
t=0;
for(int i=0;i<r;i++)
{
   for(int j=0;j<r;j++)
      {
	 gotoxy(4+s,9+t);
	 cout<<a[i][j];
	 s+=6;
      }
      t+=2;
      s=0;
}
gotoxy(r*6+8,r+8);
cout<<"=";


    
for(int i=0,j=0;i<r-1,j<r-1;i++,j++)
{
	
	if(a[i][i]==0)
	{
        h++;
	    for(int w=i+1;w<r;w++)
	    {
		    if(a[w][i]!=0)
		    {
		 	   c++;
		 	
		       for(int p=0;p<r;p++)
               {
                   temp=a[i][p];
                   a[i][p]=a[w][p];
                   a[w][p]=temp;
               }
               break;
	         }
	     }
           
    if(c==0)
	{
		q++;
		t=0;
        for(int m=0;m<r;m++)
        {
	        for(int n=0;n<r;n++)
	        {
		        gotoxy(r*6+16+s,9+t);
		        cout<<a[m][n];
	            s+=6;
            }
            t+=2;
	        s=0;
        }

        gotoxy(r*12+20,r+8);
        cout<<"=";
        gotoxy(r*12+28,r+8); 
        cout<<0;
        break;
	}
	}
		
	if(q==0)
    {
    
	for(int g=i;g<r-1;g++)
    {
	    v=a[g+1][j]/a[i][j];
   
        for(int k=0;k<r;k++)
        {
            z=a[i][k]*v;
            a[g+1][k]=a[g+1][k]-z; 
        }
    }
    }
}
	

if(q==0)
{	
t=0;
for(int i=0;i<r;i++)
{
    for(int j=0;j<r;j++)
    {
       gotoxy(r*6+16+s,9+t);
       cout<<a[i][j];
       s+=6;
    }
    t+=2;
    s=0;
}

if(h%2!=0)
{
   h=-1;
}

else
{
   h=1;
}

gotoxy(r*12+20,r+8);
cout<<"=";
gotoxy(r*12+28,r+8);
for(int i=0;i<r;i++)
{
	h=h*a[i][i];
}
cout<<h;
}
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
}

if(ch=='r'||ch=='R')
{
	system("CLS");
	goto test;
}

return 0;
}
