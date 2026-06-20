#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // 使用 sort() 
#include <iomanip>   // 為了讓功能 2 的輸出格式更清楚易讀 

using namespace std;

// 定義學生資料結構 
struct Student {
    string id;    // 學號 [cite: 39]
    string name;  // 姓名 [cite: 40]
    int score;    // 成績 [cite: 41]
};

// 五、Template 延伸挑戰題：Template Function - 通用最大值 
template <class T>
T getMax(T a, T b) { // [cite: 69]
    return (a > b) ? a : b; // [cite: 70-71]
}

// 五、Template 延伸挑戰題：Template Function - 通用最小值
template <class T>
T getMin(T a, T b) { // [cite: 73-74]
    return (a < b) ? a : b; // [cite: 76] 
}

// 功能 1：新增學生資料 
void addStudent(vector<Student>& students) {
    string id, name;
    int score;
    
    cout << "Enter Student ID: ";
    cin >> id;
    
    // 檢查學號是否重複 
    for (const auto& s : students) {
        if (s.id == id) {
            cout << "Error: Student ID already exists! Registration rejected.\n"; // 拒絕新增並提示錯誤 
            return;
        }
    }
    
    cout << "Enter Student Name: ";
    cin.ignore(); // 清除緩衝區的換行符號，避免 getline 直接跳過
    getline(cin, name);
    
    cout << "Enter Student Score (0-100): ";
    cin >> score;
    
    // 簡單的分數防呆
    while (score < 0 || score > 100) {
        cout << "Invalid score! Please enter again (0-100): ";
        cin >> score;
    }
    
    // 加入資料結構中 
    students.push_back({id, name, score});
    cout << "Student added successfully!\n";
}

// 功能 2：列出所有學生 
void listStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records found.\n";
        return;
    }
    
   
    cout << "\n-----------------------------------------\n";
    cout << left << setw(15) << "ID" << setw(15) << "Name" << setw(10) << "Score" << "\n";
    cout << "-----------------------------------------\n";
    for (const auto& s : students) {
        cout << left << setw(15) << s.id << setw(15) << s.name << setw(10) << s.score << "\n";
    }
    cout << "-----------------------------------------\n";
}

// 功能 3：依成績排序 
void sortByScore(vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records to sort.\n";
        return;
    }
    
    // 使用 sort() 對學生資料依照成績由高到低排序，並套用 lambda 語法 
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.score > b.score; // [cite: 54]
    });
    
    cout << "Students sorted by score (highest to lowest) successfully!\n";
}

// 功能 4：查詢學生 
void searchStudent(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records available to search.\n";
        return;
    }
    
    string searchId;
    cout << "Enter Student ID to search: ";
    cin >> searchId;
    
    // 輸入學號後，查詢該學生資料 
    for (const auto& s : students) {
        if (s.id == searchId) {
            cout << "\n--- Student Found ---\n";
            cout << "ID: " << s.id << "\n";
            cout << "Name: " << s.name << "\n";
            cout << "Score: " << s.score << "\n";
            return;
        }
    }
    
    // 若找不到該學號，輸出訊息 
    cout << "Error: Student with ID " << searchId << " not found.\n";
}

// 功能 5：統計成績 
void showStatistics(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No student records available for statistics.\n";
        return;
    }
    
    int totalScore = 0;
    int maxScore = students[0].score;
    int minScore = students[0].score;
    int passCount = 0;
    int failCount = 0;
    
    for (const auto& s : students) {
        totalScore += s.score;
        
        // 呼叫Template Function 協助完成最高分與最低分統計 
        maxScore = getMax(maxScore, s.score);
        minScore = getMin(minScore, s.score);
        
        if (s.score >= 60) {
            passCount++;
        } else {
            failCount++;
        }
    }
    
    double average = static_cast<double>(totalScore) / students.size();
    
    // 輸出全班平均、最高分、最低分、及格人數、不及格人數 
    cout << "\n============= STATISTICS =============\n";
    cout << "Class Average: " << fixed << setprecision(2) << average << "\n";
    cout << "Highest Score: " << maxScore << "\n";
    cout << "Lowest Score:  " << minScore << "\n";
    cout << "Passed Count:  " << passCount << " student(s)\n";
    cout << "Failed Count:  " << failCount << " student(s)\n";
    cout << "======================================\n";
}

int main() {
    vector<Student> students; // 主要儲存學生的 vector 容器 
    int choice;
    
    do {
        // 建議選單介面 
        cout << "\n====== Student Management System ======\n";
        cout << "1. Add student\n";     // [cite: 58]
        cout << "2. List all students\n"; // [cite: 59]
        cout << "3. Sort by score\n";     // [cite: 60]
        cout << "4. Search by id\n";     // [cite: 61]
        cout << "5. Show statistics\n";  // [cite: 62]
        cout << "0. Exit\n";             // [cite: 63]
        cout << "---------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                listStudents(students);
                break;
            case 3:
                sortByScore(students);
                break;
            case 4:
                searchStudent(students);
                break;
            case 5:
                showStatistics(students);
                break;
            case 0:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 0);
    
    return 0;
}
