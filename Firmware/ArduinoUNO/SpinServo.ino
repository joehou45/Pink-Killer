#include <Servo.h>

Servo myservo; // 建立一個 servo 物件，最多可建立 12個 servo

int pos = 0; // 設定 Servo 位置的變數
int SpinIntervals = 60 * 20; // 60secs * 20 = 20mins 
int forwardSpeed = 100; //forward delay time(ms)
int BackwardSpeed = 10; //Backward delay time(ms)
void setup() {
  myservo.attach(9); // 將 servo 物件連接到 pin 9
  Serial.begin(9600);
}

void loop() {
  int t= 0; 
  // 
  // 慢慢的轉動, 把螺掃進箱內, 可調整 forwardSpeed , 數字愈大愈慢 
  // pos 從 180 度旋轉到 0 度，每次 1 度
  //
  Serial.println("forward ");
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos); // 告訴 servo 走到 'pos' 的位置
    delay(forwardSpeed); // 等待 100ms 讓 servo 走到指定位置
  }

  //
  // 快速回到掃螺原點, 可調整 BackwardSpeed , 數字愈大愈慢
  // pos 從 0 度旋轉到 180 度，每次 1 度
  //
  Serial.println("Backward ");
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos); // 告訴 servo 走到 'pos' 的位置
    delay(BackwardSpeed); // 等待 10ms 讓 servo 走到指定位置
  }

  //
  // 每來回掃一次的等待時間, 參考SpinIntervals 
  //
  Serial.print("Standby ");
  Serial.print(SpinIntervals);
  Serial.println(" secs");
    
  for (t = 0; t < SpinIntervals; t++) {
    delay(1000); // 1 sec
  }
}
