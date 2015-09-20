#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>

using namespace std;

struct footBallPlayers
{
	string name;
	string pos;
	int TD;
	int cat;
	int psYds;
	int recYds;
	int rusYds;
};

void input(footBallPlayers list[], int LEN);
void output(footBallPlayers list[], int cap);

void searchList(footBallPlayers list[], int cap);
void searchByPos(footBallPlayers list[], int cap);
void menuList(footBallPlayers list[], int cap);
void addStats(footBallPlayers list[], int cap);
void allStats(footBallPlayers list[], int cap);
void editList(footBallPlayers list[], int cap);

ifstream infile;
ofstream outfile;

const int CAP =11;

int main()
{
	footBallPlayers player[CAP];
	input(player, CAP);
	_getch();
	return 0;
}
void input(footBallPlayers list[], int LEN)
{
	infile.open("playerInfo.txt");
	while(infile.good())
	{
        for(int i=0; i<LEN;i++)
        	{
        		infile>>list[i].name>>list[i].pos>>list[i].TD>>list[i].cat>>list[i].psYds>>list[i].recYds>>list[i].rusYds;
        	}
    }
	infile.close();
	menuList(list, LEN);
}
void output(footBallPlayers list[], int cap)
{
	outfile.open("playerInfo.txt", ofstream::trunc);
	for(int t=0;t<cap;t++)
	{
		int len;
		len=list[t].name.length();
		outfile<<list[t].name<<" "<<setw(18-len)<<list[t].pos<<" "<<setw(3)<<list[t].TD<<" "<<setw(4)<<list[t].cat<<" "<<setw(6)<<list[t].psYds<<" "<<setw(5)<<list[t].recYds<<" "<<setw(6)<<list[t].rusYds<<endl;
	}
	outfile.close();
}
void searchList(footBallPlayers list[], int cap)
{
	string ans;
	bool Loop= false;
	cout<<"Which player's stats would you like to see?"<<endl<<endl;
	cin>>ans;	
		for(int i=0;i<cap && !Loop;i++)
		{
			int len;
			string name;
			name=list[i].name;
			if(ans==name)
				{
					cout<<"Name             POS TDs Cat   PsYd RecYds RusYds"<<endl<<endl;
					len=name.length();
					cout<<name<<" "<<setw(18-len)<<list[i].pos<<" "<<setw(3)<<list[i].TD<<" "<<setw(4)<<list[i].cat<<" "<<setw(6)<<list[i].psYds<<" "<<setw(5)<<list[i].recYds<<" "<<setw(6)<<list[i].rusYds<<endl;
				}
		}
	menuList(list, cap);
}

void searchByPos(footBallPlayers list[], int cap)
{
     string reply;
     int size;
     bool Loop= false;
	cout<<"Which position would you like to see?"<<endl<<endl;
	cin>>reply;
	size = reply.length();
    char upperCase[size];
    
    for(int i = 0; i < size; i++)
    {
            upperCase[i] = toupper(reply[i]);
            }
    string ans(upperCase);
    cout<<"\n\nName             POS TDs Cat   PsYd RecYds RusYds"<<endl<<endl;
		for(int i=0;i<cap && !Loop;i++)
		{
			int len;
			string pos;
			pos=list[i].pos;
			if(ans==pos)
				{
					
					len=list[i].name.length();
					cout<<list[i].name<<" "<<setw(18-len)<<list[i].pos<<" "<<setw(3)<<list[i].TD<<" "<<setw(4)<<list[i].cat<<" "<<setw(6)<<list[i].psYds<<" "<<setw(5)<<list[i].recYds<<" "<<setw(6)<<list[i].rusYds<<endl;
				}
		}
	menuList(list, cap);
}

void allStats(footBallPlayers list[], int cap)
{
	cout<<"Name             POS TDs Cat   PsYd RecYds RusYds"<<endl<<endl;
	for(int t=0;t<cap;t++)
	{
		int len;
		len=list[t].name.length();
		cout<<list[t].name<<" "<<setw(18-len)<<list[t].pos<<" "<<setw(3)<<list[t].TD<<" "<<setw(4)<<list[t].cat<<" "<<setw(6)<<list[t].psYds<<" "<<setw(5)<<list[t].recYds<<" "<<setw(6)<<list[t].rusYds<<endl;
	}
	menuList(list, cap);
}

