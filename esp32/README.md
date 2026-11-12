# ESP32 Hologram

An ESP32 drives a small OLED display. A beam-splitting cube sits on top of the display. The cube reflects the image so it looks like it floats inside the glass (a Pepper's ghost effect).

## Hardware

- Microcontroller: ESP32 DevKit (classic ESP32)
- Display: 0.96" OLED, 128x64, SSD1306 driver, I²C
- Optics: beam-splitting cube, about 25 mm, placed on the display face

## Choosing an ESP32

- Classic ESP32: best for beginners and most hobby projects. The wiring below is for this board.
- ESP32-S3: use it if you plan to add AI, a camera module or complex media.
- ESP32-C3 / C6: use it for low cost or newer wireless features (the C6 has Wi-Fi 6).

On the S3, C3 and C6 there are no fixed I²C pins. Choose two free GPIOs and set `SDA_PIN` and `SCL_PIN` in the sketch.

## Wiring

| OLED pin | ESP32 pin |
| --- | --- |
| VCC | 3.3V |
| GND | GND |
| SDA | GPIO 21 |
| SCL | GPIO 22 |

## Libraries

Install these from the Arduino Library Manager:

- `Adafruit SSD1306`
- `Adafruit GFX Library`

## Build and upload

1. In the Arduino IDE, install the ESP32 board package (Boards Manager, search "esp32" by Espressif).
2. Open `hologram/hologram.ino`.
3. Select your board (for example "ESP32 Dev Module") and the serial port.
4. Upload.

If the screen stays blank, change `OLED_ADDR` from `0x3C` to `0x3D`.

## Tips for a good hologram effect

- The cube shows a mirror image. The sketch mirrors everything it draws, so text reads correctly through the glass. Set `MIRROR` to `false` to look at the bare display.
- Keep the background black. Black pixels are invisible in the cube, so only the lit shapes seem to float.
- Use the project in a dim room. The effect is much stronger with little ambient light.
