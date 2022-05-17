//header file for Movie class 
#include <string>
using namespace std; 
class Movie
{
    private:
        string name; 
        string MPAA; 
        int* rating=new int[5]; 
        int count; 
    public:
        Movie(); 
        Movie(string, string); 
        ~Movie(); 
        string get_Name(); 
        void set_Name(string); 
        void set_MPAA(string);  
        string get_MPAA();
        void add_user_rating(int); 
        float get_avg_rating();   
};