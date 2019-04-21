static int total_quantity=0;
static float total_price=0;
system("cls");

class bill
{
private :
	char name[30],qu[10],pr[20];int x;

public :
    bill()
	{
	x=8;
	}
	void getdatab()
	{
		fstream temp("bill.txt",ios::in|ios::out);
	
	     if(!temp)
		 {
		
#include"bill_design.h";

			 gotoxy(7,10);
			 cout<<"You do not buy any medicines\n";
		     return;
		 }
		 int to;float pri;
		while(!temp.eof())
		{
			temp.getline(name,sizeof(name),'|');
			temp.getline(qu,sizeof(qu),'|');
			temp.getline(pr,sizeof(pr),'#');
			gotoxy(1,x);
			cout<<"-----------------------------------------------------------\n";
			cout<<" Medicine Name: "<<name<<"\t";
			cout<<" Quantity: "<<qu<<"\t";
			cout<<" Price: "<<pr<<endl;
			x+=2;
			stringstream sr(qu);
			sr>>to;
			total_quantity+=to;

			stringstream prs(pr);
			prs>>pri;
			total_price+=(to*pri);
		}
		total_quantity-=to;
		total_price-=(to*pri);
		temp.close();
		remove("bill.txt");
	}
};

class set{
private:
	char name[50], password[10],address[70];string quantity;
public:
	set()
	{
	quantity="0";
	}
	void get_data_nm(fstream &f)
	{
#include"login_signup.h";
		
		gotoxy(1,2);
		cin>>name;
		f<<name<<"!";
		 gotoxy(1,8);
		f<<getpass()<<"|";
		 gotoxy(1,14);
		cin>>address;
		f<<address<<"|";
		f<<quantity<<"#"<<"\t\t";
	
		cout<<"\n\n";
#include"confirm.h";
		setcolor('B');
		gotoxy(5,18);
		cout<<"Confirm";
		getche();
	   
	}
	//----------override-------------------
		void get_data(fstream &f)
	{
#include"login_signup.h";
		
		gotoxy(1,2);
		cin>>name;
		f<<"\t\t"<<name<<"!";
		 gotoxy(1,8);
		f<<getpass()<<"|";
		 gotoxy(1,14);
		cin>>address;
		f<<address<<"|";
		f<<quantity<<"#";
	
		cout<<"\n\n";
#include"confirm.h";
		setcolor('B');
		gotoxy(5,18);
		cout<<"Confirm";
		getche();
	   
	}
		//--------------------------------------------
	//password func
string  getpass()
{
	int arr_pass[10],i=0;string pass_word;
lab_pass:arr_pass[i]=getch();
	pass_word+=arr_pass[i];
	if(arr_pass[i]!='\r')
	{
	cout<<"*";
	i++;
	goto lab_pass;
	}
	pass_word=pass_word.substr(0,pass_word.length()-1);
	cout<<endl;
	return pass_word;
}
   void display_data()
   {
#include"login_signup.h";
	cout<<"\n\nQuantity:\n";
#include"confirm.h";
	setcolor('G');
	gotoxy(50,23);
	cout<<"Back";
	gotoxy(1,2);
	cout<<name;
	gotoxy(1,8);
	cout<<password;
	gotoxy(1,14);
	cout<<address;
	gotoxy(1,20);
	cout<<quantity;

   }
    //---------------filter---------------------
   string filter_name(string name)
   {
	   string word="";
	   for(int i=0;i<name.length();i++)
	   {
		   if(name[i]=='#'||name[i]=='\t')
			  word.clear();
		   else
		     word+=name[i];
	   }
   
   return word;
   
   }

