//Created By Mehedi Ahamed

#include<bits/stdc++.h>
#include<conio.h>
#include <windows.h>


int playGA();
void showCards_GA(int *a_cards, int siz);
void lucky(int aceNum);
void gotoxy(int x, int y);
void setcursor(bool visible, DWORD size);
void guessCards(int *a_cards, int siz,int aceNum);

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int optkey;
char ch;

int main()
{
	setcursor(0,0);
    playGA();
}

int playGA()
{
    setcursor(0,0);
    system("cls");
    system("color 0D");

    int cards[4],optkey;


    srand(time(NULL));

    int w,x,y,z;
    w=rand()%4+1;


    if(w==1){
        x=w+3;
        y=w+1;
        z=w+2;
    }

    if(w==2){
        x=w-1;
        y=w+1;
        z=w+2;
    }
   if(w==3){
        x=w-1;
        y=w+1;
        z=w-2;
    }



gotoxy(50,14);
printf("Shuffling");

for(int i=0; i<5;i++)
    {
        Sleep(280);
        printf(" .");
    }
system("cls");



cards[0]=w;
cards[1]=x;
cards[2]=y;
cards[3]=z;



guessCards(cards,4,w);
gotoxy(0,0);


 
}

void showCards_GA(int *a_cards, int siz)
{

	// card 'visuals' - no suits => infinite decks
     char ace1[]="\n*********\
				\n* A     *\
				\n*   *   *\
				\n*       *\
				\n*     A *\
				\n*********\n";






    char jack1[]=
	           "\n*********\
				\n* J     *\
				\n*J A C K*\
				\n*       *\
				\n*     J *\
				\n*********\n";

    char queen1[]=
	           "\n*********\
				\n* Q     *\
				\n*QU EE N*\
				\n*  + +  *\
				\n*     Q *\
				\n*********\n";

	char king1[]=
	           "\n*********\
				\n* K     *\
				\n*K I N G*\
				\n* ..... *\
				\n*  \\/ K *\
				\n*********\n";

	int c;
	for (c = 0; c < siz; c++)
	{
		switch(a_cards[c])
		{
			case(1):


				printf("%s", ace1);
				break;

			case(3):

				printf("%s", jack1);
				break;
			case(2):

				printf("%s", queen1);
				break;
			case(4):

				printf("%s", king1);
				break;
		}
	}


	gotoxy(50,14);
    std::cout<<"Your Choice :"<<optkey;
    gotoxy(0,0);
	gotoxy(50,16);
    std::cout<<"Correct Choice :"<<a_cards[0];
    gotoxy(0,0);






}

void guessCards(int *a_cards, int siz,int aceNum)
{


     gotoxy(0,0);

     char g1[]="\n*********\
				\n* x     *\
				\n*   1   *\
				\n*       *\
				\n*     x *\
				\n*********\n";


    char g2[]=
	           "\n*********\
				\n* x     *\
				\n*   2   *\
				\n*       *\
				\n*     x *\
				\n*********\n";

    char g3[]=
	           "\n*********\
				\n* x     *\
				\n*   3   *\
				\n*       *\
				\n*     x *\
				\n*********\n";

	char g4[]=
	           "\n*********\
				\n* x     *\
				\n*   4   *\
				\n*       *\
				\n*     x *\
				\n*********\n";

	int c;
	for (c = 0; c < siz; c++)
	{
		switch(a_cards[c])
		{
			case(1):


				printf("%s", g1);
				break;

			case(3):

				printf("%s", g2);
				break;
			case(2):

				printf("%s", g3);
				break;
			case(4):

				printf("%s", g4);
				break;
		}
	}




    gotoxy(0,0);
    gotoxy(50,10);
    std::cout<<"The Cards Are Shuffled ";
    gotoxy(0,0);
    gotoxy(50,14);
    std::cout<<"Guess Which Card Can be Ace ";
    gotoxy(0,0);
	gotoxy(50,16);
    std::cout<<"Choice (1-4): ";
    std::cin>>optkey;

    system("cls");



    showCards_GA(a_cards,4);


    Sleep(2500);
    system("cls");

    lucky(aceNum);


}
void lucky(int aceNum)
{




    if(aceNum==optkey)
    {
        system("color 0E");
        gotoxy(45,10);
        std::cout<<"YOU ARE LUCKY";
        gotoxy(45,13);
        std::cout<<"Want To Play Again(Y/N) :";
        char ch=toupper(getche());


        if(ch=='Y')
        {

            playGA();
        }
        else
        {
           exit(1);
          // mainMenu();
        }

    }
    else



    {
        system("color 0E");
        gotoxy(45,10);
        std::cout<<"BETTER LUCK NEXT TIME";

        gotoxy(45,13);
        std::cout<<"Want To Play Again(Y/N) :";
        char ch=toupper(getch());


        if(ch=='Y')
        {
            system("cls");
            playGA();
        }
        else
        {
            system("cls");
			exit(1);
           // mainMenu();
        }

    }
}

void gotoxy(int x, int y){
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

// set bool visible = 0(invisible), bool visible = 1(visible)

void setcursor(bool visible, DWORD size) {
	if(size == 0)
		size = 20;

	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}
