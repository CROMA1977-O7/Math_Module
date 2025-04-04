# Math_Module
矩陣運算的函數庫
基於 OpenGL 1.2 格式的矩陣運算
提供 2、3、4 維的矩陣運算


模組由三種基本類別組成 CVectorReference、CVector、CMatrix 命名由 型態、維度、資料精度 組成，例如

CVectorReference2d 代表 一個 2x1 double 精度的 CVectorRefence 物件型態
CMatrix2d 代表一個 2x2 double 精度的 CMatrix 物件型態

CVectorRefence 可以將對應精度的變數組成一個向量

    // 用 e0, e1 組成 向量 P0
    double e0, e1;
    CVectorReference2d P0(e0, e1);  // e0, e1 尚未初始化
    // 對向量賦值 也會反饋到 e0, e1
    P0.Set(5, 6);

CVectorReference 的資料擁有別名，可以根據使用的情境直接使用對應的名稱，能使代碼的閱讀性更好(三維、四維 向量擁有顏色的別名)

    // 二維向量擁有別名 分別是空間上的 m_x, m_y 與 材質座標的 m_s, m_t 
    // 在這個案例中 m_x m_s 都是指向 e0， m_y m_t 都指向 e1
    P0.m_x = 1.0; P0.m_y = 2.0;     // e0 = 1.0 e1 = 2.0
    P0.m_s = 3.0; P0.m_t = 4.0;     // e0 = 3.0 e1 = 4.0

CVector 是 CVectorReference 的子類別 相當於一個自帶 陣列 的 CVectorReference2d

    CVector2d P1(1, -1);                 
    // P1 等效 P2
    double dBuffer[] = { 1, -1 };
    CVectorReference2d P2(dBuffer); // P2 = { 1, -1}

CVectorReference 擁有拷貝建構式 P3 與 P0 同指向 e0, e1

    CVectorReference2d P3(P0);      
    P3.Set(3, 5);                   // P0 & P3 = { 3, 5}

CVectorReference 可以使用多種形態進行賦值

    int iBuffer[] = { 1, -1 };
    P3.Set(iBuffer);                // P0 & P3 = { 1,-1}
    P2.Set(1, 0);                   //      P2 = { 1, 0}
    P1.Set(0.0f, 1.0f);             //      P1 = { 0, 1}
    P2.Swap(P1);                    // P1 與 P2 交換數值
    P3 = P2;                        // P0 & P3 = P2

CVectorReference 可以進行多種線性代數的運算

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

包含基本的符號運算

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

基本的邏輯判斷

    bool Flag;
    Flag = P2.IsZero();                         // (P2.m_x * P2.m_x + P2.m_y * P2.my) < 0.000001 ? true : false
    Flag = P3 == P1;                            // (P3.m_x - P1.m_x) ^ 2 + (P3.m_y - P1.my) ^ 2 < 0.000001 ? true : false
    Flag = P3 != P1;                            // (P3.m_x - P1.m_x) ^ 2 + (P3.m_y - P1.my) ^ 2 >= 0.000001 ? true : false
    Flag = P3 > P1;                             // P3.m_x > P1.m_x && P3.m_y > P1.my ? true : false
    Flag = P3 < P1;                             // P3.m_x < P1.m_x && P3.m_y < P1.my ? true : false
    Flag = P3 >= P1;                            // P3.m_x >= P1.m_x && P3.m_y >= P1.my ? true : false
    Flag = P3 <= P1;                            // P3.m_x <= P1.m_x && P3.m_y <= P1.my ? true : false