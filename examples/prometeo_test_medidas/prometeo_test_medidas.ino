#include "power_measurement.h"
Power_measurement Prometeo;

int8_t measurement_status;

void setup()
{
    Serial.begin(115200);  
    
    Serial.println();
    Serial.println();    
    
    // Configura la librería de lecctura y el ADC
    // Primer parámetro: Ajuste para Vrms
    // Segundo parámetro: Ajuste para desviación de las medidas respecto a V del primer zócalo
    // Tercer parámetro: Ajuste para desviación de las medidas respecto a V del segundo zócalo
    // Cuarto parámetro: Ajuste para desviación de las medidas respecto a V del tercer zócalo
    // Quinto parámetro: Ajuste para la sonda de corriente del primer zócalo
    // Sexto parámetro: Ajuste para la sonda de corriente del segundo zócalo
    // Séptimo parámetro: Ajuste para la sonda de corriente del tercer zócalo
    Prometeo.config(1.125, 0.330, 0.32, 0.32, 0.03322, 0.03322, 0.03322);
    Serial.println("Medición en...3");
    delay(1000);
    Serial.println("...2");
    delay(1000);
    Serial.println("...1"); 
    delay(1000);
    
}

void loop()
{
    Serial.println("=========================================================");
    measurement_status = Prometeo.calcVI(20,2000); 	// Realiza la medida. (Nº de pasos por cero, timeout para sincronizar el paso por 0)
    if (measurement_status == 0)
    {
		Prometeo.serialprint(SOCKET1);    // Muestra los datos (Vrms, Irms, potencia activa, potencia aparente, factor de potencia)
		Prometeo.serialprint(SOCKET2);    // Muestra los datos (Vrms, Irms, potencia activa, potencia aparente, factor de potencia)
		Prometeo.serialprint(SOCKET3);    // Muestra los datos (Vrms, Irms, potencia activa, potencia aparente, factor de potencia)
	}
	else
	{
		Serial.print("Valor devuelto: ");	
		Serial.println(measurement_status, DEC);
	}
    delay(1000);		
}
