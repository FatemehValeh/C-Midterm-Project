#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
/* IN THE NAME OF GOD
WELCOME
thief and robber are two names for one meaning :D
cops and policemen are two names for one meaning :D*/
int map[1000][1000]; ///cops and robber are here
int positions[1000][1000][2];/// keeps x & y of cops locations
int count; ///counts number or policemen moves
int t_count; ///counts number or thief moves
int thief[2];///location of thief. thief[0] for x & thief[1] for y
int star;///used in main

///x random location
int xloc(int column){
    int x;
    x=rand()%(column);
    return x;
}
///y random location
int yloc(int row){
    int y;
    y=rand()%(row);
    return y;
}
///prints map in a good look
void myprint(int row, int column){
    int k,l;
    for (k=0; k<row; k++){
        for (l=0; l<column; l++){
            if(map[k][l]==-1){
                printf(" T ");
        }
        else if (map[k][l]!=-2){

            printf("D%d ", map[k][l]);
        }
        else if(map[k][l] == -2){
            printf(" * ");
        }
        }

    printf("\n");
     }
}
///check if a policeman sees the thief or not
int seen(int a, int b, int x, int y){
    if ( (a==x) && (b==y) ){
        printf("GAME OVER :(\n");
        printf("Number of thief moves:%d  Number of policemen moves:%d \n", t_count, count);
        exit (0);
    }
    if((y==b) && (a>=x) && (x-a)>=-2)
        return 1;
    if ((y==b) && (a<=x) && (x-a)<=2)
        return 2;
    if( (x==a) && (b<=y) && (y-b)<=2)
        return 3;
    if ( (x==a) && (b>=y) && (y-b)>=-2)
        return 4;
    if ( (a>x) && (b<y) && ((x-a)>=-2) && ((y-b)<=2) )
        return 5;
    if ( (a>x) && (b>y) && ((x-a)>=-2) && ((y-b)>=-2) )
        return 6;
    if ( (a<x) && (b>y) && ((x-a)<=2) && ((y-b)>=-2) )
        return 7;
    if ( (a<x) && (b<y) && ((x-a)<=2) && ((y-b)<=2) )
        return 8;
    return -1;
}
///calculates the distance, used to move policemen
double distance(int a, int b, int x, int y){
    int aa=fabs(x-a);
    int bb=fabs(y-b);
    double res=sqrt((aa*aa)+(bb*bb));
    return res;
}
///calculates minimum index of an array, used in moving policemen to the nearest loc from the thief
double mymin(double arr[9]){
    double m;
    int i;
    m=arr[0];
    for(i=1; i<9; i++){
        if(arr[i]<m)
            m=arr[i];
    }
    return m;
}
///to move policemen; a & b are for a policeman and x & y are for the thief, i & j are because of calling function in a loop
void move(int a, int b, int x, int y, int i, int j, int row, int column){
    double l= distance(a,b,x,y);
    int aa=a;
    int bb=b;
    double arr[9]={l, distance(a, b-1,x,y), distance(a,b+1,x,y), distance(a+1,b,x,y), distance(a-1,b,x,y), distance(a-1,b+1,x,y), distance(a-1,b-1,x,y), distance(a+1,b-1,x,y), distance(a+1,b+1,x,y)};
    double ll=mymin(arr);
        ///up
         if (ll==distance(a,b-1,x,y) && (map[b-1][a]==-2 || map[b-1][a]==-1)){
            map[bb-1][aa]= map[bb][aa];
            map[bb][aa]=-2;
            positions[i][j][0]=aa;
            positions[i][j][1]=bb-1;
            count++;
        }
        ///down
         if (ll==distance(a,b+1,x,y) && (map[b+1][a]==-2 || map[b+1][a]==-1)){
            map[bb+1][aa]= map[bb][aa];
            map[bb][aa]=-2;
            positions[i][j][0]=aa;
            positions[i][j][1]=bb+1;
            count++;
        }
        ///right
         if (ll==distance(a+1,b,x,y) && (map[b][a+1]==-2 || map[b][a+1]==-1)){
            map[bb][aa+1]= map[bb][aa];
            map[bb][aa]=-2;
            positions[i][j][0]=aa+1;
            positions[i][j][1]=bb;
            count++;
        }
        ///left
         if (ll==distance(a-1,b,x,y) && (map[b][a-1]==-2 || map[b][a-1]==-1)){
            map[bb][aa-1]= map[bb][aa];
            map[bb][aa]=-2;
            positions[i][j][0]=aa-1;
            positions[i][j][1]=bb;
            count++;
        }
        ///left and down
        if (ll==distance(a-1,b+1,x,y) && (map[b+1][a-1]==-2 || map[b+1][a-1]==-1)){
            map[bb+1][aa-1]= map[bb][aa];
            map[bb][aa]=-2;
            positions[i][j][0]=aa-1;
            positions[i][j][1]=bb+1;
            count++;
        }
        ///left and up
        if (ll==distance(a-1,b-1,x,y) && (map[b-1][a-1]==-2 || map[b-1][a-1]==-1)){
            map[bb-1][aa-1]= map[bb][aa];
            map[bb][aa]=-2;
            positions[i][j][0]=aa-1;
            positions[i][j][1]=bb-1;
            count++;
        }
        ///right and up
        if (ll==distance(a+1,b-1,x,y) && (map[b-1][a+1]==-2 || map[b-1][a+1]==-1)){
            map[bb-1][aa+1]= map[bb][aa];
            map[bb][aa]=-2;
            positions[i][j][0]=aa+1;
            positions[i][j][1]=bb-1;
            count++;
        }
        ///right and down
        if (ll==distance(a+1,b+1,x,y) && (map[b+1][a+1]==-2 || map[b+1][a+1]==-1)){
            map[bb+1][aa+1]= map[bb][aa];
            map[bb][aa]=-2;
            positions[i][j][0]=aa+1;
            positions[i][j][1]=bb+1;
            count++;
        }
}
///policemen rand move
void rand_move (int a, int b, int i, int j, int row, int column){
    int p=rand()%9;
    switch (p){
    case 0:
        if(map[b-1][a]==-2 || map[b-1][a]==-1){
            map[b-1][a]=map[b][a];
            map[b][a]=-2;
            positions[i][j][0]=a;
            positions[i][j][1]=b-1;
            count++;
            }
        break;
    case 1:
        if(map[b-1][a+1]==-2 || map[b-1][a+1]==-1){
        map[b-1][a+1]=map[b][a];
        map[b][a]=-2;
        positions[i][j][0]=a+1;
        positions[i][j][1]=b-1;
        count++;
        }
        break;
    case 2:
        if(map[b][a+1]==-2 || map[b][a+1]==-1){
        map[b][a+1]=map[b][a];
        map[b][a]=-2;
        positions[i][j][0]=a+1;
        positions[i][j][1]=b;
        count++;}
        break;
    case 3:
        if(map[b+1][a+1]==-2 || map[b+1][a+1]==-1){
        map[b+1][a+1]=map[b][a];
        map[b][a]=-2;
        positions[i][j][0]=a+1;
        positions[i][j][1]=b+1;
        count++;}
        break;
    case 4:
        if(map[b+1][a]==-2 || map[b+1][a]==-1){
        map[b+1][a]=map[b][a];
        map[b][a]=-2;
        positions[i][j][0]=a;
        positions[i][j][1]=b+1;
        count++;}
        break;
    case 5:
        if(map[b+1][a-1]==-2 || map[b+1][a-1]==-1){
        map[b+1][a-1]=map[b][a];
        map[b][a]=-2;
        positions[i][j][0]=a-1;
        positions[i][j][1]=b+1;
        count++;}
        break;
    case 6:
        if(map[b][a-1]==-2 || map[b][a-1]==-1){
        map[b][a-1]=map[b][a];
        map[b][a]=-2;
        positions[i][j][0]=a-1;
        positions[i][j][1]=b;
        count++;}
        break;
    case 7:
        if(map[b-1][a-1]==-2 || map[b-1][a-1]==-1){
        map[b-1][a-1]=map[b][a];
        map[b][a]=-2;
        positions[i][j][0]=a-1;
        positions[i][j][1]=b-1;
        count++;}
        break;
    case 8:
        break;
    }

}
///checks if game is over or not
void end(int a, int b, int x, int y, int row,int column){
    if(a==x && b==y){
        myprint(row, column);
        printf("GAME OVER :(\n");
        printf("Number of thief moves:%d  Number of policemen moves:%d \n", t_count, count);
        exit(0);
    }
}
///moving the thief
void t_move(int x, int y, int row, int column){
    x=thief[0];
    y=thief[1];
    map[y][x]=-2;
    time_t t =time(NULL);
    srand(t);
    int p,xx,yy;
    xx=x;
    yy=y;
    ///conditions are for checking where the thief is
    if (x!=0 && y!=0 && x!=(column-1) && y!=(row-1)){
            p=rand()%9;
            switch (p){
                case 0:
                    yy--;
                    break;
                case 1:
                    xx++;
                    yy--;
                    break;
                case 2:
                    xx++;
                    break;
                case 3:
                    xx++;
                    yy++;
                    break;
                case 4:
                    yy++;
                    break;
                case 5:
                    xx--;
                    yy++;
                    break;
                case 6:
                    xx--;
                    break;
                case 7:
                    xx--;
                    yy--;
                    break;
                case 8:
                    break;
                }

    }
    if (x==0){
            if (y!=0 && y!=(row-1)){
            p=rand()%6;
            switch(p){
            case 0:
                yy--;
                break;
            case 1:
                xx++;
                yy--;
                break;
            case 2:
                xx++;
                break;
            case 3:
                xx++;
                yy++;
                break;
            case 4:
                yy++;
                break;
            case 5:
                break;}

        }
        else {
            p=rand()%4;
            if (y==0){
                switch(p){
                case 0:
                    xx++;
                    break;
                case 1:
                    xx++;
                    yy++;
                    break;
                case 2:
                    yy++;
                    break;
                case 3:
                    break;}
                    }
            if (y==(row-1)){
                switch (p){
                    case 0:
                        xx++;
                        break;
                    case 1:
                        xx++;
                        yy--;
                        break;
                    case 2:
                        yy--;
                        break;
                    case 3:
                        break;}
                        }
            }

            }
    if (x==(column-1)){
        if (y!=0 && y!=(row-1)){
            p=rand()%6;
            switch (p){
            case 0:
                yy--;
                break;
            case 1:
                xx--;
                yy--;
                break;
            case 2:
                xx--;
                break;
            case 3:
                xx--;
                yy++;
                break;
            case 4:
                yy++;
                break;
            case 5:
                break;}
            }
        else{
            p=rand()%4;
            if (y==0){
                switch (p){
                case 0:
                    xx--;
                    break;
                case 1:
                    xx--;
                    yy++;
                    break;
                case 2:
                    yy++;
                    break;
                case 3:
                    break;}
                    }
            if (y==(row-1)){
                switch (p){
                    case 0:
                        yy--;
                        break;
                    case 1:
                        xx--;
                        yy--;
                        break;
                    case 2:
                        xx--;
                        break;
                    case 3:
                        break;}

                        }
            }
    }
    if (x!=0 && x!= (column-1)){
        p=rand()%6;
        if (y==0){
            switch (p){
            case 0:
                xx++;
                break;
            case 1:
                xx++;
                yy++;
                break;
            case 2:
                yy++;
                break;
            case 3:
                xx--;
                yy++;
                break;
            case 4:
                xx--;
                break;
            case 5:
                break;}
                }
        if (y==(row-1)){
            switch (p){
            case 0:
                xx--;
                break;
            case 1:
                xx--;
                yy--;
                break;
            case 2:
                yy--;
                break;
            case 3:
                xx++;
                yy--;
                break;
            case 4:
                xx++;
                break;
            case 5:
                break;}
                }
    }
    if (xx!=x || yy!=y) ///means that the thief has moved
        t_count++;
    x=xx;
    y=yy;
    map[y][x]=-1;
    thief[0]=x;
    thief[1]=y;
    }

