#include <iostream>
#include <string>
#include <vector>
using namespace std;

// declaration of derived classes

class Bus;
class Car;

// declaration of user classe

class User;

//declration of functions

void bookBus(User users[], int, vector<Bus>& buses);
void bookCar(User users[], int , vector<Car>& cars) ;

//Booking class "base class" defined

class Booking 
{
	protected:
	    int booking_id;
	    int user_id;
	    double amount;
	    string payment_status;
	    bool isconfirmed;
	
	public:
		
	    // constructors
	    
	    Booking()
	    {
	    	this->booking_id=0;
	    	this->user_id=0;
	    	this->amount=0;
	    	this->payment_status="Not Given";
	    	this->isconfirmed=false;
		}
		Booking(int bid, int uid, double a, string s, bool c)
	    {
	    	this->booking_id=bid;
	    	this->user_id=uid;
	    	this->amount=a;
	    	this->payment_status=s;
	    	this->isconfirmed=c;
		}
		
		//setters 
		
	    void setBookingId(int bid) 
		{ 
			this->booking_id = bid; 
		}
	    void setUserId(int uid) 
		{ 
			this->user_id = uid; 
		}
	    void setAmount(double a) 
		{
			this->amount = a; 
		}
	    void setPaymentStatus(string s) 
		{ 
			this->payment_status = s; 
		}
	    void setIsconfirmed(bool c) 
		{ 
			this->isconfirmed = c; 
		}
	
		//getters
		
	    int getBookingId() 
		{ 
			return booking_id; 
		}
	    int getUserId() 
		{ 
			return user_id; 
		}
	    double getAmount() 
		{ 
			return amount; 
		}
	    string getPaymentStatus() 
		{ 
			return payment_status; 
		}
	    bool getIsconfirmed() 
		{ 
			return isconfirmed; 
		}
			
		// virtual functions
			
	    virtual bool confirmBooking() = 0;
	    virtual void book() = 0;
		
		//functions
		
	    void display() 
		{
	        cout << "\nBooking id : " << booking_id << endl;
	        cout << "\nUser id : " << user_id << endl;
	        
	        if (payment_status == "Done") 
			{
	            cout << "Confirmed: " << (isconfirmed ? "Yes" : "No") << endl;
	        } 
			else 
			{
	            cout << "Payment is failed." << endl;
	        }
	    }
};

// derived class Bus

class Bus : public Booking
{
    int bus_no;
    int no_of_seats;
    string busType;
    string seatType;

	public:
		
		//constructors
		
	    Bus() 
		{
			this->bus_no=0;
			this->no_of_seats=30;
			this->busType="Not Given";
			this->seatType="Not Given";	
		}
		
	    Bus(int bno, int seats, string type, string seat)
		{
			this->bus_no=bno;
			this->no_of_seats=seats;
			this->busType=type;
			this->seatType=seat;		
		
		}
	
		//setters
		
	    void setBusNo(int bno) 
		{ 
			this->bus_no = bno; 
		}
	    void setNoOfSeats(int seats) 
		{ 
			this->no_of_seats = seats; 
		}
	    void setBusType(const string& type) 
		{ 
			this->busType = type; 
		}
	    void setSeatType(const string& type) 
		{ 
			this->seatType = type; 
		}
	
		//getters
		
	    int getBusNo()
		{ 
			return bus_no; 
		}
	    int getNoOfSeats() 
		{
			 return no_of_seats;
		}
	    string getBusType() 
		{ 
			return busType; 
		}
	    string getSeatType() 
		{ 	
			return seatType; 
		}
	
		// functions
		
	    void display() 
		{
	        Booking::display();
	        cout << "\nBus no : " << bus_no << endl;
	        cout << "\nNo. of seats : " << no_of_seats << endl;
	        cout << "\nBus type : " << busType << endl;
	    }
	
		// virtual function defination
		
	    bool confirmBooking() 
		{
	        cout << "\nAvailable Seats: " << getNoOfSeats() << endl;
	
	        if (getNoOfSeats() > 0) 
			{
	            setIsconfirmed(true);
	            setNoOfSeats(getNoOfSeats() - 1); // Decrement the number of available seats
	            return true;
	        } 
			else 
			{
	            cout << "\nNo available seats on the bus." << endl;
	            return false;
	        }
	    }
	
