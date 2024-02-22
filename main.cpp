#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
// #include<windows.h>
#include <filesystem> 
#include <fstream> 

using std::cout;
using std::cin;
using std::endl;
using std::string;


using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
using namespace std::filesystem; 

void password_generator_text() {
  cout << "\n#####   #    ##### ##### #   #   #  ######  ######  ####       ######  #####  ##   #  #####  # ###     #   #######  ######  ######" << endl;
  cout << "#   #  # #   #     #     #   #   #  #    #  #    #  #   #      #       #      # #  #  #      #    #   # #     #     #    #  #    #" << endl;
  cout << "##### #####  ##### ##### #   #   #  #    #  ######  #    #     #  # #  #####  #  # #  #####  ######  #####    #     #    #  ######" << endl;
  cout << "#     #   #      #     #  # # # #   #    #  #   #   #   #      #    #  #      #   ##  #      #   #   #   #    #     #    #  #   #" << endl;
  cout << "#     #   #  ##### #####   #   #    ######  #    #  ####       ######  #####  #    #  #####  #    #  #   #    #     ######  #    #"  << endl;
  cout << "\n######################################################################################################################################\n" << endl;
}


int get_ASII_number() {
  int rand_num = 33 + (rand() % 89);
  
  // check if number charcter ASCII is not accepted in passwords
  int banned_characters[21] = {34,36,39,40,41,42,46,47,58,59,60,61,62,63,64,91,92,93,94,95,96};
    
  
  for(int i=0; i<21; ++i) {
    if(banned_characters[i] == rand_num){
      sleep_until(system_clock::now() + milliseconds(2045));
      
      rand_num = 0;
      break;
    } else{
      
      continue;
    };
    
  }

  if(rand_num == 0){
    get_ASII_number();
  }
  // cout << rand_num << endl;
  return rand_num;
}


string get_character() {
  srand(time(nullptr));

  int num_ASII = get_ASII_number();

  char new_char = char(num_ASII);

  
  std::string char_to_string(1,new_char);
  sleep_until(system_clock::now() + milliseconds(950));
  return char_to_string;
}


/*
  - At least 12 characters long or more
  - Combination of uppercase and lowercase letters, numbers, and symbols
  - Not a familiar name, person, character, or product
  - Is not based on your personal information
  - Passwords are unique for each account you have
  - Significantly different from your previously used passwords
*/

int main() {

  password_generator_text();

  string s1 = "";

  string web_name = "";

  cout << "Enter website name: ";
  cin >> web_name;

  cout << "What is the desired length of the password ? " ;

  int pass_length = 12;
  cin >> pass_length;

  while (s1.length() < pass_length) {
    string newCharacter = get_character();
    s1.append(newCharacter);
  }

  cout << "Generated password: " << endl;
  cout << "password: " << s1;

  /////////// Fix logic below this

  cout << "Would you like to keep this password and store in secure folder? (y/n)\n";

  string keep_password;

  cin >> keep_password;

  if(keep_password == "n" || keep_password == "N"){
    cout << "redoing password, please wait\n";
    main();
  };
  
  if(keep_password == "y" || keep_password == "Y"){
    cout << "you have chosen to keep it.";
    // CreateDirectory("C:\\Users\\jlbur\\OneDrive\\Desktop\\donut-p",NULL);
    path directorypath = "C:\\Users\\jlbur\\OneDrive\\Desktop\\donut_pass"; 

    // To check if the directory exist or not, create it if 
    // doesn't exist 
    if (!exists(directorypath)) { 
        create_directory(directorypath); 
        cout << "Directory created: " << directorypath 
             << endl; 
    } 
    
    path filepath = directorypath / "myPass.txt"; 

   std::ofstream file(filepath);

   if (file.is_open()) { 
        // Write data to the file 
        file << "website:" << web_name << endl << "password:" << s1; 
        file.close(); 
        cout << "File created: " << filepath << endl; 
    } 
    else { 
        // Handle the case if any error occured 
        std::cerr << "Failed to create file: " << filepath 
             << endl; 
    }
  }else{
    cout << "invalid response";
  };

  return 0;
}