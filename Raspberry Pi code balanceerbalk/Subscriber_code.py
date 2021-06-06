import paho.mqtt.client as mqtt

def on_connect(client, userdata, flags, rc):
	print("Connected with result code"+str(rc))
	client.subscribe("test/message")

def on_message(client, userdata, msg):
	data = msg.payload.decode()
	file = open("test.txt", 'a')
	file.write(data +'\n")
	file.close

client = mqtt.Client()
client.connect("192.168.4.1",1883,60)

client.on_connect = on_connect
client.on_message = on_message

client.loop_forever()