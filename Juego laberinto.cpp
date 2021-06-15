#include <iostream>
#include <windows.h>
#include <string.h>
#include <conio.h>

using namespace std;

void portada()
{
	cout<<"\t\t                      ^\    ^                   "<<endl;
	cout<<"\t\t                      / \\  / \                 "<<endl;
	cout<<"\t\t                     /.  \\/   \      |\___/|   "<<endl;
	cout<<"\t\t  *----*           / / |  \\    \  __/  O  O\   "<<endl;
	cout<<"\t\t  |   /          /  /  |   \\    \_\/  \     \  "<<endl;
	cout<<"\t\t / /\/         /   /   |    \\   _\/    '@___@  "<<endl;
	cout<<"\t\t/  /         /    /    |     \\ _\/       |U	   "<<endl;
	cout<<"\t\t|  |       /     /     |      \\\/        |     "<<endl;
	cout<<"\t\t\  |     /_     /      |       \\  )   \ _|_    "<<endl;
	cout<<"\t\t\   \       ~-./_ _    |    .- ; (  \_ _ _,\'   "<<endl;
	cout<<"\t\t~    ~.           .-~-.|.-*      _        {-,   "<<endl;
	cout<<"\t\t \      ~-. _ .-~                 \      /\'    "<<endl;
	cout<<"\t\t  \                   }            {   .*       "<<endl;
	cout<<"\t\t   ~.                 '-/        /.-~----.      "<<endl;
	cout<<"\t\t     ~- _             /        >..----.\\\"     "<<endl;
	cout<<"\t\t         ~ - - - - ^}_ _ _ _ _ _ _.-\\\"        "<<endl<<endl;
	cout<<"\t\t _____ __       __    _____ _____ _____ _____ _____ _____ _____ _____ "<<endl;
	cout<<"\t\t|   __|  |     |  |  |  _  | __  |   __| __  |     |   | |_   _|     |"<<endl;
	cout<<"\t\t|   __|  |__   |  |__|     | __ -|   __|    -|-   -| | | | | | |  |  |"<<endl;
	cout<<"\t\t|_____|_____|  |_____|__|__|_____|_____|__|__|_____|_|___| |_| |_____|"<<endl;
	cout<<"PRESIONA CUALQUIR TECLA";
	getch();
	fflush(stdin);
	system("cls");
}



string mapa[20]={"  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦",
				 "                 ¦¦             ¦¦                         ¦¦",
				 "  ¦¦¦¦¦¦¦¦¦¦¦    ¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦  ¦¦  ¦¦¦¦¦¦¦¦¦¦¦",
				 "  ¦¦¦¦¦¦  ¦¦¦    ¦¦             ¦¦¦¦¦¦  ¦¦¦¦  ¦¦  ¦¦¦       ¦",
				 "  ¦¦¦       ¦             ¦¦¦¦          ¦¦¦¦  ¦¦¦¦¦    ¦¦¦  ¦",
				 "  ¦¦¦   ¦¦¦¦¦    ¦¦¦¦¦¦¦¦¦¦¦ ¦  ¦¦¦¦¦¦¦¦¦         ¦¦¦¦¦¦¦   ¦",
				 "  ¦¦¦            ¦           ¦  ¦      ¦¦¦¦  ¦¦¦¦¦¦        ¦¦",
				 "  ¦     ¦¦¦¦¦    ¦¦¦   ¦¦¦¦¦¦¦  ¦  ¦¦            ¦¦  ¦¦¦¦¦¦¦¦",
				 "  ¦¦¦   ¦¦¦¦¦    ¦           ¦  ¦¦¦¦¦  ¦¦¦¦¦¦¦¦  ¦¦         _",
				 "  ¦¦¦   ¦¦¦¦¦¦¦¦¦¦¦¦   ¦¦¦¦  ¦  ¦¦¦          ¦¦      ¦¦  ¦¦ _",
				 "  ¦                    ¦¦¦¦  ¦  ¦¦¦¦¦¦¦¦¦  ¦¦¦¦  ¦¦  ¦¦  ¦¦¦¦",
				 "  ¦¦¦   ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦             ¦¦¦¦  ¦¦¦¦¦¦    ¦¦",
				 "  ¦¦¦   ¦¦         ¦   ¦¦¦¦  ¦¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦¦  ¦       ¦¦¦¦",
				 "  ¦         ¦¦¦¦¦  ¦¦        ¦     ¦  ¦¦         ¦¦¦¦¦¦    ¦¦",
				 "  ¦¦  ¦¦¦¦¦¦¦  ¦¦  ¦¦¦¦¦  ¦¦¦¦  ¦¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦",
				 "  ¦¦  ¦¦    ¦      ¦¦¦¦¦  ¦¦¦¦    ¦¦           ¦¦¦¦         ¦",
				 "  ¦¦  ¦¦¦¦  ¦¦¦¦¦¦¦¦      ¦¦¦¦¦¦  ¦¦  ¦¦¦¦¦¦¦     ¦¦¦¦¦  ¦  ¦",
				 "  ¦¦        ¦¦        ¦¦          ¦¦        ¦            ¦  ¦",
				 "  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦"};

//	Deteccion de eventos
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

//	Funcion GOTOXY
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
 
 //	Funcion para que el cursor no sea visible en la ejecucion
void setcursor(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
	if(size == 0)
	{
		size = 20;	// por defecto el cursor tiene 20 de ancho
 	}
	CONSOLE_CURSOR_INFO lpCursor;	
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console,&lpCursor);
}

//	Funcion para dibujar el escenario
void scenario()
{
	for (int i=0; i<20; i++)
		cout<<mapa[i]<<endl;
}
//	Funcion que detecta una colision dentro del escenario. camino=32 es el espacio en blanco
bool colision(int x, int y)
{
	char camino=32;
	
	if (mapa[y][x] == camino)
		return true;
	else
		return false;
}

void move(int hx, int hy)
{
	char mov;
	bool ingame=true;
	
	while (ingame)
	{
		fflush(stdin);
		mov=getch();
		gotoxy(hx,hy); cout<<" ";
		
		if (mov == 77 && colision(hx+1, hy))
			hx++;

		else if (mov == 75 && colision(hx-1, hy))
			hx--;

		else if (mov == 72 && colision(hx, hy-1))
			hy--;
			
		else if (mov == 80 && colision(hx, hy+1))
			hy++;
		
		else if (mov==27 || mapa[hy][hx]==220 )
			ingame=false;
			
		gotoxy(hx,hy); cout<<"#";
	}
}

int main()
{
	setcursor(0,0);//oculta cursor
	portada();
	scenario();
	move(0,0);
	return 0;
}




  








