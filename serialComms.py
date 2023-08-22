import time
import serial
import threading	

ser = serial.Serial(
	port='/dev/ttyACM0', 
	baudrate=115200, 
	#parity=serial.PARITY_NONE,
	#stopbits=serial.STOPBITS_ONE,
	#bytesize=serial.EIGHTBITS
)

ser.isOpen()
active = True

def readDevice():
	out = b''
	while active:
		time.sleep(0.05)
		while ser.inWaiting() > 0:
			out += ser.read(1)
		if out != b'':
			try:
				rawOut = out.decode("utf-8")
				#out = rawOut[rawOut.find(_input):rawOut.rfind(">")]
				print(rawOut)
			except:
				print("Failed to parse")
			out = b''


print('Enter your commands below.\r\nInsert "exit" to leave the application.')
ser.reset_input_buffer()

thread_device_read = threading.Timer(0, readDevice)
thread_device_read.daemon = True
thread_device_read.start()

_input=''
while True :
	_input = input(">> ")
	if (_input == 'exit'):
		active = False
		ser.close()
		exit()
	elif (_input == 'break'):
		ser.send_break()
		continue
	else:
		buffer = _input
		#print(buffer)
		ser.write(buffer.encode())