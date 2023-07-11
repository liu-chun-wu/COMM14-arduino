const int laser = 3; // 雷射腳位
const int delay_200ms = 200; // 程式暫停 200ms

char character; //字元
int decimal; // 十進位
int binary; // 二進位
void setup(){
  pinMode(laser,OUTPUT); // 設定輸出的腳位和狀態
  Serial.begin(9600); // 設定鮑率
}

void loop(){

  if(Serial.available()) { // 判斷有沒有東西要輸入

    character = Serial.read(); // 讀字元進來

    Serial.print("Your message is : ");
    Serial.println(character);
    
    delay(delay_200ms); // 程式暫停200ms
 
    // 開始訊號 : 雷射亮 -> 程式暫停200ms -> 雷射暗 -> 程式暫停200ms
    digitalWrite(laser , HIGH); // 讓雷射亮
    delay(delay_200ms); // 程式暫停200ms
    digitalWrite(laser , LOW); // 讓雷射暗
    delay(delay_200ms); // 程式暫停200ms
 
    // character -> decimal -> binary -> send
 
    Serial.print("Binary code of your message is : ");
    
    delay(delay_200ms); // 程式暫停200ms

    decimal = int(character); // 把character換成十進位，並賦值給decimal

    for (int i = 0 ; i < 7 ; i++){
      binary = decimal % 2; // 把decimal整除，取其餘數並賦值給binary
      
      // 如果二進位是 1，讓雷射亮，如果二進位是 0，讓雷射暗
      if(binary == 1) { // 如果二進位是 1
        digitalWrite(laser,HIGH); // 讓雷射亮
      }else if(binary == 0) { // 如果二進位是 0
        digitalWrite(laser,LOW); // 讓雷射暗
      }
      
      Serial.print(binary);
      Serial.print(" ");
      
      decimal /= 2;  // 使 decimal 整除以 2
      
      delay(delay_200ms); // 程式暫停200ms
    }
    
    digitalWrite(laser,LOW); // 使雷射暗，達到歸零雷射的效果
    
    Serial.println();
    Serial.println("Your message is sent.");
    Serial.println("--------------------");

    delay(delay_200ms); // 程式暫停200ms
  }
}