# Using these to demonstrate Internet Of Things capabilities of the Nanoboard
Before we get started, I seriously do not recommend going this approach as this is not how Internet of Things is commonly implemented. There are other better frameworks and libraries like Blynk that are much easier to use. I did it this way because I like to have customization over the server as well as my things.

However if you wish to go this route. Here is how to run the code.

## Step 1
Make sure you have Python and the library Flask installed. 

## Step 2
Run run.bat in IoT Server. This will run the flask server locally. Meaning any devices connected to the same network as your computer can access the server by visiting the computer's ip address.

## Step 3
Edit the ssid, password, host and port in sketch in Firmware and make sure to have the host as your computer's ip address.

## Step 4
Upload the code into your Nanoboard, make sure you have an LED connected to pin 9, and an esp8266 plug into the nanoboard's socket. 

## Step 5
You can now visit the server via your browser by typing your computer's ip address into the browser url bar and adjust the green slider to adjust the LED's brightness.