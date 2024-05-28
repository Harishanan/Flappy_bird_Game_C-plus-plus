#include <iostream>
#include <cstdlib>          //importing the C++ standard library to rand() and system(cls)
#include <windows.h>        //importing the windows header file to sleep()
#include <conio.h>          //importing the console input and output header files for console inputs (_kbhit())

using namespace std;

//dipaly console is considered as double dimension array
char s[31][21];                                //variable for storing screen particles (pixels)
int c[31][21];                                 //variable for checking screen pixels
int key = 0, t = 0;                            //initialising the input check and time
int x, y;                                      //initialsing screen x and y coordinates
int birdx, birdy;   //initialising bird parameters
int highscore, score = 0;                      //initailising variable regarding scoreboard


void playgame();

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;             // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);

}

class Screen {
private:
    int x, y;

public:
    void homescreen() {
        system("cls");              // Clears system console from the previos displayed console
        cout << "" << endl;
        cout << " ********************************************************** " << endl;
        cout << "*                                                         * " << endl;
        cout << "*   **** *    **** **** **** *   *    ***  * ***  ***     * " << endl;
        cout << "*   *    *    *  * *  * *  * *   *    *  * * *  * *  *    * " << endl;
        cout << "*   ***  *    **** **** **** *****    ***  * ***  *  *    * " << endl;
        cout << "*   *    *    *  * *    *      *      *  * * *  * *  *    * " << endl;
        cout << "*   *    **** *  * *    *      *      ***  * *  * ***     * " << endl;
        cout << "*                                                         * " << endl;
        cout << " **********************************************************  " << endl;
        cout << "" << endl << endl;
        cout << "                      High Score:  " << highscore << endl << endl;
        cout << "" << endl << endl;
        cout << "                         M E N U:    " << endl << endl;
        cout << "                     [A] Start Game  " << endl << endl;
        cout << "                     [B] Instruction " << endl << endl;
        cout << "                     [C] Game Info   " << endl << endl;
        cout << "                     [D] Exit        " << endl << endl;
    }

public:
    void gamescreen()               //function to display the game screen in console
    {
        system("cls");              //clears console
        for (y = 0; y < 21; y++)    //Prints the game console with x and y coordinates, showed in void playgame()
        {
            for (x = 0; x < 31; x++)
            {
                if (x < 30)
                {
                    cout << s[x][y];                //print the stored pipe and holes
                }
                if (x == 30)
                {
                    cout << s[x][y] << endl;        //print the stored ground
                }
            }
        }
        cout << "Pass ON" << endl;
        cout << "Hooray, You are on the right direction" << endl;
        cout << "Your Score: " << score << endl;    //prints score, calculated from void scorecalculator()
    }

public:
    void endscreen() {
        gamescreen();   //this one pops up if game ends
        cout << "" << endl << endl;
        cout << " ************************************************************************ " << endl;
        cout << "*    *****      *     *       * ******       ****  *       ****** ****    *" << endl;
        cout << "*   *          * *    * *   * * *           *    *  *     * *     *   *   *" << endl;
        cout << "*   *  ****   *   *   *  * *  * *****       *    *   *   *  ****  ****    *" << endl;
        cout << "*   *  *  *  *******  *   *   * *           *    *    * *   *     * *     *" << endl;
        cout << "*    *****  *       * *       * ******       ****      *    ***** *   *   *" << endl;
        cout << " ************************************************************************* " << endl;
        cout << "" << endl << endl;
        cout << "                        Y O U R   S C O R E : " << score << endl << endl;
        cout << "                        H I G H   S C O R E : " << highscore << endl;
        cout << "" << endl << endl;
    }
};




