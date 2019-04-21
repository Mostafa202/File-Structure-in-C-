  
    #include"make_desin.h";
	#include"make_desin.h";
	#include"make_desin.h";
    #include"draw.h";
  char press;int ress=1;string x;
  while(true)
  {
  press=getch();
  if(press=='\t')
  {
       #include"draw.h";
	   gotoxy(1,ress);
	   setcolor('R');
	   cout<<"\2";
	   setcolor('G');
	   if(ress==1)
	   {
		   x="Login";

		   for(int i=0;i<x.length();i++)
		   {
		   _sleep(100);
		   cout<<x[i];
		   }
	   }
	   else if(ress==4)
	   {
	     x="Sign Up";
		   for(int i=0;i<x.length();i++)
		   {
		   _sleep(100);
		   cout<<x[i];
		   }
	   
	   }
	   else if(ress==7)
	   {
	       x="Settings";
		   for(int i=0;i<x.length();i++)
		   {
		   _sleep(100);
		   cout<<x[i];
		   }
	   
	   }

	  if(ress==7)
	  ress=1;
      else
	  ress+=3;
  }
  
   else if(press=='\r')
   {
  if(ress==4)
  {
	  op=2;
#include"signup.h";
	  break;
  }
  else if(ress==7)
  {
	  op=1;
#include"signup.h";

	  break;
  }
  else if(ress==1)
  {
#include"settings.h";

	  break;
  }
  
  }

  }

