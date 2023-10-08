#include <iostream>
#include <cmath>
#include <fstream> // Incluir la biblioteca de manejo de paths
#define MAX 10000
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

struct Datas{
    int IR;
    int IR_point_num;
    char type[2];
    int num;
    int ROW_num;
    float x;
    float y;
    int up;
    char c; 
};

void calculate_polygon(int option, float x, float D, float H, float &y, float &max_fence);
float lower(float p_l, float p_r);
void print(ofstream& path, Datas data[MAX],int j);

float P1_A[2],P2_A[2],P3_A[2],P4_A[2];
float P1_B[2],P2_B[2],P3_B[2],P4_B[2];
float P1_C[2],P2_C[2],P3_C[2],P4_C[2];
float P1_D[2],P2_D[2],P3_D[2],P4_D[2];
float P1_E[2],P2_E[2],P3_E[2],P4_E[2];

input_data Data_1, Data_2, Data_3, Data_4, Data_5, Data_6, Data_7, Data_8; 

int main() {
    
    ofstream path("path.txt");
    ofstream path_del("path_delete_points.txt");
    ofstream path_add("path_add_points.txt");
    ofstream pylons("pylons.txt");
    ofstream start_end("start_end.txt");

    points point[1000];
    final end[1000];
    Datas data[MAX];
    int i,j = 0, up = 1, j_1 = 0, i_1 = 0;
    int num_lines = 1, IR = 0, n = 0, IR_point_num = 0, num_MP = 0, ROW_num = 1, num_R =0, num_MK = 0;
    float H,D, max_y, stop;
    float coorX, coorY;
    char type[2];

    float fence_y = -160;
    float final_x = 63040;
    float R = 200; //first stop after beginning
    float maxY_fence = 160; //distance between the fence and the pylons
    D = 320;
    H = 1000;
    stop = 500;

    coorX = D/2;
    i = 2;

    char manually = 'p';
    int option = 0;
   cout << "Enter the data manually?   y/n\n";
   cin >> manually;
    if(manually == 'y' || manually == 'Y')
    {
        option = 1;
    } 
    if(option == 1){ 
        cout << "Width of the rows: \n";
        cin >> D;
        cout <<  "Distance between the pylons in same line \n";
        cin >> H;
        cout << "X-Coordinate of the first point of Polygon A: \n";
        cin >> P1_A[0];
        cout << "Y-Coordinate of the first point of Polygon A: \n";
        cin >> P1_A[1];
        cout << "X-Coordinate of the second point of Polygon A: \n";
        cin >> P2_A[0];
        cout << "Y-Coordinate of the second point of Polygon A: \n";
        cin >> P2_A[1];
        cout << "X-Coordinate of the third point of Polygon A: \n";
        cin >> P3_A[0];
        cout << "Y-Coordinate of the third point of Polygon A: \n";
        cin >> P3_A[1];
        cout << "X-Coordinate of the fourth point of Polygon A: \n";
        cin >> P4_A[0];
        cout << "Y-Coordinate of the fourth point of Polygon A: \n";
        cin >> P4_A[1];
        cout << "X-Coordinate of the first point of Polygon B: \n";
        cin >> P1_B[0];
        cout << "Y-Coordinate of the first point of Polygon B: \n";
        cin >> P1_B[1];
        cout << "X-Coordinate of the second point of Polygon B: \n";
        cin >> P2_B[0];
        cout << "Y-Coordinate of the second point of Polygon B: \n";
        cin >> P2_B[1];
        cout << "X-Coordinate of the third point of Polygon B: \n";
        cin >> P3_B[0];
        cout << "Y-Coordinate of the third point of Polygon B: \n";
        cin >> P3_B[1];
        cout << "X-Coordinate of the fourth point of Polygon B: \n";
        cin >> P4_B[0];
        cout << "Y-Coordinate of the fourth point of Polygon B: \n";
        cin >> P4_B[1];

        cout << "X-Coordinate of the first point of Polygon C: \n";
        cin >> P1_C[0];
        cout << "Y-Coordinate of the first point of Polygon C: \n";
        cin >> P1_C[1];
        cout << "X-Coordinate of the second point of Polygon C: \n";
        cin >> P2_C[0];
        cout << "Y-Coordinate of the second point of Polygon C: \n";
        cin >> P2_C[1];
        cout << "X-Coordinate of the third point of Polygon C: \n";
        cin >> P3_C[0];
        cout << "Y-Coordinate of the third point of Polygon C: \n";
        cin >> P3_C[1];
        cout << "X-Coordinate of the fourth point of Polygon C: \n";
        cin >> P4_C[0];
        cout << "Y-Coordinate of the fourth point of Polygon C: \n";
        cin >> P4_C[1];

        cout << "X-Coordinate of the firts point of Polygon D: \n";
        cin >> P1_D[0];
        cout << "Y-Coordinate of the first point of Polygon D: \n";
        cin >> P1_D[1];
        cout << "X-Coordinate of the second point of Polygon D: \n";
        cin >> P2_D[0];
        cout << "Y-Coordinate of the second point of Polygon D: \n";
        cin >> P2_D[1];
        cout << "X-Coordinate of the third point of Polygon D: \n";
        cin >> P3_D[0];
        cout << "Y-Coordinate of the third point of Polygon D: \n";
        cin >> P3_D[1];
        cout << "X-Coordinate of the fourth point of Polygon D: \n";
        cin >> P4_D[0];
        cout << "Y-Coordinate of the fourth point of Polygon D: \n";
        cin >> P4_D[1];

        cout << "X-Coordinate of the first point of Polygon E: \n";
        cin >> P1_E[0];
        cout << "Y-Coordinate of the first point of Polygon E: \n";
        cin >> P1_E[1];
        cout << "X-Coordinate of the second point of Polygon E: \n";
        cin >> P2_E[0];
        cout << "Y-Coordinate of the second point of Polygon E: \n";
        cin >> P2_E[1];
        cout << "X-Coordinate of the third point of Polygon E: \n";
        cin >> P3_E[0];
        cout << "Y-Coordinate of the third point of Polygon E: \n";
        cin >> P3_E[1];
        cout << "X-Coordinate of the fourth point of Polygon E: \n";
        cin >> P4_E[0];
        cout << "Y-Coordinate of the fourth point of Polygon E: \n";
        cin >> P4_E[1];

        cout << "Now Intrduce the X-coordinates of frist point of the fence: \n";
        cin >> Data_1.point_x;
        cout << "Y-Coordinate of the firts point of the fence: \n";
        cin >> Data_1.point_y;
        cout << "Intrduce the X-coordinates of second point of the fence: \n";
        cin >> Data_2.point_x;
        cout << "Y-Coordinate of the second point of the fence: \n";
        cin >> Data_2.point_y;
        cout << "Intrduce the X-coordinates of third point of the fence: \n";
        cin >> Data_3.point_x;
        cout << "Y-Coordinate of the third point of the fence: \n";
        cin >> Data_3.point_y;
        cout << "Intrduce the X-coordinates of fourth point of the fence: \n";
        cin >> Data_4.point_x;
        cout << "Y-Coordinate of the fourth point of the fence: \n";
        cin >> Data_4.point_y;
        cout << "Intrduce the X-coordinates of fifth point of the fence: \n";
        cin >> Data_5.point_x;
        cout << "Y-Coordinate of the fifth point of the fence: \n";   
        cin >> Data_5.point_y;
        cout << "Intrduce the X-coordinates of sixth point of the fence: \n";
        cin >> Data_6.point_x;
        cout << "Y-Coordinate of the sixth point of the fence: \n";   
        cin >> Data_6.point_y;
        cout << "Intrduce the X-coordinates of seventh point of the fence: \n";
        cin >> Data_7.point_x;
        cout << "Y-Coordinate of the seventh point of the fence: \n";   
        cin >> Data_7.point_y;
        cout << "Intrduce the X-coordinates of eighth point of the fence: \n";
        cin >> Data_8.point_x;
        cout << "Y-Coordinate of the seventh eighth of the fence: \n";   
        cin >> Data_8.point_y;
    }

        coorX = 0;
        coorY = 0;
        pylons << "[\n";
        while(coorX < final_x)
        {
            calculate_polygon(option, coorX, D, H, max_y, maxY_fence);
            j_1 = 0;
        
            while(coorY <= max_y)
            {          
                pylons << " {\n";
                pylons << " \"Point Type\": \"VS\", \n";
                pylons << " \"Point Num\": " << j_1 +1 <<",\n";
                pylons << " \"Line Num\": " << i_1 +1<< ",\n";
                pylons << " \"Local X\": " << coorX <<",\n";
                pylons <<  " \"Local Y\":" << coorY << "\n";   
                if ((coorX + D >= final_x) && (coorY + H >= max_y))
                    pylons << " }\n";
                else
                    pylons << " },\n";

                coorY += H;
                j_1++;
            }
            if(coorY > max_y)
            {
                coorY = 0;
            }
        
            coorX += D;
            i_1++;
        }
        pylons << "]\n";

        coorX = D/2;

        start_end << "[" << endl;
        while(coorX <= final_x )
        {
            if(up == 1)
            {        
                calculate_polygon(option,coorX, D, H, max_y, maxY_fence); //choose the polygon A,B,C,D or E in depending on the eje X-axis
                // for each line:
                while(point[i-1].y < max_y-R) // R -> safety distance for good photo results
                {
                    if(i-2 == 0)
                    {
                        point[0].y = fence_y; //MP
                        point[0].x = coorX;
                        IR_point_num = 0;
                        IR_point_num++;
                        num_MP++;
                        IR++;
                        num_R = 0;
                        type[0] = 'M'; type[1] = 'P';
                        //STORAGE
                        data[j].IR = IR;
                        data[j].IR_point_num = IR_point_num;
                        data[j].type[0] = type[0]; 
                        data[j].type[1] = type[1]; 
                        data[j].num = num_MP;
                        data[j].ROW_num = ROW_num;
                        data[j].x = point[0].x;
                        data[j].y = point[0].y;
                        data[j].up = up;
                        data[j].c = type[1];

                        //path_excel << type[0] << type[1] << "   " << point[0].x << "   " << point[0].y << endl;
                        start_end << " {\n";
                        start_end << " \"Point Type\": \"MP\",\n";
                        start_end << " \"Point Num\": " << num_MP << ",\n";
                        start_end << " \"Row Num\": " << ROW_num << ",\n";
                        start_end << " \"Local X\": " << point[0].x <<",\n";
                        start_end << " \"Local Y\":" << point[0].y << "\n";
                        start_end << " },\n";  
                        j++;
                    }
                    if(i-1 == 1)
                    {
                        point[1].y = R; //first stop after beginning
                        point[1].x = coorX;

                        IR_point_num++;
                        num_R++;

                        type[0] = 'R';

                        //STORAGE
                        data[j].IR = IR;
                        data[j].IR_point_num = IR_point_num;
                        data[j].type[0] = type[0]; 
                        data[j].num = num_R;
                        data[j].ROW_num = ROW_num;
                        data[j].x = point[1].x;
                        data[j].y = point[1].y;
                        data[j].up = up;
                        data[j].c = type[0];
                        j++;
                    }

                    point[i].y = point[i-1].y + stop;
                    point[i].x = coorX;

                    IR_point_num++;
                    num_R++;

                    type[0] = 'R';

                    //STORAGE
                    data[j].IR = IR;
                    data[j].IR_point_num = IR_point_num;
                    data[j].type[0] = type[0]; 
                    data[j].type[1] = type[1]; 
                    data[j].num = num_R;
                    data[j].ROW_num = ROW_num;
                    data[j].x = point[i].x;
                    data[j].y = point[i].y;
                    data[j].up = up;
                    data[j].c = type[0];
                    i++;
                    j++;
                }
                point[i].y = maxY_fence; //The last dot of the road (line) is the coordinate of the fance (MK)
                point[i].x = coorX;
                coorX = coorX + D;
                IR_point_num++;
                num_MK++;

                type[0] = 'M'; type[1] = 'K';
                //STORAGE
                data[j].IR = IR;
                data[j].IR_point_num = IR_point_num;
                data[j].type[0] =  type[0]; 
                data[j].type[1] =  type[1]; 
                data[j].num = num_MP;
                data[j].ROW_num = ROW_num;
                data[j].x = point[i].x;
                data[j].y = point[i].y;
                data[j].up = up;
                data[j].c = type[1];

                start_end << " {\n";
                start_end << " \"Point Type\": \"MK\",\n";
                start_end << " \"Point Num\": " << num_MK << ",\n";
                start_end << " \"Row Num\": " << ROW_num << ",\n";
                start_end << " \"Local X\": " << point[0].x <<",\n";
                start_end << " \"Local Y\":" << point[0].y << "\n";
                start_end << " },\n"; 

                i = 2;
                point[i-2].y = fence_y; // back to the beginning of the road (MP)
                num_lines++;
                ROW_num++;
                j++;
                up = 0;

            }
            else if(up == 0)
            {
                //num_R = 0;
                i = 2;
                calculate_polygon(option,coorX, D, H, max_y, maxY_fence);
                point[0].y = maxY_fence; //MK
                point[0].x = coorX;
                IR_point_num++;
                num_MK++;

                type[0] = 'M'; type[1] = 'K';
                //STORAGE
                data[j].IR = IR;
                data[j].IR_point_num = IR_point_num;
                data[j].type[0] =  type[0]; 
                data[j].type[1] =  type[1]; 
                data[j].num = num_MK;
                data[j].ROW_num = ROW_num;
                data[j].x = point[0].x;
                data[j].y = point[0].y;
                data[j].up = 0;
                data[j].c = type[1];

                start_end << " {\n";
                start_end << " \"Point Type\": \"MK\",\n";
                start_end << " \"Point Num\": " << num_MK << ",\n";
                start_end << " \"Row Num\": " << ROW_num << ",\n";
                start_end << " \"Local X\": " << point[0].x <<",\n";
                start_end << " \"Local Y\":" << point[0].y << "\n";
                start_end << " },\n"; 

                point[1].y = max_y; //R
                point[1].x = coorX; 
                IR_point_num++;
                num_R++;
                j++;

                type[0] = 'R'; 
                //STORAGE
                data[j].IR = IR;
                data[j].IR_point_num = IR_point_num;
                data[j].type[0] =  type[0]; 
                data[j].num = num_R;
                data[j].ROW_num = ROW_num;
                data[j].x = point[1].x;
                data[j].y = point[1].y;
                data[j].up = 0;
                data[j].c = type[0];
                j++;

                while(point[i-1].y > R)
                {
                    point[i].y = point[i-1].y - stop; //R
                    point[i].x = coorX;
                    IR_point_num++;
                    num_R++;

                    type[0] = 'R';
                    //STORAGE
                    data[j].IR = IR;
                    data[j].IR_point_num = IR_point_num;
                    data[j].type[0] =  type[0]; 
                    data[j].type[1] =  type[1]; 
                    data[j].num = num_R;
                    data[j].ROW_num = ROW_num;
                    data[j].x = point[i].x;
                    data[j].y = point[i].y;
                    data[j].up = 0;
                    data[j].c = type[0];

                    i++;
                    j++;
                }
                point[i].y = fence_y; //MP
                point[i].x = coorX;
                IR_point_num++;
                num_MP++;
                type[0] = 'M'; type[1] = 'P';

                //STORAGE
                data[j].IR = IR;
                data[j].IR_point_num = IR_point_num;
                data[j].type[0] =  type[0]; 
                data[j].type[1] =  type[1]; 
                data[j].num = num_MP;
                data[j].ROW_num = ROW_num;
                data[j].x = point[i].x;
                data[j].y = point[i].y;
                data[j].up = 0;
                data[j].c = type[1];
                j++;

                start_end << " {\n";
                start_end << " \"Point Type\": \"MP\",\n";
                start_end << " \"Point Num\": " << num_MP << ",\n";
                start_end << " \"Row Num\": " << ROW_num << ",\n";
                start_end << " \"Local X\": " << point[i].x <<",\n";
                start_end << " \"Local Y\":" << point[i].y << "\n";
                start_end << " },\n"; 

                coorX = coorX + D;

                i = 2;
                point[i-2].y = fence_y; // back to the beginning of the road (MP)
                point[i-1].y = fence_y;

                up = 1;    
                ROW_num++;       
            }
        }

    start_end << "]" << endl;
    pylons.close();
    start_end.close();

    print(path, data, j);

    char delet;
    int IR_delete, IR_point_delete, stop_1 = 0, num = 0;
    cout << "Delete point?  y/n" << endl;
    cin >> delet;
    if(delet == 'y' || delet == 'Y')
    {
        do{ 
            cout << "Introduce IR: " << endl;
            cin >> IR_delete;
            i = 0;
            while(IR_delete != data[i].IR)
            {
                i++;
            }
            if(IR_delete != data[i].IR)
                i = -1;
            if(i == -1)
            {
                cout << "Invalid Data" << endl;
                cout << "Incremental Road not found" << endl;
                stop_1 = 1;
            }else{
                cout << "Introduce IR_point_num: " << endl;
                cin >> IR_point_delete;
     
                while((IR_delete == data[i].IR) && (IR_point_delete != data[i].IR_point_num))
                {
                    i++;
                }
                if(IR_point_delete != data[i].IR_point_num)
                    i = -1;
                if(i == -1)
                {
                cout << "Invalid Data" << endl;
                cout << "Incremental Road not found" << endl;
                stop_1 = 1;
                }else{
                    num = i;
                    Datas data_delete;

                    data_delete.IR_point_num = data[num].IR_point_num;
                    data_delete.num = data[num].num;
                    data_delete.c = data[num].c;

                    //while(data[i].IR == IR_delete)
                    while(i < j-1)
                    {
                        data[i].IR_point_num = data[i+1].IR_point_num - 1;
                        data[i].type[0] = data[i+1].type[0] ; 
                        data[i].type[1] = data[i+1].type[1] ; 
                        if(data[i+1].c == data_delete.c) // R-->R
                            data[i].num =  data[i+1].num - 1 ;
                        else
                            data[i].num =  data[i+1].num ;
                        data[i].x = data[i+1].x;
                        data[i].y = data[i+1].y;
                        data[i].up = data[i+1].up;
                        data[i].c =  data[i+1].c;
                        i++; 
                    }

                    print(path_del, data, j);
                    cout << "Delete other point?" << endl;
                    cin >> delet;
                    if(delet == 'y' || delet == 'Y')
                    {
                        stop_1 = 0;
                        path_del.open("path_delete_points.txt");
                    }
                    else
                        stop_1 = 1;
                }
            }

        }while(stop_1 == 0);
    }   

    char add;
    stop_1 = 0;
    cout << "Add point?  y/n" << endl;
    cin >> add;
    if(add == 'y' || add == 'Y')
    {
        do{ 
            cout << "Introduce IR: " << endl;
            cin >> IR_delete;
            i = 0;
            while(IR_delete != data[i].IR)
            {
                i++;
            }
            if(IR_delete != data[i].IR)
                i = -1;
            if(i == -1)
            {
                cout << "Invalid Data" << endl;
                cout << "Incremental Road not found" << endl;
                stop_1 = 1;
            }else{
                cout << "Introduce IR_point_num: " << endl;
                cin >> IR_point_delete;

                while((IR_delete == data[i].IR) && (IR_point_delete != data[i].IR_point_num))
                {
                    i++;
                }

                if(IR_point_delete != data[i].IR_point_num)
                    i = -1;
                if(i == -1)
                {
                     
                cout << "Invalid Data" << endl;
                cout << "Incremental Road not found" << endl;
                stop_1 = 1;
                }else{
                
                Datas last_data, new_data;

                char p;
                cout << "Point type" << endl;
                cin>> p;
                cout << "Point num" << endl;
                cin>> last_data.num;
                cout << "X Point" << endl;
                cin>> last_data.x;
                cout << "Y Point" << endl;
                cin>>last_data.y;

                    num = i;
                    last_data.IR_point_num = IR_point_delete;
                    last_data.c = p; 
                    if(last_data.c == 'R'){
                        last_data.type[0] = 'R';
                        last_data.c = 'R'; 
                        last_data.type[1] = 'K';
                    }else if(last_data.c == 'K')
                    {
                        last_data.c = 'K'; 
                        last_data.type[0] = 'M';
                        last_data.type[1] = 'K';
                    }else{
                        last_data.c = 'P'; 
                        last_data.type[0] = 'M';
                        last_data.type[1] = 'P';
                    }

                    while(i < j+2)
                    {
                        new_data.IR_point_num = data[i].IR_point_num+1;
                        new_data.type[0] = data[i].type[0] ; 
                        new_data.type[1] = data[i].type[1] ; 
                        new_data.num = data[i].num ;
                        new_data.x = data[i].x;
                        new_data.y = data[i].y;
                        new_data.up = data[i].up;
                        new_data.c =  data[i].c;


                        data[i].IR_point_num = last_data.IR_point_num;
                        data[i].type[0] =  last_data.type[0];
                        data[i].type[1] = last_data.type[1]; 
                        
                        data[i].num =  last_data.num ;
                        data[i].x = last_data.x;
                        data[i].y = last_data.y;
                        data[i].up = last_data.up;
                        data[i].c = last_data.c;

                        last_data.IR_point_num = new_data.IR_point_num;
                        last_data.type[0] = new_data.type[0] ; 
                        last_data.type[1] = new_data.type[1] ; 
                        if( new_data.c == p) // R-->R
                        last_data.num = new_data.num + 1;
                        else 
                        last_data.num =  new_data.num ;
                        last_data.x = new_data.x;
                        last_data.y =  new_data.y;
                        last_data.up = new_data.up;
                        last_data.c =  new_data.c;
                        i++; 
                    }

                    print(path_add, data, j);
                    cout << "Add other point?" << endl;
                    cin >> delet;
                    if(delet == 'y' || delet == 'Y')
                    {
                        stop_1 = 0;
                        path_add.open("path_add_points.txt");
                    }
                    else
                        stop_1 = 1;
                }
            }
        }while(stop_1 ==0);

    }

    return 0;
}

