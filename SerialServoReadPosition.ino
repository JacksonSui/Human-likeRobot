#include <SoftwareSerial.h>
#include "LobotSerialServo.h"

//实例化软串口
SoftwareSerial mySerial(2, 3); // RX, TX
int pos[10];
const int initPos[17] = {535, 597, 796, 309, 430, 632, 554, 85, 573, 510, 474, 381, 659, 530, 678, 331, 457};
const int rightTiltPos[17] = {470, 597, 796, 309, 430, 632, 554, 85, 573, 510, 474, 381, 659, 530, 678, 331, 457};
const int rightUpPos[17] = {470 , 597, 796, 309, 430, 632, 554, 85, 440, 510, 474, 381, 659, 530, 678, 331, 457};
const int rightDown1Pos[17] = {495, 498, 796, 309,430, 586, 586, 85, 440, 510, 474, 381, 659, 530, 675, 331, 457};
const int rightDown2Pos[17] = {508, 498, 796, 229, 430, 603, 625, 85, 467, 510, 474, 381, 659, 530, 678, 331, 457};
void robotInit(){
  for(int i = 0; i < 17; i++){
      LobotSerialServoMove(Serial, i+1, initPos[i], 200);
  }
}

void walk(){
  for(int i = 0; i < 17; i++){
          LobotSerialServoMove(Serial, i+1, rightTiltPos[i], 400);
  }
  delay(1000);
  for(int i = 0; i < 17; i++){
          LobotSerialServoMove(Serial, i+1, rightUpPos[i], 400);
  }
  delay(1000);
  for(int i = 0; i < 17; i++){
          LobotSerialServoMove(Serial, i+1, rightDown1Pos[i], 600);
  }
  delay(1000);
  for(int i = 0; i < 17; i++){
          LobotSerialServoMove(Serial, i+1, rightDown2Pos[i], 400);
  }
  delay(500);
}

void Read(){
    for(int i = 0; i < 17; i++){
      pos[i] = LobotSerialServoReadPosition(Serial, i+1);
      String ts = " ";
      ts.concat(pos[i]);
      mySerial.print(ts);
    }
}

void unload(){
  for(int i = 0; i < 17; i++){
    LobotSerialServoUnload(Serial, i+1);
  }
}

void setup(){
  mySerial.begin(9600);
  Serial.begin(115200);
  delay(1000);
  Read();
  delay(1000);
  robotInit();
  delay(1000); 
  walk();
  delay(10000);
  unload();
}

void loop(){
//  Serial.println("aa123132");
  Read();
   mySerial.println("333 ");
  delay(1000);
}




