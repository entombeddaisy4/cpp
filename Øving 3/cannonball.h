/*
    Oppgave 1
*/

//returns static accl y-direction (acceleration due to gravity)
double acclY ();

//returns velocity in Y-direction from initial Y-velocity and time
double velY(double initVelocityY, double time);

//returns x-position from initial position, velocity and time
double posX(double initPosition, double initVelocity, double time);

//returns y-position from initial position, initial velocity and time
double posY(double initPosition, double initVelocity, double time);

//prints the time in a readable format
void printTime(double time);

//returns how long an object will stay in the air from its initial y-velocity, assuming startposition y=0
double flightTime(double initVelocityY);

/*
    Oppgave 4
*/
//gets angle from user and returns value as double
double getUserInputTheta();

//gets absolute value from user and returns value as double
double getUserInputAbsVelocity();

//converts from degrees to radiansw
double degToRad(double deg);

//calculates x-velocity from angle and absolute velocity
double getVelocityX(double theta, double absVelocity);

//calculates y-velocity from angle and absolute velocity
double getVelocityY(double theta, double absVelocity);

//calculates absolute velocity into x and y components given absolute velocity and angle(theta)
vector<double> getVelocityVector(double theta, double absVelocity);

//calculates distance travelled given x and y velocity
double getDistanceTraveled(double velocityX, double velocityY);



//Places a random target from 100 to 1000m away from x=0 and allows the user to choose angle and velocity
//the function then tells the user how far away the player was from hitting and gives you 10 attempts
void playTargetPractice();