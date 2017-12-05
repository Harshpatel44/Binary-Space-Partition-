
//Flow of the program
//1.main function() -> bsp_tree() -> count_function() -> partitioning -> bsp_tree()

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<time.h>
#include<iomanip>

using namespace std;
int partition_number=0;
int count_function(float vertx[],  float verty[],float x[],float y[],int n,float x_new[],float y_new[],int &counting,int r,float x_main[],float y_main[],int n_main){


//this function calculates the number of points that resides inside the provided space
// & checks the condition by calculating centre_x and centre_y is within range R
// & If the condition fails then flag=1 and partition occurs further in bsp_function

//vertx and verty contain the vertices of the partition
//x and y contain all the points
//n is no. of points
//x_new and y_new are the points resides inside the partition
//r is the value to be provided
    float flag=0;
    int i;
    counting=0;
    int p_id[n];

    //cout<<"x0: "<<vertx[0]<<" x1: "<<vertx[1]<<" x2: "<<vertx[2]<<" x3: "<<vertx[3]<<endl;
    //cout<<"y0: "<<verty[0]<<" y1: "<<verty[1]<<" y2: "<<verty[2]<<" y3: "<<verty[3];
cout<<"Partition Number:"<<setw(3)<<partition_number;

    for(i=0;i<n_main;i++){

        if(x_main[i]<vertx[1] && x_main[i]>vertx[0] && y_main[i]<verty[2] && y_main[i]>verty[0]){
            x_new[counting]=x[i];
            p_id[counting]=i;
            y_new[counting]=y[i];    //if 'if condition' satisfies then these points reside in the partition hence stored in x_new and y_new

            counting++;
        }
    }

cout<<"\tNumber of points:"<<setw(3)<<counting<<" ";  // shows number of items in the partition i.e. counting variable
partition_number++;
cout<<setw(3)<<"Points are: ";
for(int l=0;l<counting;l++){
    cout<<p_id[l]+1<<" ";
}
cout<<endl;
int sumx=0,sumy=0;

float centre_x,centre_y;   //calculating the centre_x and centre_y
for(int i=0;i<counting;i++){
    sumx=sumx+x_new[i];

    sumy=sumy+y_new[i];
}

if(counting>1){
    centre_x=sumx/counting;
    centre_y=sumy/counting;

    for(int k=0;k<n;k++){

            if(std::abs(centre_x-x[k])>=r && std::abs(centre_y-y[k])>=r)  //checking if the diffrence betn all the points and centre(x,y)<=r

                {

                    flag=1;  //condition fails and flag=1

                    break;
                }
    }
    return flag;
}
else
    return 0;

}
void *partitioning(float vertx[], float verty[],float (&p_array)[16]){
    float medianx1,mediany1,medianx2,mediany2;

// This partition divides the space into exaclty half. and the left and right partition points are stored in p_array
        medianx1=(vertx[0]+vertx[1])/2;

        mediany1=verty[0];

        medianx2=(vertx[2]+vertx[3])/2;

        mediany2=verty[2];


        float temp[16]={vertx[0],medianx1,vertx[2],medianx2,verty[0],mediany1,verty[2],mediany2,
                 medianx1,vertx[1],medianx2,vertx[3],mediany1,verty[1],mediany2,verty[3]};

        for(int i=0;i<16;i++){
            p_array[i]=temp[i];
        }


}

void bsp_tree(float vertx[],float verty[],float x[],float y[],int n,int p,int r,float x_main[],float y_main[],int n_main){


    //This Function contains all the vertices of the space and the points that are randomly provided and listed in the program.
    // 1.It first checks the no. of elements inside the current partition and if that points follow the given condition using count_function
    // 2.If the condition is not satisfied then partition occurs of the space using the partitioning function
    // 3.After partitioning the bsp function recurses for 2 partition occured and this iterated until the given condition satisfies or only 1 element remains.

    float array_lx[4],array_ly[4],array_rx[4],array_ry[4],x_new[8],y_new[8],p_array[16];
    int flag=0,counting;


    flag=count_function(vertx,verty,x,y,n,x_new,y_new,counting,r,x_main,y_main,n_main);



    if(flag==1){

            partitioning(vertx,verty,p_array);

//P_array contains the partitioned points i.e 8 points (4 for left partition and 4 for right partition)
// All the 16 points are moved to other variables for further use here.
        for(int i=0;i<16;i++){
            if(i<8){
                if(i<4){
                    array_lx[i]=p_array[i];
                }
                else{
                    array_ly[i-4]=p_array[i];
                }
            }
            if(i<16 && i>=8){

                    if(i<12){
                        array_rx[i-8]=p_array[i];
                    }
                    else{
                        array_ry[i-12]=p_array[i];
                    }

            }
        }

        bsp_tree(array_lx,array_ly,x_new,y_new,counting,-1,r,x_main,y_main,n_main);   //left partition is recursed further
        bsp_tree(array_rx,array_ry,x_new,y_new,counting,1,r,x_main,y_main,n_main);    //right partition is recursed further


    }


}

int main(){

    float shapex[]={0,100,0,100},shapey[]={0,0,100,100};
    srand(time(NULL));
    int r,n,X,Y;



    cout<<"Enter R :";
    cin>>r;




    cout<<"Enter X and Y for Space (Eg. 50 50):";
    cin>>X>>Y;
    shapex[1]=X;
    shapex[3]=X;

    shapey[2]=Y;
    shapey[3]=Y;

    //cout<<"Enter No. Of Points :";     /* random N is given i.e. no of points */
    //cin>>n;
    n=10;
    cout<<"       X\t  Y\n";
    float x[10]={34,22,4,23,30,17,35,15,6,27},y[10]={19,35,5,38,19,31,3,17,2,25};
    //for(int i=0;i<n;i++){
    //    x[i]=rand()%X;       /* random positions(x,y) of all the N points are generated */
    //    y[i]=rand()%Y;
    //    cout<<setw(3)<<i+1<<". "<<setw(3)<<x[i]<<"\t"<<setw(3)<<y[i]<<endl;
    //}


    cout<<endl;
    bsp_tree(shapex,shapey,x,y,n,0,r,x,y,n);   //bsp function to calculate further

    return 0;
}








