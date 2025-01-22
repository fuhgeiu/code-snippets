#include <fstream>
#include <iostream>
#include <cassert>
#include <sstream>

class login {

    std::fstream file;                                          // file stream object
    std::string filename;                                       // filename
    std::string buffer;

public:

    login(std::string Filename) : filename(Filename) {}         // direct initilizer

    void write (std::string message,std::string message2) {     // to write to file

        file.open(filename,std::ios::app);            // call .open on stream object, (filename,open mode)

        file << message << ',' << message2 << std::endl;        // stream message to file

        file.close();                                           // close file
    }

    void Clear () {                                             // to clear file

        file.open(filename,std::ios::out | std::ios::trunc);    // open a file, in truncation mode(deletes all)
    }

    void prompt (size_t version) {                                                 // easier to print by passign in version

        if (version == 0) {std::cout << "enter a login usernmae" << std::endl;}

        if (version == 1) {std::cout << "enter a new username" << std::endl;}

        if (version == 2) {std::cout << "enter password" << std::endl;}
    }

    bool check_username_exist (std::string tocheck) {        // to check username, pass in username to check

        std::string line;                                   // string to store line from file
        file.open(filename,std::ios::in);       // open in input mode(stream from file)

        while (getline(file,line)) {
            std::stringstream ss(line);              // string stream object, to stream line from file

            getline(ss,line,',');           // gets entire line from file, than stream into line string

            std::cout << line << std::endl;
            if (line.compare(tocheck) == 0) {file.close(); return true;}    // if it is same, than return true
        }
        file.close();
        return false;
    }

};


int main () {

    login file1("login.txt");

    file1.write("username","pasword");
    file1.write("username2", "passowrd2");

    assert(file1.check_username_exist("username") == true);
    assert(file1.check_username_exist("username2") == true);
    assert(file1.check_username_exist("password") == false);
    assert(file1.check_username_exist("thisisatest ") == false);
    assert(file1.check_username_exist("username 2 ") == false);

    file1.prompt(0);

    std::string user_input;
    size_t choice;

    std::cin >> user_input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

    file1.Clear();
}




//bool check_login (const std::string& tocheck, bool username_password) {
//
//    if (username_password == true) {
//
//        file.open(filename,std::ios::in);
//        while (!file.eof()) {
//
//            std::string temp;
//            getline(file,temp);
//            if (temp == tocheck) return true;
//        }
//        return false;
//    }
//
//    if (username_password == false) {
//
//        file.open(filename,std::ios::in);
//        while(!file.eof()) {
//
//            std::string temp;
//            getline(file,temp);
//            std::cout << temp;
//            if (temp == tocheck) return true;
//        }
//
//    }
//    else return false;
//}