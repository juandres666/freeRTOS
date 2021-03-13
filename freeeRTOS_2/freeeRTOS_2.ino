#include <FreeRTOS.h>
#include <task.h>

void Task_LED(void *param);
void Task_Print(void *param);

TaskHandle_t Task_Handle1;
TaskHandle_t Task_Handle2;

void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);// initialize the LED pin as an output:
  pinMode(52, INPUT_PULLUP);// initialize the pushbutton pin as an input:
  
  Serial.begin(9600);

  xTaskCreate(Task_LED,"Task1",100,NULL,1,&Task_Handle1);
  xTaskCreate(Task_Print,"Task1",100,NULL,1,&Task_Handle2);
  
  vTaskStartScheduler();

  Serial.println("Failed to start FreeRTOS scheduler");
  while(1);
}

void loop()
{
}

void Task_LED(void *param)
{
  (void) param;
  while(1)
  {
    if (digitalRead(52) == LOW){
      while(digitalRead(52) == LOW);
      digitalWrite(LED_BUILTIN, LOW);// turn the LED off by making the voltage LOW
    }
    else{
      digitalWrite(LED_BUILTIN, HIGH);// turn the LED on (HIGH is the voltage level)
    }
  
    vTaskDelay(1000/portTICK_PERIOD_MS); //The Arduino will print to serial monitor each 1 sec
  }
}

void Task_Print(void *param)
{
  (void) param;
  while(1)
  {
    Serial.println("task print");
    vTaskDelay(1000/portTICK_PERIOD_MS); //The Arduino will print to serial monitor each 1 sec
  }
}
