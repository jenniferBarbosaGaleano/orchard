#include <iostream>
using namespace std;

    struct CoorName{
        float nameX;
        float nameY;
    };

void calculate_polygon(float x,float &y);

int main() {
   
    int i = 0,j = 0, num_points = 1;
    float P1[2],P2[2],P3[2],P4[2], H,D, max_y, limit = 1.6;
    CoorName Name[100000];
    float final_x = 63040;
    float coorX, coorY;

    #if 0
    cout << "Distance to fences: \n";
    cin >> limit;
    cout << "Width of the rows: \n";
    cin >> D;
    cout <<  "Distance between the pylons in same line \n";
    cin >> H;
    cout << "Coordinate X of the firts point: \n";
    cin >> P1[0];
    cout << "Coordinate Y of the firts point: \n";
    cin >> P1[1];
    cout << "Coordinate X of the second point: \n";
    cin >> P2[0];
    cout << "Coordinate Y of the second point: \n";
    cin >> P2[1];
    cout << "Coordinate X of the third point: \n";
    cin >> P3[0];
    cout << "Coordinate Y of the third point: \n";
    cin >> P3[1];
    cout << "Coordinate X of the fourth point: \n";
    cin >> P4[0];
    cout << "Coordinate Y of the fourth point: \n";
    cin >> P4[1];
   #endif
   
    D = 320;
    H = 1000;

    coorX = 0;
    coorY = 0;

    cout << "\n[\n";

    while(coorX < final_x)
    {
        calculate_polygon(coorX,max_y);
        j = 0;
       
        while(coorY <= max_y)
        {          
            Name[num_points].nameX = i;
            Name[num_points].nameY = j;

            cout << "{\n";
            cout << "\"Point Type\": \"VS\", \n";
            cout << "\"Point Num\": " << j+1 <<",\n";
            cout << "\"Line Num\": " << i+1<< ",\n";
            cout << "\"Local X\": " << coorX <<",\n";
            cout <<  "\"Local Y\":" << coorY << ",\n";
            cout << "},\n";
           // cout <<  coorY << "\n"; 
            coorY += H;
            j++;
            num_points++;
        }
        if(coorY > max_y)
        {
            coorY = 0;
        }
       
        coorX += D;
        i++;
    }
    cout << "]\n";
    cout << "\n\n";
    cout << "Amount of point: ";
    cout << num_points;

    return 0;
}

void calculate_polygon(float x,float &y)
{
    //input_data Data[2];
    float P1[2],P2[2],P3[2],P4[2],m;

    if( x >= -401 && x < 10715) // Polygon A
    {   
        P1[0] = 0;          P1[1] = 0;          //coordinates of the polygon
        P2[0] = 0;          P2[1] = 14895;       
        P3[0] = 10560;      P3[1] = 14868;      
        P4[0] = 10560;      P4[1] = 0;
    }
    else if(x >= 10715 && x < 31783) // Polygon B
    {
        P1[0] = 10880;      P1[1] = 0;
        P2[0] = 10880;      P2[1] = 14857;
        P3[0] = 31680;      P3[1] = 13572;
        P4[0] = 31680;      P4[1] = 0;
    }
    else if(x >= 31783 && x < 44221) // Polygon C
    {
        P1[0] = 32320;      P1[1] = 0;       
        P2[0] = 32320;      P2[1] = 13521;       
        P3[0] = 44160;      P3[1] = 12540;     
        P4[0] = 44160;      P4[1] = 0;
   
    }else if(x >= 44221 && x < 59369) // Polygon D
    {
        P1[0] = 44480;      P1[1] = 0;    
        P2[0] = 44480;      P2[1] = 12407;     
        P3[0] = 59200;      P3[1] = 5921; 
        P4[0] = 59200;      P4[1] = 0;
    
    }else if(x >= 59369 && x < 64404) // Polygon E
    {
        P1[0] = 59520;      P1[1] = 0;
        P2[0] = 59520;      P2[1] = 5634;  
        P3[0] = 63040;      P3[1] = 2000; 
        P4[0] = 63040;      P4[1] = 0;
    }
    else{
        cout << "Error calculating polygon\n";
        exit(-1);
    }

    // slope calculation of maximum Y-coordinate for placing the pylon
    m = (P3[1] - P2[1]) / (P3[0] - P2[0]);
    y = (m * (x - P2[0])) + P2[1]; 
}