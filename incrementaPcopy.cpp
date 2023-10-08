#include <iostream>
#include <cmath>
using namespace std;

struct points{
    float x;
    float y;
};

struct final{
    float x;
    float y;
};

struct input_data{
    float point_x;
    float point_y;
};

input_data Data[2]; // I have not put this variable inside the function Calculate_polygon because it gave me problems.

void calculate_polygon(float x, float D, float H, float &y, float &max_fence);
int last_pylon( float max, float H);
float lower(float p_l, float p_r);

int main() {
    
    points point[1000];
    final end[1000];

    int i,j, num_MP = 0, num_MK = 0, num_R = 0, num_ROW = 1;
    float H,D, max_y, stop, maxY_fence;
    float coorX, coorY;

    float fence_y = -160;  //start point in every road
    float final_x = 63040; //final x coordinate
    float R = 200; //first stop after beginning

    D = 320;  //Width of the rows
    H = 1000; //Distance between the pylons in same line
    stop = 500;

    coorX = D/2;  //We start in the middle of the first two lines of pylons

    i = 2;
    cout << "[\n";

    while(coorX < final_x)
    {
        calculate_polygon(coorX, D, H, max_y, maxY_fence); //choose the polygon A,B,C,D or E in depending on the eje X-axis
        //also returns the maximum Y-coordinate before the last pylon (maxY) and the Y-coordinate for the fence (maxY_fence)
       
        // for each line:
        while(point[i-1].y < max_y-R) // R -> safety distance for good photo results
        {
            if(i-2 == 0)
            {
                point[0].y = fence_y; //MP
                point[0].x = coorX;
                num_MP++;
                num_R = 0;
                //cout << point[0].y << "\n";
                cout << "{\n";
                cout << "\"Point Type\": \"MP\",\n";
                cout << "\"Point Num\": " << num_MP << ",\n";
                cout << "\"Row Num\": " << num_ROW << ",\n";
                cout << "\"Local X\": " << point[0].x <<",\n";
                cout << "\"Local Y\":" << point[0].y << ",\n";
                cout << "},\n";                
            }
            if(i-1 == 1)
            {
                point[1].y = R; //first stop after beginning
                point[1].x = coorX;
                num_R++;
                //cout << point[1].y << "\n";
                cout << "{\n";
                cout << "\"Point Type\": \"R\",\n";
                cout << "\"Point Num\": " << num_R << ",\n";
                cout << "\"Row Num\": " << num_ROW << ",\n";
                cout << "\"Local X\": " << point[1].x <<",\n";
                cout << "\"Local Y\":" << point[1].y << ",\n";
                cout << "},\n";  
            }
            point[i].y = point[i-1].y + stop;  //R
            point[i].x = coorX;
            num_R++;
            //cout << point[i].y << "\n";
            cout << "{\n";
            cout << "\"Point Type\": \"R\",\n";
            cout << "\"Point Num\": " << num_R << ",\n";
            cout << "\"Row Num\": " << num_ROW << ",\n";
            cout << "\"Local X\": " << point[i].x <<",\n";
            cout << "\"Local Y\":" << point[i].y << ",\n";
            cout << "},\n";  
            i++;
        }
        //The last dot of the road (line) is the coordinate of the fence (MK):
        point[i].y = maxY_fence; 
        point[i].x = coorX;
        coorX = coorX + D;
        num_MK++;
        //cout << point[i].y << "\n";
        cout << "{\n";
        cout << "\"Point Type\": \"MK\",\n";
        cout << "\"Point Num\": " << num_MK << ",\n";
        cout << "\"Row Num\": " << num_ROW << ",\n";
        cout << "\"Local X\": " << point[i].x <<",\n";
        cout << "\"Local Y\":" << point[i].y << ",\n";
        cout << "},\n";  
        i = 2;
        point[i-2].y = fence_y; // back to the beginning of the road (MP)
        num_ROW++;
    }

    cout << "]\n";
    //cout << "Num lines: " << num_ROW << "\n";

    return 0;
}

