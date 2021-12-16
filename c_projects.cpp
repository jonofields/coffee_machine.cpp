#include <iostream>
#include <string>

//MAKING A COFFEE MACHINE
int main(){
    using std::cin; using std::cout; using std::string; using std::endl;
    string str1 = "\n\tWelcome to the coffee machine, what would you like?\n\n\t\tPlease choose from an espresso, latte, or for coffee input 'drip'. \n\n\t\tAdmin: REPORT or ORDER\n\n\n\tTo leave type CLOSE\n";
    string input_str;
    double const espresso_cost = 3.00;
    double const latte_cost = 3.50;
    double const drip_cost = 2.00;

    int unsigned water_supply = 1000;
    int unsigned cfground_supply = 1000;
    int unsigned milk_supply = 300;

    double water_cost = 0.5;
    double coffee_cost = 3.00;
    double milk_cost = 2.00;

    string order_input;
    bool order_status;

    double cash_in;
    double change;
    double cash_on = 10.00;
    
    bool machine_on = true;
    string anything_else;

   


    while (machine_on==true){
         if(water_supply<=100){
                cout << "WARNING LOW WATER\n\n" << "WATER SUPPLY: " << water_supply;
                cout << " Use ORDER to purchase more water.\n\n";
               
            }
            else if(cfground_supply<=100){
                cout << "WARNING LOW COFFEE GROUNDS\n\n" << "COFFEE GROUND SUPPLY: " << cfground_supply;
                cout << " Use ORDER to purchase more coffee.\n\n";
            }
            else if(milk_supply<=50){
                cout << "WARNING LOW MILK\n\n" << "MILK SUPPLY: " << milk_supply;
                cout << " Use ORDER to purchase more milk.\n\n";
            }
        cout << str1 << endl;
        cin >> input_str;
        //STARTING WITH DRINK SELECTION
        if(input_str == "espresso"){
            cout << "You have chosen an Espresso, that will be $" << espresso_cost <<  ".  Please input the money\n";
            cin >> cash_in;
            if(cash_in < espresso_cost){
                cout << "Sorry that's not enough money, here is $" << cash_in << " back. Goodbye \n";
                cout << "\t\tRETURNING TO MENU\n";
            }   
            else if(cash_in > espresso_cost){
                change = cash_in - espresso_cost;
                water_supply = water_supply - 100;
                cfground_supply = cfground_supply - 100;
                cash_on += espresso_cost;
                cout << "Here is your espresso, your change is " << change << ".  Would you like anything else, y/n?\n";
                cin >> anything_else;
                    if(anything_else=="y"){
                        machine_on = true;
                    }
                    else{machine_on=false;}
                    }
            else{cout << "Thank you, here is your espresso, would you like anything else y/n?\n";
                water_supply = water_supply - 100;
                cfground_supply = cfground_supply - 100;
                cash_on += espresso_cost;
                cin >> anything_else;
                    if(anything_else=="y"){
                        machine_on = true;
                    }
                    else{machine_on = false;
                    }
                }
            }
    else if(input_str == "latte"){
        cout << "You have chosen a latte, that will be  $" << latte_cost << ".  Please input the money\n";
        cin >> cash_in;
        if(cash_in < latte_cost){
            cout << "Sorry that is not enough money, here is " << cash_in << " back.\n\n";
            cout << "\t\tRETURNING TO MENU\n";
            }
        else if(cash_in > latte_cost){
            change = cash_in - latte_cost;
            water_supply = water_supply - 100;
            cfground_supply = cfground_supply - 100;
            milk_supply = milk_supply - 100;
            cash_on += latte_cost;
            cout << "Here is your latte, your change is " << change << ".  Would you like anything else, y/n?\n";
            cin >> anything_else;
                if(anything_else=="y"){
                    machine_on = true;
                    }
                else{machine_on=false;}
        }
        else{cout << "Thank you, here is your latte, would you like anything else y/n?\n";
                water_supply = water_supply - 100;
                cfground_supply = cfground_supply - 100;
                milk_supply = milk_supply - 100;
                cash_on += latte_cost;
                cin >> anything_else;
                    if(anything_else=="y"){
                        machine_on = true;
                    }
                    else{machine_on = false;
                    }
                }
            }
        else if(input_str == "drip"){
            cout << "You have chosen a drip coffee, that will be  $" << drip_cost << ".  Please input the money\n";
            cin >> cash_in;
            if(cash_in < drip_cost){
                cout << "Sorry that is not enough money, here is " << cash_in << " back.  Goodbye.\n";
                cout << "\t\tRETURNING TO MENU\n";
                }
            else if(cash_in > drip_cost){
                change = cash_in - drip_cost;
                water_supply = water_supply - 250;
                cfground_supply = cfground_supply - 50;
                cash_on += drip_cost;
                cout << "Here is your coffee, your change is " << change << ".  Would you like anything else, y/n?\n";
                cin >> anything_else;
                    if(anything_else=="y"){
                        machine_on = true;
                        }
                    else{machine_on=false;}
            }
            else{cout << "Thank you, here is your coffee, would you like anything else y/n?\n";
                water_supply = water_supply - 250;
                cfground_supply = cfground_supply - 50;
                cash_on += drip_cost;
                cin >> anything_else;
                    if(anything_else=="y"){
                        machine_on = true;
                    }
                    else{machine_on = false;
                    }
                }
            }
            else if(input_str == "REPORT"){
                cout << "\n\n\n*****REPORT*****\n\n";
                cout << "Water: " << water_supply << "ml\n";
                cout << "Coffee: " << cfground_supply << "g\n";
                cout << "Milk: " << milk_supply << "ml\n";
                cout << "Cash: $" << cash_on << endl;
                cout << "Would you like to return to the menu?\n\n";
                cin >> anything_else;
                    if(anything_else=="y"){
                        machine_on = true;
                    }
                    else{machine_on = false;
                    }
            }
            else if(input_str == "ORDER"){
                order_status = true;
                while (order_status==true)
                {
                cout << "What would you like to order?\n\nFor water input 'w', for coffee, 'c', and for milk, 'm'\n\n";
                cout << "\tWater: $" << water_cost << "\n";
                cout << "\tCoffee: $" << coffee_cost << "\n";
                cout << "\tMilk: $" << milk_cost << "\n";
                cin >> order_input;
                if(order_input == "w"){
                    water_supply = water_supply + 1000;
                    cash_on = cash_on - water_cost;
                    cout << "Water has been ordered, the new water supply is " << water_supply << "ml\n\n";
                    cout << "Your remaining balance is $" << cash_on << "\n\n"; 
                    cout << "Would you like to order anything else y/n?\n";
                    cin >> anything_else;
                        if(anything_else=="y"){
                            order_status = true;
                        }
                        else{order_status = false;
                        }
                }
                else if(order_input == "c"){
                    cfground_supply = cfground_supply + 1000;
                    cash_on = cash_on - coffee_cost;
                    cout << "Coffee has been ordered, the new coffee supply is " << cfground_supply << "ml\n\n";
                    cout << "Your remaining balance is $" << cash_on << "\n\n"; 
                    cout << "Would you like to order anything else y/n?\n";
                    cin >> anything_else;
                        if(anything_else=="y"){
                            order_status = true;
                        }
                        else{order_status = false;
                        }
                }
                else if(order_input == "m"){
                    milk_supply = milk_supply + 500;
                    cash_on = cash_on - milk_cost;
                    cout << "Milk has been ordered, the new milk supply is " << milk_supply << "ml\n\n";
                    cout << "Your remaining balance is $" << cash_on << "\n\n"; 
                    cout << "Would you like to order anything else y/n?\n";
                    cin >> anything_else;
                        if(anything_else=="y"){
                            order_status = true;
                        }
                        else{order_status = false;
                        }
                }
                else{
                    cout << "That was not an option" << endl;
                }
                }
            }
            else if(input_str == "CLOSE"){
                machine_on = false;
            }    
        }    
    }
