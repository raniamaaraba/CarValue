#include <iomanip>
#include <iostream>

/*
 * car_model_year: Takes no parameters and prompts the user to enter
 * the model year of the car they are listing. The model year of the
 * car is returned as an integer (`int`).
 *
 * returns: the model year of the code as entered by the user (`int`).
 */
int car_model_year() {
  int model_year{0};
  std::cout << "What is the model year of the car? ";
  std::cin >> model_year;
  return model_year;
}

/*
 * car_accidents: Takes no parameters and prompts the user to enter
 * the number of accidents the car has been in. The number of accidents
 * is returned as an integer (`int`).
 *
 * returns: the number of accidents as entered by the user (`int`).
 */
int car_accidents() {
  int accidents{0};
  std::cout << "How many accidents has the car been in? ";
  std::cin >> accidents;
  return accidents;
}

/*
 * car_msrp: Takes no parameters and prompts the user to enter
 * the car's MSRP. The car's MSRP is returned as a floating-point
 * number (`double`).
 *
 * returns: the car's MSRP as entered by the user (`double`).
 */
double car_msrp() {
  double msrp{0.0};
  std::cout << "How much did you pay for the car? ";
  std::cin >> msrp;
  return msrp;
}

/*
 * car_has_premium_options: Takes no parameters and prompts the user
 * to enter whether the car has premium options. The presence of premium
 * options on the car is return as a Boolean (`bool`).
 *
 * returns: whether the car has premium option as entered by the user (`bool`).
 */
bool car_has_premium_options() {
  std::string has_options_string{""};
  std::cout << "Does your car have premium options (yes/no)? ";
  std::cin >> has_options_string;
  if (has_options_string == "yes") {
    return true;
  } else {
    return false;
  }
}

/*
 * print_eligible_message: Takes a single parameter (the car's resale value
 * as a floating-point number [`double`]) and prints a nice message telling
 * the user their car is eligible for sale through dappreciation and its price.
 *
 * returns: nothing
 */
void print_eligible_message(double resale_price) {
  std::cout << std::fixed << std::setprecision(2)
            << "dappreciation will list your car for $" << resale_price
            << ".\n";
}

/*
 * print_ineligible_message: Takes no parameters and prints a nice message telling
 * the user their car is ineligible for sale through dappreciation.
 *
 * returns: nothing
 */
void print_ineligible_message() {
  std::cout << "Unfortunately your car is ineligible for the dappreciation "
               "platform.\n";
}

int main() {
  double baseline{-1}, wreck, premium, FSR, price;

  auto user_model_year{car_model_year()};
  auto user_car_accidents{car_accidents()};
  auto user_car_has_premium_options{car_has_premium_options()};
  double user_car_msrp{car_msrp()};
 
  user_model_year = 2023 - user_model_year;


  if (user_model_year < 11 && user_car_accidents <= 3) {
    if (user_model_year < 5) {
      baseline = 0.85;
    } else if (user_model_year < 9 ) {
      baseline = 0.63;
    } else if (user_model_year <= 10) {
      baseline = 0.45;
    }

    if (user_car_accidents == 3) {
      wreck = 0.20;
    } else if  (user_car_accidents == 2) {
      wreck = 0.10;
    } else if (user_car_accidents == 1) {
      wreck = 0.02;
    } else {
      wreck = 0;
    }

    if (user_car_has_premium_options == 1) {
      premium = 0.05;
    } else {
      premium = 0;
    }


    FSR = baseline - wreck + premium;

    price = user_car_msrp * FSR;

    print_eligible_message(price);


  } else {
   print_ineligible_message();
  }

  

    return 0;
}