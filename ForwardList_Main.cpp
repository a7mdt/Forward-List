#include "bits/stdc++.h"
using namespace std;

bool removeifFunction(int i)
{
    return i%2 ;
}

int main()
{
    // Forward List : It takes less Storage than the regular List.
    // It has push_front() but doesn't have push_back()

    // 1) ASSIGN :
    forward_list<int>fl={1,2,3,4,5,6,7,8,9,10};
    cout<<"My fl before any assign : ";
    for(int &i : fl)
        cout<<i<<" "; // 1,2,3,4,5,6,7,8,9,10
    cout<<endl;
    fl.assign(5,10);
    cout<<"My fl after first assign : ";
    for(int &i : fl)
        cout<<i<<" "; // 10,10,10,10,10
    cout<<endl;
    fl.assign({10,20,30,40,50,60,70,80,90,100});
    cout<<"My fl after second assign : "; // 10,20,30,40,50,60,70,80,90,100
    for(int &i : fl)
        cout<<i<<" ";
    cout<<endl;
    cout<<"------------------------------------------\n";

    forward_list<char>fl1 = {'A','H','M','E','D'};
    fl1.push_front('i'); // iAHMED
    fl1.pop_front(); // AHMED
    fl1.emplace_front('i'); // iAHMED
    fl1.insert_after(fl1.begin(),'m'); // imAHMED
    fl1.insert_after(fl1.before_begin(),'i'); // iimAHMED

    forward_list<int>fl2 = {1,2,3,4,5,6,7,8,9,10};
    auto f2 = fl2.begin();
    cout<<"fl2.begin() : "<<*f2<<endl; // 1
    f2 = next(fl2.begin());
    cout<<"next(fl2.begin()) : "<<*f2<<endl; // 2
    f2 = next(fl2.begin(),2); // Go 2 steps after the begging point ==> 3
    cout<<"next(fl2.begin(),2) : "<<*f2<<endl; // 3
    cout<<"fl2 before the function erase_after(fl2.begin()) : ";
    for(auto &f : fl2)
        cout<<f<<" "; // 1,2,3,4,5,6,7,8,9,10
    cout<<endl;
    fl2.erase_after(fl2.begin());
    cout<<"fl2 after the function erase_after(fl2.begin()) : ";
    for(auto &f : fl2)
        cout<<f<<" "; // 1,3,4,5,6,7,8,9,10
    cout<<endl;
    fl2.erase_after(fl2.before_begin());
    cout<<"fl2 after the function erase_after(fl2.before_begin()) : ";
    for(auto &f : fl2)
        cout<<f<<" "; // 3,4,5,6,7,8,9,10
    cout<<endl;
    cout<<"-------------------\n";
    // What if u want to remove item in the middle ? ==> Make iterator and make it = the begin() and use the next func
    forward_list<int>fl3 = {1,2,3,4,5};
    cout<<"fl3 before deleting 4 : ";
    for(auto f : fl3)
        cout<<f<<" ";
    cout<<endl;
    auto itF = fl3.begin(); // 1
    itF = next(itF,2); // This will go from (1) to (3)
    fl3.erase_after(itF); // I say delete the item after the 3
    cout<<"fl3 after deleting 4 : ";
    for(auto f : fl3)
        cout<<f<<" ";
    cout<<endl;
    cout<<"-------------------\n";
    forward_list<int>fl4 = {1,1,2,1,3,4,1,5};
    cout<<"fl4 before using the remove function : ";
    for(auto f : fl4)
        cout<<f<<" ";
    cout<<endl;
    fl4.remove(1); // remove each 1 in the fl4
    cout<<"fl4 after using the remove function : ";
    for(auto f : fl4)
        cout<<f<<" ";
    cout<<endl;
    cout<<"-------------------\n";
    forward_list<int>fl5 = {1,2,3,4,5,6,7,8,9,10,11};
    cout<<"fl5 before using the remove_if function : ";
    for(auto f : fl5)
        cout<<f<<" ";
    cout<<endl;
    fl5.remove_if(removeifFunction); // remove if the condition is true
    cout<<"fl5 after using the remove_if function : ";
    for(auto f : fl5)
        cout<<f<<" ";
    cout<<endl;
    cout<<"-------------------\n";
    forward_list<int>fl6 = {1,2,3,4,5};
    forward_list<int>fl7 = {-5,-4,-3,-2,-1};
    cout<<"fl6 before the fl6.splice_after() : ";
    for(int f : fl6)
        cout<<f<<" "; // 1 2 3 4 5
    cout<<endl;
    cout<<"fl7 before the fl6.splice_after() : ";
    for(int f : fl7)
        cout<<f<<" "; // -5 -4 -3 -2 -1
    cout<<endl;
    fl6.splice_after(fl6.before_begin(),fl7);
    cout<<"fl6 after the fl6.splice_after(fl6.before_begin(),fl7) : ";
    for(int f : fl6)
        cout<<f<<" "; // -5 -4 -3 -2 -1 1 2 3 4 5
    cout<<endl;
    cout<<"fl7 after the fl7.splice_after(fl6.before_begin(),fl7) : ";
    for(int f : fl7)
        cout<<f<<" "; // EMPTY.
    cout<<endl;
    //---
    fl6 = {1,2,3,4,5};
    fl7 = {-5,-4,-3,-2,-1};
    //---
    fl6.splice_after(fl6.before_begin(),fl7,fl7.begin(),fl7.end()); // splice after the fl7.begin()=>-4
    cout<<"fl6 after the fl6.splice_after(fl6.before_begin(),fl7,fl7.begin(),fl7.end()) : ";
    for(int f : fl6)
        cout<<f<<" "; // -4 -3 -2 -1 1 2 3 4 5
    cout<<endl;
    cout<<"fl7 after the fl6.splice_after(fl6.before_begin(),fl7,fl7.begin(),fl7.end()) : ";
    for(int f : fl7)
        cout<<f<<" "; // -5
    cout<<endl;

    // VIP NOTE : THERE ARE resize() , empty() , merge() , sort() , reverse() , unique() , swap() LIKE THE LIST.

    return 0;
}