void calculate_polygon(float x, float D, float H, float &y, float &max_fence)
{
    //input_data Data[2];
    float P1[2],P2[2],P3[2],P4[2],m, m_fence, pylon_right, pylon_left;

    if( x >= -401 && x < 10715) // Polygon A
    {   
        P1[0] = 0;          P1[1] = 0;          //coordinates of the polygon
        P2[0] = 0;          P2[1] = 14895;       
        P3[0] = 10560;      P3[1] = 14868;      
        P4[0] = 10560;      P4[1] = 0;

        Data[1].point_x = -288;     Data[1].point_y = 15056; //coordinates of the fences
        Data[2].point_x = 10716;    Data[2].point_y = 15027;
    }
    else if(x >= 10715 && x < 31783) // Polygon B
    {
        P1[0] = 10880;      P1[1] = 0;
        P2[0] = 10880;      P2[1] = 14857;
        P3[0] = 31680;      P3[1] = 13572;
        P4[0] = 31680;      P4[1] = 0;

        Data[1].point_x = 10716;    Data[1].point_y = 15027;
        Data[2].point_x = 31783;    Data[2].point_y = 13726;
    }
    else if(x >= 31783 && x < 44221) // Polygon C
    {
        P1[0] = 32320;      P1[1] = 0;       
        P2[0] = 32320;      P2[1] = 13521;       
        P3[0] = 44160;      P3[1] = 12540;     
        P4[0] = 44160;      P4[1] = 0;

        Data[1].point_x = 31783;    Data[1].point_y = 13726;
        Data[2].point_x = 44221;    Data[2].point_y = 12696;     
    }else if(x >= 44221 && x < 59369) // Polygon D
    {
        P1[0] = 44480;      P1[1] = 0;    
        P2[0] = 44480;      P2[1] = 12407;     
        P3[0] = 59200;      P3[1] = 5921; 
        P4[0] = 59200;      P4[1] = 0;

        Data[1].point_x = 44221;    Data[1].point_y = 12696;
        Data[2].point_x = 59369;    Data[2].point_y = 6021;
    
    }else if(x >= 59369 && x < 64404) // Polygon E
    {
        P1[0] = 59520;      P1[1] = 0;
        P2[0] = 59520;      P2[1] = 5634;  
        P3[0] = 63040;      P3[1] = 2000; 
        P4[0] = 63040;      P4[1] = 0;

        Data[1].point_x = 59369;    Data[1].point_y = 6021;
        Data[2].point_x = 64404;    Data[2].point_y = 823; 
    }
    else{
        cout << "Error calculating polygon\n";
        exit(-1);
    }

    // slope calculation of maximum Y-coordinate for placing the pylons
    m = (P3[1] - P2[1]) / (P3[0] - P2[0]);
    // maximum Y-coordinate for placing the pylons
    pylon_left = (m * (x-D/2 - P2[0])) + P2[1]; 
    pylon_right = (m * (x+D/2 - P2[0])) + P2[1]; 

   // pylon_left = (last_pylon(pylon_left, H)-1)*H;  // last_pylon(pylon, H)*H  --> to know the height of the last pylon
   // pylon_right = (last_pylon(pylon_right, H)-1)*H;

    y = lower(pylon_left, pylon_right);

    // slope calculation of maximum Y-coordinate for placing the fences
    m_fence = (Data[2].point_y - Data[1].point_y) / (Data[2].point_x - Data[1].point_x);
    // slope calculation of maximum Y-coordinate for placing the fences
    max_fence = (m_fence * (x- Data[1].point_x)) + Data[1].point_y; 
    //max_fence = Data[2].point_y - (m_fence * (Data[2].point_x - x)); 

    //  cout << "\nSlope calculation: " << m_fence << "\n";
    //  cout << "max fence calculation: " << max_fence << "\n";
}

int last_pylon( float max, float H)
{
    return ceil(max/H);  //ceil() returns a value of type int (example: 19/10 returns 1)   **always round down
}    

float lower(float p_l, float p_r)
{
    if(p_l <= p_r)
        return p_l;
    else
        return p_r;
}
