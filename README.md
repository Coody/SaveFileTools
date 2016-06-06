# Save file system in iOS(存檔管理工具)
![建立者](https://img.shields.io/badge/建立者-Coody-orange.svg)
![License](https://img.shields.io/dub/l/vibe-d.svg)

### Brief 簡述
You have to wrote a lot of similar code with save file code in iOS. If you create a class to handle save file, it is easily mix all kinds of data in one class and hard to expand, hard to manage.
This class is build for easily manage, expand, and data encryption and check easily.(Data encryption is in TODO list)

存檔在 iOS 中必須自行寫一大堆重複的 code ，即使把存檔做成一個類別，也容易把所有資料都綁死在一起，不好擴充、也不好管理。
這個類別目的就是為了好擴充、好管理、以及好作加解密、存檔讀檔前確認數值是否異常的類別模組化（加解密目前還沒有加入，當成 TODO 項目）。

### How to use 如何使用

>推薦用法（使用 SaveFileToolsManager 來管理存檔群）

0、將 SaveFileTools 資料夾內的類別複製到您的專案。

1、建立一個客製化的 SaveFileTools 、以及裡面自己建立一個你要的 Model （裡面包含你想要的 property）。

2、使用 SaveFileToolsManager 初始化路徑，並且給他一個你要的存檔路徑。
```
[[SaveFileToolsManager sharedInstance] initialFilePath:@"test/TestSaveFile"];
```
3、初始化你的客製化存檔類別，直接傳入類別名稱、以及你整個檔案的存檔名稱（必須獨一無二）
```
[[SaveFileToolsManager sharedInstance] initialSaveFileToolsWithClassNameArray:@[@"RemoteNotificationFileTool"]       
                                                                      withKey:@"fileOne"];
```
4、存檔
```
[[SaveFileToolsManager sharedInstance] saveWithKey:@"fileOne"];
```
5、讀檔
```
[[SaveFileToolsManager sharedInstance] loadWithKey:@"fileOne"];
```

> 單純使用單一檔案存檔（不使用 SaveFileToolsManager 來處理存/讀檔檔案）
0、將 SaveFileTools 資料夾內的 SaveFileTools 類別拷貝下來。
1、繼承他，並且建立自己的 Model 。（可參考範例中 RemoteNotificationFileTool 這個類別）
2、自行管理 SaveFileTools 。

### License

SaveFileTools is available under the MIT license.

