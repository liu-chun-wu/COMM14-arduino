const int sensor = A5; // 感測器腳位
const int delay_200ms = 200; // 程式暫停 200ms

int sensorvalue; // 感測器的值
char character; // 字元
int decimal; // 十進位
int binary; // 二進位
int multiple_2; // 用迭代2的次方

void setup(){
  Serial.begin(9600); // 設定鮑率
}

void loop(){

  // 判斷是否收到開始訊號，如果收到開始訊號，delay 400ms，開始接收訊息，否則就繼續等待開始訊號

  sensorvalue = analogRead(sensor); // 讀感測器的值
  
  if(sensorvalue > 500){ // 如果雷射亮，感測器的值會大於50，相當於開始訊號
    
    delay(400); // 程式暫停400ms

    Serial.print("Received binary code is : ");
    
    delay(delay_200ms) ;// 程式暫停200ms
    
    // 初始化 decimal 和 multiple_2
    decimal = 0; // 從 0 開始累加
    multiple_2 = 1; // 因為 2 ^ 0 = 1
    
    // 輸入二進位並還原成十進
    // 如果感測器的值讀進來小於500，代表雷射暗，使輸入的二進位為 0
    // 如果感測器的值讀進來大於500，代表雷射亮，使輸入的二進位為 1
    
    for (int i = 0; i < 7; i++){
      
      sensorvalue = analogRead(sensor); // 讀感測器的值

      if(sensorvalue < 500 ) { // 如果感測器的值讀進來小於500
        binary = 0; // 使輸入的二進位為 0
      }else if(sensorvalue > 500) { //如果感測器的值讀進來大於500
        binary = 1; // 使輸入的二進位為 1   
      }
    
      Serial.print(binary);
      Serial.print(" ");
      
      decimal += binary * multiple_2; // 把 binay 乘以 multiple_2 並加到 decimal
      
      multiple_2 *= 2; // multiple_2 一開始是 2 ^ 0 = 1，每過一次迴圈會多一次方
      
      delay(delay_200ms); // 程式暫停200ms
    }
    
    Serial.println(); 
    
    character = char(decimal); // 把decimal轉換成int型態並賦值給character
      
    Serial.print("Your message is : ");
    Serial.println(character);
    Serial.print("--------------------\n");
      
    delay(delay_200ms); // 程式暫停200ms
  }
}