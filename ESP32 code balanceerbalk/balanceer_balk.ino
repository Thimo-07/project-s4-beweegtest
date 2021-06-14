/*
main code for the "balance beam" for the "beweegtest"
created on: april 13th
created by: Thimo Meeusen
last edited on: may 18th
last edited by: Thimo Meeusen                                   
*/

#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <Arduino.h>
#include "config.hpp"
#include "mqtt.hpp"
#include "sensorread.hpp"
#include "balk_test.hpp"


char mqtt_SSID[] = "MobielThimo";
char mqtt_pasword[] = "Bookshelf";
char mqtt_topic[] = "balanceerbalk/balk_1";
char mqtt_server[] = "192.168.146.209";
char mqtt_client_name[] = "balanceertest";
int send_flag= 0;

// SSID and password used for the softap setup by the raspberry pi for mqtt


mqtt_handler mqtt_object(mqtt_SSID, mqtt_pasword, mqtt_server, mqtt_topic);
balk_test test;

void setup() {
  Serial.begin(115200);
  pinMode(15, OUTPUT);
  digitalWrite(15, LOW);
  test.start();
}


void loop() {
  //Serial.println("test1");
  if(!mqtt_object.check_connected()){
    mqtt_object.reconnect("Balktest1");
  }
  //Serial.println("test2");
  mqtt_object.pollmessage();
  delay(1000);
  if(test.run()){
    //Serial.println("test");
  }
  if((test.get_score() != -1) && send_flag==0){
    mqtt_object.Publish_score(test.get_score(), mqtt_topic);
    send_flag= 1;
  }
}
