from flask import Flask, render_template
from flask_socketio import SocketIO
import serial
import time

app = Flask(__name__)
socketio = SocketIO(app)

ser = None

try:
    ser = serial.Serial('COM6', 9600)
    ser.write('1'.encode())
    time.sleep(0.2)
    ser.write('0'.encode())
    time.sleep(0.2)
    ser.write('1'.encode())
    time.sleep(0.2)
    ser.write('0'.encode())
    time.sleep(0.2)
except serial.SerialException as e:
    print("Error opening serial port:", e)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/mercurio')
def mercurio():
    return render_template('mercurio.html')

@app.route('/venus')
def venus():
    return render_template('venus.html')

@app.route('/terra')
def terra():
    return render_template('terra.html')

@app.route('/marte')
def marte():
    return render_template('marte.html')

@app.route('/jupiter')
def jupiter():
    return render_template('jupiter.html')

@app.route('/saturno')
def saturno():
    return render_template('saturno.html')

@app.route('/urano')
def urano():
    return render_template('urano.html')

@app.route('/netuno')
def netuno():
    return render_template('netuno.html')

@socketio.on('comando_arduino')
def handle_comando_arduino(comando):
    print(comando)
    if comando == 'ligar':
        ser.write('1'.encode())
    if comando == 'desligar':
        ser.write('0'.encode())
    time.sleep(2) 
    print(comando)

if __name__ == '__main__':
    socketio.run(app, debug=True)
    if ser:
        ser.close()
