#include <iomanip>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    const int COLOR_SIZE = 20;
    char first_color[COLOR_SIZE];
    char second_color[COLOR_SIZE];
    
    cout<<"Enter first color(red, blue, or yellow): ";
    cin>>setw(COLOR_SIZE)>>first_color;
    cout<<"Enter second color(red, blue, or yellow): ";
    cin>>setw(COLOR_SIZE)>>second_color;
    
    if (strcmp(first_color, "red")==0 and strcmp(second_color, "red")==0)
{
    cout<<"Result: red (two of the same colors are not going to make a new color you dummy"<<endl;
}    
 if (strcmp(first_color, "blue")==0 and strcmp(second_color, "blue")==0)
{
    cout<<"Result: blue (two of the same colors are not going to make a new color you dummy"<<endl;
}  
 if (strcmp(first_color, "yellow")==0 and strcmp(second_color, "yellow")==0)
{
    cout<<"Result: yellow (two of the same colors are not going to make a new color you dummy"<<endl;
}  
 if ((strcmp(first_color, "red")==0 and strcmp(second_color, "blue")==0) or (strcmp(second_color, "red")==0 and strcmp(first_color, "blue")==0))
{
    cout<<"Result: Violet/Purple"<<endl;
} 
if ((strcmp(first_color, "red")==0 and strcmp(second_color, "yellow")==0) or (strcmp(second_color, "red")==0 and strcmp(first_color, "yellow")==0))
{
    cout<<"Result: Orange"<<endl;
} 
if ((strcmp(first_color, "yellow")==0 and strcmp(second_color, "blue")==0) or (strcmp(second_color, "yellow")==0 and strcmp(first_color, "blue")==0))
{
    cout<<"Result: Green"<<endl;
} 
else{
    cout<<"Error: Enter a COLOR (red, blue, or yellow): ";
}
    return 0;
}