	    void book() {}
};

// derived class Car

class Car : public Booking 
{
    int car_no;
    int no_of_seats;
    string carType;

	public:
		
		//constructors
		
	    Car()
		{
			this->car_no=0;
			this->no_of_seats=4;
			this->carType="Not Given"; 	
		}
	    Car(int cno, int seats, string type) 
		{
			this->car_no=cno;
			this->no_of_seats=seats;
			this->carType=type; 
		} 
	
		//setters
		
	    void setCarNo(int cno) 
		{ 
			this->car_no = cno; 
		}
	    void setNoOfSeats(int seats) 
		{ 
			this->no_of_seats = seats; 
		}
	    void setCarType(const string& type) 
		{ 
			this->carType = type; 
		}
	
		//getters
		
	    int getCarNo() 
		{ 
			return car_no; 
		}
	    int getNoOfSeats()
		{ 
			return no_of_seats;
		}
	    string getCarType() 
		{ 
			return carType; 
		}
		
		//display function
	
	    void display() 
		{
	        Booking::display();
//	        cout << "Car no : " << car_no << endl;
	        cout << "\nNo. of seats : " << no_of_seats << endl;
	        cout << "\nCar type : " << carType << endl;
	    }
	    
		// virtual function
		
	    bool confirmBooking() 
		{
	        cout << "\nAvailable Cars: " << "\t";
	        cout << "\nCar no: " << car_no << ", Type: " << carType << ", Seats: " << no_of_seats << endl;
	
	        setIsconfirmed(true);
	        return true;
	    }
	
	    void book() {}
};


// class user

class User 
{
	private:
	    static int last_user_id;
	    int user_id;
	    string user_name;
	    int age;
	    string gender;
	    string gmail_id;
	    string paymentStatus; // Added payment status
	
	public:
		
		//constructors
		
	    User()
		{
			this->user_id=++last_user_id;
			this->user_name="Not Given";
			this->age=0;
			this->gender="Not Given";
			this->gmail_id="Not Given";
			this->paymentStatus="Not Done";	
		}
	    User(int u_id, const string& name, int user_age, const string& user_gender, const string& user_email)
	    {
	   		this->user_id=++u_id;
			this->user_name=name;
			this->age=user_age;
			this->gender=user_gender;
			this->gmail_id=user_email;	
		}
		
		//setters
		
	    void setName(const string& name) 
		{ 
			this->user_name = name; 
		}
	    void setAge(int user_age) 
		{ 
			this->age = user_age; 
		}
	    void setGender(const string& user_gender) 
		{ 
			this->gender = user_gender; 
		}
	    void setGmailId(const string& user_email) 
		{ 
			this->gmail_id = user_email; 
		}
	    void setPaymentStatus(const string& status) 
		{ 
			this->paymentStatus = status; 
		} 
	
		//getters
		
	    int getUserId()  
		{ 
			return user_id; 
		}
	    const string& getName()  
		{ 
			return user_name; 
		}
	    int getAge() 
		{ 
			return age; 
		}
	    const string& getGender()  
		{ 
			return gender; 
		}
	    const string& getGmailId()  
		{ 
			return gmail_id; 
		}
	    const string& getPaymentStatus()  
		{ 
			return paymentStatus; 
		} 
	
		// function
	    void displayUser()  
		{
	        cout << "\nUser ID: " << user_id << endl;
	        cout << "\nUser Name: " << user_name << endl;
	        cout << "\nAge: " << age << endl;
	        cout << "\nGender: " << gender << endl;
	        cout << "\nGmail ID: " << gmail_id << endl;
	        cout << "\nPayment Status: " << paymentStatus << endl;
	    }
	    
		// static 
	    static int getLastUserId() 
		{ 
			return last_user_id; 
		}
	    static void setLastUserId(int id) 
		{ 
			last_user_id = id; 
		}
	
		// friend function
		
	    friend void user_registration(User users[], int& userCount, int MAX_USERS);
};


// declration of static variable

int User::last_user_id;

// user registration function

