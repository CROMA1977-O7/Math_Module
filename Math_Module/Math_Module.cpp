// Math_Module.cpp: 定義應用程式的進入點。
//
#include <stdlib.h>
#include "Math_Module.hpp"

using namespace std;

void TestVectorReference2() {
    // 用 e0, e1 組成 向量 P0
    double e0, e1;
    double a, b;
    CVectorReference2d P0(e0, e1);  // e0, e1 尚未初始化
    cout << "CVectorReference 可以將相同型態的變數組合成一個向量" << endl;
    cout << "以 double e0, e1 組成 P0" << endl << "CVectorReferenct2d P0(e0, e1)" << endl << endl;
    cout << "二維向量擁有別名 分別是空間上的 {m_x, m_y} 與 材質座標的 {m_s, m_t} 在這個案例中都是指向 {e0, e1}" << endl;
    cout << "對向量的任意元素賦值 也會反饋到其他對應的元素上" << endl << endl << "現在的 P0" << endl;
    cout << "P0(e0, e1) => {e0, e1} = {" << e0 << "," << e1 << "}" << endl;
    cout << "P0(e0, e1) => {P0.m_x, P0.m_y} = {" << P0.m_x << "," << P0.m_y << "}" << endl;
    cout << "P0(e0, e1) => {P0.m_s, P0.m_t} = {" << P0.m_s << "," << P0.m_t << "}" << endl;
    // 對向量賦值 也會反饋到 e0, e1
    a = 5, b = 6.0;
    e0 = a; e1 = b;
    cout << endl << "當我們 修改 {e0, e1} e0 = " << a << " e1 = " << b << " 三組數值應該相等" << endl;
    cout << "P0 會變成" << endl;
    cout << "P0.Set(" << a << "," << b << ") = > {e0, e1} = {" << e0 << "," << e1 << "}" << endl;
    cout << "P0.Set(" << a << "," << b << ") => {P0.m_x, P0.m_y} = {" << P0.m_x << "," << P0.m_y << "}" << endl;
    cout << "P0.Set(" << a << "," << b << ") => {P0.m_s, P0.m_t} = {" << P0.m_s << "," << P0.m_t << "}" << endl;

    cout << endl << "開始測試修改 {e0, e1} 三組數值應該相等" << endl << "請輸入兩個數值並用空白分隔:"; 
    cin >> a >> b;
    e0 = a; e1 = b;
    cout << endl << "呼叫賦值函數 P0.Set(" << a << "," << b << ")" << endl;
    cout << "{e0, e1} e0 = " << a << " e1 = " << b << " => {e0, e1} = {" << e0 << "," << e1 << "}" << endl;
    cout << "{e0, e1} e0 = " << a << " e1 = " << b << " => {P0.m_x, P0.m_y} = {" << P0.m_x << "," << P0.m_y << "}" << endl;
    cout << "{e0, e1} e0 = " << a << " e1 = " << b << " => {P0.m_s, P0.m_t} = {" << P0.m_s << "," << P0.m_t << "}" << endl;
    cout << "請檢查數值是否同步更新" << endl << "按 Enter 鍵繼續......" << endl;
    cin.ignore(1024, '\n');
    cin.get();
    system("cls");

    // 二維向量擁有別名 分別是空間上的 m_x, m_y 與 材質座標的 m_s, m_t 在這個案例中 m_x m_s 都是指向 e0， m_y m_t 都指向 e1
    a = 1.0; b = 2.0;
    P0.m_x = a; P0.m_y = b;     // e0 = 1.0 e1 = 2.0
    cout << endl << "當我們對任意元素做出調整 三組數值應該同步變化" << endl;
    cout <<"賦值 P0.m_x = " << a << " P0.m_y = " << b << endl;
    cout << "{P0.m_x, P0.m_y} = {" << a << "," << b << "} => {e0, e1} = {" << e0 << "," << e1 << "}" << endl;
    cout << "{P0.m_x, P0.m_y} = {" << a << "," << b << "} => {P0.m_x, P0.m_y} = {" << P0.m_x << "," << P0.m_y << "}" << endl;
    cout << "{P0.m_x, P0.m_y} = {" << a << "," << b << "} => {P0.m_s, P0.m_t} = {" << P0.m_s << "," << P0.m_t << "}" << endl;
    
    cout << endl << "測試賦值 {P0.m_x, P0.m_y}" << endl << "請輸入兩個數值並用空白分隔:" << endl;
    cin >> a >> b;
    P0.m_x = a; P0.m_y = b;
    cout << "{P0.m_x, P0.m_y} = {" << a << "," << b << "} => {e0, e1} = {" << e0 << "," << e1 << "}" << endl;
    cout << "{P0.m_x, P0.m_y} = {" << a << "," << b << "} => {P0.m_x, P0.m_y} = {" << P0.m_x << "," << P0.m_y << "}" << endl;
    cout << "{P0.m_x, P0.m_y} = {" << a << "," << b << "} => {P0.m_s, P0.m_t} = {" << P0.m_s << "," << P0.m_t << "}" << endl;
    cout << "請檢查數值是否同步更新" << endl << "按 Enter 鍵繼續......" << endl;
    cin.ignore(1024, '\n');
    cin.get();
    system("cls");

    a = 3.0; b = 4.0;
    P0.m_s = a; P0.m_t = b;     // e0 = 3.0 e1 = 4.0
    cout << endl << "當我們對任意元素做出調整 三組數值應該同步變化" << endl;
    cout << "賦值 P0.m_s = " << a << " P0.m_t = " << b << endl;
    cout << "{P0.m_s, P0.m_t} = {" << a << "," << b << "} => {e0, e1} = {" << e0 << "," << e1 << "}" << endl;
    cout << "{P0.m_s, P0.m_t} = {" << a << "," << b << "} => {P0.m_x, P0.m_y} = {" << P0.m_x << "," << P0.m_y << "}" << endl;
    cout << "{P0.m_s, P0.m_t} = {" << a << "," << b << "} => {P0.m_s, P0.m_t} = {" << P0.m_s << "," << P0.m_t << "}" << endl;
    cout << endl << "測試賦值 {P0.m_s, P0.m_t}" << endl << "請輸入兩個數值並用空白分隔:" << endl;
    cin >> a >> b;
    P0.m_s = a; P0.m_t = b;
    cout << endl << "賦值 P0.m_s = " << a << " P0.m_t = " << b << endl;
    cout << "{P0.m_s, P0.m_t} = {" << a << "," << b << "} => {e0, e1} = {" << e0 << "," << e1 << "}" << endl;
    cout << "{P0.m_s, P0.m_t} = {" << a << "," << b << "} => {P0.m_x, P0.m_y} = {" << P0.m_x << "," << P0.m_y << "}" << endl;
    cout << "{P0.m_s, P0.m_t} = {" << a << "," << b << "} => {P0.m_s, P0.m_t} = {" << P0.m_s << "," << P0.m_t << "}" << endl;
    cout << "請檢查數值是否同步更新" << endl << "按 Enter 鍵繼續......" << endl;
    cin.ignore(1024, '\n');
    cin.get();
    system("cls");

    // CVector2d 是 CVectorReference2d 的子類別
    // 相當於一個自帶 陣列 的 CVectorReference2d
    a = 1; b = -1;
    CVector2d P1(a, b);             
    // P1 等效 P2
    double dBuffer[] = { 1, -1 };
    CVectorReference2d P2(dBuffer); // P2 = { 1, -1}
    cout << endl << "CVector2d 是 CVectorReference2d 的子類別" << endl;
    cout << "相當於一個自帶 陣列 的 CVectorReference2d" << endl;
    cout << endl << "宣告 CVector2d P1(" << a << "," << b << "); " << endl;
    cout << "P1(" << a << "," << b << ") => {P1.m_Buffer[0], P1.m_Buffer[1]} = {" << P1.m_Buffer[0] << "," << P1.m_Buffer[1] << "}" << endl;
    cout << "P1(" << a << "," << b << ") => {P1.m_x, P1.m_y} = {" << P1.m_x << "," << P1.m_y << "}" << endl;
    cout << "P1(" << a << "," << b << ") => {P1.m_s, P1.m_t} = {" << P1.m_s << "," << P1.m_t << "}" << endl;
    cout << endl <<"P1 等效 P2" << endl;
    cout << "double dBuffer[] = { 1, -1 };" << endl;
    cout << "CVectorReference2d P2(dBuffer);" << endl;
    cout << "P2(dBuffer) => {dBuffer[0], dBuffer[1]} = {" << dBuffer[0] << "," << dBuffer[1] << "}" << endl;
    cout << "P2(dBuffer) => {P1.m_x, P1.m_y} = {" << P2.m_x << "," << P2.m_y << "}" << endl;
    cout << "P2(dBuffer) => {P1.m_s, P1.m_t} = {" << P2.m_s << "," << P2.m_t << "}" << endl;
    cout << "按 Enter 鍵繼續......" << endl;
    cin.ignore(1024, '\n');
    cin.get();
    system("cls");

    // CVectorReference 擁有拷貝建構式 P3 與 P0 同指向 e0, e1
    CVectorReference2d P3(P0);      
    cout << "CVectorReference 的拷貝建構式 會指向相同的變數" << endl;
    cout << endl << "CVectorReference2d P3(P0); // P3 也會指向 {e0, e1}" << endl;
    cout << "P0(e0, e1) => {e0, e1} = {" << e0 << "," << e1 << "}" << endl;
    cout << "P0(e0, e1) => {P0.m_x, P0.m_y} = {" << P0.m_x << "," << P0.m_y << "}" << endl;
    cout << "P0(e0, e1) => {P0.m_s, P0.m_t} = {" << P0.m_s << "," << P0.m_t << "}" << endl;
    cout << "P3(P0) => {P3.m_x, P3.m_y} = {" << P3.m_x << "," << P3.m_y << "}" << endl;
    cout << "P3(P0) => {P3.m_s, P3.m_t} = {" << P3.m_s << "," << P3.m_t << "}" << endl;

    a = 3; b = 5;
    P3.Set(a, b);                   // P0 & P3 = { 3, 5}
    cout << endl << "對 P3 進行賦值 P0 也會同步更新" << endl;
    cout << "P3.Set(" << a << "," << b << ")" << endl;
    cout << "P0(e0, e1) => {e0, e1} = {" << e0 << "," << e1 << "}" << endl;
    cout << "P0(e0, e1) => {P0.m_x, P0.m_y} = {" << P0.m_x << "," << P0.m_y << "}" << endl;
    cout << "P0(e0, e1) => {P0.m_s, P0.m_t} = {" << P0.m_s << "," << P0.m_t << "}" << endl;
    cout << "P3.Set(" << a << ", " << b << ") => {P3.m_x, P3.m_y} = {" << P3.m_x << "," << P3.m_y << "}" << endl;
    cout << "P3.Set(" << a << ", " << b << ") => {P3.m_s, P3.m_t} = {" << P3.m_s << "," << P3.m_t << "}" << endl;
    cout << "請檢查數值是否同步更新" << endl << "按 Enter 鍵繼續......" << endl;
    cin.ignore(1024, '\n');
    cin.get();

    cout << endl << "測試賦值 P3.Set(a,b)" << endl << "請輸入兩個數值並用空白分隔:" << endl;
    cin >> a >> b;
    P3.Set(a, b);                   
    cout << "P3.Set(" << a << "," << b << ")" << endl;
    cout << "P0(e0, e1) => {e0, e1} = {" << e0 << "," << e1 << "}" << endl;
    cout << "P0(e0, e1) => {P0.m_x, P0.m_y} = {" << P0.m_x << "," << P0.m_y << "}" << endl;
    cout << "P0(e0, e1) => {P0.m_s, P0.m_t} = {" << P0.m_s << "," << P0.m_t << "}" << endl;
    cout << "P3.Set(" << a << ", " << b << ") => {P3.m_x, P3.m_y} = {" << P3.m_x << "," << P3.m_y << "}" << endl;
    cout << "P3.Set(" << a << ", " << b << ") => {P3.m_s, P3.m_t} = {" << P3.m_s << "," << P3.m_t << "}" << endl;
    cout << "請檢查數值是否同步更新" << endl << "按 Enter 鍵繼續......" << endl;
    cin.ignore(1024, '\n');
    cin.get();
    system("cls");

    // CVectorReference 可以使用多種形態進行賦值
    int iBuffer[] = { 1, -1 };
    P3.Set(iBuffer);                // P0 & P3 = { 1,-1}
    cout << "CVectorReference 可以使用多種方式進行賦值" << endl;
    cout << "int iBuffer[] = {" << iBuffer[0] << "," << iBuffer[1] << "}; " << endl;
    cout << "P3.Set(iBuffer); " << endl;
    cout << "P3.Set(iBuffer) => {e0, e1} = {" << e0 << "," << e1 << "}" << endl;
    cout << "P3.Set(iBuffer) => {P3.m_x, P3.m_y} = {" << P3.m_x << "," << P3.m_y << "}" << endl;
    cout << "P3.Set(iBuffer) => {P3.m_s, P3.m_t} = {" << P3.m_s << "," << P3.m_t << "}" << endl;
    cout << "請檢查數值是否同步更新" << endl << "按 Enter 鍵繼續......" << endl;
    cin.ignore(1024, '\n');
    cin.get();
    cout << endl << "測試賦值 P3.Set(iBuffer)" << endl << "請輸入兩個數值並用空白分隔:" << endl;
    cin >> a >> b;
    iBuffer[0] = (int) a; iBuffer[1] = (int) b;
    P3.Set(iBuffer);
    cout << "int iBuffer[] = {" << iBuffer[0] << "," << iBuffer[1] << "}; " << endl << "P3.Set(iBuffer); " << endl;
    cout << "P3.Set(iBuffer) => {e0, e1} = {" << e0 << "," << e1 << "}" << endl;
    cout << "P3.Set(iBuffer) => {P3.m_x, P3.m_y} = {" << P3.m_x << "," << P3.m_y << "}" << endl;
    cout << "P3.Set(iBuffer) => {P3.m_s, P3.m_t} = {" << P3.m_s << "," << P3.m_t << "}" << endl;
    cout << "請檢查數值是否同步更新" << endl << "按 Enter 鍵繼續......" << endl;
    cin.ignore(1024, '\n');
    cin.get(); 

    int c = 1, d = 0;
    P2.Set(c, d);                   //      P2 = { 1, 0}
    cout << "int c = " << c << ", d = " << d << "; " << endl;
    cout << "P2.Set(" << c << "," << d << "); " << endl;
    cout << "P2.Set(" << c << "," << d << ") => {dBuffer[0], dBuffer[1]} = {" << dBuffer[0] << "," << dBuffer[1] << "}" << endl;
    cout << "P2.Set(" << c << "," << d << ") => {P2.m_x, P2.m_y} = {" << P2.m_x << "," << P2.m_y << "}" << endl;
    cout << "P2.Set(" << c << "," << d << ") => {P2.m_s, P2.m_t} = {" << P2.m_s << "," << P2.m_t << "}" << endl;
    cout << "請檢查數值是否同步更新" << endl << "按 Enter 鍵繼續......" << endl;
    cin.ignore(1024, '\n');
    cin.get();
    cout << endl << "測試賦值 P3.Set(iBuffer)" << endl << "請輸入兩個數值並用空白分隔:" << endl;
    cin >> a >> b;
    iBuffer[0] = (int)a; iBuffer[1] = (int)b;
    P3.Set(iBuffer);
    cout << "int iBuffer[] = {" << iBuffer[0] << "," << iBuffer[1] << "}; " << endl << "P3.Set(iBuffer); " << endl;
    cout << "P3.Set(iBuffer) => {e0, e1} = {" << e0 << "," << e1 << "}" << endl;
    cout << "P3.Set(iBuffer) => {P3.m_x, P3.m_y} = {" << P3.m_x << "," << P3.m_y << "}" << endl;
    cout << "P3.Set(iBuffer) => {P3.m_s, P3.m_t} = {" << P3.m_s << "," << P3.m_t << "}" << endl;
    cout << "請檢查數值是否同步更新" << endl << "按 Enter 鍵繼續......" << endl;
    cin.ignore(1024, '\n');
    cin.get();




    a = 0.0f; b = 1.0f;
    P1.Set(0.0f, 1.0f);             //      P1 = { 0, 1}
    P3.Set(P1, P2, 0.5);            // P3 = { (P2.m_x-P1.m_x) * 0.5 + P1.m_x, (P2.m_y-P1.m_y) * 0.5 + P1.m_y}
    P2.Swap(P1);                    // P1 與 P2 交換數值
    P3 = P2;                        // P0 & P3 = P2

    system("cls");
    // CVectorReference 可以進行多種線性代數的運算
    double Dot = P2.Dot(P1);                    // P2.m_x * P1.m_x + P2.m_y * P1.m_y
    double Length = P2.GetLength();             // sqrt(P2.m_x*P2.m_x + P2.m_y+P2.m_y)
    double Deg = P2.GetAngle(P1);               // P2 Dot P1 / (|P2|*|P1|) * Rad2Deg
    double Rad = P2.GetRadian(P1);              // P2 Dot P1 / (|P2|*|P1|) 

    P2.Set(3, 5);
    Length = P2.GetLength();                    // sqrt(P2.m_x*P2.m_x + P2.m_y+P2.m_y)
    P3 = P2.GetNormalize();                     // P3 = {P2.m_x / Length, P2.m_y / Length}
    P3 = P2.GetReverse();                       // P3 = {-P2.m_x, -P2.m_y}
    P2.Normalize();                             // P2 = {P2.m_x / Length, P2.m_y / Lenght}
    P2.Reverse();                               // P2 = {-P2.m_x,-P2.m_y}

    // 包含基本的符號運算
    P3 = P2 + P1;                               // P3 = {P2.m_x + P1.m_x, P2.m_y + P1.m_y}
    P3 = P2 - P1;                               // P3 = {P2.m_x - P1.m_x, P2.m_y - P1.m_y}
    P3 = P2 * 3;                                // P3 = {P2.m_x * 3, P2.m_y * 3}
    P3 = P2 * P1;                               // P3 = {P2.m_x * P1.m_x, P2.m_y * P1.m_y}
    P3 = P2 / 3;                                // P3 = {P2.m_x / 3, P2.m_y / 3}
    P3 = P2 / P1;                               // P3 = {P2.m_x / P1.m_x, P2.m_y / P1.m_y}
    P3 += P1;                                   // P3 = {P3.m_x + P1.m_x, P3.m_y + P1.m_y}
    P3 -= P1;                                   // P3 = {P3.m_x - P1.m_x, P3.m_y - P1.m_y}
    P3 *= 3;                                    // P3 = {P3.m_x * 3, P3.m_y * 3}
    P3 *= P1;                                   // P3 = {P3.m_x * P1.m_x, P3.m_y * P1.m_y}
    P3 /= 3;                                    // P3 = {P3.m_x / 3, P3.m_y / 3}
    P3 /= P1;                                   // P3 = {P3.m_x / P1.m_x, P3.m_y / P1.m_y}

    // 基本的邏輯判斷
    bool Flag;
    Flag = P2.IsZero();                         // (P2.m_x * P2.m_x + P2.m_y * P2.my) < 0.000001 ? true : false
    Flag = P3 == P1;                            // (P3.m_x - P1.m_x) ^ 2 + (P3.m_y - P1.my) ^ 2 < 0.000001 ? true : false
    Flag = P3 != P1;                            // (P3.m_x - P1.m_x) ^ 2 + (P3.m_y - P1.my) ^ 2 >= 0.000001 ? true : false
    Flag = P3 > P1;                             // P3.m_x > P1.m_x && P3.m_y > P1.my ? true : false
    Flag = P3 < P1;                             // P3.m_x < P1.m_x && P3.m_y < P1.my ? true : false
    Flag = P3 >= P1;                            // P3.m_x >= P1.m_x && P3.m_y >= P1.my ? true : false
    Flag = P3 <= P1;                            // P3.m_x <= P1.m_x && P3.m_y <= P1.my ? true : false
}

