# Buy List (ESP32-C3 build)

Everything you need for the hologram with an ESP32-C3. Each link opens an Amazon search, so you can compare sellers and pick one with good reviews. The links use amazon.com; change the domain (for example amazon.co.uk or amazon.com.au) for your country.

Prices are rough guides only. Check the listing before you buy.

## Required parts

| # | Part | What to look for | Approx. price | Amazon search |
| --- | --- | --- | --- | --- |
| 1 | ESP32-C3 board | "ESP32-C3 SuperMini", USB-C. Packs of 2–5 cost little more than one. | $5–15 | [ESP32-C3 SuperMini](https://www.amazon.com/s?k=ESP32-C3+SuperMini) |
| 2 | OLED display | 128x64, I²C (4 pins), **white** pixels. 0.96" (SSD1306) is the safe default; 1.3" is bigger (often SH1106). | $6–12 | [0.96" white SSD1306](https://www.amazon.com/s?k=0.96+inch+OLED+SSD1306+I2C+white) · [1.3" white](https://www.amazon.com/s?k=1.3+inch+OLED+I2C+128x64+white) |
| 3 | Beam-splitter cube | Glass beam-splitter / "hologram" cube. 25 mm for a 0.96" display, 30 mm for a 1.3" display. | $8–20 | [25 mm](https://www.amazon.com/s?k=beam+splitter+cube+25mm) · [30 mm](https://www.amazon.com/s?k=beam+splitter+cube+30mm) |
| 4 | Breadboard | Half-size (400 points) is enough. | $5–10 | [Half-size breadboard](https://www.amazon.com/s?k=half+size+breadboard+400) |
| 5 | Jumper wires | Male-to-male for a breadboard. Male-to-female if you connect the display directly to the board. | $5–8 | [Jumper wire kit](https://www.amazon.com/s?k=dupont+jumper+wires+kit) |
| 6 | USB-C cable | Must carry **data**, not only power. | $5–10 | [USB-C data cable](https://www.amazon.com/s?k=usb+c+data+cable) |

Estimated total: about $35–75.

## Optional

| Part | Why | Amazon search |
| --- | --- | --- |
| Pre-soldered headers | Many SuperMini boards ship with loose header pins. Buy pre-soldered boards if you have no soldering iron. | [ESP32-C3 SuperMini soldered](https://www.amazon.com/s?k=ESP32-C3+SuperMini+soldered+headers) |
| Soldering iron kit | To solder the header pins. | [Soldering kit](https://www.amazon.com/s?k=soldering+iron+kit+electronics) |
| ESP32-C3 SuperMini with built-in OLED | All-in-one board, but its 0.42" screen is too small for a good hologram. Not recommended. | — |

## Before you buy

- **White, not two-colour.** Many cheap OLEDs are "yellow-blue": the top 16 rows are yellow. White looks best in the cube.
- **I²C, not SPI.** I²C modules have 4 pins (VCC, GND, SCL, SDA). SPI modules have 6–7 pins and need different wiring.
- **Match the cube to the screen.** The cube should cover the lit area of the display. Too small cuts the image; too large shows the board.
- **1.3" display?** Set `USE_SH1106` to `1` in the sketch if the listing says SH1106.

## Wiring

See [wiring-esp32-c3.svg](wiring-esp32-c3.svg).
