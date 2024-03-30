
uint8_t connect_wifi(const char *ssid, const char *pass){
  uint8_t status = WL_IDLE_STATUS;
  while(status != 3){
    status = WiFi.begin(ssid, pass);
    //blink(2, 50);
  }
  //blink(3, 1000);
  return status;
}

