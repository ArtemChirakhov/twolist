#include <iostream>
#include "realization.h"
#include <string>
using namespace std;
 
int main() {
    List<int> l;
    string inp;
    int n;
    cout << "available commands:" << endl << "stop" << endl << "next" << endl << "prev" << endl << "push_front" << endl << "push_ back" << endl << "pop_back" << endl << "pop_back" << endl << "erase" << endl << "empty" << endl << "pointerValue" << endl << "pointerPosition" << endl << "cout" << endl << "///////////////////////////////////////////" << endl;
    while(true){
        n = 0;
        cin >> inp;
        if(inp == "stop"){
            break;
        }
        else if(inp == "next"){
            l.next();
            cout << "moved cursor forward" << endl;
        }
        else if(inp == "prev"){
            l.prev();
            cout << "moved cursor backward" << endl;
        }
        else if(inp == "push_front"){
            cout << "enter number" << endl;
            cin >> n;
            l.push_front(n);
        }
        else if(inp == "push_back"){
            cout << "enter number" << endl;
            cin >> n;
            l.push_back(n);
        }
        else if(inp == "insert"){
            cout << "enter number" << endl;
            cin >> n;
            l.insert(n);
        }
        else if(inp == "pop_back"){
            l.pop_back();
        }
        else if(inp == "pop_front"){
            l.pop_front();
        }
        else if(inp == "erase"){
            l.erase();
        }
        else if(inp == "empty"){
            if(l.empty()){
                cout << "NO" << endl;
            }
            else{
                cout << "YES" << endl;
            }
        }
        else if(inp == "pointerValue"){
            cout << l.pointerValue() << endl;
     
        }
        else if(inp == "pointerPosition"){
            cout << l.pointerPosition() << endl;
        }
        else if(inp == "cout"){
            cout << l << endl;
        }
        else{
            cout << "unknown command";
        }
    }
}
