/**
 * @file writingToaTextfile.cpp
 * 
 * Steps to Writing to a Text file
 * 
 * step 1; #onclude <fstream>
 * step 2; Declare an fstream or ofstream object
 * step 3; Connect it to a file on your system(opens it for writing)// by default c++ will create the file if it does not exist
 * step 4; Write data to the file via the stream
 * step 5; close the stream
 * 
 * fstream and ofstream are commonly used for output files
 * - Output files will be overwritten(truncated ) by default
 * they can be opened so that new writes append
 * can be open in text or binary modes
 * 
 * Opening a file for writing with fstream
 * std::fstream out_file {"../myfile.txt",std::ios::out};//param 1 - file, param two - binary
 * 
 * open for writing in binary mode
 * std::fstream out_file {"../myfile.txt",std::ios::out | std::ios::binary};param 2 - sets bot output and binary to true
 * fstream can be used to read and write into a file
 * 
 * ofstream is used for output files ony
 * std::ofstream out_file {"../myfile.txt",std::ios::out};  //std::ios::out optitional sinc already default
 * 
 * Different ways to open a file for writing with ofstream
 * - Truncate (discard content) when opening
 * std::ofstream out_File {"myfile.txt", std::ios::trunc};
 * 
 * - Append on each write (opens the outfile file but appends new writings to end of file)
 * std::ofstream out_file {"../myfile.txt",std::ios::app}; 
 * 
 * - seek to end of stream when opening
 * std::ofstream out_file {"../myfile.txt",std::ios::ate}; 
 * 
 * opening a file for writing with open
 * std::ofstream out_file;
 * std::string filename;
 * std::cin>>filename;
 * out_file.open(filename);
 * if(out_file.is_open()) //or if(out_file) checks the object
 * {}else{
 * }
 * out_file.close()
 * 
 * to write into a file the same concepts of reading into a file holds, only exception is extraction operator rather than insertion
 */

#include <iostream>
#include <fstream>
#include <string> 

int main(){
    using std::cout;
    using std::endl;
    using std::string;

    // //std::ofstream out_file{"output.txt"};//creates output.txt file.. note if txt file existed then information in the file is cleared(truncated)
    std::ofstream out_file{"output.txt",std::ios::app};//adds new line written to end of file rather than truncate
    if(!out_file){
        std::cerr<<"Error creating file"<<endl;
        return 1;
    }
    string line;
    cout<<"Enter something to write to the file: ";
    std::getline(std::cin,line);
    out_file<<line<<endl;
    out_file.close();



    //Reading from a file and writing to another file
    std::ifstream in_file {"poem.txt"};
    std::ofstream out_file {"poem_out.txt"};
    if(!in_file){
        std::cerr<<"Error openinng input file"<<endl;
        return 1;
    }
    if(!out_file){
        std::cerr<<"Error openinng output file"<<endl;
        return 1;
    }
    string line{};
    while(std::getline(in_file,line)){
        out_file<<line<<endl;
    }
    cout<<"File copied"<<endl;
    in_file.close();
    out_file.close();
    return 0;
}