   //------------------------------------------
  //search by nm&&pass
   void search_account(char f[],string nm,string pass)
   {
	   fstream temp(f,ios::in|ios::out);
	   int offset;
	   while(!temp.eof())
	   {
		   offset=temp.tellg();
		   temp.getline(name,sizeof(name),'!');
		   temp.getline(password,sizeof(password),'|');
		   temp.getline(address,sizeof(address),'|');
		   getline(temp,quantity,'#');
	         strcpy(name,filter_name(name).c_str());
		   if(name==nm&&password==pass)
		   {
#include"login.h";
			   system("cls");
			   gotoxy(30,0);
			   cout<<"The Bill\n";
#include"bill_design.h";
			   gotoxy(1,4);
			   cout<<"Name: "<<name<<endl;
			   gotoxy(1,6);
			   cout<<"Address: "<<address<<endl;
			  bill b;
			  b.getdatab();
			  //------------------------override----------------
			
			   static int oo;
			   int pos=searchforaccount(f,nm,pass);
			   fstream temp(f,ios::in|ios::out);
			   if(pos!=-1)
			   {
			   temp.seekp(pos,ios::beg);
			   stringstream turn(quantity);
			   turn>>oo;
			   stringstream g;
			   g<<(total_quantity+oo);
			   quantity=g.str();
			 
			   temp<<nm<<"!"<<pass<<"|"<<address<<"|"<<quantity<<"#"<<"\t\t";
			   }
			   temp.close();
			  //---------------------------------------------------
			  cout<<" ------------------------------------------------------------\n";
			  if((total_quantity+oo)>=10)
			  {
				  cout<<" Discount: 1%\n";
			   cout<<" -----------------------------------------------------------\n";
			   cout<<" Total price: "<<0.01*total_price<<" L.E"<<endl;
			  }
			  else if((total_quantity+oo)>=20)
			  {
				  cout<<" Discount: 2%\n";
			   cout<<"-----------------------------------------------------------\n";
			   cout<<" Total price: "<<0.02*total_price<<" L.E"<<endl;
			  }
			  else if((total_quantity+oo)>=30)
			  {
				  cout<<" Discount: 3%\n";
				 cout<<"-----------------------------------------------------------\n";
			   cout<<" Total price: "<<0.03*total_price<<" L.E"<<endl;
			  }
			  else
			  {
				  cout<<" Discount: 0%\n";
				 cout<<"-----------------------------------------------------------\n";
				
			     cout<<" Total price: "<<total_price<<" L.E"<<endl;
			  }
		    
			   getche();
			return;
		   }
	   }
	  cout<<"\n\nThis Account Is Not Found\n"; 

	   gotoxy(50,20);
	   setcolor('G');
	   cout<<"Back";
	   getche();
	   gotoxy(50,20);
	   setcolor('B');
	   cout<<"Back";
	 
   }
   //overload for treating//
     int search4account(char f[],string nm,string pass)
   {
	   fstream temp(f,ios::in|ios::out);
	   int offset;
	   while(!temp.eof())
	   {
		   offset=temp.tellg();
		   temp.getline(name,sizeof(name),'!');
		   temp.getline(password,sizeof(password),'|');
		   temp.getline(address,sizeof(address),'|');
		   getline(temp,quantity,'#');
	  strcpy(name,filter_name(name).c_str());
		   if(name==nm&&password==pass)
		   {
			   system("cls");
			   display_data();
			   return offset+2;
		   }
	   }
	   cout<<"\n\nThis Account Is not Found\n"; 
	   gotoxy(50,20);
	   setcolor('G');
	   cout<<"Back";
	   getche();
	   gotoxy(50,20);
	   setcolor('B');
	   cout<<"Back";
	   return -1;
   }
	 //---------------------------override---------------------
  int searchforaccount(char f[],string nm,string pass)
   {
	   fstream temp(f,ios::in|ios::out);
	   int offset;
	   while(!temp.eof())
	   {
		   offset=temp.tellg();
		   temp.getline(name,sizeof(name),'!');
		   temp.getline(password,sizeof(password),'|');
		   temp.getline(address,sizeof(address),'|');
		   getline(temp,quantity,'#');
	  strcpy(name,filter_name(name).c_str());
		   if(name==nm&&password==pass)
		   {
			   return offset+2;
		   }
	   }
	   return -1;
   }
		//------------------------------------------------------------------
   //overload func
   //search by nm&&pass
   int search_for_account(char f[],string pass)
   {
	   fstream temp(f,ios::in|ios::out);
	   int offset;
	   while(!temp.eof())
	   {
		   offset=temp.tellg();
		   temp.getline(name,sizeof(name),'!');
		   temp.getline(password,sizeof(password),'|');
		   temp.getline(address,sizeof(address),'|');
		   getline(temp,quantity,'#');
	  strcpy(name,filter_name(name).c_str());
		   if(password==pass)
		   {
			   system("cls");
			   display_data();
			   	setcolor('G');
	            gotoxy(50,23);
	            cout<<"Retrieve";
				getche();
				setcolor('B');
	            gotoxy(50,23);
	            cout<<"Retrieve";
			   return offset+2;
		   }
	   }
	   cout<<"\n\nThis Account Is Not Found\n"; 

	   gotoxy(50,20);
	   setcolor('G');
	   cout<<"Back";
	   getche();
	   gotoxy(50,20);
	   setcolor('B');
	   cout<<"Back";

	   return -1;
	
   }
   //------------
   void _delete(char f[],string nm,string pass)
   {
	  
	   int pos=search4account(f,nm,pass);
	   fstream temp(f,ios::in|ios::out);
	   if(pos!=-1)
	   {
	   temp.seekp(pos,ios::beg);
	    gotoxy(50,23);
		setcolor('G');
		cout<<"Delete";
		getche();
		gotoxy(50,23);
		setcolor('B');
		cout<<"Delete";
		getche();
		setcolor('G');
	   temp<<"*";
	   }
   }
   void update(char f[],string nm,string pass)
   {
	   int pos=search4account(f,nm,pass);
	   fstream temp(f,ios::in|ios::out);
	   if(pos!=-1)
	   {
	   temp.seekp(pos,ios::beg);
	   	gotoxy(50,23);
		setcolor('G');
		cout<<" new";
		getche();
		gotoxy(50,23);
		setcolor('B');
		cout<<" new";
		getche();
		setcolor('G');
		system("cls");
	    get_data_nm(temp);
		
	   }
   
   
   }
   void retrive(char f[],string name,string pass)
   {
       int pos=search_for_account(f,pass);
	   fstream temp(f,ios::in|ios::out);
	   if(pos!=-1)
	   {
	   temp.seekp(pos,ios::beg);
		temp<<name;
	   }
   }
};


