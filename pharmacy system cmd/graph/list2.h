
    #include"make_desin.h";
	#include"make_desin.h";
	#include"make_desin.h";
    #include"make_desin.h";
    #include"draw2.h";
  char press;int ress=1;string x;
  while(true)
  {
  press=getch();
  if(press=='\t')
  {
       #include"draw2.h";
	   gotoxy(1,ress);
	   setcolor('R');
	   cout<<"\2";
	   setcolor('G');
	   if(ress==1)
	   {
		   x="Display";

		   for(int i=0;i<x.length();i++)
		   {
		   _sleep(100);
		   cout<<x[i];
		   }
	   }
	   else if(ress==4)
	   {
	     x="Update";
		   for(int i=0;i<x.length();i++)
		   {
		   _sleep(100);
		   cout<<x[i];
		   }
	   
	   }
	   else if(ress==7)
	   {
	       x="Delete";
		   for(int i=0;i<x.length();i++)
		   {
		   _sleep(100);
		   cout<<x[i];
		   }
	   
	   }
	      else if(ress==10)
	   {
	       x="Retrieve";
		   for(int i=0;i<x.length();i++)
		   {
		   _sleep(100);
		   cout<<x[i];
		   }
	   
	   }

	  if(ress==10)
	  ress=1;
      else
	  ress+=3;
  }
  
   else if(press=='\r')
   {
  if(ress==4)
  {
  op=6;
#include"signup.h";
  break;
  }
  else if(ress==1)
  {
	  op=5;
#include"signup.h";
	  break;
  }
  else if(ress==7)
  {
	  op=4;
#include"signup.h";
	    break;
  }
  else if(ress==10)
  {
	  op=3;
#include"signup.h";
	  break;

  }
  
  }

  }

