/*
*	Copyright 2009 idleCool. All rights reserved.
*
*	Redistribution and use in source and binary forms, with or without modification, are
*	permitted provided that the following conditions are met:
*
*	   1. Redistributions of source code must retain the above copyright notice, this list of
*	      conditions and the following disclaimer.
*
*	   2. Redistributions in binary form must reproduce the above copyright notice, this list
*	      of conditions and the following disclaimer in the documentation and/or other materials
*	      provided with the distribution.
*
*	THIS SOFTWARE IS PROVIDED BY iDLECOOL ``AS IS'' AND ANY EXPRESS OR IMPLIED
*	WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
*	FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL iDLECOOL OR
*	CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
*	CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
*	SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
*	ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
*	NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
*	ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*	The views and conclusions contained in the software and documentation are those of the
*	authors and should not be interpreted as representing official policies, either expressed
*	or implied, of idleCool.
*/

//snakes and ladders implementation in C

#include <stdio.h>
#include <time.h>
main()
{
int a=0,b=0,p=0,e=0,f,x,y=0,i;
char n;
int c[]={4,22,44,62,70,33,47,58,78,99};  //location of ladders (first 5) location of snakes(later 5)
int d[]={15,33,22,20,21,-10,-22,-10,-22,-56};  //jump values in case of snake or ladder

time_t t;		//initialising/seeding random values
t=time(NULL);
srand(t);

while (1)
{
f=(e%2)+1;			//condition to swap player 1 and player 2
printf("Player %d Turn\n",f);

 
while(1)				//rolling dice
  {
  printf("Press Enter/Return to Roll the the dice");
  scanf("%c",&n);
  if (n==10)		// 10 is the ASCII code of return/enter or line break \n
    {
    x=(rand()%6)+1;
    break;
    }     
  }
  printf("The dice tuned to be : %d\n",x);	//rolling dice



while(1)		// case when dice turns to be 6
  {
  if (x!=6 && y!=6)
  break;
  while(1)		// loop condition to roll the dice
    {
    printf("Your dice returned to be 6. So, \n");
    printf("Press Enter/Return to roll the dice again");
    scanf("%c",&n);		// 10 is the ASCII code for return/enter or line break \n
    if (n==10)
      {
      y=(rand()%6)+1;
      break;
      }
    }			// end of dice loop
   printf("The new dice value is %d\n",y);
   x=x+y;
   }		//end of case 6

if (f==1)		//passing the value of a to a dummy value
  p=a;
if (f==2)		//passing the value of b to a dummy value
  p=b;

if (p+x > 100)
  printf("The Value exceeds 100 so the player will not move\n");
else if (p+x <= 100)
  {
  p=p+x;			//increment of player position according to the return value from dice roll

  for(i=0;i<10;i++)		//condition to check snakes and ladders
    {
    if (p==c[i])
    p=p+d[i];
    }
  }

if (f==1)
  {
  a=p;			//geting back the value of a from a dummy value
  printf("Player 1 value = %d\n",a);
  }
if (f==2)
  {
  b=p;			//getting back the value of b from a dummy value
  printf("Player 2 value = %d\n",b);
  }

if (a==100)
  {
  printf("Player 1 wins the game\n");		//case when player 1 wins
  break;
  }
if (b==100)
  {
  printf("Player 2 wins the game\n");		//case when player 2 wins
  break;
  }
e++;
}

printf("Game Over\n");				//end of the game, end of all loops
}