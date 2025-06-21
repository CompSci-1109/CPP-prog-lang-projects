#include<iostream>   //for input and output (cin, cout).
#include<cstdlib>   //for rand() and system("color").
#include<ctime>   //for time() to seed random number generator (the srand() thing).
#include<limits>  //for input buffer handling (input validation in error handling).
#include<string> //for using string types.
#include<algorithm> //for remove_if() function.
using namespace std;

//class to handle number guessing game.
class beginGame
{
	int num, compnum, tries; // num = player's guess, compnum = number to guess, tries = number of attempts.
	public:
		
		// gameStart() function starts the game and generates the computer's secret number.
		void gameStart()
		{
			cout<<"************ NUMBER GUESSING GAME ************"<<endl<<endl;
			cout<<"Welcome , O Seeker!\n"<<endl;
			cout<<"The Digitron has awakened.\n"<<endl;
			cout<<"Deep within its tangled cable mess, it has a number hidden.Which ranges from 1 to 100.";
			cout<<"\n\nCan You Outwit this Wired Beast?\n";
			
			// srand(), time() sets random seed and generate number between 1 and 100.
			srand(time(0));       // Set random seed using current time.
			compnum= (rand() %100) + 1;  // Computer picks a number between 1 and 100
			tries=0;            // Reset tries to 0.
		}
		
		// play() function handles user input and checks guesses.
		void play()
		{
			cout<<"Test your wit.";
			cout<<"\nPick Any number from 1 to 100: \n";
			
			string input;  //to store user input as a string.
			
			// Below is the Main loop until user guesses the correct number.
			do{
				cout<<"\nYour guess:";
				getline(cin>> ws, input); //this reads full input even with space given.
                 
                 // the below functions trim the space if mixed input like "abc 123" has a space entered in between.
                 input.erase(remove_if(input.begin(),input.end(), ::isspace),input.end());
                
				bool hasDigit= false;
				bool hasAlpha= false;
				bool hasSymbol= false;
				
				 // Analyze input character by character
				  for(int i=0; i<input.length(); ++i)
				  {
				  	if (isdigit (input[i]))
				  	{
				  		hasDigit= true;
					}
					else if (isalpha(input[i]))
					{
						hasAlpha=true;
					}
					else if (!isalnum (input[i]))
					{
						if (!(input[i]=='-' && i==0))
						{
							hasSymbol=true;
						}
					}
			      }
			      
                 //for handling user inputs like "90ab","ab(*&", "ads545*&^", "565*&("
				 if((hasAlpha && hasSymbol) || (hasAlpha && hasDigit && hasSymbol) || (hasDigit && hasSymbol))
				 {
				 	system("color C5"); //light red and purple
				 	cout<<"The processor stares: Did I stutter? I. NEED. PURELY. NUMBERS. BETWEEN 1 TO 100\n";
				 	continue;
				 }
				 
				else if(hasDigit && hasAlpha)
				 {
				 	//changes color and shows the error.
					system("color 56"); //purple and yellow
			  		cout<<"The Processor says: No Mixing. I need pure numbers.\n ";
			  		continue;
				 }
				  //for handling symbols
				else if(hasSymbol && !hasDigit && !hasAlpha)
				{
					system("color C7"); // light red and white
					cout<<"The Processor loses its calm: Did I say I need only numbers?\n";
					continue;
				}
				 //for handling inputs like "ojkskd"(if user input was a string)
				 else if(hasAlpha && !hasDigit && !hasSymbol)
				 {
				 	system("color E1"); //pale yellow and blue
					cout<<"The Processor speaks: Calm, O Seeker. You're so close to the answer.\n Please enter only numbers.\n";
					continue;
				 }
				
				 num= atoi(input.c_str());  // Convert string to integer safely (since it's already checked for digits).
				
				
				// Check if number is within the allowed range.
				if (num < 1 || num > 100)
				{
					system("color B2");
					cout<<"The Processor warns: O Seeker! I plead you to not bend the rules. Enter numbers only between 1 and 100.\n";
					continue; // Ask again
				}
				
				tries++;   // Count the pure numbers (like 0, 1, 10 etc.) as a valid attempt.
				
				
				// Compare user's guess with the computer's number
				if (num > compnum)
				{
					system("color 60");
					cout<<"\nyour guess is:"<<num<<endl;
					cout<<"\a";
					cout<<"\nThe Processor Scoffs: Too High, O Seeker. Try Again.\n\n"<<endl;
				}
				else if (num < compnum)
				{
					system ("color 17");
					cout<<"Your guess was:"<<num<<endl;
					cout<<"\nThe Processor Buzzes In Disapointment: Too Low,Dear Seeker. Try Again.\n\n"<<endl;
				}
				else
				{
					system("color 2E");
					cout<<"your guess:"<<num<<endl;
					cout<<"\nPraises Be Upon You, O Seeker!";
					cout<<"\nYour Intelligence has conquered The Digitron.";
					cout<<"\nThe Mess of Wires Thus Tremble & Bow to You.";
					cout<<"\nYou won over The Digitron in: "<<tries<<" tries.";
				}
			}while (num != compnum);    // Loop continues until correct guess
	 	}		
};
int main()
{
	char choice;
  do{
  	system("color 0F");
  	beginGame game;     // Create game object.
	game.gameStart();  // Call function to initialize the game.
	game.play();      // Start the actual guessing game
  	
  	cout<<"\n\n\nDo you want to play again?\n\nEnter 'y' for yes, 'n' for no(y/n)";
  	cin>>choice;
  	 
  	 choice=tolower(choice); //normalises input to lowercase
  	 
  	 system("cls"); //clears screen before restarting
  	 
  	  }while (choice=='y');
  	  
  	  cout<<"The Digitron says: Thanks for playing! I'll await your return!";
  	  
  	  return 0;
}

