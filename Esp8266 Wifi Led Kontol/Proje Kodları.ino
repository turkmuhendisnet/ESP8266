#include <ESP8266WiFi.h>

void LED_CHANGE();

// LED FET AYARI
#define ledPIN    0

int led_parlaklik = 0;
#define time_at_colour 1200 
unsigned long TIME_LED = 0;
int LED; 
int LED_A = 0;

// WiFi AYARI
const char *ssid =  "ali";   // Buraya kendi bağlanacağınız wifi ağının adı yazılacak
const char *pass =  "12345678"; // Burayada onun şifresi

//  WiFi Server Başlangıç
WiFiServer server(80);

void setup()
{
  
  pinMode(ledPIN, OUTPUT); 
  
  // Konsol Ayarı
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.println();

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("BAGLANAMADI\n");
  }
  Serial.println("");
  Serial.println("WiFi BAGLANDI");
  Serial.println("IP ADRESİ: ");
  Serial.println(WiFi.localIP());
  
  Serial.println("");
  
  server.begin();
  Serial.println("WEBSERVER BASLATILDI");
  
}

void loop()
{
  // Veri bağlantısı kontrol edildi
  WiFiClient client = server.available();
  if (client) {
    
      // isteğin ilk satırı okunuyor
      String istek = client.readStringUntil('\r');
      Serial.println(istek);
      client.flush();
    
      // Web sayfasına yazılıyor
      String s = "HTTP/1.1 200 OK\r\n";
      s += "Content-Type: text/html\r\n\r\n";
      s += "<!DOCTYPE HTML>\r\n<html>\r\n";
      s += "<h1>LED Kontrolü</h1>";
      s += "<form action=\"/\" method=\"GET\" class=\"rgbkontrol\">";
      s += "<label for=\"led\">Led Değeri: </label><input type=\"text\" name=\"led\"><br />";
      s += "<p></p>";
      s += "<input type=\"submit\" value=\"OK\">";
      s += "<p></p>";
      s += "</form>";
      if((istek.indexOf("/?led=") != -1)) { // bilgi kontrol ediliyor
         
        // bilignin değeri
        int pos = istek.length();
        int ind1 = istek.indexOf("/?led=") + 6;
        String teststring = istek.substring(ind1, pos);
        int ind2 = teststring.indexOf('/');
        String ledDeger = istek.substring(ind1, ind2+ind1);
        
        int ledSonucDeger = map(ledDeger.toInt(),0,100,0,1023);
        LED = constrain(ledSonucDeger,0,1023);
        
        int diff_led = abs(LED-LED_A);
        if(diff_led > 0){
          led_parlaklik = time_at_colour / abs(LED-LED_A); 
        }else{
          led_parlaklik = time_at_colour / 100; 
        }
        
        // veri geiliyor
        s += "LED yeni değeri";
        s += ledDeger;
      
      }
      
      s += "<br>";
      s += "İstek Tamamlandı!";
      
      s += "</html>\n";
     
      client.flush();
    
      // cevap gönderiliyor
      client.print(s);
      //delay(1);
      Serial.println("Client Bağlantısı Kapatıldı");
    
      // cevap bağlantısı kesiliyor
      
  }
  
  if(millis() - TIME_LED >= led_parlaklik){
    TIME_LED = millis();
    LED_CHANGE();
  }
  
}

void LED_CHANGE()
{
  if(LED != LED_A){
    if(LED_A > LED) LED_A = LED_A - 1;
    if(LED_A < LED) LED_A++;
    analogWrite(ledPIN, LED_A);
  }
}
