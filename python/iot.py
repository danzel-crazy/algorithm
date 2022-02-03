import drivers
from time import sleep
import adafruit_dht
import board
import time
import RPi.GPIO as GPIO

display = drivers.Lcd()

dht_device = adafruit_dht.DHT22(board.D18, use_pulseio = False)

GPIO.setwarnings(False)

GPIO.setup(26, GPIO.IN)         
GPIO.setup(22, GPIO.OUT, initial=GPIO.LOW)
    
try:
    while True:
        GPIO.output(22, GPIO.LOW)
        i=GPIO.input(26)
        print("Writing to display")
        try:
            humidity= dht_device.humidity
            temperature = dht_device.temperature
        except(RuntimeError):
            print("no new data this loop!")

        if humidity is not None and temperature is not None:
            display.lcd_display_string("Temp={0:0.2f}*C".format(temperature), 1)
            display.lcd_display_string("Humidity="+str(humidity)+"%", 2)
        else:
            print("Failed to retrieve data from HDT22 sensor")
        if i==0:                 
            display.lcd_display_string ("No intruders " +str(i), 3)
            GPIO.output(22, GPIO.LOW)  
        elif i==1:               
            display.lcd_display_string ("Intruders detected! " +str(i), 3)
            GPIO.output(22, GPIO.HIGH)  
        display.lcd_display_string("I am a display!", 4)     
        sleep(1) 
        GPIO.output(22,GPIO.LOW)                                 
        display.lcd_clear()
        sleep(2)                                           
except KeyboardInterrupt:
    print("Cleaning up!")
    GPIO.output(22,GPIO.LOW)
    display.lcd_clear()



