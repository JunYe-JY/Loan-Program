#include <iomanip>
#include <iostream>

using namespace std;

struct user_input {
    float amount_dollar;
    float interest_rate;
    float duration;
};

user_input get_input(void) {
    user_input input;
    cout << "Please enter the annual interest rate as percentage (e.g., 15 for "
    "15%) (enter 0 to quit): ";
    cin >> input.interest_rate;
    if (input.interest_rate == 0){
        cout << "Program Ended";
        exit(0);
    }
    input.interest_rate /= 100.0;
    cout << "Please enter the loan amount you would like to receive (in dollars): $";
    cin >> input.amount_dollar;
    cout << "Please enter loan period (in months): ";
    cin >> input.duration;
    input.duration /= 12.0;
    return input;
}

float calculate_loan(user_input input) {
    float amount_received;
    amount_received =
    (input.amount_dollar) / (1 - (input.interest_rate * input.duration));
    
    return amount_received;
}

bool play_again(void) {
    char response = 'n';
    cout << endl << "Do you want to calculate another loan? (Y/N): ";
    cin >> response;
    cout << endl;
    return (response == 'Y' || response == 'y');
}

void print(float amount, user_input input){
    cout << "-------------------------------------------------------------------------------------------" << endl << endl; 
    cout << "The total amount of your loan (including interest at 15% per annum) is $" << fixed << setprecision(2) << amount << endl;
    cout << "Your monthly payment for " <<  input.duration * 12 << " will be $" << fixed << setprecision(2) << amount / input.duration / 12;
    cout << endl << endl << "-------------------------------------------------------------------------------------------" << endl; 
}

int main() {
    float amount;
    do {
        user_input input = get_input();
        amount = calculate_loan(input);
        print(amount , input );
    } while (play_again());
    
    return 0;
}
