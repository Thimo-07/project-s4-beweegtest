/*
implementation code for the mqtt connection
created on: may 18th
created by: Thimo Meeusen
last edited on: may 18th
last edited by: Thimo Meeusen                                   
*/

#include "mqtt.hpp"
char received_command = '0';

void mqtt_handler::pollmessage(){
  mqtt_client->loop();
}

void mqtt_handler::callback(char* topic, byte* message, unsigned int length){
  received_command = (char)message[0];
}

mqtt_handler::mqtt_handler(char *ssid, char *password, char *mqtt_server, char *topic){
  wifi_client = new WiFiClient;
  mqtt_client = new PubSubClient(*wifi_client);

  current_ssid = ssid;
  current_password = password;
  current_topic = topic;

  WiFi.begin(ssid, password);
  mqtt_client->setServer(mqtt_server, 1883);
  mqtt_client->setCallback(callback);
  mqtt_client->subscribe(topic, 0);
}

mqtt_handler::~mqtt_handler(){
  delete wifi_client;
  delete mqtt_client;
}

void mqtt_handler::reconnect(char *client_name){
  // Loop until we're reconnected
  WiFi.disconnect();
  WiFi.begin(current_ssid, current_password);
  while (!mqtt_client->connected()) {
    
    // Attempt to connect
    if (mqtt_client->connect(client_name)) {
      // Subscribe
      mqtt_client->subscribe(current_topic);
    } 
    else {
      Serial.print(mqtt_client->state());
      delay(5000);
    }
  }
}

void mqtt_handler::Publish_score(int score, char topic[]){
  char message[4];
  itoa(score, message, 10);
  mqtt_client->publish(topic,message);
}

bool mqtt_handler::check_connected(){
  return mqtt_client->connected();
}


char mqtt_handler::get_received_command(){
  char ret = received_command;
  received_command = no_command;
  return ret;
}
