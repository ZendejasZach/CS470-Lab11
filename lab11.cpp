/***********************************************************************
* Program:
*    Lab 11, Zach Zendejas
*    Brother Wilson, CS470
* Author:
*    Zach Zendejas
* Summary: 
*    1. What this program is designed to do
*        This program prompts the user for a password, then determines how
*        many combinations of passwords exist in the set. Then determines
*        the bit equivalence based on the number of combinations
*    2. How this program will go about solving the problem
*        First, the program will prompt the user for a password. Then it
*        determines the number of combinations via the checkCombonations
*        function. After that it determines the key via the checkKey 
*        function.
*    3. What assumptions about input (file or user) is made
*        The user would input ASCII characters
*    4. Citations if the algorithm was borrowed or inspired from any source
*        http://www.cplusplus.com/reference/cctype/isupper/
*        http://www.cplusplus.com/reference/cctype/islower/
*        https://www.techiedelight.com/convert-string-char-array-cpp/
*        http://www.cplusplus.com/reference/cmath/log2/
************************************************************************/

#include <iostream>        // for cout and cin
#include <istream>         // for getline
#include <stdio.h>
#include <string.h>        // easier input
#include <ctype.h>         // for isupper & islower
#include <cstring>
#include <math.h>          // for pow

using namespace std;

/***********************************************************************
 * Prompt Password
 * Prompts the user for a password to be used for the program
 * OUTPUT: password
 *       password that was entered in by the user. 
 * ********************************************************************/
string promptPassword()
{
   string password;

   cout << "Please enter the password: ";
   getline(cin, password);

   return password;
}

/***********************************************************************
 * alphabet Size
 * This function determines what is in the password variable and 
 * calculates its alphabet size
 * INPUT: password
 *       Users password that was given earlier
 * OUTPUT: n
 *       Alphabet size
 * ********************************************************************/
int alphabetSize(string password)
{
   bool upper = 0;
   bool lower = 0;
   bool digit = 0;
   bool specChar = 0;
   int alphaSize = 0;

   // convert password string to char array
   int size = password.length();
   char charPassword[size + 1];
   password.copy(charPassword, password.size() + 1);
   charPassword[password.size()] = '\0';

   // go through the string to determine what characters are used
   for(int i = 0; i < size; i++)
   {
      char c = password[i];

      // checks for alpha characters
      if (isupper(c))
         upper = 1;
         
      if (islower(c))
         lower = 1;

      // checks for digits
      else if (isdigit(c))
         digit = 1;

      // checks for other special characters
      else if (!isalpha(c) && !isdigit(c) && isascii(c))
         specChar = 1;
   }

   // add up alphabet size from test ran
   if (upper == 1)
      alphaSize += 26;
   if (lower == 1)
      alphaSize += 26;
   if (digit == 1)
      alphaSize += 10;
   if (specChar == 1)
      alphaSize += 32;

   return alphaSize;
}

/***********************************************************************
 * check Combinations
 * Checks to see how many combinations there are for the given password
 * INPUT: Password
 *       The users password that was entered previously
 * OUTPUT: Combinations
 *       The number of combinations from the password
 * ********************************************************************/
double checkCombinations(string password)
{
   // Variables
   int m = password.length();
   int n;
   double comb;

   // determine alphabet size
   n = alphabetSize(password);

   // calculate combinations
   comb = pow(n, m);

   // return it to the user
   cout.precision(14);
   cout << "There are " << comb << " combinations\n";

   return comb;
}

/***********************************************************************
 * check Key
 * This will take the combinaations and convert it to a key bit value
 * INPUT: Combinations
 *       The number of combinations that were determined previously
 * OUTPUT: key
 *       The key equivalent from the combinations
 * ********************************************************************/
int checkKey(double c)
{
   int key = log2(c);

   cout << "That is equivalent to a key of " << key << " bits\n";

   return 0;
}

/***********************************************************************
 * Main Program
 * This carries out all the sub functions of the program
 *  String Password:
 *      The users password
 * ********************************************************************/
int main()
{
   // Variables
   string password;
   double c;

   // first prompt the user for their password
   password = promptPassword();

   // next check combinations
   c = checkCombinations(password);

   // Check the key
   checkKey(c);

   return 0;
}