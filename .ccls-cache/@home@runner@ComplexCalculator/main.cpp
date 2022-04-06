// Author : Steffano Martinez
// Florida Altantic University 2022 - Circuits 1 
// Enjoy!
// Version 1.0

#include <iostream> //cin and cout
#include <cmath> //math stuff
#include <iomanip> //input and output manipulation
using namespace std;

//Pi defined
#define pi 3.14159 

//This is Rectangular to Polar form, getting only magnitude
double RtoP_mag(double x, double y)
{
  double mag = sqrt(pow(x,2) + pow(y,2)); //Obtain the magnitude
  return mag;
}

//This is Rectangular to Polar form, getting only angle
double RtoP_angle(double x, double y)
{
  double val = y/x; // Get the value as a single ratio
  double angle = atan(val); // This will give value in radians
  angle = angle * 180/pi; // Angle degree conversion
  if (y < 0 && x < 0) // Quadrant III
  {
    angle = angle - 180;
  }
  if (x < 0 && y > 0) // Quadrant II
  {
  angle = 180 - abs(angle);
  }
  // Else the angle will be on Quadrant I or IV (or -I), ok with inverse    tan domain restriction.
  return angle;
}

//This is Polar to Rectangular, meaning x value.
double PtoR_real(double mag,double angl)
{
  double angle = angl * (pi/180); //Convert degrees to radians.
  angle = cos(angle); // Get the value.
  double real_value = mag*angle; // Do r*cos()
  return real_value;
}

//This is Polar to Rectangular, meaning y value.
double PtoR_imag(double mag,double angl)
{
  double angle = angl * (pi/180);
  angle = sin(angle);
  double imag_value = mag*angle;
  return imag_value;
}

//Function to request rectangular to polar conversion.
void RtoP_function()
{
  double real_part; // Define Real Part
  double imag_part; // Define Imaginary Part
  double magnitude; // Define Magnitude
  double angle; // Define Angle
  cout << "Enter real part: ";
  cin >> real_part;
  cout << "Enter imaginary part: ";
  cin >> imag_part;
  angle = RtoP_angle(real_part,imag_part);
  magnitude = RtoP_mag(real_part,imag_part);
  cout << "Hello World!, this is the magnitude: " << fixed <<     setprecision(2) << magnitude << "\n";
  cout << "And this is the angle : " << angle << " degrees." << "\n";
}

//Function to request polar to rectangular conversion.
void PtoR_function()
{
  double real_part; // Define Real Part
  double imag_part; // Define Imaginary Part
  double magnitude; // Define Magnitude
  double angle; // Define Angle
  cout << "Enter the magnitude: " << "\n";
  cin >> magnitude;
  cout << "Enter the angle: " << "\n";
  cin >> angle;
  real_part = PtoR_real(magnitude,angle);
  imag_part = PtoR_imag(magnitude,angle);
  cout << "Rectangular form: " << "\n";
  cout << "Real part: " << fixed << setprecision(2) << real_part << "\n";
  cout << "Imaginary part: " << fixed << setprecision(2) << imag_part << "j" << "\n";
  
}

//This is rectangular addition or susbtraction.
void ComplexAdd_Sub(double real1, double imag1, double real2, double imag2)
{
  string oper;
  cout << "Input either + or -, depending on your operator: ";
  cin >> oper;
  if (oper == "+")
  {
    double real = (real1 + real2);
    double imag = (imag1 + imag2);
    cout << "The real part is: " << real << "\n";
    cout << "The imaginary part is: " << imag << "j" << "\n";
  }
  if (oper == "-")
  {
    double real = (real1 - real2);
    double imag = (imag1 - imag2);
    cout << "The real part is: " << real << "\n";
    cout << "The imaginary part is: " << imag << "j" << "\n";
  }
}

//Function to request complex addition or susbtraction
void CompAdd_Sub_function()
{
  double real_part_1; // Define Real Part
  double imag_part_1; // Define Imaginary Part
  double real_part_2; // Define Real Part
  double imag_part_2; // Define Imaginary Part
  cout << "Enter the real part for the 1st term: " << "\n";
  cin >> real_part_1;
  cout << "Enter the imaginary part for the 1st term: " << "\n";
  cin >> imag_part_1;
  cout << "Enter the real part for the 2nd term: " << "\n";
  cin >> real_part_2;
  cout << "Enter the imaginary part for the 2nd term: " << "\n";
  cin >> imag_part_2;
  ComplexAdd_Sub(real_part_1,imag_part_1,real_part_2,imag_part_2);
}

//This is polar multiplication and division
void ComplexMult_Div(double mag1, double angl1, double mag2, double angl2)
{
  string oper;
  cout << "Input either * or /, depending on your operator: ";
  cin >> oper;
  if (oper == "*")
  {
    double mag = mag1 * mag2;
    double angl = (angl1 + angl2);
    cout << "The magnitude is: " << mag << "\n";
    cout << "The angle is: " << angl << "\n";
  }
  if (oper == "/")
  {
    double mag = mag1 / mag2;
    double angl = (angl1 - angl2);
    cout << "The magnitude is: " << mag << "\n";
    cout << "The angle is: " << angl << "\n";
  }
}

//Function to request complex multiplication or division
void ComplexMult_Div_function()
{
  double mag_part_1; // Define Real Part
  double angle_part_1; // Define Imaginary Part
  double mag_part_2; // Define Real Part
  double angle_part_2; // Define Imaginary Part
  cout << "Enter the magnitude for the 1st term: " << "\n";
  cin >> mag_part_1;
  cout << "Enter the angle for the 1st term: " << "\n";
  cin >> angle_part_1;
  cout << "Enter the magnitude for the 2nd term: " << "\n";
  cin >> mag_part_2;
  cout << "Enter the angle for the 2nd term: " << "\n";
  cin >> angle_part_2;
  ComplexMult_Div(mag_part_1,angle_part_1,mag_part_2,angle_part_2);
}

int main() {
  int sys_on = 0;
  int choice = 0;
  string response;
  //Continiously runs the different algorithms
  while(sys_on == 0)
  {
    cout << "Choose from: \n";
    cout << "(1) = Polar to Rectangular" << "\n";
    cout << "(2) = Rectangular to Polar" << "\n";
    cout << "(3) = Complex Addition or Susbtraction" << "\n";
    cout << "(4) = Complex Multiplication or Division" << "\n";
    cout << "(9) = Exit" << "\n";
    cout << "Choice: ";
    cin >> choice;
    if (choice == 1)
    {
      PtoR_function();
      cout << "Again? (yes or no): ";
      cin >> response;
      while (response == "yes")
        {
          PtoR_function();
          cout << "Again? (yes or no): ";
          cin >> response;
        }
    }
    if (choice == 2)
    {
      RtoP_function();
      cout << "Again? (yes or no): ";
      cin >> response;
      while (response == "yes")
      {
        RtoP_function();
        cout << "Again? (yes or no): ";
        cin >> response;
      }
    }
    if (choice == 3)
    {
      CompAdd_Sub_function();
      cout << "Again? (yes or no): ";
      cin >> response;
      while (response == "yes")
      {
        CompAdd_Sub_function();
        cout << "Again? (yes or no): ";
        cin >> response;
      }
    }
    if (choice == 4)
    {
      ComplexMult_Div_function();
      cout << "Again? (yes or no): ";
      cin >> response;
      while (response == "yes")
      {
        ComplexMult_Div_function();
        cout << "Again? (yes or no): ";
        cin >> response;
      }
    }
    if (choice == 9)
    {
      sys_on = 1;
      break;
    }
  }
  
  return 0;
}