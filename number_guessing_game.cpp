#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>
using namespace std;
class beginGame
{
	int humannum, compnum, tries;
	public:
		void gameStart()
		{
			cout<<"************ NUMBER GUESSING GAME ************"<<endl<<endl;
			cout<<"Welcome , O Seeker!\n"<<endl;
			cout<<"The Digitron has awakened.\n"<<endl;
			cout<<"Deep within its tangled cable mess, it has a number hidden.Which ranges from 1 to 100.";
			cout<<"\n\nCan You Outwit this Wired Beast?\n";
			srand(time(0));
			compnum= (rand() %100) + 1; 
			tries=0;
		}
		void play()
		{
			cout<<"Test your wit.";
			cout<<"\nPick Any number from 1 to 100: \n";
			do{
				//cin>>humannum;
				
				if (!(cin>>humannum))
				{
					cout<<"The Processor speaks: Calm, my Seeker. You're so close to the answer.\n Please enter only numbers.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					continue;
				}
				
				if (humannum < 1 || humannum > 100)
				{
					cout<<"The Processor warns: O Seeker! I plead you to not bend the rules. Enter numbers only between 1 and 100.\n";
					continue;
				}
				
				tries++;
				
				if (humannum > compnum)
				{
					system("color 60");
					cout<<"your guess:"<<humannum<<endl;
					cout<<"\a";
					cout<<"\nThe Processor Scoffs: Too High, O Seeker. Try Again.\n\n"<<endl;
				}
				else if (humannum < compnum)
				{
					system ("color 17");
					cout<<"your guess:"<<humannum<<endl;
					cout<<"\nThe Processor Buzzes In Disapointment: Too Low,Dear Seeker. Try Again.\n\n"<<endl;
				}
				else
				{
					system("color 2E");
					cout<<"your guess:"<<humannum<<endl;
					cout<<"\nPraises Be Upon You, O Seeker!";
					cout<<"\nYour Intelligence has conquered The Digitron.";
					cout<<"\nThe Mess of Wires Thus Tremble & Bow to You.";
					cout<<"\nYou won over The Digitron in: "<<tries<<" tries.";
				}
			}while (humannum != compnum);
		}		
};
int main()
{
	beginGame game;
	game.gameStart();
	game.play();
  return 0;
}

