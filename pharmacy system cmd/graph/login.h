system("cls");
class treat{
private:
	char name[30], effect[5],amount[10],price[10];
public:
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
void search4name_treat(char f[],string nm,int qua)
   {
	   ofstream b("bill.txt",ios::app);
	   b.close();
	   fstream temp(f,ios::in|ios::out);
	   int pos;
	   while(!temp.eof())
	   {
		   pos=temp.tellg();
		   temp.getline(name,sizeof(name),'!');
		   temp.getline(effect,sizeof(effect),'|');
		   temp.getline(amount,sizeof(amount),'|');
		   temp.getline(price,sizeof(price),'#');
		   strcpy(name,filter_name(name).c_str());
		   if(name==nm)
		   {
			   if(atoi(amount)>=qua)
			   {
			   temp.seekp(pos+1,ios::beg);
			   temp<<name<<"!"<<effect<<"|"<<atoi(amount)-qua<<"|"<<price<<"#"<<"\t";
			   b.open("bill.txt",ios::app);
			   b<<name<<"|"<<qua<<"|"<<price<<"#";
			   b.close();
			   return;
			   }
			   else if(atoi(amount)<qua)
			   {
				   int eff=atoi(effect);
				   string nm_ex=name;
				   while(!temp.eof())
				   {
					   pos=temp.tellg();
					   temp.getline(name,sizeof(name),'|');
					   temp.getline(effect,sizeof(effect),'|');
					   temp.getline(amount,sizeof(amount),'|');
					   temp.getline(price,sizeof(price),'#');
					   if(eff==atoi(effect)&&nm!=name)
					   {
						   if(qua<=atoi(amount))
							{
							int choice_n;
							cout<<"\n There is Alternative for this treatment is called : "<<name<<"\n";
							cout<<"\n 1.accept 2.refuse\n";
							cout<<"\n Your Choice:\\";
							cin>>choice_n;
								if(choice_n==1)
								{
							  temp.seekp(pos+1,ios::beg);
			                  temp<<name<<"!"<<effect<<"|"<<atoi(amount)-qua<<"|"<<price<<"#"<<"\t";
							   b.open("bill.txt",ios::app);
			                   b<<name<<"|"<<qua<<"|"<<price<<"#";
							   b.close();
							  return ;
								}
								else
									return;
									   
							}
						   else
						   {
							   cout<<"The quantity of this treatment is not enough for your order ";
					           return ;
						   }
					   }
			      }
				    cout<<"This treatment is not Found";
				   return;
		      }
		   }
   
   }
	    cout<<"This treatment is not Found";
	 return ;
}
};

treat tr;int quan;
	fstream mfile;int num;string name_treat;
	mfile.open("treatments.txt",ios::in|ios::out);
	cout<<"\n Enter the number of sorts of treatments:";
	cin>>num;
	for(int i=1;i<=num;i++)
	{
	cout<<"\n Enter the name of the treatment:";
	cin>>name_treat;
	cout<<"\n Enter the quantity:";
	cin>>quan;
	tr.search4name_treat("treatments.txt",name_treat,quan);
	}
	
	gotoxy(30,20);
	cout<<"Print The Bill";
	getche();
	setcolor('B');
	gotoxy(30,20);
	cout<<"Print The Bill";
	setcolor('G');
	getche();


