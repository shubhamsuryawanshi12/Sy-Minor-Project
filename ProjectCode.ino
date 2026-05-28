#include <SoftwareSerial.h>
#include <NewPing.h>

#define enA 10 // Enable1 L298 Pin enA 
#define in1 9  // Motor1  L298 Pin in1 
#define in2 8  // Motor1  L298 Pin in2 
#define in3 7  // Motor2  L298 Pin in3 
#define in4 6  // Motor2  L298 Pin in4 
#define enB 5  // Enable2 L298 Pin enB 

#define TRIG_PIN A2  // Ultrasonic sensor trigger pin
#define ECHO_PIN A3  // Ultrasonic sensor echo pin
#define MAX_DISTANCE 200 // Maximum distance to detect obstacles
#define OBSTACLE_THRESHOLD 25 // Obstacle detection threshold in cm
#define MOTOR_SPEED 80 // Motor speed (0-255)

#define R_S A0    // IR sensor Right
#define L_S A1    // IR sensor Left
#define SERVO_PIN A4

SoftwareSerial BT(0, 1); // RX, TX for Bluetooth module
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
char command;
int mode = 0; // 0 - Bluetooth Control, 1 - Obstacle Avoidance, 2 - Line Following
bool stopFlag = false;

int distance_L, distance_F = 30, distance_R;
long distance;
int set = 20;

void setup(){
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(R_S, INPUT);
    pinMode(L_S, INPUT);
    pinMode(SERVO_PIN, OUTPUT);
    
    Serial.begin(9600);
    BT.begin(9600);
    
    analogWrite(enA, MOTOR_SPEED);
    analogWrite(enB, MOTOR_SPEED);
    resetServo();
    delay(500);
}

void loop(){  
    if (BT.available()) {
        command = BT.read();
        if (command == 'S') { // Stop command received
            mode = 0;
            stopFlag = true;
            Stop();
            Serial.println("Stopped");
        } else {
            stopFlag = false;
            executeCommand(command);
        }
    }
    
    if (mode == 1 && !stopFlag) {  // Obstacle avoidance mode only if not stopped
        distance_F = Ultrasonic_read();
        Serial.print("Front Distance: "); Serial.println(distance_F);

        if (distance_F > set) {
            forward();
        } else {
            Stop();
            delay(500);
            backward();
            delay(500);
            Stop();
            Check_side();
        }
    }
    
    if (mode == 2 && !stopFlag) {  // Line following mode only if not stopped
        lineFollowing();
    }
    delay(10);
}

void lineFollowing() {
    int rightSensor = digitalRead(R_S);
    int leftSensor = digitalRead(L_S);

    Serial.print("Right Sensor: ");
    Serial.print(rightSensor);
    Serial.print("  Left Sensor: ");
    Serial.println(leftSensor);

    if (rightSensor == 0 && leftSensor == 0) {
        forward();
    }
    else if (rightSensor == 1 && leftSensor == 0) {
        turnRight();
    }
    else if (rightSensor == 0 && leftSensor == 1) {
        turnLeft();
    }
    else {
        Stop();
    }
}

long Ultrasonic_read(){
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    distance = pulseIn(ECHO_PIN, HIGH);
    return distance / 29 / 2;
}

void compareDistance(){
    if (distance_L > distance_R){
        turnRight();
        delay(350);
    } else if (distance_R > distance_L){
        turnLeft();
        delay(350);
    } else {
        backward();
        delay(300);
        turnRight();
        delay(600);
    }
    Stop();
    forward();
}

void Check_side(){
    distance_L = getDistanceAtAngle(140);
    delay(100);
    distance_R = getDistanceAtAngle(0);
    delay(100);
    resetServo(); 

    Serial.print("Left: "); Serial.print(distance_L);
    Serial.print(" | Right: "); Serial.println(distance_R);

    compareDistance();
}

int getDistanceAtAngle(int angle){
    servoPulse(SERVO_PIN, angle);
    delay(300);
    return Ultrasonic_read();
}

void resetServo(){
    servoPulse(SERVO_PIN, 70);
    delay(300);
}

void servoPulse(int pin, int angle){
    int pwm = (angle * 11) + 500;
    digitalWrite(pin, HIGH);
    delayMicroseconds(pwm);
    digitalWrite(pin, LOW);
    delay(50);
}

void forward(){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

void backward(){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

void turnRight(){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

void turnLeft(){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

void Stop(){
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}

void executeCommand(char cmd) {
    switch (cmd) {
        case 'P': mode = 1; stopFlag = false; Serial.println("Obstacle Avoidance Mode"); break;
        case 'Q': mode = 2; stopFlag = false; Serial.println("Line Following Mode"); break;
        case 'T': mode = 0; stopFlag = false; Serial.println("Bluetooth Control Mode"); break;
        case 'F': if (mode == 0) forward(); break;
        case 'B': if (mode == 0) backward(); break;
        case 'L': if (mode == 0) turnRight(); break;
        case 'R': if (mode == 0) turnLeft(); break;
        case 'S': mode = 0; stopFlag = true; Stop(); Serial.println("Stopped"); break;
        default: break;
    }
}