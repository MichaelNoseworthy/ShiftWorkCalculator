// ShiftCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>


bool debugging = 0; //Set to 1 if you want to see debugging info

std::string ShiftCalculation(int dayShiftDays, int nightShiftDays, double dayShiftWage = 0.00, double nightShiftWage = 0.00, double hoursPerDay = 11.5)
{
    double total = 0;
    //get wage amounts
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

    int precisionVal = 2;
    return std::to_string(total).substr(0, std::to_string(total).find(".") + precisionVal + 1);

}

int main()
{
    //Note: Default hours per day set to 11.5
    //      Default wages set to 19.00 for day and 20.00 for nights 
    
    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout << std::setprecision(2) << std::fixed;
    
    int dayShiftDays = 0;
    int nightShiftDays = 0;
    double hoursPerDay = 11.5;
    double dayShiftWage = 0.00;
    double nightShiftWage = 0.00;
    bool wageHoursBool = 0;



    //std::cout << "Do you want to enter wages?  (0 for default hours, 1 for yes)";
    //std::cin >> wageHoursBool;

    if (wageHoursBool == 1)
    {
        std::cout << "Enter total amount of Wage for day shift: ";
        std::cin >> dayShiftWage;

        //Enter night shift hours
        std::cout << "Enter total amount of Wage for night shift: ";
        std::cin >> nightShiftWage;
    }


    {
        //Enter day shift hours
        std::cout << "Enter total amount of hours for day shift: ";
        std::cin >> dayShiftDays;
        //dayShiftHours = 6;

        //Enter night shift hours
        std::cout << "Enter total amount of hours for night shift: ";
        std::cin >> nightShiftDays;
        //nightShiftHours = 9;

        //std::ostringstream totalString = total;
        std::cout << "Total = $" + ShiftCalculation(dayShiftDays, nightShiftDays, dayShiftWage, nightShiftWage, hoursPerDay);
        std::cout << std::endl;
    }


}