class gamesupport {
private:
    char opt;

public:
    void gameInformation()
    {
        char opt;
        system("cls");
        while (1)
        {
            cout << "" << endl << endl;
            cout << "        Programmers: Harishanan, Fikayo             " << endl << endl;
            cout << "         Computer Engineering , Year 2              " << endl << endl;
            cout << "            Module : ELEE - 1147                    " << endl << endl;
            cout << "       Designed for ELEE-1147 Course work           " << endl << endl;

            cout << "Want to go back? [y/n]  ";
            cin >> opt;
            if (opt == 'y')
            {
                return;
            }
            if (opt == 'n')
            {
                system("cls");
            }
        }
    }

public:
    void instruction()
    {
        system("cls");
        while (1)
        {
            cout << "" << endl << endl;
            cout << "       Controls: Press the enter key to make the bird fly.              " << endl << endl;
            cout << " Target: Fly through the holes with size of 4 pixel between the pipes.  " << endl << endl;
            cout << "         If you passed a pipe successfully, you earn one point.         " << endl << endl;
            cout << "              Try to make the bird fly longer as you can.               " << endl << endl;
            cout << "         Watchout! bird does not like pipes in the journey.             " << endl << endl;
            cout << "            Bird is even scared to the upper limit and ground.          " << endl << endl;
            cout << "                    Are you ready? Start!                               " << endl << endl;
            cout << "                      Be the champion!!!                                " << endl << endl;
            cout << "Want to go back? [y/n]  ";
            cin >> opt;
            if (opt == 'y')
            {
                return;
            }
            if (opt == 'n')
            {
                system("cls");
            }
        }
    }
};




class menuSelection {
private:
    char sel;

public:
    void showmenu()
    {
        gamesupport support1;
        Screen screen1;
        screen1.homescreen();       //calling menu function
        cin >> sel;                 //input the selection number
        switch (sel)                //menu selections
        {
        case 'A':           //Selecting to play game
        {
            playgame();                 //calling the function to play
            break;
        }
        case 'B':           //Selecting to look instruction
        {
            support1.instruction();     //calling the function to display instruction
            break;
        }
        case 'C':           //Selecting to look game credits
        {
            support1.gameInformation(); //calling the function to display credits
            break;
        }
        case 'D':           //Selecting to exit the game
        {
            cout << "I quit.";          //stops game, app closes.
            exit(0);
            break;
        }
        }
    }
};




class Pipes {

private:
    int x, y, h;                        //Intialising coordinates of console and pipe hole

public:
    void pipeMove() {
        //Creating pipes with hole
        if (t == 12)                    //Time=12 create a new pipe
        {
            for (y = 0; y < 20; y++)    //Create the pipes above y=20, At 20 ground is printed, shown in the void playgame()
            {
                s[30][y] = '|';         //Setting pipes  
                c[30][y] = 2;           //Assigning value as 2 for those pixels  
            }

            h = (rand() % 11) + 5;      //Creates pipe hole using rand function. Hole will place between y=5 to y=15
            s[30][h - 1] = ' ';         //Setting holes, created 4 holes
            s[30][h] = ' ';
            s[30][h + 1] = ' ';
            s[30][h + 2] = ' ';
            c[30][h - 1] = 0;          //Assigning value as 0 for those holes
            c[30][h] = 0;
            c[30][h + 1] = 0;
            c[30][h + 2] = 0;
            t = 0;                    //Setting the time back to 0.
        }

        //Moving the pipes leftwards and stop printing the pipes in the left end screen
        for (y = 0; y < 20; y++)            //Creating console interface, to find pipe coordinates
        {
            for (x = 0; x < 31; x++)
            {
                if (s[x][y] == '|')         //if pipe found in the co-ordinate
                {                           //Yes
                    //Moving the pipes to leftwards
                    if (x > 0)              //If the pipe is not in the left end screen,
                    {
                        s[x - 1][y] = '|';  //moving the pipes to left by 1 pixel
                        c[x - 1][y] = 2;    //assigning value as 1 for those coordinates
                        s[x][y] = ' ';      //making the old co-ordinates as empty
                        c[x][y] = 0;        //assigning value as 0 for the old coordinates  
                    }
                    //Stop printing the pipes in the left end screen
                    if (x == 0)             //If the pipe comes to the left end screen,
                    {
                        s[x][y] = ' ';      //make the pipes disappear
                        c[x][y] = 0;        //assign the value 0 for the coordinates
                    }
                }
            }
        }
    }
};




