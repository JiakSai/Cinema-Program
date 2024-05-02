#include <iostream>
#include <iomanip>
using namespace std;

class Movie
{
private:
    string movie[10];
    string showtime[10][3];

public:
    Movie() //set the data of movies and their showtimes
    {
        movie[0] = "Spider Man";
        movie[1] = "Super Man";
        movie[2] = "Iron Man";
        movie[3] = " ";
        movie[4] = " ";
        movie[5] = " ";
        movie[6] = " ";
        movie[7] = " ";
        movie[8] = " ";
        movie[9] = " ";

        showtime[0][0] = "0930";
        showtime[0][1] = "1500";
        showtime[0][2] = "2200";

        showtime[1][0] = "1000";
        showtime[1][1] = "1300";
        showtime[1][2] = "1800";

        showtime[2][0] = "1200";
        showtime[2][1] = "2000";
        showtime[2][2] = "2300";
    }

    void display() //display the available movies and their showtime 
    {
        cout << "--------------------------------------------------------------------------------------------" << endl;
        cout << "Serial\tMovie\t\tShowtimes[HHMM]" << endl;
        cout << "-------------------    ---------------------------------------------------------------------" << endl;
        int serial = 1;
        int moviecount = 0;
        for (int i = 0; i < 10; i++)
        {
            if (movie[i] != " ")  //prevent to show the empty movie array
            {
                cout << "   " << serial++<< "\t" << setw(15) << left << movie[i] << "\t"; //display movie accordingly

                for (int j = 0; j < 3; j++)
                {
                    if (showtime[i][j] != " ") //prevent to show the empty showtime array
                    {   
                        cout << "Showtime " << j + 1 << ": " << showtime[i][j]<<"\t"; //display showtime accordingly
                    }
                }
                cout << endl;
                moviecount++;
            }

		}
		cout << "--------------------------------------------------------------------------------------------" << endl;

        if(moviecount == 0)
        {
            cout<<"No Movie is Availble at this moment"<<endl;
        }
	}
	
    friend class Manager;
    friend class Customer;
    friend class Receipt;
}m;

class User
{
    protected :
    string name;
};

class Selection
{

public:
    char choice;
    void get_select() //first UI that will come out on cmd //let user choose A.Customer or B.Manager
    {

		cout << "--------------------------------------------------------------------------" << endl;
        cout << "\t\tWelcome to Movie Ticket Booking System!" << endl;
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "Please select your role:" << endl;
        cout << "\tA. Customer" << endl;
        cout << "\tB. Manager" << endl;
        cout << "Enter your choice (A/B)      : ";
		cin >> choice;
		cout << "---------------------------------------------------------------------------" << endl;
    }

    friend class Manager;
    friend class Customer;
};

class Customer : public User
{
private:
    int age;

protected:
	int itemcount = 0;
    string fnb[10], drink[10];
    double fnbPrice[10]= {0.00} , t_fnbPrice = 0.00;
    char choice_fnb;
public:
	int num;
	char studID;
	int pick_movie,pick_showtime;
    void customer_input() //customer input their info
    {
		cin.sync();
		cout << "\n";
		cout <<"--------------------------- Enter Your Details ----------------------------"<<endl; 
        cout << "Please enter your name       : ";
        getline(cin,name);
        cout << "Please enter your age        : ";
        cin >> age;
		cout << "Do you have student ID [Y/N] ?  ";
        cin >> studID;
		cout << "\n";
    }

	void pick_1()//customer select movie,ticket and show time.
	{	
		m.display();
		cout<<"\tThe price of movie ticket is all priced at RM20!!"<<endl;
		cout<<"\tIf you have a student ID card,you will enjoy a discount!! WELCOME <3"<<endl;
		int i;
		cout << "\n";
		cout<<"Please select a movie [1,2,3,....]          : ";
		cin>>pick_movie;
        
        while(m.movie[pick_movie-1] == " ") //loop while choosing unavailable movie serial
        {
            cout<<"Invalid Movie ! "<<endl;
            cout<<"Please select a movie [1,2,3,....]          : ";
            cin>>pick_movie;
        }

        cout<<"-----------You Have Selected "<<m.movie[pick_movie-1]<<"----------"<<endl;
		cout<<"How many ticket you wanna buy ?               ";
		cin>>num;
		cout<<"Which show you want to select for [e.g SHOW(1) please type 1] : ";
		cin>>pick_showtime;

        while(pick_showtime > 3) //loop while choosing unavailable showtime serial
        {
            cout<<"Invalid Showtime ! "<<endl;
            cout<<"Please reselect a showtime [e.g SHOW(1) please type 1]  : ";
            cin>>pick_showtime;
        }
		i++;
	}
	
