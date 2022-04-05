//
// Created by Ming Yu on 2022/3/17.
//

#include <iostream>
#include <sys/fcntl.h>

using namespace std;

string nvm_file_path = "/Users/ymkzpx/cpp_practice/text.txt";


int main() {
    int open_flags = O_WRONLY | O_CREAT;
    int fd = open(nvm_file_path.c_str(), open_flags, 0666);
    if (fd == -1) {
        cout << "open file Error !" << endl;
    }
    cout << fd << endl;
    return 0;
}