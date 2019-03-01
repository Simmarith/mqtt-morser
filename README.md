# MQTT Morser

this programm just sends messages to an mqtt server if wires are shorted. You can however extend it to your needs pretty easily.

## Setup

- Make sure you have a Wifi and an MQTT server (I'd go for [mosquitto](https://mosquitto.org/)) at hand
- Change the variables on the top if you need to (spoiler: you'll probably need to change most of them). You shouldn’t touch 'isDown' though, as that’ll break the code.
- Short a wire between D4(unless configured otherwise) and ground
- See the messages roll in!

## Customization

You can, if you want to, make it do other things as well! The functions 'onKeyDown' and 'onKeyUp' are called when the electrical connection is made/undone. You can add just about any code that you want to here. Knock yourself out :D
