//CSCI111-05 : Group 6 Alpha
//

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

int will(int slice);

int andrew(int i);

int endroom (int p);

int kyleroom (int p);

int luke(int x);
int raphael(int option, int x);

int pedro(int P);
int luckyRoom(int P); //P is pizza


int main() {
  int pizza=0,room=0;
  cout << "You are Ezio. The secret fifth Ninja Turtle. Wielding a zanbatou, you patrol New York at night to protect all those that dwell within the city from the forces" << endl;
  cout << " of evil." << endl;
  cout << "Stopping on top of the building, you see a struggle taking place in the distance. Being forced down into the sewers by the Foot Clan is Todd Gibson, a visiting college professor from Chico State University." << endl;
  cout << "You immediately give chase. Using your ninja skills, you track the trail left by the foot clan down to a central chamber with tunnels leading to several rooms" << endl;
  cout << " attached to it. The trail ends here. However, you briefly hear Todd's voice" << endl;
  cout << " before hearing it gagged with what sounds like a roll of blue socks." << endl;
  cout << "You can't tell which room the sounds came from though. You now have no choice" << endl;
  cout << " but to randomly guess which room, and hope you make it on time to save Todd." << endl;
   
  do{
    cout << "You are currently in the central chamber. You must choose one of the following:" << endl;
    cout << "1) a tunnel with the Batman symbol above it." << endl;
    cout << "2) a tunnel with some oddly stylish drapes hanging across the entrance." << endl;
    cout << "3) a tunnel with what looks like a picture of a ladder above it." << endl;
    cout << "4) a tunnel with a sign above that says The Red Light District." << endl;
    cout << "5) a tunnel that looks like it leads to an aqueduct." << endl;
    cout << "6) A tunnel with the number 42 above it" << endl;
    cout << "7) A tunnel with a bunch of tentacles leading into it." << endl;
    cin >> room;
    switch(room) {

        case 1:
          pizza = will(pizza);
          break;
        case 2:
          pizza = andrew(pizza);
          break;
        case 3:
          pizza = kyleroom(pizza);
          break;
        case 4:
          pizza = luke(pizza);
          break;
        case 5:
          pizza = pedro(pizza);
          break;
        case 6:
          pizza = endroom(pizza);
          break;
        case 7:
          cout << "NO! NO! NO! ASOLUTELY NOT! If you want to oblige your sick tentacle fetish, you do it by yourself! I don't get paid nearly enough as a narrator to follow you in there!" << endl;
          break;
        default:
          cout << "Sorry. Invalid choice. Try Again." << endl;
          break;
    }

  } while (room != 6);
  
  cout << "You have collected " << pizza << " pizza slice(s)." << endl;
  if (pizza == 0) cout << "That was sad." << endl;
  else if (pizza < 8) cout << "It was alright. Performance could use some improvement." << endl;
  else if (pizza < 16) cout << "Not bad. Definitely not going hungry tonight." << endl;
  else cout << "You collected that much. COWABUNGA!!!!!!!" << endl;
  
  return 0;
}

//Andrew Loveless
int andrew(int i){
  bool leave=false;int choice=0;
  cout << "Your in room 2" << endl;
  cout << "Your looking for Todd and don't see him anywhere when a huge sewer rat jumps out of the stinky water" << endl;
  
  do{
    cout << "Do you want to:" << endl << "  1: throw a pizza slice at the rat and run away (-1 slice)" << endl << "  2: test your luck and fight the rat" << endl << "  3: do nothing" << endl;
    cin >> choice;
    switch(choice){

      case 1:
        (i==0) ? cout << "you don't have any pizza to throw at the rat" << endl : (cout << "The rat is distracted     by your pizza slice and you slip away" << endl, --i, leave=true);
        break;
      case 2:
        cout << "You scared the rat back into the sewer with your weird green face and find a slice of pizza the rat was guarding" << endl;
        cout << "Plus 1 pizza slice" << endl;
        ++i; leave=true;
        break;
      case 3:
        cout << "You both did nothing and just stared into each others eyes" << endl;
        break;
    }
    choice = 0;
  } while(leave == false);
  cout << "You return back to the central chamber" << endl;
  return i;
}
//Will Cortez function
//Integer name is       int michelangelo(int slice) 
//Function for William Cortez
//Group 6 Alpha
//Ninja Turtles finding Todd Gibson!! 
//Integer is slice
int will(int slice)
{ 
  cout<< "Ezio has been looking for Todd. He approaches"<<endl;
  cout<< "A T-intersection and hears noise coming from both ends."<<endl;
  string answer;
    cout<< "Which way should Ezio go? \"left\" or \"right\" ?"<<endl;
    cin>> answer;

    if(answer=="left")
    {
      cout<< "As he turns into the left corridor, Ezio encounters"<<endl;
      cout<< "A foot clan soldier lurking in the tunnels. It's a FIGHT!!"<<endl;
      cout<< "The goon seems to be very well versed in Brasilian jiu jitsu."<<endl;
      cout<< "They duke it out for what seems to be an eternity and just"<<endl;
      cout<< "as Ezio sees a way to defeat his attacker......."<<endl;
      cout<< "An army of Foot clan goons surround and capture him!!!!"<<endl;
      cout<< "When the foot try to tie him up, he bursts into smoke. Ezio created a bushin earlier in the fight and escaped" << endl;
     
    }

    else if (answer=="right")
    {
      cout<< "To the right, he finds a room littered with trash and junk."<<endl;
      cout<< "The odor of the room is overwhelming but within the stench."<<endl;
      cout<< "He catches a wift of something familliar. Something amazing."<<endl;
      cout<< "PIZZA!!!!!!" <<endl;
      cout<< "Well just two partially eaten slices from Celestino's Pizza."<<endl;
      slice = slice+2;
    

    cout<< "With his newly found food, Ezio continues his quest" <<endl;
    cout<< "to find Todd and rid him of his brutal hunger." <<endl;
     
	}
	
	else {
		cout << "On second thought, Ezio decides to turn around and head back." << endl;
	}
	cout << "Ezio returns to the central chamber." << endl;
  return slice;
}

