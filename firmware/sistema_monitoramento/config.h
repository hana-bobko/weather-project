#ifndef CONFIG_H
#define CONFIG_H

#define DHTPIN 4         
#define DHTTYPE DHT22    
#define MQ135PIN A0      
#define NOISEPIN A1      
#define SDPIN 10         

#define USE_WIFI

#define READ_INTERVAL 60000    
#define UPLOAD_INTERVAL 300000 

#define TEMP_MIN_LIMIT 18.0     
#define TEMP_MAX_LIMIT 30.0     