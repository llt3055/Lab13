// COMSC-210 | Lab  13| Tianyi Cao
#include <iostream>
#include <algorithm> // for std::sort
#include <numeric> // for std::accumulate
#include <array> // for std::array
#include <fstream> // for file I/O 
#include <vector>

using namespace std;

const int DAYS = 30;

int main() {
    //Declare an array to hold the temperatures for 10 days
    vector<double> temps;
    
    ifstream fin;
    fin.open("data.txt");

    if (fin.good()) {
        for (int i=0; i< DAYS; i++) {
            fin >> temps[i];
        }
        fin.close();

    }
    else {
       cout << "File not found." << endl; 
    }
    
    // size()
    cout << "1. Number of days recorded: " << temps.size() << endl;

    // front() and back()
    cout << "2. First day temp: " << temps.front() << endl;
    cout << "3. Last day temp: " << temps.back() << endl;
    // empty() and data()
    cout << "4. Array empty? " << (temps.empty() == 0 ? "False" : "True") << endl;
    cout << "5. Memory Address: " << temps.data() << endl;
    // sort() using iterators
    sort(temps.begin(), temps.end());
    cout << "6. Lowest temp of the month: " << temps.front() << endl;
    
    // max_element and min_element
    cout << "7. Max: " << *max_element(temps.begin(), temps.end()) << endl;
    cout << "8. Min: " << *min_element(temps.begin(), temps.end()) << endl;

    // accumulate for sum
    cout << "9. Sum: " << accumulate(temps.begin(), temps.end(), 0.0) << endl;
    double average = accumulate(temps.begin(), temps.end(), 0.0) / temps.size();

    // find an element
    double target = 75.0;   // search target
    vector<double>::iterator it;  // declare iterator to point to the found element
    it = find(temps.begin(), temps.end(), target);
    cout << "10. Value " << target;
    if (it != temps.end())
        cout << " found in position " << it - temps.begin() << endl;
    else
        cout << " was not found.\n";
    if (it != temps.end()) cout << "    Value: " << *it << endl;
     
    cout << "11. Element 2 : " << temps.at(2) << endl;
    cout << "12. Element 2 : " << temps[2] << endl;
    ofstream fout; 
    fout.open("Report.txt");
    fout << "Maximum" << '\t' << *max_element(temps.begin(), temps.end()) << '\n';
    fout << "Minimum" << '\t' << *min_element(temps.begin(), temps.end()) << '\n';
    fout << "Total Sum" << '\t' << accumulate(temps.begin(), temps.end(), 0.0) << '\n';
    fout.close( ); // close the file
    return 0;

}