class Bird {
private:
    int birdt, birdx1, birdx2;

public:
    void birdMove()                                 //function for bird flying
    {

        //When key pressed bird flys up
        if (key > 0)                            //If key is pressed
        {
            birdt = 0;                          //Pressed the key, bird time will be zero
            for (y = 0; y < 20; y++)            //Creating console interface, to find bird's coordinates
            {
                for (x = 0; x < 31; x++)
                {
                    if ((s[x][y] == '*') && (s[x + 1][y] = '*') && (s[x + 2][y] = '0'))         //if bird find in a coordinate
                    {
                        if (y > 0)             //Check the y coordinate is above zero. y=0 is the top horizontol of the screen
                        {                      //Yes
                            s[x][y - 1] = '*'; //bird moves up by 1;
                            s[x + 1][y - 1] = '*';
                            s[x + 2][y - 1] = '0';
                            s[x][y] = ' ';     //replace the bird with empty space
                            s[x + 1][y] = ' ';
                            s[x + 2][y] = ' ';
                            birdx = x;         //Set birdx is similar to the old x coordinate
                            birdx1 = x + 1;
                            birdx2 = x + 1;
                            birdy = y - 1;     //Set the new y coordinate to birdy coordinate
                            return;            //returns to playgame() function
                        }
                    }
                }
            }
        }

        //When key is not pressed bird falls down differing the time
        else                                    //If key is not pressed
        {
            birdt++;                            //Increment bird time, when enter did not press
            for (y = 0; y < 20; y++)            //Creating console interface, to find bird's coordinates
            {
                for (x = 0; x < 31; x++)
                {
                    if ((s[x][y] == '*') && (s[x + 1][y] = '*') && (s[x + 2][y] = '0'))         //if bird find in a coordinate
                    {
                        if (y < 20)             //If y coordinate is over the ground, y=20 ground is printed
                        {                       //Yes
                            //Option 1
                            if (birdt < 3)      //if enter did not press until birdt get 1 or 2 values
                            {                   //It falls by one pixel
                                s[x][y + 1] = '*';  //bird falls down by 1
                                s[x + 1][y + 1] = '*';
                                s[x + 2][y + 1] = '0';
                                s[x][y] = ' ';      //replace bird old coordinate by empty space
                                s[x + 1][y] = ' ';
                                s[x + 2][y] = ' ';
                                birdx = x;          //birdx is similar to the old x coordinate
                                birdx1 = x + 1;
                                birdx2 = x + 2;
                                birdy = y + 1;      //Set the new y coordinate to birdy coordinate
                                return;             //returns to playgame() function
                            }



                            //Option 2
                            else if (birdt >= 3 && birdt < 5)  //if enter did not press until birdt get 3 or 4 values
                            {                                   //It falls by two pixel
                                s[x][y + 2] = '*';              //bird falls down by 2
                                s[x + 1][y + 2] = '*';
                                s[x + 2][y + 2] = '0';
                                s[x][y] = ' ';                  //replace bird old coordinate by empty space
                                s[x + 1][y] = ' ';
                                s[x + 2][y] = ' ';
                                birdx = x;                      //birdx is similar to the old x coordinate
                                birdx1 = x + 1;
                                birdx2 = x + 2;
                                birdy = y + 2;                  //Set the new y coordinate to birdy coordinate
                                return;                         //returns to playgame() function
                            }



                            //Option 3
                            else if (birdt >= 5)    //if enter did not press until birdt get more than or equal to value of 5
                            {                                   //It falls by three pixel
                                s[x][y + 3] = '*';              //bird falls down by 3
                                s[x + 1][y + 3] = '*';
                                s[x + 2][y + 3] = '0';
                                s[x][y] = ' ';                  //replace bird old coordinate by empty space
                                s[x + 1][y] = ' ';
                                s[x + 2][y] = ' ';
                                birdx = x;                      //birdx is similar to the old x coordinate
                                birdx1 = x + 1;
                                birdx2 = x + 2;
                                birdy = y + 3;                  //Set the new y coordinate to birdy coordinate
                                return;                         //returns to playgame() function
                            }
                        }

                        else                     //If bird touched the ground already
                        {
                            return;             //return to playgame() function and it finsihes the game by showing endscreen
                        }
                    }
                }
            }
        }
    }
};




