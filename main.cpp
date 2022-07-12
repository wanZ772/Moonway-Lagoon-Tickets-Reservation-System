// coded by WanZ
// logical error fixed
// 0 error, 0 warning
// clean code
// unused data removed

#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

string park[4] = {"null", "Theme Park", "Water Park", "Theme & Water Park"}; // array for park type
	string city[3] = {"null", "Malaysian", "Non-Malaysian"}; // array for citizenship
	
int calcPrice(int category, int citizenship, int family, int kids, int adults)    {
    int price, local_tp_price[4] = {0,40,75,100}, global_tp_price[4] = {0,50,85,120}, local_wp_price[4] = {0,60,120,150}, global_wp_price[4] = {0,80,150,200};
    switch (citizenship)   {
        case 1:
            switch(category)    {
                case 1:
                    if (!family) {
                        price = (kids * 40) + (adults * 75);
                    }   else    {
                        price = 100;
                    }
                    break;
                case 2:
                    if (!family)    {
                        price = (kids * 60) + (adults * 120);
                        
                    }   else    {
                        price = 150;
                    }
                    break;
                case 3:
                    price = (((kids * 60) + (adults * 120)) + ((kids * 40) + (adults * 75))) - (((kids * 60) + (adults * 120)) + ((kids * 40) + (adults * 75)) * .3);
                    break;
                
            }
            break;
        case 2:
             switch(category)    {
                case 1:
                    if (!family) {
                        price = (kids * 50) + (adults * 85);
                    }   else    {
                        price = 120;
                    }
                    break;
                case 2:
                    if (!family)    {
                        price = (kids * 80) + (adults * 150);
                        
                    }   else    {
                        price = 200;
                    }
                    break;
                case 3:
                    price = (((kids * 50) + (adults * 85)) + ((kids * 80) + (adults * 150))) - (((kids * 50) + (adults * 85)) + ((kids * 80) + (adults * 150)) * .4);
                    break;
                
            }
            break;
            
    }
    return price;
}

int main()
{
    
    string tickets = "Tickets price: RM";
    char heart = 3;
    int category, kids, adults, citizenship, family, conti;
    int the_price = 0;
	//tp_price[5] = {0, 40, 75, 50, 85}, wp_price[5] = {0, 60, 120, 80, 150}, b_price[6] = {250, 320, 100, 195, 130, 235};
	
	while (true) // repeat the program until user terminate it
	{
    	while (true) { // repeat to ask users input if input was wrong or empty
           	     cout << "\n\nWelcome to Moonway Lagoon Theme Park Tickets Reservation System.\n";
           cout<<"\n\tCategory\t\t\tFull name";
           cout<<"\n\t1.\t\t\t\tTheme Park";
           cout<<"\n\t2.\t\t\t\tWater Park";
           cout<<"\n\t3.\t\t\t\tTheme & Water Park\n";

           cout<<"\n\n\tCitizenship \t\t\tFull name";
           cout<<"\n\t1.\t\t\t\tMalaysia Citizen";
           cout<<"\n\t2.\t\t\t\tNon-Malaysia Citizen\n";

           cout << "\nEnter code category: ";
           cin >> category;
           cout << "\nEnter code citizenship: ";
           cin >> citizenship;

                 if ((category > 0 && category < 4) && (citizenship > 0 && citizenship < 3)){ // to check input given correct or wrong
               break;
           }    else    {
               cout << "\nSorry, invalid category and citizenship.";
               cout << "\nRe-Enter the code.";
           }
    }

	cout << "Great choices! Now please confirm:\n\n";
	cout<<"\n\n\tTicket\t\t\t\t\tPrice(Malaysian)\t\t\tPrice(Non-Malaysian)\n";
       cout<<"\tTheme Park";
       cout<<"\n\t1.1 Kids(Age<12)\t\t\tRM40.00\t\t\t\t\tRM50.00";
       cout<<"\n\t1.2 Adults & senior citizen\t\tRM75.00\t\t\t\t\tRM85.00";
       cout<<"\n\t1.3 Family Package(2 kids & 2 adults)\tRM100.00\t\t\t\tRM120.00\n";
       cout<<"\n\tWater Park";
       cout<<"\n\t2.1 Kids(Age<12)\t\t\tRM60.00\t\t\t\t\tRM80.00";
       cout<<"\n\t2.2 Adults & senior citizen\t\tRM120.00\t\t\t\tRM150.00";
       cout<<"\n\t2.3 Family Package(2 kids & 2 adults)\tRM150.00\t\t\t\tRM200.00\n";
       cout<<"\n\tTheme & Water Park";
       cout<<"\n\t3. All Age\t\t\t\t30% discount\t\t\t\t40% discount\n";
       
    

	cout << "\nNumber of kids (1-12 y/o): ";
    cin >> kids; // take input and store in kids variable
    cout << "\nNumber of adults (over 12 y/o): ";
    cin >> adults; // take input and store in adults variale

    if (adults == 2 && kids == 2)
    	family = 1;
	else
    	family = 0;
    // cout << calcPrice(category, citizenship, family, kids, adults);

	the_price = calcPrice(category, citizenship, family, kids, adults);;//calcPrice(category, family, citizenship, kids, adults, tickets, tp_price, wp_price, b_price); // calling function calcPrice and store returned data into variable name the_price
	cout << "\n\nDo you wanna continue to buy tickets ? \n1. Yes, please.\n2. No, thanks\n\n>> ";
    cin >> conti;
    
    if (conti == 2) // condition of users if they want to continue using this program or not
	{
    	cout << "Thank you for using our service!!!!! " << heart << heart << heart << endl;

        cout <<  setw(15) << left << " " << setw(15) << right << "welcome to the Moonway Lagoon.\n";
        cout <<  setw(15) << left << " " << setw(15) << right <<"category: " << park[category] << "\n"; // output of selected park category
        cout <<  setw(15) << left << " " << setw(15) << right <<"tickets: " << kids << " and " << adults << "\n"; // output of people
        cout <<  setw(17) << left << " " << setw(17) << right << "total price: RM" << the_price <<"\n\n"; // ouput of total price
        cout <<  setw(15) << left << " " << setw(15) << right << "Thanks for using our service  . ."; 

        break;
    }
    

    return 0;
	}
}
