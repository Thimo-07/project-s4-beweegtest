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


char mqtt_SSID[] = "RaspberryMarijn";
char mqtt_pasword[] = "thimoisgek";
char mqtt_topic[] = "balanceerbalk/balk_1";
char mqtt_server[] = "192.168.4.1";
char mqtt_client_name[] = "balanceertest";

// SSID and password used for the softap setup by the raspberry pi for mqtt


mqtt_handler mqtt_object(mqtt_SSID, mqtt_pasword, mqtt_server, mqtt_topic);
sensor_read sensor;
int sensor_data[aantal_koperbanen];

void setup() {
  Serial.begin(115200);
  pinMode(15, OUTPUT);
  digitalWrite(15, LOW);
}


void loop() {
  //if(!mqtt_object.check_connected()){
  //  mqtt_object.reconnect("Balktest1");
  //}
  //mqtt_object.pollmessage();
  //Serial.println(mqtt_object.get_received_command());
 sensor.read_data(sensor_data);
  for(int i=0; i < aantal_koperbanen; i++){
    
    Serial.print("koperbaan ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(sensor_data[i]);
  }
  //mqtt_object.Publish_score(8,mqtt_topic);
  delay(2000);
}
