#include <ESP32Servo.h>

Servo baseServo, forwardServo, upDownServo, gripServo;

// ===== HOME =====
int baseHome = 88;
int forwardHome = 46;
int upDownHome = 138;
int gripHome = 70;

// ===== CURRENT =====
int baseNow = 90;
int forwardNow = 90;
int upDownNow = 90;
int gripNow = 90;

// ===== STATE =====
bool pathToggle = false; // false = hướng 1, true = hướng 2

int speedDelay = 10;

// ===== MOVE MƯỢT =====
void moveSmooth(Servo &s, int &current, int target) {
  while (current != target) {
    if (current < target) current++;
    else current--;

    s.write(current);
    delay(speedDelay);
  }
  delay(400);
}

// ===== VỀ HOME =====
void goHome() {
  moveSmooth(baseServo, baseNow, baseHome);
  moveSmooth(forwardServo, forwardNow, forwardHome);
  moveSmooth(upDownServo, upDownNow, upDownHome);
  moveSmooth(gripServo, gripNow, gripHome);
}

void setup() {
  delay(3000); // chỉnh tay trước

  baseServo.attach(33);
  forwardServo.attach(32);
  upDownServo.attach(25);
  gripServo.attach(26);

  delay(300);

  goHome(); // về vị trí ban đầu mượt
}

void loop() {

  // ===== CHUỖI CHUNG =====
  moveSmooth(forwardServo, forwardNow, 84);

  moveSmooth(upDownServo, upDownNow, 100);

  moveSmooth(gripServo, gripNow, 114);

  // ===== RẼ NHÁNH =====
  if (!pathToggle) {
    // ===== HƯỚNG 1 =====
    moveSmooth(baseServo, baseNow, 144);
    moveSmooth(gripServo, gripNow, 92);
  } else {
    // ===== HƯỚNG 2 =====
    moveSmooth(baseServo, baseNow, 178);
    moveSmooth(forwardServo, forwardNow, 70);
    moveSmooth(gripServo, gripNow, 92);
  }

  // ===== QUAY VỀ BAN ĐẦU =====
  moveSmooth(upDownServo, upDownNow, 108);
  goHome();

  // đổi hướng cho lần sau
  pathToggle = !pathToggle;

  delay(10000); // nghỉ 10s
}