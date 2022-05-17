//Author: Lauren Smith 
//Project Programming II HW2 
//Date 2/7/21 
//Uses a movie.h, movie.cpp file and make file to make a pointer arrray of movies and collect data on them
#include <iostream>
#include "movie.h"
#include <ctime>
#include <iomanip>

using namespace std;
//function prototypes//////////////////////////////////////
//fills array of movie pointers, accepts array name and array size 
void instantiate(Movie **, const int); 
//third argument accepted is the number of user ratings you want to set. Fills movies with random rating values.  
void set_user_ratings(Movie **, const int, const int); 
//Displays the movie information with correct formatting 
void print_movie_info(Movie **,const int); 
//uses Movie deconstructors to clean the heap
void free_heap(Movie **, const int); 

int main()
{
    //declares a const int for the size of the movie array 
    const int SIZE=3;
    //Makes the double pointer array for an array of pointers with the size 
    Movie **Movies = new Movie*[SIZE];
    //runs the instantiate function to initialize Movie object variables 
    instantiate(Movies,SIZE); 
    //sets 5 random user ratings for each movie 
    set_user_ratings(Movies,SIZE,5);
    //displays the information for each movie 
    print_movie_info(Movies,SIZE);
    //clears the heap
    free_heap(Movies,SIZE);    
    return 0;
}

void free_heap(Movie ** m, const int SIZE)
{
    //displays that the deconstructor was called and for what address for each movie 
    //before calling the deconstructor for that movie object
    for(int i=0; i<3; i++)
    {
        cout << "~Movie() called: " << &m[i] <<endl; 
        m[i]->~Movie(); 
    }
}

void print_movie_info(Movie ** m, const int SIZE)
{
    //prints the line of 20 hyphens for a break in the terminal
    cout << string(20,'-') <<"Print Movie Info " << string(20,'-') <<endl;
    //loops for each Movie object in the array
    for(int i=0; i<3; i++)
    {
        //displays the name of the movie 
        cout << left << setw(15) << setfill(' ') << m[i]->get_Name(); 
        //adds needed spacing for formatting 
        cout << left << setw(8) << setfill(' ') << " ";
        //prints the MPAA rating 
        cout << right << setw(5) << setfill(' ') << m[i]->get_MPAA();
        //adds needed spacing for formatting 
        cout << setw(3) << setfill(' ') << " "; 
        //displays the avg rating using the Movie class get_avg_rating function 
        cout << left << setw(5) << setfill(' ') << fixed<< setprecision(2) << m[i]->get_avg_rating();
        //prints a newline for the next movie 
        cout << endl;  
    }  
    //prints a line of hyphens tosignify finished display 
    cout << string(56,'-')<<endl;
}

//r is used to specify the number of ratings to set 
void set_user_ratings(Movie ** m, const int SIZE, const int r)
{
    //top loop loops to set the correct number of ratings 
    for(int i=0; i<r; i++)
    { 
        //second loop loops through the array for each object 
        for(int j=0; j<3; j++)
        {
            //gives a random rating from one to 5
            int a=(int)(rand() % 5 +1);
            //adds the rating to the object using the movie add user rating function 
            m[j]->add_user_rating(a); 
        }
    }
    

}

void instantiate(Movie ** m, const int SIZE)
{
    //sets srand for randomonized values 
    srand(time(NULL));  
    //arrays for movie titles and MPAA ratings
    string rating [4]={"PG","R","PG-13","E"}; 
    string names [3]={"The Lorax", "Fight Club", "Iron Man"}; 
    int a=SIZE;
    //loops through for each movie object in the array
    for(int i=0; i<a; i++)
    {
        //creates a movie object using the default constructor 
        m[i]=new Movie(); 
        //displays that a movie object was created with the address 
        cout << "Movie() called: " << &m[i] <<endl; 
        //uses set_MPAA and set_Name functions with a randomonized index from respective arrays 
        m[i]->set_MPAA(rating[rand()%4]);
        m[i]->set_Name(names[rand()%3]);
        //displays output with desired formattng with setfill and setw
        cout << left<< setw(15) << setfill(' ') << m[i]->get_Name(); 
        cout << setw(8) << setfill(' ') << " ";
        cout << setw(5) << setfill(' ') << m[i]->get_MPAA();
        cout << setw(6) << setfill(' ') << " "; 
        cout << setw(5) << setfill(' ') << 0;
        cout << endl;  
    }
} 




