import serial
import serial.tools.list_ports
import time

def get_mac_from_port(port, retries=3):
    try:
        with serial.Serial(port, 115200, timeout=1) as ser:
            time.sleep(0.5)  # Let the ESP32 stabilize
            ser.reset_input_buffer()
            ser.reset_output_buffer()

            for attempt in range(retries):
                ser.write(b'm')  # No newline — ESP32 reads one byte
                time.sleep(0.2)
                response = ser.readline().decode(errors='ignore').strip()

                if response and len(response.split(':')) == 6:
                    return response

            return None  # Nothing valid received after all retries
    except Exception:
        return None


def find_esp32_ports():
    """
    Scans all /dev/ttyUSB* ports for ESP32 devices and returns a mapping:
    {mac_address: port_path}
    """
    mac_to_port = {}
    ports = serial.tools.list_ports.comports()
    
    for port_info in ports:
        if 'USB' in port_info.device:
            mac = get_mac_from_port(port_info.device)
            if mac:
                mac_to_port[mac] = port_info.device
                
    return mac_to_port

if __name__ == '__main__':
    esp32_devices = find_esp32_ports()
    
    for mac, port in esp32_devices.items():
        print(f"MAC {mac} => {port}")

    # Example use-case for a known ESP32 (Tilt/Pan)
    TILT_PAN_MAC = "00:00:00:00:00:01"
    
    if TILT_PAN_MAC in esp32_devices:
        tilt_pan_port = esp32_devices[TILT_PAN_MAC]
        print(f"Tilt/Pan camera should use port: {tilt_pan_port}")
    else:
        print("Tilt/Pan ESP32 not found!")