void TestVector2() {
    //double dBuffer[2] = { 1.0, 2.0 };
    //int iBuffer[] = { 1, -1 };
    double Dot, Length, Deg, Rad;
    bool Flag;

    // CVector2d 是 CVectorReference2d 的子類別
    // 相當於一個自帶 陣列 的 CVectorReference2d

    // P0 等效 P1
    double dBuffer[] = { 1, -1 };
    CVectorReference2d P0(dBuffer); // P0 = { 1, -1}
    CVector2d P1(1, -1);            // P1 = { 1, -1}   
 
    // 預設建構式會設定初值為 { 0, 0}
    CVector2d P2;                   // P2 = { 0, 0}
    // 允許使用 初始值 與 各種型態的陣列 設定建構式
    int iBuffer[] = { 1, -1 };
    CVector2d P3(1.0, 2.0);
    CVector2d P4(iBuffer);
    // 擁有兩種拷貝建構式
    CVector2d P5(P0);               // P5 = {P0.m_x, P0.m_y}
    CVector2d P6(P1);               // P6 = {P1.m_x, P1.m_y}
    // CVector 可以使用多種形態進行賦值
    P3.Set(iBuffer);                // P3 = { 1,-1}
    P2.Set(1, 0);                   // P2 = { 1, 0}
    P1.Set(0.0f, 1.0f);             // P1 = { 0, 1}
    P3.Set(P1, P2, 0.5);            // P3 = { (P2.m_x-P1.m_x) * 0.5 + P1.m_x, (P2.m_y-P1.m_y) * 0.5 + P1.m_y}
    P2.Swap(P1);                    // P1 與 P2 交換數值
    P3 = P2;                        // P3 = P2

    P0.Set(3, 5);
    P1.Set(iBuffer);
    P2.Set(1, 0);
    P3.Set(0, 1);
    Dot = P1.Dot(P2);
    P1.Swap(P2);
    Length = P1.GetLength();
    Deg = P1.GetAngle(P2);
    Rad = P1.GetRadian(P2);
    P1.Set(3, 5);
    P3 = P1.GetNormalize();
    P3 = P1.GetReverse();
    P1 = P2;
    P1.Normalize();
    P1.Reverse();
    Flag = P1.IsZero();
    P3 = P1 + P2;
    P3 = P1 - P2;
    P3 = P1 * 3;
    P3 = P1 * P2;
    P3 = P1 / 3;
    P3 = P1 / P2;
    P3 += P1;
    P3 -= P1;
    P3 *= 3;
    P3 *= P1;
    P3 /= 3;
    P3 /= P1;

    Flag = P3 == P1;
    Flag = P3 != P1;
    Flag = P3 > P1;
    Flag = P3 < P1;
    Flag = P3 >= P1;
    Flag = P3 <= P1;

}
void TestMatrix2(void) {
    double dBuffer[] = { 2.0, 0.0, 0.0, 2.0 };
    CMatrix2d M0;
    CMatrix2d M1(3.0, 1.0, 2.0, 4.0);
    CMatrix2d M2(dBuffer);
    CMatrix2d M3(M1);
    double* dPtr = M1.GetBuffer();
    M3 = M1.GetInverse();
    M3 = M1.GetTranspose();
    double Det = M1.GetDet();
    CVectorReference2d R0 = M1.GetRowVector(0);
    CVectorReference2d R1 = M1.GetRowVector(1);
    CVectorReference2d C0 = M1.GetColumnVector(0);
    CVectorReference2d C1 = M1.GetColumnVector(1);
    M1.WriteMatrix();
    M1.SetMatrix(dBuffer);
    M1.ReadMatrix();
    M1.SetScale(5, 3);
    M1.LoadIdentity();
    M1.Inverse();
    M1.Transpose();
    M3 = M1 + M2;
    M3 = M1 - M2;
    M3 = M1 * 3;
    M3 = M1 * M2;
    M3 = M1 / 2;
    M3 += M1;
    M3 -= M1;
    M3 *= 5;
    M3 /= 2;
    CVector2d P0(2.0, 1.0), P1;
    M3.LoadIdentity();
    M1.SetScale(3, 1);
    M2.LoadIdentity();
    M2.SetRotate(90);
    M3 = M1 * M2;
    P1 = M3 * P0;
    M3.LoadIdentity();
    M3.SetScale(3, 1);
    M3.PushMatrix();
    M3.SetRotate(90);
    M3 = M2;
    P1 = M3 * P0;
    M3.PopMatrix();
    P1 = M3 * P0;
}

