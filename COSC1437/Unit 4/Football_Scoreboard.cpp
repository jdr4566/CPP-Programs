/*  Programmer : John-David Rodriguez
    Course: COSC-1437
    Date: 11/15/2021
    IDE: Microsoft Visual Studio
    Description:   Your objective is to create C++ program that keeps track of various objects and variables in a Football Scoreboard.

*/


#include <iostream>
#include "Input_Validation_Extended.h"			//for input validation
using namespace std;



class Team                          //create a class for Team
{
    private:
        string name;               //name of team
        string Coach_Name;         // Coach name
        string Home_City;          //Home city name
        bool Home_Status;          //Home or visitor status
        int Score;                 //variable for score
        int Timeout_Count;         //keep track of timeouts
    public:
        Team()                      //Default Constructor
        {
            name = "team";
            Coach_Name = "Dr_t";
            Home_City = "Fort Worth";
            Home_Status = "True";
            Score = 0;
            Timeout_Count = 0;
        }
        Team(string n, string ch, string hc, bool hs, int sc, int tc)
        {
            name = n;
            Coach_Name = ch;
            Home_City = hc;
            Home_Status = hs;
            Score = sc;
            Timeout_Count = tc;
        }

        void setName(string n) { name = n; }                                        //Setters and getters!!
        void setCoachName(string ch) { Coach_Name = ch; }
        void setHomeCity(string hc) { Home_City = hc; }
        void setHomeStatus(bool hs) { Home_Status = hs; }
        void setScore(int sc) { Score = sc; }
        void setTimeoutCount(int tc) { Timeout_Count = tc; }
        string getName() const { return name; }
        string getCoachName()const { return Coach_Name; }
        string getHomeCity()const { return Home_City; }
        bool getHomeStatus()const { return Home_Status; }
        int getScore()const { return Score; }
        int getTimeoutCount()const { return Timeout_Count; }

};      






class Scoreboard                    //create a scoreboard class
{
private:
    bool Home_Status;       // Home or visitor status
    int quarter;            //what quarter is game in
    int time;          //current game time
    bool Ball_Status;       //who has the ball
    int down;               //What down is it?
    int togo;               //how many yards to 1st down?
    int team1score;         //team 1 score
    int team2score;         //team 2 score


public:
    Scoreboard()        //default constructor
    {
        Home_Status = "false";
        quarter = 0;
        Ball_Status = "false";
        down = 1;
        togo = 10;
        time = 1500;
        team1score = 0;
        team2score = 0;
    }
    Scoreboard(bool hs, int q, bool bs, int d, int tg, int t,int t1s, int t2s)
    {
        Home_Status = hs;
        quarter = q;
        Ball_Status = bs;
        down = q;
        togo = tg;
        time = t;
        team1score = t1s;
        team2score = t2s;

    }       
       
    //setters and getters
    void setHomeStatus(bool hs) { Home_Status = hs; }
    void setQuarter(int q) { quarter = q; }
    void setTime(int t) { time = t; }
    void setBallStatus(bool bs) { Ball_Status = bs; }
    void setDown(int d) { down = d; }
    void setTogo(int tg){ togo = tg; }
    void setT1S(int t1s) { team1score = t1s; }
    void setT2S(int t2s) { team2score = t2s; }
    bool getHomeStatus() const { return Home_Status; }
    int getQuarter() const { return quarter; }
    int getTime()  { return time; }
    bool getBallStatus() const { return Ball_Status; }
    int getDown() const { return down; }
    int getTogo() const { return togo; }
    int getT1S() const { return team1score; }
    int getT2S() const { return team2score; }

};