void editList(footBallPlayers list[], int cap)
{
	string ans;
	
	cout<<"Which player's stats would you like to edit?"<<endl<<endl;
	cin>>ans;	
		for(int i=0;i<cap;i++)
		{
			int len;
			string name;
			name=list[i].name;
			if(ans==list[i].name)
				{
					cout<<"Name             POS TDs Cat   PsYd RecYds RusYds"<<endl<<endl;
					len=name.length();
					cout<<name<<" "<<setw(18-len)<<list[i].pos<<" "<<setw(3)<<list[i].TD<<" "<<setw(4)<<list[i].cat<<" "<<setw(6)<<list[i].psYds<<" "<<setw(5)<<list[i].recYds<<" "<<setw(6)<<list[i].rusYds<<endl;
					cout<<"Enter new stats for "<<name<<endl<<"POS: ";
					cin>>list[i].pos;
					cout<<endl<<"TDs: ";
					cin>>list[i].TD;
					cout<<endl<<"Catches: ";
					cin>>list[i].cat;
					cout<<endl<<"PsYds: ";
					cin>>list[i].psYds;
					cout<<endl<<"RecYds: ";
					cin>>list[i].recYds;
					cout<<endl<<"RusYds: ";
					cin>>list[i].rusYds;
				cout<<"Name             POS TDs Cat   PsYd RecYds RusYds"<<endl<<endl;
				len=name.length();
				cout<<name<<" "<<setw(18-len)<<list[i].pos<<" "<<setw(3)<<list[i].TD<<" "<<setw(4)<<list[i].cat<<" "<<setw(6)<<list[i].psYds<<" "<<setw(5)<<list[i].recYds<<" "<<setw(6)<<list[i].rusYds<<endl;
			}
		}
	menuList(list, cap);
}
void addStats(footBallPlayers list[], int cap)
{
     string ans;
	
	cout<<"Which player's totals would you like to add to?"<<endl<<endl;
	cin>>ans;	
		for(int i=0;i<cap;i++)
		{
			int len, td, cat, PsYds, RecYds, RusYds;
			string name;
			name=list[i].name;
			if(ans==list[i].name)
				{
					cout<<"Name             POS TDs Cat   PsYd RecYds RusYds"<<endl<<endl;
					len=name.length();
					cout<<name<<" "<<setw(18-len)<<list[i].pos<<" "<<setw(3)<<list[i].TD<<" "<<setw(4)<<list[i].cat<<" "<<setw(6)<<list[i].psYds<<" "<<setw(5)<<list[i].recYds<<" "<<setw(6)<<list[i].rusYds<<endl;
					cout<<endl<<"TDs: ";
					cin>>td;
                    list[i].TD = list[i].TD + td;
					cout<<endl<<"Catches: ";
					cin>>cat;
                    list[i].cat = list[i].cat + cat;
					cout<<endl<<"PsYds: ";
					cin>>PsYds;
                    list[i].psYds = list[i].psYds;
					cout<<endl<<"RecYds: ";
					cin>>RecYds;
                    list[i].recYds = list[i].recYds + RecYds;
					cout<<endl<<"RusYds: ";
					cin>>RusYds;
                    list[i].rusYds = list[i].rusYds + RusYds;
				cout<<"Name             POS TDs Cat   PsYd RecYds RusYds"<<endl<<endl;
				len=name.length();
				cout<<name<<" "<<setw(18-len)<<list[i].pos<<" "<<setw(3)<<list[i].TD<<" "<<setw(4)<<list[i].cat<<" "<<setw(6)<<list[i].psYds<<" "<<setw(5)<<list[i].recYds<<" "<<setw(6)<<list[i].rusYds<<endl;
			}
		}
	menuList(list, cap);
}

void menuList(footBallPlayers list[], int cap)
{
    
    	int reply;
    	while(reply!=0)
    	{
    	cout<<"\nWould you like to\n1.) View all stats\n2.) View a player's stats \n3.) View by Position \n4.) Add Stats to Players Totals \n5.) Edit a Player's Stats and Position \n0.) Exit\n\nPlease make a selection."<<endl;
    	cin>>reply;
    	cout<<endl;
        	if(reply == 0)
                {
                     string choice;
                     cout<<"Would you like to save the data? y/n"<<endl;
                     cin>>choice;
               	     if((choice=="y")||(choice=="Y")||(choice=="yes"))
            	     output(list, cap);
            	    
                 }
    		else if(reply==1)
    			{
                    allStats(list, cap);    
    			 }
    		else if(reply==2)
    			{
    				searchList(list, cap);
    			}
            else if(reply==3)
    			{
    				searchByPos(list, cap);
    			}
    		else if(reply==4)
    			{
    				addStats(list, cap);
    			}
            else if(reply==5)
    			{
    				editList(list, cap);
    			}
    		else
    			{
    				cout<<"Please make a valid choice."<<endl<<endl;
    				menuList(list, cap);	
    			}
    	reply = 0;
    	}
    	
        
}






