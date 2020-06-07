#include <stdio.h>
#include<conio.h>
#include<string.h>
//Compiler version gcc  6.3.0
char player1[50]={'P','L','A','Y','E','R','1','\0'},player2[50]={'P','L','A','Y','E','R','2','\0'};
int score1,score2;
int a[3][3]={1,2,3,4,5,6,7,8,9};
char b[3][3]={'1','2','3','4','5','6','7','8','9'};
void score()
{
    printf("\n\n\t\t");
    printf("\t\t%s : %d",player1,score1);
    printf("\n\n\t\t");
    printf("\t\t%s : %d",player2,score2);

}
void reIntialize()
{
    int i,j;
    char n ='1';
    for( i = 0;i<3;i++)
    {
      for( j=0;j<3;j++) 
      {
          b[i][j]=n;
          n=n+1;
      } 
    }
}
void layout()
{
  int i,j,f=0,s=0;
  printf("\n\t\t\t\tTIC TAC TOE\n");
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
void play()
{
    int i,j,posn,start,win;
    char ch;
    score1=0;score2=0;
    re1 :
  clrscr();
  layout();
  printf("\n\n\t  ENTER PLAYER1 NAME : ");
  fflush(stdin);
  gets(player1);
  if(player1[0]==' ' || player1[0]=='\0')
  {
      
    goto re1;
  }
  re2:
  printf("\n\n\t  ENTER PLAYER2 NAME : ");
  fflush(stdin);
  gets(player2);
  if(player2[0]==' ' || player2[0]=='\0')
  {
    printf("\n\t  DONOT ENTER BLANK SPACE AT START\n");
    goto re2;
  }
  if(strcmp(player1,player2)==0)
  {
    printf("\n\t  DONOT ENTER SAME NAME AS IN  PLAYER1\n");
    goto re2;  
  }

  clrscr();
  layout();
 
 
   enterstart:
   printf("\n\n  who will start first 1 or 2: ");
   scanf("%d",&start);
   if(start!=1 && start!=2)
   {
     printf("  you have eneter wrong choice\n");
     goto enterstart;
   }
   reEntry:
   for(i=0;i<9;i++)
   {
       score();
     if((i+start)%2!=0)
     {
       enterposn1:
       
       printf("\n  %s chance\n  enter position: ",player1);
       scanf("%d",&posn);
       if(posn<1 || posn>9)
       {
         printf("\n  entered wrong posn\n");
          goto enterposn1;
       }
       put_sign(posn,'X');
       clrscr();
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
       printf("\n  %s chance\n  enter position: ",player2);
       scanf("%d",&posn);
       if(posn<1 || posn>9)
       {
         printf("\n  entered wrong posn\n");
          goto enterposn2;
       }
       put_sign(posn,'O');
       clrscr();
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
     printf("\n  player1 wins");
     score1++;
   }
   else if(win==2)
   {
     printf("\n  player2 wins");
     score2++;
   }
   else
   {
     printf("\n  draw game");
   }
   reIntialize();
   printf("\n\n   Do you want to See More Result (y/n)?");
   fflush(stdin);
   scanf("%c",&ch);
   if(ch=='y' || ch=='Y')
   {
     
     start++;
     clrscr();
     layout();
     goto reEntry;

   }
   getch();
}
void instr()
{
    clrscr();
    layout();
    printf("\n\n\t\t\t\tINSTRUCTIONS\n");
    printf("\n\t 1. The game is played on a grid that's 3 squares by 3 squares.\n");
    printf("\n\t 2. You are X, your friend (or the computer in this case) is O.\n\t  Players take turns putting their marks in empty square \n");
    printf("\n\t 3. The first player to get 3 of her marks in a row (up, down, across,\n\t  or diagonally) is the winner. \n");
    printf("\n\t 4. When all 9 squares are full, the game is over.\n");
    printf("\n\t 5. Enter the postion shown in above layout to place your symbol.\n\n");
    printf("\n\t\t\t\tALL THE BEST!!!\n");
    getch();
}
void mainmenu()       //MAIN MENU
 {
	char ch;
     do                        
    {
      clrscr();
      printf("\n\n\n\tMAIN MENU");
      printf("\n\n\t01. PLAY");
      printf("\n\n\t02. INSTRUCTION");
      printf("\n\n\t03. EXIT");
      printf("\n\n\tPlease Select Your Option (1-3)\n\t ");
       ch=getche();
      switch(ch)
      {
         case '1': clrscr();
	       play();
           
               break;
          case '2': instr();
                break;
          case '3':exit(0);
          default :printf("\a");
    }
    }while(ch!='3');
 }
void intro()  //INTRODUCTION
{
 clrscr();
 gotoxy(35,11);
 printf("TIC   TAC");
 gotoxy(33,13);
 printf("     TOE");
 gotoxy(35,16);
 printf(" PROJECT");
 printf("\n\n\n\n\n\n  MADE BY : CHRIS CORREIA");
 printf("\n\n  COLLEGE : DJ. SANGHVI COLLEGE OF ENGINEERING ");
 getch();
}
void main()
{
  clrscr();
  intro();
  mainmenu();
   
  }