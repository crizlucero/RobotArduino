#define MPU 0x68

#define A_R 16384.0
#define G_R 131.0

#define RAD_A_DEG = 57.295779

int16_t AcX, AcY, AcZ, GyX, GyY, GyZ;

float Acc[2];
float Gy[2];
float Angle[2];

void Acelerometro() {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true);
  AcX = Wire.read() << 8 | Wire.read();
  AcY = Wire.read() << 8 | Wire.read();
  AcZ = Wire.read() << 8 | Wire.read();

  //Calculo de angulos Y, X
  Acc[1] = atan(-1 * (AcX / A_R) / sqrt(pow((AcY / A_R), 2) + pow((AcZ / A_R), 2))) * RAD_TO_DEG;
  Acc[0] = atan((AcY / A_R) / sqrt(pow((AcX / A_R), 2) + pow((AcZ / A_R), 2))) * RAD_TO_DEG;

  //Leer los valores del Giroscopio
  Wire.beginTransmission(MPU);
  Wire.write(0x43);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 4, true);
  GyX = Wire.read() << 8 | Wire.read();
  GyY = Wire.read() << 8 | Wire.read();

  Gy[0] = GyX / G_R;
  Gy[1] = GyY / G_R;

  Angle[0] = 0.98 * (Angle[0] + Gy[0] * 0.010) + 0.02 * Acc[0];
  Angle[1] = 0.98 * (Angle[1] + Gy[1] * 0.010) + 0.02 * Acc[1];
  Serial.print("Angle X: "); Serial.println(Angle[0]);
  Serial.print("Angle Y: "); Serial.println(Angle[1]);

  delay(1000);

}
