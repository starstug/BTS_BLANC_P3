#include <WiFiS3.h>
#include <WiFiUdp.h>

// ---------- WIFI ----------
char ssid[] = "iPhone";
char pass[] = "btsciel1";
int status = WL_IDLE_STATUS;

// ---------- UDP ----------
WiFiUDP udp;
const int localPort = 1234;   // Port sur lequel le serveur écoute

char packetBuffer[255];      // Buffer pour stocker le message reçu


void setup() {

  Serial.begin(9600);
  while (!Serial);

  // Connexion WiFi
  while (status != WL_CONNECTED) {
    Serial.print("Connexion au WiFi : ");
    Serial.println(ssid);

    status = WiFi.begin(ssid, pass);
    delay(5000);
  }

  Serial.println("✅ WiFi connecté !");
  Serial.print("Adresse IP du serveur : ");
  Serial.println(WiFi.localIP());

  // Démarrage du serveur UDP
  udp.begin(localPort);
  Serial.print("✅ Serveur UDP en écoute sur le port ");
  Serial.println(localPort);
}


void loop() {

  // Vérifie si un paquet UDP est reçu
  int packetSize = udp.parsePacket();

  if (packetSize) {

    Serial.println("📩 Message UDP reçu !");

    // Lire le paquet reçu
    int len = udp.read(packetBuffer, 255);

    if (len > 0) {
      packetBuffer[len] = '\0'; // Fin de chaîne
    }

    // Affichage
    Serial.print("Message : ");
    Serial.println(packetBuffer);

    Serial.print("Depuis IP : ");
    Serial.println(udp.remoteIP());

    Serial.print("Port client : ");
    Serial.println(udp.remotePort());

    Serial.println("------------------------");
  }
}