class gameFeatures {
    // method to calculate score
public:
    void gamescore()                   //calculating the score
    {
        for (int y = 0; y < 20; y++)   //printing the rows in a coloumn  
        {
            if (c[birdx][y] == 2)      //Checking the bird's tail is in the same column of pipe. Tells bird passing through the pipe hole
            {
                score = score + 1;     //Yes, increase the score by 1.
                return;
            }
        }
    }

    // method to decide the game levels
public:
    void gamelevels()                       //function to incresase difficulty in the game realte with time
    {
        if (score <= 10)                    //When score is less than or equal to 5
        {
            Sleep(200);                     //Game run in less speed, by delaying 200ms in the game      
        }
        if ((score > 10) && (score <= 15))  //When score is greater than 10 and less than or equal to 15
        {
            Sleep(150);                     //Game run speed increase by 50
        }
        if ((score > 15) && (score <= 20))  //When score is greater than 10 and less than or equal to 15
        {
            Sleep(120);                     //Game run speed increase by 30
        }
        if (score > 20)                     //When score is greater than 20
        {
            Sleep(100);                     //Game run speed increase by 20 and will be in constant forever
        }
    }

    //method to over the game
public:
    bool gameover()                 //Checking bird hits with the pipe or ground and erase the errors
    {
        // Option 1 of failing the game
        if (birdy > 19)            //Checking the bird hits ground (ground is printerd in y=20), showed in void game(), If yes
        {                          //To prvent the error between bird and ground hitting points
            s[birdx][19] = '*';    //Print the bird on the hit ground point
            s[birdx + 1][19] = '*';
            s[birdx + 2][19] = '0';
            s[birdx][20] = '-';    //Print the ground in the before same coordinate
            s[birdx + 1][20] = '-';
            s[birdx + 2][20] = '-';
            return true;           //Returning the boolean value true to over the game
        }


        // Option 2 of failing the game
        if (birdy == 0)            //Checking the bird touches the sky limit(sky limit is in y=0), If yes
        {                          //To prvent the error between bird and sky hitting points
            s[birdx][19] = '*';    //Print the bird on the ground in the same birdx line
            s[birdx + 1][19] = '*';
            s[birdx + 2][19] = '0';
            s[birdx][0] = ' ';
            s[birdx + 1][0] = ' ';
            s[birdx + 2][0] = ' ';
            return true;           //Returning the boolean value true to over the game
        }


        // Option 3.1 of failing the game
        if (c[birdx + 2][birdy] == 2)   //Checking the bird's head hits pipe (pipes' position have value of 2), showed in void pipe(), If yes
        {                               //To prvent the error between bird and ground hitting points
            s[birdx + 1][19] = '0';
            s[birdx][19] = '*';             //Print the bird before the pipe coordinate but on the ground
            s[birdx - 1][19] = '*';
            s[birdx][birdy] = ' ';
            s[birdx + 1][birdy] = ' ';
            s[birdx + 2][birdy] = '|';      //Print the pipe in the old same coordinate
            s[birdx + 2][birdy - 1] = '|';  //Just derived from try and run error
            return true;                    //Returning the boolean value true to over the game
        }


        // Option 3.2 of failing the game
        if (c[birdx + 1][birdy] == 2)    //Checking the bird's body hits pipe (pipes' position have value of 2), showed in void pipe(), If yes
        {                               //To prvent the error between bird and ground hitting points
            s[birdx][19] = '0';         //Print the bird before the pipe coordinate but on the ground
            s[birdx - 1][19] = '*';
            s[birdx - 2][19] = '*';
            s[birdx][birdy] = ' ';
            s[birdx + 1][birdy] = '|';  //Print the pipe in the old same coordinate
            s[birdx + 2][birdy] = ' ';
            return true;                //Returning the boolean value true to over the game
        }


        // Option 3.3 of failing the game
        if (c[birdx][birdy] == 2)        //Checking the bird's tail hits pipe (pipes' position have value of 2), showed in void pipe(), If yes
        {                               //To prvent the error between bird and ground hitting points
            s[birdx - 1][19] = '0';     //Print the bird before the pipe coordinate but on the ground
            s[birdx - 2][19] = '*';
            s[birdx - 3][19] = '*';
            s[birdx][birdy] = '|';      //Print the pipe in the old same coordinate
            s[birdx + 1][birdy] = ' ';
            s[birdx + 2][birdy] = ' ';
            return true;                //Returning the boolean value true to over the game
        }


        // If did not fail, the gameplay continues
        else {
            return false;           //Returning the boolean value false continues the game
        }

    }
};




