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

void print_point(int IR, int IR_point_num, char p_type[2], int num_type, int num_row, float x, float y, int up,  char c);
void calculate_polygon(float x, float D, float H, float &y, float &max_fence);
int last_pylon( float max, float H);
float lower(float p_l, float p_r);

int main() {
    
    points point[1000];
    final end[1000];
    Datas data[10000];

    int i,j = 0, up = 1;
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
    cout << "\n[\n";
    while(coorX <= final_x)
    {
        if(up == 1)
        {        
            calculate_polygon(coorX, D, H, max_y, maxY_fence); //choose the polygon A,B,C,D or E in depending on the eje X-axis
            // for each line:
            while(point[i-1].y < max_y-R) // R -> safety distance for good photo results
            {
                if(i-2 == 0)
                {
                    point[0].y = fence_y; //MP
                    point[0].x = coorX;

                    IR_point_num++;
                    num_MP++;
                    IR++;
                    num_R = 0;
                    type[0] = 'M'; type[1] = 'P';
                    // //STORAGE
                    // data[j].IR = IR;
                    // data[j].IR_point_num = IR_point_num;
                    // data[j].type[0] = type[0]; 
                    // data[j].type[1] = type[1]; 
                    // data[j].num = num_MP;
                    // data[j].ROW_num = ROW_num;
                    // data[j].x = point[0].x;
                    // data[j].y = point[0].y;
                    // data[j].up = up;
                    // data[j].c = type[1];
                    print_point(IR, IR_point_num, type, num_MP, ROW_num, point[0].x, point[0].y, up, type[1]);
                    j++;
                }
                if(i-1 == 1)
                {
                    point[1].y = R; //first stop after beginning
                    point[1].x = coorX;

                    IR_point_num++;
                    num_R++;

                    type[0] = 'R';

                    // //STORAGE
                    // data[j].IR = IR;
                    // data[j].IR_point_num = IR_point_num;
                    // data[j].type[0] = type[0]; 
                    // data[j].num = num_MP;
                    // data[j].ROW_num = ROW_num;
                    // data[j].x = point[1].x;
                    // data[j].y = point[1].y;
                    // data[j].up = up;
                    // data[j].c = type[0];
                    j++;
                    print_point(IR,IR_point_num, type, num_R, ROW_num, point[1].x, point[1].y, up, type[0]);
                }

                point[i].y = point[i-1].y + stop;
                point[i].x = coorX;

                IR_point_num++;
                num_R++;

                type[0] = 'R';

                // //STORAGE
                // data[j].IR = IR;
                // data[j].IR_point_num = IR_point_num;
                // data[j].type[0] = type[0]; 
                // data[j].type[1] = type[1]; 
                // data[j].num = num_MP;
                // data[j].ROW_num = ROW_num;
                // data[j].x = point[0].x;
                // data[j].y = point[0].y;
                // data[j].up = up;
                // data[j].c = type[0];
                print_point(IR,IR_point_num, type, num_R, ROW_num, point[i].x, point[i].y, up, type[0]);
                i++;
            }
            point[i].y = maxY_fence; //The last dot of the road (line) is the coordinate of the fance (MK)
            point[i].x = coorX;
            coorX = coorX + D;
            IR_point_num++;
            num_MK++;
            // if(count_MK == 2)
            // {
            //     ROW_num++;
            //     count_MK = 0;
            // }
            type[0] = 'M'; type[1] = 'K';
            // //STORAGE
            // data[j].IR = IR;
            // data[j].IR_point_num = IR_point_num;
            // data[j].type[0] =  type[0]; 
            // data[j].type[1] =  type[1]; 
            // data[j].num = num_MP;
            // data[j].ROW_num = ROW_num;
            // data[j].x = point[i].x;
            // data[j].y = point[i].y;
            // data[j].up = up;
            // data[j].c = type[1];
            print_point(IR,IR_point_num, type, num_MK, ROW_num, point[i].x, point[i].y, up, type[1]);
            i = 2;
            point[i-2].y = fence_y; // back to the beginning of the road (MP)
            num_lines++;
            ROW_num++;
            up = 0;

        }
        else if(up == 0)
        {
            //num_R = 0;
            i = 2;
            calculate_polygon(coorX, D, H, max_y, maxY_fence);
            point[0].y = maxY_fence; //MK
            point[0].x = coorX;
            IR_point_num++;
            num_MK++;

            type[0] = 'M'; type[1] = 'K';
            // //STORAGE
            // data[j].IR = IR;
            // data[j].IR_point_num = IR_point_num;
            // data[j].type[0] =  type[0]; 
            // data[j].type[1] =  type[1]; 
            // data[j].num = num_MP;
            // data[j].ROW_num = ROW_num;
            // data[j].x = point[0].x;
            // data[j].y = point[0].y;
            // data[j].up = up;
            // data[j].c = type[1];
            print_point(IR,IR_point_num, type, num_MK, ROW_num, point[0].x, point[0].y, up, type[1]);

            point[1].y = max_y; //R
            point[1].x = coorX; 
            IR_point_num++;
            num_R++;

            type[0] = 'R'; 
            // //STORAGE
            // data[j].IR = IR;
            // data[j].IR_point_num = IR_point_num;
            // data[j].type[0] =  type[0]; 
            // data[j].num = num_MP;
            // data[j].ROW_num = ROW_num;
            // data[j].x = point[1].x;
            // data[j].y = point[1].y;
            // data[j].up = up;
            // data[j].c = type[0];
            print_point(IR,IR_point_num, type, num_R, ROW_num, point[1].x, point[1].y, up, type[0]);

            while(point[i-1].y > R)
            {
                point[i].y = point[i-1].y - stop; //R
                point[i].x = coorX;
                IR_point_num++;
                num_R++;

                type[0] = 'R';
                //STORAGE
                // data[j].IR = IR;
                // data[j].IR_point_num = IR_point_num;
                // data[j].type[0] =  type[0]; 
                // data[j].type[1] =  type[1]; 
                // data[j].num = num_MP;
                // data[j].ROW_num = ROW_num;
                // data[j].x = point[0].x;
                // data[j].y = point[0].y;
                // data[j].up = up;
                // data[j].c = type[1];
                print_point(IR,IR_point_num, type, num_R, ROW_num, point[i].x, point[i].y, up, type[0]);
                i++;
            }
            point[i].y = fence_y; //MP
            point[i].x = coorX;
            IR_point_num++;
            num_MP++;

            type[0] = 'M'; type[1] = 'P';
            print_point(IR,IR_point_num, type, num_MP, ROW_num, point[i].x, point[i].y, up, type[1]);

            coorX = coorX + D;

            i = 2;
            point[i-2].y = fence_y; // back to the beginning of the road (MP)
            point[i-1].y = fence_y;

            up = 1;    
            ROW_num++;       
        }
    }

    cout << "]\n";

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

    //  cout << "\n Slope calculation: " << m_fence << "\n";
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

void print_point(int IR, int IR_point_num, char p_type[2], int num_type, int num_row, float x, float y, int up,  char c)
{
    cout << "{\n";
    cout << "\"IR Number\":" << IR <<", \n";
    cout << "\"IR Point Num\": " << IR_point_num <<",\n";
    if(p_type[0] == 'R')
    {
        cout << "\"Point Type\": \""<< p_type[0] << "\",\n";
    }else{
        cout << "\"Point Type\": \""<< p_type[0] << p_type[1] <<"\",\n";
    }
    cout << "\"Point Num\": " << num_type << ",\n";
    cout << "\"Row Num\": " << num_row << ",\n";
    cout << "\"Local X\": " << x <<",\n";
    cout << "\"Local Y\":" << y << ",\n";
    if(c == 'R')
    {
        cout << "\"operations\": \"Record\"";
    }else if(up == 1 && c == 'P')
    {
        cout << "\"operations\": \"Start IR\"";
    }else if(up == 1 && c == 'K')
    {
        cout << "\"operations\": \"Out Row North\"";
    }else if(up == 0 && c == 'K')
    {
        cout << "\"operations\": \"Enter Row North\"";
    }else if(up == 0 && c == 'P')
    {
        cout << "\"operations\": \"End IR\"";
    }
    cout << "\n},\n";
}