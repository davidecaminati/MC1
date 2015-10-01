import RPi.GPIO as GPIO  
GPIO.setmode(GPIO.BCM)  # set up BCM GPIO numbering  
GPIO.setup(25, GPIO.IN) # set GPIO 25 as input  