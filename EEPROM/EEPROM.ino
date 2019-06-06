#include <EEPROM.h>

void setup()
{
  Serial.begin(9600);

  EEPROM.write(10,150);
  Serial.println(EEPROM.read(10));

  Serial.print("EEPROM Memory: ");
  Serial.println(EEPROM.length());
}

void loop()
{
  //UNO
  //adreslerde 0 - 1023 kadar adresimiz var
  //her adres için 0 - 254 deger arası sayı kayıt edilir
  //EEPROM 100.000 kez yazılıp siline bilinir. 1KB EEPROM
  //Program Flash Memory 10.000 kez yazılıp siline bilinir. 32KB Flash Memory
  //2KB SRAM Memory
}

void EEPROMWriteInt(int address, int value)
{
  EEPROM.update(address, lowByte(value));
  EEPROM.update(address + 1, highByte(value));
}

int EEPROMReadInt(int address)
{
  return EEPROM.read(address) + (EEPROM.read(address + 1) << 8);
}
