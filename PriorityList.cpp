#include <bits/stdc++.h>
#include <fstream>

using namespace std;

void help()
{                                               // cmd -help
    cout << " Usage:-\n";
    cout << " ./task add 2 hello world    # Add a new item with priority 2 and text \"hello world\" to the list\n";
    cout << " ./task ls                   # Show incomplete priority list items sorted by priority in ascending order\n";
    cout << " ./task del INDEX            # Delete the incomplete item with the given index\n";
    cout << " ./task done INDEX           # Mark the incomplete item with the given index as complete\n";
    cout << " ./task help                 # Show usage\n";
    cout << " ./task report               # Statistics\n";
}

void printTasks()
{                                                 // cmd -ls
    ifstream read;
    read.open("task.txt");
    string s;
    int i = 1;
    while (getline(read, s))
    {
        stringstream ss(s);
        string word;
        ss >> word;
        string task = s.substr(word.length(), s.length() - word.length());

        cout << i << ". " << task << " [" << word << "] " << endl;
        i++;
    }

    read.close();
}

void add(string s)
{                                               // cmd -add
    ofstream file;
    file.open("task.txt", ios::app);
    file << s << endl;

    file.close();

    ifstream read;
    read.open("task.txt");
    vector<string> ar;

    while (getline(read, s))
    {
        ar.push_back(s);
    }
    read.close();

    sort(ar.begin(), ar.end(), [](string a, string b)
         {
             stringstream s1(a);
             stringstream s2(b);

             string word1, word2;
             s1 >> word1;
             s2 >> word2;

             int w1 = stoi(word1);
             int w2 = stoi(word2);

             if (w1 < w2)
                 return true;
             else if (w1 == w2)
                 return false;
             else
                 return false;
         });

    ofstream file2("task.txt");

    int size=ar.size();

    for (int i = 0; i <size; i++)
    {                                           // inserting tasks back again after sorting
        file2 << ar[i] << endl;
    }
}



void done_del(int i, int code)         // cmd -done i     // code-1 for done   // code-2 for delete
{
    ifstream file;
    file.open("task.txt");
    ofstream tempfile;                           // temporray file to store the content fo file
    tempfile.open("temp.txt", ios::app);
    string s;
    int cnt = 0;
    while (getline(file, s))
    {   cnt++;
        if(cnt!=i){
            tempfile<<s<<endl;
        }
        if (cnt == i and code==1)
        {                        // marking it complete
            ofstream complete;
            complete.open("CompletedTask.txt", ios::app); // writing into COMPLETED.TXT file
            complete << s << endl;
            complete.close();

        }
        else if(cnt==i and code==2) {
            continue;
        }
     
    }

    if (i > cnt )
    {
        cout<<"Error: item with index "<<i<<" does not exist. Nothing deleted."<<endl;
    }
    else {
        if(code==1){
            cout<<"Marked item as done."<<endl;
        }
        else{
            cout<<"Deleted task #"<<i<<endl;
        }
    }
    
    file.close();               // first close it and then remove it
    remove("task.txt");                          
    tempfile.close();                   // first close it and then rename it
    rename("temp.txt", "task.txt");                   
}




void report()
{   
    ifstream read;
    read.open("task.txt");
    string s;
    int lines=0;
    int i = 1;
    while(getline(read, s)){
        lines++;
    }

    read.close();
    ifstream read1;
    read1.open("task.txt");

    cout<<"Pending: "<<lines<<endl;

    while (getline(read1, s))
    {
        stringstream ss(s);
        string word;
        ss >> word;
        string task = s.substr(word.length(), s.length() - word.length());

        cout << i << ". " << task << " [" << word << "] " << endl;
        i++;
    }

    read1.close();

    cout<<endl;

    ifstream readcomp;
    readcomp.open("CompletedTask.txt");
    //string scomp;
    int linescomp=0;
    i=1;
    while(getline(readcomp, s)){
        linescomp++;
    }

    readcomp.close();
    ifstream readcomp1;
    readcomp1.open("CompletedTask.txt");

    cout<<"Completed: "<<linescomp<<endl;

    while (getline(readcomp1, s))
    {
        stringstream ss(s);
        string word;
        ss >> word;
        string task = s.substr(word.length(), s.length() - word.length());

        cout << i << ". " << task << endl; 
        i++;
    }

    readcomp1.close();

}




int main(int argc, char *argv[])
{
    if (argc == 1)
        help();
    else if (argc == 2)
    {
        string s1 = argv[1];
        if (s1 == "help")
            help();
        else if (s1 == "ls")
            printTasks();
        else if(s1=="report") 
            report();
    }

    else if(argc==3){
        string s1=argv[1];
        string s2=argv[2];

        if(s1=="del"){
            int i= stoi(s2);
            done_del(i, 2);
        }
        else if(s1=="done"){
            int i= stoi(s2);
            done_del(i, 1);
        }
    }

    else if (argc == 4)
    {
        string s1 = argv[1];
        string s2 = argv[2];
        string s3 = argv[3];

        if (s1 == "add")
        {
            string s = s2 + " " + s3;
            add(s);
            cout << "Added task: \"" << s3 << "\" with priority " << s2 << endl;
        }
    }




    return 0;
}