	void foodndrinks() //food n beverages (if user press Y)
	{   
        int drinkSel;
        char choice;
        int fnbSel;

        cout<<"\nDo you want order Food & Beverages [Y/N] : ";
        cin>>choice_fnb;
        do{
            if(choice_fnb == 'Y' || choice_fnb == 'y') //food n beverages UI
            {
                cout << "==============================================================================" << endl;
				cout << "|                                 Menu                                       |" << endl;
				cout << "|============================================================================|" << endl;
				cout << "|  No. |              Combo                   |         Price (RM)           |" << endl;
				cout << "|============================================================================|" << endl;
				cout << "|   1. |  Combo A - 1x Signature Popcorn      |             18.00            |" << endl;
				cout << "|      |  + Regular Drink                     |                              |" << endl;
				cout << "|----------------------------------------------------------------------------|" << endl;
				cout << "|   2. |  Combo B - 1x Royale Popcorn         |             21.00            |" << endl;
				cout << "|      |  + Regular Drink                     |                              |" << endl;
				cout << "|----------------------------------------------------------------------------|" << endl;
				cout << "|   3. |  Combo C - 5pcs Hot Minis            |             18.00            |" << endl;
				cout << "|      |  + Regular Drink                     |                              |" << endl;
				cout << "|----------------------------------------------------------------------------|" << endl;
				cout << "|   4. |  Combo D - 5pcs Chicken Nuggets      |             18.00            |" << endl;
				cout << "|      |  + Regular Drink                     |                              |" << endl;
				cout << "|----------------------------------------------------------------------------|" << endl;
				cout << "|   5. |  Combo E - Big Dipper                |             21.00            |" << endl;
				cout << "|      |  + Regular Drink                     |                              |" << endl;
				cout << "|============================================================================|" << endl;
				cout << "\n"<<endl;
            
                cout << "Enter your choice [e.g Combo A please type 1] : ";
                cin >> fnbSel;
            
                while(fnbSel>5) //loop while choosing unavailable food & beverages serial
                {   
                    cout << "Combo serial is not available. Please re-enter your choice" << endl;
                    cin >> fnbSel;
                }
                switch (fnbSel) //Set data of fnb
                {
                case 1: fnb[itemcount] = "Combo A - 1x Signature Popcorn + Regular Drink";
                        fnbPrice[itemcount] = 18.00;
                        break;

                case 2: fnb[itemcount]  = "Combo B - 1x Royale Popcorn + Regular Drink";
                        fnbPrice[itemcount] = 21.00;
                        break;

                case 3: fnb[itemcount]  = "Combo C - 5pcs Hot Minis + Regular Drink";
                        fnbPrice[itemcount] = 18.00;
                        break;

                case 4: fnb[itemcount]  = "Combo D - 5pcs Chicken Nuggets + Regular Drink";
                        fnbPrice[itemcount] = 18.00;
                        break;

                case 5: fnb[itemcount]  = "Combo E = Big Dipper + Regular Drink";
                        fnbPrice[itemcount] = 21.00;
                        break;
                default:  break;
                }

				
				cout << "----------------------------------------------------------------" << endl;
                cout << "\t\t Drink Options " << endl; //drink option UI
				cout << "----------------------------------------------------------------" << endl;
                cout << "\t1. Coke(R)" << endl;
                cout << "\t2. Sprite(R)" << endl;
                cout << "\t3. Iced Lemon Tea(R)" << endl;
                cout << "\t4. Fanta Grape(R)" << endl;
                cout <<"\t5. Mineral Water"<<endl;
				cout << "----------------------------------------------------------------" << endl;

                cout << "What drinks you want [e.g Coke(R) please type 1] ? "; //DRINK
                cin >> drinkSel;

                while(drinkSel>5) //loop while choosing unavailable drinks serial
                {   
                    cout << "Drink serial is not available. Please re-enter your choice" << endl;
                    cin >> drinkSel;
                }

                switch (drinkSel) //Set data of drinks
                {
                    case 1: drink[itemcount] = "Coke(R)";
                            break;
                            
                    case 2: drink[itemcount] = "Sprite(R)";
                            break;

                    case 3: drink[itemcount] = "Iced Lemon Tea(R)";
                            break;

                    case 4: drink[itemcount] = "Fanta Grape(R)";
                            break;

                    case 5 : drink[itemcount] = "Mineral Water";
                            break;
                    default: break;
                    
                }

                cout<<"Do you want to continue order ? [Y/N] : ";
                cin>>choice;
				 
				//here will calc the price for fnb first
                t_fnbPrice = t_fnbPrice + fnbPrice[itemcount];
                itemcount++;
            }   
        }while(choice == 'Y' || choice == 'y');
    }
	friend class Receipt; 
	//friend with receipt class 
	//receipt class can have access for t_fnbPrice which is total price fnb that we calc justnow
	
	
};

