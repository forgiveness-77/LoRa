# LoRa Chat with RH_RF95

A simple Arduino-based serial chat application using the RH_RF95 LoRa module. It allows two devices to communicate wirelessly over LoRa at 950 MHz using the serial monitor.

## 📡 Features

- Real-time two-way communication via LoRa
- Serial interface for sending/receiving messages
- Displays message content and RSSI (signal strength)

## 🧰 Hardware Requirements

- Arduino board (e.g., Uno, Nano)
- LoRa module (e.g., RFM95)
- Jumper wires
- USB cable

## 🔌 Wiring (default pins)

| Module Pin | Arduino Pin |
|------------|-------------|
| CS         | 8           |
| RST        | 4           |
| INT        | 7           |

> Adjust the pin definitions in the code if using a different board.

## 📦 Libraries Required

Make sure to install the following libraries via the **Arduino Library Manager**:

- [RadioHead](http://www.airspayce.com/mikem/arduino/RadioHead/)
- **Adafruit BusIO** (dependency required by some Adafruit drivers)

> Go to **Sketch > Include Library > Manage Libraries**, then search for and install:
> - "RadioHead"
> - "Adafruit BusIO"

## 🚀 How to Use

1. Upload the code to two Arduino boards with LoRa modules.
2. Open the Serial Monitor on both (baud rate: 115200).
3. Type a message in one and press Enter to send.
4. The other board will receive and display it with RSSI info.

## ⚙️ Frequency

Set to `950.0 MHz`. Modify `#define RF95_FREQ` if your region uses a different frequency (e.g., 868 MHz, 915 MHz).

## 📝 License

This project is open source and free to use for educational and non-commercial purposes.
