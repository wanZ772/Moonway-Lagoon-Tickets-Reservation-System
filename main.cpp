// coded by WanZ

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string tickets = "Tickets price: RM";
    int category, kids, adults, citizenship, price, family, conti;
   while (true) {
       while (true) {
           cout << "\n\nWelcome to Moonway Lagoon Theme Park Tickets Reservation System.\nPlease select category: \n\n1. Theme Park\n2. Water Park\n3. Theme Park and Water Park\n\nCategory: ";
           cin >> category;
       
           if (category > 0 && category < 4)   {
               break;
           }    else    {
               cout << "\nSorry, invalid category " << category << "\n\n";
           }
       }
       
       cout << "Great choise! Now please confirm:\n\nAmount of kids (1-12 y/o): ";
       cin >> kids;
       cout << "\nAmount of adults (over 12 y/o): ";
       cin>> adults;
       cout << "Thanks! Please confirm your citizenship: \n1. Malaysian\n2. Non-Malaysian\n\nCitizenship: ";
       cin >> citizenship;
       
       if (adults == 2 && kids == 2)    {
           family = 1;
       }    else    {
           family = 0;
       }
       
       switch (category)    {
           case 1:
            if (family == true) {
                if (citizenship == 1)   {
                    cout << "Tickets price: RM100";
                }   else    {
                    cout << "Tickets price: RM120";
                }  
                }   else  {
                    if (citizenship == 1)   {
                        price = (40 * kids) + (75 * adults);
                        cout << tickets << price;
                    }   else    {
                        price = (50 * kids) + (85 * adults);
                        cout << tickets << price;
                    }
                }
            break;
            case 2:
                 if (family) {
                if (citizenship == 1)   {
                    cout << "Tickets price: RM150";
                }   else    {
                    cout << "Tickets price: RM200";
                }  
                }   else    {
                    if (citizenship == 1)   {
                        price = (60 * kids) + (120 * adults);
                        cout << tickets << price; 
                    }   else    {
                        price = (80 * kids) + (150 * adults);
                        cout << tickets << price;
                    }
                }
            break;
            case 3:
                if (family) {
                    if (citizenship == 1)   {
                         price =  250 - (0.4 * 250);
                        cout << tickets << price;
                    }   else    {
                         price =  320 - (0.4 * 320) ;
                        cout << tickets << price;
                    }
                }   else    {
                    if (citizenship == 1)   {
                        price =  ((100 * kids) + (195 * adults)) - (0.3 * ((100 * kids) + (195 * adults)))  ;
                        cout << tickets << price;
                    }   else    {
                         price =  ((130 * kids) + (235 * adults)) - (0.4 * ((130 * kids) + (235 * adults)))  ;
                        cout << tickets << price;
                    }
                }
                break; 
       }
       
       cout << "\n\nDo you wanna continue to buy tickets ? \n1. Yes, please.\n2. No, thanks\n\n>> ";
       cin >> conti;
   
       if (conti == 2)  {
           cout<< "Thank you for using our service ! Developed by WanZ";
           break;
       }
   }
    return 0;
}