class Screen //for seat UI
{
	private:
	const int rows = 6;
    const int columns = 10;
	char rowChar, choice;
    int seatNumber;
	
	public:
	int count = 0;
	char row[50];
	int col[50];
	void displayScreen()
	{
		cout << "\n";
		cout << "----------------------------------------------------------------" << endl;
    
		for (int row = 0; row < rows; ++row) //to display the row number
		{
			switch(row)
			{
			case 1:
			cout<<"A";
			break;
			case 2:
			cout<<"B";
			break;
			case 3:
			cout<<"C";
			break;
			case 4:
			cout<<"D";
			break;
			case 5:
			cout<<"E";
			}
			cout << " ";
        
			for (int col = 0; col < columns; ++col) //to dislpay the column number
			{	
				if ((col % 3 == 0) && (col != 0)) 
				{
					cout << "	     ";
				}
				if(row == 0 && col ==0)
				{
					cout<<"  "<<col+1<<" ";
				}
				else if(row == 0 && col ==1)
				{
					cout<<" "<<col+1<<" ";
				}
				else if(row == 0 && col ==2)
				{
					cout<<" "<<col+1<<" ";
				}
				else if(row == 0 && col ==3)
				{
					cout<<" "<<col+1<<" ";
				}
				else if(row == 0 && col ==4)
				{
					cout<<" "<<col+1<<" ";
				}
				else if(row == 0 && col ==5)
				{
					cout<<" "<<col+1<<" ";
				}
				else if(row == 0 && col ==6)
				{
					cout<<" "<<col+1<<" ";
				}
				else if(row == 0 && col ==7)
				{
					cout<<" "<<col+1<<" ";
				}
				else if(row == 0 && col ==8)
				{
					cout<<" "<<col+1<<" ";
				}
				else if(row == 0 && col ==9)
				{
					cout<<col+1<<" ";
				}
				else
				cout << "[ ]"; 
			}
        
			cout << "\n";
			cout << "----------------------------------------------------------------" << endl;
		}
    }
	
	void seatSelection(Customer &c2)
	{	
		int i = 0;
		do
		{
			cin.sync();
			cout<<"\nEnter the seat number you would like to choose [e.g A1]	     : ";
			cin>>rowChar>>seatNumber;
					
			if (rowChar != 'A' && rowChar != 'B' && rowChar != 'C' && rowChar != 'D' && rowChar != 'E' || seatNumber >=11 || seatNumber <=0)
			{
				cout<< "Invalid seat. Please try again."<<endl;
			}
			else
			{  	
				row[i] = rowChar;
				col[i] = seatNumber;
				cout<<"---------------Seat "<<row[i]<<col[i]<<" marked as occupied.--------------------"<<endl;
				count++;
				i++;
			}
		}while(count < c2.num); //c2.num mean will loop base on user enter how many ticket they enter justnow
	}
	
	friend class Customer; //can have access (for ticket) from Customer class 
};

class Receipt
{
	private:
	float pay, change = 0.0;
	float movie_price=20,totalprice=0; //we set all movie price as RM20.00
	public:
	~Receipt()
	{
		cout<<"HAVE A NICE DAY!!!"<<endl;
	}
	void calc(Customer &c1) //calculate the price
	{	
		totalprice = movie_price * c1.num;
		if(c1.studID =='Y' || c1.studID=='y')
		{
            totalprice *= 0.70;
            //if customer got studen ID will have discount
        }			
	
	}
	