void playgame()                     //function for playing game
{
    ShowConsoleCursor(false);
    Pipes pipe1;                    //calling the object from Pipes class
    Screen screen1;                 //calling the object from Screen class, to display game screen and end screen
    Bird bird1;                     //calling the object from Bird class
    gameFeatures Features1;

    for (y = 0; y < 21; y++)        //set the screen positions with ground first, then
    {
        for (x = 0; x < 31; x++)
        {
            if (y < 20)             //Levae space above y=20 to print the pipes, shown in the above Pipes class method
            {
                s[x][y] = ' ';
                c[x][y] = 0;
            }
            if (y == 20)            //Print the gound when y coordinate values get 20
            {
                s[x][y] = '-';
                c[x][y] = 2;
            }
        }
    }

    screen1.gamescreen();           //Display the game screen second,then
    s[10][10] = '*';                //Positioning the bird's tail
    s[11][10] = '*';                //Positioning the bird's body
    s[12][10] = '0';                //Positioning the bird's head

    while (1)                        //loop starts, actual gameplay begins
    {
        Features1.gamelevels();
        t++;                         //this is a variable for storing 'time',or how many times a loop passed

        if (_kbhit()) {              //check a key pressed by player
            char input = cin.get();  //store the key in input variable
            if (input == '\n') {     //check is it an enter key
                key = 1;             //Yes, key equals to one, says bird to fly
            }
            else {                  //if not
                key = 0;            //key gets zero, says bird to fall differing the time
            }
        }


        bird1.birdMove();           //cals bird move function
        Features1.gamescore();      //checks score

        if (Features1.gameover() == true)     //checks if bird hits pipes by calling game function, if yes, game ends
        {
            if (score > highscore)  //check the current score is greater than previous high score
            {
                highscore = score;  //Store the score it as a high score
            }
            screen1.endscreen();    //Shows the endscreen method in the screen class
            return;
        }

        pipe1.pipeMove();
        screen1.gamescreen();

        if (key > 0) key++;         //if key is pressed, bird will fly up 2 times.( key already has 1 and increments get 2)
        if (key == 3) key = 0;      //When key gets 3, key gets value 0 and have to press the enter key
    }
}




int main()
{
    int play = 1;               //intialising and decalring number of play as 1
    char sel;                   //intialising menu selection
    menuSelection menu1;        //intialising object for menuSelection class

    while (1)                   //runs the game until break or return function show up
    {
        score = 0;              //Setting score=0, when starting a new game

        //If playing the game first time in the opened console
        if (play == 1)          //Check play is equal to 1
        {                       //Yes
            menu1.showmenu();   //calling the menu option, if A selected game play begins
        }

        //If want to play more in the same console
        if (play > 1)           //Check play is greater than 1
        {                       //Yes
            cout << "Do you want to play again? [y/n] ";       //ask want to play more
            cin >> sel;             //get the player input
            if (sel == 'y')         //if player wants to play again
            {
                playgame();
            }
            if (sel == 'n')         //if player does not want to play
            {
                menu1.showmenu();   //calling the menu option, if A selected game play begins
            }
        }
        play++;            //Increment by one when game played
    }
}