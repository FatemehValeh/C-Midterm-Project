#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//x random location
int xloc(int column){
    int x;
    //time_t t=time(NULL);
    //srand(t);
    x=rand()%(column);
    return x;
}
//y random location
int yloc(int row){
    int y;
    //time_t t=time(NULL);
    //srand(t);
    y=rand()%(row);
    return y;
}
void myprint( int row, int column, int map[row][column]){
    int k,l;
    for (k=0; k<row; k++){
        for (l=0; l<column; l++){
            printf("%d ", map[k][l]);
        }
    printf("\n");
     }

}
int check(int a, int b, int x, int y){
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


   /*
   rand_move(int x, int y){
    srand(time(0));
    time_t t=time(NULL);
    int a=rand()%9;
    switch (a){
    case 0:
        y++;
        break;
    case 1:
        x++;
        y++;
        break;
    case 2:
        x++;
        break;
    case 3:
        x--;
        y--;
        break;
    case 4:
        y--;
        break;
    case 5:
        x--;
        y--;
        break;
    case 6:
        x--;
        break;
    case 7:
        x--;
        y++;
        break;
    case 8:
        break;
    }

   }*/


int main()
{   //(1 displaying screen

       int timee=0;
    int row, column;
    int x,y;
    srand(time(NULL));
    printf("Please enter rows and columns :)\n");
    scanf("%d%d", &row,&column);
    int map[row][column];
    int ii,jj;
    for (ii=0; ii<row; ii++){
        for (jj=0; jj<column; jj++)
            map[ii][jj]=-2;
    }
    char matrix[row][column];
    int i,j;
    for (i=0; i<row; i++){
        for (j=0; j<column; j++){
            matrix[i][j]='0';
            ///printf("%c ", matrix[i][j]);
        }
    ///printf("\n");
    }
    //1)
    //allocate first location of thief with T
    x=xloc(column);
    printf("test x %d\n", x);
    y=yloc(row);
    printf("test y %d\n", y);
    matrix[y][x]='T';
    map[y][x]=-1;

    printf("Please enter the number of police stations.\n");
    int stations;
    scanf("%d", &stations);
    int sheriff[stations];
    printf("Please enter the number of policemen in each station.\n");
    int w, h, policemen,a,b, e;
    for (w=0; w<stations; w++){
            scanf("%d", &policemen);
            sheriff[w]=policemen;
            printf("sheriff[%d] is %d\n", w, policemen);

        for (h=0; h<policemen; h++){
                a=xloc(column);
                b=yloc(row);
                printf("a & b are %d %d\n", a , b);
                while (map[b][a]!=-2){
                            a=xloc(column);
                            b=yloc(row);
                            printf("a* & b* are %d & %d\n", a , b);

                }
                map[b][a]=w;
                printf("map [%d][%d] is %d\n", b , a, w);
                printf("check is %d\n", check(a,b,x,y));

            printf("test %c%d\n",'D', w );
        }
        printf("\n");
    }

    myprint(row,column,map);
    timee++;
    sleep(2);
    //system("cls");

    map[y][x]=-2;
    printf("map[%d][%d] is %d\n", y, x, map[y][x]);
    srand(time(0));
    time_t t =time(NULL);
    int p=rand()%9;
    if (x!=0 && y!=0 && x!=column && y!=row){
            switch (p){
                case 0:
                    y++;
                    break;
                case 1:
                    x++;
                    y++;
                    break;
                case 2:
                    x++;
                    break;
                case 3:
                    x--;
                    y--;
                    break;
                case 4:
                    y--;
                    break;
                case 5:
                    x--;
                    y--;
                    break;
                case 6:
                    x--;
                    break;
                case 7:
                    x--;
                    y++;
                    break;
                case 8:
                    break;
                }

    }
    if (x==0){
        if (y==0){
            switch(p){
                case 0:
                    y++;
                    break;
                case 3:
                    x--;
                    y--;
                    break;
                case 4:
                    y--;
                    break;
                case 5:
                    x--;
                    y--;
                    break;

            }
        }
        if (y==row){
            switch (p){
                case 0:
                    y++;
                    break;
                case 1:
                    x++;
                    y++;
                    break;
                case 2:
                    x++;
                    break;
                case 3:
                    x--;
                    y--;
                    break;

            }
        }
    }
        if (x==column){
            if (y==0){
                switch (p){
                case 0:
                    y++;
                    break;

                }

        }




    map[y][x]=-1;
    printf("now map[%d][%d] is %d\n", y, x, map[y][x]);
    myprint(row, column, map);
    /*int k,l;
    for (k=0; k<row; k++){
        for (l=0; l<column; l++){
            printf("%d ", map[k][l]);
        }
    printf("\n");
     }
*/
    return 0;
}
