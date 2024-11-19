#include <iostream>
#include <string>
using namespace std;
void horrorStory() {
    cout << "You find yourself standing at the edge of a dense forest.The canopy above blocks out most of the sunlight, casting shadows that seem to move with every rustle of leaves. You're not sure how you ended up here, but you know you need to find your way out. With a deep breath, you step forward into the unknown.\n\n";
    cout << "You come across a fork path. On the left side,You see a dark  and ominous path. On the right side, You hear some weird noices.\n";
cout<<"\n1. Left\n2. Right"<<endl;
    int choice;
    cin >> choice;
    
    if (choice == 1) {
         cout <<"You walk down the dark and ominous path. You can't see anything, but you can hear the sound of footsteps behind you. You turn around and see a group of bandits blocking your way. They look angry and ready to attack.\n What do you do?";
        cout << "(Press 1 to fight and 2 to run)" << endl;
  cin >> choice;
  if (choice == 1) {
    cout << "You find a sword and fight the bandits. After a long fight you manage to deafeat the bandits. you stand victorious but wary, knowing that danger could still lurk around every corner."<<endl;
         cout<<"1.Search the Bandits\n2.Tend to Your Injuries"<<endl;
         if (choice == 1){
             cout<<"You search the defeated bandits for any useful items they may have had, hoping to find supplies or clues that could aid you on your journey.";
         }
         else {
             cout<<"You search the defeated bandits for any useful items they may have had, hoping to find supplies or clues that could aid you on your journey.";
         }
         }
          else {
    cout << "You run away from the bandits and fall in a pit.\n  Pain shoots through your body as you struggle to regain your bearings in the dim light." << endl;
    cout<<"1. Assess Injuries\n2.Search for a Way Out"<<endl;
    cin>>choice;
    if (choice == 1){
        cout<<"You take a moment to assess any injuries you may have sustained from the fall, checking for broken bones or cuts that need immediate attention.";
    }
    else {
        cout<<"Despite the pain, you begin to search for a way to climb out of the pit, feeling around the walls in search of any footholds or ledges that could aid your escape.";
    }
    }
    }
     else {
  cout << " Intrigued by the mysterious noises, you cautiously tread down the right path, determined to uncover the source of the strange sounds and perhaps find some answers.\n";
        cout<<"\n1.Follow the Noises\n 2.Proceed with Caution\n";
        cin>>choice;
        if (choice == 1){
        cout<<"Each step forward feels like a tentative dance with the unknown, your senses alert to any potential dangers lurking in the shadows."<<endl;}
        else{
            cout<<"While intrigued, you proceed along the path cautiously, keeping your guard up and staying alert for any signs of danger or unexpected encounters."<<endl;
        }
        }
    cout<<" to continue the story login to our new app TXT"<<endl;
}
        void ficStory() {
    cout << "You find yourself transported to a fantastical world filled with magic and mythical creatures.\n";
    cout << "1. Seek out a wise sage for guidance.\n";
    cout << "2. Train to become a powerful warrior.\n";
     int choice;
    cin >> choice;
    if (choice == 1) {
        cout<<" The sage, an ancient being with eyes that seem to hold the wisdom of centuries, welcomes you with a knowing smile."<<endl;
        cout << "The sage imparts ancient wisdom upon you, revealing the path you must take to fulfill your destiny.\n";
        cout<<"1.Ask about the world\n 2.Request guidance on your journey"<<endl;
        int choice3;
        cin>>choice3;
        if (choice3 == 1){
            cout<<"Curious about the world you've found yourself in, you inquire about its history, inhabitants, and the source of its magic. The sage, with patience and kindness, shares tales of ancient civilizations, powerful magic, and the delicate balance that exists between the realms.\n"<<endl;
        }
        else{
            cout<<"Knowing that you are here for a reason, you seek the sage's counsel on how to navigate this new world and fulfill your purpose. The sage listens intently, then imparts cryptic advice that speaks of trials to come, allies to seek, and the importance of following your heart's true path.\n"<<endl;
        } 
        } 
else {
        cout << "You spend years honing your combat skills, mastering powerful techniques.\n";
        cout<<"One day, while sparring with fellow warriors, you receive word of a looming threat to the realm. A dark sorcerer has begun to amass an army of monstrous creatures,


 intent on plunging the world into chaos. The wise sage urges you to take action and join the fight against this evil force."<<endl;
        cout<<"\n Now faced with a crucial decision, you must choose your path:"<<endl;
        cout<<"1. Join the battle:\n 2. Seek further training:"<<endl;
        cout<<"enter your choice"<<endl;
        int choice1;
        cin>>choice1;
    if (choice1== 1){
        cout<<" You rally your fellow warriors and march forth to confront the dark sorcerer and his minions. Fight bravely to protect the realm and restore peace to the land.\n"<<endl;
    }
    else {
        cout<<" feel that you are not yet prepared to face such a formidable foe. Decide to embark on a quest to seek out legendary masters and ancient artifacts that can grant you the power needed to defeat the sorcerer.\n"<<endl   
}
    cout<<" to continue the story login to our new app TXT"<<endl;
}
int main() {
    cout << "Welcome to the Text Adventure Game!\n";
    cout<<"enter your name"<<endl;
    char x[5];
    cin>>x;
    cout << "Choose your story:\n";
    cout << "1. Horror\n";
    cout << "2. fiction \n";
    int storyChoice;
    cin >> storyChoice; 
    switch(storyChoice) {
        case 1:
            horrorStory();
          
  break;
        case 2:
            ficStory();
            break;
        default:
            cout << "Invalid choice. Please select a valid option.\n";
            break;
    }
   return 0;
}