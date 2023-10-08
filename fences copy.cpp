#include <iostream>
using namespace std;

char choose_polyg(float point);

    struct CoorName{
        float nameX;
        float nameY;
        char polyg;
    };
   
    struct paramFence{
        float beginX;
        float beginY;
        float endX;
        float endY;
    };
   
int main() {
   
    int i = 0,j = 0, num_points = 0;
    float P1[2],P2[2],P3[2],P4[2], H,D, max_y, limit = 1.6;
    CoorName Name[10000];
    float coorY;
    float coorX;
   
    paramFence fences[100000];
   
    cout << "Distance to fences: \n";
    cin >> limit;
    // cout << "Width of the rows: \n";
    // cin >> D;
    // cout <<  "Distance between the pylons in same line \n";
    // cin >> H;
    // cout << "Coordinate X of the firts point: \n";
    // cin >> P1[0];
    // cout << "Coordinate Y of the firts point: \n";
    // cin >> P1[1];
    // cout << "Coordinate X of the second point: \n";
    // cin >> P2[0];
    // cout << "Coordinate Y of the second point: \n";
    // cin >> P2[1];
    // cout << "Coordinate X of the third point: \n";
    // cin >> P3[0];
    // cout << "Coordinate Y of the third point: \n";
    // cin >> P3[1];
    // cout << "Coordinate X of the fourth point: \n";
    // cin >> P4[0];
    // cout << "Coordinate Y of the fourth point: \n";
    // cin >> P4[1];
   
   cout << limit << endl;
    D = 3.2;
    H = 10;
   
    // Polygon A
    P1[0] = 0;
    P1[1] = 0;
   
    P2[0] = 0;
    P2[1] = 148.95;
   
    P3[0] = 105.60;
    P3[1] = 148.68;
   
    P4[0] = 105.60;
    P4[1] = 0;
   
   
   
    // Polygon B
    // P1[0] = 108.8;
    // P1[1] = 0;
   
    // P2[0] = 108.8;
    // P2[1] = 148.57;
   
    // P3[0] = 316.8;
    // P3[1] = 135.72;
   
    // P4[0] = 316.8;
    // P4[1] = 0;
   
   
   
    // Polygon C
    // P1[0] = 323.2;
    // P1[1] = 0;
   
    // P2[0] = 323.2;
    // P2[1] = 135.21;
   
    // P3[0] = 441.6;
    // P3[1] = 125.4;
   
    // P4[0] = 441.6;
    // P4[1] = 0;
   
   
   
     
    // Polygon D
    // P1[0] = 444.8;
    // P1[1] = 0;
   
    // P2[0] = 444.8;
    // P2[1] = 124.07;
   
    // P3[0] = 592;
    // P3[1] = 59.21;
   
    // P4[0] =592;
    // P4[1] = 0;
   
   
   
   
    // Polygon E
    // P1[0] = 595.2;
    // P1[1] = 0;
   
    // P2[0] = 595.2;
    // P2[1] = 56.34;
   
    // P3[0] = 630.4;
    // P3[1] = 20;
   
    // P4[0] = 630.4;
    // P4[1] = 0;
   
   
   
    coorX = P1[0];
    coorY = P1[1];
   
    //  cout << "coorX:";
    //   cout <<  coorX;
    // cout << "\n P4:";
    //  cout << P4[0];
    //  cout << "\n";
   
   
    // slope calculation
    float m = (P3[1] - P2[1]) / (P3[0] - P2[0]);


    while(coorX < P4[0])
    {
        max_y = (m * (coorX - P2[0])) + P2[1];
        j = 0;
       
        while(coorY < max_y)
        {
            // cout <<"\n" << coorX ;  //<< "  " << coorY;
           
            Name[num_points].nameX = i;
            Name[num_points].nameY = j;
            Name[num_points].polyg = 'A'; 
            cout <<  coorX*100 << "\n"; 
            coorY += H;
            j++;
            num_points++;
        }
        if(coorY > max_y)
        {
            coorY = 0;
        }
       
         if(coorX + D*2 < P4[0]) // to avoid putting points after the final pylon
        {
            fences[i].beginX = coorX + D/2;
            fences[i].beginY = P1[1] - limit;
           
            fences[i].endX = coorX  + D/2;
            fences[i].endY = max_y + limit;
        }  
        //cout <<"\n" << fences[i].endX*100 ;  //<< "  " << coorY;
        coorX += D;
        i++;
    }
    cout << "\n\n";
    cout << "Amount of point: ";
    cout << num_points;
   
    // for(int i=0; i < num_points; i++)
    // {
    //      cout <<"\n" << Name[i].nameX;
    // }

    return 0;
}

// char choose_polyg(float point)
// {
//     float x = point;
//     char p;
   
//     if(x == 0)
//     {
//          p = 'A';
//     }else if(x == 108.88){
//         p = 'B';
//     }else if(x == 323.2){
//         p = 'C';
//     }else if(x == 444.8){
//         p = 'D';
//     }else if(x == 595.2){
//         p = 'E';
//     }
//     return p;
// }
