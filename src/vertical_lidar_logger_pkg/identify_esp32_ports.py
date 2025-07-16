import serial
import time
import glob

def find_esp32_ports():
    ports = glob.glob('/dev/ttyUSB*')
    for port in ports:
        try:
            ser = serial.Serial(port, 115200, timeout=1)
            time.sleep(0.5)  # Give ESP32 time to boot/settle
            ser.reset_input_buffer()

            ser.write(b"m")  # Send char 'm' to get MAC
            time.sleep(0.1)

            response = ser.readline().decode().strip()
            print(f"{port}: {response if response else '(no response)'}")
            ser.close()

        except Exception as e:
            print(f"{port}: Error - {e}")

if __name__ == "__main__":
    find_esp32_ports()