// John Pinto: Did this function, came up with general scenario, put everyone's function together in this document. Also did case 7 in int main() as a joke.
int endroom (int p) {
	int c;
	c=0;
	do {
	cout << "You found Todd with three foot clan in front of him by a ladder. It appears a" << endl;
	cout << " truck was sitting on the sewer cover preventing them from leaving. The truck" << endl;
	cout << " has just moved off." << endl; 
	cout << " Todd is currently tied up with a pair of blue socks stuffed in his mouth." << endl;
	cout << " You must choose:" << endl; 
	cout << "1) Attack immediately." << endl;
	cout << "2) Fake a frontal attack and use substitution to get behind the foot clan." << endl;
	cout << "3) Rush past the foot to put earplugs in Todd's ear and yours and begin to" << endl;
	cout << " recite Vogon poetry." << endl;
	cout << "4) Perform a summoning jutsu using a gumwrapper you found." << endl;
	cin >> c;
	if (c == 1) {
 		cout << "You barely triumph and at great cost. Todd's award-winning facial hair has been completely shaved off. You must give him the three pizza slices found on the foot and all of your previously collected pizza in punishment." << endl;
		p=0;
 	}
	else if (c == 2) {
		cout << "Blindsided, the foot are completely defeated. You take the three pizza slices " << endl;
		cout << "found on the foot and free Todd." << endl;
		p=p+3;
	}
 	else if (c == 3) {
		cout << "Within mere moments, the foot knocks themselves out. You take the three pizza" << endl;
		cout << " slices found on the foot, remove the earplugs, and free Todd." << endl;
		p=p+3;
	}
	else if (c==4) {
		cout << "You use the gum wrapper and summon: CHUCK NORRIS." << endl;
		cout << "CHUCK NORRIS has just finished chewing his last piece of bubble gum." << endl;
		cout << "The first foot clan member attacks with a knife. CHUCK NORRIS cuts it in" << endl;
		cout << " half with a hot stick of butter." << endl;
		cout << "The second foot clan member uses a smoke pellet to get in close for a strike at the throat. A fist comes from the beard of CHUCK NORRIS and knocks the foot clan out." << endl;
		cout << "The final foot summons a cobra that bites CHUCK NORRIS. Two minutes later, the " << endl;
		cout << "cobra dies. CHUCK NORRIS then roundhouse kicks the final foot member unconscious." << endl;
		cout << "CHUCK NORRIS then looks at the bound up Todd. The ropes disintegrate, and the" << endl;
		cout << " blue sock embed themselves into a nearby wall." << endl;
		cout << "CHUCK NORRIS then disappears in a burst of smoke. When the smoke clears, you see two whole pizzas left behind." << endl;
		p =p+16;
	}
	else cout << "Invalid choice. Try again." << endl;

	} while (c!=1 && c!=2 && c!=3 && c!=4);
	cout << "You have rescued Todd and head to the exit." << endl;
	return p;
}

// Kyle Lasater
int kyleroom (int p)
{
  string answer;
  string answer2;
  int c=0;
  int n=0;
  int randnum;
  cout<< "You look around the room you have just entered but there is nothing but a"<<endl;
  cout<<"ladder. Then it hits you: an overwhelming smell. You cant controll yourself."<<endl;
  cout<<"You walk closer to the ladder and the smell gets stronger. You look up but you"<<endl;
  cout<<"cant see anything. You have to choose (Y)yes go up the ladder and investigate"<<endl;
  cout<<"or (N)no dont go up the ladder and leave the room before the amazing aroma"<<endl;
  cout<<"changes your mind."<<endl;
  cin>> answer;
  if (answer == "Y")
  {
    cout << "You start climbing the ladder."<<endl;
    cout<<"When you get closer to the top you start to hear vehicles on what"<<endl;
    cout<<"you beleive might be a road above. From here you can tell that the amazing smell"<<endl;
    cout<<"is PIZZA."<<endl;
    srand (time(NULL));
 
      randnum = rand()%3+1;
      switch (randnum)
      {
        case 1:
          cout<<" There are headlights directly in your face. You fall down the ladder "<<endl;
          cout<<"crushing all of your prevously collected pizza and you sadly leave the room"<<endl;
          p = 0;
          break;
        case 2:
          cout<<" There are headlights inches from your face. You quickly duck, then you run "<<endl;
          cout<<"up and grab "<<randnum<<" slices of pizza off a nearby table. You happily "<<endl;
          cout<<"leave the room with your pizza."<<endl; 
          p + randnum;
          break;
        case 3:
          cout<<" There are headlights directly in your face. You quickly duck and run out of"<<endl;
          cout<<"the room. Forgetting about the smell of pizza."<<endl;
          break;
      }
    
    
      cout<<"You walk out of the room and return to the central chamber."<<endl;  
}
  
  else
  { 
    cout<<"You leave the room and return to the central chamber" <<endl;
  }
  return p;
}