void user_registration(User users[], int& userCount, int MAX_USERS) 
{
    string name, gender, email;
    int age;
    int id = User::getLastUserId() + 1;
    
    cout << "\nEnter User Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Gender: ";
    cin.ignore();
    getline(cin, gender);
    cout << "Enter Email: ";
    cin >> email;

    if (userCount < MAX_USERS) 
	{
        users[userCount] = User(id, name, age, gender, email); // No payment status
        userCount++;
        User::setLastUserId(id);
        cout << "\nUser registered successfully!" << endl;
    } 
	else 
	{
        cout << "\nMaximum number of users reached!" << endl;
    }
}

// view user data function

void view_user_data(User users[], int count) {
    cout << "\nUser Details:\n";
    for (int i = 0; i < count; ++i) {
        users[i].displayUser();
    }
}

// Booking of bus 

void bookBus(User users[], int userCount, vector<Bus>& buses) 
{
    string busType, seatType;
    int userIndex;

    
    cout << "Choose your bus type (AC/Normal): ";
    cin >> busType;
    cout << "Choose your seat type (Seater/Sleeper): ";
    cin >> seatType;

    
    cout << "Enter your user ID: ";
    cin >> userIndex;

    if (userIndex < 1 || userIndex > userCount) 
	{
        cout << "Invalid user ID!" << endl;
        return;
    }


   
    for (auto& bus : buses) 
	{
        
        if (bus.getBusType() == busType && bus.getSeatType() == seatType && bus.getNoOfSeats() > 0) 
		{
            cout << "\nBus available with type: " << bus.getBusType() << ", seat type: " << bus.getSeatType() << endl;
            cout << "\nNo. of available seats: " << bus.getNoOfSeats() << endl;

            if (bus.confirmBooking()) 
			{
                cout << "\nBooking confirmed!" << endl;
                return; 
            } 
			else 
			{
                cout << "\nNo available seats on the bus." << endl;
                return; 
            }
        }
    }

   
    cout << "No buses available matching your criteria." << endl;
}


// car booking function

void bookCar(User users[], int userCount, vector<Car>& cars) 
{
    string carType;
    int userIndex;

   
    cout << "Choose your car type (SUV/Sedan): ";
    cin >> carType;

    cout << "Enter your user ID: ";
    cin >> userIndex;

    if (userIndex < 1 || userIndex > userCount) 
	{
        cout << "Invalid user ID!" << endl;
        return;
    }

   
    for (auto& car : cars) 
	{
        if (car.getCarType() == carType) 
		{
            cout << "\nCar available with type: " << car.getCarType() << ", Seats: " << car.getNoOfSeats() << endl;

            if (car.confirmBooking()) 
			{
                cout << "Booking confirmed!" << endl;
                return; 
            } 
			else 
			{
                cout << "Booking failed." << endl;
                return; 
            }
        }
    }

   
    cout << "No cars available matching your criteria." << endl;
}


// main  

int main() 
{
    const int MAX_USERS = 10;
    User users[MAX_USERS];
    int userCount = 0;

    vector<Bus> buses = {
        Bus(101, 50, "AC", "Seater"),
        Bus(102, 20, "AC", "Sleeper"),
        Bus(103, 30, "Normal", "Seater"),
        Bus(104, 10, "Normal", "Sleeper")
    };
    
     vector<Car> cars = {
        Car(101, 4, "SUV"),
        Car(102, 4, "SUV"),
        Car(103, 4, "Sedan"),
        Car(104, 4, "Sedan")
    };
     
    // Initialize last_user_id to 0
	 
    User::setLastUserId(0); 

    char choice;
    
    cout<<"Travel Management System "<<endl;
    cout<<"========================"<<endl;
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Register a new user\n";
        cout << "2. View all registered users\n";
        cout << "3. Book a Bus \n";
        cout<<"4. Book a car\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case '1':
                user_registration(users, userCount, MAX_USERS);
                break;
            case '2':
                cout << "\nAll Registered Users:\n";
                view_user_data(users, userCount);
                cout << endl;
                break;
            case '3':
                bookBus(users, userCount, buses);
                break;
            case '4':
                bookCar(users, userCount, cars);
                break;
            case '5':
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != '5');

    return 0;
}
