#include <iostream>
#include <stdlib.h>
using namespace std;

void Menu (char[]);

void Search (char[], char&, int&, int&, char&);
void Change (char[], char&, int&, int&, char&);
void DisplayFirst (char[], char&, int&, int&, char&);
void DisplayLast (char[], char&, int&, int&, char&);
void StringNull (char[], char&, int&, int&, char&);
void Induce (char[], int&, int&, int&, char&);

void Print (char[], char&, int&, int&, char&);
void Print2 (char[], int&, int&, int&, char&);

int main()
{
  char EnteredString[50];
  cout << "Please enter a string: \n";
  cin.getline(EnteredString, 50, '\n');
  
  Menu(EnteredString);
  
  return 0;
}

void Menu (char EnteredString[50])
{
  char LocalSearch, ChangeThisLetter;
  int LocalInduce1, LocalInduce2, LocalIncrement = 0;
  
  int LocalOption, Outbound;
  do {
    cout << "\n1. Search for a character within the string\n"
	 << "\n2. Change a character within the string\n"
	 << "\n3. Display the first x characters of the string\n"
	 << "\n4. Display the last x characters of the string\n"
	 << "\n5. Display all character that lie between two given induces\n"
	 << "\n6. Null the string\n"
	 << "\n7. Exit\n";

    cin >> LocalOption; cin.ignore();
    if (LocalOption == 1) {
      cout << "What character do you want to search for: \n";
      cin.get(LocalSearch); cin.ignore();
      Outbound = LocalOption;

      Print(EnteredString, LocalSearch, LocalIncrement, Outbound, ChangeThisLetter);
    }
    
    else if (LocalOption == 2) {
      cout << "What letter do you want to change?: \n";
      cin.get(LocalSearch); cin.ignore();

      cout << "Which letter do you want to replace it with?: \n";
      cin.get(ChangeThisLetter); cin.ignore();
      Outbound = LocalOption;

      Print(EnteredString, LocalSearch, LocalIncrement, Outbound, ChangeThisLetter);
    }

    else if (LocalOption == 3) {
      cout << "From which position of the character would you want to display from?: \n";
      cin >> LocalInduce1; 
      Outbound = LocalOption;

      Print(EnteredString, LocalSearch, LocalInduce1, Outbound, ChangeThisLetter);
    }

    else if (LocalOption == 4) {
      cout << "From which of the last character do you want to display?: \n";
      cin >> LocalInduce1; 
      Outbound = LocalOption;

      Print(EnteredString, LocalSearch, LocalInduce1, Outbound, ChangeThisLetter);
    }

    else if (LocalOption == 5) {
      cout << "Print the first index: \n";
      cin >> LocalInduce1;

      cout << "Print the second index: \n";
      cin >> LocalInduce2;
      Outbound = LocalOption;

      Print2(EnteredString, LocalInduce1, LocalInduce2, Outbound, ChangeThisLetter);
    }

    else if (LocalOption == 6) {
      Outbound = LocalOption;

      Print(EnteredString, LocalSearch, LocalInduce1, Outbound, ChangeThisLetter);
    }

    else if (LocalOption == 7) {
      exit(1);
    }
  }while (LocalOption < 0 || LocalOption > 8);
}

void Search (char EnteredString[50], char& SearchLetter, int& Instances, int& Outbound, char& ChangeThisLetter)
{
  for (int i = 0; i <= 50; ++i)
    {
      if(EnteredString[i] == SearchLetter)
	{
	  Instances++;
	}
    }
}

void Change (char EnteredString[50], char& SearchLetter, int& Instances, int& Outbound, char& ChangeThisLetter)
{
  for (int Increment = 0; Increment <= 50; ++Increment)
    {
      if(EnteredString[Increment] == SearchLetter)
	{
	  EnteredString[Increment] = ChangeThisLetter;
	}
    }
}

void Induce (char EnteredString[50], int& LocalInduce1, int& LocalInduce2, int& Outbound, char& ChangeThisLetter)
{
  int i = 0;
  for (; EnteredString[i] != '\0'; ++i);

  for (int j = 0; j <= LocalInduce1 - 1; ++j)
    EnteredString[j] = ' ';
  
  for (int k = i - LocalInduce2; k <= i; ++k)
    EnteredString[k] = '\0';

  /* Trying to resize the array and shift the old ones into the new array */
  int m = 0;
  for (; EnteredString[m] == ' '; ++m);
  char rsz_a[i - m]; int p = 0; /* Variables for array shifting */
  for (; p <= i; ++p && ++m)
    {
      rsz_a[p] = EnteredString[m];
      EnteredString[p] = rsz_a[p];
    } 
}

void DisplayLast (char EnteredString[50], char& SearchLetter, int& Instances, int& Outbound, char& ChangeThisLetter)
{
  int countback = 0;
  for (int i = countback; i <= 50; ++i)
    {
      if(EnteredString[i] == '\0')
	{
	  countback = i;
	  break;
	}
    }

  char name[Instances];
  for (int i = 0; i <= Instances; ++i)
    {
      name[i] = EnteredString[countback - Instances + i];
      EnteredString[i] = name[i];
    }
}
	
void DisplayFirst (char EnteredString[50], char& SearchLetter, int& Instances, int& Outbound, char& ChangeThisLetter)
{
  EnteredString[Instances] = '\0';
}

void StringNull (char EnteredString[50], char& SearchLetter, int& Instances, int& Outbound, char& ChangeThisLetter)
{
  EnteredString[0] = '\0';
}

void Print (char EnteredString[50], char& SearchLetter, int& Instances, int& Outbound, char& ChangeThisLetter)
{
  if (Outbound == 1) {
    Search(EnteredString, SearchLetter, Instances, Outbound, ChangeThisLetter);
    
    cout << "\nThere were " << Instances << " instances of the letter " << SearchLetter << endl;
  }

  else if (Outbound  == 2) {
    Change(EnteredString, SearchLetter, Instances, Outbound, ChangeThisLetter);
    
    cout << EnteredString << endl;
  }
  
  else if (Outbound == 3) {
    DisplayFirst(EnteredString, SearchLetter, Instances, Outbound, ChangeThisLetter);
    
    cout << EnteredString << endl;
  }
  
  else if (Outbound == 4) {
    DisplayLast(EnteredString, SearchLetter, Instances, Outbound, ChangeThisLetter);
    
    cout << EnteredString << endl;
  }

  else if (Outbound == 6) {
    StringNull(EnteredString, SearchLetter, Instances, Outbound, ChangeThisLetter);
    
    cout << EnteredString << endl;
  }
}

void Print2 (char EnteredString[50], int& LocalInduce1, int& LocalInduce2, int& Outbound, char& ChangeThisLetter)
{
  Induce(EnteredString, LocalInduce1, LocalInduce2, Outbound, ChangeThisLetter);
  
  cout << EnteredString << endl;
}
