/*
definitons and prototypes for the mqtt connection
created on: may 18th
created by: Thimo Meeusen
last edited on: may 18th
last edited by: Thimo Meeusen                                   
*/

#ifndef mqtt_H
#define mqtt_H

#include <PubSubClient.h>
#include <WiFi.h>

#define start_command 'S'
#define quit_command 'Q'
#define no_command '0'

class mqtt_handler{
  private:
  WiFiClient *wifi_client;
  PubSubClient *mqtt_client;
  static void callback(char* topic, byte* message, unsigned int length); 
  
  //static char received_command;
  char *current_ssid;
  char *current_password;
  char *current_topic;

  public:
  mqtt_handler(char *ssid, char *password, char *mqtt_server, char *topic);
  ~mqtt_handler();
  void pollmessage();
  void reconnect(char *client_name);
  void Publish_score(int score, char topic[]);
  char get_received_command();
  bool check_connected();
};




#endif //mqtt_H 