	void displayReceipt(const Screen&S, const Customer&C)
	{
		cout<<"\n";
		cout<<"---------------------------------------------------------"<<endl;
		cout<<"|\t\t\t Receipt\t\t\t|"<<endl;
		cout<<"---------------------------------------------------------"<<endl<<endl;
		
		cout<<"\tName	        : "<<C.name<<endl; 
		cout<<"\tMovie Name	: "<<m.movie[C.pick_movie - 1]<<endl; 
		cout<<"\tMovie Time	: "<<m.showtime[C.pick_movie-1][C.pick_showtime-1]<<endl; 
		cout<<"\tSeat Number	: ";
		for (int i = 0; i < S.count; i++)
        {
            cout << S.row[i] << S.col[i] << " ";
        }
    cout << endl;
        if(C.choice_fnb == 'Y' || C.choice_fnb == 'y') //if user press Y for food n beverages
        {	
			cout<<"\n";
            cout<<"---------------------------------------------------------"<<endl;
		    cout<<"|\t\t    Food & Beverages\t\t\t|"<<endl;
		    cout<<"---------------------------------------------------------"<<endl<<endl;
            cout<<"Odered Items : "<<endl;
            for (int i = 0; i < C.itemcount; i++)
            {
                cout << C.fnb[i] << "\tRM " << fixed << setprecision(2) << C.fnbPrice[i] << endl;
                cout<<"Drinks Selection : "<<C.drink[i]<<endl;
				cout<<"\n";
            }
			//display information about food n beverages that user choose justnow
			totalprice += C.t_fnbPrice;
			//here will plus price movie and price food n beverages
        }
		
		do{
			cout<<"Total Payment	: RM"<<fixed << setprecision(2) <<totalprice<<endl; 
			cout<<"---------------------------------------------------------"<<endl<<endl;
			cout<<"Amount Paid	: RM";
			cin>>pay;
			cout<<"\n";
			if(pay < totalprice)
			{
				cout<<"Sorry! Kindly pay the sufficient amount of required sum! "<<endl;
			}
			else if(pay == totalprice)
			{
				cout<<"Thank You! Enjoy Your Movie!!!"<<endl;
			}
			else if(pay > totalprice)
			{
				change = pay - totalprice;
				cout<<"Thank You! This is Your Change	: RM"<<change<<endl;
			}
		}while(pay < totalprice); 
	}
	friend class Screen; //make receipt part can have access to display the seating place 
	friend class Customer; //access for food n beverages 
	//can know which fodd n drink user choose and total price for food
};	

class Manager : public User
{
private:
    int choice;
    char continuee;
    Selection s;

public:

    void verify()
    {   
        string *id = new string; //use dynamic memory allocation
        string password;
        cout << "Please enter your manager ID      : ";
        cin >> *id;
        do
        {
            cout << "Please enter the manager password : "; 
            cin >> password;

            if (password == "p22word2") //wrong password cant have access
            {
                do
                {
                    display_manager_menu();
                    cout << "Enter your choice : ";
                    cin >> choice;

                    while(choice > 4)
                    {
                        cout << "Invalid selection. Please reselect : ";
                        cin>>choice;
                    }

                    switch (choice)
                    {
                        case 1:
                            add(); 
                            break;

                        case 2:
                            update_showtime();
                            
                            break;

                        case 3:
                            delete_movie();
                            break;

                        case 4:
                            cout << "Exiting Manager Menu..." << endl;
                            return; //it will return if user press 4 on this menu selection

                        default: break;
                    }
                   
                } while (continuee == 'Y' || continuee == 'y'); //it will loop while user want to continue use to manager program
                
            }
            else
            {
                cout << "Invalid Login Attempt. Please try again." << endl << endl;
            }
        } while (password != "p22word2");
        delete id; // here will deallocate
    }
    void display_manager_menu() //manager UI 
    {
		cout<<"--------------------------------------------"<<endl;
        cout << "\t1. Add a new movie" << endl;
        cout << "\t2. Update the showtime for a movie" << endl;
        cout << "\t3. Delete a movie" << endl;
        cout << "\t4. Exit" << endl;
		cout<<"--------------------------------------------"<<endl;
    }

