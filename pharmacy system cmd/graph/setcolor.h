void setcolor(char c)
{
	HANDLE hConsole;

	hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
	if(c=='G')

	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	if(c=='R')
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
	if(c=='B')
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}