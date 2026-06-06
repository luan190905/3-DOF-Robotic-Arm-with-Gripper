#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

// ===== WIFI =====
const char* ssid = "ESP32-ARM";
const char* password = "12345678";

WebServer server(80);

// ===== SERVO =====
Servo baseServo, forwardServo, upDownServo, gripServo;

// ===== GÓC KHỞI TẠO =====
int basePos = 78;
int forwardPos = 90;
int upDownPos = 110;
int gripPos = 90;  // bắt đầu giữa

// ===== GIỚI HẠN GRIP =====
int gripMin = 30;   // đóng
int gripMax = 140;  // mở

// ===== KEY =====
bool a,d,w,x,q,r,g,h;
bool freeMode = false;
bool wasFree = false;

// ===== HTML =====
String html = R"rawliteral(
<!DOCTYPE html>
<html>
<body style="text-align:center;font-size:22px;">
<h2>Robot Arm</h2>

<p>A/D: Base | W/X: Forward | Q/R: UpDown</p>
<p>G: Open | H: Close | F: Free</p>

<h3>Angles</h3>
<p>Base: <span id="base">0</span>°</p>
<p>Forward: <span id="forward">0</span>°</p>
<p>UpDown: <span id="updown">0</span>°</p>
<p>Grip: <span id="grip">0</span>°</p>

<script>
let keys={};
document.addEventListener('keydown',(e)=>{keys[e.key]=true;});
document.addEventListener('keyup',(e)=>{keys[e.key]=false;});

setInterval(()=>{
 fetch("/control",{
  method:"POST",
  headers:{"Content-Type":"application/json"},
  body:JSON.stringify(keys)
 });
},100);

setInterval(()=>{
 fetch("/status")
 .then(r=>r.json())
 .then(d=>{
  base.innerText=d.base;
  forward.innerText=d.forward;
  updown.innerText=d.updown;
  grip.innerText=d.grip;
 });
},200);
</script>

</body>
</html>
)rawliteral";

// ===== HANDLER =====
void handleRoot(){ server.send(200,"text/html",html); }

void handleStatus(){
  String json="{";
  json+="\"base\":"+String(basePos)+",";
  json+="\"forward\":"+String(forwardPos)+",";
  json+="\"updown\":"+String(upDownPos)+",";
  json+="\"grip\":"+String(gripPos);
  json+="}";
  server.send(200,"application/json",json);
}

void handleControl(){
  if(server.hasArg("plain")){
    String body=server.arg("plain");

    a = body.indexOf("\"a\":true")!=-1;
    d = body.indexOf("\"d\":true")!=-1;
    w = body.indexOf("\"w\":true")!=-1;
    x = body.indexOf("\"x\":true")!=-1;
    q = body.indexOf("\"q\":true")!=-1;
    r = body.indexOf("\"r\":true")!=-1;
    g = body.indexOf("\"g\":true")!=-1;
    h = body.indexOf("\"h\":true")!=-1;

    if(body.indexOf("\"f\":true")!=-1){
      freeMode = !freeMode;
    }
  }
  server.send(200,"text/plain","OK");
}

// ===== SETUP =====
void setup(){
  WiFi.softAP(ssid,password);

  baseServo.attach(33);
  forwardServo.attach(32);
  upDownServo.attach(25);
  gripServo.attach(26);

  baseServo.write(basePos);
  forwardServo.write(forwardPos);
  upDownServo.write(upDownPos);
  gripServo.write(gripPos);

  delay(500);

  server.on("/",handleRoot);
  server.on("/status",handleStatus);
  server.on("/control",HTTP_POST,handleControl);

  server.begin();
}

// ===== LOOP =====
void loop(){
  server.handleClient();

  // ===== FREE MODE =====
  if(freeMode){
    baseServo.detach();
    forwardServo.detach();
    upDownServo.detach();
    gripServo.detach();
    wasFree = true;
    delay(20);
    return;
  }

  // ===== THOÁT FREE MODE =====
  if(wasFree){
    baseServo.attach(5);
    forwardServo.attach(18);
    upDownServo.attach(19);
    gripServo.attach(21);

    delay(300);

    basePos = 78;
    forwardPos = 90;
    upDownPos = 100;
    gripPos = 90;

    wasFree = false;
  }

  // ===== ĐIỀU KHIỂN =====
  if(a) basePos -= 2;
  if(d) basePos += 2;

  if(w) forwardPos += 2;
  if(x) forwardPos -= 2;

  if(q) upDownPos += 2;
  if(r) upDownPos -= 2;

  // ===== GRIP =====
  if(g && gripPos < gripMax) gripPos += 2;  // mở
  if(h && gripPos > gripMin) gripPos -= 2;  // đóng

  // ===== GIỚI HẠN =====
  basePos = constrain(basePos,0,180);
  forwardPos = constrain(forwardPos,30,120);
  upDownPos = constrain(upDownPos,40,150);
  gripPos = constrain(gripPos,gripMin,gripMax);

  // ===== GHI =====
  baseServo.write(basePos);
  forwardServo.write(forwardPos);
  upDownServo.write(upDownPos);
  gripServo.write(gripPos);

  delay(20);
}