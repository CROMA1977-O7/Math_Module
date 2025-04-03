// Math_Module.cpp: 定義應用程式的進入點。
//

#include "Math_Module.hpp"

using namespace std;

void TestVectorReference2() {
    double e0, e1;
    double dBuffer[] = { 1, -1 };
    int iBuffer[] = { 1, -1 };
    double Dot, Length, Deg, Rad;
    bool Flag;
    CVectorReference2d P0(e0, e1);  // e0,e1 未初始化
    CVectorReference2d P2(dBuffer); // 1, -1
    CVectorReference2d P1(P0);      // e0,e1 未初始化
    CVector2d P3;                   // 0, 0
    // P0 = P1, P2, P3
    P0.Set(3, 5);                   // P0&P1 3, 5 
    P1.Set(iBuffer);                // P0&P1 1,-1
    P2.Set(1, 0);                   // 1, 0
    P3.Set(0, 1);                   // 0, 1
    Dot = P1.Dot(P2);               // 1
    P1.Swap(P2);                    // 1,0 1,-1
    Length = P1.GetLength();        // 1
    Deg = P1.GetAngle(P2);          // 45
    Rad = P1.GetRadian(P2);         // 3.14/4
    P1.Set(3, 5);
    Length = P1.GetLength();        // 5.83
    P3 = P1.GetNormalize();         // 0.51457, 0.85763
    P3 = P1.GetReverse();           //-3,-5
    P1 = P2;                        // 1,-1
    P1.Normalize();                 // 1, 0
    P1.Reverse();                   // 0.707,-0.707
    Flag = P1.IsZero();             // false
    P3 = P1 + P0;                   //-1.414, 1.414
    P3 = P1 - P0;                   // 0, 0
    P3 = P1 * 3;                    //-2.12, 2.12
    P3 = P1 * P2;                   //-0.707,-0.707
    P3 = P1 / 3;                    //-0.235, 0.235
    P3 = P1 / P2;                   //-0.707,-0.707
    P3 += P1;                       //-1.414, 0.0
    P3 -= P1;                       //-0.707,-0.707
    P3 *= 3;                        //-2.121,-2.121
    P3 *= P1;                       // 1.499,-1.499
    P3 /= 3;                        // 0.499,-0.499
    P3 /= P1;                       //-0.707,-0.707
    Flag = P3 == P1;                // false
    Flag = P3 != P1;                // true
    Flag = P3 > P1;                 // false
    Flag = P3 < P1;                 // false
    Flag = P3 >= P1;                // false
    Flag = P3 <= P1;                // true
}

void TestVector2() {
    double dBuffer[2] = { 1.0, 2.0 };
    int iBuffer[] = { 1, -1 };
    double Dot, Length, Deg, Rad;
    bool Flag;
    CVector2d P0;
    CVector2d P1(1.0, 2.0);
    CVector2d P2(dBuffer);
    CVector2d P3(P1);
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
