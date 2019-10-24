# ESP8266 Led Dimmer Uygulaması
## Amaç ve Hedef 
Bu proje elektronik cihazın wifi modülü üzerinden kontrolünü sağlamaktır. Bu kontrol, wifi modülü  ESP8266nın çıkışına 
bağlı olan elektronik cihazın gücünü kontrol etmektir.Projenin hedefi elektronik cihazların uzak mesafelerden kontrolünü sağlamaktır. 
Gündelik hayatı kolaylaştırmaktır.

## Çalışma Prensibi
Devreye adaptörden gelen 12V LM2596 gerilim regülatörü ile 3.3V’a düşürülerek ESP8266nın çalışması sağlanır. ESP8266 çalışmaya 
başladıktan sonra telefon üzerinden açılmmış wifi hotspota otomatik olarak bağlanır.  Bağlı olduğu telefon üzerinden görülen 
ESP8266nın ıp adresi uygulamaya yazılarak bağlantı tamamlanmış olur. Uygulama üzerinden gönderilen veriyi ESP8266 işleyerek 
çıkışına verir. Çıkıştan alınan sinyal, L7805C beslemesi ile çalışan IR2112 sinyali güçlendirerek  IRFZ44N tetiklenmesini 
sağlar, IRFZ44N mosfet de sinyali anahtarlama yaparak power ledin parlaklığı ayarlanır.

## Malzemeler 
**LM2596 :**    Adaptörden gelen 12 V gerilimi espnin çalışma gerilimi olan 3.3 V yapar.

**L7805C :**    IR2112 sürücünün  5V sabit beslemesini  verir.

**ESP8266 :**   Bu modül devre ile telefonun bağlantısını sağlar.

**IR2112 :**    Esp8266nın çıkışındaki sinyali güçlendirir
.
**IRFZ44N :**   IR2112nin pwm sinyalini anahtarlama yapar.

## Devre Tasarımı
Devrenin Proteus ISIS'te çizilmiş hali
![Devre Tasarımı](https://github.com/turkmuhendisnet/ESP8266/blob/master/Devre%20Tasarımı.png)

## Devre Baskı Çıktısı
![Baskı Çıktısı](https://github.com/turkmuhendisnet/ESP8266/blob/master/Devre%20PCB%20Çıktısı.png)

## Proje Telefon Uygulaması
Uygulamanın telefon arayüzü
  Ip giriniz kısmına ESP8266’nın ıp adresi yazılarak bağlantı sağlanır. Sliderdan ledin parlaklığı ayarlanır.

![Telefon Uygulaması](https://github.com/turkmuhendisnet/ESP8266/blob/master/Proje%20Telefon%20Uygulaması.png)

## Proje Son Hali
![Proje Son Hali](https://github.com/turkmuhendisnet/ESP8266/blob/master/Proje%20Görüntüsü.png)

