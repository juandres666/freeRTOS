#include <FreeRTOS.h>
#include <task.h>

void Task_Print1(void *param);
void Task_Print2(void *param);

TaskHandle_t Task_Handle1;
TaskHandle_t Task_Handle2;
//
//void blink(void *pvParameters)
//{
//  Serial.println("Blink task started");
//  pinMode(LED_BUILTIN, OUTPUT);
//  
//  for( ;; ) {
//    digitalWrite(LED_BUILTIN, HIGH);
//    Serial.println("H");
//    vTaskDelay(1000);
//    
//    digitalWrite(LED_BUILTIN, LOW);
//    Serial.println("L");
//    vTaskDelay(1000);
//  }
//}

void setup() 
{
  Serial.begin(9600);

  xTaskCreate(Task_Print1,"Task1",100,NULL,1,&Task_Handle1);
  xTaskCreate(Task_Print2,"Task1",100,NULL,1,&Task_Handle2);
  
  vTaskStartScheduler();

  Serial.println("Failed to start FreeRTOS scheduler");
  while(1);
}

void loop()
{
}

void Task_Print1(void *param)
{
  (void) param;
  while(1)
  {
    Serial.println("task 1");
    vTaskDelay(1000/portTICK_PERIOD_MS); //The Arduino will print to serial monitor each 1 sec
  }
}

void Task_Print2(void *param)
{
  (void) param;
  while(1)
  {
    Serial.println("task 2");
    vTaskDelay(1000/portTICK_PERIOD_MS); //The Arduino will print to serial monitor each 1 sec
  }
}