set st;
switch(op)
	{
	case 1:
			myfile.open("file.txt",ios::in|ios::app);
			st.get_data(myfile);
			myfile.close();
		break;
	case 2:
		#include"name_password.h";
		gotoxy(1,2);
		cin>>name;
		gotoxy(1,8);
		st.search_account("file.txt",name,st.getpass());
		break;
	case 3:
#include"name_password.h";
		gotoxy(1,2);
		cin>>name;
		gotoxy(1,8);
		st._delete("file.txt",name,st.getpass());
		break;
	case 4:
#include"name_password.h";
		gotoxy(1,2);
		cin>>name;
		gotoxy(1,8);
		st.update("file.txt",name,st.getpass());
		break;
	case 5:
		
		#include"name_password.h";
		gotoxy(1,2);
		cin>>name;
		gotoxy(1,8);
		st.retrive("file.txt",name,st.getpass());
		break;
	case 6:
		
		cout<<"Name:\n";
#include"confirm.h";
		cout<<"\n\n\nPassword:\n";
		#include"confirm.h";
	    gotoxy(1,2);
		cin>>name;
		gotoxy(1,9);
		st.search4account("file.txt",name,st.getpass());

	    getche();
		gotoxy(50,23);
		setcolor('B');
		cout<<"Back";
		setcolor('G');
		system("cls");
		
		break;
	}
	

