#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"
#include "cannonball_viz.h"

/*
    Oppgave 2
*/

//returns static accl y-direction (acceleration due to gravity)
double acclY () {
    return -9.81;
}

//returns velocity in Y-direction from initial Y-velocity and time
double velY(double initVelocityY, double time) {
    double velocity;
    velocity = initVelocityY + acclY() * time;
    return velocity;
}

//returns x-position from initial position, velocity and time
double posX(double initPosition, double initVelocity, double time) {
    double position;
    position = initPosition + initVelocity * time;
    return position;
}

//returns y-position from initial position, initial velocity and time
double posY(double initPosition, double initVelocity, double time) {
    double position;
    position = initPosition + initVelocity * time + (acclY() * time * time) / 2;
    return position;
}

//prints the time in a readable format
void printTime(double time) {
    int hours;
    int minutes;
    int seconds = time;
    minutes = time / 60;
    hours = minutes / 60;
    cout << "Time was " << hours << " hours, " << (minutes % 60) << " minutes, and " << (seconds % 60) << " seconds.";

}

//returns how long an object will stay in the air from its initial y-velocity, assuming startposition y=0
double flightTime(double initVelocityY) {
    double time;
    time = -(2*initVelocityY)/acclY();
    return time;
}


/*
    Oppgave 4
*/

//gets angle from user and returns value as double
double getUserInputTheta() {
    double theta;
    cout << "Input θ [°]: ";
    cin >> theta;
    return theta;
}

//gets absolute value from user and returns value as double
double getUserInputAbsVelocity() {
    double absVelocity;
    cout << "Input absolute velocity: ";
    cin >> absVelocity;
    return absVelocity;
}

//converts from degrees to radians
double degToRad(double deg) {
    double rads;
    rads = (M_PI * deg) / 180;
    return rads;
}

//calculates x-velocity from angle and absolute velocity
double getVelocityX(double theta, double absVelocity) {
    double velX;
    velX = absVelocity * cos(theta);
    return velX;
}

//calculates y-velocity from angle and absolute velocity
double getVelocityY(double theta, double absVelocity) {
    double velY;
    velY = absVelocity * sin(theta);
    return velY;
}

//calculates absolute velocity into x and y components given absolute velocity and angle(theta)
vector<double> getVelocityVector(double theta, double absVelocity) {
    vector<double> velocityVector(2);
    velocityVector[0] = getVelocityX(theta, absVelocity);
    velocityVector[1] = getVelocityY(theta, absVelocity);
    return velocityVector;
}

//calculates distance travelled given x and y velocity
double getDistanceTraveled(double velocityX, double velocityY) {
    double distanceTraveled;
    distanceTraveled = posX(0, velocityX, flightTime(velocityY));
    return distanceTraveled;
}


//Places a random target from 100 to 1000m away from x=0 and allows the user to choose angle and velocity
//the function then tells the user how far away the player was from hitting and gives you 10 attempts
void playTargetPractice() {
    double target = randomWithLimits(100,1000);
    for(int i = 1; i <= 10; i++) {
        double theta = degToRad(getUserInputTheta());
        double absVelocity = getUserInputAbsVelocity();
        vector<double> velocityVector =  getVelocityVector(theta, absVelocity);
        double distanceTraveled = getDistanceTraveled(velocityVector[0], velocityVector[1]);
        cannonBallViz(target, 1000, velocityVector[0], velocityVector[1], 5);
        if (abs(distanceTraveled-target) <= 5) {
            cout << "Congratulations you won!\n";
            return;
        } else {
            cout << "You hit " << abs(target-distanceTraveled) << " meters too ";
            if (target < distanceTraveled) {
                cout << "far.\n";
            } else if (target > distanceTraveled) {
                cout << "short.\n";
            }
        }
    }
    cout << "Sorry! You lost the game\n";
}