    void add() //manager can add movie 
    {   
        string new_movie;

        cout<<"Adding New Movie !!!\n"<<endl;
        cout << "Enter the name of the movie      : ";
        cin.sync();
        getline(cin, new_movie);

        int emptyindex = -1;

        for (int i = 0; i < 10; i++) //using for loop and if else to find empty movie array
        {
            if (m.movie[i] == " ") 
            {
                emptyindex = i; 
                break;
            }
        }

        if(emptyindex == -1)
        {
            cout<<"Movie is already full.Unable to add a new movie."<<endl;
            cout<<"If you want to continue to use program press[Y/y] : ";
            cin>>continuee;
            return;
        }

        for(int i = 0;i<10;i++) //using for loop and if else to check the movie exist or not by compare movie array with new_movie
        {
            if(m.movie[i] == new_movie)
            {   
                cout<<"Movie already exist"<<endl;
                cout<<"If you want to continue to use program press[Y/y] : ";
                cin>>continuee;
                return;
               
            }
        }
        
        m.movie[emptyindex] = new_movie; //assign the movie to empty movie array
        for (int i = 0; i < 3; i++) //using for loop to enter the showtime
        {   
            cout << "Enter the time for "<<i+1<<" show [HHMM] : ";
            cin >> m.showtime[emptyindex][i];
        }
        
        cout<<"\nYou are done, Manager ! If you want to continue to use program press [y / Y] : ";
        cin>>continuee;
        cout<<"\n"<<endl;
        
    }

    void update_showtime() //manager can update showtime 
    {   
        int index;

        m.display();
        cout << "Enter the serial number of the movie to update the showtime: ";
        cin >> index;
        index--;

        if (index < 0 || index >= 10 || m.movie[index] == " ") //using if else check the serial
        {
            cout << "Invalid movie selection. Please try again." << endl;
            cout<<"If you want to continue to use program press[Y/y] : ";
            cin>>continuee;
            return;
        }

       else
       {
            cout<<"-------------You Have Selected "<<m.movie[index]<<" Showtime------------------"<<endl;
            for (int i = 0; i < 3; i++) //using for loop to update the showtime
            {
                cout << "Enter the time for "<<i+1<<" show [HHMM]: ";
                cin >> m.showtime[index][i];
            }
            cout << "Showtime updated successfully." << endl;
            cout<<"If you want to continue to use program press[Y/y] : ";
            cin>>continuee;
        }
    }

    void delete_movie() //manager can delete movie
    {
        m.display();
        int index;
        cout << "Enter the serial number of the movie to delete: ";
        cin >> index;
        index--;

        if (index < 0 || index >= 10 || m.movie[index] == " ") //using if else check the serial
        {
            cout << "Invalid movie selection. Please try again." << endl;
            cout<<"If you want to continue to use program press[Y/y] : ";
            cin>>continuee;
            return;
        }

        else
        {
            m.movie[index] = " "; //set the selected movie array to empty
            for (int i = 0; i < 3; i++)//set the selected showtime array to empty
            {
                m.showtime[index][i] = " ";
            }

            for (int i = index; i < 9; i++) //using nested for loop to swifting the array infront
            {
                m.movie[i] = m.movie[i + 1];

                for(int j = 0 ; j < 3 ; j++)
                {
                    m.showtime[i][j] = m.showtime[i+1][j];
                }
            }
            cout << "Movie deleted successfully." << endl;
            cout<<"If you want to continue to use program press[Y/y] : ";
            cin>>continuee;
        }
    }


};

int main()
{
    Selection sel;
    int count_select = 0;

    do
    {
        sel.get_select(); // call the select A or B UI

        if (sel.choice == 'A' || sel.choice == 'a') // if user chooses customer
        {
            Customer cust;
            Screen s;
            Receipt r;

            cust.customer_input();         // customer inputs their information
            cust.pick_1();                 // customer selects movie, ticket, and show time
            s.displayScreen();             // booking seat system
            s.seatSelection(cust);         // let customer choose seating place within how many tickets they buy
            cust.foodndrinks();            // food and beverages system
            r.calc(cust);                  // calculate movie price
            r.displayReceipt(s, cust);     // display receipt with total price
            break;
        }
        else if (sel.choice == 'B' || sel.choice == 'b') // if user chooses manager
        {
            Manager m;
            m.verify(); // verify the password
            continue;
        }
        else
        {
            count_select++;
            if (count_select < 3) //user maximum can reselect three times
            {
                cout << "Invalid selection. Please re-select:\n ";
            }
            else
            {
                cout << "Maximum reselection attempts reached. Exiting program." <<endl;
                break;
            }
        }
        cout<<count_select;
    } while (count_select < 3 && (sel.choice != 'A' || sel.choice != 'a' || sel.choice != 'B' || sel.choice != 'b'));

    return 0;
}