void print(ofstream& path,Datas data[MAX], int j)
{

    if (path.is_open()) {
        path << "[" << endl;
        //cout << "[" << endl;
        for(int i = 0; i < j; i++)
        {
            //cout << " {\n";
            path << " {\n";
            //cout << " \"IR Number\":" << data[i].IR <<", \n";
            path << " \"IR Number\":" << data[i].IR <<", \n";
            //cout << " \"IR Point Num\": " << data[i].IR_point_num <<",\n";
            path << " \"IR Point Num\": " << data[i].IR_point_num <<",\n";
            if(data[i].type[0] == 'R')
            {
                //cout << " \"Point Type\": \""<< data[i].type[0] << "\",\n";
                path << " \"Point Type\": \""<< data[i].type[0] << "\",\n";
            }else{
                //cout << " \"Point Type\": \""<< data[i].type[0] << data[i].type[1] <<"\",\n";
                path << " \"Point Type\": \""<< data[i].type[0] << data[i].type[1] <<"\",\n";
            }
            //cout << " \"Point Num\": " << data[i].num << ",\n";
            //cout << " \"Row Num\": " << data[i].ROW_num << ",\n";
            //cout << " \"Local X\": " << data[i].x <<",\n";
            //cout << " \"Local Y\":" << data[i].y << ",\n";

            path << " \"Point Num\": " << data[i].num << ",\n";
            path << " \"Row Num\": " << data[i].ROW_num << ",\n";
            path << " \"Local X\": " << data[i].x <<",\n";
            path << " \"Local Y\":" << data[i].y << ",\n";

                if(data[i].type[0] == 'M' && data[i].type[1] == 'P')
                {
                    if(data[i].IR == 1 && data[i].IR_point_num == 1)
                    {
                        //cout << " \"North\": \"R1\"," << endl;
                        //cout << " \"East\": \"MP2\"," << endl;
                        path << " \"North\": \"R1\"," << endl;
                        path << " \"East\": \"MP2\"," << endl;
                    }else
                    {
                        //cout << " \"North\": \"R" << data[i+1].num <<"\"," << endl;
                        //cout << " \"East\": \"MP" << data[i-1].num <<"\"," << endl;
                        //cout << " \"West\": \"MP" << data[i-1].num - 1 << "\"," << endl;

                        path << " \"North\": \"R" << data[i+1].num <<"\"," << endl;
                        path << " \"East\": \"MP" << data[i].num + 1 <<"\"," << endl;
                        path << " \"West\": \"MP" << data[i].num - 1 << "\"," << endl;
                    }
                }else if(data[i].type[0] == 'R')
                {
                    
                    if(data[i].IR_point_num == 1) //if delete the fisrt point (MP)
                     {
                        //cout << " \"North\": \"R" << data[i+1].num << "\"," << endl;
                        path << " \"North\": \"R" << data[i+1].num << "\"," << endl;
                     }
                    else if(data[i].IR_point_num == 2)
                    {
                        //cout << " \"North\": \"R" << data[i+1].num << "\"," << endl;
                        //cout << " \"South\": \"MP" << data[i-1].num << "\"," << endl;
                        if(data[i+1].c == 'R')
                        path << " \"North\": \"R" << data[i+1].num << "\"," << endl;
                         if(data[i-1].c == 'P')
                        path << " \"South\": \"MP" << data[i-1].num << "\"," << endl;
                        if(data[i-1].c == 'R')
                        path << " \"North\": \"R" << data[i-1].num << "\"," << endl;
                         if(data[i+1].c == 'P')
                        path << " \"South\": \"MP" << data[i+1].num << "\"," << endl;
                    }
                    else if( data[i+1].c == 'K')
                    {
                        //cout << " \"North\": \"MK" << data[i+1].num << "\"," << endl;
                        //cout << " \"South\": \"R" << data[i-1].num << "\"," << endl;

                        path << " \"North\": \"MK" << data[i+1].num << "\"," << endl;
                        path << " \"South\": \"R" << data[i-1].num << "\"," << endl;
                    }else
                    {
                        //cout << " \"North\": \"R" << data[i+1].num << "\"," << endl;
                        //cout << " \"South\": \"R" << data[i-1].num << "\"," << endl;       
                         if(data[i+1].c == 'R')
                        path << " \"North\": \"R" << data[i+1].num << "\"," << endl;
                         if(data[i-1].c == 'R')
                        path << " \"South\": \"R" << data[i-1].num << "\"," << endl;      
                    } 
                }else if(data[i].type[0] == 'M' && data[i].type[1] == 'K')
                {
                    if(data[i].num == 1)
                    {
                        //cout << " \"East\": \"MK" << data[i+1].num << "\"," << endl;
                        //cout << " \"South\": \"R" << data[i-1].num << "\"," << endl;
                        if(data[i+1].c == 'K')
                        path << " \"East\": \"MK" << data[i+1].num << "\"," << endl;
                         if(data[i+1].c == 'R')
                        path << " \"South\": \"R" << data[i-1].num << "\"," << endl;
                    }else if(i == j-1)
                    {
                        //cout << " \"South\": \"R" << data[i-1].num << "\"," << endl; 
                        //cout << " \"West\": \"MK" << data[i].num - 1 << "\"," << endl;   
                         if(data[i+1].c == 'R')
                        path << " \"South\": \"R" << data[i-1].num << "\"," << endl; 
                         if(data[i+1].c == 'K')
                        path << " \"West\": \"MK" << data[i].num - 1 << "\"," << endl;     
                    }else
                    {
                        //cout << " \"East\": \"MK" << data[i].num + 1 << "\"," << endl;
                        //cout << " \"South\": \"R" << data[i-1].num << "\"," << endl; 
                        //cout << " \"West\": \"MK" << data[i].num - 1 << "\"," << endl;    
                         if(data[i+1].c == 'K')
                        path << " \"East\": \"MK" << data[i].num + 1 << "\"," << endl;
                         if(data[i-1].c == 'R')
                        path << " \"South\": \"R" << data[i-1].num << "\"," << endl;
                         if(data[i+1].c == 'K') 
                        path << " \"West\": \"MK" << data[i].num - 1 << "\"," << endl;                 
                    }
                }
                if(data[i].c == 'R')
                {
                    //cout << " \"operations\": \"Record\"";
                    path << " \"operations\": \"Record\"";
                }else if(data[i].up == 1 && data[i].c == 'P')
                {
                    //cout << " \"operations\": \"Start IR\"";
                    path << " \"operations\": \"Start IR\"";
                }else if(data[i].up == 1 && data[i].c == 'K')
                {
                    //cout << " \"operations\": \"Out Row North\"";
                    path << " \"operations\": \"Out Row North\"";
                }else if(data[i].up == 0 && data[i].c == 'K')
                {
                    //cout << " \"operations\": \"Enter Row North\"";
                    path << " \"operations\": \"Enter Row North\"";
                }else if(data[i].up == 0 && data[i].c == 'P')
                {
                    path << " \"operations\": \"End IR\"";
                    //cout << " \"operations\": \"End IR\"";
                }
                
                if(i == j-1)
                {
                //cout << " }\n";
                path << "\n }\n";                   
                }else{ 
                //cout << "\n },\n";
                path << "\n },\n";
                }
        }
        path << "]\n";
        //cout << "]\n";

        path.close();

    } // if (path.is_open())
    else {
        cerr << "Error opening file." << endl;
    }
}
void calculate_polygon(int option,float x, float D, float H, float &y, float &max_fence)
{
    //input_data Data[2];
    float P1[2],P2[2],P3[2],P4[2],m, m_fence, pylon_right, pylon_left;


    if( option == 0){ 
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


    }else{


        if( x >=  P1_A[0] && x <= P3_A[0]) // Polygon A
        {   
            for(int i = 0; i<2; i++)
            {
                P1[i] = P1_A[i];
                P2[i] = P2_A[i];
                P3[i] = P3_A[i];
                P4[i] = P4_A[i];
            }

            Data[1].point_x = Data_2.point_x;    Data[1].point_y = Data_2.point_y;//coordinates of the fences
            Data[2].point_x = Data_3.point_x;    Data[2].point_y = Data_3.point_y;
        }
        else if(x >= P1_B[0] && x < P3_B[0]) // Polygon B
        {
            for(int i = 0; i<2; i++)
            {
                P1[i] = P1_B[i];
                P2[i] = P2_B[i];
                P3[i] = P3_B[i];
                P4[i] = P4_B[i];
            }

            Data[1].point_x = Data_3.point_x;    Data[1].point_y = Data_3.point_y;//coordinates of the fences
            Data[2].point_x = Data_4.point_x;    Data[2].point_y = Data_4.point_y;
        }
        else if(x >= P1_C[0] && x < P3_C[0]) // Polygon C
        {
            for(int i = 0; i<2; i++)
            {
                P1[i] = P1_C[i];
                P2[i] = P2_C[i];
                P3[i] = P3_C[i];
                P4[i] = P4_C[i];
            }

            Data[1].point_x = Data_4.point_x;    Data[1].point_y = Data_4.point_y;//coordinates of the fences
            Data[2].point_x = Data_5.point_x;    Data[2].point_y = Data_5.point_y;   

        }else if(x >= P1_D[0] && x < P3_D[0]) // Polygon D
        {
            for(int i = 0; i<2; i++)
            {
                P1[i] = P1_D[i];
                P2[i] = P2_D[i];
                P3[i] = P3_D[i];
                P4[i] = P4_D[i];
            }

            Data[1].point_x = Data_5.point_x;    Data[1].point_y = Data_5.point_y;//coordinates of the fences
            Data[2].point_x = Data_6.point_x;    Data[2].point_y = Data_6.point_y;
        
        }else if(x >= P1_E[0] && x < P3_E[0]) // Polygon E
        {
            for(int i = 0; i<2; i++)
            {
                P1[i] = P1_E[i];
                P2[i] = P2_E[i];
                P3[i] = P3_E[i];
                P4[i] = P4_E[i];
            }

            Data[1].point_x = Data_6.point_x;    Data[1].point_y = Data_6.point_y;//coordinates of the fences
            Data[2].point_x = Data_7.point_x;    Data[2].point_y = Data_7.point_y;
        }
        else{
            cout << "Error calculating polygon\n";
            exit(-1);
        }
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

    //  cout << "\n Slope calculation: " << m_fence << "\n";
    //  cout << "max fence calculation: " << max_fence << "\n";
}
   

float lower(float p_l, float p_r)
{
    if(p_l <= p_r)
        return p_l;
    else
        return p_r;
}