void TestVectorReference3() {

    double e0, e1, e2;
    double dBuffer[] = { 1, -1 , 1 };
    int iBuffer[] = { 1, -1 , 0 };
    double Dot, Length, Deg, Rad;
    bool Flag;
    CVectorReference3d P0(e0, e1, e2);  // e0, e1, e2 未初始化
    CVectorReference3d P2(dBuffer);     // 1, -1, 1
    CVectorReference3d P1(P0);          // e0, e1, e2 未初始化
    CVector3d P3;                       // 0, 0, 0
    // P0 = P1, P2, P3
    P0.Set(3, 5, 2);                    // P0&P1 3, 5,2
    P1.Set(iBuffer);                    // P0&P1 1,-1, 0
    P2.Set(-1, 1, 0);                   // -1, 1, 0
    P3.Set(0, 1, 2);                    //  0, 1, 2
    Dot = P1.Dot(P2);                   // -2
    P1.Swap(P2);                        //  -1, 1, 0 | 1,-1, 0

    Length = P1.GetLength();            // 2 ^ 0.5
    Deg = P1.GetAngle(P2);              // 180
    Rad = P1.GetRadian(P2);             // 3.14

    P1.Set(3, 5, 2);
    Length = P1.GetLength();            // 6.164
    P3 = P1.GetNormalize();             // 0.486, 0.811, 0.324
    P3 = P1.GetReverse();               //-3,-5,-2
    P1 = P2;                            // 1,-1, 0
    P1.Normalize();                     // 0.707,-0.707, 0
    P1.Reverse();                       // 0.707,-0.707
    Flag = P1.IsZero();                 // false
    P1.m_z = 1.0;
    P3 = P1 + P0;                       //-1.414, 1.414, 2
    P3 = P1 - P0;                       // 0, 0, 0
    P3 = P1 * 3;                        //-2.12, 2.12, 3
    P3 = P1 * P2;                       //-0.707,-0.707, 0
    P3 = P1 / 3;                        //-0.235, 0.235, 0.333
    P3 = P1 / P2;                       //-0.707,-0.707 應報錯
    P3 += P1;                           //-1.414, 0.0, 2
    P3 -= P1;                           //-0.707, 0.707, 1
    P3 *= 3;                            //-2.121, 2.121, 3
    P3 *= P1;                           // 1.499, 1.499, 3
    P3 /= 3;                            // 0.499, 0.499, 1
    P3 /= P1;                           //-0.707, 0.707, 1
    Flag = P3 == P1;                    // true
    Flag = P3 != P1;                    // false
    Flag = P3 > P1;                     // false
    Flag = P3 < P1;                     // false
    Flag = P3 >= P1;                    // true
    Flag = P3 <= P1;                    // true
}