int main()
{
    ///displaying screen
    system("color 72");
    int timee=0; ///shows time
    int row, column;
    srand(time(NULL));
    printf("WELCOME to the Cops and Robber game :)\n\n");
    sleep(3);
    system("cls");
    printf("Please enter rows and columns for the game board. \n");
    scanf("%d%d", &row,&column);
    system("cls");
    int ii,jj;
    for (ii=0; ii<row; ii++){
        for (jj=0; jj<column; jj++){
            map[ii][jj]=-2;
            }
    }
    ///first location of thief
    thief[0]=xloc(column);
    thief[1]=yloc(row);
    map[thief[1]][thief[0]]=-1;
    printf("Please enter the number of police stations.\n");
    int stations;
    scanf("%d", &stations);
    system("cls");
    int sheriff[stations];///keeps the number or policemen in each station
    printf("Please enter the number of policemen in each station. NOTICE: total number of policemen must be less than %d\n", row*column-1 );
    int w, h, policemen,a,b;
    ///locating policemen in map
    for (w=0; w<stations; w++){
        scanf("%d", &policemen);
        sheriff[w]=policemen;
        for (h=0; h<policemen; h++){
            a=xloc(column);
            b=yloc(row);
            while (map[b][a]!=-2){
                a=xloc(column);
                b=yloc(row);
                }
            map[b][a]=w;
            positions[w][h][0]=a;
            positions[w][h][1]=b;
            }
    }
    system("cls");
    printf("\nThe game board is:\n");
    myprint(row,column);
    while (1){
    printf("\nnow thief moves: \n");
    t_move(thief[0],thief[1],row,column);
    myprint(row,column);
    printf("\nnow police move: \n");
    int i,j, check, jj, qq;
    int flag=0;
    for(i=0; i<stations; i++){
        for (j=0; j<sheriff[i]; j++){
            flag= seen(positions[i][j][0], positions[i][j][1],thief[0],thief[1]);
            if (flag!=-1){
                star=1;
                break;}
        }
        if(star==1){
            for (jj=0; jj<sheriff[i]; jj++){
                move(positions[i][jj][0],positions[i][jj][1],thief[0],thief[1],i,jj,row,column);
                end(positions[i][jj][0],positions[i][jj][1],thief[0],thief[1],row,column);
                }
        }
        else{
            for (qq=0; qq<sheriff[i]; qq++){
                rand_move(positions[i][qq][0],positions[i][qq][1],i,qq,row,column);
                end(positions[i][qq][0],positions[i][qq][1],thief[0],thief[1],row,column);
                }
        }
    printf("\n");
    star=0;
   }
    timee++;
    sleep(2);
    myprint(row, column);
    }
    return 0;
}
