#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

using namespace std;

#define N 20

///Task 1 

// search for a word in the input file, return true if found
bool lookup(const char filename[], const char word[]){
	ifstream infile;
	infile.open(filename);
	bool valid = false;
	if(!infile)
	{cerr<<"Error: Cannot Open File"<<endl;return -1;}
	char line[N];
	while(!infile.eof()){
		infile.getline(line,N,'\n');
		if(strcmp(word,line)==0)
		{
			valid = true;
			break;
		}
	}
	infile.close();
	return valid;
}
	

///Task 2

// delete a word in the input file
// the result should not contain blank lines
void delete_word(const char filename[], const char word[])
{
    if (lookup(filename, word))
    {

        fstream myFile(filename); //open the file

        if (!myFile.is_open())
        { //check if the file stream is currently accessing a file
            cerr << "An error occurred when opening the file " << endl;
        }

        //get the size of the file
        myFile.seekg(0, myFile.end);
        int size = myFile.tellg(); //the position indicator at the end of the file
        myFile.seekg(0);           //set back the position to 0

        char allWords[size][21]; //store all the word, the size is equal to the size of the file

        for (int row = 0; !myFile.eof(); row++)
        { //run until EOF is reached
            myFile >> allWords[row];
        }

        myFile.close();
        myFile.open(filename, ios::in | ios::out | ios::trunc); //open the file again

        for (int i = 0; allWords[i][0] != '\0'; i++)
        {
            if (strcmp(allWords[i], word) != 0)
                myFile << allWords[i];

            if (allWords[i + 1][0] != '\0' && strcmp(allWords[i], word) != 0)
                myFile << '\n';
        }
        myFile.close();
                cout<<"The word \""<<word<<"\"  is deleted successfully!"<<endl;
    }
    else
    {
        cout<<"The word \""<<word<<"\" is not in the file!"<<endl;
    }
    
}

void ascending(const char filename[], const char word[])
{
    ifstream in(filename);
	
    if(!in.is_open())
        cout << "Unable to open file\n";

    string words;
	vector<string> names;
    while(getline(in, words))
            names.push_back(words);

    sort(names.begin(), names.end());
	in.close();

	ofstream out(filename);
	if(!out){cerr<<"Error: "<<endl;}
	for (size_t i = 0; i < names.size(); i++)
        out << names[i] << '\n';

	out.close();

	return;

}

/// Task 3

// insert a word in the input file such that the words are in ascending order
// it should not insert duplicate word
void insert_word(const char filename[], const char word[]){

	ofstream outfile;
	outfile.open(filename, fstream::app);

	if(!outfile){cerr<<"Error";}

	ifstream infile;
	infile.open(filename);


	if(!lookup(filename,word)){
		outfile<<word<<endl;
		cout<<"The word \""<<word<<"\"  is inserted successfully!"<<endl;
	}

	else
	{
		cout<<"The word \""<<word<<"\" already exists!"<<endl;
	}
	

	infile.close();
	outfile.close();
	ascending(filename,word);

	return;

}


int main(){

	const char filename[] = "words.txt";
	char choice; 
	char word[N];

	while (true){
		cout << "1 for lookup; 2 for insertion; 3 for deletion; q for quit: ";
		cin >> choice;

		if (choice == '1'){
			cout << "Please enter the word you want to search for: ";
			cin >> word;
			if (lookup(filename, word)){
				cout << "The word \"" << word << "\" is found!" << endl;
			}else{
				cout << "The word \"" << word << "\" is not found!" << endl;
			}
		}else if (choice == '2'){
			cout << "Please enter the word you want to insert: ";
			cin >> word;
			insert_word(filename, word);
		}else if (choice == '3'){
			cout << "Please enter the word you want to delete: ";
			cin >> word;
			delete_word(filename, word);
		}else if (choice == 'q'){
			break;
		}else{
			cout << "Invalid input. Please input again." << endl;
		}
		cout << endl;
	}

	ascending(filename,word);
	return 0;
}

