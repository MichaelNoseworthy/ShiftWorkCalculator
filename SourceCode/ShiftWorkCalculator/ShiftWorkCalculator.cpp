// ShiftCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Program to calculate the wage for a rotational day and night shift.

#include <iostream>
#include <string>


bool debugging = 0; //Set to 1 if you want to see debugging info

std::string ShiftCalculation(int dayShiftDays, int nightShiftDays, double dayShiftWage = 0.00, double nightShiftWage = 0.00, double hoursPerDay = 11.5)
{
    double total = 0;
    //get wage amounts if defaults are 0
    if (dayShiftWage == 0 && nightShiftWage == 0)
    {
        dayShiftWage = 19.00;
        nightShiftWage = 20.00;
    }


    if (debugging == 1)
    {
        std::cout << "Debugger: Dayshift Hours: " + std::to_string(dayShiftDays) + "\tNightshift Hours: " + std::to_string(nightShiftDays); std::cout << std::endl;
        std::cout << "Debugger: Dayshift wage: " + std::to_string(dayShiftWage) + "\tNightshift Wage: " + std::to_string(nightShiftWage); std::cout << std::endl;
    }
    
    //Calculating wage total
    if (dayShiftWage > 0.00)
    {
        if (nightShiftWage > 0.00)
        {
            total = (dayShiftWage * dayShiftDays * hoursPerDay) + (nightShiftWage * nightShiftDays * hoursPerDay);
        }
        else {
            std::string error = "Invalid night shift wage";
            return error;
        }
    }
    else {
        std::string error = "Invalid day shift wage";
        return error;
    }

    if (debugging == 1)
    {
        std::cout << "Debugger: " + std::to_string(total); std::cout << std::endl;
    }

    int precisionVal = 2; //setting double precision to x decimal places
    return std::to_string(total).substr(0, std::to_string(total).find(".") + precisionVal + 1); //Making sure that the output looks like 0.00

}

//Checks if number is an integer and corrects user.
bool has_only_int(std::string &answer) {
    bool aux = false;
    do {
        if (answer.find_first_not_of("0123456789") == std::string::npos)
        {
            aux = true;
            return answer.find_first_not_of("0123456789") == std::string::npos;
        }
        else
        {
            std::cout << "Invalid Number.  Please enter valid number." << std::endl;
            std::cin >> answer;
        }
    } while (aux == false);
}

//Checks if number is an double and corrects user.
bool has_only_double(std::string &answer) {
    bool aux = false;
    do {
        if (answer.find_first_not_of("0123456789.") == std::string::npos)
        {
            if ((std::count(answer.begin(), answer.end(), '.') <= 1 ))
            {
                aux = true;
                return answer.find_first_not_of("0123456789.") == std::string::npos;
            }
            std::cout << "Invalid Number.  Please enter valid decimal number." << std::endl;
            std::cin >> answer;
        }
        else
        {
            std::cout << "Invalid Number.  Please enter valid decimal number." << std::endl;
            std::cin >> answer;
        }
    } while (aux == false);
}

//Checks if number is an double and corrects user.
bool has_only_bool(std::string &answer) {
    bool aux = false;
    do {
        if (answer.find_first_not_of("01") == std::string::npos)
        {
            aux = true;
            return answer.find_first_not_of("01") == std::string::npos;
        }
        else
        {
            std::cout << "Invalid Number.  Please enter valid  1 or 0 number." << std::endl;
            std::cin >> answer;

        }
    } while (aux == false);
}

int main()
{
    //Note: Default hours per day set to 11.5
    //      Default wages set to 19.00 for day and 20.00 for nights 
    
    //Initialize values
    int dayShiftDays = 0;
    int nightShiftDays = 0;
    double hoursPerDay = 11.5; //Add a function value to change if needed within the script.
    double dayShiftWage = 0.00;
    double nightShiftWage = 0.00;
    bool wageHoursBool = 0;
    bool aux = false;
    std::string answer;
    


    //Start program
    bool sentinal = 1;
    while (sentinal == 1)
    {


        std::cout << "Do you want to enter wages?  (0 for default hours, 1 for yes)";
        std::cin >> answer;
        has_only_bool(answer);
        wageHoursBool = (answer == "1");

        if (wageHoursBool == 1)
        {
            std::cout << "Enter total amount of Wage for day shift: ";
            std::cin >> answer;
            has_only_double(answer);
            dayShiftWage = stoi(answer);

            //Enter night shift hours
            std::cout << "Enter total amount of Wage for night shift: ";
            std::cin >> answer;
            has_only_double(answer);
            nightShiftWage = stoi(answer);
        }


        //Enter day shift hours
        std::cout << "Enter total amount of days for day shift: ";
        std::cin >> answer;
        has_only_int(answer);
        dayShiftDays = stoi(answer);


        //Enter night shift hours
        std::cout << "Enter total amount of days for night shift: ";
        std::cin >> answer;
        has_only_int(answer);
        nightShiftDays = stoi(answer);


        //total calculation
        std::cout << "Monthly Total = $" + ShiftCalculation(dayShiftDays, nightShiftDays, dayShiftWage, nightShiftWage, hoursPerDay);
        std::cout << std::endl;
     
        std::string answer;
        std::cout << "Do you wish to continue?  0 for no and 1 for yes: ";
        std::cin >> answer;

        //Asks user if you want to do this operation over again.
        if (answer == "0" || answer == "1")
        {
            if (answer == "0")
                sentinal = 0;

            if (answer == "1")
            {
                sentinal = 1;
                system("CLS");
            }
        }
        else 
        {
            std::cout << "Wrong answer entered.  Exiting program." << std::endl;
            break;
        }
        //End sentinal while loop.
    }
}
