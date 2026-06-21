# C-Template-

# 學生成績管理系統 (Student Management System)

這是 C++ Template 延伸自主練習作業的第 2 週整合應用小專題。
本專案使用 C++ 標準模板函式庫 (STL) 的 `vector` 容器來實作學生成績的管理、排序與統計功能。

## 功能介紹
1. **新增學生 (Add student)**：輸入學號、姓名與成績，具備學號重複防呆機制。
2. **列出學生 (List all students)**：格式化輸出目前所有的學生資料。
3. **依成績排序 (Sort by score)**：使用 STL `sort()` 搭配 Lambda 語法將成績由高到低降冪排序。
4. **查詢學生 (Search by id)**：輸入學號即可尋找特定學生的資料。
5. **統計成績 (Show statistics)**：計算全班平均、及格/不及格人數，並使用自訂的 Template Function 找出最高分與最低分。

## 環境要求與編譯方式

本程式需在支援 C++17 語法標準的環境下編譯與執行。

### 1. 編譯程式
請打開終端機 (Terminal) 或命令提示字元，切換到本專案所在的目錄，並輸入以下指令進行編譯：

```bash
g++ -std=c++17 main.cpp -o main
