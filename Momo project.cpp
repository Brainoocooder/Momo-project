#include <iostream>
using namespace std;

void Authentication() {
    string phoneNumber;
    string authPin;
    bool x = true;
    
    while(x == true){
	
	    cout<<"Enter Phone Number"<<endl;
	    cout<<"0";
	    cin>>phoneNumber;
        if(phoneNumber.length() != 9){
            cout<<"Enter a valid Phone Number."<<endl<<endl;
        }
        else {
			x = false;
		}
	}
	
	x = true;
	while(x == true){
		cout<<"Enter 4-digit PIN"<<endl;
	    cin>>authPin;
		if(authPin.length() != 4){
			cout<<"Enter a valid 4-digit PIN"<<endl;
		}
		else {
			x = false;
		}

    }
    return;
}

string Reset(string pin) {
	string oldPin = pin;
	string newPin;
	string enteredPin;
	
	cout << "Enter old PIN: ";
	cin >> enteredPin;
	if (enteredPin != oldPin){
		cout<<"\nIncorrect PIN"<<endl;
	}
	else{
		cout<<"Enter new PIN: ";
		cin>>newPin;
		if (newPin.length() != 4){
			cout<<"\nEnter a 4-digit PIN"<<endl;
		}
		else{
			cout << "\nPIN successfully changed."<<endl;
			pin = newPin;
			oldPin = newPin;
		}
		
	}
	return pin;
}

void Balance(int balance, string pin){
	string enteredPin;
	int x = 3;
	int j = false;
	while(x != 0 && j == false){
		cout<<"Enter PIN: ";
		cin>>enteredPin;
		
		if (enteredPin == pin){
			cout << "Your balance is $" << balance;	
			j=true;	
		}
		else{
			x--;
		}
	}
}

void phone(){
	string phoneNum;
    string comfPhoneNum;
	
	bool x = true;
	while(x == true){
		cout<<"Enter Phone Number: ";
		cin>>phoneNum;
		if (phoneNum.length() != 10){
		cout<<"Enter a valid Phone Number."<<endl<<endl;
		}	
		else {
			x = false;
		}

    }

	
	cout<<"Comfirm Phone Number: ";
	cin>>comfPhoneNum;
	
	if (phoneNum != comfPhoneNum){
		cout<<"Phone numbers doesn't match."<<endl;
		phone();
	}
	
}

int sendMoney(int balance, string pin){
    int amount;
    
	cout << "Enter the amount to send: ";
    cin >> amount;
    
	phone();
	
	
	string enteredPin;
	int x = 3;
	int j = false;
	while(x != 0 && j == false){
		cout<<"Enter PIN: ";
		cin>>enteredPin;
		if (enteredPin == pin){
			if (amount > balance) {
		        cout << "Insufficient balance.\n";
		    } else {
		        balance -= amount;
		        cout << "Money sent successfully.\n";
		        cout << "Your new balance is $" << balance << ".\n";
		    }	
		    j=true;
		}
		else{
			x--;
		}
	}

    return balance;
}

int main(){
	
	Authentication();
	cout<<endl;

	string pin = "0000";
	int balance = 1000;

	
	while (true) {
		cout<<"Welcome to the Mobile Money Service."<<endl;
        cout << "1. Reset/Change PIN\n";
        cout << "2. Check Balance\n";
        cout << "3. Send Money\n";
        cout << "4. Exit\n";
        cout << "Choose your option: ";
        
        int choice;
        cin >> choice;
        cout << endl;
        
        switch (choice) {
            case 1: // Reset/Change PIN 
				pin = Reset(pin);
                cout << endl;
                break;
                
            case 2: // Check Balance
				Balance(balance, pin);
                cout << endl;
                break;
                
            case 3:  // Send Money
				balance = sendMoney(balance, pin);
                cout << endl;
                break;
                
            case 4: // Exit
                cout << "Exiting...\n";
                return 0;
                
            default:
                cout << "Invalid choice.\n";
        }
        
        cout << endl;
    }
	
	return 0;
}