void TestVector3() {

    double dBuffer[] = { 1, -1 , 1 };
    int iBuffer[] = { 1, -1 , 0 };
    double Dot, Length, Deg, Rad;
    bool Flag;
    CVector3d P0(-1, 1, 2);             //-1, 1, 2
    CVector3d P2(dBuffer);              // 1,-1, 1
    CVector3d P1(P0);                   //-1, 1, 2 
    CVector3d P3;                       // 0, 0, 0
    // P0 = P1, P2, P3
    P0.Set(3, 5, 2);                    // P0&P1 3, 5, 2
    P1.Set(iBuffer);                    // P0&P1 1,-1, 0
    P2.Set(-1, 1, 0);                   // -1, 1, 0
    P3.Set(0, 1, 2);                    //  0, 1, 2
    Dot = P1.Dot(P2);                   // -2
    P1.Swap(P2);                        //  -1, 1, 0 | 1,-1, 0

    Length = P1.GetLength();            // 2 ^ 0.5
    Deg = P1.GetAngle(P2);              // 180
    Rad = P1.GetRadian(P2);             // 3.14

    P1.Set(3, 5, 2);
    Length = P1.GetLength();            // 6.164
    P3 = P1.GetNormalize();             // 0.486, 0.811, 0.324
    P3 = P1.GetReverse();               //-3,-5,-2
    P1 = P2;                            // 1,-1, 0
    P1.Normalize();                     // 0.707,-0.707, 0
    P1.Reverse();                       // 0.707,-0.707, 0
    Flag = P1.IsZero();                 // false
    P1.m_z = 1.0;
    P3 = P1 + P0;                       // 2.292, 5.707, 3
    P3 = P1 - P0;                       //-3.707,-4.292,-1
    P3 = P1 * 3;                        //-2.121, 2.121, 3
    P3 = P1 * P2;                       //-0.707,-0.707, 0
    P3 = P1 / 3;                        //-0.235, 0.235, 0.333
    P3 = P1 / P2;                       //-0.707,-0.707 應報錯
    P3 += P1;                           //-1.414, 1.414, 2
    P3 -= P1;                           //-0.707, 0.707, 1
    P3 *= 3;                            //-2.121, 2.121, 3
    P3 *= P1;                           // 1.499, 1.499, 3
    P3 /= 3;                            // 0.499, 0.499, 1
    P3 /= P1;                           //-0.707, 0.707, 1
    Flag = P3 == P1;                    // true
    Flag = P3 != P1;                    // flase
    Flag = P3 > P1;                     // false
    Flag = P3 < P1;                     // false
    Flag = P3 >= P1;                    // true
    Flag = P3 <= P1;                    // true
}
void TestMatrix3(void) {
    double dBuffer[] = { 2.0, 0.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 1.0 };
    CMatrix3d M0;
    CMatrix3d M1(3.0, 1.0, 0.0, 2.0, 4.0, 0.0, 0.0, 0.0, 1.0);
    CMatrix3d M2(dBuffer);
    CMatrix3d M3(M1);
    double* dPtr = M1.GetBuffer();
    M3 = M1.GetInverse();
    M2 = M3 * M1;
    M3 = M1.GetTranspose();

    double Det = M1.GetDet();

    CVectorReference3d R0 = M1.GetRowVector(0);
    CVectorReference3d R1 = M1.GetRowVector(1);
    CVectorReference3d R2 = M1.GetRowVector(2);
    CVectorReference3d C0 = M1.GetColumnVector(0);
    CVectorReference3d C1 = M1.GetColumnVector(1);
    CVectorReference3d C2 = M1.GetColumnVector(2);

    M1.WriteMatrix();
    M1.SetMatrix(dBuffer);
    M1.ReadMatrix();
    M1.SetScale(5, 3, 2);
    M1.LoadIdentity();
    M1.Inverse();
    M1.Transpose();
    /*
    M3 = M1 + M2;
    M3 = M1 - M2;
    M3 = M1 * 3;
    M3 = M1 * M2;
    M3 = M1 / 2;
    M3 += M1;
    M3 -= M1;
    M3 *= 5;
    M3 /= 2;
    CVector2d P0(2.0, 1.0),P1;
    M3.LoadIdentity();
    M1.SetScale(3, 1);
    M2.LoadIdentity();
    M2.SetRotate(90);
    M3 = M1 * M2;
    P1 = M3 * P0;
    M3.LoadIdentity();
    M3.SetScale(3, 1);
    M3.PushMatrix();
    M3.SetRotate(90);
    M3 = M2;
    P1 = M3 * P0;
    M3.PopMatrix();
    P1 = M3 * P0;
    */
}

int main()
{
    TestVectorReference2();
    TestVector2();
    TestMatrix2();
    TestVectorReference3();
    TestVector3();
    TestMatrix3();
	cout << "Hello CMake." << endl;
	return 0;
}
