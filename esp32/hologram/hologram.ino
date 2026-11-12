// ESP32 Hologram: spinning wireframe cube on a 128x64 OLED,
// mirrored so it reads correctly through a beam-splitting cube.

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <math.h>

// ---- Settings -------------------------------------------------------
#define USE_SH1106 0     // 0 = SSD1306 (0.96"), 1 = SH1106 (many 1.3" modules)
#define OLED_ADDR 0x3C   // try 0x3D if the screen stays blank
const bool MIRROR = true;  // mirror horizontally for the beam-splitter cube

// I2C pins: picked automatically from the board you select in the IDE.
#if defined(CONFIG_IDF_TARGET_ESP32)
  #define SDA_PIN 21
  #define SCL_PIN 22
#else  // ESP32-S3, C3, C6: no fixed I2C pins, change to match your wires
  #define SDA_PIN 8
  #define SCL_PIN 9
#endif
// ---------------------------------------------------------------------

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#if USE_SH1106
  #include <Adafruit_SH110X.h>
  Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
  #define WHITE_PX SH110X_WHITE
#else
  #include <Adafruit_SSD1306.h>
  Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
  #define WHITE_PX SSD1306_WHITE
#endif

const float vertices[8][3] = {
  {-1, -1, -1}, { 1, -1, -1}, { 1,  1, -1}, {-1,  1, -1},
  {-1, -1,  1}, { 1, -1,  1}, { 1,  1,  1}, {-1,  1,  1}
};

const uint8_t edges[12][2] = {
  {0, 1}, {1, 2}, {2, 3}, {3, 0},
  {4, 5}, {5, 6}, {6, 7}, {7, 4},
  {0, 4}, {1, 5}, {2, 6}, {3, 7}
};

float angleX = 0, angleY = 0;

int16_t mx(int16_t x) {
  return MIRROR ? (SCREEN_WIDTH - 1 - x) : x;
}

void drawLineM(int16_t x0, int16_t y0, int16_t x1, int16_t y1) {
  display.drawLine(mx(x0), y0, mx(x1), y1, WHITE_PX);
}

void setup() {
  Wire.begin(SDA_PIN, SCL_PIN);
#if USE_SH1106
  bool ok = display.begin(OLED_ADDR, true);
#else
  bool ok = display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
#endif
  if (!ok) {
    for (;;) delay(1000);  // display not found; check wiring and address
  }
  display.clearDisplay();
  display.display();
}

void loop() {
  int16_t px[8], py[8];
  float cx = cos(angleX), sx = sin(angleX);
  float cy = cos(angleY), sy = sin(angleY);

  for (uint8_t i = 0; i < 8; i++) {
    float x = vertices[i][0], y = vertices[i][1], z = vertices[i][2];

    float y1 = y * cx - z * sx;   // rotate around X
    float z1 = y * sx + z * cx;
    float x2 = x * cy + z1 * sy;  // rotate around Y
    float z2 = -x * sy + z1 * cy;

    float scale = 60.0 / (z2 + 4.0);  // simple perspective
    px[i] = SCREEN_WIDTH / 2 + (int16_t)(x2 * scale);
    py[i] = SCREEN_HEIGHT / 2 + (int16_t)(y1 * scale);
  }

  display.clearDisplay();
  for (uint8_t e = 0; e < 12; e++) {
    drawLineM(px[edges[e][0]], py[edges[e][0]], px[edges[e][1]], py[edges[e][1]]);
  }
  display.display();

  angleX += 0.03;
  angleY += 0.05;
  delay(16);
}