// Luck Putnam
int luke(int x)
{

  cout<<"You have chosen to enter the red light district"<<endl;
  cout<<"there is an\"urban entrepreneur\" protected by three foot clan."<<endl;
  cout<<"He knows where Todd is being held."<<endl;

  int option=0;
  cout<<"Press 1 to run away, press 2 to make an undercover purchase and"<<endl;
  cout<<"try to sneak a peek at Todd's whereabouts, or press 3 to wipe"<<endl;
  cout<<"the floor with the foot clan and get the info from the entrepreneur"<<endl;
  cout<<"the old fashioned way!"<<endl;

  cin>>option;
x=raphael(option, x);
cout<<"You return to the central chamber." << endl;
return x;
}
int raphael(int option, int x)
  {
  switch(option)
  {
    case 1:
      cout<<"You chose to be a coward and run away, you have no pizza!"<<endl;
      break;
    case 2:
      cout<<"Very slyly you make an undisclosed purchase from the \"urban entrepreneur\""<<endl;
      cout<<"while doing so you sneek a peak at Todd's whereabouts!"<<endl;
      cout<<"Well done! You walk away with a big smile on your face and 2 slices of pizza!"<<endl;
      ++x;
      break;
    case 3:
      cout<<"You bust out your zanbatou and take it to the foot clan ninja style"<<endl;
      cout<<"they are no match for your superior skills.  Then you very nicley"<<endl;
      cout<<"\"persuade\" the entreprenuer to disclose the details of Todd's whereabouts."<<endl;
      cout<<"Just as your cleaning up the mess there is a knock at the door,"<<endl;
      cout<<"Its the pizza delivery guy!  You just got piping hot XL pizza! Totaly Rad!"<<endl;
      x=x+8;
      break;
    default:cout<<"You entered "<<option<<endl;
  }
  return x;
}

// Pedro Guardado
int pedro(int P)
{
  cout << "\n\n\n\nYou follow a group of foot clan into a sketchy large aqueduct. when you enter the aqueduct u see three doors; a moldy door to the right, a metal plated door to the left, and a old creeky wooden door" << endl;
  cout << "remember that they still have Todd! we have to save him!" << endl;
  int choice;
  
  do
  {
    cout << "Which door do you choose to go through??\n\n1 for the moldy door to the right\n2 for the metal door to the left\n3 for the creeky wooden door up ahead\n";
    cin >> choice;
    
    switch(choice)
    {
      case 1://The moldy door
       cout << "Hmmm....\nthis rooms empty." << endl;
        break;

      case 2://The metal door
        P=luckyRoom(P);
        break;

      case 3://The creeky wooden door
        cout << "The door leads to another lightly lit tunnel" << endl;
        cout << "You find a single slice of pizza at the end of the tunnel" << endl;
        P++;
        break;
        
      default:
        cout << "\nSorry, Not a valid choice.\n";
        break;
    }
 }
  while(choice!=1 && choice!=2 && choice!=3);
  cout << "You return to the central chamber" << endl;
  return P;
}

int luckyRoom(int P)
{
  cout << "The room smells....\n like PIZZA!\n oh wait! whats that?!\nThe foot were hiding on the sealing and tries to jump you.." << endl;
  int choice;
 
  do
  {
    cout << "Do you want to: \n1 dodge their ambush attempt and throw a table\n2 pull out your zanbatou and fight!\n3 jump for that PIZZA on the table and Run\n";
    cin >> choice;
    
    if(choice==1)
    {
    cout << "You dodged their attack and threw a table at the foot but they dodged it as well and you still got jumped..." << endl;
    cout << "You barely manage to defeat them." << endl;
    }

    if(choice==2)
    {
    cout << "You pulled out your zanbatou and defeated the group of foot with one swift swing but were able to salvage 4 out of the 8 pizzas that were on the table"<< endl;
    P = P+4;
    }

    if(choice==3)
    {
    cout << "You jumped for the pizza on the table and managed to escape from the room but the foot is still after you!..\nRUN!" << endl;
    P = P+8;
    }
   
  }
  while(choice==1);
  cout << "You return to the central chamber" << endl;
  return P;
}