int main() {

    //local variables for Team 1
    string nameLocal = "Dallas Cowboys";
    string CoachLocal = "Dr_t";
    string HomeCLocal = "Fort Worth";
    bool HomeStatusLocal = "true";
    int scoreLocal = 0;
    int timeoutLocal = 0;

    //local variables for Team 2
    string name2Local = "";
    string Coach2Local = "";
    string Home2CLocal = "";
    bool HomeStatus2Local = "false";
    int score2Local = 0;
    int timeout2Local = 0;



    //local varibles for Scoareboard
    bool HomeSLocal = "false";
    int QuarterLocal = 1;
    int TimeLocal = 1500;
    bool BallStatusLocal = "false";
    int downLocal = 1;
    int togoLocal = 10;
    int t1sLocal = 0;
    int t2sLocal = 0;
   





    Team t0(nameLocal, CoachLocal, HomeCLocal, HomeStatusLocal, scoreLocal, timeoutLocal);                   //create first instance


    cout << "Default Team Info is as follows: " << endl;
    cout << "Team name : " << t0.getName() << endl;
    cout << "Coach name: " << t0.getCoachName() << endl;
    cout << "Home City: " << t0.getHomeCity() << endl;
    cout << "Home Status: " << t0.getHomeStatus() << endl;
    cout << "Score: " << t0.getScore() << endl;
    cout << "Timeout Count: " << t0.getTimeoutCount() << endl;


    //get input from user and create team 1
    cout << "\n\n\nPlease enter Team 1 Name: " << endl;
    nameLocal = validateString(nameLocal);
    cout << "Please enter Coach Name: " << endl;
    CoachLocal = validateString(CoachLocal);
    cout << "Please enter Home City: " << endl;
    HomeCLocal = validateString(HomeCLocal);
    cout << "Visitor or Home? : (0 for visitor or 1 for home)";
    cin >> HomeStatusLocal;
    cout << "Please enter current score: " << endl;
    scoreLocal = validateInt(scoreLocal);
    cout << "Finally Enter a timeout count: " << endl;
    timeoutLocal = validateInt(timeoutLocal);



    //get input from user and create team 2
    cout << "\n\n\nPlease enter Team 2 Name: " << endl;
    name2Local = validateString(name2Local);
    cout << "Please Enter Coach 2 Name: " << endl;
    Coach2Local = validateString(Coach2Local);
    cout << "Please enter Home City for Team 2 : " << endl;
    Home2CLocal = validateString(Home2CLocal);
    cout << "Visitor or home? : (0 for visitor or 1 for home)";
    cin >> HomeStatus2Local;
    cout << "Please enter Team 2 current score: " << endl;
    score2Local = validateInt(score2Local);
    cout << "Finally Enter Team 2 Timeout count: " << endl;
    timeout2Local = validateInt(timeout2Local);


    Team t1(nameLocal, CoachLocal, HomeCLocal, HomeStatusLocal, scoreLocal, timeoutLocal);      //create team 1 class instance

    Team t2(name2Local, Coach2Local, Home2CLocal, HomeStatus2Local, score2Local, timeout2Local); //create team 2 class instance


    //team 1 info

    cout << "\n\n\nTeam 1 Info is as follows: " << endl;
    cout << "Team name : " << t1.getName() << endl;
    cout << "Coach name: " << t1.getCoachName() << endl;
    cout << "Home City: " << t1.getHomeCity() << endl;
    cout << "Home Status: " << t1.getHomeStatus() << endl;
    cout << "Score: " << t1.getScore() << endl;
    cout << "Timeout Count: " << t1.getTimeoutCount() << endl;



    //team2 info 
    cout << "\n\n\nTeam 2 Info is as follows: " << endl;
    cout << "Team name : " << t2.getName() << endl;
    cout << "Coach name: " << t2.getCoachName() << endl;
    cout << "Home City: " << t2.getHomeCity() << endl;
    cout << "Home Status: " << t2.getHomeStatus() << endl;
    cout << "Score: " << t2.getScore() << endl;
    cout << "Timeout Count: " << t2.getTimeoutCount() << endl;


    //Start Scoreboard

    Scoreboard s0(HomeSLocal, QuarterLocal, TimeLocal, BallStatusLocal, downLocal, togoLocal, t1sLocal, t2sLocal);          //create instance 0 to show defualt values zeroed out

    //display values initialized to zero
    cout << "\n\n\nTime for ScoreBoard!!" << endl;
    cout << "Current Default Values: " << endl;
    cout << "Home Status : " << s0.getHomeStatus() << endl;
    cout << "Quarter : " << s0.getQuarter() << endl;
    cout << "Time : " << s0.getTime() << endl;
    cout << "Ball Status: " << s0.getBallStatus() << endl;
    cout << "Down : " << s0.getDown() << endl;
    cout << "To Go : " << s0.getTogo() << endl;
    cout << "Team 1 Score: " << s0.getT1S() << endl;
    cout << "Team 2 Score: " << s0.getT2S() << endl;





    
    
    
        cout << "\n\n\n Scoreboard Values: " << endl;
        cout << "Enter home Status: (0 for visitor or 1 for home)" << endl;
        cin >> HomeSLocal;
        cout << "Enter Current Quarter: " << endl;
        QuarterLocal = validateInt(QuarterLocal);
        cout << "Enter current Game time: " << endl;
        TimeLocal = validateInt(TimeLocal);
        cout << "Enter Ball Status: (0 for visitor or 1 for home)" << endl;
        cin >> BallStatusLocal;
        cout << "Enter Current Down: " << endl;
        downLocal = validateInt(downLocal);
        cout << "Enter To Go value : " << endl;
        togoLocal = validateInt(togoLocal);
        cout << "Enter Team 1 Score: " << endl;
        t1sLocal = validateInt(t1sLocal);
        cout << "Enter Team 2 Score: " << endl;
        t2sLocal = validateInt(t2sLocal);


        Scoreboard s1(HomeSLocal, QuarterLocal, TimeLocal, BallStatusLocal, downLocal, togoLocal, t1sLocal, t2sLocal);          //create scoreboard instance s1

        //display s1 values

        cout << "\n\n\nHome Status : " << s1.getHomeStatus() << endl;
        cout << "Quarter : " << s1.getQuarter() << endl;
        cout << "Time : " << s1.getTime() << endl;
        cout << "Ball Status: " << s1.getBallStatus() << endl;
        cout << "Down : " << s1.getDown() << endl;
        cout << "To Go : " << s1.getTogo() << endl;
        cout << "Team 1 Score: " << s1.getT1S() << endl;
        cout << "Team 2 Score: " << s1.getT2S() << endl;
       


       
    
    return 0;
}