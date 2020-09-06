#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
bool gameover;
const int height=30;
const int width=30;
int x,y,fruitx,fruity,score=0;
int tailx[100],taily[100],taill=0;
enum eDirection { STOP=0 , LEFT , RIGHT , UP , DOWN}dir;
//eDirection dir;
void setup()
{
	gameover=false;
	x=width/2;
	y=height/2;
	fruitx=rand()%width;
	fruity=rand()%height;
	score=0;
}
void draw()
{
	char c=1;
	system("cls");
	int i,j;
	for(i=0;i<width+1;i++)
		cout<<"#";
		cout<<"\n";
	for(i=1;i<height;i++)
	{
		for(j=0;j<=width;j++)
		{
			if(j==0||j==width)
			cout<<"#";
			else if(i==y&&j==x)
			cout<<c;
			else if(i==fruity&&j==fruitx)
			cout<<"O";
			else
			{
				bool space=false;
				for(int k=0;k<taill;k++)
				{
					if(x==tailx[i]&&y==taily[i])
					gameover=true;
				if(i==taily[k]&&j==tailx[k])
				{
					cout<<"*";space=true;
				}
				}
				if(!space)
				cout<<" ";
			}
		}
		cout<<"\n";
	}
	for(i=0;i<width+1;i++)
		cout<<"#";
		cout<<"\nscore="<<score<<"\n";
}
void input()
{
	if(kbhit())
	{
	 	char c;
		c=getch();
		switch (c)
		{
		case 'w':
		{
			dir=UP;
			break;
		}
		case 'a':
		{
			dir=LEFT;
			break;
		}
		case 's':
		{
			dir=DOWN;
			break;
		}
		case 'd':
		{
			dir=RIGHT;
			break;
		}
		default :dir=STOP;
		}
	}
}
void logic()
{
	int prevx=tailx[0];
	int prevy=taily[0];
	int prev2x,prev2y;
	tailx[0]=x;
	taily[0]=y;
	for(int i=1;i<taill;i++)
	{
		prev2x=tailx[i];
		prev2y=taily[i];
		tailx[i]=prevx;
		taily[i]=prevy;
		prevx=prev2x;
		prevy=prev2y;
	}
		switch(dir)
	{
		case LEFT:
		{
			x--;
			break;
		}
		case RIGHT:
		{
			x++;
			break;
		}
		case UP:
		{
			y--;
			break;
		}
		case DOWN:
		{
			y++;
			break;
		}	
	}
	if(x>width||x<0||y>height||y<0)
			gameover=true;
			if(y==fruity&&x==fruitx)
			{
				fruitx=rand()%width;
				fruity=rand()%height;
				score+=10;
				taill++;
			}
}
int main()
{
	setup();
	while(!gameover)
	{
		draw();
		input();
		logic();
		Sleep(20);
	}
	
		return 0;
}
