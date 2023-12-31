Arduino project
===
## 緣由
- 我於2022/12 ~ 2023/7 作為第十四屆通訊營的課程組的組員，這是我為了課程而設計的簡易的arduino的裝置。
- 我在上大學前沒有玩過arduino，只有玩過像是樂高或是慧魚積木，這是我為了準備課程自學的。
## 內容
包含程式碼和電路圖，由於這是為了教學製作所以也有製作相關的教材，基本上從發想主題到實際寫程式碼是我自己完成的，電路圖則有相關經驗的組員協助完成。
## 使用的材料
1. Arduino板與連接線 x1
2. 麵包板 x1
3. 330Ω電阻 
4. 1MΩ電阻
5. 光敏二極體 x1
6. 650nm紅光雷射 x1
7. 排針母座 x1
8. 單芯線適量
## 目標
可以在A電腦上輸入訊息並透過雷射模組傳送到光敏二極體，最後在B電腦還原出來。
## 運作原理
1. 總共有兩組裝置，接收端和發射端，接收端主要有arduino R3版和雷射模組，發射端主要有arduino R3版和光敏二極體。
- 發射端 : 在A電腦上輸入訊息->透過ASCII table換成十進位->換成二進位->用雷射發射出去(1代表高電位，0代表低電位)。
- 接收端 : 用光敏二極體接收二進位訊號(1代表高電位，0代表低電位)->換回十進位並還原訊息->在B電腦上呈現出來。
2. 開始訊號和結束訊號
- 由於使用人工的方式讓板子同步處理訊息不太現實，因此在發送真正的訊息前會先發射開始訊號，使發射端和接收端同步delay，達到同步的效果。
- 結束訊號也是為了要達到可以在發射端控制接收端所設計的，其實就是發送一段特別的二進位，我原本設計會有一個觸發關鍵字，如果關鍵字被觸發那就會傳送11111111(127的二進位)，接收端接收到這個結束訊息後就會結束程式。
- 註 : 原本的程式碼是有寫結束訊號，但是後來因為要降低難度所以刪掉了，但是要加上去不難。
## 遇到的困難
此裝置的程式碼很簡單，需要基本的C語言語法，我花最多時間是在硬體的部分的debug。
### arduino板有問題
- 在運行測試時出現雷射因為程式碼delay的時間不一樣而亂閃的情況，由於這個裝置是透過發送開始訊號來同步訊號的傳送，因此這會導致裝置無法正確傳送訊息，經檢查過後程式碼沒有問題，找不到問題點，也因此困擾我許久。
- 後來碰巧更換了arduino板，測試沒問題，才發現原來是板子本身有問題，由於我之前沒有太多硬體相關的經驗，所以沒有想過板子本身也會出現問題，這次經驗也算是增加了知識呢。
### 電腦需要額外安裝驅動程式
我們教學的場所是在學校的電腦教室，在試安裝時在發現電腦找不到arduino的開發版，剛好組員中有一位有相關經驗，幫忙安裝usb裝置的驅動程式後就可以順利地執行
## 結論
製作這個project讓我學習很多，尤其是硬體方面，雖然中間debug很漫長，但是教學時看到學員開心的臉也算是值了。
