#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>

using namespace std;

// Program Execution is as follows
// ./a.out TOTALGAMES FILENAME
// This will append the output statistics to the end of the FILENAME specified.
// If no such file exists, it will be created.

void tell_past(char* FILENAME, 
               unsigned long long & BATCH, 
               unsigned long long & WINS, 
               unsigned long long & LOSSES, 
               unsigned long long & TURNS, 
               unsigned long long ROLLS[] );

int main(int argc, char* argv[])
{
   // Initialize the Random Number Seed
   srand((unsigned int)time(NULL));

   // Set Number of Batch to Play [to be brought from file]
   unsigned long long batch = 0;
   // Set Number of Games to Play [to be brought from command line]
   unsigned long long TOTALGAMES = atoi(argv[1]);
   // Set Filename to Read/Write Statistics From
   char* FILENAME = argv[2];
   // Set Win/Loss Counters [to be brought from file]
   unsigned long long wins = 0; unsigned long long losses = 0;
   // Set Game/Roll Counters
   unsigned long long turns = 0;
   unsigned long long rolls[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

   // Set Starting Turn Number
   unsigned int games = 1;
   // Set Starting Point / Roll values
   short point = 0; short roll = 0;

   // Set Input/Output File to Read Statistics From, and Open it
   ofstream outfile;
   outfile.open(FILENAME, ios::app);

   // Find out the past data
   tell_past(FILENAME, batch, wins, losses, turns, rolls);

   // Run Through the Specified Amount of Games
   while(games <= TOTALGAMES) {
     // Set the First Roll
     roll = short(double(rand())/RAND_MAX * 6 + 1) 
             + short(double(rand())/RAND_MAX * 6 + 1);
     turns++;
     rolls[roll-2]++;

      // Win on First Roll
      if(roll == 7 || roll == 11)
         wins++;
      // Lose on First Roll
      else if(roll == 2 || roll == 3 || roll == 12)
         losses++;
      // The Point was Set, Now Pursue It
      else {
         // Assign the Point value to the First Roll Value
         point = roll;

         // Roll Again, until the Roll is a 7 or the Point
         do {
            roll = short(double(rand())/RAND_MAX * 6 + 1) 
                    + short(double(rand())/RAND_MAX * 6 + 1);
            turns++;
            rolls[roll-2]++;
            if(roll == 7)
               losses++;
            else if(roll == point)
               wins++;
         } while(roll != 7 && roll != point);
      }
      games++;
   }

   batch++;

   // Wins / Losses / Total Turns / Roll Counts
   // Avg Turns / Total Games / Win % / Loss %
   cout << wins << " "
        << losses << " "
        << turns << " "
        << rolls[0] << " "
        << rolls[1] << " "
        << rolls[2] << " "
        << rolls[3] << " "
        << rolls[4] << " "
        << rolls[5] << " "
        << rolls[6] << " "
        << rolls[7] << " "
        << rolls[8] << " "
        << rolls[9] << " "
        << rolls[10] << " "
        << (float)turns / (wins+losses) << " "
        << wins+losses << " "
        << (float)wins / (wins+losses) << " "
        << (float)losses / (wins+losses) << " "
        << endl;

   // Sets / Wins / Losses / Total Turns / Roll Counts
   // Avg Turns / Total Games / Win % / Loss %
   outfile << batch << " "
        << wins << " "
        << losses << " "
        << turns << " "
        << rolls[0] << " "
        << rolls[1] << " "
        << rolls[2] << " "
        << rolls[3] << " "
        << rolls[4] << " "
        << rolls[5] << " "
        << rolls[6] << " "
        << rolls[7] << " "
        << rolls[8] << " "
        << rolls[9] << " "
        << rolls[10] << " "
        << (float)turns / (wins+losses) << " "
        << wins+losses << " "
        << (float)wins / (wins+losses) << " "
        << (float)losses / (wins+losses) << " "
        << endl;

   outfile.close();

   return 0;
}

// Reads in the Wins and Losses from the specified text file.
// The program then uses these to increment upon.
void tell_past(char* FILENAME, 
               unsigned long long & BATCH, 
               unsigned long long & WINS, 
               unsigned long long & LOSSES, 
               unsigned long long & TURNS, 
               unsigned long long ROLLS[] )
{
      ifstream infile;
      infile.open(FILENAME);

      while(!infile.eof())
      {
         infile >> BATCH >> WINS >> LOSSES >> TURNS
                >> ROLLS[0]
                >> ROLLS[1]
                >> ROLLS[2]
                >> ROLLS[3]
                >> ROLLS[4]
                >> ROLLS[5]
                >> ROLLS[6]
                >> ROLLS[7]
                >> ROLLS[8]
                >> ROLLS[9]
                >> ROLLS[10];
         infile.ignore(1000000,'\n');
      }

      infile.close();
      return;
}

