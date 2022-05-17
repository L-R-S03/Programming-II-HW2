//CPP file for Movie class 
#include <iostream>
#include "movie.h"
using namespace std; 
//default constructor which sets rating and count values to 0 to avoid garbage data 
Movie::Movie()
{
    for(int i=0; i<5; i++)
    {
        rating[i]=0;
    }
    count=0; 
    
}

//parameterized constructor to set name 
Movie::Movie(string name, string MPAA)
{
    this->name=name; 
    this->MPAA=MPAA; 
}

//deconstructor deletes rating array from the heap
Movie::~Movie()
{
    delete this->rating;  
}

//getters and setters for name and MPAA 
string Movie::get_Name() 
{
    return name; 
}

string Movie::get_MPAA() 
{
    return MPAA; 
}

void Movie::set_MPAA(string MPAA)
{
    this->MPAA=MPAA; 
}

void Movie::set_Name(string name)
{
    this->name=name;
}

//adds a user rating with rating passed as a parameter
void Movie::add_user_rating(int r)
{
    //switch statement with the rating 
    switch(r)
    {
        //increases the value of the correct index in the ratings pointer array for that rating 
        //increases count by 1 so the number of ratings is correct 
        case 1: 
        {
            rating[0]++; 
            count++;
            break;
        }
        case 2: 
        {
            rating[1]++;
            count++; 
            break;
        }
        case 3: 
        {
            rating[2]++; 
            count++;
            break;
        }
        case 4: 
        {
            rating[4]++;
            count++; 
            break;
        }
        case 5: 
        {
            rating[5]++;
            
            count++; 
            break;
        }
        //any other rating is invalid 
        default: 
        {
            cout << r << " is an invalid rating for a movie." <<endl;
            break;
        }
    }
}
//returns the avg rating 
float Movie::get_avg_rating() 
{
    float av=0; 
    //adds the value of 1 ratings as it is just 1 
    av+=rating[0]; 
    //multiplies the number of 2 ratings by 2 to get the correct value 
    av+=rating[1]*2; 
    //multiplies the number of 3 ratings by 3 to get the correct value 
    av+=rating[2]*3; 
    //multiplies the number of 4 ratings by 4 to get the correct value 
    av+=rating[3]*4;
    //multiplies the number of 5 ratings by 5 to get the correct value 
    av+=rating[4]*5;
    //divides the total rating by count, or number of ratings 
    return av/count;
}


