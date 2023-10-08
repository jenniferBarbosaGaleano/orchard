#include <iostream>
using namespace std;

struct points{
    float x;
    float y;
};

struct input_data{
    float point_x;
    float point_y;
};

int main()
{
    points point[1000];
    input_data Data[100];

    Data[0].point_x = -401;
    Data[0].point_y = -160;
    Data[1].point_x = -288;
    Data[1].point_y = 15056;
    Data[2].point_x = 10716;
    Data[2].point_y = 15027;
    
    float D = 320, stop = 400, m, max;

    point[0].x = D/2;
    point[0].y = Data[0].point_y;  

    //cout << point[0].x << "\n";
    cout << point[0].y << "\n";

    //start POint
    point[1].x = D/2;
    point[1].y = 0;  

    //cout << point[1].x << "\n";
    cout << point[1].y << "\n";

    m = (Data[2].point_y - Data[1].point_y) / (Data[2].point_x - Data[1].point_x);
    //cout << " m es : "<< m << "\n";

    int i = 2;
    max = (m * (point[1].x- Data[i].point_x)) + Data[i].point_y;  
    //cout << " max es : "<< max << "\n";
    while(point[i-1].y < max)
    {
        point[i].y = point[i-1].y + stop;
        point[i].x = D/2;

        //cout << point[i].x << "\n";
        cout << point[i].y << "\n";
        i++;
    }
    //cout << "\n\n END \n\n";
    point[i+1].y = max; 
    point[i+1].x = D/2; 
    
    //cout << point[i+1].x << "\n";
    cout << point[i+1].y << "\n";

    point[i+2].x = point[i+1].x + D; 
    point[i+2].y  = (m * (point[i+2].x- Data[1].point_x)) + Data[1].point_y;

    //cout << point[i+2].x << "\n";
    cout << point[i+2].y << "\n";

    while(point[i+2].y > 0)
    {
        point[i+3].y =  point[i+2].y - stop;
        point[i+3].x = D/2 + D;
        
        //cout << point[i+3].x << "\n";
        cout << point[i+3].y << "\n";

        i++;
    }

    //end point
    point[i+4].y = 0;
    point[i+4].x = D/2 + D;

    //cout << point[i+4].x << "\n";
    cout << point[i+4].y << "\n";

    return 0;
}
