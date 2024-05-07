from flask import Flask, render_template
import serial, time

app = Flask(__name__)

ser = None
# ser = serial.Serial('COM3')
# time.sleep()

# def write_read(com):
#     ser.write(bytes(com, 'utf-8'))
#     time.sleep(0.5)
#     print(str(ser.read())[2:-1], 'arduino')

'''
0 - desligar
1 - mercurio
2 - venus
3 - terra
4 - marte
5 - jupiter
6 - saturno
7 - urano
8 - netuno
'''

@app.route('/')
def index():
    print('0')
    return render_template('index.html')

@app.route('/mercurio')
def mercurio():
    print('1')
    return render_template('mercurio.html')

@app.route('/venus')
def venus():
    print('2')
    return render_template('venus.html')

@app.route('/terra')
def terra():
    print('3')
    return render_template('terra.html')

@app.route('/marte')
def marte():
    print('4')
    return render_template('marte.html')

@app.route('/jupiter')
def jupiter():
    print('5')
    return render_template('jupiter.html')

@app.route('/saturno')
def saturno():
    print('6')
    return render_template('saturno.html')

@app.route('/urano')
def urano():
    print('7')
    return render_template('urano.html')

@app.route('/netuno')
def netuno():
    print('8')
    return render_template('netuno.html')

if __name__ == '__main__':
    app.run()
    