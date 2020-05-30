#include <stdio.h>

//Compiler version gcc  6.3.0
int a[3][3]={1,2,3,4,5,6,7,8,9};
char b[3][3]={'1','2','3','4','5','6','7','8','9'};
void layout()
{
  int i,j,f=0,s=0;
  printf("\n\n");
  printf("\t\t");
  printf("\t\t");
  for(i=0;i<5;i++)
  {
    for(j=0;j<5;j++)
    {
      if(j%2==0 && i%2==0)
      {
        printf(" %c ",b[f][s]);
        s++;
        if(s==3)
        {
          s=0;
          f++;
        }
      }
      else if(i%2==0 && (j==1 || j==3))
      {
        printf("|");
      }
      else if(i%2!=0 && j%2==0)
      {
        printf("===");
      }
      else if(i%2!=0 && j%2!=0)
      {
        printf("|");
      }
    }
    printf("\n\t\t\t\t");
  }
}
void put_sign(int posn ,char sign)
{
  int i,j;
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      if(a[i][j]==posn)
      {
        b[i][j]=sign;
      }
    }
  }
}
int check(char sign)
{
  int i,j;
  for(i=0;i<3;i++)
  {
    if(b[i][0]==b[i][1]&& b[i][0]==b[i][2] && b[i][0]==sign)
    {
      if(sign=='X')
      return 1;
      else if(sign=='O')
      return 2;
    }
    
    else if(b[0][i]==b[1][i]&& b[0][i]==b[2][i] && b[0][i]==sign)
    {
      if(sign=='X')
      return 1;
      else if(sign=='O')
      return 2;
    }
    
    else if(b[0][0]==b[1][1]&& b[0][0]==b[2][2] && b[0][0]==sign)
    {
      if(sign=='X')
      return 1;
      else if(sign=='O')
      return 2;
    }
    
    else if(b[0][2]==b[1][1]&& b[0][2]==b[2][0] && b[0][2]==sign)
    {
      if(sign=='X')
      return 1;
      else if(sign=='O')
      return 2;
    }
    
  }
  return 0;
}
void main()
{
  int i,j,posn,start,win;
  printf("\n\t\t\t\tTIC TAC TOE\n");
  layout();
 
 
 
 
   enterstart:
   printf("\n\nwho will start first 1 or 2:\n");
   scanf("%d",&start);
   if(start!=1 && start!=2)
   {
     printf("you have eneter wrong choice\n");
     goto enterstart;
   }
   
   for(i=0;i<9;i++)
   {
     if((i+start)%2!=0)
     {
       enterposn1:
       printf("\nplayer1 chance\nenter position: ");
       scanf("%d",&posn);
       if(posn<1 || posn>9)
       {
         printf("\nentered wrong posn\n");
          goto enterposn1;
       }
       put_sign(posn,'X');
       
       layout();
       win = check('X');
       if(win)
       {
         break;
       }
     }
     else
     {
       enterposn2:
       printf("\nplayer2 chance\nenter position: ");
       scanf("%d",&posn);
       if(posn<1 || posn>9)
       {
         printf("\nentered wrong posn\n");
          goto enterposn2;
       }
       put_sign(posn,'O');
       
       layout();
       win = check('O');
       if(win)
       {
         break;
       }
     }
   }
   if(win == 1)
   {
     printf("\nplayer1 wins");
   }
   else if(win==2)
   {
     printf("\nplayer2 wins");
   }
   else
   {
     printf("\ndraw game");
   }
   
  }
