#include <iostream>
using namespace std; 

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define BLUE    "\033[34m"      /* Blue */
#define WHITE   "\033[37m"      /* White */
#define MAGENTA "\033[35m"      /* Magenta */
#define BOLD    "\033[1m"       /*Bold Modifier*/

enum orient {N,E,S,W};

int entryPoint[2] = {1,0};
static orient entryOrient = N;
int grid[6][6] = {
{0, 0, 0, 0, 0, 0},
{0, 1, 1, 1, 0, 0},
{0, 1, 0, 1, 1, 0},
{1, 1, 0, 0, 1, 0},
{0, 1, 0, 0, 1, 1},
{0, 1, 0, 0, 0, 0}
};

class player {
    public:
    int location[2];
    orient orient;

    int moveForward(){

        if(orient == N){
            if(grid[location[0]-1][location[1]] == 1){
                cout << location[0] << endl;
                location[0]--;
                cout << location[0] << endl;
                return 1;
            }else{
                return 0;
            }
        }
        if(orient == E){
            if(grid[location[0]][location[1]+1] == 1){
                location[1]++;
                return 1;
            }else{
                return 0;
            }
        }
        if(orient == S){
            if(grid[location[0]+1][location[1]] == 1){
                location[0]++;
                return 1;
            }else{
                return 0;
            }
        }
        if(orient == W){
            if(grid[location[0]][location[1]-1] == 1){
                location[1]--;
                return 1;
            }else{
                return 0;
            }
        }
        return 0;
    } 

    void turnRight(){
        if(orient == N){
            orient = E;
        }if(orient == E){
            orient = S;
        }if(orient == S){
            orient = W;
        }if(orient == W){
            orient = N;
        }
        
    }
    void turnLeft(){
        if(orient == N){
            orient = W;
        }if(orient == E){
            orient = N;
        }if(orient == S){
            orient = E;
        }if(orient == W){
            orient = S;
        }
        
    }
};
void printGrid(player player);

void playerCommand(player player);

void playerCommand(player player){
    if(player.orient == N){
        if(grid[player.location[0]-1][player.location[1]]){
            cout << "Forward" << endl;
        }
        if(grid[player.location[0]][player.location[1]-1]){
            cout << "Left" << endl;
        }
        if(grid[player.location[0]][player.location[1]+1]){
            cout << "Right" << endl;
        }
        if(grid[player.location[0]+1][player.location[1]]){
            cout << "Backward" << endl;
        }
    }
    char command;
    cin >> command;
    if(command == 'f'){
        player.moveForward();
    }
}

void printGrid(player player)
{
    for(int a=0;a<6;a++){
        for(int b=0;b<6;b++){
            if(a == player.location[0] && b == player.location[1]){
                switch(player.orient){
                    case N:
                        cout << MAGENTA << "N" << RESET;
                    break;
                    case E:
                        cout << MAGENTA << "E" << RESET;   
                    break;
                    case S:
                        cout << MAGENTA << "S" << RESET;
                    break;
                    case W:
                        cout << MAGENTA << "W" << RESET;
                    break;
                }
            }else{
                if(grid[a][b] == 1){
                    cout << GREEN << "0" << RESET;
                }
                if(grid[a][b] == 0){
                    cout << RED << "#" << RESET;
                }
            }
            cout << " ";
        }
    cout << endl;
    }
}
 
int main()
{   
    
    player player1;
    player1.location[0] = 5 ;
    player1.location[1] = 1 ;
    player1.orient = entryOrient;
    
    char q;
    while(q != 'Q'){
        printGrid(player1);
        playerCommand(player1);
        cout << player1.location[0] << endl;
        //cin >> q;
    }
    
    // cout << player1.location[0] << ", " << player1.location[1] << endl;
    // player1.moveForward();
    // cout << player1.location[0] << ", " << player1.location[1] << endl;
    // player1.moveForward();
    // cout << player1.location[0] << ", " << player1.location[1] << endl;
    // player1.turnLeft();
    // player1.moveForward();
    // cout << player1.location[0] << ", " << player1.location[1] << endl;                              
}